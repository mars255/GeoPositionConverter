#include "coordinates.hpp"
#include <cmath>
#include <iostream>

GeodeticPoint::GeodeticPoint(float lat_val, float lon_val, float height_val)
    : latitude(lat_val), longitude(lon_val), height(height_val) {}
std::ostream &operator<<(std::ostream &os, const GeodeticPoint &point) {
  os << "(" << point.latitude << ", " << point.longitude << ", " << point.height
     << ")";
  return os;
}

ECEFPoint::ECEFPoint(float x_val, float y_val, float z_val)
    : x(x_val), y(y_val), z(z_val) {}
ECEFPoint &ECEFPoint::operator+=(const ECEFPoint &other) {
  x += other.x;
  y += other.y;
  z += other.z;
  return *this;
}
ECEFPoint &ECEFPoint::operator-=(const ECEFPoint &other) {
  x -= other.x;
  y -= other.y;
  z -= other.z;
  return *this;
}
ECEFPoint ECEFPoint::operator-() const { return {-x, -y, -z}; }

ECEFPoint ECEFPoint::operator+(const ECEFPoint &other) const {
  return {x + other.x, y + other.y, z + other.z};
}

ECEFPoint ECEFPoint::operator-(const ECEFPoint &other) const {
  return {x - other.x, y - other.y, z - other.z};
}

std::ostream &operator<<(std::ostream &os, const ECEFPoint &point) {
  os << "(" << point.x << ", " << point.y << ", " << point.z << ")";
  return os;
}
