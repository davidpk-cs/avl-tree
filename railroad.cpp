//UMBC - CSEE - CMSC 341 - Fall 2022 - Proj1
#include "railroad.h"

Railroad::Railroad(){
    //just initializing an empty railroad system
    m_numStations = 0;
    m_head = nullptr;
    m_tail = nullptr;
}

Railroad::~Railroad(){
    
    //this will do all the work
    clearNetwork();
}

void Railroad::clearNetwork(){
    
    //temp to iterate through all stations
    Station* tempStation = m_head;

    while (tempStation != nullptr) {

        //reset all station values
        tempStation->setNorth(nullptr);
        tempStation->setSouth(nullptr);
        tempStation->setEast(nullptr);
        tempStation->setWest(nullptr);
        tempStation->setNumPassengers(0);

        m_head = tempStation;

        //move to next station
        tempStation = tempStation->getNext();

        //delete the previous station
        delete m_head;
    }

    //clear Railroad variables
    m_head = nullptr;
    m_tail = nullptr;
    m_numStations = 0;
}

bool Railroad::extendAtHead(int newCode, int passengers){
    
    //first things first
    //make sure no negative station code or number of passengers
    //codeMatch() makes sure that no duplicate station exists
    if ((newCode < 1) || (passengers < 0) || (codeMatch(newCode) != nullptr)) {
        return false;
    }

    Station* newStation = new Station(newCode, passengers);
    
    if (m_numStations == 0) { //adding first element
        
        m_head = newStation;
        m_tail = newStation;
        newStation->setNext(nullptr);
        newStation->setPrevious(nullptr);

    }
    else if (m_numStations == 1) { //adding second element
        
        m_head = newStation;
        newStation->setNext(m_tail);

        m_tail->setPrevious(newStation);

    }
    else {
        //normal case
        newStation->setNext(m_head);
        newStation->setPrevious(nullptr);

        m_head = newStation;
        
        //make the previous head point backwards to the new head
        newStation->getNext()->setPrevious(m_head);
        
    }

    m_numStations++;
    
    return true;
}

bool Railroad::extendAtTail(int newCode, int passengers){

    //first things first
    //make sure no negative station code or number of passengers
    //codeMatch() makes sure that no duplicate station exists
    if ((newCode < 1) || (passengers < 0) || (codeMatch(newCode) != nullptr)) {
        return false;
    }

    Station* newStation = new Station(newCode, passengers);
    
    if (m_numStations == 0) { //adding first element
        
        m_head = newStation;
        m_tail = newStation;
        newStation->setNext(nullptr);
        newStation->setPrevious(nullptr);

    }
    else if (m_numStations == 1) { //adding second element

        m_tail = newStation;
        newStation->setPrevious(m_head);

        m_head->setNext(m_tail);
    }
    else {
        //normal case
        newStation->setPrevious(m_tail);
        newStation->setNext(nullptr);

        m_tail = newStation;

        //make the previous tail point forwards to the new tail
        m_tail->getPrevious()->setNext(m_tail);

    }

    m_numStations++;
    return true;
}


void Railroad::dump(){
    if (m_head != nullptr){
        int northCode, southCode, eastCode, westCode;
        Station *temp = m_head;
        while(temp != nullptr){
            if (temp->m_north != nullptr) northCode = temp->m_north->m_code;
            else northCode = -1;
            if (temp->m_south != nullptr) southCode = temp->m_south->m_code;
            else southCode = -1;
            if (temp->m_east != nullptr) eastCode = temp->m_east->m_code;
            else eastCode = -1;
            if (temp->m_west != nullptr) westCode = temp->m_west->m_code;
            else westCode = -1;
            cout << temp->m_code << 
                    " (" << 
                    "P: " << temp->m_passengers << 
                    ", N: " << northCode <<
                    ", S: " << southCode <<
                    ", E: " << eastCode <<
                    ", W: " << westCode <<
                    ")" << endl;
            temp = temp->m_next;
        }
    }
}

