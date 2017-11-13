#include "MassSpringSystemSimulator.h"
#include "Demo1.h"

MassSpringSystemSimulator::MassSpringSystemSimulator()
:currentDemo(nullptr)
{
	scenes.push_back(std::make_unique<Demo1>(*this));
	//TODO: push back other types of scenes.
	// When the i-th demo is selected from the drop-down menu, the i-th DemoScene is taken from the list...
}

const char* MassSpringSystemSimulator::getTestCasesStr()
{
	return "Demo 1, Demo2, Demo3, Demo 4, Demo 5";
}
 void MassSpringSystemSimulator::initUI(DrawingUtilitiesClass* DUC)
{
	 this->DUC = DUC;
	currentDemo = scenes.at(m_iTestCase).get();
	//we add a new listbox to the control panel:
	//first, we create a new "enum type"
	TwType TW_TYPE_INTEGRATOR = TwDefineEnumFromString("Integrator", "Euler, Leapfrog, Midpoint");
	//Then, we create the listbox, the changed value will be directly written into the variable 'm_iIntegrator'
	TwAddVarRW(DUC->g_pTweakBar, "Integrator", TW_TYPE_INTEGRATOR, &m_iIntegrator, "");
	reset();
}

void MassSpringSystemSimulator::reset()
{
	points.clear();
	springs.clear();
	if (currentDemo) {
		currentDemo->init();
	}
}

 void MassSpringSystemSimulator::drawFrame(ID3D11DeviceContext* pd3dImmediateContext)
{
	float scale = 0.25;
	DUC->setUpLighting(Vec3(), 0.4*Vec3(1, 1, 1), 100, 0.6*Vec3(0, 1, 0));
	for (Point & p : points)
	{
		DUC->drawSphere(p.position* scale, .05);
	}
	for (Spring &s : springs)
	{
		Point& p1 = points[s.point1];
		Point& p2 = points[s.point2];
		Vec3 pos = p1.position * scale;
		Vec3 pos2 = p2.position * scale;
		DUC->beginLine();
		DUC->drawLine(pos, Vec3(0, 0, 1), pos2, Vec3(0, 0, 1));
		DUC->endLine();

	}
}

void MassSpringSystemSimulator::notifyCaseChanged(int testCase)
{
	m_iTestCase = testCase;
	currentDemo = scenes.at(m_iTestCase).get();
}

void MassSpringSystemSimulator::externalForcesCalculations(float timeElapsed)
{
}

void MassSpringSystemSimulator::computeForces()
{
	for (Point& p : points)
	{
		p.force = 0;
	}
	for (Spring& s : springs)
	{
		float k = s.stifness;
		float L= s.initialLength;
		Point& p1 = points.at(s.point1);
		Point& p2 = points.at(s.point2);
		Vec3 pos1 = p1.position;
		Vec3 pos2 = p2.position;
		float l = norm(pos1 - pos2);
		Vec3 force = -k * (L - l) *  (pos2 - pos1) / l;
		p1.force += force;
		p2.force -= force;
	}
	//TODO: add external forces...
}

void MassSpringSystemSimulator::integratePositionsEuler(float timestep)
{
	for (Point& p : points)
	{
		p.position += p.velocity* timestep;
	}
}

void MassSpringSystemSimulator::integrateVelocitiesEuler(float timestep)
{
	for (Point& p : points)
	{
		Vec3 acc = p.force / p.mass;
		p.velocity += acc * timestep;
	}
}

void MassSpringSystemSimulator::simulateTimestepEuler(float timestep)
{
	computeForces();
	integratePositionsEuler(timestep);
	integrateVelocitiesEuler(timestep);
}


void MassSpringSystemSimulator::computeForcesTmp()
{
	for (Point& p : points)
	{
		p.force = 0;
	}
	for (Spring& s : springs)
	{
		float k = s.stifness;
		float L = s.initialLength;
		Point& p1 = points.at(s.point1);
		Point& p2 = points.at(s.point2);
		Vec3 pos1 = p1.positionTemp;
		Vec3 pos2 = p2.positionTemp;
		float l = norm(pos1 - pos2);
		Vec3 force = -k * (L - l) *  (pos2 - pos1) / l;
		p1.force += force;
		p2.force -= force;
	}
	//TODO: add external forces...
}

void MassSpringSystemSimulator::simulateTimestepMidpoint(float time_step)
{
	computeForces();
	for (Point  & point : points)
	{
		//See the lecture02 slides, esp. the slides (pages) 48 and 71  
		point.positionTemp = point.position + point.velocity * time_step / 2;
		Vec3 acc = point.force / point.mass;
		point.velocityTemp = point.velocity + acc * time_step / 2;
		point.position += point.velocityTemp*time_step;
	}
	//Compute the forces in the midpoint and calculate accelerations from them...
	computeForcesTmp();
	for (Point& point : points)
	{
		Vec3 acc = point.force / point.mass;
		point.velocity += acc * time_step;
	}
}

void MassSpringSystemSimulator::simulateTimestep(float timeStep)
{
	if (m_iIntegrator == EULER)
	{
		simulateTimestepEuler(timeStep);
	}
	else if (m_iIntegrator == MIDPOINT)
	{
		simulateTimestepMidpoint(timeStep);
	}
}

void MassSpringSystemSimulator::onClick(int x, int y)
{
}

void MassSpringSystemSimulator::onMouse(int x, int y)
{
}

void MassSpringSystemSimulator::setMass(float mass)
{
	m_fMass = mass;
}

void MassSpringSystemSimulator::setStiffness(float stiffness)
{
	m_fStiffness = stiffness;
}

void MassSpringSystemSimulator::setDampingFactor(float damping)
{
	m_fDamping = damping;
}

int MassSpringSystemSimulator::addMassPoint(Vec3 position, Vec3 velocity, bool isFixed)
{
	points.emplace_back(position, velocity, m_fMass, isFixed);
	return points.size() - 1;
}

void MassSpringSystemSimulator::addSpring(int masspoint1, int masspoint2, float initialLength)
{
	springs.emplace_back(masspoint1, masspoint2, initialLength, m_fStiffness);
}

int MassSpringSystemSimulator::getNumberOfMassPoints()
{
	return points.size();
}

int MassSpringSystemSimulator::getNumberOfSprings()
{
	return springs.size();
}

Vec3 MassSpringSystemSimulator::getPositionOfMassPoint(int index)
{
	return points.at(index).position;
}

Vec3 MassSpringSystemSimulator::getVelocityOfMassPoint(int index)
{
	return points.at(index).velocity;
}

void MassSpringSystemSimulator::applyExternalForce(Vec3 force)
{
	//throw std::exception("Not implemented.");
}