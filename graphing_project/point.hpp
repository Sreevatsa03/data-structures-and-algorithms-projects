#ifndef POINT_HPP_
#define POINT_HPP_

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <ctime>
#include <algorithm>

using namespace std;

class point { 
public:
    double x;
    double y;

    point(double X, double Y) {
        x = X;
        y = Y;
    }

    point() {
        random_device rd;  
        mt19937 gen(rd()); 
        uniform_real_distribution<> dis(-10.0, 10.0);
        x = dis(gen);
        y = dis(gen);
        // x = ((double)rand() / (double)RAND_MAX) * (20.0) - 10.0;
        // y = ((double)rand() / (double)RAND_MAX) * (20.0) - 10.0;
    }

    double distance(point a) {
        double d = sqrt((pow((a.x) - (this -> x), 2) + pow((a.y) - (this -> y), 2)));
        return d;
    }
};

#endif /* POINT_HPP_ */
