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
//	TimeCount = Timer();

	A = Agent(50, 200,0);
	meal = Food();
	Rock = Obstacle();
	//m = Monitor(A);
	ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	Rock.display();
	Rock.appear();
	A.display();
	meal.display();
	A.eat(meal);

	if ((A.see(meal) >= 0) && (A.smell(meal) >=0)) {
		A.move();
	}

	A.die();
	A.energy = A.energy - 1;

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
