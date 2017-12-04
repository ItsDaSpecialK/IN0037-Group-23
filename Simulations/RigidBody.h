#pragma once
#include "util/vectorbase.h"
#include "DrawingUtilitiesClass.h"

class RigidBody
{
public:
	RigidBody(const Vec3& position, int mass, const Vec3 size)
		: position_(position),
		orientation_(Vec3(1,0,0),0),
		rotation_(0, 0, 0),
		mass_(mass),
		size_(size),
		velocity_(0,0,0),
		angular_momentum_(0,0,0),
		color_(.6,0,0),
		force_(0,0,0),
		torque_(0,0,0)
	{
	}

	Vec3 position() CONST
	{
		return position_;
	}

	void set_position(const Vec3& position)
	{
		position_ = position;
	}

	Quat orientation() const
	{
		return orientation_;
	}

	void set_orientation(const Quat& orientation)
	{
		orientation_ = orientation;
	}

	Vec3 rotation() const
	{
		return rotation_;
	}

	void set_rotation(const Vec3& rotation)
	{
		rotation_ = rotation;
	}

	int mass() const
	{
		return mass_;
	}

	void set_mass(const int mass)
	{
		mass_ = mass;
	}

	Vec3 size() const
	{
		return size_;
	}

	void set_size(const Vec3& size)
	{
		size_ = size;
	}

	Vec3 velocity() const
	{
		return velocity_;
	}

	void set_velocity(const Vec3& velocity)
	{
		velocity_ = velocity;
	}

	Mat4 scale_matrix() const
	{
		Mat4 mat;
		mat.initScaling(size_.x, size_.y, size_.z);
		return mat;
	}
	Mat4 orientation_matrix() const
	{
		return orientation_.getRotMat();
	}
	Mat4 translation_matrix() const
	{
		Mat4 mat;
		mat.initTranslation(position_.x, position_.y, position_.z);
		return mat;
	}
	Mat4 object_to_world_matrix() const
	{
		return scale_matrix() * orientation_matrix() * translation_matrix();
	}

	//From wikipedia
	//https://en.wikipedia.org/wiki/List_of_moments_of_inertia
	Mat4 inertia_matrix() const
	{
		Mat4 m;
		float h = size_[1];
		float w = size_[0];
		float d = size_[2];
		m.initScaling(h*h + d*d, w*w + d*d, w*w + h*h);
		m *= mass_ / 12;
		return m;
	}

	Mat4 inverse_inertia_matrix() const
	{
		Mat4 m;
		float h = size_[1];
		float w = size_[0];
		float d = size_[2];
		m.initScaling(1/(h*h + d*d), 1/(w*w + d*d), 1/(w*w + h*h));
		m *= 12 / mass_;
		return m;
	}

	Vec3 color() const
	{
		return color_;
	}

	void set_color(const Vec3& color)
	{
		color_ = color;
	}
	void simulate_step(const float timeStep)
	{
		position_ = position_ + timeStep * velocity_;
		velocity_ = velocity_ + timeStep * (force_ / mass_);
		Quat quat(rotation_.x, rotation_.y, rotation_.z, 0);
		orientation_ = orientation_ + timeStep / 2 * quat * orientation_;
		//Normalize the quaternion:
		orientation_ /= orientation_.norm();	
		angular_momentum_ += timeStep * torque_;
			
		Mat4 rotMat = orientation_matrix();
		Mat4 rotMatT = rotMat;
		rotMatT.transpose();
		const Mat4 inverse_inertia = rotMatT * inverse_inertia_matrix() * rotMat;
		rotation_ = inverse_inertia * angular_momentum_;

		//clean old values:
		force_ = 0;
		torque_ = 0;

	}

	Vec3 force() const
	{
		return force_;
	}

	void set_force(const Vec3& force)
	{
		force_ = force;
	}

	Vec3 torque() const
	{
		return torque_;
	}

	void set_torque(const Vec3& torque)
	{
		torque_ = torque;
	}

	void add_force(const Vec3& loc, const Vec3& force)
	{
		force_ += force;
		torque_ += cross(loc, force);
	}

private:
	Vec3 position_;
	Quat orientation_;
	Vec3 rotation_;
	int mass_;
	Vec3 size_;
	Vec3 velocity_;
	Vec3 color_;
	//TODO: Add other variables
	Vec3 angular_momentum_;
	Vec3 force_;
	Vec3 torque_;

};