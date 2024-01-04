#include <iostream>
#include <cmath>
#include <random>
#include "Boid.h"
#include "m_vec.h"


float Boid::rand_float()
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_real_distribution<float> dis(0, 1);
	return dis(gen);
}

/////////////////////////////
// Boids Constructors
//

Boid::Boid(float x, float y, float PSpace, float Vision, float Speed) : 
	Boid_PSpace{PSpace},
	Boid_Vision{Vision},
	Boid_MaxSpeed{Speed}
{
	//Position given by button press
	Pos_Vec = m_vec(x, y);

	//Rand value 50/50 negative, multiply by max speed
	Vel_Vec = ((rand_float() - 0.5)*(Boid_MaxSpeed)); 
	
	//Inital acceleration is zero
	Acc_Vec = m_vec(0.0, 0.0);	
}

Boid::~Boid() = default;

const m_vec 	Boid::Get_Pos () const
{
	return Pos_Vec;
}

const m_vec 	Boid::Get_Vel () const
{
	return Vel_Vec;
}

const m_vec 	Boid::Get_Accel () const
{
	return Acc_Vec;
}

/////////////////////////
//Boids algo functions

// Coherence rule, we want boids to attract to the center of mass of the boids that it sees
m_vec 	Boid::Coherence( const std::vector<Boid *> &allBoids) 
{
	m_vec 	CohVector;
	float 	count = 0.0;
	float 	dist = 0.0;

	for(uint32_t i = 0; i < allBoids.size(); i++)
	{
		dist = Pos_Vec.Distance( allBoids[i]->Get_Pos());
		if( (dist < Boid_Vision) && (dist >0) )
		{//If the boid is in our vision add it's position to the coh vector
			CohVector += allBoids[i]->Pos_Vec;
			count++;
		}

	}
	if(count == 0.0)
	{
		return CohVector;
	}
	//Find average of Coh vector and point to it
	CohVector /= count;
	CohVector -= Pos_Vec;
	//Normalize
	return CohVector.Normalize();
}

// Seperation Rule, we don't want boids to be to close to back off when they are within out protection range
m_vec 	Boid::Separation(const std::vector<Boid *> &allBoids) 
{
	m_vec 	SepVector;
	float 	dist = 0.0;

	for(uint32_t i = 0; i < allBoids.size(); i++)
	{
		dist = Pos_Vec.Distance(allBoids[i]->Get_Pos());
		if( (dist < Boid_PSpace) && (dist >0) )
		{//If the boid is in our protection range subtract their position their postion
			SepVector -= (allBoids[i]->Pos_Vec - Pos_Vec);
		}
	}
	//Normalize
	return SepVector.Normalize();
}

//Alignment Rule, we want the boids to fly in a similar direction so consider other boids vectors
m_vec 	Boid::Alignmnet(const std::vector<Boid *> &allBoids) 
{
	m_vec 	AliVector;
	float 	count = 0.0;
	float 	dist = 0.0;
	for(uint32_t i = 0; i < allBoids.size(); i++)
	{
		dist = Pos_Vec.Distance(allBoids[i]->Get_Pos());
		if( (dist > 0) && (dist < Boid_Vision) )
		{//If the boid is in our vision add it's current vector to the alignment vector
			AliVector += allBoids[i]->Vel_Vec;
			count++;
		}
	}
	if(count == 0.0){
		return AliVector;
	}
	//Find the average of the Alignment vector
	AliVector /= count;
	//Subtract our current movement vector from the alignment vector for difference 
	AliVector -= Vel_Vec;
	//Normalize
	return AliVector.Normalize();
}

//Used to find the angle at which the boid should be pointing towards
float 	Boid::CalcAngle()
{
	return (float)(atan2(Vel_Vec.xComp, -(Vel_Vec.yComp)) * 180 / PI);
}		




