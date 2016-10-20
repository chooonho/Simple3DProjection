/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#pragma once

#ifndef MESH_TORUS_H
#define MESH_TORUS_H

#include "Mesh.h"

class MeshTorus : public Mesh {
	private:
		// Attributes
		GLdouble mInnerRadius;
		GLdouble mOuterRadius;
		GLint mNSideCount;
		GLint mRingCount;
	public:
		// Constructor
		MeshTorus();
		MeshTorus(GLdouble innerRadius, GLdouble outerRadius, GLint nSideCount, GLint ringCount, ColorRGBA4D color,
			Transform translate, Rotate rotate, Transform scale, bool isWireFrame);
		// Getter function
		GLdouble getInnerRadius();
		GLdouble getOuterRadius();
		GLint getNSideCount();
		GLint getRingCount();
		// Setter function
		void setInnerRadius(GLdouble innerRadius);
		void setOuterRadius(GLdouble outerRadius);
		void setNSideCount(GLint nSideCount);
		void setRingCount(GLint ringCount);
		// Overriden virtual draw function
		virtual void draw();
};

#endif // MESH_CONE_H
