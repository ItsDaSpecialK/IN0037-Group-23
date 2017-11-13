#include "Demo1.h"
#include "MassSpringSystemSimulator.h"
void Demo1::init()
{
	simulator.setIntegrator(EULER);
	simulator.setMass(10);
	simulator.addMassPoint(Vec3(0, 0, 0), Vec3(-1, 0, 0),true);
	simulator.addMassPoint(Vec3(0, 2, 0), Vec3(1, 0, 0),true);
	simulator.setStiffness(40);
	simulator.addSpring(0, 1, 1);
	elapsed_frames = 0;
}

void Demo1::stepPerformedCallback()
{
	elapsed_frames++;
	if (elapsed_frames == 1)
	{
		std::cout << "Results after the first step:" <<std::endl;
		size_t i = 0;
		for (Point & p : simulator.getPoints())
		{
			std::cout <<"The point "<< ++i << ":" <<std::endl;
			std::cout << "Position " << p.position << std::endl;
			std::cout << "Velocity " << p.velocity <<std::endl;
		}
	}
}


Demo1::~Demo1()
{
}
