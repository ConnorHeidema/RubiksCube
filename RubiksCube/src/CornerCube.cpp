#include "..\inc\CornerCube.hpp"

CornerCube::CornerCube(int face1, int position1, int face2, int position2, int face3, int position3)
	: squarePlacements {
	SquarePlacement(face1, position1), 
	SquarePlacement(face2, position2), 
	SquarePlacement(face3, position3)} {
}
