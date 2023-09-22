//UMBC - CSEE - CMSC 341 - Fall 2022 - Proj1
#include "railroad.h"

//xxclass Tester{ // Tester class to implement test functions
  //xx  public:

    /**************************************
    * Test function declarations go here! *
    **************************************/
//xx};

/*xx
int main(){
    Railroad aNetwork;
    for (int i=1;i<10;i++)
        aNetwork.extendAtTail(i,i*2);
    cout << "Create a route [(2,NORTH),(5,SOUTH),(8,NONE)]\n\n";
    list<pair<int,DIRECTION>> aRoute;
    aRoute.push_back(pair<int,DIRECTION>(2,NORTH));
    aRoute.push_back(pair<int,DIRECTION>(5,SOUTH));
    aRoute.push_back(pair<int,DIRECTION>(8,NONE));
    aNetwork.makeRoute(aRoute);
    cout << "Total travellers: " << aNetwork.travel(aRoute) << endl;
    cout << "\nDump of the list:\n\n";
    aNetwork.dump();
    cout << "\n\nRemove node 5.\n\n";
    aNetwork.removeStation(5);
    cout << "Removing node 5 invalidates the route passing through 5.\n\n";
    cout << "Total travellers: " << aNetwork.travel(aRoute) << endl;
    cout << "\nDump of the list:\n\n";
    aNetwork.dump();
    return 0;
}


bool Tester::testMakeRouteAll() {


	//make sure MakeRoute returns false if it tries to make a station with a starting station
	cout << "\nTesting MakeRoute\n";

	//first create a railRoad and fill it up
	Railroad testRailroad = Railroad();

	for (int i = 0; i < 12; i++) {

		testRailroad.extendAtTail(i + 1, i + 1);
	}

	testRailroad.dump();

	//create a route in a list
	list<pair<int, DIRECTION>> aRoute;
	aRoute.push_back(pair<int, DIRECTION>(2, NORTH));
	aRoute.push_back(pair<int, DIRECTION>(4, SOUTH));
	aRoute.push_back(pair<int, DIRECTION>(3, WEST));
	aRoute.push_back(pair<int, DIRECTION>(4, EAST));
	aRoute.push_back(pair<int, DIRECTION>(22, EAST));
	aRoute.push_back(pair<int, DIRECTION>(5, NONE));

	testRailroad.makeRoute(aRoute);

	testRailroad.dump();

	cout << testRailroad.travel(aRoute) << endl;

	list<pair<int, DIRECTION>> bRoute;
	bRoute.push_back(pair<int, DIRECTION>(2, EAST));
	bRoute.push_back(pair<int, DIRECTION>(5, SOUTH));
	bRoute.push_back(pair<int, DIRECTION>(3, WEST));
	bRoute.push_back(pair<int, DIRECTION>(4, NORTH));
	bRoute.push_back(pair<int, DIRECTION>(5, SOUTH));
	bRoute.push_back(pair<int, DIRECTION>(9, NORTH));

	testRailroad.makeRoute(bRoute);

	testRailroad.dump();

	cout << testRailroad.travel(bRoute) << endl;

	cout << testRailroad.travel(aRoute) << endl;

	testRailroad.clearAllRoutes();

	testRailroad.dump();

	return false;

}

bool testMakeRouteAll() {

		list<pair<int, DIRECTION>> wRoute;
		wRoute.push_back(pair<int, DIRECTION>(2, SOUTH));
		wRoute.push_back(pair<int, DIRECTION>(4, WEST));
		wRoute.push_back(pair<int, DIRECTION>(7, SOUTH));
		wRoute.push_back(pair<int, DIRECTION>(3, NORTH));
		wRoute.push_back(pair<int, DIRECTION>(6, WEST));
		wRoute.push_back(pair<int, DIRECTION>(4, EAST));
		wRoute.push_back(pair<int, DIRECTION>(22, EAST));
		wRoute.push_back(pair<int, DIRECTION>(5, NONE));


		//make sure MakeRoute returns false if it tries to make a station with a starting station
		cout << "\nTesting MakeRoute\n";

		//first create a railRoad and fill it up
		Railroad testRailroad = Railroad();

		for (int i = 0; i < 12; i++) {

			testRailroad.extendAtTail(i + 1, i + 1);
		}

		testRailroad.dump();

		//create a route in a list
		list<pair<int, DIRECTION>> aRoute;
		aRoute.push_back(pair<int, DIRECTION>(2, NORTH));
		aRoute.push_back(pair<int, DIRECTION>(4, SOUTH));
		aRoute.push_back(pair<int, DIRECTION>(6, WEST));
		aRoute.push_back(pair<int, DIRECTION>(4, EAST));
		aRoute.push_back(pair<int, DIRECTION>(22, EAST));
		aRoute.push_back(pair<int, DIRECTION>(5, NONE));

		list<pair<int, DIRECTION>> qRoute;
		qRoute.push_back(pair<int, DIRECTION>(3, SOUTH));
		qRoute.push_back(pair<int, DIRECTION>(6, NORTH));
		testRailroad.makeRoute(qRoute);

		testRailroad.makeRoute(aRoute);

		testRailroad.dump();

		list<pair<int, DIRECTION>> xRoute;
		xRoute.push_back(pair<int, DIRECTION>(2, SOUTH));
		xRoute.push_back(pair<int, DIRECTION>(4, WEST));
		xRoute.push_back(pair<int, DIRECTION>(7, SOUTH));
		xRoute.push_back(pair<int, DIRECTION>(3, NORTH));
		xRoute.push_back(pair<int, DIRECTION>(6, WEST));
		xRoute.push_back(pair<int, DIRECTION>(4, EAST));
		xRoute.push_back(pair<int, DIRECTION>(22, EAST));
		xRoute.push_back(pair<int, DIRECTION>(5, NONE));
		testRailroad.makeRoute(xRoute);
		cout << testRailroad.travel(xRoute);
		cout << testRailroad.travel(qRoute);
		cout << testRailroad.travel(aRoute) << endl;
		cout << testRailroad.travel(wRoute) << endl;

		list<pair<int, DIRECTION>> bRoute;
		bRoute.push_back(pair<int, DIRECTION>(2, EAST));
		bRoute.push_back(pair<int, DIRECTION>(5, SOUTH));
		bRoute.push_back(pair<int, DIRECTION>(3, WEST));
		bRoute.push_back(pair<int, DIRECTION>(4, NORTH));
		bRoute.push_back(pair<int, DIRECTION>(5, SOUTH));
		bRoute.push_back(pair<int, DIRECTION>(9, NORTH));

		testRailroad.makeRoute(bRoute);

		testRailroad.dump();

		cout << testRailroad.travel(bRoute) << endl;

		cout << testRailroad.travel(aRoute) << endl;

		testRailroad.clearAllRoutes();

		testRailroad.dump();

		return false;

	}



xx*/