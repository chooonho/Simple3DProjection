/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#pragma once

#ifndef MESH_SPHERE_H
#define MESH_SPHERE_H

#include "Mesh.h"

class MeshSphere : public Mesh {
	private:
		// Attributes
		GLdouble mRadius;
		GLint mSliceCount;
		GLint mStackCount;
	public:
		// Constructor
		MeshSphere();
		MeshSphere(GLdouble radius, GLint sliceCount, GLint stackCount, ColorRGBA4D color,
						Transform translate, Rotate rotate, Transform scale, bool isWireFrame);
		// Getter function
		GLdouble getRadius();
		GLint getSliceCount();
		GLint getStackCount();
		// Setter function
		void setRadius(GLdouble radius);
		void setSliceCount(GLint sliceCount);
		void setStackCount(GLint stackCount);
		// Overriden virtual draw function
		virtual void draw();
};

#endif // MESH_SPHERE_H