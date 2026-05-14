#include <cassert>
#include "tuple.h"

int main()
{
    //scenario: a tuple with w = 1.0 is a point, w = 0 is a vector
    auto a = Tuple(4.3, -4.2, 3.1, 1.0); //given a <- tuple(4.3, -4.2, 3.1, 1.0)
    auto p = point(4,-4,3); //point() creates tuples with w=1


    assert(equal(a._x, 4.3)); //a.x = 4.3 // assert(equal(a.getX(), 4.3));
    assert(equal(a._y, -4.2)); //a.y = -4.2
    assert(equal(a._z, 3.1)); //a.z = 3.1
    assert(equal(a._w, 1.0)); //a.w = 1.0

    assert(isPoint(a)); //a is a point
    assert(!isVector(a)); //a is not a vector

    

}