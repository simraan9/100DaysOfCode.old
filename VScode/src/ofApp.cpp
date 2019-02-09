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
	gui.setup();
	gui.add(endTime.set("endtime",1000.0,0.0,6000.0));
	timerEnd = false;
	startTime = ofGetElapsedTimeMillis();
	//timer
	
	A = Agent(50, 200,0);
	meal = Food();
	//m = Monitor(A);
	ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw(); //timer
	float barWidth = 600;
	float timer = ofGetElapsedTimeMillis()-startTime;

	if timer >= endTime{
		timerEnd = true;
	}

	float timerBar = ofMap(timerEnd, 0.0, endTime, 0.0, 1.0, true);
	ofSetColor = 255;
	ofRect(ofGetWidth() / 2 - 300, ofGetHeight() / 2, barWidth*timerBar, 30);

	if (timer >= 300) {
		ofSetColor(255, 0, 0);
		ofCircle(300, 600, 100);
	}

	A.display();
	A.move();
	meal.display();
	A.eat(meal);
	A.die();
	A.energy = A.energy - 1;
	ofDrawBitmapString("Energy:" , 10, 120);
	ofDrawBitmapString("Death count: " + to_string(A.deathCount), 200, 140);
	ofDrawBitmapString("Eat count: " + to_string(A.eatCount), 10, 140);

	
	ofDrawRectangle(70, 112, int(A.energy/10), 5);
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key = " ") {
		timerEnd = false;
		startTime = ofGetElapsedMillis();
	}

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