bool Railroad::makeRoute(list< pair<int,DIRECTION> > route){

    //a single station or empty route require no changes
    //but if a singular station does not exist in the Route, then it is an error case
    //this block of code before hand handles any 1 or 0 routes
    if (route.size() < 1) {
        //completely empty route
        return true;
    }
    else if (route.size() == 1) {
        if (codeMatch(route.begin()->first) == nullptr) { 
            //the only station is technically the first station
            //so it needs to exist
            return false;
        }
        else {
            //if the first station exists
            return true;
        }
    }

    //make sure the route is valid
    if (validRoute(route) == false) {
        return false;
    }

   
    for (list < pair < int, DIRECTION> >::iterator it = route.begin(); (it != route.end()); it++) {

        Station* copy = codeMatch(it->first); //the station where we add the link

        //check if the first station in the route is already in (return false if it isn't)
        if (it == route.begin() && codeMatch(it->first) == nullptr) { return false; }

        //if station doesn't actually exist
        if (copy == nullptr) {
            //then we create it and set copy to it
            extendAtHead(it->first, 0);
            copy = m_head;

        }

        //first if just to prevent linkage if this is the final station in the route
        if (next(it) == route.end()) {
            //nothing occurs here, just to prevent any of the other statements from executing
            //ideally the direction should be NONE in the last item, but this is a failsafe if that isn't the case
        }
        else if (it->second == NORTH) {
            //move iterator to the next item temporarily
            it++;
            if (it != route.end()) { //make sure we aren't going past bounds
                copy->setNorth(codeMatch(it->first, true));
            }
            //return iterator back to previous position
            it--;
        }
        else if (it->second == SOUTH) {
            //move iterator to the next item temporarily
            it++;
            if (it != route.end()) {
                copy->setSouth(codeMatch(it->first, true));
            }
            //return iterator back to previous position
            it--;
        }
        else if (it->second == EAST) {
            //move iterator to the next item temporarily
            it++;
            if (it != route.end()) {
                copy->setEast(codeMatch(it->first, true));
            }
            //return iterator back to previous position
            it--;
        }
        else if (it->second == WEST) {
            //move iterator to the next item temporarily
            it++;
            if (it != route.end()) {
                copy->setWest(codeMatch(it->first, true));
            }
            //return iterator back to previous position
            it--;
        }
    }
    
    return true;
}

int Railroad::travel(list< pair<int,DIRECTION> > route){
    
    int totalPassengers = 0;

    for (list < pair<int, DIRECTION> >::iterator it = route.begin(); it != route.end(); it++) {

        Station* tempStation = codeMatch(it->first);

        //if station does not exist return -1 since it failed
        if (tempStation == nullptr) { return -1; }

        //this function returns true if there is no link meaning it failed
        if (openDirection(it->second, tempStation) == true) {   
            if (next(it) != route.end()) {
                return -1;
            }     
        }

        //this block makes sure we don't have any Stations that link to itself
        if (next(it) != route.end()) {

            if (tempStation->getStationCode() == next(it)->first) {
                return -1;
            }
        }


        //now we know there is a link, so check if the link is the right one...
        //...after making sure that we aren't on the final element of the list

        if (next(it) == route.end()) {
            //prevent the other statements from executing if this is the last station
            //since the last one has no link
            //this is a failsafe against bad (but still valid) routes
        }
        else if (it->second == NORTH) {
            if (tempStation->getNorth()->getStationCode() != next(it)->first) {
                return -1;
            }
        }
        else if (it->second == SOUTH) {
            if (tempStation->getSouth()->getStationCode() != next(it)->first) {
                return -1;
            }
        }
        else if (it->second == EAST) {
            if (tempStation->getEast()->getStationCode() != next(it)->first) {
                return -1;
            }
        }
        else if (it->second == WEST) {
            if (tempStation->getWest()->getStationCode() != next(it)->first) {
                return -1;
            }
        }
        else if (it->second == NONE) {
            //if a NONE is somewhere before the end of a list
            if(next(it) != route.end()){
                return -1;
            }
        }

        //add the passengers from this station
        totalPassengers += tempStation->getNumPassegers();

    }

    //if we get here thats because the route is valid
    return totalPassengers;
}

