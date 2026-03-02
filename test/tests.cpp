// Copyright 2022 UNN-CS
#define _USE_MATH_DEFINES
#include <gtest/gtest.h>
#include <cmath>
#include <stdexcept>
#include "circle.h"
#include "tasks.h"

const double EPSILON = 1e-10;

TEST(CircleTest, Constructor) {
    Circle circle(5.0);
    EXPECT_NEAR(circle.getRadius(), 5.0, EPSILON);
    EXPECT_NEAR(circle.getFerence(), (2.0 * M_PI * 5.0), EPSILON);
    EXPECT_NEAR(circle.getArea(), M_PI * 25.0, EPSILON);
}

TEST(CircleTest, ConstructorZeroRadius) {
    EXPECT_THROW(Circle(0.0), std::invalid_argument);
}

TEST(CircleTest, ConstructorNegativeRadius) {
    EXPECT_THROW(Circle(-5.0), std::invalid_argument);
}

TEST(CircleTest, SetRadius) {
    Circle circle(1.0);
    circle.setRadius(3.0);
    EXPECT_NEAR(circle.getRadius(), 3.0, EPSILON);
    EXPECT_NEAR(circle.getFerence(), 2.0 * M_PI * 3.0, EPSILON);
    EXPECT_NEAR(circle.getArea(), M_PI * 9.0, EPSILON);
}

TEST(CircleTest, SetRadiusZero) {
    Circle circle(1.0);
    EXPECT_THROW(circle.setRadius(0.0), std::invalid_argument);
}

TEST(CircleTest, SetRadiusNegative) {
    Circle circle(1.0);
    EXPECT_THROW(circle.setRadius(-2.0), std::invalid_argument);
}

TEST(CircleTest, SetFerence) {
    Circle circle(1.0);
    double new_ference = 10.0;
    circle.setFerence(new_ference);
    double expected_radius = new_ference / (2.0 * M_PI);
    EXPECT_NEAR(circle.getRadius(), expected_radius, EPSILON);
    EXPECT_NEAR(circle.getFerence(), new_ference, EPSILON);
    EXPECT_NEAR(circle.getArea(), M_PI * expected_radius * expected_radius, EPSILON);
}

TEST(CircleTest, SetFerenceZero) {
    Circle circle(1.0);
    EXPECT_THROW(circle.setFerence(0.0), std::invalid_argument);
}

TEST(CircleTest, SetFerenceNegative) {
    Circle circle(1.0);
    EXPECT_THROW(circle.setFerence(-10.0), std::invalid_argument);
}

TEST(CircleTest, SetArea) {
    Circle circle(1.0);
    double new_area = 50.0;
    circle.setArea(new_area);
    double expected_radius = std::sqrt(new_area / M_PI);
    EXPECT_NEAR(circle.getRadius(), expected_radius, EPSILON);
    EXPECT_NEAR(circle.getArea(), new_area, EPSILON);
    EXPECT_NEAR(circle.getFerence(), 2.0 * M_PI * expected_radius, EPSILON);
}

TEST(CircleTest, SetAreaZero) {
    Circle circle(1.0);
    EXPECT_THROW(circle.setArea(0.0), std::invalid_argument);
}

TEST(CircleTest, SetAreaNegative) {
    Circle circle(1.0);
    EXPECT_THROW(circle.setArea(-10.0), std::invalid_argument);
}

TEST(CircleTest, MultipleSetOperations) {
    Circle circle(1.0);

    circle.setRadius(2.0);
    EXPECT_NEAR(circle.getRadius(), 2.0, EPSILON);
    
    circle.setFerence(10.0);
    EXPECT_NEAR(circle.getFerence(), 10.0, EPSILON);
    
    circle.setArea(50.0);
    EXPECT_NEAR(circle.getArea(), 50.0, EPSILON);
}


TEST(EarthRopeTest, DefaultAdditionalLength) {
    double gap = EarthRope();
    EXPECT_GT(gap, 0.0);
    EXPECT_NEAR(gap, 1.0 / (2.0 * M_PI), 0.001);
}

TEST(EarthRopeTest, ZeroAdditionalLength) {
    double additional = 0.0;
    double gap = EarthRope(additional);
    EXPECT_NEAR(gap, 0.0, EPSILON);
}

TEST(EarthRopeTest, CustomAdditionalLength) {
    double additional = 2.0;
    double gap = EarthRope(additional);
    double expected_gap = additional / (2.0 * M_PI);
    EXPECT_NEAR(gap, expected_gap, EPSILON);
}

TEST(PoolTest, DefaultValues) {
    double cost = Pool();
    EXPECT_GT(cost, 0.0);
    double expected_cost = (M_PI * 7000.0) + (M_PI * 16000.0);
    EXPECT_NEAR(cost, expected_cost, 1.0);
}

TEST(PoolTest, ZeroRoadWidth) {
    double cost = Pool(3.0, 0.0);
    double expected_cost = 2.0 * M_PI * 3.0 * 2000.0;
    EXPECT_NEAR(cost, expected_cost, 1.0);
}

TEST(PoolTest, ZeroPrices) {
    double cost = Pool(3.0, 1.0, 0.0, 0.0);
    EXPECT_NEAR(cost, 0.0, EPSILON);
}

TEST(PoolTest, CustomPrices) {
    double concrete = 1500.0;
    double fence = 2500.0;
    double cost = Pool(3.0, 1.0, concrete, fence);
    
    double expected_cost = (M_PI * 7.0 * concrete) + (M_PI * 8.0 * fence);
    EXPECT_NEAR(cost, expected_cost, 1.0);
}
