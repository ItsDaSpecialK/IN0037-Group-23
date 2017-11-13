#pragma once
#include "Point.h"
#include "Spring.h"
#include <vector>


class MassSpringSystemSimulator;

//Demo Scene should setup the points and springs 
// (in the init method) and possibly implement  
// other features that are specific for a certain "demo".
class DemoScene
{
public:
	MassSpringSystemSimulator& simulator;

	explicit DemoScene(MassSpringSystemSimulator& simulator)
		: simulator(simulator)
	{
	}

	virtual ~DemoScene() = default;
	virtual void init() = 0;
	virtual void stepPerformedCallback() = 0;
	//TODO: Add other "demo-specific" features as virtual functions, that are called from the MassSpringSystemSimulator file.
	
	void print_points_info();

};


