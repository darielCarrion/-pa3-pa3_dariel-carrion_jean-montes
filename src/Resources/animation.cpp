#include "animation.h"

Animation::Animation(int* n, int speed) {
    this->n = n;
    this->speed = speed;
    timer = 0;
}

void Animation::StartAnimation() {
    *n = 0;
    SetEnd(false);
}

void Animation::Update() {
    timer+=1;
    if(timer > speed){
        *n+=1;
        timer = 0;
        if(*n == N_LIMIT){
            SetEnd(true);
        }
    }

}

 void Animation::CheckKey(int* key) {
    if(*key != ' ') {
        *key = '#';
    }      
}

void Animation::SetEnd(bool end) {
    this->end = end;
}

bool Animation::GetEnd() {
    return end;
}



