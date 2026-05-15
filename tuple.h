#include "utility.h"

struct Tuple
{
    public:
    
        double _x;
        double _y;
        double _z;
        double _w;

        Tuple(double x, double y, double z, double w) : _x(x), _y(y), _z(z), _w(w){}
};


// HELPER FUNCTIONS

//create a point
Tuple point (double x, double y, double z)
{
    return Tuple(x,y,z,1.0);
}

//create a vector
Tuple vector (double x, double y, double z)
{
    return Tuple(x,y,z,0.0);
}

//add two tuples together
Tuple addTuples(Tuple& tuple1, Tuple& tuple2)
{
    double x = tuple1._x + tuple2._x;
    double y = tuple1._y + tuple2._y;
    double z = tuple1._z + tuple2._z;
    double w = tuple1._w + tuple2._w;
    Tuple newTuple(x,y,z,w);

    return newTuple;
}

//subtract two points to get a vector
Tuple vectorFromPoints(Tuple& point1, Tuple& point2)
{
    double x = point1._x - point2._x;
    double y = point1._y - point2._y;
    double z = point1._z - point2._z;
    auto newVector = vector(x,y,z);

    return newVector;
}


bool isVector(Tuple tuple)
{
    return equal(tuple._w, 0.0);
}

bool isPoint(Tuple tuple)
{
    return equal(tuple._w, 1.0);
}

