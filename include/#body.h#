#include <string>
#include <vector>
#include <cmath>

/*
Magnitude, Direction, also has sum operator
*/
struct Vector3D {
    double x,y,z;
    Vector3D(double x_val = 0.0, double y_val = 0.0, double z_val = 0.0) : x(x_val), y(y_val), z(z_val) {}
    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }
    bool operator==(const Vector3D &other) const
    {
    return ((x == other.x) && (y == other.y) && (z == other.z));  
    }
    //sqrt (x^2 + y^2 + z^2)
    double magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }
    // Linar transormation from 3D -> 1D
    double Vec3Dto1D() const {
      return (x + y + z);
    }
};

/*
Lander class used for any rockets, satelites, etc.
*/
class lander
{
public:
  // name, meters, kg, kg, kg/s, m/s
  lander(std::string name, Vector3D pos, double dry_mass, double fuel, double max_flow_rate, double exhaust_velocity)
    : m_dry_mass(dry_mass), m_exhaust_velocity(exhaust_velocity), m_max_flow_rate(max_flow_rate){};
  
  char get_status() const;
  Vector3D get_position() const { return this->m_pos; }
  Vector3D get_velocity() const { return this->m_velocity; }
  double get_mass() const { return this->m_fuel + this->m_dry_mass; }
  double get_max_thrust() const { return m_max_flow_rate * m_exhaust_velocity; }

  bool operator<(const lander &) const;
  bool operator==(const lander &) const;
  bool adjust_thrust(Vector3D);
  void simulate();

private:
  Vector3D m_pos, m_velocity, m_thrust;
  double m_fuel;
  // total_mass = dry_mass + fuel
  bool m_grounded;
  std::string const m_name;
  const double m_exhaust_velocity, m_dry_mass, m_max_flow_rate; // Exhaust velocity
  };
