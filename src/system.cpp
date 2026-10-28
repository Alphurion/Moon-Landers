#include "system.h"

interstellarObject::interstellarObject(std::string name, Vector3D pos, double r_atmos, double r_surface, double mass)
: m_name(name), m_pos(pos), m_r_atmos(r_atmos), m_r_surface(r_surface), m_mass(mass)
{

}

bool interstellarObject::operator==(const lander &lander) const
{
  if (lander.m_pos == this->m_r_surface)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool interstellarObject::operator<(const lander &lander) const
{
  if (lander.m_pos < this->m_r_atmos)
  {
    return true;
  }
  else
  {
    return false;
  }
}