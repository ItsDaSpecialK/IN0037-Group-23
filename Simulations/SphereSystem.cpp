#include "SphereSystem.h"

void SphereSystem::computeForces()
{
	//TODO: Compute the forces based on collisions
	for (Point& p : spheres)
	{
		p.force = gravity_ * gravityScale_;
	}
	computeCollisionForces();
}

void SphereSystem::computeForcesTmp()
{
	//TODO: Compute the forces based on collisions in temporary locations
	for (Point& p : spheres)
	{
		p.force = gravity_ * gravityScale_;
	}
	computeCollisionForcesTmp();
}
#define BOX_DIMENSION 2.f
void SphereSystem::enforceBounds()
{
	for (Point& point : spheres) {
		if (point.position.x < -BOX_DIMENSION) {
			point.position.x = -BOX_DIMENSION;
			point.velocity.x = 0;
		}
		else if (point.position.x > BOX_DIMENSION) {
			point.position.x = BOX_DIMENSION;
			point.velocity.x = 0;
		}

		if (point.position.y < -2) {
			point.position.y = -2;
			point.velocity.y = 0;
		}
		//else if (point.position.y > BOX_DIMENSION) {
		//	point.position.y = BOX_DIMENSION;
		//	point.velocity.y = 0;
		//}

		if (point.position.z < -BOX_DIMENSION) {
			point.position.z = -BOX_DIMENSION;
			point.velocity.z = 0;
		}
		else if (point.position.z > BOX_DIMENSION) {
			point.position.z = BOX_DIMENSION;
			point.velocity.z = 0;
		}
	}
}

void SphereSystem::simulateTimestep(float timeStep)
{
	//Simulate the step using the midpoint method as in the 1st assignment.
	//auto user_force = calculateUserInteractionForce(time_step);
	computeForces();
	//addExternalForcesToPoints(user_force);
	for (Point & point : spheres)
	{
		if (point.is_fixed)
			continue;

		//See the lecture02 slides, esp. the slides (pages) 48 and 71  
		point.positionTemp = point.position + point.velocity * timeStep / 2;
		Vec3 acc = point.force / point.mass;
		point.velocityTemp = point.velocity + acc * timeStep / 2;
		point.position += point.velocityTemp * timeStep;
	}
	//Compute the forces in the midpoint and calculate accelerations from them...
	computeForcesTmp();
	//addExternalForcesToPoints(user_force);
	for (Point& point : spheres)
	{
		if (point.is_fixed)
			continue;

		Vec3 acc = point.force / point.mass;
		point.velocity += acc * timeStep;
	}

	enforceBounds();
}

void SphereSystem::drawFrame(DrawingUtilitiesClass * DUC, ID3D11DeviceContext* pd3_d_immediate_context)
{
	float scale = 0.25;
	//TODO: Draw spheres in the sphere system.
	//(as in the 1st assignment)
	DUC->setUpLighting(Vec3(), 0.4*Vec3(1, 1, 1), 100, color_);
	for (Point & p : spheres)
	{
		DUC->drawSphere(p.position* scale, radius_ * scale);
	}
}

void SphereSystem::addSphere(Vec3 position, Vec3 velocity, bool isFixed, float mass)
{
	spheres.emplace_back(position, velocity, mass, isFixed);
}
