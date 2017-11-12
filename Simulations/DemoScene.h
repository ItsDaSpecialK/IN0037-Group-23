﻿#pragma once
#include "Point.h"
#include "Spring.h"
#include <vector>

class MassSpringSystemSimulator;

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
	//TODO: Add other "demo-specific" features as virtual functions, that are called from the MassSpringSystemSimulator file.

};

