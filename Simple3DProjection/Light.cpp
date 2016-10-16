#include "Light.h"

Light::Light()
{
	mPointSource[4] = { 0.0 };
	mAmbient[4] = { 0.0 };
	mDiffuse[4] = { 0.0 };
	mSpecular[4] = { 0.0 };
}

Light::Light(GLfloat pointSource[], GLfloat ambient[], GLfloat diffuse[], GLfloat specular[], ColorRGBA4D color)
{
	for (int i = 0; i < 4; i++)
	{
		mPointSource[i] = pointSource[i];
		mAmbient[i] = ambient[i];
		mDiffuse[i] = diffuse[i];
		mSpecular[i] = specular[i];
	}
}

void Light::setPointSource(GLfloat pointSource[])
{
	for (int i = 0; i < 4; i++)
	{
		mPointSource[i] = pointSource[i];
	}
}

void Light::setAmbient(GLfloat ambient[])
{
	for (int i = 0; i < 4; i++)
	{
		mAmbient[i] = ambient[i];
	}
}

void Light::setDiffuse(GLfloat diffuse[])
{
	for (int i = 0; i < 4; i++)
	{
		mDiffuse[i] = diffuse[i];
	}
}

void Light::setSpecular(GLfloat specular[])
{
	for (int i = 0; i < 4; i++)
	{
		mSpecular[i] = specular[i];
	}
}

void Light::setColor(ColorRGBA4D color)
{
	mColor = color;
}

const GLfloat* Light::getPointSource()
{
	return mPointSource;
}

const GLfloat* Light::getAmbient()
{
	return mAmbient;
}

const GLfloat* Light::getDiffuse()
{
	return mDiffuse;
}

const GLfloat* Light::getSpecular()
{
	return mSpecular;
}

ColorRGBA4D Light::getColor()
{
	return mColor;
}