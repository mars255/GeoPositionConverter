#include "conversion.hpp"
#include "coordinates.hpp"
#include <iostream>
int main() {
  auto original = GeodeticPoint(23, 40, 22);
  std::cout << "Original point (lla): " << original << "\n";
  auto ecef = convert_geodetic_to_ecef(original);
  std::cout << "ECEF (m): " << ecef << "\n";

  auto res = convert_ecef_to_geodetic(ecef, 4);
  std::cout << "Converted back to lla: " << res << "\n";

  return 0;
}
