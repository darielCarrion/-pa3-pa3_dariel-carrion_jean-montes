
#include "FractalCircle.h"

FractalCircle::FractalCircle() {
    this->radius = 100;
    this->n = 0;
    for(int i = 0; i < 7; i++) {
        colorPerN.push_back(ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255)));
    }
}

void FractalCircle::draw() {
    if(this->n >= 6)
        this->n = 6;
    ofSetBackgroundColor(0,0,0); 
    circleMode1(ofGetWidth()/2, ofGetHeight()/2, n, radius);
}

void FractalCircle::circleMode1(int x, int y, int n, float radius) {
    ofSetColor(colorPerN.at(this->n-n));
    if(n!=0){
        ofDrawCircle(x, y, radius);
        circleMode1(x+100, y, n-1, radius*5/((this->n-(n-2))*3));
        circleMode1(x-100, y, n-1, radius*5/((this->n-(n-2))*3));
        circleMode1(x, y+100, n-1, radius*5/((this->n-(n-2))*3));
        circleMode1(x, y-100, n-1, radius*5/((this->n-(n-2))*3));
    }
}


