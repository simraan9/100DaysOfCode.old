#include "ofApp.h"
#include "ofMain.h"
//--------------------------------------------------------------
int death_count=-1;
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
    meal.checkEnergy(dummy);
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
    //meal.checkEnergy();
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
//void Food :: checkEnergy(Agent dummy){
    //this->energy=energy;
  //  if (this->energy<0){
        //this->reset();
   // }
//}
    
//--------------------------------------------------------------
void Agent::setFood(Food food){
        this->look_for = food;
    }
//--------------------------------------------------------------
//void Agent::setTimer(Time timer){
  //  this->timer = timer;

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
void Agent::flip(){
    if (this->direction==0){
        this->direction=1;
    }
    else    if (this->direction==1){
        this->direction=0;
    }
}
//--------------------------------------------------------------
int Agent::see(){
    if ((this->check_jumps(this->x,this->x+50)!=0) && this->direction ==1){//checks for 50px awareness in +ve direction
        if ((this->check_jumps(this->x,(this->x+(this->energy/100)))!=0) && this->direction ==1){ //checks for speed awareness +ve direction
            if(this->energy<=900){
                this->eat_food();
            }
        }
            else{
                this->move();
            }
    }
    else if ((this->check_jumps(this->x-50,this->x)!=0)&& this->direction ==0){ //checks for 50px awareness in -ve direction
        if ((this->check_jumps(this->x-(this->energy/100),this->x)!=0)&& this->direction ==0){ //checks for speed awareness -ve direction
            if(this->energy<=900){
                this->eat_food();
            }
        }
            else{
                this->move();
            }
    }
    else
        this->move();
    return this->flag;
}
//--------------------------------------------------------------
//checks if the food is between two points
int Agent::check_jumps(int m, int n){
    int r = this->look_for.r;
    if(this->direction==1){
        for(int i=m; i<n+1; i++)
            if(i>=r-1 && i<=r+1)
                this->flag=i;
                }
    
    else if (this->direction==0){
        for(int j=n; j>m-1; j--)
            if(j>=r-1 && j<=r+1)
                this->flag=j;
                }
    return this->flag;
}
//--------------------------------------------------------------
void Agent::eat_food(){
    int r = this->look_for.r;
    if(this->x>=r-(this->energy/100) && this->x<=r+(this->energy/100)){
        this->timer.count_cycletime();
        this->energy=this->energy+50;
        this->change_f.reset();
        this->flag=0;
    }
}
//--------------------------------------------------------------
void Agent:: die(){
    if (this->energy<0){
        this->reset();
    }
    this->flag=0;
}
//--------------------------------------------------------------

//respawns the agent
void Agent::reset(){
    this->x = ofRandom(400);
    this->energy=1000;
    death_count=death_count+1;
}
//--------------------------------------------------------------
void Time::count_cycletime(){
    int time= this->frameCounts;
    this->cycle_time= time-this->time2;
    this->total_time=this->total_time+this->cycle_time;
    this->avg_time=this->total_time/this->count_cycle;
    this->time2= time;
    this->count_cycle=this->count_cycle+1;
}
//--------------------------------------------------------------

/*void Time:: keyPressed(){
    if (ofGetKeyPressed() == char(65)){
        this->simulation_speed += 20;
    }
    else if(ofGetKeyPressed( == char(66)){
        this->simulation_speed -= 20;
    }
}*/
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
