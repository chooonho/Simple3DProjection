#pragma once

#ifndef MESH_H
#define MESH_H
#include <GL/glut.h>
#include "Transform.h"
#include "Rotate.h"

struct ColorRGBA4D
{
	double red;
	double green;
	double blue;
	double alpha;
};

class Mesh
{
	private:
		bool mIsWireFrame;
		Transform mTranslate;
		Rotate mRotate;
		Transform mScale;
		ColorRGBA4D mColor;
	public:
		Mesh() { mScale.setX(1.0); mScale.setY(1.0); mScale.setZ(1.0); }
		Transform getTranslate() { return mTranslate; }
		GLdouble getTranslateX() { return mTranslate.getX(); }
		GLdouble getTranslateY() { return mTranslate.getY(); }
		GLdouble getTranslateZ() { return mTranslate.getZ(); }
		Rotate getRotate() { return mRotate; }
		GLdouble getRotateAngle() { return mRotate.getAngle(); }
		GLdouble getRotateX() { return mRotate.getX(); }
		GLdouble getRotateY() { return mRotate.getY(); }
		GLdouble getRotateZ() { return mRotate.getZ(); }
		Transform getScale() { return mScale; }
		GLdouble getScaleX() { return mScale.getX(); }
		GLdouble getScaleY() { return mScale.getY(); }
		GLdouble getScaleZ() { return mScale.getZ(); }
		ColorRGBA4D getColor() { return mColor;  }
		double getColorR() { return mColor.red; }
		double getColorG() { return mColor.green; }
		double getColorB() { return mColor.blue; }
		void setTranslate(Transform translate) { mTranslate = translate; }
		void setTranslateX(GLdouble translateX) { mTranslate.setX(translateX); }
		void setTranslateY(GLdouble translateY) { mTranslate.setY(translateY); }
		void setTranslateZ(GLdouble translateZ) { mTranslate.setZ(translateZ); }
		void setRotate(Rotate rotate) { mRotate = rotate; }
		void setRotateAngle(GLdouble angle) { mRotate.setAngle(angle); }
		void setRotateX(GLdouble rotateX) { mRotate.setX(rotateX); }
		void setRotateY(GLdouble rotateY) { mRotate.setY(rotateY); }
		void setRotateZ(GLdouble rotateZ) { mRotate.setZ(rotateZ); }
		void setScale(Transform scale) { mScale = scale; }
		void setScaleX(GLdouble scaleX) { mScale.setX(scaleX); }
		void setScaleY(GLdouble scaleY) { mScale.setY(scaleY); }
		void setScaleZ(GLdouble scaleZ) { mScale.setZ(scaleZ); }
		void setColor(ColorRGBA4D color) { mColor = color; }
		void setColorR(double red) { mColor.red = red; }
		void setColorG(double green) { mColor.green = green; }
		void setColorB(double blue) { mColor.blue = blue; }
		void setColorA(double alpha) { mColor.alpha = alpha; }
		bool getIsWireFrame() { return mIsWireFrame; }
		void setIsWireFrame(bool isWireFrame) { mIsWireFrame = isWireFrame; }
		virtual void draw() = 0;
};

#endif
