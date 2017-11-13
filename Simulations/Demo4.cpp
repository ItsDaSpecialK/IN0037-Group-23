#include "Demo4.h"
#include "MassSpringSystemSimulator.h"

void Demo4::init()
{
	simulator.setIntegrator(EULER);
	simulator.setMass(10);
	
	int anchor = simulator.addMassPoint(Vec3(0, 3.5f, 0), Vec3(0.f), true);
	int floating = simulator.addMassPoint(Vec3(0, 3, 0), Vec3(0.f), false);
	int bottom = simulator.addMassPoint(Vec3(0, 2, 0), Vec3(1, -5, 0), false);

	//cube
	int ltf = simulator.addMassPoint(Vec3(1, 1, 1), Vec3(0.f), false);
	int ltb = simulator.addMassPoint(Vec3(1, 1,-1), Vec3(0.f), false);
	int rtf = simulator.addMassPoint(Vec3(-1, 1, 1), Vec3(0.f), false);
	int rtb = simulator.addMassPoint(Vec3(-1, 1,-1), Vec3(0.f), false);
	int lbf = simulator.addMassPoint(Vec3(1,-1, 1), Vec3(0.f), false);
	int lbb = simulator.addMassPoint(Vec3(1,-1, -1), Vec3(0.f), false);
	int rbf = simulator.addMassPoint(Vec3(-1,-1, 1), Vec3(0.f), false);
	int rbb = simulator.addMassPoint(Vec3(-1,-1, -1), Vec3(0.f), false);


	simulator.setStiffness(40);
	simulator.addSpring(anchor, floating, .5f);
	simulator.addSpring(bottom, floating, 1);

	//cube
	simulator.addSpring(ltf, ltb, 3);
	simulator.addSpring(ltf, rtf, 3);
	simulator.addSpring(ltf, lbf, 3);
	simulator.addSpring(ltb, lbb, 3);
	simulator.addSpring(ltb, rtb, 3);
	simulator.addSpring(rtb, rtf, 3);
	simulator.addSpring(rtb, rbb, 3);
	simulator.addSpring(rtf, rbf, 3);
	simulator.addSpring(lbf, lbb, 3);
	simulator.addSpring(lbb, rbb, 3);
	simulator.addSpring(rbb, rbf, 3);
	simulator.addSpring(rbf, lbf, 3);

	//cube to "bottom"
	simulator.addSpring(ltf, bottom, 1);
	simulator.addSpring(rtf, bottom, 1);
	simulator.addSpring(ltb, bottom, 1);
	simulator.addSpring(rtb, bottom, 1);

}

void Demo4::stepPerformedCallback()
{
}
