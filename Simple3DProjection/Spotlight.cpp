/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#include "Spotlight.h"

// Constructor
Spotlight::Spotlight()
{
	mDirection[0] = { 0.0f };
	mCutOff = 0.0;
	mExponent = 0.0;
}

Spotlight::Spotlight(GLfloat pointSource[], GLfloat ambient[], GLfloat diffuse[], GLfloat specular[],
	GLfloat direction[], GLfloat cutOff, GLfloat exponent) : Light(pointSource, ambient, diffuse, specular)
{
	for (int i = 0; i < 3; i++)
	{
		mDirection[i] = direction[i];
	}

	mCutOff = cutOff;
	mExponent = exponent;
}

// Getter function
const GLfloat* Spotlight::getDirection()
{
	return mDirection;
}

GLfloat Spotlight::getCutOff()
{
	return mCutOff;
}

GLfloat Spotlight::getExponent()
{
	return mExponent;
}

// Setter function
void Spotlight::setDirection(GLfloat direction[])
{
	for (int i = 0; i < 3; i++)
	{
		mDirection[i] = direction[i];
	}
}

void Spotlight::setCutOff(GLfloat cutOff)
{
	mCutOff = cutOff;
}

void Spotlight::setExponent(GLfloat exponent)
{
	mExponent = exponent;
}