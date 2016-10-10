#pragma once

#ifndef ROTATE_H
#define ROTATE_H

#include "Transform.h"

class Rotate : public Transform
{
	private:
		GLdouble mAngle;
	public:
		Rotate();
		Rotate(GLdouble, GLdouble, GLdouble, GLdouble);
		GLdouble getAngle();
		void setAngle(GLdouble);
};

#endif
