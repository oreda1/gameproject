#include "Geometry.h"

Vector2 Vector2::operator+(const Vector2& val) const
{
	return Vector2{ x + val.x,y + val.y };
}

Vector2 Vector2::operator-(const Vector2& val) const
{
	return Vector2{ x - val.x,y - val.y };
}

Vector2 Vector2::operator*(float scale) const
{
	return Vector2();
}

Vector2 Vector2::operator/(float div) const
{
	return Vector2{};
}

void Vector2::operator+=(const Vector2& val)
{
}

void Vector2::operator-=(const Vector2& val)
{
}

void Vector2::operator*=(float scale)
{
}

void Vector2::operator/=(float div)
{
}

float Vector2::Length() const
{
	return std::hypotf(x,y);
}

float Vector2::SQLength() const
{
	return x*x+y*y;
}

Vector2 Vector2::Normalize() const
{
	float len = Length();
	if (len == 0.0f)
	{
		return{ 0.0f,0.0f };

	}
	return{ x / len,y / len };

}

void Vector2::Normalize()
{
	float len = Length();
	if (len==0.0f)
	{
		return;

	}
	x /= len;
	y /= len;

}

float Dot(const Vector2& lval, const Vector2& rval)
{
	return lval.x*rval.x+lval.y*rval.y;
}
