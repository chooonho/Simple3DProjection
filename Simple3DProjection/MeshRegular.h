/*******************************************************************************
*	Author				: OOI CHOON HO
*	Date				: 20/10/2016
*******************************************************************************/

#pragma once

#ifndef MESH_REGULAR_H
#define MESH_REGULAR_H

#include "Mesh.h"

// Enumeration which specifies the types of regular polygon available
enum RegularType
{
	DODECAHEDRON,
	OCTAHEDRON,
	TETRAHEDRON,
	ICOSAHEDRON
};

class MeshRegular : public Mesh
{
	private:
		// Attribute
		RegularType mRegularType;
	public:
		// Constructor
		MeshRegular(RegularType regularType);
		MeshRegular(RegularType regularType, ColorRGBA4D color, bool isWireFrame);
		// Getter function
		RegularType getRegularType();
		// Setter function
		void setRegularType(RegularType regularType);
		// Overriden virtual draw function
		virtual void draw();
};

#endif