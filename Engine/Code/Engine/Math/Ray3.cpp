#include "Engine/Math/Ray3.hpp"
//-----------------------------------------------------------------------------------------------
// Engine Includes

//-----------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------
// Evaluates the ray position at step 't'
//
Vector3 Ray3::Evaluate(float t) const
{
	return start + dir * t;
}