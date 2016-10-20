/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#pragma once

#ifndef MATERIAL_H
#define MATERIAL_H

#include<GL/glut.h>

class Material
{
	private:
		// Attributes
		GLfloat mAmbient[4];
		GLfloat mDiffuse[4];
		GLfloat	mSpecular[4];
		GLfloat mEmission[4];
		GLfloat mShine;
	public:
		// Constructor
		Material();
		Material(GLfloat ambient[], GLfloat diffuse[], GLfloat specular[], GLfloat shine);
		// Getter function
		const GLfloat* getAmbient();
		const GLfloat* getDiffuse();
		const GLfloat* getSpecular();
		const GLfloat* getEmission();
		GLfloat getShine();
		// Setter function
		void setAmbient(GLfloat ambient[]);
		void setDiffuse(GLfloat diffuse[]);
		void setSpecular(GLfloat specular[]);
		void setEmission(GLfloat emission[]);
		void setShine(GLfloat shine);
		// Overloaded assigment operator to allow direct assignment of the same object type
		Material& operator=(const Material& rhMaterial);
};

#endif