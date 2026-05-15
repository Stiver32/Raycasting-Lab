#include "tuple.h"

int main()
{
    //scenario: a tuple with w = 1.0 is a point, w = 0 is a vector
    auto a = Tuple(4.3, -4.2, 3.1, 1.0); //given a <- tuple(4.3, -4.2, 3.1, 1.0)

    auto a1 = Tuple(3.0, -2.0, 5.0, 1.0); 
    auto a2 = Tuple(-2.0, 3.0, 1.0, 0.0);

    auto p = point(4, -4, 3); //point() creates tuples with w=1
    auto v = vector(4, -4, 3);

    auto addedTuples = addTuples(a1,a2);

    // TESTS FOR SCENARIO A
    assert(equal(a._x, 4.3)); //a.x = 4.3 // assert(equal(a.getX(), 4.3));
    assert(equal(a._y, -4.2)); //a.y = -4.2
    assert(equal(a._z, 3.1)); //a.z = 3.1
    assert(equal(a._w, 1.0)); //a.w = 1.0
    
    assert(isPoint(a)); //a is a point
    assert(!isVector(a)); //a is not a vector


    // TESTS FOR SCENARIO A1/A2
    assert(equal(addedTuples._x, 1.0));
    assert(equal(addedTuples._y, 1.0));
    assert(equal(addedTuples._z, 6.0));
    assert(equal(addedTuples._w, 1.0));

    std::cout << "All tests passed\n";

}