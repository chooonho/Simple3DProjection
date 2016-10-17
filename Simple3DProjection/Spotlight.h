#pragma once

#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H

#include "Light.h"

class Spotlight : public Light
{
	private:
		GLfloat mDirection[3];
		GLfloat mCutOff;
		GLfloat mExponent;
	public:
		Spotlight();
		Spotlight(GLfloat pointSource[], GLfloat ambient[], GLfloat diffuse[], GLfloat specular[],
					GLfloat direction[], GLfloat cutOff, GLfloat exponent);
		const GLfloat* getDirection();
		GLfloat getCutOff();
		GLfloat getExponent();
		void setDirection(GLfloat direction[]);
		void setCutOff(GLfloat cutOff);
		void setExponent(GLfloat exponent);
};

#endif