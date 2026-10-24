#include "grid.h"
#include "lander.h"

#ifndef PI 
#define PI 3.141592

/*
 Stats and functions for planets, asteroids, and the like.
*/

class body
{
public:
  Vector3D relative_position(const lander &);
  
private:
  Vector3D position, acceleration, velocity;
  const double radius, mass;
  const double gravity;
};

#endif
