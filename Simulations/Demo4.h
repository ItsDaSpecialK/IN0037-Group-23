#pragma once
#ifndef DEMO4_H
#define DEMO4_H
#include "DemoScene.h"


class Demo4:public DemoScene
{
public:
	explicit Demo4(MassSpringSystemSimulator& simulator)
		: DemoScene(simulator)
	{
	}

	void init() override;
	void stepPerformedCallback() override;
};

#endif // DEMO4_H
