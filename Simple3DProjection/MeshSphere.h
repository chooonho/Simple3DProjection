#pragma once

#ifndef MESH_SPHERE_H
#define MESH_SPHERE_H

#include "Mesh.h"

class MeshSphere : public Mesh {
	private:
		GLdouble mRadius;
		GLint mSliceCount;
		GLint mStackCount;
	public:
		MeshSphere();
		MeshSphere(GLdouble radius, GLint sliceCount, GLint stackCount, ColorRGBA4D color,
						Transform translate, Rotate rotate, Transform scale, bool isWireFrame);
		GLdouble getRadius();
		GLint getSliceCount();
		GLint getStackCount();
		void setRadius(GLdouble radius);
		void setSliceCount(GLint sliceCount);
		void setStackCount(GLint stackCount);
		virtual void draw();
};

#endif // MESH_SPHERE_H