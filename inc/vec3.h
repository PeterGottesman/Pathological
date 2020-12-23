#pragma once

#include <cmath>
#include <ostream>

struct Vec3
{
	// NOTE: This struct is copied directly into the output, if this
	// is modified to be larger than 12 bytes, the pixels array in
	// camera will need to be changed 
	union {
		struct {float x,y,z;};
		struct {float r,g,b;};
	};

	Vec3() {x=y=z = 0;}
	Vec3(float i) {x=y=z = i;}
	Vec3(float i, float j, float k) {x=i; y=j; z= k;}
	Vec3(const Vec3 &cp) {x=cp.x; y=cp.y; z=cp.z;}

	// Operators

	friend std::ostream& operator<<(std::ostream &s, const Vec3 &v)
	{
		return s << "<" << v.x << " " << v.y << " " << v.z << ">";
	}

	bool operator==(const Vec3 &v) const
	{
		return (x==v.x) & (y==v.y) & (z==v.z);
	}

	Vec3 operator/(float a) const
	{
		return Vec3(this->x/a, this->y/a, this->z/a);
	}

	Vec3 operator*(const Vec3 &a) const
	{
		return Vec3(this->x*a.x, this->y*a.y, this->z*a.z);
	}

	Vec3 operator*(float a) const
	{
		return Vec3(this->x*a, this->y*a, this->z*a);
	}

	friend Vec3 operator*(float a, const Vec3 &b)
	{
		return b * a;
	}

	Vec3 operator-(const Vec3 &a) const
	{
		return Vec3(this->x-a.x, this->y-a.y, this->z-a.z);
	}

	Vec3 operator+(const Vec3 &a) const
	{
		return Vec3(this->x+a.x, this->y+a.y, this->z+a.z);
	}

	Vec3 operator-=(const Vec3 &a)
	{
		return (*this = *this - a);
	}

	Vec3 operator+=(const Vec3 &a)
	{
		return (*this = *this + a);
	}

	Vec3 operator*=(const Vec3 &a)
	{
		return (*this = *this * a);
	}

	Vec3 operator*=(const float &a)
	{
		return (*this = *this * a);
	}

	Vec3 operator/=(const float &a)
	{
		return (*this = *this / a);
	}

	// Static Vector methods
	static float dot(const Vec3 &a, const Vec3 &b)
	{
		return a.x*b.x + a.y*b.y + a.z*b.z;
	}

	static Vec3 cross(const Vec3 &a, const Vec3 &b)
	{
		return Vec3(
			a.y*b.z - a.z*b.y,
			a.z*b.x - a.x*b.z,
			a.x*b.y - a.y*b.x
			);
	}

	static float squared_magnitude(const Vec3 &a)
	{
		return a.x*a.x + a.y*a.y + a.z*a.z;
	}

	static float magnitude(const Vec3 &a)
	{
		return sqrt(squared_magnitude(a));
	}

	static Vec3 normalize(const Vec3 &a)
	{
		float mag = magnitude(a);
		return a/mag;
	}

	static Vec3 sp2cart(float rad, float theta, float phi)
	{
		return rad * Vec3(
			sin(phi) * cos(theta),
			sin(phi) * sin(theta),
			cos(phi)
			);
	}

	static Vec3 reflect(const Vec3 &norm, const Vec3 &wi)
	{
		return wi - 2.0 * norm * Vec3::dot(norm, wi);
	}

};

using Color = Vec3;
