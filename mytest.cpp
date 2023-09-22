/*
Filename: mytest.cpp
Date: 9/22/2022
Name: David Premkumar
email: davidp3@umbc.edu
Descrpition: This file is my implentation of the railroad tester
*/

#include "railroad.h"

class Tester {

	public:

	/*
	This function tests a normal case extend at head
	Will pass if all rails are added properly
	*/
	bool testExtendAtHeadNormal();

	/*
	This function tests an error case with extend at head
	Will pass if all error cases return false
	*/
	bool testExtendAtHeadError();

	/*
	This function tests a normal case extend at tail
	Will pass if all rails are added properly
	*/
	bool testExtendAtTailNormal();

	/*
	This function tests an error case with extend at tail
	Will pass if all error cases return false
	*/
	bool testExtendAtTailError();

	/*
	This function tests normal cases of remove station
	Will pass if all stations are removed properly
	*/
	bool testRemoveStationNormal();


	/*
	This function tests the 3 error cases involving removing a station
	Will pass if all 3 tests pass
	*/
	bool testRemoveStationError();


	/*
	This function tests whether route links to a station will be properly removed
	Returns true if all traces of station are gone from routes (pass)
	*/
	bool testRemoveStationRoutes();


	/*
	This function tests whether the assignment operator works with normal cases
	Returns true if new memory is allocated and all values are the same
	*/
	bool testAssignmentOperatorNormal();

	/*
	This function tests whether the assignment operator works with edge cases
	Returns true if new memory is allocated and all values are the same
	*/
	bool testAssignmentOperatorEdge();


	/*
	This function tests whether the copy works with normal cases
	Returns true if new memory is allocated and all values are the same
	*/
	bool testCopyConstructorNormal();


	/*
	This function tests whether the copy constructor works with edge cases
	Returns true if new memory is allocated and all values are the same
	*/
	bool testCopyConstructorEdge();

	/*
	This function tests whether makeRoute will return false if the start station does not exist
	Passes if it returns false, fails other wise
	*/
	bool testMakeRouteNonExistant();


	/*
	This function tests whether makeRoute will return false if there is an attempt to overwrite a link
	Passes if it returns false, fails otherwise
	*/
	bool testMakeRouteOverwrite();

	/*
	This function tests whether makeRoute will accept a route with 1 or 0 elements
	Returns true if makeRoute returns true and vice versa
	*/
	bool testMakeRouteEdge();

	/*
	This function tests the makeRoute function in a normal case
	Returns true if the route is made properly, false otherwise
	*/
	bool testMakeRouteNormal();


	/*
	This function tests whether the travel function works on a normal case
	Passes if it returns the right amount of passengers
	*/
	bool testTravelNormal();

	/*
	This function tests whether the travel function works on a normal case
	Passes if it returns -1, or fails otherwise
	*/
	bool testTravelError();


	/*
	This function tests whether the travel function handles an edge case
	Passes if it returns 0, or fails otherwise
	*/
	bool testTravelEdge();

	/*
	This function tests whether setNumPassengers() handles a normal case
	Returns true if it does, false otherwise
	*/
	bool testSetNumPassengersNormal();


	/*
	This function tests whether setNumPassengers() handles error cases
	Returns true if it does, false otherwise
	*/
	bool testSetNumPassengersError();


	/*
	This function tests to see if removeStation() works
	Returns true if station isn't present and all links to it are gone, false otherwise
	*/
	bool testRemoveStation();


	/*
	This function tests to see if clearAllRoutes() works in a normal case
	Returns true if if all links are cut, false otherwise
	*/
	bool testClearAllRoutes();


	/*
	This function tests to see if clear() and by extension, the destructor work
	Returns true if the station is fully cleared, false otherwise
	*/
	bool testClearNetwork();

};

int main() {

	//in main() we call all the functions and run them
	//use ternary operator to specify whether the test passed or not

	Tester railRoadTester;
	
	cout << "Now Initiating All testCases for the Railroad class\n";

	cout << ((railRoadTester.testExtendAtHeadNormal()) ? "Test Passed\n" : "Test Failed\n");

	cout << ((railRoadTester.testExtendAtHeadError()) ? "Test Passed\n" : "Test Failed\n");
	
	cout << ((railRoadTester.testExtendAtTailNormal()) ? "Test Passed\n" : "Test Failed\n");

	cout << ((railRoadTester.testExtendAtTailError()) ? "Test Passed\n" : "Test Failed\n");

	cout << ((railRoadTester.testRemoveStationNormal()) ? "Test Passed\n" : "Test Failed\n");

	cout << ((railRoadTester.testRemoveStationError()) ? "Test Passed\n" : "Test Failed\n");

	cout << ((railRoadTester.testRemoveStationRoutes()) ? "Test Passed\n" : "Test Failed\n");

	cout << ((railRoadTester.testAssignmentOperatorNormal()) ? "Test Passed\n" : "Test Failed\n");

	cout << ((railRoadTester.testAssignmentOperatorEdge()) ? "Test Passed\n" : "Test Failed\n");

	cout << ((railRoadTester.testCopyConstructorNormal()) ? "Test Passed\n" : "Test Failed\n");

	cout << ((railRoadTester.testCopyConstructorEdge()) ? "Test Passed\n" : "Test Failed\n");

	cout << ((railRoadTester.testMakeRouteNonExistant()) ? "Test Passed\n" : "Test Failed\n");

	cout << ((railRoadTester.testMakeRouteOverwrite()) ? "Test Passed\n" : "Test Failed\n");

	cout << ((railRoadTester.testMakeRouteNormal()) ? "Test Passed\n" : "Test Failed\n");

	cout << ((railRoadTester.testMakeRouteEdge()) ? "Test Passed\n" : "Test Failed\n");

	cout << ((railRoadTester.testTravelNormal()) ? "Test Passed\n" : "Test Failed\n");

	cout << ((railRoadTester.testTravelError()) ? "Test Passed\n" : "Test Failed\n");

	cout << ((railRoadTester.testTravelEdge()) ? "Test Passed\n" : "Test Failed\n");

	cout << ((railRoadTester.testSetNumPassengersNormal()) ? "Test Passed\n" : "Test Failed\n");

	cout << ((railRoadTester.testSetNumPassengersError()) ? "Test Passed\n" : "Test Failed\n");

	cout << ((railRoadTester.testRemoveStation()) ? "Test Passed\n" : "Test Failed\n");

	cout << ((railRoadTester.testClearAllRoutes()) ? "Test Passed\n" : "Test Failed\n");

	cout << ((railRoadTester.testClearNetwork()) ? "Test Passed\n" : "Test Failed\n");

	cout << "\nAll Tests Complete\n";

}

