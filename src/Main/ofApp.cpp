#include "ofApp.h"
#include "FractalCircle.h"
#include "FractalY.h"
#include "FractalTriangle.h"
#include "FractalLine.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0, 0, 0);
    fractalModes.push_back(new FractalCircle);
    fractalModes.push_back(new FractalY);
    fractalModes.push_back(new FractalTriangle);
    fractalModes.push_back(new FractalLines);
    anim = new Animation(&n, 60);
}

//--------------------------------------------------------------
void ofApp::update(){
    /* The update method is called muliple times per second
    It's in charge of updating variables and the logic of our app */
    
    if(anim->GetEnd() == false){
        int n = this->n;
        anim->Update();
        if(n < this->n)
            dynamic_cast<FractalY*>(fractalModes[1])->addDegree();
    }
    if(this->n >= 9) {
        this->n = 9;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    /* The update method is called muliple times per second
    It's in charge of drawing all figures and text on screen */
    ofNoFill();
    if(fractalModes[0]->getActivate()){
        fractalModes[0]->setN(this->n);
        fractalModes[0]->draw();
    }if(fractalModes[1]->getActivate()){
        fractalModes[1]->setN(this->n);
        fractalModes[1]->draw();
    }if(fractalModes[2]->getActivate()) {
        fractalModes[2]->setN(this->n);
        fractalModes[2]->draw();
    }if(fractalModes[3]->getActivate()){
        fractalModes[3]->setN(this->n);
        fractalModes[3]->draw();
    }
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // This method is called automatically when any key is pressed
    if(anim->GetEnd() == false) {
            anim->CheckKey(&key);
        }
    switch(key){
        case '1':
            fractalModes[0]->setActivate(!fractalModes[0]->getActivate());
            break;
        case '2':
            fractalModes[1]->setActivate(!fractalModes[1]->getActivate());
            break;
        case '3':
            fractalModes[2]->setActivate(!fractalModes[2]->getActivate());
            break;
        case '4':
            fractalModes[3]->setActivate(!fractalModes[3]->getActivate());
            break;
        case '-':
            if(n > 0) {
                n--;
                dynamic_cast<FractalY*>(fractalModes[1])->removedegree();
            }
            break;
        case '=':
            n++;
            dynamic_cast<FractalY*>(fractalModes[1])->addDegree();
            break;
        case ' ':
            if(anim->GetEnd() == true)
                anim->StartAnimation();
            else
                anim->SetEnd(true);
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}