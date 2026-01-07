#include "Fixed.hpp"
#include "Point.hpp"

//https://stackoverflow.com/a/2049712
//https://stackoverflow.com/a/34093754
//bool bsp( Point const a, Point const b, Point const c, Point const point) {
//	Fixed dX = point.getX() - c.getX();
//    Fixed dY = point.getY() - c.getY();
//    Fixed dX21 = c.getX() - b.getX();
//    Fixed dY12 = b.getY() - c.getY();
//    Fixed D = dY12 * (a.getX() - c.getX()) + dX21*(a.getY() - c.getY());
//    Fixed s = dY12*dX + dX21*dY;
//    Fixed t = (c.getY() - a.getY())*dX + (a.getX() - c.getX())*dY;
//    if (D<0) return s<=0 && t<=0 && s+t>=D;
//    return s>=0 && t>=0 && s+t<=D;
//}

static Fixed cross(Point const vecA, Point const vecB)
{
	return vecA.getX() * vecB.getY() - vecA.getY() * vecB.getX();
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	//float d1 = (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
    //float d2 = (C.x - B.x) * (P.y - B.y) - (C.y - B.y) * (P.x - B.x);
    //float d3 = (A.x - C.x) * (P.y - C.y) - (A.y - C.y) * (P.x - C.x);

	Fixed d1 = cross(a - b, a - point);
    Fixed d2 = cross(b - c, b - point);
    Fixed d3 = cross(c - a, c - point);

    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    bool has_zero = (d1 == 0) || (d2 == 0) || (d3 == 0);

    if (has_zero)
        return (false);
    return !(has_neg && has_pos);
}