bool Tester::testExtendAtHeadNormal() {

	Railroad testRailroad;

	//-------------------------------------------------------------
	//first part is making sure that it adds 300 stations

	cout << "\nTesting a normal extend at head case\n";

	cout << "Inserting 300 stations\n";

	for (int i = 0; i < 300; i++) {
		
		if (testRailroad.extendAtHead(i + 1, i + 1) == false) {
			cout << "Railroad Tester Failed to add station# " << i + 1 << " -> Test Failed\n";
			return false;
		}
	}

	if (testRailroad.m_numStations != 300) {
		cout << "Extend at head did not add 300 stations\n";
		return false;
	}
	else {
		cout << "Successfully inserted 300 stations\n";
	}

	//--------------------------------------------------------------
	//now verify that the stations added properly

	cout << "Now checking to make sure the stations are correct" << endl;

	if((testRailroad.m_head == nullptr) || (testRailroad.m_tail == nullptr)){

		cout << "The head and tail Station were not properly initialized\n";
		return false;
	}
	else if ((testRailroad.m_head->m_code != 300) || (testRailroad.m_head->m_passengers != 300)) {
		//300 should be m_head since it was the final one added 
		cout << "The head station did not initalize its code of number of passnegers\n";
		return false;
	}
	else if ((testRailroad.m_tail->m_code != 1) || (testRailroad.m_tail->m_passengers != 1)) {
		cout << "The tail station did not initalize its code of number of passnegers\n";
		return false;
	}
	else {
		cout << "The head and tail station initalized properly\n";
	}

	Station* temp = testRailroad.m_head; //to iterate
	
	//iterate and make sure things added properly
	for(int i = 299; i >= 0; i--) {
		
		if (temp == nullptr) {
			cout << "Error at station " << i << " -> The stations was not properly added\n";
			return false;
		}
		else if ((temp->m_code != i + 1) || (temp->m_passengers != i + 1)) {
			cout << "Error at station " << i << " -> The station does not have the correct passengers or code\n";
			return false;
		}
		
		temp = temp->m_next;
	}

	cout << "All Tests passed, extend at head works properly \n";
	return true;
}


bool Tester::testExtendAtHeadError() {

	Railroad testRailroad;

	//populate a Railroad
	for (int i = 1; i < 10; i++) {
		testRailroad.extendAtHead(i + 1, i + 1);
	}

	cout << "\nTesting Extend At Head Error Cases\n";

	if (testRailroad.extendAtHead(22, -22)) { //negative passengers
		cout << "Fail -> Railroad accepts a station with negative passengers\n";
		return false;
	}
	else if (testRailroad.extendAtHead(-22, 22)) { //negative station code
		cout << "Fail -> Railroad accepts a station with a negative code \n";
		return false;
	}
	else if (testRailroad.extendAtHead(3, 3)) { //duplicate station code
		cout << "Fail -> Railroad accepts a duplicate station code\n";
		return false;
	}

	//if we reach here the tests have passed
	cout << "Pass -> Railroad does not accept negative station codes or passengers, or duplicate codes\n";

	return true;

}


bool Tester::testExtendAtTailNormal() {

	Railroad testRailroad;

	//-------------------------------------------------------------
	//first part is making sure that it adds 300 stations

	cout << "\nTesting a normal extend at tail case\n";

	cout << "Inserting 300 stations\n";

	for (int i = 0; i < 300; i++) {

		if (testRailroad.extendAtTail(i + 1, i + 1) == false) {
			cout << "Railroad Tester Failed to add station# " << i + 1 << " -> Test Failed\n";
			return false;
		}
	}

	if (testRailroad.m_numStations != 300) {
		cout << "Extend at tail did not add 300 stations\n";
		return false;
	}
	else {
		cout << "Successfully inserted 300 stations\n";
	}

	//--------------------------------------------------------------
	//now verify that the stations added properly

	cout << "Now checking to make sure the stations are correct" << endl;

	if ((testRailroad.m_head == nullptr) || (testRailroad.m_tail == nullptr)) {

		cout << "The head and tail Station were not properly initialized\n";
		return false;
	}
	else if ((testRailroad.m_tail->m_code != 300) || (testRailroad.m_tail->m_passengers != 300)) {
		//300 is the station code of m_tail since it was added last
		cout << "The head station did not initalize its code of number of passengers\n";
		return false;
	}
	else if ((testRailroad.m_head->m_code != 1) || (testRailroad.m_head->m_passengers != 1)) {
		cout << "The tail station did not initalize its code of number of passnegers\n";
		return false;
	}
	else {
		cout << "The head and tail station initalized properly\n";
	}

	Station* temp = testRailroad.m_head; //to iterate

	//iterate and make sure things added properly
	for (int i = 0; i < 300; i++) {

		if (temp == nullptr) {
			cout << "Error at station " << i << " -> The stations was not properly added\n";
			return false;
		}
		else if ((temp->m_code != i + 1) || (temp->m_passengers != i + 1)) {
			cout << "Error at station " << i << " -> The station does not have the correct passengers or code\n";
			return false;
		}

		temp = temp->m_next;
	}

	cout << "All Tests passed, extend at head works properly \n";
	return true;
}