bool Railroad::setNumPassengers(int code, int passengers){
    
    //first try and pull the station needed
    Station* temp = codeMatch(code);

    //if temp is nullptr station doesn't exist
    if (temp == nullptr) {
        return false;
    }
    //ensure a valid number of passengers
    else if (passengers < 0) {
        return false;
    }

    //otherwise set the number of passengers
    temp->setNumPassengers(passengers);
    return true;
}

bool Railroad::removeStation(int aCode){
    
    Station* toBeDeleted = codeMatch(aCode); //to delete the station

    //station does not exist
    if (toBeDeleted == nullptr) {
        return false;
    }
    
    Station* linkRemover = m_head; //for removing any links

    while (linkRemover != nullptr) {

        //remove any links to the station that is set to be removed
        if (linkRemover->getEast() != nullptr) {
            if (linkRemover->getEast()->getStationCode() == aCode) {
                linkRemover->setEast(nullptr);
            }
        }
        if (linkRemover->getWest() != nullptr) {
            if (linkRemover->getWest()->getStationCode() == aCode) {
                linkRemover->setWest(nullptr);
            }
        }
        if (linkRemover->getNorth() != nullptr) {
            if (linkRemover->getNorth()->getStationCode() == aCode) {
                linkRemover->setNorth(nullptr);
            }
        }
        if (linkRemover->getSouth() != nullptr) {
            if (linkRemover->getSouth()->getStationCode() == aCode) {
                linkRemover->setSouth(nullptr);
            }
        }     
        
        linkRemover = linkRemover->getNext();
    }
    
    //first not off any of the potential edge cases
    //
    //edge case, if this station is the only 1
    if (m_numStations == 1) {
        m_head = nullptr;
        m_tail = nullptr;
    }
    else if (toBeDeleted == m_head) {

        //if this is the head
        m_head = m_head->getNext();
        m_head->setPrevious(nullptr);

    }
    else if (toBeDeleted == m_tail) {

        //if this is the tail
        m_tail = m_tail->getPrevious();
        m_tail->setNext(nullptr);
    }
    else { //normal case

        //connect the previous and next stations of the one that is being removed
        toBeDeleted->getNext()->setPrevious(toBeDeleted->getPrevious());
        toBeDeleted->getPrevious()->setNext(toBeDeleted->getNext());

    }

    delete toBeDeleted;
    toBeDeleted = nullptr;
    m_numStations--;

    return true;
}

void Railroad::clearAllRoutes(){
    
    Station* tempStation = m_head; //to jiterate through all stations

    while (tempStation != nullptr) {
        
        //remove all links from every station
        tempStation->setEast(nullptr);
        tempStation->setNorth(nullptr);
        tempStation->setSouth(nullptr);
        tempStation->setWest(nullptr);

        tempStation = tempStation->getNext();
    }
}

