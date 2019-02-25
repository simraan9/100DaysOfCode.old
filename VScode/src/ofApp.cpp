/*
 The Autonomous Agent of Future
 Authors: Apoorva & Simran
 © 2019 Apoorva&Simran. All Rights Reserved.
 */

#include "ofApp.h"
#include "agent.h"
#include "iostream"

using namespace std;

//--------------------------------------------------------------

void ofApp::setup(){
    ofSetFrameRate(24);
    ofSetVerticalSync(true);
    A = Agent(50, 200,0);
    meal = Food();
    Rock = Obstacle();
    pill = Poison();
    ofSetBackgroundColor(100,100,100);
	ofResetElapsedTimeCounter();
	timer = Time();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if ((A.see(meal) >= 0) && (A.smell(meal) >=0) && A.avoidObstacle(Rock)>0) {
        A.move();
    }
    
    A.avoidEdge(meal);
    A.die();
    A.eatPoison(pill);
    A.energy = A.energy - 1;
	//Rock.controlDisplay();
	time = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    Rock.display();
    Rock.controlDisplay();
    A.display();
    A.displayText();
    meal.display();
    A.eat(meal);
    pill.display();
    
    //    if (A.get_x() <= 380) {
    //    A.avoidEdge(meal);
    //}
    //if (A.get_x() <= 20) {
    //A.avoidEdge(meal);
    //}
    
    ofSetColor(255);
    ofDrawBitmapString("Energy:" , 10, 120);
    ofDrawBitmapString("Death count: " + to_string(A.deathCount), 200, 140);
    ofDrawBitmapString("Eat count: " + to_string(A.eatCount), 10, 140);
    ofDrawBitmapString("Estpos: " + to_string(A.estPos), 10, 100);
    
    ofDrawRectangle(70, 112, int(A.energy/10), 5);
    
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
