/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#pragma once

#ifndef MESH_CONE_H
#define MESH_CONE_H

#include "Mesh.h"

class MeshCone : public Mesh {
	private:
		// Attributes
		GLdouble mBase;
		GLdouble mHeight;
		GLint mSliceCount;
		GLint mStackCount;
	public:
		// Constructor
		MeshCone();
		MeshCone(GLdouble base, GLdouble height, GLint sliceCount, GLint stackCount, ColorRGBA4D color,
					Transform translate,Rotate rotate, Transform scale, bool isWireFrame);
		// Getter function
		GLdouble getBase();
		GLdouble getHeight();
		GLint getSliceCount();
		GLint getStackCount();
		// Setter function
		void setBase(GLdouble base);
		void setHeight(GLdouble height);
		void setSliceCount(GLint sliceCount);
		void setStackCount(GLint stackCount);
		// Overriden virtual function
		virtual void draw();
};

#endif // MESH_CONE_H
