#include <iostream>
#include "point.h"
#include "cmath"

Point::Point::Point(const double abscissa, const double ordinate, const double applicate) : x{ abscissa }, y{ ordinate }, z{ applicate } {}


bool Point::Point::operator==(const Point& point) const
{
	return(std::abs(this->x - point.x) <= std::numeric_limits<double>::epsilon() && std::abs(this->y - point.y) <= std::numeric_limits<double>::epsilon() && std::abs(this->z - point.z) <= std::numeric_limits<double>::epsilon());
}

bool Point::Point::operator!=(const Point& point) const
{
	return !(*this == point);
}

std::ostream& Point::operator<<(std::ostream& output, const Point& point)
{
	output << point.x << point.y << point.z;
	return output;
}

std::istream& Point::operator>>(std::istream& input, Point& point)
{
	input >> point.x >> point.y >> point.z;
	return input;
}