bool Tester::testExtendAtTailError() {

	Railroad testRailroad;

	//populate a Railroad
	for (int i = 1; i < 10; i++) {
		testRailroad.extendAtTail(i + 1, i + 1);
	}

	cout << "\nTesting Extend At Tail Error Cases\n";

	if (testRailroad.extendAtTail(22, -22)) { //negative passengers
		cout << "Fail -> Railroad accepts a station with negative passengers\n";
		return false;
	}
	else if (testRailroad.extendAtTail(-22, 22)) { //negative station code
		cout << "Fail -> Railroad accepts a station with a negative code \n";
		return false;
	}
	else if (testRailroad.extendAtTail(3, 3)) { //duplicate station code
		cout << "Fail -> Railroad accepts a duplicate station code\n";
		return false;
	}

	//if we reach here the tests have passed
	cout << "Pass -> Railroad does not accept negative station codes or passengers, or duplicate codes\n";

	return true;

}


bool Tester::testRemoveStationNormal() {

	Railroad testRailroad; //for testing

	cout << "\nNow Testing a normal case of remove station\n";

	//add a bunch of stations
	cout << "Adding Stations\n";
	for (int i = 0; i < 300; i++) {

		testRailroad.extendAtHead(i + 1, i + 1);
	}

	//now first remove a singular station and see if it worked properly
	//if code match doesn't return nullptr the station is still there some how
	//155 was chosen randomly
	if ((testRailroad.removeStation(155) == false) || (testRailroad.codeMatch(155) != nullptr)) {

		cout << "Removal of a single station failed\n";
		return false;
	}
	else {

		cout << "A single station was successfully removed\n";
	}

	//reinsert the station that was removed
	testRailroad.extendAtHead(155, 155);

	cout << "Now Testing the Removal of ALL the Stations\n";

	//iterate and remove every station
	for (int i = 0; i < 300; i++) {

		//if any removal doesn't work
		if (testRailroad.removeStation(i + 1) == false) {
			cout << "Failure to remove Station " << i << "\n";
			return false;
		}
	}

	//make sure m_head and m_tail are pointing to nullptr and that the size is 0
	if ((testRailroad.m_numStations != 0) && (testRailroad.m_head != nullptr) && (testRailroad.m_tail != nullptr)) {
		cout << "Station is not empty as it should be with the removal of all stations\n";
		return false;
	}


	//if the code reaches here, all tests passed
	cout << "All Tests passed, removeStation() works well for all normal cases.\n";
	return true;

}


bool Tester::testRemoveStationError() {

	Railroad testRailroad = Railroad(); //for testing

	cout << "\nNow Testing removeStation error cases\n";

	cout << "Now trying to remove a station from an empty railroad\n";

	//check if removeStation returns false (which is what we want for the error case)
	//also make sure that m_numStations is still 0 instead of something like -1
	if (testRailroad.removeStation(3) || testRailroad.m_numStations != 0) {
		cout << "Test Failed: Remove station tries to remove a station from an empty railroad\n";
		return false;
	}
	else {
		cout << "Test Passed: Remove station does not to remove a station from an empty railroad\n";
	}

	//now put some stations in and try to remove a non-existant station
	cout << "Now trying to remove a non-existant station from a railroad with stations in it\n";

	//populate the railroad
	for (int i = 0; i < 5; i++) {
		testRailroad.extendAtHead(i + 1, i + 1);
	}

	//now see if removeStation returns false when we try to remove a nonexistant station
	if (testRailroad.removeStation(8) || testRailroad.m_numStations != 5) {
		cout << "Test Failed: Remove station tries to remove a non-existant station from the railroad\n";
		return false;
	}
	else {
		cout << "Test Passed: Remove station does not to remove a non-existant station from the railroad\n";
	}

	//all test cases pass, then we get here and return true
	cout << "Test Cases passed, removeStation works for error cases \n";
	return true;
}


bool Tester::testRemoveStationRoutes() {

	Railroad testRailroad; //to apply the tests on

	//populate testRailroad with a few elements
	for (int i = 0; i < 5; i++) {
		testRailroad.extendAtHead(i + 1, 1 + 1);
	}

	//create a route in a list
	list<pair<int, DIRECTION>> aRoute;
	aRoute.push_back(pair<int, DIRECTION>(2, NORTH));
	aRoute.push_back(pair<int, DIRECTION>(4, SOUTH));
	aRoute.push_back(pair<int, DIRECTION>(3, WEST));
	aRoute.push_back(pair<int, DIRECTION>(4, EAST));
	aRoute.push_back(pair<int, DIRECTION>(5, NONE));

	//insert the route in the testRailroad
	testRailroad.makeRoute(aRoute);

	cout << "\nNow testing to see if removing a Station removes all links to it\n";

	//there are 2 links to this, so both need to be gone after this function executes
	testRailroad.removeStation(4); 

	//both of these SHOULD evaluate to nullptr if the route links are gone
	//so if it doesn't the test fails
	if (testRailroad.codeMatch(2)->getNorth() || testRailroad.codeMatch(3)->getEast()){

		cout << "Traces of the removed Station exists, test failed \n";
		return false;
	}
	else { //if both are nullptr we get here where the test passes
		cout << "All traces of removed Station gone from the routes, test passed \n";
		return true;
	}
}


