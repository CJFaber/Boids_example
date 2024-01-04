// boids.h
// Contains the define for the boids class, works in a 2D space.
//
//
// Each boid has it's own set of rules it follows:
// 		1.) Cohesion - Fly towards the center of mass of neighbouring boids
//		2.) Seperation - Boids try to maintain a set distance away from other boids
//		3.) Alignment - Velocity Match with nearby boids	
//	These are all maintained by vectors implemented by the class m_vec (movement vector)
//
//	Each boid occupies a 4x4 space and has a range in the sky of which it is considers other boids, 
//		this is usually a circle around them, but can be reduced to actual visual sight in flight (a cone)
//	
//	Would be cool to add little animations for the boids

#include <vector>
#include <iostream>
#include <stdlib.h>
#include "m_vec.h"

#ifndef BOID_H_
#define BOID_H_



#define PI 3.141592

//Globals for updates during running
class Boid {
	private:
		float 	rand_float(); 	
	
	public:
		//Bird attributes
		
		//Movement vectors
		m_vec Pos_Vec;
		m_vec Vel_Vec;
		m_vec Acc_Vec;
		float Boid_PSpace;
		float Boid_Vision;
		float Boid_MaxSpeed;
		//Random Float: used for velocity vector

		//Constructor 
		Boid	() {}
		~Boid 	();
		Boid	(float x, float y, float PSpace, float Vision, float Speed);
		
		//Const Getter Methods
		const m_vec 	Get_Pos() const;
		const m_vec 	Get_Vel() const; 
		const m_vec 	Get_Accel() const;

		//Methods for base Boids algorithm
		m_vec 	Coherence 	(const std::vector<Boid *> &allBoids) ;
		m_vec 	Separation 	(const std::vector<Boid *> &allBoids) ;
		m_vec 	Alignmnet	(const std::vector<Boid *> &allBoids) ;

		void CalculateHeading(m_vec up_coh, m_vec up_sep, m_vec up_ali);
		void UpdateHeading(m_vec up_coh, m_vec up_sep, m_vec up_ali);
		float CalcAngle();

		//Function for random vector setup

};

#endif //_BOID_H
