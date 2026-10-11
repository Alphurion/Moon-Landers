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

class lander
{
public:
  // name, meters, kg, kg, kg/s, m/s
  lander(std::string name, Vector3D pos, double dry_mass, double fuel, double max_flow_rate, double exhaust_velocity);

  char get_status() const;
  Vector3D get_position() const { return this->pos; }
  Vector3D get_velocity() const { return this->velocity; }
  double get_mass() const { return this->fuel + this->dry_mass; }
  double get_max_thrust() const { return max_flow_rate * exhaust_velocity; }

  bool operator<(const lander &) const;
  bool operator==(const lander &) const;
  bool adjust_thrust(Vector3D);
  void simulate();

private:
  Vector3D pos, velocity, thrust;
  double fuel;
  // total_mass = dry_mass + fuel
  bool grounded;
  std::string const name;
  const double exhaust_velocity, dry_mass, max_flow_rate; // Exhaust velocity
  };
