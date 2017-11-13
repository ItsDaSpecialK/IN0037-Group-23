#pragma once
#ifndef DEMO1_H
#define DEMO1_H

#include "DemoScene.h"
//The demo 1 initialization, see the pdf assignment for details.
class Demo1 :public DemoScene
{
public:
	Demo1(MassSpringSystemSimulator& s) : DemoScene(s)
	{
	}
	void init() override;

	~Demo1() override;
};


#endif // DEMO1_H


