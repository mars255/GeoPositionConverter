#include <cmath>
#include <iostream>

#pragma once
// Flattening, equatorial radius, polar radius
constexpr float F = 1.f / 298.257224f;
constexpr float A = 6378137.f;
constexpr float E2 = F * (2 - F);

// Coordinate systems with overriden methods

struct GeodeticPoint {
  float longitude;
  float latitude;
  float height;
  GeodeticPoint(float lat_val, float long_val, float height_val);
  friend std::ostream &operator<<(std::ostream &os, const GeodeticPoint &point);
};

/*x, y, and z are given in METERS*/
struct ECEFPoint {
  float x, y, z;
  ECEFPoint(float x_val, float y_val, float z_val);
  ECEFPoint &operator+=(const ECEFPoint &other);
  ECEFPoint &operator-=(const ECEFPoint &other);
  ECEFPoint operator-() const;

  ECEFPoint operator+(const ECEFPoint &other) const;

  ECEFPoint operator-(const ECEFPoint &other) const;

  friend std::ostream &operator<<(std::ostream &os, const ECEFPoint &point);
};
