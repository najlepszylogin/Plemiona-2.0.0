#pragma once
#ifndef VEC__
#define VEC__
#include <iostream>

class Vector2
{
public:
	enum MODE { kart, bieg };
private:
	
	MODE mode;
	void set_mag();
	void set_ang();
	void set_x();
	void set_y();
public:
	double x;
	double y;
	double ang;
	double mag;
	Vector2();
	Vector2(double a, double b, MODE mode = kart);
	void Reset(double a, double b, MODE mode = kart);
	~Vector2();
	double getX() const { return x; };
	double getY() const { return y; };
	double getMag() const { return mag; };
	double getAng() const { return ang; };
	void switchMode();
	Vector2 operator+(const Vector2& a) const;
	Vector2 operator-(const Vector2& a) const;
	Vector2 operator-() const;
	Vector2 operator*(double n)const;
	friend bool operator<(const Vector2& v1, const Vector2& v2);
	friend bool operator>(const Vector2& v1, const Vector2& v2);
	friend bool operator==(const Vector2& v1, const Vector2& v2);
	friend Vector2 operator*(double n, const Vector2& a);
	friend std::ostream& operator<<(std::ostream& os, const Vector2& a);


};

#endif VEC__