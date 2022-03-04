#pragma once
#include "ofMain.h"

class Animation
{
private:
    int const N_LIMIT = 9;
    int* n;
    int timer;
    int speed;
    bool end = true;

public:
    Animation(int*, int);
    void StartAnimation();
    void Update();
    bool GetEnd();
    void SetEnd(bool);
    void CheckKey(int* key);
};


