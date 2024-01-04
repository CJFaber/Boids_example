//Display.cpp 


#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include <random>

#include "Display.h"
#include "Sky.h"
#include "Boid.h"
#include "m_vec.h"


Display::Display(uint32_t Total_Boids, 
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
					float Accel_Scale) : 

	sky(Total_Boids, 
		Window_Width,
	   	Window_Height, 
		Number_Threads, 
		Boid_Size, 
		Turn_Speed,
		Visual_Range, 
		Personal_Space, 
		Coherence_Weight, 
		Separation_Weight, 
		Alignmnet_Weight, 
		Max_Speed, 
		Margins,
		Limit_Factor,
		Accel_Scale)
{
		
	this->Total_Boids = Total_Boids;
	this->Window_Width = Window_Width;
	this->Window_Height = Window_Height;
	this->Number_Threads = Number_Threads; 
	this->Boid_Size = Boid_Size; 
	this->Turn_Speed = Turn_Speed;
	this->Visual_Range = Visual_Range;
	this->Personal_Space = Personal_Space;
	this->Coherence_Weight = Coherence_Weight;
	this->Separation_Weight = Separation_Weight;
	this->Alignmnet_Weight = Alignmnet_Weight; 
	this->Max_Speed = Max_Speed;
	this->Margins = Margins;
	this->Limit_Factor = Limit_Factor;
	this->Accel_Scale = Accel_Scale;
}

Display::~Display() = default;

//Main Function of the simulation, sets up the display window, creates Boids and representaive
//	sprites, and starts the boid's processes
void Display::Run()
{

	//Start the video object
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	skybox.create(sf::VideoMode(Window_Width, Window_Height, desktop.bitsPerPixel), 
			"Boids!", sf::Style::Close);
	
	//Add intial Boids to the sky
	for(uint32_t i = 0; i < Total_Boids; i++){
		AddBoidToSky( (Window_Width*rand_float()) , (Window_Height*rand_float()) ) ;
	}


	//Set Framerate to 60Hz
	skybox.setFramerateLimit(60);
	
	//!!MAIN LOOP!!//
	while (skybox.isOpen())
	{
		if(GrabInput()) 
		{
			//Break if we got a close from the input
			break;
		}
		RenderBoids();
	}
	std::exit(0);
	
}

// Grabs input from the user
bool Display::GrabInput()
{
	sf::Event event;
	while (skybox.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			skybox.close();
			return true;
		}
	}
	//Grab events
	//Left Mouse Click - Spawn a boid
	//Q - Quit
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mouse_xy = sf::Mouse::getPosition(skybox);
		AddBoidToSky(mouse_xy.x, mouse_xy.y);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		skybox.close();
		return true;
	}
	return false;
}

//Adds a Boid and its corresponding sprite
void Display::AddBoidToSky(float x, float y)
{
	//Add boid to sky
	sky.addBoid(x, y);
	
	//Create Boid sprite
	sf::CircleShape shape(Boid_Size, 3);
		shape.setPosition(x,y);
		shape.setFillColor(sf::Color::Green);
		shape.setOutlineColor(sf::Color::Black);
		shape.setOutlineThickness(3);
	Boid_Sprites.emplace_back(shape);
}

void Display::RenderBoids()
{
	//Clear window
	skybox.clear(sf::Color::White);
	//Update all Boids on position
	sky.FlyLoop();
	//DrawLoop
	for(uint32_t i = 0; i < Boid_Sprites.size(); i++)
	{
		Boid* b = sky[i];	
		Boid_Sprites[i].setPosition(b->Pos_Vec.xComp, b->Pos_Vec.yComp);
		Boid_Sprites[i].setRotation(b->CalcAngle());
		skybox.draw(Boid_Sprites[i]);
	}
	skybox.display();
}

//Returns a float for inital position
float Display::rand_float()
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_real_distribution<float> dis(0, 1);
	return dis(gen);
}


