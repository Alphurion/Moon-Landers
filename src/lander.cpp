#include "lander.h"
#include "system.h"

// Initializes all values of a lander
lander::lander(std::string name, Vector3D pos, double dry_mass, double fuel, double max_flow_rate, double exhaust_velocity) : m_exhaust_velocity(exhaust_velocity), m_dry_mass(dry_mass), m_max_flow_rate(max_flow_rate) 
{
this->m_fuel = fuel;
this->m_pos = pos;
}


char lander::get_status() const {}

bool lander::operator<(const lander &) const
{}

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

bool adjust_thrust(Vector3D){}

void simulate(){}
