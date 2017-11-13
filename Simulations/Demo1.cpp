#include "Demo1.h"
#include "MassSpringSystemSimulator.h"
void Demo1::init()
{
	simulator.setIntegrator(EULER);
	simulator.setMass(10);
	simulator.addMassPoint(Vec3(0, 0, 0), Vec3(-1, 0, 0), false);
	simulator.addMassPoint(Vec3(0, 2, 0), Vec3(1, 0, 0), false);
	simulator.setStiffness(40);
	simulator.addSpring(0, 1, 1);
}


Demo1::~Demo1()
{
}
