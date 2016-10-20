/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#pragma once

#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H

#include "Light.h"

class Spotlight : public Light
{
	private:
		// Attributes
		GLfloat mDirection[3];
		GLfloat mCutOff;
		GLfloat mExponent;
	public:
		// Constructor
		Spotlight();
		Spotlight(GLfloat pointSource[], GLfloat ambient[], GLfloat diffuse[], GLfloat specular[],
					GLfloat direction[], GLfloat cutOff, GLfloat exponent);
		// Getter function
		const GLfloat* getDirection();
		GLfloat getCutOff();
		GLfloat getExponent();
		// Setter function
		void setDirection(GLfloat direction[]);
		void setCutOff(GLfloat cutOff);
		void setExponent(GLfloat exponent);
};

#endif