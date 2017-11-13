#pragma once
#ifndef DEMO1_H
#define DEMO1_H

#include "DemoScene.h"
#include "TwoPointsDemoScene.h"

//The demo 1 initialization, see the pdf assignment for details.
class Demo1 :public TwoPointsDemoScene
{
public:
	Demo1(MassSpringSystemSimulator& s) : TwoPointsDemoScene(s)
	{
	}

	void init() override;

	void stepPerformedCallback() override;

	~Demo1() override;
private:
	
};


#endif // DEMO1_H


