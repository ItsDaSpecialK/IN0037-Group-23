#include "../RigidBodySystemSimulator.h"

RigidBodySystemSimulator::RigidBodySystemSimulator()
{
	m_system = new RigidBodySystem();
}

const char * RigidBodySystemSimulator::getTestCasesStr()
{
	return "Demo 1, Demo 2, Demo 3, Demo 4";;
}

void RigidBodySystemSimulator::initUI(DrawingUtilitiesClass * DUC)
{
	this->DUC = DUC;
}

void RigidBodySystemSimulator::reset()
{
	notifyCaseChanged(m_currentTestCase);
}

void RigidBodySystemSimulator::drawFrame(ID3D11DeviceContext * pd3dImmediateContext)
{
	float scale = .25;
	Mat4 scaleMat;
	scaleMat.initScaling(scale);
	for (RigidBody* body : m_system->bodies_)
	{
		DUC->setUpLighting(Vec3(), 0.4*Vec3(1, 1, 1), 100, body->color());
		DUC->drawRigidBody(body->object_to_world_matrix() * scaleMat);
	}
}

void RigidBodySystemSimulator::notifyCaseChanged(int testCase)
{
	m_system = new RigidBodySystem();
	m_currentTestCase = testCase;
	switch (testCase)
	{
		case 0: 
			m_system->addRigidBody(Vec3(0, 0, 0), Vec3(1, 1, 1), 1);
			m_system->setColorOf(0, Vec3(0, 0, 0.6));
			m_system->addRigidBody(Vec3(3, 0, 0), Vec3(2, 1, 1), 1);
			m_system->setColorOf(1, Vec3(.6, 0, 0));
			break;
		case 1 :
			break;
		case 2:
			break;
		case 3 :
			break;
	}
}

void RigidBodySystemSimulator::externalForcesCalculations(float timeElapsed)
{
}

void RigidBodySystemSimulator::simulateTimestep(float timeStep)
{
}

void RigidBodySystemSimulator::onClick(int x, int y)
{
}

void RigidBodySystemSimulator::onMouse(int x, int y)
{
}

int RigidBodySystemSimulator::getNumberOfRigidBodies()
{
	return m_system->getNumberOfRigidBodies();
}

Vec3 RigidBodySystemSimulator::getPositionOfRigidBody(int i)
{
	return m_system->getPositionOfRigidBody(i);
}

Vec3 RigidBodySystemSimulator::getLinearVelocityOfRigidBody(int i)
{
	return m_system->getLinearVelocityOfRigidBody(i);
}

Vec3 RigidBodySystemSimulator::getAngularVelocityOfRigidBody(int i)
{
	return m_system->getAngularVelocityOfRigidBody(i);
}

void RigidBodySystemSimulator::applyForceOnBody(int i, Vec3 loc, Vec3 force)
{
	return m_system->applyForceOnBody(i, loc, force);
}

void RigidBodySystemSimulator::addRigidBody(Vec3 position, Vec3 size, int mass)
{
	return m_system->addRigidBody(position, size, mass);
}

void RigidBodySystemSimulator::setOrientationOf(int i, Quat orientation)
{
	m_system->setOrientationOf(i, orientation);
}

void RigidBodySystemSimulator::setVelocityOf(int i, Vec3 velocity)
{
	m_system->setVelocityOf(i, velocity);
}