bool Tester::testAssignmentOperatorNormal() {

	Railroad rightRailroad = Railroad(); //to be used on the right hand side

	//populate testRailroad with a few elements
	for (int i = 0; i < 5; i++) {
		rightRailroad.extendAtHead(i + 1, i + 1);
	}

	//create a route in a list
	list<pair<int, DIRECTION>> aRoute;
	aRoute.push_back(pair<int, DIRECTION>(2, NORTH));
	aRoute.push_back(pair<int, DIRECTION>(4, SOUTH));
	aRoute.push_back(pair<int, DIRECTION>(3, WEST));
	aRoute.push_back(pair<int, DIRECTION>(4, EAST));
	aRoute.push_back(pair<int, DIRECTION>(5, NONE));

	//insert the route
	rightRailroad.makeRoute(aRoute);

	cout << "\nNow Testing the overloaded assignment operator in normal cases\n";

	Railroad leftRailroad = Railroad();
	leftRailroad = rightRailroad;

	cout << "First checking to see if new memory has been adequately allocated\n";


	//first makesure both stations have the same numStations
	if (rightRailroad.m_numStations != leftRailroad.m_numStations) {
		cout << "The number of stations did not copy properly, test failed\n";
		return false;
	}
	else {
		cout << "The left-hand station is reporting the correct size\n";
	}

	//these 2 are to compare pointers
	Station* rightTemp = rightRailroad.m_head;
	Station* leftTemp = leftRailroad.m_head;

	while (rightTemp != nullptr && leftTemp != nullptr) {

		if (rightTemp == leftTemp) {
			cout << "Same memory adress detected in right and left hand side, test failed\n";
			return false;
		}

		rightTemp = rightTemp->getNext();
		leftTemp = leftTemp->getNext();
	}

	//all new memory was allocated if we get here
	cout << "Test Case Passed -> All new memory has been allocated \n";


	//Now comparing contents of the station (the routes). These need to be the same
	cout << "Now checking to make sure that the contents of the station are the same\n";

	rightTemp = rightRailroad.m_head;
	leftTemp = leftRailroad.m_head;

	//iterate through both in the same fashion, but compare this time.
	while (rightTemp != nullptr && leftTemp != nullptr) {

		//obvious before comparing, need to make sure that there is something there
		//since if we try to dereference a nullptr we would get a segmentation fault
		if (rightTemp->getEast() && leftTemp->getEast()) {

			if (rightTemp->getEast()->getStationCode() != leftTemp->getEast()->getStationCode()) {
				cout << "Content mismatch found between 2 railroads, test failed \n";
				return false;
			}

		}
		if (rightTemp->getWest() && leftTemp->getWest()) {

			if (rightTemp->getWest()->getStationCode() != leftTemp->getWest()->getStationCode()) {
				cout << "Content mismatch found between 2 railroads, test failed \n";
				return false;
			}

		}
		if (rightTemp->getNorth() && leftTemp->getNorth()) {

			if (rightTemp->getNorth()->getStationCode() != leftTemp->getNorth()->getStationCode()) {
				cout << "Content mismatch found between 2 railroads, test failed \n";
				return false;
			}

		}
		if (rightTemp->getSouth() && leftTemp->getSouth()) {

			if (rightTemp->getSouth()->getStationCode() != leftTemp->getSouth()->getStationCode()) {
				cout << "Content mismatch found between 2 railroads, test failed \n";
				return false;
			}

		}	

		//iterate to next item
		rightTemp = rightTemp->getNext();
		leftTemp = leftTemp->getNext();
	}

	//and if we get here, the test passed and no mismatches were seen
	cout << "All Contents Matched, Assignment Operator Test Passed for the Normal Case \n";
	return true;
}


bool Tester::testAssignmentOperatorEdge() {

	Railroad rightTemp = Railroad(); //right side of =
	Railroad leftTemp = Railroad(); //left side of =

	cout << "\nNow Testing the overloaded Assignment Operator in Edge Cases\n";

	cout << "First testing a single item copy\n";

	//first add an item to rightTemp and set that to be left temp
	rightTemp.extendAtHead(1, 1);
	
	leftTemp = rightTemp;

	//first make sure that new memory was allocated
	if (leftTemp.m_head == rightTemp.m_head) {
		cout << "New memory was not allocated, test failed \n";
		return false;
	}
	else {
		cout << "New memory was allocated\n";
	}

	//make sure all values were assigned
	if (leftTemp.m_head != leftTemp.m_tail || leftTemp.m_head->getStationCode() != 1 || leftTemp.m_head->getNumPassegers() != 1) {
		cout << "The data does not match, Single item copy failed\n";
		return false;
	}
	else {
		cout << "the Data matches, Single item copy passed\n";
	}


	//now add another item to rightTemp and try the overloaded assignment operator again
	rightTemp.extendAtHead(2, 2);

	leftTemp = rightTemp;

	cout << "Now testing a double item copy\n";

	//check to make sure that new memory is allocated
	if (leftTemp.m_head == rightTemp.m_head || leftTemp.m_tail == rightTemp.m_tail) {
		cout << "New memory was not fully allocated, test failed \n";
		return false;
	}
	else {
		cout << "New memory was allocated\n";
	}

	//now checking all the elements to see if they line up
	if (leftTemp.m_head->getStationCode() != 2 || leftTemp.m_head->getNumPassegers() != 2) {
		cout << "Copy failure at m_head\n";
	}
	else if (leftTemp.m_tail->getStationCode() != 1 || leftTemp.m_tail->getNumPassegers() != 1) {
		cout << "Copy failure at m_tail\n";
		return false;
	}
	else {
		cout << "Double item copy successful, all edge case tests passed\n";
	}

	//the test passed if control reaches here
	return true;

}


