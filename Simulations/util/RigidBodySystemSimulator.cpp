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
			m_system->addRigidBody(Vec3(0, 0, 0), Vec3(1, 0.6, 0.5), 2);
			m_system->setColorOf(0, Vec3(0, 0, 0.6));
			m_system->applyForceOnBody(0,Vec3(0.3, 0.5, 0.25),Vec3(1,1,0));
			break;
		case 1 :
			m_system->addRigidBody(Vec3(0, 0, 0), Vec3(1, 0.6, 0.5), 2);
			m_system->setColorOf(0, Vec3(0, 0, 0.6));
			break;
		case 2:
			m_system->addRigidBody(Vec3(2, 0, 0), Vec3(0.6, 0.6, 0.6), 1);
			m_system->setColorOf(0, Vec3(0, 0, 0.6));
			m_system->addRigidBody(Vec3(-2, 0, 0), Vec3(1, 2, 2), 4);
			m_system->setColorOf(1, Vec3(0.6, 0, 0));
			m_system->setOrientationOf(0, Quat(Vec3(0.75,0.75,0.75), 45));
			m_system->setVelocityOf(0, Vec3(-0.5, 0, 0));
			m_system->setVelocityOf(1, Vec3(0.2, 0, 0));
			break;
		case 3 :
			m_system->addRigidBody(Vec3(2, 0, 2), Vec3(0.6, 0.6, 0.6), 2);
			m_system->setColorOf(0, Vec3(0, 0, 0.6));
			m_system->addRigidBody(Vec3(-2, 0, 2), Vec3(0.6, 0.6, 0.6), 2);
			m_system->setColorOf(1, Vec3(0.6, 0, 0));
			m_system->addRigidBody(Vec3(2, 0, -2), Vec3(0.6, 0.6, 0.6), 2);
			m_system->setColorOf(2, Vec3(0, 0.6, 0));
			m_system->addRigidBody(Vec3(-2, 0, -2), Vec3(0.6, 0.6, 0.6), 2);
			m_system->setColorOf(3, Vec3(0.6, 0.6, 0.6));
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
