#pragma once
#include "./Function/Include/struct.h"
#include "./Camera/Include/Camera.h"
class Ball
{
private:
	BallStruct ball;
	bool onAirResistance;

	Matrix3x3 worldMatrix_;
	Matrix3x3 wvpVpMatrix_;

	Vector2 screenPos;
	Vector2 airResistance;
	Vector2 airResistanceAcceleration;
	float k;

	
public:

	static int ballCount;

	Ball();
	~Ball();

	void Init();
	void Update();
	void Draw(Camera*camera_);
	void Debug(Vector2 pos);

	void SetPos(Vector2 setPos) { ball.pos = setPos; }
	void SetAirResist(bool set) { onAirResistance = set; }

};

