#pragma once
#include "RigidBody.h"
#include <vector>

class RigidBodySystem
{

public:
	int getNumberOfRigidBodies();
	Vec3 getPositionOfRigidBody(int i);
	Vec3 getLinearVelocityOfRigidBody(int i);
	Vec3 getAngularVelocityOfRigidBody(int i);
	void applyForceOnBody(int i, Vec3 loc, Vec3 force);
	void addRigidBody(Vec3 position, Vec3 size, int mass);
	void setOrientationOf(int i, Quat orientation);
	void setVelocityOf(int i, Vec3 velocity);
	void setColorOf(int i, Vec3 color);
	void simulateTimeStep(float step);
	std::vector<RigidBody*> bodies_;
	~RigidBodySystem()
	{
		for (auto body : bodies_)
		{
			delete body;
		}
	}
};
