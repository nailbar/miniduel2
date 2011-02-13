#ifndef RR_VECTOR_H
#define RR_VECTOR_H 1

class RR_vector {
public:
    double x, y;
    
    // Constructors
    RR_vector() {
        x = 0;
        y = 0;
    }
    RR_vector(double newx, double newy) {
        x = newx;
        y = newy;
    }
    
    // Operator overloading
    RR_vector operator + (RR_vector v) {
        RR_vector vec;
        vec.x = x + v.x;
        vec.y = y + v.y;
        return vec;
    }
    RR_vector operator - (RR_vector v) {
        RR_vector vec;
        vec.x = x - v.x;
        vec.y = y - v.y;
        return vec;
    }
    RR_vector operator * (double d) {
        RR_vector vec;
        vec.x = x * d;
        vec.y = y * d;
        return vec;
    }
    RR_vector operator / (double d) {
        RR_vector vec;
        vec.x = x / d;
        vec.y = y / d;
        return vec;
    }
    
    // Methods
    void normalise() {
        double dis = sqrt(x * x + y * y);
        if(dis > 0.0) {
            x = x / dis;
            y = y / dis;
        } else {
            x = 1;
            y = 0;
        }
    }
    void extrude() {
        double x2 = -y;
        double y2 = x;
        x = x2;
        y = y2;
    }
};

// Helpers
class RR_vector_funcs {
public:
    
    // Return the normal of a vector
    RR_vector normal(RR_vector v) {
        double dis = sqrt(v.x * v.x + v.y * v.y);
        if(dis > 0.0) return v / dis;
        return RR_vector(1, 0);
    }
    
    // Return the extruded vector (90 deg right)
    RR_vector extrude(RR_vector v) {
        return RR_vector(-v.y, v.x);
    }
};

// Auto declare helper class
RR_vector_funcs RRvf;

#endif // RR_VECTOR_H
