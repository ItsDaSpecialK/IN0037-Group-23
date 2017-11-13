﻿#include "Demo4.h"
#include "MassSpringSystemSimulator.h"

void Demo4::init()
{
	simulator.setIntegrator(EULER);
	simulator.addMassPoint(Vec3(0.5, 0.5, 0.5), Vec3(0.7, 0.7, 0.7),false);
	simulator.addMassPoint(Vec3(0.4, 0.5, 0.5), Vec3(0.7, 0.7, 0.7),false);
	simulator.addMassPoint(Vec3(0.3, 0.5, 0.3), Vec3(0.0, 0.7, 0.7),false);
	simulator.addMassPoint(Vec3(0.2, 0.3, 0.1), Vec3(0.0, 0.70, 0.0),false);
	simulator.addMassPoint(Vec3(0.1, 0.4, 0.5), Vec3(0.5, 0.7, 0.7),false);
	simulator.addMassPoint(Vec3(0.6, 0.5, 0.3), Vec3(0.0, 0.7, 0.70),false);
	simulator.addMassPoint(Vec3(0.7, 0.2, 0.4), Vec3(0.0, 0.7, 0.07),false);
	simulator.addMassPoint(Vec3(0.8, 0.6, 0.1), Vec3(0.7, 0.0, 0.7),false);
	simulator.addMassPoint(Vec3(0.9, 0.8, 0.2), Vec3(0.7, 0.0, 0.7),false);
	simulator.addMassPoint(Vec3(0.5, 0.1, 0.3), Vec3(0.7, 0.0, 0.7),false);


	simulator.addSpring(0, 1, 1);

	simulator.addSpring(1, 2, 1);
	simulator.addSpring(2, 3, 1);
	simulator.addSpring(3, 4, 1);
	simulator.addSpring(5, 6, 1);
	simulator.addSpring(6, 7, 1);
	simulator.addSpring(7, 8, 1);
	simulator.addSpring(9, 1, 1);
	simulator.addSpring(9, 2, 1);
	simulator.addSpring(8, 5, 1);
}

void Demo4::stepPerformedCallback()
{
	
}
