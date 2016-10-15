#include "MeshRegular.h"

MeshRegular::MeshRegular(RegularType regularType)
{
	mRegularType = regularType;
}

MeshRegular::MeshRegular(RegularType regularType, bool isWireFrame)
{
	mRegularType = regularType;
	setIsWireFrame(isWireFrame);
}

RegularType MeshRegular::getRegularType()
{
	return mRegularType;
}

void MeshRegular::setRegularType(RegularType regularType)
{
	mRegularType = regularType;
}

void MeshRegular::draw()
{
	glPushMatrix();
		glColor3d(getColor().red, getColor().green, getColor().blue);
		glTranslated(getTranslateX(), getTranslateY(), getTranslateZ());
		glRotated(getRotateAngle(), getRotateX(), getRotateY(), getRotateZ());
		glScaled(getScaleX(), getScaleY(), getScaleZ());

		if (getIsWireFrame())
		{
			switch (mRegularType)
			{
				case DODECAHEDRON:
					glutWireDodecahedron();
					break;
				case OCTAHEDRON:
					glutWireOctahedron();
					break;
				case TETRAHEDRON:
					glutWireTetrahedron();
					break;
				case ICOSAHEDRON:
					glutWireIcosahedron();
					break;
			}
		}
		else
		{
			switch (mRegularType)
			{
				case DODECAHEDRON:
					glutSolidDodecahedron();
					break;
				case OCTAHEDRON:
					glutSolidOctahedron();
					break;
				case TETRAHEDRON:
					glutSolidTetrahedron();
					break;
				case ICOSAHEDRON:
					glutSolidIcosahedron();
					break;
			}
		}
	glPopMatrix();
}

