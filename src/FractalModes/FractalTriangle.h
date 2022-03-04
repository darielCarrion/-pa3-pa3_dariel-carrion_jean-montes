#pragma once
#include "FractalMode.h"

class FractalTriangle : public FractalMode {
    public:
        FractalTriangle();
        void draw();
        void TriangleMode1(float x, float y, float size, int n);
};
