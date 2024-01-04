#include <cmath>
#include <stdexcept>
#include "m_vec.h"

//Constructors:
m_vec::m_vec (float x, float y) : xComp{x}, yComp{y} {}

m_vec::~m_vec() = default;


////////////////////////
// assignment overloads
////////////////////////
m_vec &m_vec::operator=(const m_vec &v)
{
	this->xComp = v.xComp;
	this->yComp = v.yComp; 	
	return *this;
}

m_vec &m_vec::operator=(float s)
{
	this->xComp = s;
	this->yComp = s;
	return *this;
}

void m_vec::Set(float x, float y)
{
	this->xComp = x;
	this->yComp = y;
}


//////////////////////
//Multiply Overloads
//////////////////////
m_vec m_vec::operator*(const m_vec& v) const
{
   return m_vec{xComp * v.xComp, yComp * v.yComp};
}

m_vec &m_vec::operator*=(const m_vec& v) 
{
	xComp *= v.xComp;
	yComp *= v.yComp;
	return *this;
}

m_vec m_vec::operator*(const float s) const
{
	return m_vec{ (xComp*s), (yComp*s) }; 
}

m_vec &m_vec::operator*=(const float s)
{
	xComp *= s;
	yComp *= s;
	return *this;
}

///////////////////////
// Divide Overloads
////////////////////////
m_vec m_vec::operator/(const m_vec& v) const
{
	//Double check for 0
	if (v.xComp == 0 || v.yComp == 0)
	{
		throw std::invalid_argument("Vector is Zero on divide!\n");
	}
	return m_vec{ (xComp / v.xComp), (yComp / v.yComp) };
}

m_vec &m_vec::operator/=(const m_vec& v)  
{
	//Double check for 0
	if (v.xComp == 0 || v.yComp == 0)
	{
		throw std::invalid_argument("Vector is Zero on divide!\n");
	}

	xComp /= v.xComp;
	yComp /= v.yComp;
	return *this;
}

m_vec m_vec::operator/(const float s) const
{
	//Double check for 0
	if (s == 0)
	{
		throw std::invalid_argument("Vector is Zero on divide!\n");
	}
	return m_vec{ (xComp/s), (yComp/s) };
}

m_vec &m_vec::operator/=(const float s)
{
	//Double check for 0
	if (s == 0)
	{
		throw std::invalid_argument("Vector is Zero on divide!\n");
	}
	xComp /= s;
	yComp /= s;
	return *this;
}

////////////////////
// add Overloads
////////////////////
m_vec m_vec::operator+(const m_vec& v) const
{
   return m_vec{ (xComp + v.xComp), (yComp + v.yComp) };
}

m_vec &m_vec::operator+=(const m_vec& v)  
{
	xComp += v.xComp;
	yComp += v.yComp;
	return *this;
}

m_vec m_vec::operator+(const float s) const
{
	return m_vec{ (xComp+s), (yComp+s) };
}

m_vec &m_vec::operator+=(const float s)
{
	xComp += s;
	yComp += s;
	return *this;
}


////////////////////////
// subtract Overloads
///////////////////////
m_vec m_vec::operator-(const m_vec& v) const
{
   return m_vec{ (xComp - v.xComp), (yComp - v.yComp) };
}

m_vec &m_vec::operator-=(const m_vec& v)  
{
	xComp -= v.xComp;
	yComp -= v.yComp;
	return *this;
}

m_vec m_vec::operator-(const float s) const
{
	return m_vec{ (xComp-s), (yComp-s) };
}

m_vec &m_vec::operator-=(const float s)
{
	xComp -= s;
	yComp -= s;
	return *this;
}

/////////////////////////
//Logical Overloads
/////////////////////////
//Equality
bool m_vec::operator==(const m_vec &v) const 
{
    return xComp == v.xComp && yComp == v.yComp;
}
//Inequality
bool m_vec::operator!=(const m_vec &v) const 
{
    return !(xComp == v.xComp && yComp == v.yComp);
}

//////////////////////////
//Vector Functions
//////////////////////////

//Magnitude - Returns the magnitude of this vector
float m_vec::Magnitude()
{
	return sqrt((xComp*xComp) + (yComp*yComp));
}

//Normalize - Normalizes and returns this vector
m_vec& m_vec::Normalize()
{
	float mag = Magnitude();
	if (mag > 0){
		Set(xComp/mag, yComp/mag);
	}
	return *this;
}

//Limit - Limits the current vector have a magnitude no greater than limit 
m_vec& m_vec::Limit(float limit)
{
	float mag = Magnitude();
	if(mag > limit)
	{
		xComp *= limit/mag;
		yComp *= limit/mag;
	}
	return *this;
}

//Distance - Returns the Distance between two vectors
float m_vec::Distance( m_vec v)
{
	float d_x = xComp - v.xComp;
	float d_y = yComp - v.yComp;
	return sqrt((d_x*d_x) + (d_y*d_y));
}




