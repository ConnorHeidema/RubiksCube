#pragma once
#include "SquarePlacement.hpp"
class CornerCube {
public:
	CornerCube(int face1, int position1, int face2, int position2, int face3, int position3);
	SquarePlacement squarePlacements[3];
};
