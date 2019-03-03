#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //    int angle = ofRandom(0, 360);
    a = Agent();
    ofSetFrameRate(40);
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(FALSE); //unclear the window
    //    int x = ofRandom(1024);
    //    int y = ofRandom(768);
    //    x = 400;
    //    y = 70;
    //    ofDrawCircle(x, y, 30, 30);
    //    a.setTarget(x,y);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //    a.move2();
    //angle = ofRandom(0, 360);
}

//--------------------------------------------------------------
void ofApp::draw(){
    //    a.display();
    a.moveAlongAngle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
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
ofApp.cpp
Displaying textCode.h.
