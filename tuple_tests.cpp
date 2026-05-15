#include "tuple.h"

int main()
{

    // TESTS FOR SCENARIO A
    //scenario: a tuple with w = 1.0 is a point, w = 0 is a vector
    auto a = Tuple(4.3, -4.2, 3.1, 1.0); //given a <- tuple(4.3, -4.2, 3.1, 1.0)
    auto p = point(4, -4, 3); //point() creates tuples with w=1
    auto v = vector(4, -4, 3);

    assert(equal(a._x, 4.3)); //a.x = 4.3 // assert(equal(a.getX(), 4.3));
    assert(equal(a._y, -4.2)); //a.y = -4.2
    assert(equal(a._z, 3.1)); //a.z = 3.1
    assert(equal(a._w, 1.0)); //a.w = 1.0
    
    assert(isPoint(a)); //a is a point
    assert(!isVector(a)); //a is not a vector


    // TESTS FOR SCENARIO A1/A2 - SUBTRACTING AND ADDING TUPLES
    //note that adding a point to a vector produces w=1, which is another point
    //but adding a point to a point gives w=2, which is neither vector or point
    auto a1 = Tuple(3.0, -2.0, 5.0, 1.0); 
    auto a2 = Tuple(-2.0, 3.0, 1.0, 0.0);
    auto addedTuples = addTuples(a1,a2);

    auto p1 = point(3.0, 2.0, 1.0); 
    auto p2 = point(5.0, 6.0, 7.0);
    auto v1 = vector(5.0, 6.0, 7.0);
    
    auto v2 = vectorFromPoints(p1,p2); //subtract two points to get a vector
    auto p3 = pointFromVector(p1, v1);//subtract a vector from a point to get a point

    assert(equal(addedTuples._x, 1.0));
    assert(equal(addedTuples._y, 1.0));
    assert(equal(addedTuples._z, 6.0));
    assert(equal(addedTuples._w, 1.0));

    assert(equal(v2._x, -2.0));
    assert(equal(v2._y, -4.0));
    assert(equal(v2._z, -6.0));





    std::cout << "All tests passed\n";

}