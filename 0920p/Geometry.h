#pragma once

struct Vector2
{
	float x;
	float y;
	Vector2 operator+(const Vector2& val)const;
	Vector2 operator-(const Vector2& val)const;
	Vector2 operator*(float scale)const;
	Vector2 operator/(float div)const;
	void operator+= (const Vector2 & val);
	void operator-= (const Vector2 & val);
	void operator*= (float scale);
	void operator/= (float div);
	/// <summary>
	/// �x�N�g���̑傫����Ԃ�
	/// </summary>
	/// <returns></returns>
	float Length()const;
	/// <summary>
	/// �x�N�g���̑傫����2���Ԃ�
	/// </summary>
	/// <returns></returns>
	float SQLength()const;
	/// <summary>
	/// ���K���ς݂̃x�N�g��
	/// </summary>
	Vector2 Normalize()const;
	void Normalize();

	
	

};
/// <summary>
///���ς�Ԃ�
/// </summary>
/// <param name="lval"></param>
/// <param name="rval"></param>
/// <returns></returns>
float
Dot(const Vector2& lval, const Vector2& rval);

//Vector2�̕ʖ���Position2(���W)
using Position2 = Vector2;

