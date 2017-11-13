#include "Demo1.h"
#include "MassSpringSystemSimulator.h"
void Demo1::init()
{
	simulator.setIntegrator(EULER);
	simulator.setMass(10);
	//where is ground f
	simulator.addMassPoint(Vec3(0, 0, 0), Vec3(-1, 0, 0),true);
	simulator.addMassPoint(Vec3(0, 2, 0), Vec3(1, 0, 0),true);
	simulator.addMassPoint(Vec3(1, 2, 1), Vec3(0, 0, 0), true);
	simulator.addMassPoint(Vec3(0, 1, 0.5), Vec3(0, 0, 0), true);


	//simulator.addMassPoint(Vec3(0, -2, 0), Vec3(0, 0, 0), false);
	//simulator.addMassPoint(Vec3(0, 2, 0), Vec3(0, 0, 0), false);

	simulator.setStiffness(40);
	simulator.addSpring(0, 1, 1);
	simulator.addSpring(2, 3, 1);
}


Demo1::~Demo1()
{
}
