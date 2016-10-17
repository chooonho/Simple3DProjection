#include "Light.h"

Light::Light()
{
	mPointSource[4] = { 0.0f };
	mAmbient[4] = { 0.0f };
	mDiffuse[4] = { 0.0f };
	mSpecular[4] = { 0.0f };
}

Light::Light(GLfloat pointSource[], GLfloat ambient[], GLfloat diffuse[], GLfloat specular[])
{
	for (int i = 0; i < 4; i++)
	{
		mPointSource[i] = pointSource[i];
		mAmbient[i] = ambient[i];
		mDiffuse[i] = diffuse[i];
		mSpecular[i] = specular[i];
	}
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