#include <vector>

#include "Sky.h"
#include "Boid.h"

//Sky Constructior
Sky::Sky(uint32_t Total_Boids, int Window_Width, int Window_Height,
			int Number_Threads, float Boid_Size, float Turn_Speed,
			float Visual_Range, float Personal_Space, float Coherence_Weight,
			float Separation_Weight, float Alignmnet_Weight, float Max_Speed,
			float Margins, float Limit_Factor, float Accel_Scale) : 
	Total_Boids			{Total_Boids},
	Window_Width		(Window_Width),
	Window_Height		(Window_Height),
	Number_Threads		{Number_Threads},
	Boid_Size			{Boid_Size},
	Turn_Speed			{Turn_Speed},
	Visual_Range		{Visual_Range},
	Personal_Space		{Personal_Space},
	Coherence_Weight	{Coherence_Weight},
	Separation_Weight	{Separation_Weight},
	Alignmnet_Weight	{Alignmnet_Weight},
	Max_Speed			{Max_Speed},
	Top_Margin			(Margins),
	Bot_Margin			(Window_Height - Margins),
	Lft_Margin			(Margins),
	Rgt_Margin			(Window_Width - Margins),
	Limit_Factor		{Limit_Factor},
	Accel_Scale 		{Accel_Scale}
{}

//Destructor - Frees all boids allocated created in display
Sky::~Sky()
{
	for(uint32_t i = 0; i < allBoids.size(); i++)
	{
		delete allBoids[i];
	}
}

//Creates a new boid
void Sky::addBoid(float x, float y)
{
	allBoids.emplace_back(new Boid(x, y, Personal_Space, Visual_Range, Max_Speed));
	Total_Boids++;
}

//Overload of [] for allBoids
Boid* Sky::operator[](int i) const
{
	return allBoids[i];
}

//Deletes allBoids
void Sky::clear()
{
	for(uint32_t i = 0; i < Total_Boids; i++)
	{
		delete allBoids[i];
	}
}

//Fly loop
//Main loop in Sky, called in display to calculated boids movement and rule effects
void Sky::FlyLoop()
{
		for(uint32_t i = 0; i < allBoids.size(); i++)
		{	
					m_vec up_coh = allBoids[i]->Coherence(allBoids) * Coherence_Weight;
					m_vec up_sep = allBoids[i]->Separation(allBoids) * Separation_Weight;
					m_vec up_ali = allBoids[i]->Alignmnet(allBoids) * Alignmnet_Weight;
					
					//sum vectors for final accleration
					allBoids[i]->Acc_Vec += (up_ali + up_coh + up_sep);
		
					//Handle screen wrap
					//
					//If we are too close to the left margin add turn speed to x
					if(allBoids[i]->Pos_Vec.xComp < Lft_Margin)
					{
						allBoids[i]->Acc_Vec.xComp += Turn_Speed;
					}
					//If we are too close to the right margin subtract turn speed from x
					if(allBoids[i]->Pos_Vec.xComp > Rgt_Margin)
					{	
						allBoids[i]->Acc_Vec.xComp -= Turn_Speed;
					}
					
					//If we are too close to the top margin add turn speed to y
					if(allBoids[i]->Pos_Vec.yComp < Top_Margin)
					{				
						allBoids[i]->Acc_Vec.yComp += Turn_Speed;
					}
					//If we are too close to the bottom margin subtract turn speed from y
					if(allBoids[i]->Pos_Vec.yComp > Bot_Margin)
					{
						allBoids[i]->Acc_Vec.yComp -= Turn_Speed;
					}	
		
					//Scale and limit the acceleration
					allBoids[i]->Acc_Vec *= Accel_Scale;
					allBoids[i]->Acc_Vec.Limit(Limit_Factor);

					//Everyone has figured out their acceleration vectors update velocity
					allBoids[i]->Vel_Vec += allBoids[i]->Acc_Vec;	//Add Acceleration
					allBoids[i]->Vel_Vec.Limit(Max_Speed);			//Limit Speed
					allBoids[i]->Pos_Vec += allBoids[i]->Vel_Vec;	//add Velocity to Posisiton vector
					allBoids[i]->Acc_Vec = 0;						//Reset Acceleration
		}

}



