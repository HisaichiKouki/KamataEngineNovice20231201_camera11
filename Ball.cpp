#include "Ball.h"

Ball::Ball()
{
	Init();
	ballCount++;
}

Ball::~Ball()
{
	ballCount--;
}

void Ball::Init()
{
	ball.pos = {160,960};
	ball.vel = {};
	ball.acc = {0,-9.8f};
	ball.mass = 1.0f;
	ball.radius = 10.0f;
	ball.color = WHITE;
	screenPos = {};

	onAirResistance = true;
	airResistance = {};
	airResistanceAcceleration = {};

	k = 0.6f;
}

void Ball::Update()
{
	if (onAirResistance)
	{
		airResistance = { k * -ball.vel.x,k * -ball.vel.y };
		airResistanceAcceleration = { airResistance.x / ball.mass ,
		 airResistance.y / ball.mass };

		ball.acc.y = -9.8f + airResistanceAcceleration.y;
	}
	ball.vel.y += ball.acc.y/60;
	ball.pos.y += ball.vel.y/60;
}

void Ball::Draw(Camera *camera_)
{
	worldMatrix_ = MaketranslateMatrix(ball.pos);


	wvpVpMatrix_ = Multiply(worldMatrix_, camera_->GetViewMatrix());
	wvpVpMatrix_ = Multiply(wvpVpMatrix_, camera_->GetOrthMatrix());
	wvpVpMatrix_ = Multiply(wvpVpMatrix_, camera_->GetViewportMatrix());

	screenPos = Transform(ball.pos, wvpVpMatrix_);

	Novice::DrawEllipse(int(screenPos.x), int(screenPos.y), int(ball.radius), int(ball.radius), 0, ball.color, kFillModeSolid);

	
	

}

void Ball::Debug(Vector2 pos)
{
	
		Novice::ScreenPrintf(int(pos.x)+0, int(pos.y) + 0 , "screenPos x=%f y=%f ", screenPos.x, screenPos.y);
		Novice::ScreenPrintf(int(pos.x) + 0, int(pos.y) + 20 , "vel x=%f y=%f ", ball.vel.x, ball.vel.y);
		Novice::ScreenPrintf(int(pos.x) + 0, int(pos.y) + 40 , "worldPos x=%f y=%f ", ball.pos.x, ball.pos.y);

	
}
