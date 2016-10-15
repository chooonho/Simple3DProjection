#pragma once

#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "Transform.h"
#include "Mesh.h"

class Model
{
	private:
		Transform mTranslate;
		Rotate mRotate;
		Transform mScale;
		std::vector<Mesh*> mMeshes;
	public:
		Model();
		Model(Transform translate, Rotate rotate, Transform scale, std::vector<Mesh*> meshes);
		~Model();
		Transform getTranslate();
		GLdouble getTranslateX();
		GLdouble getTranslateY();
		GLdouble getTranslateZ();
		Rotate getRotate();
		GLdouble getRotateAngle();
		GLdouble getRotateX();
		GLdouble getRotateY();
		GLdouble getRotateZ();
		Transform getScale();
		GLdouble getScaleX();
		GLdouble getScaleY();
		GLdouble getScaleZ();
		void setTranslate(Transform translate);
		void setTranslateX(GLdouble translateX);
		void setTranslateY(GLdouble translateY);
		void setTranslateZ(GLdouble translateZ);
		void setRotate(Rotate rotate);
		void setRotateAngle(GLdouble rotateAngle);
		void setRotateX(GLdouble rotateX);
		void setRotateY(GLdouble rotateY);
		void setRotateZ(GLdouble rotateZ);
		void setScale(Transform scale);
		void setScaleX(GLdouble scaleX);
		void setScaleY(GLdouble scaleY);
		void setScaleZ(GLdouble scaleZ);
		void setMeshes(std::vector<Mesh*> meshes);
		void setIsWireFrame(bool isWireFrame);
		void addMesh(Mesh* mesh);
		void clearMesh();
		void draw();
};

#endif