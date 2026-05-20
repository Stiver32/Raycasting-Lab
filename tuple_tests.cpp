#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <cmath>
#include "doctest.h"
#include "tuple.h"

TEST_CASE("tuple with w=1 is a point") 
{
    auto a = Tuple(4.3, -4.2, 3.1, 1.0);
    CHECK(equal(a._x, 4.3));
    CHECK(equal(a._y, -4.2)); //a.y = -4.2
    CHECK(equal(a._z, 3.1)); //a.z = 3.1
    CHECK(equal(a._w, 1.0)); //a.w = 1.0
    CHECK(isPoint(a));
    CHECK(!isVector(a)); //a is not a vector
}


// TESTS FOR SCENARIO A1/A2 - SUBTRACTING AND ADDING TUPLES
    //note that adding a point to a vector produces w=1, which is another point
    //but adding a point to a point gives w=2, which is neither vector or point
TEST_CASE("Adding two tuples")
{
    auto a1 = Tuple(3.0, -2.0, 5.0, 1.0); 
    auto a2 = Tuple(-2.0, 3.0, 1.0, 0.0);
    auto result = addTuples(a1,a2);
        //added tuples
    CHECK(equal(result._x, 1.0)); 
    CHECK(equal(result._y, 1.0));
    CHECK(equal(result._z, 6.0));
    CHECK(equal(result._w, 1.0));
}

TEST_CASE("Subtracting a vector from a point gives a point")
{
    auto p1 = makePoint(3.0, 2.0, 1.0); 
    auto v1 = makeVector(5.0, 6.0, 7.0);
    auto pR = pointFromVector(p1, v1);
        
    CHECK(equal(pR._x, -2.0)); 
    CHECK(equal(pR._y,-4.0));
    CHECK(equal(pR._z, -6.0));
}

TEST_CASE("Subtracting two points gives a vector")
{
    auto p1 = makePoint(3.0, 2.0, 1.0); 
    auto p2 = makePoint(5.0, 6.0, 7.0);
    auto vR = vectorFromPoints(p1,p2); 
    CHECK(equal(vR._x, -2.0)); 
    CHECK(equal(vR._y, -4.0));
    CHECK(equal(vR._z, -6.0));
}

TEST_CASE("Subtracting two vectors gives a vector")
{
    auto v1 = makeVector(3.0, 2.0, 1.0);
    auto v2 = makeVector(5.0, 6.0, 7.0);
    auto vR = subtractVectors(v1,v2);
    
    CHECK(equal(vR._x, -2.0)); 
    CHECK(equal(vR._y, -4.0));
    CHECK(equal(vR._z, -6.0));
}

TEST_CASE("Negating a vector")
{
    auto v1 = makeVector(1.0, -2.0, 3.0);
    auto vR = negateVector(v1);

    CHECK(equal(vR._x, -1.0));
    CHECK(equal(vR._y, 2.0));
    CHECK(equal(vR._z, -3.0));
}

TEST_CASE("Multiplying a tuple by a scalar")
{
    auto a1 = Tuple(1.0,-2.0,3.0,-4.0);
    auto aR = multiplyTupleScalar(a1, 3.5);

    CHECK(equal(aR._x, 3.5));
    CHECK(equal(aR._y, -7.0));
    CHECK(equal(aR._z, 10.5));
    CHECK(equal(aR._w, -14.0));
}

TEST_CASE("Multiplying a tuple by a fraction")
{
    auto a1 = Tuple(1.0,-2.0,3.0,-4.0);
    auto aR = multiplyTupleScalar(a1, 0.5);

    CHECK(equal(aR._x, 0.5));
    CHECK(equal(aR._y, -1.0));
    CHECK(equal(aR._z, 1.5));
    CHECK(equal(aR._w, -2.0));
}

TEST_CASE("Dividing a tuple by a scalar")
{
    auto a1 = Tuple(1.0,-2.0,3.0,-4.0);
    auto aR = divideTupleScalar(a1, 2.0);

    CHECK(equal(aR._x, 0.5));
    CHECK(equal(aR._y, -1.0));
    CHECK(equal(aR._z, 1.5));
    CHECK(equal(aR._w, -2.0));
}


TEST_CASE("Computing magnitude of vector(1,0,0)")
{
    auto v1 = makeVector(1.0, 0.0, 0.0);
    auto mR = getVectorMagnitude(v1);

    CHECK(equal(mR, 1.0));
}
TEST_CASE("Computing magnitude of vector(0,1,0)")
{
    auto v1 = makeVector(0.0, 1.0, 0.0);
    auto mR = getVectorMagnitude(v1);

    CHECK(equal(mR, 1.0));
}
TEST_CASE("Computing magnitude of vector(0,0,1)")
{
    auto v1 = makeVector(0.0, 0.0, 1.0);
    auto mR = getVectorMagnitude(v1);

    CHECK(equal(mR, 1.0));
}

TEST_CASE("Normalize the vector (4,0,0)")
{
    auto v1 = makeVector(4.0, 0.0, 0.0);
    auto vR = normalizeVector(v1);
    
    CHECK(equal(vR._x, 1.0));
    CHECK(equal(vR._y, 0.0));
    CHECK(equal(vR._z, 0.0));

}
