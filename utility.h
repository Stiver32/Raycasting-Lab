#pragma once

#include <cmath>
#include <iostream>
#include <cassert>


const double EPSILON = 0.00001;


//HELPER FUNCTIONS

// When you need to test two floating point numbers for equivalence, compare their difference.
// If the absolute value of their difference is less than some value (called EPSILON), you can consider them equal.
bool equal(double var1, double var2)
{
    return std::abs(var1 - var2) < EPSILON;
}

