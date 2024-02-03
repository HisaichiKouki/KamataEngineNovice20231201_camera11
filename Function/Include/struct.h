#pragma once
#include <Vector2.h>

static int kWindowSizeX = 480;
static int kWindowSizeY = 960;
struct  intVector2
{
	int x;
	int y;
};

struct Vertex
{
	Vector2 leftTop;
	Vector2 rightTop;
	Vector2 leftBottom;
	Vector2 rightBottom;
};

struct Matrix3x3
{
	float m[3][3];
};

struct BallStruct
{
	Vector2 pos;
	Vector2 vel;
	Vector2 acc;

	float mass;
	float radius;
	unsigned int color;
};