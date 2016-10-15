#pragma once

#ifndef ROTATE_H
#define ROTATE_H

#include <GL/glut.h>
#include "Transform.h"

class Rotate : public Transform
{
	private:
		GLdouble mAngle;
	public:
		Rotate();
		Rotate(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
		GLdouble getAngle();
		void setAngle(GLdouble angle);
		Rotate& operator=(const Rotate& rhRotate);
};

#endif
