#include "lander.h"

// Initializes all values of a lander
lander::lander(std::string name, Vector3D pos, double dry_mass, double fuel, double max_flow_rate, double exhaust_velocity) 
: m_exhaust_velocity(exhaust_velocity), m_dry_mass(dry_mass), m_max_flow_rate(max_flow_rate) 
{
this->m_fuel = fuel;
this->m_pos = pos;
this->m_name = name;
this->m_velocity = Vector3D(0, 0, 0);
this->m_thrust = Vector3D(0, 0, 0);
}

char lander::get_status() const {}

bool lander::operator<(const lander & other) const
{
  if (this->m_pos < other.m_pos)
  {
    return true;
  }
  else
  {
    return false;
  }

}

// Checks if 2 landers are in the same position.
bool lander::operator==(const lander &) const
{
  if (m_pos == this->m_pos)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool lander::adjust_thrust(Vector3D thrust)
{
  if(thrust.magnitude() > this->get_max_thrust())
  { // If thrust change is greater than max change, increase as much as possible keeping the ratio
    
    return false;
  }
  else
  { // Successful thrust adjustment
    return true;
  }
}

void simulate(){}
