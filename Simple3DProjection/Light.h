#pragma once

#ifndef LIGHT_H
#define LIGHT_H

#include <GL/glut.h>
#include "Mesh.h"

class Light
{
	private:
		GLfloat mPointSource[4];
		GLfloat mAmbient[4];
		GLfloat mDiffuse[4];
		GLfloat	mSpecular[4];
	public:
		Light();
		Light(GLfloat pointSource[], GLfloat ambient[], GLfloat diffuse[], GLfloat specular[]);
		const GLfloat* getPointSource();
		const GLfloat* getAmbient();
		const GLfloat* getDiffuse();
		const GLfloat* getSpecular();
		void setPointSource(GLfloat pointSource[]);
		void setAmbient(GLfloat ambient[]);
		void setDiffuse(GLfloat diffuse[]);
		void setSpecular(GLfloat specular[]);
};

#endif