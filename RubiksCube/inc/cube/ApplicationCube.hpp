#pragma once
#include "Drawable2DCube.hpp"
#include "InteractableCube.hpp"
#include "Scramble.hpp"
#include "Reset.hpp"
#include "Solve.hpp"
#include "TestSolvableCubes.hpp"

class ApplicationCube : 
	public virtual Drawable2DCube, 
	public virtual InteractableCube, 
	public virtual Scramble,
	public virtual Reset,
	public virtual Solve,
	public virtual TestSolvableCubes {};
