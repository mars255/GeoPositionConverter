#include "conversion.hpp"
#include <cmath>
float deg2rad(float deg) { return deg * 3.141592 / 180.0; }

float rad2deg(float rad) { return rad * 180 / 3.141592; }

float prime_vertical(float angle) {
  return A / sqrt(1 - E2 * pow(std::sin(angle), 2));
}

ECEFPoint convert_geodetic_to_ecef(const GeodeticPoint &coords) {
  const float cos_lat = std::cos(deg2rad(coords.latitude));
  const float sin_lat = std::sin(deg2rad(coords.latitude));
  const float cos_long = std::cos(deg2rad(coords.longitude));
  const float sin_long = std::sin(deg2rad(coords.longitude));

  const float N = prime_vertical(deg2rad(coords.latitude));

  float x = (N + coords.height) * cos_lat * cos_long;
  float y = (N + coords.height) * cos_lat * sin_long;
  float z = ((1 - E2) * N + coords.height) * sin_lat;

  return ECEFPoint(x, y, z);
}

GeodeticPoint convert_ecef_to_geodetic(const ECEFPoint &coords,
                                       int iterations = 4) {
  // Find longitude
  float longitude = std::atan2(coords.y, coords.x);
  // Physical radius, x-y radius
  float r = std::sqrt(coords.x * coords.x + coords.y * coords.y +
                      coords.z * coords.z);
  float p = std::sqrt(coords.x * coords.x + coords.y * coords.y);
  // Iterate
  float kappa = A * std::atan2(p, coords.z);
  float h, n = 0;

  for (int i = 0; i < iterations; i++) {
    n = prime_vertical(kappa);
    h = (p / std::cos(kappa)) - n;
    kappa = std::atan2(coords.z, p * (1 - E2 * n / (n + h)));
  }

  h = (p / std::cos(kappa)) - prime_vertical(kappa);
  return {rad2deg(kappa), rad2deg(longitude), h};
}
