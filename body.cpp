#include "body.h"
#include <vector>
#include <limits>

const Vector2D Earth = {0, 0};
double E_r = 6378; // km
const Vector2D Moon = {264400.0, 120000.0};
double M_r = 1735.5; //km
const double T_ = 0.005; // \delta t = 0.005s
lander::lander(std::string name, Vector2D pos, double fuel)
{
  this->pos = pos;
  this->name = name;
  stillLanding = true;
}

bool lander::adjust_thrust(Vector2D delta)
{
  if (( (this->thrust + delta).Vec2Dto1D() > this->max_thrust))
  {
    return false;
  }
  this->thrust = delta + this->thrust;
  return true;
}

void lander::simulate()
{
  
}
