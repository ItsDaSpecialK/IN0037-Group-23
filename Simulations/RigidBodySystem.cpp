#include "RigidBodySystem.h"
#include "collisionDetect.h"

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
//returns true if the objects collide.
bool RigidBodySystem::compute_collision(RigidBody* a, RigidBody* b)
{
	Mat4 obj_world_a = a->object_to_world_matrix();
	Mat4 obj_world_b = b->object_to_world_matrix();
	CollisionInfo info = checkCollisionSAT(obj_world_a, obj_world_b);
	if (!info.isValid) return false;
	Vec3 xa = a->transform_world_to_loc(info.collisionPointWorld);
	Vec3 xb = b->transform_world_to_loc(info.collisionPointWorld);
	auto va = a->velocity() + cross(a->rotation(), xa);
	auto vb = b->velocity() + cross(b->rotation(), xb);
	Vec3 v_rel = va - vb;
	Vec3 n = info.normalWorld;
	float v_rel_proj = dot(n, v_rel);
	if (v_rel_proj > 0) return false; //separating, OK.
	//Compute the impulse:
	float c = (a->restitution_coef() + b->restitution_coef())/2;
	float numerator = - (1 + c) * v_rel_proj;
	float ma = a->mass();
	float mb = b->mass();
	Mat4 ia_inv = a->inverse_inertia_matrix_rotated();
	Mat4 ib_inv = b->inverse_inertia_matrix_rotated();
	Vec3 xan = cross(xa, n);
	Vec3 xbn = cross(xb, n);
	Vec3 factor = cross(ia_inv * xan, xa) + cross(ib_inv *xbn, xb);
	float denom = 1 / ma + 1 / mb + dot(factor, n);
	float impulse = numerator / denom;
	a->updateVelocity(impulse, n);
	b->updateVelocity(- impulse, n);

	a->addAngularMomentum(cross(xa, impulse * n));
	b->addAngularMomentum(- cross(xb, impulse * n));
	return true;
}

void RigidBodySystem::simulateTimeStep(float step)
{
	for (RigidBody* body : bodies_)
	{
		Vec3 old_pos = body->position();
		Quat old_orient = body->orientation();
		body->simulate_step(step);
		for (RigidBody* body2 : bodies_)
		{
		
			if (body == body2) continue;
			if (compute_collision(body, body2))
			{
				body->set_position(old_pos);
				body->set_orientation(old_orient);
			}
		}
	}
}
