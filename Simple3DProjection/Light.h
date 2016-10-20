/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#pragma once

#ifndef LIGHT_H
#define LIGHT_H

#include <GL/glut.h>
#include "Mesh.h"

class Light
{
	private:
		// Attributes
		GLfloat mPointSource[4];
		GLfloat mAmbient[4];
		GLfloat mDiffuse[4];
		GLfloat	mSpecular[4];
	public:
		// Constructor
		Light();
		Light(GLfloat pointSource[], GLfloat ambient[], GLfloat diffuse[], GLfloat specular[]);
		// Getter function
		const GLfloat* getPointSource();
		const GLfloat* getAmbient();
		const GLfloat* getDiffuse();
		const GLfloat* getSpecular();
		// Setter function
		void setPointSource(GLfloat pointSource[]);
		void setAmbient(GLfloat ambient[]);
		void setDiffuse(GLfloat diffuse[]);
		void setSpecular(GLfloat specular[]);
};

#endif