const Railroad & Railroad::operator=(const Railroad & rhs){
    
    //protect against self assignment
    if (this == &rhs) {
        return *this;
    }

    //clean-up previous memory in case it is there
    //this also initalizes m_numStations
    this->clearNetwork();

    Station* tempStation = rhs.m_tail; //to iterate and pull data

    //iterate reverse and insert them at head to get the order right
    while (tempStation != nullptr) {

        //create new Stations with new memory but same info from rhs
        extendAtHead(tempStation->getNumPassegers(), tempStation->getStationCode());
        
        tempStation = tempStation->getPrevious(); //iterate backwards since were inserting the other way
    }

    tempStation = rhs.m_head;
    Station* newTempStation = m_head; //now to reiterate and set up all the links

    while ((tempStation != nullptr) && (newTempStation != nullptr)) {

        //first make sure that there is a route component to copy, and then copy it to the new one
        if (tempStation->getNorth() != nullptr) {
            newTempStation->setNorth(codeMatch(tempStation->getNorth()->getStationCode()));
        }
        else if (tempStation->getSouth() != nullptr) {
            newTempStation->setSouth(codeMatch(tempStation->getSouth()->getStationCode()));
        }
        else if (tempStation->getEast() != nullptr) {
            newTempStation->setEast(codeMatch(tempStation->getEast()->getStationCode()));
        }
        else if (tempStation->getWest() != nullptr) {
            newTempStation->setWest(codeMatch(tempStation->getWest()->getStationCode()));
        }

        //then keep iterating
        tempStation = tempStation->getNext();
        newTempStation = newTempStation->getNext();

    }

    return *this;
}

Railroad::Railroad(const Railroad & rhs){

    //first initialize values
    m_head = nullptr;
    m_tail = nullptr;
    m_numStations = 0;
    
    Station* tempStation = rhs.m_tail; //to iterate and pull data

    //iterate reverse and insert them at head to get the order right
    while (tempStation != nullptr) {

        //create new Stations with new memory but same info from rhs
        extendAtHead(tempStation->getNumPassegers(), tempStation->getStationCode());

        tempStation = tempStation->getPrevious(); //iterate backwards since were inserting the other way

    }

    tempStation = rhs.m_head;
    Station* newTempStation = m_head; //now to reiterate and set up all the links

    while ((tempStation != nullptr) && (newTempStation != nullptr)) {

        //first make sure that there is a route component to copy, and then copy it to the new one
        if (tempStation->getNorth() != nullptr) {
            newTempStation->setNorth(codeMatch(tempStation->getNorth()->getStationCode()));
        }
        else if (tempStation->getSouth() != nullptr) {
            newTempStation->setSouth(codeMatch(tempStation->getSouth()->getStationCode()));
        }
        else if (tempStation->getEast() != nullptr) {
            newTempStation->setEast(codeMatch(tempStation->getEast()->getStationCode()));
        }
        else if (tempStation->getWest() != nullptr) {
            newTempStation->setWest(codeMatch(tempStation->getWest()->getStationCode()));
        }

        //then keep iterating
        tempStation = tempStation->getNext();
        newTempStation = newTempStation->getNext();

    }
}


//-------------------------------------
//private helper functions implented here

//return the station given the code
    //will create the station and add it to the linked list if needed
Station* Railroad::codeMatch(int code, bool create) {

    //quickly make sure the station code is valid
    if (code < 1) {
        return nullptr;
    }

    //step 1: try and find and return pointer to existing station
    Station* temp = m_head;

    while (temp != nullptr) {

        //see if this is the right station and return if so
        if (temp->getStationCode() == code) {
            return temp;
        }

        //move on otherwise
        temp = temp->getNext();
    }

    //temp should be a null pointer if it gets here (intentional)
    if (!create) {
        return temp;
    }

    //if code continues here we make a new node 
    extendAtHead(code, DEFNUMPASS);
    return m_head;

}

