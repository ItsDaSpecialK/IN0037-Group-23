#ifndef MASSSPRINGSYSTEMSIMULATOR_h
#define MASSSPRINGSYSTEMSIMULATOR_h
#include "Simulator.h"
#include "Point.h"
#include "Spring.h"
#include "Spring.h"
#include "DemoScene.h"
// Do Not Change
#define EULER 0
#define LEAPFROG 1
#define MIDPOINT 2
// Do Not Change


class MassSpringSystemSimulator:public Simulator{
public:
	// Constructors
	MassSpringSystemSimulator();
	
	// UI Functions
	const char * getTestCasesStr();
	void initUI(DrawingUtilitiesClass * DUC);
	void clearSimulation();
	void reset();
	void drawFrame(ID3D11DeviceContext* pd3dImmediateContext);
	void notifyCaseChanged(int testCase);
	void externalForcesCalculations(float timeElapsed);
	void computeForces();
	void integratePositionsEuler(float timestep);
	void integrateVelocitiesEuler(float timestep);
	void simulateTimestepEuler(float timestep);
	//Computes the forces based on the temporary positions of points
	//I.e. the positions that were generated only for the intermediate step of the integration.
	void computeForcesTmp();
	void simulateTimestepMidpoint(float time_step);
	void simulateTimestep(float timeStep);
	void onClick(int x, int y);
	void onMouse(int x, int y);

	// Specific Functions
	void setMass(float mass);
	void setStiffness(float stiffness);
	void setDampingFactor(float damping);
	//returns the index of the point in the vector 'points'
	int addMassPoint(Vec3 position, Vec3 Velocity, bool isFixed);
	//masspoint1 and masspoint2 are indices returned by the addMassPoint function.
	void addSpring(int masspoint1, int masspoint2, float initialLength);
	int getNumberOfMassPoints();
	int getNumberOfSprings();
	Vec3 getPositionOfMassPoint(int index);
	Vec3 getVelocityOfMassPoint(int index);
	void applyExternalForce(Vec3 force);
	void addExternalForcesToPoints(Vec3 force);
	void enforceBounds();
	
	// Do Not Change
	void setIntegrator(int integrator) {
		m_iIntegrator = integrator;	
	}


	std::vector<Point>& getPoints()
	{
		return points;
	}

private:
	// Data Attributes
	//used for every new point
	float m_fMass;
	//used for every new spring
	float m_fStiffness;
	//TODO: Damping is not used, yet
	float m_fDamping;
	//MIDPOINT or EULER
	int m_iIntegrator;
	
	// UI Attributes
	Vec3 m_externalForce;
	Point2D m_mouse;
	Point2D m_trackmouse;
	Point2D m_oldtrackmouse;
	//list of all points, a new point is added by the function addMassPoint
	std::vector<Point> points;
	//list of all springs, a new spring is inserted using the addSpring function.
	std::vector<Spring> springs;
	//currently selected demo scene, might be null (e.g. during the unit tests)
	DemoScene* currentDemo;
	//Demo Scenes should correspond to demo 1, demo2 etc. in the assignments, this is a list of all available scenes
	std::vector<std::unique_ptr<DemoScene>> scenes;
	Vec3 gravity;
	float gravityScale;
	Vec3 calculateUserInteractionForce(float timeStep);
};
#endif
