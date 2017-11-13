#ifndef DEMO2_H
#define DEMO2_H
#include "DemoScene.h"
#include "TwoPointsDemoScene.h"

class Demo2 : public TwoPointsDemoScene
{
public:

	explicit Demo2(MassSpringSystemSimulator& simulator)
		: TwoPointsDemoScene(simulator)
	{
	}

	void init() override;
	void stepPerformedCallback() override;
};



#endif // DEMO2_H