#include "Vector3f.h"

Vector3f::Vector3f(float x, float y, float z)
{
	this->vertices[0] = x;
	this->vertices[1] = y;
	this->vertices[2] = z;
}

Vector3f::~Vector3f()
{
}

float Vector3f::x()
{
	return this->vertices[0];
}

float Vector3f::y()
{
	return this->vertices[1];
}

float Vector3f::z()
{
	return this->vertices[2];
}