#pragma once

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <GL/glut.h>

class Transform
{
	private:
		double mX;
		double mY;
		double mZ;
	public:
		Transform();
		Transform(double, double, double);
		double getX();
		double getY();
		double getZ();
		void setX(double);
		void setY(double);
		void setZ(double);
		Transform& operator=(const Transform&);
};

#endif