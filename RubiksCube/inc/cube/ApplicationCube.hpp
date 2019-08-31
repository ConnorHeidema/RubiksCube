#pragma once
#include "Drawable2DCube.hpp"
#include "MoveInteractionHUDCube.hpp"
#include "Scramble.hpp"


class ApplicationCube : public virtual Drawable2DCube, public virtual MoveInteractionHUDCube, public virtual Scramble {
};
