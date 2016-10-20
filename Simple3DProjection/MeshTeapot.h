/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#pragma once

#ifndef MESH_TEAPOT_H
#define MESH_TEAPOT_H

#include "Mesh.h"

class MeshTeapot : public Mesh {
	private:
		// Attribute
		GLdouble mSize;
	public:
		// Constructor
		MeshTeapot();
		MeshTeapot(GLdouble size, ColorRGBA4D color, Transform translate, Rotate rotate, Transform transform, bool isWireFrame);
		// Getter function
		GLdouble getSize();
		// Setter function
		void setSize(GLdouble size);
		// Overriden virtual draw function
		virtual void draw();
	};

#endif // MESH_TEAPOT_H
