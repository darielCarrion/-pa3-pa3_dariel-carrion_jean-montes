#include "FractalY.h"

FractalY::FractalY() {
    this->n = 4;
    for(int i = 0; i < 9; i++) {
        colorPerN.push_back(ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255)));
    }
    for(int i = 0; i < pow(2,n) * 2 - 2 ; i++) degrees.push_back(ofRandom(30,70));
}

void FractalY::draw() {
    if(this->n >= 8)
        this->n = 8;
    ofSetBackgroundColor(0,0,0); 
    index = 0;
    YMode1(200, n, ofGetWidth()/2, ofGetHeight()-50, 30);
}

void FractalY::YMode1(int length, int n, int x, int y, int d) {
    ofSetColor(colorPerN.at(this->n-n));
    if(n != 0){
        int middleY = y-length;
        int leftBranchX = x -length*cos(PI/180*d);
        int leftBranchY = middleY -length*sin(PI/180*degrees[index]);
        int rightBranchX = x +length*cos(PI/180*d);
        int rightBranchY = middleY -length*sin(PI/180*degrees[index+1]);
        index += 1;

        ofDrawLine(x, y, x,y-length);
        ofDrawLine(x, y-length, rightBranchX, rightBranchY);
        ofDrawLine(x,y-length, leftBranchX, leftBranchY);

        YMode1(length/2, n-1,rightBranchX,rightBranchY, 30);
        YMode1(length/2,n-1,leftBranchX,leftBranchY, 30);
    }
}

void FractalY::removedegree() {
    for(int i = 0; i < pow(2,n); i++) degrees.pop_back();
}

void FractalY::addDegree() {
    for(int i = 0; i < pow(2,n); i++) degrees.push_back(ofRandom(30,70));
}
