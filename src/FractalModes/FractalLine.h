#pragma once
#include "FractalMode.h"

class FractalLines : public FractalMode {
    public:
        FractalLines();
        void draw();
        void linesMode1(int x, int y, int n, int lenght);
};
