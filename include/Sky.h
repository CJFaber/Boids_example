//	sky.h
//	Contains the class for managing the flock of boids
//	all boids fly in the sky
//

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>
#include "Boid.h"

#ifndef SKY_H 
#define SKY_H


class Sky {
	//Program config variables
	private:
		
		uint32_t	Total_Boids;
		int		 	Window_Width;
		int 		Window_Height;
		int 		Number_Threads;
		float 		Boid_Size;

		float 		Turn_Speed;
		float		Visual_Range;
		float		Personal_Space;
		
		float 		Coherence_Weight;
		float 		Separation_Weight;
		float 		Alignmnet_Weight;

		float 		Max_Speed;
		
		//Margins for display, Top left of display window is origin (0,0)
		float 		Top_Margin;			
		float 		Bot_Margin;
		float 		Lft_Margin;
		float 		Rgt_Margin;

		//Acceleration Modifiers
		float 		Limit_Factor;
		float 		Accel_Scale;
	
		
		std::vector<Boid *> allBoids;
	public:	

		Sky(uint32_t Total_Boids, int Window_Width, int Window_Height,
			int Number_Threads, float Boid_Size, float Turn_Speed,
			float Visual_Range, float Personal_Space, float Coherence_Weight,
			float Separation_Weight, float Alignmnet_Weight, float Max_Speed,
			float Margins, float Limit_Factor, float Accel_Scale) ;
	
		~Sky();
		
		Boid* operator[](int i) const;
				
		void addBoid(float x, float y);

		void clear();

		void FlyLoop();
}; 

#endif //SKY_H
