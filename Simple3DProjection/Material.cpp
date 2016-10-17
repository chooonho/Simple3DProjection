#include "Material.h"

Material::Material()
{
	mAmbient[4] = { 0.0f };
	mDiffuse[4] = { 0.0f };
	mSpecular[4] = { 0.0f };
	mShine = 0.0f;
}

Material::Material( GLfloat ambient[], GLfloat diffuse[], GLfloat specular[], GLfloat shine)
{
	for (int i = 0; i < 4; i++)
	{
		mAmbient[i] = ambient[i];
		mDiffuse[i] = diffuse[i];
		mSpecular[i] = specular[i];
	}

	mShine = shine;
}

const GLfloat* Material::getAmbient()
{
	return mAmbient;
}

const GLfloat* Material::getDiffuse()
{
	return mDiffuse;
}

const GLfloat* Material::getSpecular()
{
	return mSpecular;
}

GLfloat Material::getShine()
{
	return mShine;
}

void Material::setAmbient(GLfloat ambient[])
{
	for (int i = 0; i < 4; i++)
	{
		mAmbient[i] = ambient[i];
	}
}

void Material::setDiffuse(GLfloat diffuse[])
{
	for (int i = 0; i < 4; i++)
	{
		mDiffuse[i] = diffuse[i];
	}
}

void Material::setSpecular(GLfloat specular[])
{
	for (int i = 0; i < 4; i++)
	{
		mSpecular[i] = specular[i];
	}
}

void Material::setShine(GLfloat shine)
{
	mShine = shine;
}