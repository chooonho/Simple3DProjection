/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#pragma once

#ifndef MESH_CUBE_H
#define MESH_CUBE_H

#include "Mesh.h"

class MeshCube : public Mesh {
	private:
		// Attribute
		GLdouble mSize;
	public:
		// Constructor
		MeshCube();
		MeshCube(GLdouble size, ColorRGBA4D color, Transform translate, Rotate rotate, Transform scale, bool isWireFrame);
		// Getter function
		GLdouble getSize();
		// Setter function
		void setSize(GLdouble size);
		// Overriden virtual draw function
		virtual void draw();
};

#endif // MESH_CUBE_H