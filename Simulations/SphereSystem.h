#ifndef SPHERESYSTEM_H
#define SPHERESYSTEM_H

#pragma once
#include "util/FFmpeg.h"
#include "Point.h"

class SphereSystem
{
public:
	
	virtual ~SphereSystem() = default;

	SphereSystem(float radius, float mass, float box_dimension)
		: radius_(radius), mass_(mass),
		  color_(0.6*Vec3(0, 1, 0)), 
		  gravity_(Vec3(0,-1,0)), gravityScale_(1),
		  kernelFunc_(nullptr), box_dimension_(box_dimension)
	{
	}

	Vec3 color() const
	{
		return color_;
	}

	void set_color(const Vec3& color)
	{
		color_ = color;
	}

	double gravity_scale() const
	{
		return gravityScale_;
	}

	void set_gravity_scale(double gravity_scale)
	{
		gravityScale_ = gravity_scale;
	}
	
	void set_kernel_func(const std::function<float(float)>& kernel_func)
	{
		kernelFunc_ = kernel_func;
	}

	virtual void computeCollisionForces() = 0;
	void computeForces();
	virtual void computeCollisionForcesTmp() = 0;
	void computeForcesTmp();
	void enforceBounds();
	void simulateTimestep(float timeStep);
	void drawFrame(DrawingUtilitiesClass * DUC, ID3D11DeviceContext* pd3_d_immediate_context);
	void addSphere(Vec3 position, Vec3 velocity, bool isFixed, float mass);

protected:
	std::vector<Point> spheres;
	float radius_;
	std::function<float(float)> kernelFunc_;
	float box_dimension_;
	const double FORCE_LAMBDA = 1000;
private:
	float mass_;
	Vec3 color_;
	Vec3 gravity_;
	double gravityScale_;
};


#endif // SPHERESYSTEM_H
