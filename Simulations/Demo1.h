#pragma once
#ifndef DEMO1_H
#define DEMO1_H

#include "DemoScene.h"
//The demo 1 initialization, see the pdf assignment for details.
class Demo1 :public DemoScene
{
public:
	Demo1(MassSpringSystemSimulator& s) : DemoScene(s), elapsed_frames(0)
	{
	}

	void init() override;

	void stepPerformedCallback() override;

	~Demo1() override;
private:
	int elapsed_frames;
};


#endif // DEMO1_H


