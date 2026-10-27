#include "lander.h"

#include <memory>


/*
Represents any interstellar object and simulates landers and other objects in space
Vector3D orbit: Calculates the position of the object in orbit at a given time

*/
class interstellarObject
{
  public:
  interstellarObject(std::string name, Vector3D pos, double r_atmos, double r_surface, double mass);
  Vector3D orbit(double time) const;
  
  private:
  const std::string m_name;
  Vector3D m_pos;
  interstellarObject *m_orbitingObject;
   
  
};
// System constant
#ifndef SUN
#define SUN interstellarObject("Sun", Vector3D(0, 0, 0), 696340000, 696340000, 1.989e30)
#endif
