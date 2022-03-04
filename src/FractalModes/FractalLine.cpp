#pragma once
#include "FractalLine.h"

FractalLines::FractalLines(){
    this->n = 0;
    for(int i = 0; i < 5; i++) colorPerN.push_back(ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255)));
}

void FractalLines::draw(){
    if(n >= 5)
       n = 5;
    linesMode1(ofGetWidth()/2,ofGetHeight()/2,n,250);
}

void FractalLines::linesMode1(int x, int y, int n, int length){
    int branchX;
    int branchY;
    if(n != 0){
        for(int d = 0; d < 360; d +=45){
            branchX = x -length*cos(PI/180*d);
            branchY = y -length*sin(PI/180*d);
            ofSetColor(colorPerN.at(this->n-n));
            ofDrawLine(x,y,branchX,branchY);
            linesMode1(branchX,branchY,n-1,length/2.5);
        }
    }
}