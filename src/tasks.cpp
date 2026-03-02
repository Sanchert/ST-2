// Copyright 2026 UNN-CS
#define _USE_MATH_DEFINES

#include <stdexcept>
#include <cmath>
#include "circle.h"
#include "tasks.h"

double EarthRope(double additioanl_length) {
    if (additioanl_length <= 0) {
        throw std::invalid_argument("Additional length must be positive");
    }

    Circle earth(EARTH_RADIUS_M);
    double earth_ference = earth.getFerence();
    double new_ference = earth_ference + additioanl_length;

    Circle rope_plus = Circle(1.0);
    rope_plus.setFerence(new_ference);

    return rope_plus.getRadius() - EARTH_RADIUS_M;
}

double Pool(double pool_radius,
           double road_width,
           double concrete_price,
           double fence_price) {
    if (pool_radius <= 0.0) {
        throw std::invalid_argument("pool radius must be positive number");
    }

    Circle pool(pool_radius);
    Circle outer(pool_radius + road_width);

    double road_area = outer.getArea() - pool.getArea();
    double fence_length = outer.getFerence();
    double total_cost = (road_area  * concrete_price) + 
                        (fence_length * fence_price);
    return total_cost;
}
