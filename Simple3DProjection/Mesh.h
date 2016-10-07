#pragma once

#ifndef MESH_H
#define MESH_H
#include "Transform.h"

struct ColorRGB3F {
	double red;
	double green;
	double blue;
};

class Mesh
{
	private:
		bool mIsWireFrame;
		Transform mTranslate;
		Transform mRotate;
		Transform mScale;
		ColorRGB3F mColor;
	public:
		Transform getTranslate() { return mTranslate; }
		double getTranslateX() { return mTranslate.getX(); }
		double getTranslateY() { return mTranslate.getY(); }
		double getTranslateZ() { return mTranslate.getZ(); }
		Transform getRotate() { return mRotate; }
		double getRotateX() { return mRotate.getX(); }
		double getRotateY() { return mRotate.getY(); }
		double getRotateZ() { return mRotate.getZ(); }
		Transform getScale() { return mScale; }
		double getScaleX() { return mScale.getX(); }
		double getScaleY() { return mScale.getY(); }
		double getScaleZ() { return mScale.getZ(); }
		ColorRGB3F getColor() { return mColor;  }
		double getColorR() { return mColor.red; }
		double getColorG() { return mColor.green; }
		double getColorB() { return mColor.blue; }
		void setTranslate(Transform translate) { mTranslate = translate; }
		void setTranslateX(double translateX) { mTranslate.setX(translateX); }
		void setTranslateY(double translateY) { mTranslate.setY(translateY); }
		void setTranslateZ(double translateZ) { mTranslate.setZ(translateZ); }
		void setRotate(Transform rotate) { mRotate = rotate; }
		void setRotateX(double rotateX) { mRotate.setX(rotateX); }
		void setRotateY(double rotateY) { mRotate.setY(rotateY); }
		void setRotateZ(double rotateZ) { mRotate.setZ(rotateZ); }
		void setScale(Transform scale) { mScale = scale; }
		void setSclaeX(double scaleX) { mScale.setX(scaleX); }
		void setScaleY(double scaleY) { mScale.setY(scaleY); }
		void setScaleZ(double scaleZ) { mScale.setZ(scaleZ); }
		void setColor(ColorRGB3F color) { mColor = color; }
		void setColorR(double red) { mColor.red = red; }
		void setColorG(double green) { mColor.green = green; }
		void setColorB(double blue) { mColor.blue = blue; }
		bool getIsWireFrame() { return mIsWireFrame; }
		void setIsWireFrame(bool isWireFrame) { mIsWireFrame = isWireFrame; }
		virtual void draw() = 0;
};

#endif
