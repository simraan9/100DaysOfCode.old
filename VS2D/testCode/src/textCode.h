#pragma once
#include "ofMain.h"
using namespace std;

class Agent {
private:
    
public:
    int x;
    int y;
    int tx;
    int ty;
    int a;
    int b;
    //int angle;
    int p;
    int q;
    
    int new_x;
    int new_y;
    
    void display() {
        //stroke(13,45,32);
        ofNoFill();
        ofSetColor(45, 45, 230);
        ofDrawCircle(x,y,10,10);
    }
    
    
    void moveLeft() {
        x = x - 1;
    }
    void moveRight() {
        x = x + 1;
    }
    void moveUp() {
        y = y + 1;
    }
    void moveDown() {
        y = y - 1;
    }
    void setTarget(int tx, int ty) {
        this->tx = tx;
        this->ty = ty;
    }
    
    void move3() {
        x = (tx - x) / 100;
        y = (ty - y) / 100;
        
        
    }
    float slope() {
        float m = 0;
        if (tx - x != 0) {
            m = atan((ty - y) / (tx - x));
        }
        return m;
    }
    
    void move2() {
        float s = slope();
        
        if ((tx - x) >= 0) {
            x = x + 1;
        }
        else if ((tx - x) <= 0) {
            x = x - 1;
        }
        y = s * x;
    }
    
    void move() {
        
        int buff = ofRandom(0, 4);
        if (buff == 0) {
            moveLeft();
        }
        else if (buff == 1) {
            moveRight();
        }
        else if (buff == 2) {
            moveUp();
        }
        else if (buff == 3) {
            moveDown();
        }
    }
    
    void moveAlongAngle() {
        
        
        int origin_x = 0;
        int origin_y = 0;
        
        int R = 50;
        int r = 10;
        int angle = ofRandom(0,360);
        //ofDrawCircle(origin_x, origin_y, 2); // home
        
        //    new_x = origin_x + r * cos((angle*PI)/180);
        //    new_y = origin_y + r * sin((angle*PI)/180);
        
        ofSetColor(40, 40, 200);
        ofDrawCircle(new_x, new_y, 2);
        
        ofDrawBitmapString(to_string(new_x) + " new x " + to_string(new_y) + " new y ", 150, 100);
        
        for (int i = r; i < R; i=i+1) {
            origin_x = p;
            origin_y = q;
            origin_x = origin_x + r * cos((angle*PI) / 180);
            origin_y = origin_y + r * sin((angle*PI) / 180);
            ofDrawCircle(origin_x, origin_y, 2);
            p = origin_x;
            q = origin_y;
            
        }
        
        //}
        
        /*int moveToPoint(int a, int b) {
         
         int a = 50;
         int b = 50;
         
         for (int j = angle; j <= 360; j++) { //checking at every angle
         new_x = origin_x + r * cos((angle*PI) / 180);
         
         if (new_x == a) {
         ofDrawBitmapString(to_string(angle) + " angle", 20,100);
         }
         }
         
         for (int j = angle; j <= 360; j++) { //checking at every angle
         new_y = origin_y + r * cos((angle*PI) / 180);
         
         if (new_y == b) {
         ofDrawBitmapString(to_string(angle) + " angle", 20, 110);
         }
         }
         */
    }
    
    
    Agent() {
        this->x = 400;
        this->y = 400;
        this->p = 200;
        this->q = 200;
        //this->angle = ofRandom(0, 360);
        //        this->a = 50;
        //        this->b = 50;
    }
    
};
textCode.h
Displaying textCode.h.
