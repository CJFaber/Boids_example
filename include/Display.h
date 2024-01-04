///////////////////////////////////////////////
/// Display Class header (Display.h)
/// Contains the class definition for the main display of the program, draws boids and maintains the
/// Collection of boid sprites
/// Utilizes SMFL for rendering

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Sky.h"
#include "Boid.h"
#include "m_vec.h"

#ifndef DISPLAY_H
#define DISPLAY_H

class Display{

	private:
		//Config parameters
		uint32_t Total_Boids;		//Total number of boids
		int 	Window_Width;		//Display Width
		int 	Window_Height;		//Display height
		int 	Number_Threads;		//Number of OpenMP threads
		float 	Boid_Size;			//Size of boid sprite
		float 	Turn_Speed;			//Speed at which a boid can turn
		float 	Visual_Range;		//Visual range of Boid
		float 	Personal_Space;		//How close a boid can be before it will try and back off
		float 	Coherence_Weight;	//Weight of the coherence rule for boids
		float 	Separation_Weight;	//Weight of the Separation rule
		float 	Alignmnet_Weight;	//Weight of the Alignment rule
		float 	Max_Speed;			//Maximum Boid speed
		float 	Margins;			//Distance at which a boid will start to turn away from the edge
		float 	Limit_Factor;		//Limiting factor of vectors
		float 	Accel_Scale;		//Scale of the acceleration vector
		
		//Display object
		sf::RenderWindow skybox;
		//Boid sprites vector	
		std::vector<sf::CircleShape> Boid_Sprites;

		//Sky Class - Holds all boids
		Sky sky;
		
		//Returns a random float for initial boid placement
		float rand_float();

		//Input for human interation
		bool GrabInput();

		//Displays a boid on screen
		void RenderBoids();

		//Adds a boid to a postion
		void AddBoidToSky(float x, float y);
		

	public:
		//constexpr for defaults
		////////////////////////////////////////////////////////////////////
		constexpr static uint32_t 	DEFAULT_TOTAL_BOIDS 		=500;
		constexpr static int 	 	DEFAULT_WINDOW_HEIGHT		=720;
		constexpr static int 	  	DEFAULT_WINDOW_WIDTH		=1280;
		constexpr static int 		DEFAULT_NUM_THREADS			=4;
		constexpr static float 		DEFAULT_BOID_SIZE			=1;
		constexpr static float 		DEFAULT_TURN_SPEED			=0.75;
		constexpr static float 		DEFAULT_VISUAL_RANGE		=60;
		constexpr static float 		DEFAULT_PERSONAL_SPACE		=30;
		constexpr static float 		DEFAULT_COHERENCE_WT 		=0.1;
		constexpr static float 		DEFAULT_SEPERARATION_WT		=0.8;
		constexpr static float 		DEFAULT_ALIGNMENT_WT		=0.2;
		constexpr static float 		DEFAULT_MAX_SPEED			=6;
		constexpr static float 		DEFAULT_MARGINS				=50;
		constexpr static float 		DEFAULT_TOP_MARGIN			=50;
		constexpr static float 		DEFAULT_BOT_MARGIN			=50;
		constexpr static float 		DEFAULT_LFT_MARGIN			=50;
		constexpr static float 		DEFAULT_RGT_MARGIN			=50;
		constexpr static float 		DEFAULT_LIMIT_FACTOR 		=1;
		constexpr static float 		DEFAULT_ACCEL_SCALE 		=0.35;
		///////////////////////////////////////////////////////////////////
		
		Display(uint32_t Total_Boids, 
				int Window_Width, 
				int Window_Height,
				int Number_Threads, 
				float Boid_Size, 
				float Turn_Speed,
				float Visual_Range, 
				float Personal_Space, 
				float Coherence_Weight,
				float Separation_Weight, 
				float Alignmnet_Weight, 
				float Max_Speed,
				float Margins,
				float Limit_Factor,
				float Accel_Scale 
			   );

		~Display();

		//Main loop of program! Called in main
		void Run();
		
};

#endif //DISPLAY_H

		

