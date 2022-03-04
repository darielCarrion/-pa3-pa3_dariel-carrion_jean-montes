#pragma once
#include "ofMain.h"

class FractalMode {
    protected:
        bool activate = false;
        int n;
        vector<ofColor> colorPerN;
    public:
        virtual void draw() = 0;
        virtual void setActivate(bool activate) {this->activate = activate;}
        virtual bool getActivate() {return activate;}
        void setN(int n) {this->n = n;} 
};
