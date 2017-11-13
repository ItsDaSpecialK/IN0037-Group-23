#include "TwoPointsDemoScene.h"
#include "MassSpringSystemSimulator.h"

void TwoPointsDemoScene::init()
{
	simulator.setIntegrator(EULER);
	simulator.setMass(10);
	simulator.addMassPoint(Vec3(0, 0, 0), Vec3(-1, 0, 0), false);
	simulator.addMassPoint(Vec3(0, 2, 0), Vec3(1, 0, 0), false);
	simulator.setStiffness(40);
	simulator.addSpring(0, 1, 1);
	elapsed_frames = 0;
}

void TwoPointsDemoScene::stepPerformedCallback()
{
}
