#include "Vector2.h"

using namespace std;


const double RadToDeg = 45.0 / atan(1.);
void Vector2::set_mag()
{
	mag = sqrt(x * x + y * y);
}
void Vector2::set_ang()
{
	if (x == 0. && y == 0.)
		ang = 0.0;
	else
		ang = atan2(y, x);
}
void Vector2::set_x()
{
	x = mag * cos(ang);
}
void Vector2::set_y()
{
	y = mag * sin(ang);
}
Vector2::Vector2()
{
	x = y = mag = ang = 0.;
	mode = kart;
}
Vector2::Vector2(double a, double b, MODE form)
{
	mode = form;
	if (form == kart)
	{
		x = a;
		y = b;
		set_mag();
		set_ang();
	}
	else if (form == bieg)
	{
		mag = a;
		ang = b / RadToDeg;
		set_x();
		set_y();

	}
	else
	{
		cout << "Niepoprawna wartosc trzeciego argumentu Vector2() -- ";
		cout << "zeruje wartosc\n";
		x = y = mag = ang = 0.;
		mode = kart;
	}
}
void Vector2::Reset(double a, double b, MODE form)
{
	mode = form;
	if (form == kart)
	{
		x = a;
		y = b;
		set_mag();
		set_ang();
	}
	else if (form == bieg)
	{
		mag = a;
		ang = b / RadToDeg;
		set_x();
		set_y();

	}
	else
	{
		cout << "Niepoprawna wartosc trzeciego argumentu Vector2() -- ";
		cout << "zeruje wartosc\n";
		x = y = mag = ang = 0.;
		mode = kart;
	}
}
Vector2::~Vector2()
{
}
void Vector2::switchMode()
{
	if (mode == kart)
	{
		mode = bieg;
		cout << "Zmieniono tryb wektora na biegunowy/n";
	}
	else
	{
		mode = kart;
		cout << "Zmieniono tryb wektora na kartezjañski/n";
	}
}
Vector2 Vector2::operator+(const Vector2 & a)const
{
	return Vector2(x + a.x, y + a.y);
}
Vector2 Vector2::operator-(const Vector2 & a)const
{
	return Vector2(x - a.x, y - a.y);
}
Vector2 Vector2::operator-() const
{
	return Vector2(-x, -y);
}
Vector2 Vector2::operator*(double n)const
{
	return Vector2(n * x, n * y);
}
Vector2 operator*(double n, const Vector2 & a)
{
	return a * n;
}
std::ostream& operator<<(std::ostream & os, const Vector2 & a)
{
	if (a.mode == Vector2::kart)
		os << "(x, y) = (" << a.x << ", " << a.y << ")";
	else if (a.mode == Vector2::bieg)
	{
		os << "(m, a) = (" << a.mag << ", " << a.ang * RadToDeg << ")";
	}
	else
		os << "Niepoprawny tryb reprezentacji obiektu wektora";
	return os;
}

bool operator<(const Vector2& v1, const Vector2& v2)
{
	if ((v1.x < v2.x && v1.y <= v2.y) || (v1.x <= v2.x && v1.y < v2.y))return true;
	else return false;
}
bool operator>(const Vector2& v1, const Vector2& v2)
{
	return(v2 < v1);
}
bool operator==(const Vector2& v1, const Vector2& v2)
{
	if (v1.x == v2.x && v1.y == v2.y)return true;
	else
		return false;
}