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

        bool isVector()
        {
            return equal(_w, 0.0);
        }

        bool isPoint()
        {
            return equal(_w, 1.0);
        }

};

