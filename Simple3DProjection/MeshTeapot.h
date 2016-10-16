#pragma once

#ifndef MESH_TEAPOT_H
#define MESH_TEAPOT_H

#include "Mesh.h"

class MeshTeapot : public Mesh {
	private:
		GLdouble mSize;
	public:
		MeshTeapot();
		MeshTeapot(GLdouble size, ColorRGBA4D color, Transform translate, Rotate rotate, Transform transform, bool isWireFrame);
		GLdouble getSize();
		void setSize(GLdouble size);
		virtual void draw();
	};

#endif // MESH_TEAPOT_H
