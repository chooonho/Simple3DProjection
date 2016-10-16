#pragma once

#ifndef LIGHT_H
#define LIGHT_H

#include <GL/glut.h>

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
		void setPointSource(GLfloat pointSource[]);
		void setAmbient(GLfloat ambient[]);
		void setDiffuse(GLfloat diffuse[]);
		void setSpecular(GLfloat specular[]);
		void getPointSource(GLfloat pointSource[]);
		void getAmbient(GLfloat ambient[]);
		void getDiffuse(GLfloat diffuse[]);
		void getSpecular(GLfloat specular[]);
};

#endif