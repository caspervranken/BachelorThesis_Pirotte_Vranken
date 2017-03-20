#ifndef INNERSPHERETREE_H
#define INNERSPHERETREE_H

#include "collisions/CGenericCollision.h"
#include "ist/Sphere.h"

/*
	UHAS IMPLEMENTED

	\author Casper Vranken
	\author Niels Pirotte
*/

namespace chai3d {

	class InnerSphereTree : public cGenericCollision {

	// CONSTRUCTOR - DESTRUCTOR
	public:

		// Constructor of the inner sphere tree.
		InnerSphereTree();

		// Destructor of the inner sphere tree.
		virtual ~InnerSphereTree();

	// PUBLIC METHODS
	public:

		// Computes the collision between 2 inner sphere trees.
		virtual bool computeCollision(cGenericCollision* ist2, traversalSetting setting, double &collisionfeedback, int maxdiepte, cVector3d myLocal, cVector3d BLocal, cVector3d& positie);
		// Get the type of tree. In this case IST.
		virtual inline CollisionTreeType getCollisionTreeType() { return CollisionTreeType::IST; };
		// Render the leaf nodes.
		virtual void render(cRenderOptions& a_options);
		// Get the rootsphere of this inner sphere tree.
		Sphere* getRootSphere();
		//! This method computes all collisions between a segment passed as argument and the attributed 3D object.
		virtual bool computeCollision(cGenericObject* a_object,
			cVector3d& a_segmentPointA,
			cVector3d& a_segmentPointB,
			cCollisionRecorder& a_recorder,
			cCollisionSettings& a_settings)
		{
			return (false);
		}

		inline virtual void update() {}
		//UHAS implemented
		//This method prints the AABB box tree for this mesh
		virtual void printAABBCollisionTree(int maxDiepte) {};

	// DATA MEMBERS
	private:

		// The rootsphere
		Sphere* rootSphere;

		std::vector<Sphere*> spheres;

	// PROTECTED FUNCTIONS
	public:

		// This method is used to recursively build the collision tree.
		int buildTree(std::vector<Sphere*> leafs, const int a_depth);

		inline std::vector<Sphere*> getSpheres() { return spheres; }

	};
}

#endif