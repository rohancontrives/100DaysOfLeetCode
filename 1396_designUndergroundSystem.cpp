/* #1396. Design Underground System
An underground railway system is keeping track of customer travel times between different stations. 
They are using this data to calculate the average time it takes to travel from one station to another.

Implement the UndergroundSystem class:
    1. void checkIn(int id, string stationName, int t)
        - A customer with a card ID equal to id, checks in at the station stationName at time t.
        - A customer can only be checked into one place at a time.
    2. void checkOut(int id, string stationName, int t)
        - A customer with a card ID equal to id, checks out from the station stationName at time t.
    3. double getAverageTime(string startStation, string endStation)
        - Returns the average time it takes to travel from startStation to endStation.
        - The average time is computed from all the previous traveling times from startStation 
          to endStation that happened directly, meaning a check in at startStation followed by a check out from endStation.
        - The time it takes to travel from startStation to endStation may be 
          different from the time it takes to travel from endStation to startStation.
        - There will be at least one customer that has traveled from startStation to 
          endStation before getAverageTime is called.

You may assume all calls to the checkIn and checkOut methods are consistent.
If a customer checks in at time t1 then checks out at time t2, then t1 < t2. 
All events happen in chronological order.
*/

#include <iostream>
#include <utility>
#include <unordered_map>
using namespace std;

class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> journey;  // { {45, make_pair("Leyton", 3)}, {32, make_pair("Paradise", 8)} };
    unordered_map<string, pair<int, int>> timeLog;  //  { {"Leyton-Waterloo", {12, 1}} };
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        // journey.insert( { id, make_pair(stationName, t) } );
        journey[id] = {stationName, t};  // <---- alternatively
    }
    
    void checkOut(int id, string stationName, int t) {
        // auto it = journey.find(id);  // eg: id = 45 => it -> {45, make_pair("Leyton", 3)}
        // int diff = t - (it->second.second);
        // string travelStr = it->second.first + "-" + stationName;  // "Leyton-Waterloo"
        // if(timeLog.find(travelStr) != timeLog.end()) {  // if travelStr exist in timeLog
        //     timeLog[travelStr].first += diff;
        //     timeLog[travelStr].second++;
        // } else {
        //     timeLog.insert({ travelStr, make_pair(diff, 1) });
        // }

        // Alternatively
        auto [startStation, t0] = journey[id];
        string startEndStn = startStation + "->" + stationName;
        auto [timeSum, cnt] = timeLog[startEndStn];
        timeLog[startEndStn] = make_pair(timeSum+(t-t0), ++cnt);

        // clean up
        journey.erase(id);

    }
    
    double getAverageTime(string startStation, string endStation) {
        // auto it = timeLog.find(startStation + "->" + endStation);
        // double avg = double(it->second.first) / it->second.second;
        // alternatively
        auto [timeSum, cnt] = timeLog[startStation+"->"+endStation];
        return double(timeSum) / cnt;
    }
};
 
int main(){
    UndergroundSystem* obj = new UndergroundSystem();

    // obj->checkIn(45, "Leyton", 3);  // map<int, pair> journey = { {45, {"Leyton", 3}}, }; 
    // obj->checkIn(32, "Paradise", 8);  // journey = { {45, {"Leyton", 3}}, {32, {"Paradise", 8}} }
    // obj->checkIn(27, "Leyton", 10);  // journey = { {45, {"Leyton", 3}}, {32, {"Paradise", 8}}, {27, {"Leyton", 10} }

    // obj->checkOut(45, "Waterloo", 15);  // Customer 45 "Leyton" -> "Waterloo" in 15-3 = 12  | map<pair, int> timeLog = {{"Leyton", "Waterloo"}, {12, 1}}
    // obj->checkOut(27, "Waterloo", 20);  // Customer 27 "Leyton" -> "Waterloo" in 20-10 = 10  | timeLog = { {{"Leyton", "Waterloo"}, {12+10, 2}}, }
    // obj->checkOut(32, "Cambridge", 22); // Customer 32 "Paradise" -> "Cambridge" in 22-8 = 14

    // cout << obj->getAverageTime("Paradise", "Cambridge") << endl; // return 14.00000. One trip "Paradise" -> "Cambridge", (14) / 1 = 14
    // cout << obj->getAverageTime("Leyton", "Waterloo") << endl;    // return 11.00000. Two trips "Leyton" -> "Waterloo", (10 + 12) / 2 = 11

    // obj->checkIn(10, "Leyton", 24);

    // cout << obj->getAverageTime("Leyton", "Waterloo") << endl;    // return 11.00000

    // obj->checkOut(10, "Waterloo", 38);  // Customer 10 "Leyton" -> "Waterloo" in 38-24 = 14

    // cout << obj->getAverageTime("Leyton", "Waterloo") << endl;    // return 12.00000. Three trips "Leyton" -> "Waterloo", (10 + 12 + 14) / 3 = 12


    // ----------------------------------------------------------------
    obj->checkIn(10, "Leyton", 3);

    obj->checkOut(10, "Paradise", 8);

    cout << obj->getAverageTime("Leyton", "Paradise") << endl; // return 5.00000


    obj->checkIn(5, "Leyton", 10);

    obj->checkOut(5, "Paradise", 16);

    cout << obj->getAverageTime("Leyton", "Paradise") << endl; // return 5.50000


    obj->checkIn(2, "Leyton", 21);

    obj->checkOut(2, "Paradise", 30);

    cout << obj->getAverageTime("Leyton", "Paradise") << endl; // return 6.66667


}