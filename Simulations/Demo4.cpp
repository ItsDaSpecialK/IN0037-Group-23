#include "Demo4.h"
#include "MassSpringSystemSimulator.h"

void Demo4::init()
{
	simulator.setIntegrator(EULER);
<<<<<<< HEAD
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
=======
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

>>>>>>> d4644c287932e6ad11d713bbf941bfc46c1b8c59
}

void Demo4::stepPerformedCallback()
{
	
}
