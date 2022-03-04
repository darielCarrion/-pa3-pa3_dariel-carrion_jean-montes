#include "FractalTriangle.h"

FractalTriangle::FractalTriangle() {
    this->n = 0;
    for(int i = 0; i < 9; i++) {
        colorPerN.push_back(ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255)));
    }
}

void FractalTriangle::draw() {
    if(this->n >= 9)
        this->n = 9;
    ofSetBackgroundColor(0,0,0); 
    TriangleMode1(ofGetWidth()/3, 10, ofGetHeight()/2, n);
}

void FractalTriangle::TriangleMode1(float x, float y, float size, int n) {
    if(n == 0) {
        return;
    }
    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    ofDrawTriangle(a, b, c);

    TriangleMode1(x, y, size / 2, n - 1);
    TriangleMode1((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1);
    ofSetColor(colorPerN.at(this->n-n));
    TriangleMode1((c.x + a.x) / 2, (c.y + a.y) / 2, size / 2, n - 1);
}

