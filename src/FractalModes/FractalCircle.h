#pragma once
#include "FractalMode.h"

class FractalCircle : public FractalMode {
    private:
        float radius;
    public:
        FractalCircle();
        void draw();
        void circleMode1(int, int, int, float);
};
