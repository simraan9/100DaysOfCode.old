//
//  VectorHead.h
//  VectorMotion
//
//  Created by Apoorva on 06/03/19.
//

#ifndef VectorHead_h
#define VectorHead_h

class PVector {
public:
    float x;
    float y;
    
    PVector(){
        x = 200;
        y = 200;
    }
    
    PVector(float x, float y){
        this->x = x;
        this->y = y;
    }
    
    void add(PVector v){
        x = x + v.x;
        y = y + v.y;
    }
    
    void sub(PVector v){
        x = x - v.x;
        y = y - v.y;
    }
    void mul(float m){
        x = x * m;
        y = y * m;
    }
    void div(float m){
        x = x / m;
        y = y / m;
    }
    
    void limit(float max) {
        if (x > max) {
            x=max;
        }
        if (y > max) {
            y=max;
        }
    }
    
    float mag(){
        return sqrt((x*x)+(y*y));
    }
    
    void normalize(){
        float m = mag();
        div(m);
    }
    
    float heading(){
       return atan(y/x);
    }
    
    void translate(PVector v){
        x=v.x-x;
        y=v.y-y;
    }
    
};

class VectorHead {
public:
    PVector location;
    PVector velocity;
    PVector acceleration;
    PVector desired;
    PVector steer;
    float r;
    float maxforce;
    float maxspeed;
    
    VectorHead(float x, float y) {
        acceleration = PVector(0,0);
        velocity = PVector(0,0);
        location = PVector(x,y);
        r = 3.0;
        maxspeed = 4;
        maxforce = 0.1;
    }
    
    void update() {
        velocity.add(acceleration);
        velocity.limit(maxspeed);
        location.add(velocity);
        acceleration.mul(0);
    }
    
    void applyForce(PVector force) {
            acceleration.add(force);
        }
        
    void seek(PVector target) {
        target.sub(location);
        desired= new PVector(target.x,target.y);
        desired.normalize();
        desired.mul(maxspeed);
        desired.sub(velocity);
        steer= new PVector(desired.x,desired.y);
        steer.limit(maxforce);
        applyForce(steer);
        }
        
    void display() {
            float theta = velocity.heading() + PI/2;
            //fill(175);
            //stroke(0);
            pushMatrix();
            translate(location);
            rotate(theta);
            ofBeginShape();
            vertex(0, -r*2);
            vertex(-r, r*2);
            vertex(r, r*2);
            endShape(CLOSE);
            popMatrix();
        }

};

#endif /* VectorHead_h */
