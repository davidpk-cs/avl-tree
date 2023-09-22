//UMBC - CSEE - CMSC 341 - Fall 2022 - Proj1
#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;
enum DIRECTION {NORTH, SOUTH, EAST, WEST, NONE};
const int DEFNUMPASS = 10; // default number of passengers
class Grader;
class Tester;
class Railroad;
class Station{
    public:
    friend class Grader;
    friend class Tester;
    friend class Railroad;
    Station():m_code(0), m_passengers(0), 
        m_next(nullptr), m_previous(nullptr),
        m_north(nullptr), m_south(nullptr),
        m_east(nullptr), m_west(nullptr){}
    Station(int c, int p):m_code(c), m_passengers(p), 
        m_next(nullptr), m_previous(nullptr),
        m_north(nullptr),m_south(nullptr),
        m_east(nullptr), m_west(nullptr){}
    Station(int c, int p, Station* n, Station* s, Station* e, Station* w):
        m_code(c),m_passengers(p), 
        m_north(n),m_south(s),
        m_east(e),m_west(w){}
    ~Station(){}
    void setStationCode(int aValue){m_code = aValue;}
    int getStationCode(){return m_code;}
    void setNumPassengers(int p){m_passengers=p;}
    int getNumPassegers(){return m_passengers;}
    void setNext(Station * aNode){m_next=aNode;}
    Station * getNext(){return m_next;}
    void setPrevious(Station * aNode){m_previous = aNode;}
    Station * getPrevious(){return m_previous;}
    void setNorth(Station * aNode){m_north = aNode;}
    Station * getNorth(){return m_north;}
    void setSouth(Station * aNode){m_south = aNode;}
    Station * getSouth(){return m_south;}
    void setEast(Station * aNode){m_east = aNode;}
    Station * getEast(){return m_east;}
    void setWest(Station * aNode){m_west = aNode;}
    Station * getWest(){return m_west;}

    private:
    int m_code;//stores the station code number
    int m_passengers;// the number of passengers who board the train
    Station * m_next;
    Station * m_previous;
    Station * m_north;
    Station * m_south;
    Station * m_east;
    Station * m_west;
};

class Railroad{
    public:
    friend class Grader;
    friend class Tester;
    Railroad();
    Railroad(const Railroad & rhs);// copy constructor
    ~Railroad();// delete all memory
    void dump();// print the list of stations
    const Railroad & operator=(const Railroad & rhs);// overloaded assignment operator
    bool extendAtHead(int newCode, int passengers);
    bool extendAtTail(int newCode, int passengers);
    bool makeRoute(list< pair<int,DIRECTION> > route);
    int travel(list< pair<int,DIRECTION> > route);
    bool removeStation(int aCode);// this removes a node from the list
    void clearAllRoutes();// this clears all routes, resets all direction pointers
    bool setNumPassengers(int code, int passengers);
    void clearNetwork();// delete all memory and reset all member variables

    private:
    int m_numStations;// number of stations in the network
    Station * m_head;
    Station * m_tail;

    // ***************************************************
    // Any private helper functions must be delared here!
    // 
    //All implentations are at the bottom of railroad.cpp
    
    //will return the pointer to the station based on code
    //will return nullptr if station does not exist
    //if create = true, it will create the station and return if needed
    Station* codeMatch(int code, bool create = false); 
     
    //check to see if a route is valid
    //This does filter handle all error cases (won't recognize conflicting links created earier in the route
    //makeRoute() is designed to handle what this one can't
    bool validRoute(list < pair < int, DIRECTION > > route);

    //check to see if the desired direction has or doesn't have a link
    bool openDirection(DIRECTION direction, Station* station);

    //this function removes the head of the Railroad
    //this removes any Stations that were added by makeRoute() if it has an error midway
    //this is because all Stations that are created through makeRoute are inserted at the head
    void removeHead();

    //this checks to see if a conflicting link is identical to the link we want to add
    //to ensure that the program doesn't reject a route that has an identical link or loop
    bool sameLink(Station* currStation, Station* nextStation, DIRECTION direction);

    // ***************************************************
};