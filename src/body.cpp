#include "body.h"

lander::lander(std::string name, Vector3D pos, double dry_mass, double fuel, double max_flow_rate,
               double exhaust_veloicty) 
{
this->m_name = name;
this->m_dry_mass = dry_mass;
this->m_fuel = fuel;
this->m_max_flow_rate = max_flow_rate

this->m_pos = pos;
}
char lander::get_status() const {}

bool operator<(const lander &) const {}

bool operator==(const lander &) const {}

bool adjust_thrust(Vector3D){}

void simulate(){}
