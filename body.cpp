#include "body.h"
#include <string>

lander::lander(std::string name, Vector3D pos, double dry_mass, double fuel, double max_flow_rate,
               double exhaust_veloicty)
{
  this->dry_mass = dry_mass;
}
char lander::get_status() const
{
  
}
