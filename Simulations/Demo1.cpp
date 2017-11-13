#include "Demo1.h"
#include "MassSpringSystemSimulator.h"
#include "TwoPointsDemoScene.h"

void Demo1::init()
{
	TwoPointsDemoScene::init();
	simulator.simulateTimestep(.1);
	cout << "Euler method, results after a single step by .1:" << endl;
	print_points_info();
	simulator.clearSimulation();
	TwoPointsDemoScene::init();
	cout << "Midpoint method, results after a single step by .1:" << endl;
	simulator.setIntegrator(MIDPOINT);
	simulator.simulateTimestep(.1);
	print_points_info();
}


void Demo1::stepPerformedCallback()
{
}


Demo1::~Demo1()
{
}
