#pragma once

#ifndef MESH_REGULAR_H
#define MESH_REGULAR_H

#include "Mesh.h"

enum RegularType
{
	DODECAHEDRON,
	OCTAHEDRON,
	TETRAHEDRON,
	ICOSAHEDRON
};

class MeshRegular : public Mesh
{
	public:
		MeshRegular(RegularType regularType);
		MeshRegular(RegularType regularType, ColorRGBA4D color, bool isWireFrame);
		RegularType getRegularType();
		void setRegularType(RegularType regularType);
		virtual void draw();
	private:
		RegularType mRegularType;
};

#endif