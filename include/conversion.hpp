#include "coordinates.hpp"

/*Convert degrees to radians and viceversa*/
float deg2rad(float deg);
float rad2deg(float rad);

/*Needed for conversions*/
float prime_vertical(float angle);

/*Convert from one system to the other*/
ECEFPoint convert_geodetic_to_ecef(const GeodeticPoint &coords);
GeodeticPoint convert_ecef_to_geodetic(const ECEFPoint &coords, int iterations);
