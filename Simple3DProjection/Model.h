/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#pragma once

#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "Transform.h"
#include "Mesh.h"

class Model
{
	private:
		// Attribute
		Transform mTranslate;
		Rotate mRotate;
		Rotate mAnimateRotate;
		Transform mScale;
		std::vector<Mesh*> mMeshes;
	public:
		// Constructor
		Model();
		Model(Transform translate, Rotate rotate, Transform scale, std::vector<Mesh*> meshes);
		// Destructor
		~Model();
		// Getter function
		Transform getTranslate();
		GLdouble getTranslateX();
		GLdouble getTranslateY();
		GLdouble getTranslateZ();
		Rotate getRotate();
		GLdouble getRotateAngle();
		GLdouble getRotateX();
		GLdouble getRotateY();
		GLdouble getRotateZ();
		Rotate getAnimateRotate();
		GLdouble getAnimateRotateAngle();
		GLdouble getAnimateRotateX();
		GLdouble getAnimateRotateY();
		GLdouble getAnimateRotateZ();
		Transform getScale();
		GLdouble getScaleX();
		GLdouble getScaleY();
		GLdouble getScaleZ();
		// Setter function
		void setTranslate(Transform translate);
		void setTranslateX(GLdouble translateX);
		void setTranslateY(GLdouble translateY);
		void setTranslateZ(GLdouble translateZ);
		void setRotate(Rotate rotate);
		void setRotateAngle(GLdouble rotateAngle);
		void setRotateX(GLdouble rotateX);
		void setRotateY(GLdouble rotateY);
		void setRotateZ(GLdouble rotateZ);
		void setAnimateRotate(Rotate rotate);
		void setAnimateRotateAngle(GLdouble rotateAngle);
		void setAnimateRotateX(GLdouble rotateX);
		void setAnimateRotateY(GLdouble rotateY);
		void setAnimateRotateZ(GLdouble rotateZ);
		void setScale(Transform scale);
		void setScaleX(GLdouble scaleX);
		void setScaleY(GLdouble scaleY);
		void setScaleZ(GLdouble scaleZ);
		void setMeshes(std::vector<Mesh*> meshes);
		void setIsWireFrame(bool isWireFrame);
		// Function that adds mesh to the model
		void addMesh(Mesh* mesh);
		// Function that removes all the mesh from the model
		void clearMesh();
		// Function that render the model
		void draw();
};

#endif