#ifndef TWOPOINTSDEMOSCENE_H
#define TWOPOINTSDEMOSCENE_H

#include "DemoScene.h"

class TwoPointsDemoScene : public DemoScene
{
public:

	explicit TwoPointsDemoScene(MassSpringSystemSimulator& simulator)
		: DemoScene(simulator), elapsed_frames(0)
	{
	}

	void init() override;
	void stepPerformedCallback() override;
private:
	int elapsed_frames;
};


#endif // TWOPOINTSDEMOSCENE_H