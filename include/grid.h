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
    bool operator<(const Vector3D &other) const
    {
        if ( x + y + z < other.x + other.y + other.z)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator>(const Vector3D &other) const
    {
        if ( x + y + z > other.x + other.y + other.z)
        {
            return true;
        }
        else
        {
            return false;
        }
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

