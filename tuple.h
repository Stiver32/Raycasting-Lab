#include "utility.h"

struct Tuple
{
    //private:
        

    public:
    
        double _x;
        double _y;
        double _z;
        double _w;

        Tuple(double x, double y, double z, double w) : _x(x), _y(y), _z(z), _w(w){}

        // When you need to test two floating point numbers for equivalence, compare their difference.
        // If the absolute value of their difference is less than some value (called EPSILON), you can consider them equal.



};


Tuple point (double x, double y, double z)
{
    return Tuple(x,y,z,1.0);
}

Tuple vector (double x, double y, double z)
{
    return Tuple(x,y,z,0.0);
}

Tuple addTuples(Tuple& tuple1, Tuple& tuple2)
{
    double x = tuple1._x + tuple2._x;
    double y = tuple1._y + tuple2._y;
    double z = tuple1._z + tuple2._z;
    double w = tuple1._w + tuple2._w;
    Tuple newTuple(x,y,z,w);
    
    return newTuple;
}


bool isVector(Tuple tuple)
{
    return equal(tuple._w, 0.0);
}

bool isPoint(Tuple tuple)
{
    return equal(tuple._w, 1.0);
}

