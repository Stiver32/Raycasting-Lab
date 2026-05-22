#pragma once

#include "utility.h"

struct Tuple
{
    public:
    
        double _x, _y, _z, _w;

        Tuple(double x, double y, double z, double w) : _x(x), _y(y), _z(z), _w(w){}
};


// HELPER FUNCTIONS //

//create a point
Tuple makePoint (double x, double y, double z) { return Tuple(x,y,z,1.0); }

//create a vector
Tuple makeVector (double x, double y, double z) { return Tuple(x,y,z,0.0); }

//add two tuples together
Tuple addTuples(Tuple& tuple1, Tuple& tuple2)
{
    double x = tuple1._x + tuple2._x;
    double y = tuple1._y + tuple2._y;
    double z = tuple1._z + tuple2._z;
    double w = tuple1._w + tuple2._w;
    

    return Tuple(x,y,z,w);
}

//subtract two points to get a vector
Tuple vectorFromPoints(Tuple& point1, Tuple& point2)
{
    double x = point1._x - point2._x;
    double y = point1._y - point2._y;
    double z = point1._z - point2._z;

    return makeVector(x,y,z);
}

// subtract vector from point to get point
Tuple pointFromVector(Tuple& point1, Tuple& vector1)
{
    double x = point1._x - vector1._x;
    double y = point1._y - vector1._y;
    double z = point1._z - vector1._z;

    return makePoint(x,y,z);
}


//subtract two vectors to get a vector
Tuple subtractVectors(Tuple& vector1, Tuple& vector2)
{
    double x = vector1._x - vector2._x;
    double y = vector1._y - vector2._y;
    double z = vector1._z - vector2._z;

    return makeVector(x,y,z);
}

//find the opposite of a vector.
// e.g. given a vector pointing from a surface to a light source, 
//      what vector points from the light source back to the surface?
// obtain this by subtracting the vector from the zero vector (a tuple (0,0,0))
Tuple negateVector(Tuple& vector1)
{
    return makeVector(-vector1._x, -vector1._y, -vector1._z);
}


Tuple multiplyTupleScalar(Tuple& tuple1, double scalar)
{
    double x = tuple1._x * scalar;
    double y = tuple1._y * scalar;
    double z = tuple1._z * scalar;
    double w = tuple1._w * scalar;

    return Tuple(x,y,z,w);
}


Tuple divideTupleScalar(Tuple& tuple1, double scalar)
{
    double x = tuple1._x / scalar;
    double y = tuple1._y / scalar;
    double z = tuple1._z / scalar;
    double w = tuple1._w / scalar;


    return Tuple(x,y,z,w);
}





double getVectorMagnitude(Tuple& tuple1)
{
    double sum = 
    tuple1._x * tuple1._x +
    tuple1._y * tuple1._y +
    tuple1._z * tuple1._z +
    tuple1._w * tuple1._w;

    return std::sqrt(sum);
}   


Tuple normalizeVector(Tuple& vector1)
{
    
    double length = getVectorMagnitude(vector1);

    double x = vector1._x / length;
    double y = vector1._y / length;
    double z = vector1._z / length;

    return makeVector(x,y,z);
}



bool isVector(Tuple tuple)
{
    return equal(tuple._w, 0.0);
}

bool isPoint(Tuple tuple)
{
    return equal(tuple._w, 1.0);
}

