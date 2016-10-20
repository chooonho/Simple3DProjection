/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#include "Material.h"

// Constructor
Material::Material()
{
	mAmbient[0] = { 0.0f };
	mDiffuse[0] = { 0.0f };
	mSpecular[0] = { 0.0f };

	for (int i = 0; i < 4; i++)
	{
		if (i < 3)
		{
			mEmission[i] = 0.0f;
		}
		else
		{
			mEmission[i] = 1.0f;
		}
	}
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

	mEmission[4] = { 0.0f };
	mShine = shine;
}

// Getter function
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

const GLfloat* Material::getEmission()
{
	return mEmission;
}

GLfloat Material::getShine()
{
	return mShine;
}

// Setter function
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

void Material::setEmission(GLfloat emission[])
{
	for (int i = 0; i < 4; i++)
	{
		mEmission[i] = emission[i];
	}
}

void Material::setShine(GLfloat shine)
{
	mShine = shine;
}

// Overloaded assignment operator to allow direct assignment of object
Material& Material::operator=(const Material& rhMaterial)
{
	if (this != &rhMaterial)
	{
		for (int i = 0; i < 4; i++)
		{
			this->mAmbient[i] = rhMaterial.mAmbient[i];
			this->mDiffuse[i] = rhMaterial.mDiffuse[i];
			this->mSpecular[i] = rhMaterial.mSpecular[i];
			this->mEmission[i] = rhMaterial.mEmission[i];
		}

		this->mShine = rhMaterial.mShine;
	}

	return *this;
}