bool Tester::testCopyConstructorNormal() {

	Railroad sourceRailroad = Railroad(); //to be copied off

	//populate testRailroad with a few elements
	for (int i = 0; i < 5; i++) {
		sourceRailroad.extendAtHead(i + 1, i + 1);
	}

	//create a route in a list
	list<pair<int, DIRECTION>> aRoute;
	aRoute.push_back(pair<int, DIRECTION>(2, NORTH));
	aRoute.push_back(pair<int, DIRECTION>(4, SOUTH));
	aRoute.push_back(pair<int, DIRECTION>(3, WEST));
	aRoute.push_back(pair<int, DIRECTION>(4, EAST));
	aRoute.push_back(pair<int, DIRECTION>(5, NONE));

	//insert the route
	sourceRailroad.makeRoute(aRoute);

	cout << "\nNow Testing the copy constructor in normal cases\n";

	Railroad leftRailroad = Railroad(sourceRailroad);

	cout << "First checking to see if new memory has been adequately allocated\n";


	//first makesure both stations have the same numStations
	if (sourceRailroad.m_numStations != leftRailroad.m_numStations) {
		cout << "The number of stations did not copy properly, test failed\n";
		return false;
	}
	else {
		cout << "The left-hand station is reporting the correct size\n";
	}

	//these 2 are to compare pointers
	Station* rightTemp = sourceRailroad.m_head;
	Station* leftTemp = leftRailroad.m_head;

	//iterate and compare the both to make sure it is all new memory
	while (rightTemp != nullptr && leftTemp != nullptr) {

		if (rightTemp == leftTemp) {
			cout << "Same memory adress detected in right and left hand side, test failed\n";
			return false;
		}

		rightTemp = rightTemp->getNext();
		leftTemp = leftTemp->getNext();
	}

	//all new memory was allocated if we get here
	cout << "Test Case Passed -> All new memory has been allocated \n";


	//Now comparing contents of the station (the routes). These need to be the same
	cout << "Now checking to make sure that the contents of the station are the same\n";

	rightTemp = sourceRailroad.m_head;
	leftTemp = leftRailroad.m_head;

	//iterate through both in the same fashion, but compare this time.
	while (rightTemp != nullptr && leftTemp != nullptr) {

		//obvious before comparing, need to make sure that there is something there
		//since if we try to dereference a nullptr we would get a segmentation fault
		if (rightTemp->getEast() && leftTemp->getEast()) {

			if (rightTemp->getEast()->getStationCode() != leftTemp->getEast()->getStationCode()) {
				cout << "Content mismatch found between 2 railroads, test failed \n";
				return false;
			}

		}
		if (rightTemp->getWest() && leftTemp->getWest()) {

			if (rightTemp->getWest()->getStationCode() != leftTemp->getWest()->getStationCode()) {
				cout << "Content mismatch found between 2 railroads, test failed \n";
				return false;
			}

		}
		if (rightTemp->getNorth() && leftTemp->getNorth()) {

			if (rightTemp->getNorth()->getStationCode() != leftTemp->getNorth()->getStationCode()) {
				cout << "Content mismatch found between 2 railroads, test failed \n";
				return false;
			}

		}
		if (rightTemp->getSouth() && leftTemp->getSouth()) {

			if (rightTemp->getSouth()->getStationCode() != leftTemp->getSouth()->getStationCode()) {
				cout << "Content mismatch found between 2 railroads, test failed \n";
				return false;
			}

		}

		//iterate to next item
		rightTemp = rightTemp->getNext();
		leftTemp = leftTemp->getNext();
	}

	//and if we get here, the test passed and no mismatches were seen
	cout << "All Contents Matched, Copy Constructor Test Passed for the Normal Case \n";
	return true;
}


bool Tester::testCopyConstructorEdge() {
	
	Railroad sourceTemp = Railroad(); //source to be copied from

	cout << "\nNow Testing the Copy Constructor in Edge Cases\n";

	cout << "First testing a single item copy\n";

	//first add an item to rightTemp and set that to be left temp
	sourceTemp.extendAtHead(1, 1);

	Railroad leftTemp1 = Railroad(sourceTemp); //the one that copies from source

	//first make sure that new memory was allocated
	if (leftTemp1.m_head == sourceTemp.m_head) {
		cout << "New memory was not allocated, test failed \n";
		return false;
	}
	else {
		cout << "New memory was allocated\n";
	}

	//make sure all values were assigned
	if (leftTemp1.m_head != leftTemp1.m_tail || leftTemp1.m_head->getStationCode() != 1 || leftTemp1.m_head->getNumPassegers() != 1) {
		cout << "The data does not match, Single item copy failed\n";
		return false;
	}
	else {
		cout << "the Data matches, Single item copy passed\n";
	}


	//now add another item to rightTemp and try the overloaded assignment operator again
	sourceTemp.extendAtHead(2, 2);

	Railroad leftTemp2 = Railroad(sourceTemp); //the next railroad to test the edge case of 2 stations in the railroad

	cout << "Now testing a double item copy\n";

	//check to make sure that new memory is allocated
	if (leftTemp2.m_head == sourceTemp.m_head || leftTemp2.m_tail == sourceTemp.m_tail) {
		cout << "New memory was not fully allocated, test failed \n";
		return false;
	}
	else {
		cout << "New memory was allocated\n";
	}

	//now checking all the elements to see if they line up
	if (leftTemp2.m_head->getStationCode() != 2 || leftTemp2.m_head->getNumPassegers() != 2) {
		cout << "Copy failure at m_head\n";
	}
	else if (leftTemp2.m_tail->getStationCode() != 1 || leftTemp2.m_tail->getNumPassegers() != 1) {
		cout << "Copy failure at m_tail\n";
		return false;
	}
	else {
		cout << "Double item copy successful, all edge case tests passed\n";
	}

	//the test passed if control reaches here
	return true;
}


