#include "RigidBodySystem.h"

int RigidBodySystem::getNumberOfRigidBodies()
{
	return bodies_.size();
}

Vec3 RigidBodySystem::getPositionOfRigidBody(int i)
{
	return bodies_.at(i)->position();
}

Vec3 RigidBodySystem::getLinearVelocityOfRigidBody(int i)
{
	return bodies_.at(i)->velocity();
}

Vec3 RigidBodySystem::getAngularVelocityOfRigidBody(int i)
{
	return bodies_.at(i)->rotation();
}

void RigidBodySystem::applyForceOnBody(int i, Vec3 loc, Vec3 force)
{
	auto & body = bodies_.at(i);
	body->add_force(loc, force);
}

void RigidBodySystem::addRigidBody(Vec3 position, Vec3 size, int mass)
{
	bodies_.push_back(new RigidBody(position, mass, size));
}

void RigidBodySystem::setOrientationOf(int i, Quat orientation)
{
	bodies_.at(i)->set_orientation(orientation);
}

void RigidBodySystem::setVelocityOf(int i, Vec3 velocity)
{
	bodies_.at(i)->set_velocity(velocity);
}

void RigidBodySystem::setColorOf(int i, Vec3 color)
{
	bodies_.at(i)->set_color(color);
}

void RigidBodySystem::simulateTimeStep(float step)
{
	for (RigidBody* body : bodies_)
	{
		body->simulate_step(step);
	}
}
