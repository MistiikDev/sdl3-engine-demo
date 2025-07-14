#pragma once
#ifndef MATH_H
#define MATH_H

#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

struct Vector2 {
    Vector2(): x(0), y(0) {};
    Vector2(double x, double y): x(x), y(y) {};

    double x, y;

    void print() {
        std::cout << "X: " << x << " / Y: " << y << "\n";
    }
};

#endif