bool Tester::testMakeRouteNonExistant() {

	//make sure MakeRoute returns false if it tries to make a station with a starting station
	cout << "\nNow Testing to see if MakeRoute rejects a route where the starting station doesn't exist\n";

	//first create a railRoad and fill it up
	Railroad testRailroad = Railroad();

	for (int i = 0; i < 5; i++) {
	
		testRailroad.extendAtHead(i + 1, i + 1);
	}

	//create a route in a list
	list<pair<int, DIRECTION>> aRoute;
	aRoute.push_back(pair<int, DIRECTION>(33, SOUTH));
	aRoute.push_back(pair<int, DIRECTION>(2, NORTH));
	aRoute.push_back(pair<int, DIRECTION>(4, SOUTH));
	aRoute.push_back(pair<int, DIRECTION>(3, WEST));
	aRoute.push_back(pair<int, DIRECTION>(4, EAST));
	aRoute.push_back(pair<int, DIRECTION>(5, NONE));


	//insert the route and see if it is rejected
	if (testRailroad.makeRoute(aRoute)) {

		cout << "The railroad accepts the route despite not having the first Station, Fail\n";
		return false;
	}
	else {

		cout << "The railroad does not accept a route when it doesn't have the first station in it, Pass\n";
		return true;
	}

}

bool Tester::testMakeRouteOverwrite() {

	//making sure that MakeRoute won't overwrite an existing link
	cout << "\nNow testing to see if MakeRoute won't overwrite an existing link\n";

	//first create a railRoad and fill it up
	Railroad testRailroad = Railroad();

	for (int i = 0; i < 12; i++) {

		testRailroad.extendAtTail(i + 1, i + 1);
	}


	//create a route in a list
	list<pair<int, DIRECTION>> aRoute;
	aRoute.push_back(pair<int, DIRECTION>(2, NORTH));
	aRoute.push_back(pair<int, DIRECTION>(4, SOUTH));
	aRoute.push_back(pair<int, DIRECTION>(3, WEST));
	aRoute.push_back(pair<int, DIRECTION>(4, EAST));
	aRoute.push_back(pair<int, DIRECTION>(22, EAST));
	aRoute.push_back(pair<int, DIRECTION>(5, NONE));

	testRailroad.makeRoute(aRoute);

	//now make an opposing route with a link conflict
	list<pair<int, DIRECTION>> bRoute;
	bRoute.push_back(pair<int, DIRECTION>(2, EAST));
	bRoute.push_back(pair<int, DIRECTION>(4, SOUTH));
	bRoute.push_back(pair<int, DIRECTION>(6, NORTH));
	bRoute.push_back(pair<int, DIRECTION>(4, NORTH));
	bRoute.push_back(pair<int, DIRECTION>(9, NORTH));

	//bRoute should not be inserted since it conflicts with aRoute
	if (testRailroad.makeRoute(bRoute)) {
		
		cout << "MakeRoute does not return false, test failed \n";
		return false;
	}
	else {
		cout << "MakeRoute returns false without changing anything, test passed \n";
	}

	//if we get here the test passed
	return true;
}


bool Tester::testMakeRouteNormal(){
	
	cout << "\nNow Testing to see if makeRoute() handles a normal case\n";

	//first create a railRoad and fill it up
	Railroad testRailroad = Railroad();

	for (int i = 0; i < 12; i++) {

		testRailroad.extendAtTail(i + 1, i + 1);
	}


	//create a route in a list
	list<pair<int, DIRECTION>> aRoute;
	aRoute.push_back(pair<int, DIRECTION>(2, NORTH));
	aRoute.push_back(pair<int, DIRECTION>(4, SOUTH));
	aRoute.push_back(pair<int, DIRECTION>(3, WEST));
	aRoute.push_back(pair<int, DIRECTION>(4, EAST));
	aRoute.push_back(pair<int, DIRECTION>(22, EAST));
	aRoute.push_back(pair<int, DIRECTION>(5, NONE));

	//insert the route
	testRailroad.makeRoute(aRoute);

	cout << "Now verifying that a route was inserted properly\n";

	//now check to see if all the routes links exist
	if (testRailroad.codeMatch(2)->getNorth()->getStationCode() != 4) {
		cout << "Error at insertion detected, test failed\n";
		return false;
	}
	else if (testRailroad.codeMatch(4)->getSouth()->getStationCode() != 3) {
		cout << "Error at insertion detected, test failed\n";
		return false;
	}
	else if (testRailroad.codeMatch(3)->getWest()->getStationCode() != 4) {
		cout << "Error at insertion detected, test failed\n";
		return false;
	}
	else if (testRailroad.codeMatch(4)->getEast()->getStationCode() != 22) {
		cout << "Error at insertion detected, test failed\n";
		return false;
	}
	else if (testRailroad.codeMatch(22)->getEast()->getStationCode() != 5) {
		cout << "Error at insertion detected, test failed\n";
		return false;
	}

	//if it gets through those above stations the test passed
	//whether travel() handles this is tested in the travel function test
	cout << "All route links exist, test pass \n";
	return true;

}