//make sure that the route is valid
//will "scout" the linked list to make sure that it is possible
//to implement the route before adding it in.
bool Railroad::validRoute(list < pair < int, DIRECTION > > route) {

    //first thing is first, iterate throught the loop to see if there are any link conflicts...
    //...that are within the route itself, by checking for any identical items in the list excluding the final one
    for (list < pair < int, DIRECTION> >::iterator i = route.begin(); next(i) != route.end(); i++) {
        for (list < pair < int, DIRECTION> >::iterator j = route.begin(); next(j) != route.end(); j++) {

            //make sure we aren't comparing the same thing
            //then check to see if the direction and station code are the same
            //if they are, then check if the links are the same
            if (i != j && i->first == j->first && i->second == j->second) {
                
                //if the links are not the same...
                if (next(i)->first != next(j)->first) {
                    //...then return false
                    return false;
                }
            }
        }
    }
    //if we get through the above loop without returning false,
    //then we can check all the other cases for an invalid route

    //iterate through the list
    for (list < pair < int, DIRECTION> >::iterator it = route.begin(); it != route.end(); it++) {

        Station* tempStation = codeMatch(it->first);

        //verify that the Station itself is valid (no negative code)
        if (it->first < 1) {
            return false;
        }

        //make sure that there is no NONE in the middle of the list
        if (it->second == NONE && next(it) != route.end()) {
            return false;
        }

        //verify that the link isn't to itself
        if (next(it) != route.end() && it->first == next(it)->first) {
            return false;
        }

        //if the station isn't in the linked list it would be added (and doesn't need to be checked here)
        if (tempStation != nullptr) {

            //verify an existing link isn't being overwritten
            if (openDirection(it->second, tempStation) == false) {

                //make sure that this isn't the last Station
                if (next(it) != route.end()) {

                    //peak at next Station
                    Station* nextStation = codeMatch(next(it)->first);

                    //if the next station does not exist
                    //that means that we have an overwrite present
                    if (nextStation == nullptr) {
                        return false;
                    }
                    //verify that the existing link isn't identical to the one the code wants to put in
                    else if (!sameLink(tempStation, nextStation, it->second)) {
                        return false;
                    }
                }
            }
        }
    }

    return true; //if the route is valid it will come here
}

//This function takes a Station pointer and Direction and returns false
// if the direction is already used in the Station for another route
// if it isn't used, returns true
bool Railroad::openDirection(DIRECTION direction, Station* station) {

    //check, based on direction that another route doesn't
    //already use that direction
    if (direction == NORTH) {
        if (station->getNorth() == nullptr) {
            return true;
        }
    }
    else if (direction == SOUTH) {
        if (station->getSouth() == nullptr) {
            return true;
        }
    }
    else if (direction == EAST) {
        if (station->getEast() == nullptr) {
            return true;
        }
    }
    else if (direction == WEST) {
        if (station->getWest() == nullptr) {
            return true;
        }
    }
    else if (direction == NONE) {
        return true;
    }

    //if another route conflicts here
    return false;
}

//will remove the head of a route
void Railroad::removeHead() {

    //handle the edge cases first, otherwise delete in the normal case
    if (m_numStations == 1) {
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
    }
    else if (m_numStations == 2) {
        delete m_head;
        m_head = m_tail;
    }
    else {

        //set the item after head to be head and delete the memory held by the outgoing head
        Station* temp = m_head;
        m_head = m_head->m_next;
        delete temp;
        temp = nullptr;
        m_head->setPrevious(nullptr);
    }

    //update the size of the linked list
    m_numStations--;

}

//this function checks to see if an existing link that would normally cause an overwrite error...
// ...is actually the same link as the one being written, which is allowed
bool Railroad::sameLink(Station* currStation, Station* nextStation, DIRECTION direction) {

    //depending on direction...
    //...see if an existing link is identical to a link that we want to add
    if (direction == NORTH) {
        if (nextStation->getStationCode() == currStation->getNorth()->getStationCode()) {
            return true;
        }
    }
    else if (direction == SOUTH) {
        if (nextStation->getStationCode() == currStation->getSouth()->getStationCode()) {
            return true;
        }
    }
    else if (direction == EAST) {
        if (nextStation->getStationCode() == currStation->getEast()->getStationCode()) {
            return true;
        }
    }
    else if (direction == WEST) {
        if (nextStation->getStationCode() == currStation->getWest()->getStationCode()) {
            return true;
        }
    }

    return false;

}