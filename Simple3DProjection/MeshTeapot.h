#pragma once

#ifndef MESH_TEAPOT_H
#define MESH_TEAPOT_H

#include "Mesh.h"

class MeshTeapot : public Mesh {
	private:
		GLdouble mSize;
	public:
		MeshTeapot();
		MeshTeapot(GLdouble, ColorRGB3F, Transform, Rotate, Transform, bool);
		GLdouble getSize();
		void setSize(GLdouble);
		virtual void draw();
	};

#endif // MESH_TEAPOT_H
