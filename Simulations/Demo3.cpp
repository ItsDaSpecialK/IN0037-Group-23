#include "Demo3.h"
#include "MassSpringSystemSimulator.h"

void Demo3::init()
{
	TwoPointsDemoScene::init();
	simulator.setIntegrator(MIDPOINT);
	cout << "Midpoint method, steps by default by.005:" << std::endl;
}

void Demo3::stepPerformedCallback()
{
	print_points_info();
}
