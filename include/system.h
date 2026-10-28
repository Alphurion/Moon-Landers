#include "lander.h"

#include <memory>


/*
Represents any interstellar object and simulates landers and other objects in space
Vector3D orbit: Calculates the position of the object in orbit at a given time
bool operator==: surface collision detection
bool operator<: atmosphere detection
*/
class interstellarObject
{
  public:
  interstellarObject(std::string name, Vector3D pos, double r_atmos, double r_surface, double mass);
  Vector3D orbit(double time) const;
  bool operator==(const lander &) const;
  bool operator<(const lander &) const;
  
  private:
  friend class lander;
  const std::string m_name;
  Vector3D m_pos;
  interstellarObject *m_orbitingObject;
  double m_r_atmos;
  const double m_r_surface;
  const double m_mass;
  
};
// System constant
#ifndef SUN
#define SUN interstellarObject("Sun", Vector3D(0, 0, 0), 696340000, 696340000, 1.989e30)
#endif
