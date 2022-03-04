#pragma once
#include "FractalMode.h"

class FractalY : public FractalMode {
    private:
        vector<int> degrees;
		int index = 0;
    public:
        FractalY();
        void draw();
        void YMode1(int length, int n, int x, int y, int d);
        void removedegree();
        void addDegree();
};