bool Tester::testMakeRouteEdge() {

	cout << "\nNow Testing to see if makeRoute handles an edge case\n";

	//first create a railRoad and fill it up
	Railroad testRailroad = Railroad();

	for (int i = 0; i < 12; i++) {

		testRailroad.extendAtTail(i + 1, i + 1);
	}

	//simply verify that makeRoute does properly take 1 station and 0 station routes

	//then set up a 1 and 0 station route
	list<pair<int, DIRECTION>> route1;
	list<pair<int, DIRECTION>> route0;

	route1.push_back(pair<int, DIRECTION>(3, SOUTH));

	//see if makeRoute returns true;
	if (testRailroad.makeRoute(route1) && testRailroad.makeRoute(route0)) {
		cout << "1 and 0 station routes are handled properly, test passed\n";
		return true;
	}

	//if the above doesn't execute the test failed
	cout << "1 and 0 station routes are NOT handled properly, test failed\n";
	return false;
}


bool Tester::testTravelNormal() {

	//make sure MakeRoute returns false if it tries to make a station with a starting station
	cout << "\nNow Testing to see if Travel works in a normal case\n";

	//first create a railRoad and fill it up
	Railroad testRailroad = Railroad();

	for (int i = 0; i < 5; i++) {

		testRailroad.extendAtHead(i + 1, i + 1);
	}

	//create a route in a list
	list<pair<int, DIRECTION>> aRoute;
	aRoute.push_back(pair<int, DIRECTION>(2, NORTH));
	aRoute.push_back(pair<int, DIRECTION>(4, SOUTH));
	aRoute.push_back(pair<int, DIRECTION>(3, WEST));
	aRoute.push_back(pair<int, DIRECTION>(4, EAST));
	aRoute.push_back(pair<int, DIRECTION>(5, NONE));

	testRailroad.makeRoute(aRoute);

	//insert the route and see if it is rejected
	if (testRailroad.travel(aRoute) == 18) {

		cout << "The travel function visited the right number of passengers, pass\n";
		return true;
	}
	else if (testRailroad.travel(aRoute) == -1) {

		cout << "The travel function indicates failure despite the route being valid, fail\n";
		return false;
	}
	else {
		cout << "The travel function did not return the right number of passnegers, fail\n";
	}

	//if we get here, the function did not pass
	return false;
}


bool Tester::testTravelError() {
	//test to see if travel() handles error cases

	cout << "\nNow Testing to see if travel will reject an invalid route\n";

	//first intialize Railroad
	Railroad testRailroad = Railroad();

	for (int i = 0; i < 5; i++) {

		testRailroad.extendAtHead(i + 1, i + 1);
	}


	//create a valid route in a list
	list<pair<int, DIRECTION>> aRoute;
	aRoute.push_back(pair<int, DIRECTION>(2, NORTH));
	aRoute.push_back(pair<int, DIRECTION>(4, SOUTH));
	aRoute.push_back(pair<int, DIRECTION>(3, WEST));
	aRoute.push_back(pair<int, DIRECTION>(4, EAST));
	aRoute.push_back(pair<int, DIRECTION>(5, NONE));

	//add it to testRailroad
	testRailroad.makeRoute(aRoute);

	//create an invalid route in a list
	//invalid as in it doesn't fully exist within testRailroad
	list<pair<int, DIRECTION>> bRoute;
	bRoute.push_back(pair<int, DIRECTION>(2, NORTH));
	bRoute.push_back(pair<int, DIRECTION>(4, SOUTH));
	bRoute.push_back(pair<int, DIRECTION>(3, WEST));
	bRoute.push_back(pair<int, DIRECTION>(2, EAST));
	bRoute.push_back(pair<int, DIRECTION>(5, NONE));

	
	//try to travel it
	if (testRailroad.travel(bRoute) == -1) {
		cout << "travel() returns -1, pass\n";
		return true;
	}

	//or if it doesn't return -1
	cout << "travel does not reject the incompatible route, fail\n";
	return false;
}


bool Tester::testTravelEdge() {

	cout << "\nNow Testing to see if travel() handles an edge case\n";

	//first create a railRoad and fill it up
	Railroad testRailroad = Railroad();

	for (int i = 0; i < 12; i++) {

		testRailroad.extendAtTail(i + 1, i + 1);
	}

	//simply verify that travel() does properly look through 1 station and 0 station routes

	//then set up a 1 and 0 station route
	list<pair<int, DIRECTION>> route1;
	list<pair<int, DIRECTION>> route0;

	//now verify that travel() can take 0 or 1 station routes (returning 0 of course)
	if (testRailroad.travel(route1) == 0 && testRailroad.travel(route0) == 0) {
		cout << "1 and 0 station routes are handled properly, test passed\n";
		return true;
	}

	//if not tell the user and return false
	cout << "1 and 0 station routes are not handled properly, test failed\n";
	return false;

}


bool Tester::testSetNumPassengersNormal() {

	Railroad testRailroad; //for testing

	//see if setNumPassengers handles a normal case

	for (int i = 0; i < 5; i++) {
		testRailroad.extendAtTail(i + 1, i + 1);
	}

	cout << "\nNow testing setNumPassengers in a normal case\n";

	//set a new passenger amount
	testRailroad.setNumPassengers(3, 19);

	//now see if the numbers match-up
	if (testRailroad.codeMatch(3)->m_passengers != 19) {
		cout << "setNumPassengers failed in a normal case\n";
		return false;
	}

	//if we get here the test passed
	cout << "setNumPassengers worked in a normal case\n";
	return true;
}


