
#include "Display.h"

#include "cxxopts.hpp"
int main(int argc, char **argv)
{
	cxxopts::Options options("boids", "Boids life algo. simulation using sfml and OpenMP, click to add a boid.");

	options.add_options()
			("boids" , "Total number of initial Boids",
			 	cxxopts::value<uint32_t>()->default_value(std::to_string(Display::DEFAULT_TOTAL_BOIDS)))
            ("height", "Height of the window.",
             	cxxopts::value<int>()->default_value(std::to_string(Display::DEFAULT_WINDOW_HEIGHT)))
			("width", "Width of the window.",
			 	cxxopts::value<int>()->default_value(std::to_string(Display::DEFAULT_WINDOW_WIDTH)))
            ("num_thread", "Maximum number of threads",
             	cxxopts::value<int>()->default_value(std::to_string(Display::DEFAULT_NUM_THREADS)))
            ("boid_size", "The size of the boids.",
             	cxxopts::value<float>()->default_value(std::to_string(Display::DEFAULT_BOID_SIZE)))
			("turn_speed", "Turning speed of a boid.",
             	cxxopts::value<float>()->default_value(std::to_string(Display::DEFAULT_TURN_SPEED))) 
            ("visual_range", "Range for which a boid can see another boid",
             	cxxopts::value<float>()->default_value(std::to_string(Display::DEFAULT_VISUAL_RANGE)))
            ("personal_space", "Range for which a boid will try to avoid another boid",
             	cxxopts::value<float>()->default_value(std::to_string(Display::DEFAULT_PERSONAL_SPACE)))
            ("coherence_weight", "Weight applied to the cohesion rule.",
             	cxxopts::value<float>()->default_value(std::to_string(Display::DEFAULT_COHERENCE_WT)))
            ("separation_weight", "Weight applied to the separation rule.",
             	cxxopts::value<float>()->default_value(std::to_string(Display::DEFAULT_SEPERARATION_WT)))
            ("alignment_weight", "Weight applied to the alignment rule.",
             	cxxopts::value<float>()->default_value(std::to_string(Display::DEFAULT_ALIGNMENT_WT)))
			("max_speed", "Maximum speed of a boid.",
             	cxxopts::value<float>()->default_value(std::to_string(Display::DEFAULT_MAX_SPEED)))
            ("margins", "Margins for the edge of the window",
             	cxxopts::value<float>()->default_value(std::to_string(Display::DEFAULT_TOP_MARGIN)))
            ("limit_factor", "Sets the limit on the maximum force a vector can have",
             	cxxopts::value<float>()->default_value(std::to_string(Display::DEFAULT_LIMIT_FACTOR)))
            ("acceleration_scale", "Sets the scale factor of the acceleration",
             	cxxopts::value<float>()->default_value(std::to_string(Display::DEFAULT_ACCEL_SCALE)))
            ("help", "Displays this help message.");
	auto result = options.parse(argc, argv);

	if(result["help"].as<bool>()){
	//if(true){
		std::cout << options.help() << std::endl;
		return 0;
	}

	//Create Display with values provided by cxxopts
	
	Display display(result["boids"].as<uint32_t>(), 
						result["width"].as<int>(), 
						result["height"].as<int>(),
                        result["num_thread"].as<int>(), 
						result["boid_size"].as<float>(),
                        result["turn_speed"].as<float>(), 
						result["visual_range"].as<float>(),
                        result["personal_space"].as<float>(), 
						result["coherence_weight"].as<float>(),
                        result["separation_weight"].as<float>(), 
						result["alignment_weight"].as<float>(),
                        result["max_speed"].as<float>(), 
						result["margins"].as<float>(),
						result["limit_factor"].as<float>(),
						result["acceleration_scale"].as<float>());
						

	//Run main display loop
	display.Run();
	return EXIT_SUCCESS;
}
