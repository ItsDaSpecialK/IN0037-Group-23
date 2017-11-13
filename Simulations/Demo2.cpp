#include "Demo2.h"
#include "MassSpringSystemSimulator.h"

void Demo2::init()
{
	TwoPointsDemoScene::init();
	cout << "Euler method, steps by default by .005:" << std::endl;
}

void Demo2::stepPerformedCallback()
{
	print_points_info();
}
