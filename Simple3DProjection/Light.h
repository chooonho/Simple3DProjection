#pragma once

#ifndef LIGHT_H
#define LIGHT_H

#include <GL/glut.h>
#include "Mesh.h"

class Light
{
	private:
		ColorRGBA4D mColor;
		GLfloat mPointSource[4];
		GLfloat mAmbient[4];
		GLfloat mDiffuse[4];
		GLfloat	mSpecular[4];
	public:
		Light();
		Light(GLfloat pointSource[], GLfloat ambient[], GLfloat diffuse[], GLfloat specular[], ColorRGBA4D color);
		const GLfloat* getPointSource();
		const GLfloat* getAmbient();
		const GLfloat* getDiffuse();
		const GLfloat* getSpecular();
		ColorRGBA4D getColor();
		void setPointSource(GLfloat pointSource[]);
		void setAmbient(GLfloat ambient[]);
		void setDiffuse(GLfloat diffuse[]);
		void setSpecular(GLfloat specular[]);
		void setColor(ColorRGBA4D color);
};

#endif