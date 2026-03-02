// Copyright 2022 UNN-CS
#define _USE_MATH_DEFINES

#include <cmath>
#include <stdexcept>
#include "circle.h"

Circle::Circle(double radius) : radius_(radius) {
    if (radius <= 0.0) {
        throw std::invalid_argument("Radius mast be > 0");
    }
    ference_ = 2.0 * M_PI * radius_;
    area_ = M_PI * radius_ * radius_;
}

void Circle::setRadius(double radius) {
    if (radius <= 0.0) {
        throw std::invalid_argument("Radius mast be > 0");
    }
    radius_ = radius;
    ference_ = 2.0 * M_PI * radius_;
    area_ = M_PI * radius_ * radius_;
}

void Circle::setFerence(double ference) {
    if (ference <= 0.0) {
        throw std::invalid_argument("Ference mast be > 0");
    }
    ference_ = ference;
    radius_ = ference_ / 2.0 / M_PI;
    area_ = M_PI * radius_ * radius_;
}

void Circle::setArea(double area) {
    if (area <= 0.0) {
        throw std::invalid_argument("Area mast be > 0");
    }
    area_ = area;
    radius_ = std::sqrt(area_ / M_PI);
    ference_ = 2.0 * M_PI * radius_;
}

double Circle::getRadius() const {
    return radius_;
}

double Circle::getFerence() const {
    return ference_;
}

double Circle::getArea() const {
    return area_;
}
