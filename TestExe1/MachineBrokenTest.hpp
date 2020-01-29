#include "../productioncontrol/ProductionControl.hpp"
#include "../productioncontrol/Machine.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( dinges) {
	Machine m("Name", 1, 1.0, 5, 5, 500, 200, 30);

	BOOST_CHECK(m.calculateRepairTime() = 200);
}

//Start aangeven van een groepje test cases.
BOOST_AUTO_TEST_SUITE( MachineBrokenModule )

//Een voorbeeld test case.
BOOST_AUTO_TEST_CASE( machineBrokenCheckNoThrow ){
	ProductionControl pc;
	Machine m("Name", 1, 1.0, 5, 5, 500, 200, 30);

    BOOST_CHECK_NO_THROW(pc.machineBroken(m));
}

BOOST_AUTO_TEST_CASE( CheckBroken ) {

	ProductionControl pc;
		Machine m("Name", 1, 1.0, 5, 5, 500, 200, 30);

		BOOST_CHECK( pc.machineBroken(m) );
}

//Einde van het groepje test cases aangeven.
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( Algorithm )


//calculateRunningTime
BOOST_AUTO_TEST_CASE( CalculateTime ) {

	ProductionControl pc;

	BOOST_REQUIRE_EQUAL( pc.calculateRunningTime(2), 249600 );
}


//machineSortingAlgorithm
BOOST_AUTO_TEST_CASE( machineSortingAlgorithm ) {

	ProductionControl pc;
	std::map<unsigned short, double> machineTimeMap;

	Machine m(("Third", 3, 8.0, 5, 5, 500, 200, 30),
			("First", 1, 7.0, 5, 5, 500, 200, 30),
			("Second", 2, 4.0, 5, 5, 500, 200, 30));

	for (Machine aMachine : m) {
			aMachine.setInBuffer(0);
			machineTimeMap.insert(
					{ std::make_pair(aMachine.getId(), aMachine.getProductionTime()) });
			//std::cout << "ProductionTime in init: " << aMachine.getProductionTime() << std::endl;
		}

	pc.machineSortingAlgorithm(&machineTimeMap);

	//first in map will be checked if the val is 4.0
	//this will be the one with te least time.
	for (auto const& [key,val] : machineTimeMap) {
			BOOST_REQUIRE_EQUAL(val , 4.0 );

	}


}

BOOST_AUTO_TEST_SUITE_END()

