#include <cmath>
const double EPSILON = 0.00001;

//HELPER FUNCTIONS
bool equal(double var1, double var2)
{
    return std::abs(var1 - var2) < EPSILON;
}