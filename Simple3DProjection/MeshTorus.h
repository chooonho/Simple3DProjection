#pragma once

#ifndef MESH_TORUS_H
#define MESH_TORUS_H

#include "Mesh.h"

class MeshTorus : public Mesh {
	private:
		GLdouble mInnerRadius;
		GLdouble mOuterRadius;
		GLint mNSideCount;
		GLint mRingCount;
	public:
		MeshTorus();
		MeshTorus(GLdouble innerRadius, GLdouble outerRadius, GLint nSideCount, GLint ringCount, ColorRGBA4D color,
			Transform translate, Rotate rotate, Transform scale, bool isWireFrame);
		GLdouble getInnerRadius();
		GLdouble getOuterRadius();
		GLint getNSideCount();
		GLint getRingCount();
		void setInnerRadius(GLdouble innerRadius);
		void setOuterRadius(GLdouble outerRadius);
		void setNSideCount(GLint nSideCount);
		void setRingCount(GLint ringCount);
		virtual void draw();
};

#endif // MESH_CONE_H
