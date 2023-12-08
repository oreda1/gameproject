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
	/// ベクトルの大きさを返す
	/// </summary>
	/// <returns></returns>
	float Length()const;
	/// <summary>
	/// ベクトルの大きさの2乗を返す
	/// </summary>
	/// <returns></returns>
	float SQLength()const;
	/// <summary>
	/// 正規化済みのベクトル
	/// </summary>
	Vector2 Normalize()const;
	void Normalize();

	
	

};
/// <summary>
///内積を返す
/// </summary>
/// <param name="lval"></param>
/// <param name="rval"></param>
/// <returns></returns>
float
Dot(const Vector2& lval, const Vector2& rval);

//Vector2の別名でPosition2(座標)
using Position2 = Vector2;

