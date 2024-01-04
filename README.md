Boids program written in C++ 

- Utilizes [SFML](https://www.sfml-dev.org/index.php) for rendering, required for compilation 

- Multi-threading currently not implemented 

Usage:
./boids.exe 

Click in the window to add a boid!
```
Boids life algo. simulation using sfml and OpenMP, click to add a boid.
Usage:
  boids [OPTION...]

      --boids arg               Total number of initial Boids (default: 500)
      --height arg              Height of the window. (default: 720)
      --width arg               Width of the window. (default: 1280)
      --num_thread arg          Maximum number of threads (default: 4)
      --boid_size arg           The size of the boids. (default: 1.000000)
      --turn_speed arg          Turning speed of a boid. (default: 0.750000)
      --visual_range arg        Range for which a boid can see another boid
                                (default: 60.000000)
      --personal_space arg      Range for which a boid will try to avoid
                                another boid (default: 30.000000)
      --coherence_weight arg    Weight applied to the cohesion rule.
                                (default: 0.100000)
      --separation_weight arg   Weight applied to the separation rule.
                                (default: 0.800000)
      --alignment_weight arg    Weight applied to the alignment rule.
                                (default: 0.200000)
      --max_speed arg           Maximum speed of a boid. (default: 6.000000)
      --margins arg             Margins for the edge of the window (default:
                                50.000000)
      --limit_factor arg        Sets the limit on the maximum force a vector
                                can have (default: 1.000000)
      --acceleration_scale arg  Sets the scale factor of the acceleration
                                (default: 0.350000)
      --help                    Displays this help message.



```


Algortihm explaination: 

- [https://en.wikipedia.org/wiki/Boids](https://en.wikipedia.org/wiki/Boids)

- [https://vergenet.net/~conrad/boids/pseudocode.html](https://vergenet.net/~conrad/boids/pseudocode.html)

- [https://cs.stanford.edu/people/eroberts/courses/soco/projects/2008-09/modeling-natural-systems/boids.html](https://cs.stanford.edu/people/eroberts/courses/soco/projects/2008-09/modeling-natural-systems/boids.html)

To Do:
Add multi-threading and partitioning to make faster
Add user sliders for parameter change
Fuse boid algorithm loops togther for more efficiency 