bool Tester::testSetNumPassengersError() {

	Railroad testRailroad; //for testing

	//see if setNumPassengers handles an error case

	for (int i = 0; i < 5; i++) {
		testRailroad.extendAtTail(i + 1, i + 1);
	}

	cout << "\nNow testing setNumPassengers in an error case\n";

	//now see if setNumPassengers fails in both error cases
	//station doesn't exist AND invalid passenger amount (less than 0) are tested
	if (testRailroad.setNumPassengers(11, 22) || testRailroad.setNumPassengers(34, 22)) {
		cout << "setNumPassengers failed to reject bad data in an error case\n";
		return false;
	}

	//if we get here the test passed
	cout << "setNumPassengers properly rejected bad data in an error case\n";
	return true;
}


bool Tester::testRemoveStation() {

	Railroad testRailroad; //for testing

	//check if remove Station works as intended

	cout << "\nNow checking if removeStation works as intended\n";

	//first populate testRailroad
	for (int i = 0; i < 12; i++) {
		testRailroad.extendAtTail(i + 1, i + 1);
	}


	//create a valid route in a list
	list<pair<int, DIRECTION>> aRoute;
	aRoute.push_back(pair<int, DIRECTION>(2, NORTH));
	aRoute.push_back(pair<int, DIRECTION>(4, SOUTH));
	aRoute.push_back(pair<int, DIRECTION>(3, WEST));
	aRoute.push_back(pair<int, DIRECTION>(4, EAST));
	aRoute.push_back(pair<int, DIRECTION>(5, NONE));

	//add it to testRailroad
	testRailroad.makeRoute(aRoute);

	//now cut a station out of the route
	testRailroad.removeStation(4);

	//first make sure the station is gone
	if (testRailroad.codeMatch(4) != nullptr) {
		cout << "Station was not properly removed, test failed\n";
		return false;
	}
	else {
		cout << "Station was properly removed\n";
	}

	cout << "Now checking to see if all links were removed\n";

	//check to see if the links that were set for this are gone
	if (testRailroad.codeMatch(2)->getNorth() != nullptr || testRailroad.codeMatch(3)->getWest() != nullptr) {
		cout << "Links to removed station still exist, test failed\n";
	}

	//if both links are gone, this test passed
	cout << "All links to the removed station are gone, test passed\n";
	return true;
}


bool Tester::testClearAllRoutes() {

	Railroad testRailroad; //for testing

	//check if clearAllRoutes() works as intended

	cout << "\nNow checking if clearAllRoutes() works as intended\n";

	//first populate testRailroad
	for (int i = 0; i < 12; i++) {
		testRailroad.extendAtTail(i + 1, i + 1);
	}


	//create a valid route in a list
	list<pair<int, DIRECTION>> aRoute;
	aRoute.push_back(pair<int, DIRECTION>(2, NORTH));
	aRoute.push_back(pair<int, DIRECTION>(4, SOUTH));
	aRoute.push_back(pair<int, DIRECTION>(3, WEST));
	aRoute.push_back(pair<int, DIRECTION>(4, EAST));
	aRoute.push_back(pair<int, DIRECTION>(5, NONE));

	//add it to testRailroad
	testRailroad.makeRoute(aRoute);

	//then clear it of the route
	testRailroad.clearAllRoutes();

	//now iterate and make sure that there are no links remaining
	Station* temp = testRailroad.m_head; //for iteration
	while (temp != nullptr) {
		if (temp->getEast() != nullptr) {
			cout << "Link detected after clearAllRoutes ran, test failed\n";
			return false;
		}
		else if (temp->getEast() != nullptr) {
			cout << "Link detected after clearAllRoutes ran, test failed\n";
			return false;
		}
		else if (temp->getEast() != nullptr) {
			cout << "Link detected after clearAllRoutes ran, test failed\n";
			return false;
		}
		else if (temp->getEast() != nullptr) {
			cout << "Link detected after clearAllRoutes ran, test failed\n";
			return false;
		}
		
		//move temp to the next Station
		temp = temp->getNext();
	}

	//if we get here the test passed
	cout << "No links detected, clearAllRoutes() works properly\n";
	return true;
}


bool Tester::testClearNetwork() {

	cout << "\nNow making sure that clearNetwork() properly clears the Railroad\n";

	Railroad testRailroad; //for testing

	//check if clearNetwork() works as intended

	cout << "Now checking if clearNetwork() works as intended\n";

	//first populate testRailroad
	for (int i = 0; i < 12; i++) {
		testRailroad.extendAtTail(i + 1, i + 1);
	}


	//create a valid route in a list
	list<pair<int, DIRECTION>> aRoute;
	aRoute.push_back(pair<int, DIRECTION>(2, NORTH));
	aRoute.push_back(pair<int, DIRECTION>(4, SOUTH));
	aRoute.push_back(pair<int, DIRECTION>(3, WEST));
	aRoute.push_back(pair<int, DIRECTION>(4, EAST));
	aRoute.push_back(pair<int, DIRECTION>(5, NONE));

	//add it to testRailroad
	testRailroad.makeRoute(aRoute);

	//then clear it
	testRailroad.clearNetwork();

	//make sure that all member variables have been reset to defaults
	if (testRailroad.m_head != nullptr || testRailroad.m_tail != nullptr || testRailroad.m_numStations != 0) {
		cout << "Clear network did not work properly, test failed\n";
		return false;
	}

	//if it doesn't return false then clearNetwork() worked properly
	cout << "Clear network properly cleared the railroad\n";
	return true;
}