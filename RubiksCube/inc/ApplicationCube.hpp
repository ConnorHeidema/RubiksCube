#pragma once
#include "Drawable2DCube.hpp"
#include "MoveInteractionHUDCube.hpp"
#include "Scramble.hpp"

class ApplicationCube : public Drawable2DCube, public MoveInteractionHUDCube, public Scramble {
};

