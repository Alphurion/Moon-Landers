#pragma once
#include "grid.h"

#include <string>
/*
Lander class used for any rockets, satelites, etc.
*/
class lander
{
public:
  // name, meters, kg, kg, kg/s, m/s
  lander(std::string name, Vector3D pos, double dry_mass, double fuel, double max_flow_rate, double exhaust_velocity);
  lander(const lander &other);
  char get_status() const;
  double get_mass() const { return this->m_fuel + this->m_dry_mass; }
  double get_max_thrust() const { return m_max_flow_rate * m_exhaust_velocity; }

  bool operator<(const lander &) const;
  bool operator==(const lander &) const;
  bool adjust_thrust(Vector3D);
  void simulate();

private:
  friend class interstellarObject;
  Vector3D m_pos, m_velocity, m_thrust;
  double m_fuel;
  // total_mass = dry_mass + fuel
  bool m_grounded;
  std::string m_name;
  const double m_exhaust_velocity;
  const double m_dry_mass;
  const double m_max_flow_rate; // Exhaust velocity
  };
