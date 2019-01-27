#include "ofApp.h"
#include "ofMain.h"
//--------------------------------------------------------------
void ofApp::setup(){
    dummy=Agent();
    meal=Food();
    t=Time();
    ofSetFrameRate(t.simulation_speed);
    ofSetVerticalSync(true);
    ofSetCircleResolution(50);
    dummy.setFood(meal);
    dummy.setTimer(t);
    dummy.reSpawn(meal);
}

//--------------------------------------------------------------
void ofApp::update(){
    if(dummy.see()>=0){
        dummy.move();  
    }
    t.keyPressed();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(220, 220, 220);
    //ofTrueTypeFont();
    dummy.display();
    //fill(255,255,255);
    meal.display();
    dummy.die();
    meal.die();
}

//--------------------------------------------------------------
void Food::  display(){
    ofDrawCircle(this->r,this->y,10);
}
//--------------------------------------------------------------
void Food::reset(){
    this->r = ofRandom(50,350);
}
//--------------------------------------------------------------
//void Food :: die(){
  //  if (this->energy<0){
    //   this->reset();
    //}
//--------------------------------------------------------------
void Agent::setFood(Food food){
        this->look_for = food;
    }
//--------------------------------------------------------------
//void Agent::setTimer(Time timer){
  //  this->timer = timer;
}
//--------------------------------------------------------------
void Agent:: reSpawn(Food doof){
    this->change_f=doof;
}

//--------------------------------------------------------------

void Agent::display(){
    int beta=this->radius*cos(2*PI/9);
    int gamma=this->radius*sin(2*PI/9);
    
    if (this->direction==0){
        ofDrawTriangle(this->x+this->radius,this->y,this->x-beta,this->y-gamma,this->x-beta,this->y+gamma);
    }
    else if (this->direction==1) {
        ofDrawTriangle(this->x-this->radius,this->y,this->x-beta+2*beta,this->y-gamma,this->x-beta+2*beta,this->y+gamma);
    }
}

//--------------------------------------------------------------
void Agent::  move(){
    if (this->x<=0+this->radius) {
        this->flip();
    }
    else if (this->x>=400-this->radius) {
        this->flip();
    }
    
    if (this->x<=400 && this->direction==0) {
        if(this->energy/100<=this->max_speed)
            this->x=this->x+(this->energy/100);
        else
            this->x=this->x+this->max_speed;
            }
    else if (this->x>0 && this->direction==1) {
        if(this->energy/100<=this->max_speed)
            this->x=this->x-(this->energy/100);
        else
            this->x=this->x-this->max_speed;
            }
    this->energy=this->energy-1;
}

//--------------------------------------------------------------


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
