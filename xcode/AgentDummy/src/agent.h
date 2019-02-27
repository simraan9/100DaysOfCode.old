/*
 The Autonomous Agent of Future
 Authors: Apoorva & Simran
 © 2019 Apoorva&Simran. All Rights Reserved.
 */

#pragma once
using namespace std;

class Time {
public:
    unsigned long long instantTime;
    
    Time() {
        instantTime= ofGetElapsedTimeMillis();
    }
    
    unsigned long long get_time(){
        return instantTime;
    }
};


class Obstacle {
private:
    int x;
    int y;
    
public:
    int time;
    int start;
    int end;
    
    void display() {
        ofSetColor(100, 150, 100);
        ofDrawBitmapString("Time: " + to_string(start) + "  End" + to_string(end) + "s", 10, 380);
        if (controlDisplay() == 0) {
            ofDrawRectangle(x, y - 15, 10, 30);
        }
    }
    
    int get_x() {
        return x;
    }
    
    void respawn() {
        x = ofRandom(20, 380);
        y = 200;
        ofResetElapsedTimeCounter();
    }
    
    int controlDisplay() {
        float endT = ofGetElapsedTimeMillis();
        float timePeriod = time - endT;
        
        if (timePeriod < 10000) {
            appear();
            return 0;
        }
        else if (timePeriod > 10000) {
            
            //timer = ofResetElapsedTimeCounter(); //timer = 0;
            return 1;
        }
        
        return 1;
    }
    
    void appear() {
        time = ofGetElapsedTimeMillis();
        start = time / 1000;
        end = ofRandom(5, 30);
        
        if (start >= end) {
            respawn();
        }
    }
    
    Obstacle() {
        this->x = ofRandom(20, 380);
        this->y = 200;
    }
    
    Obstacle(int x, int y) {
        this->x = x;
        this->y = y;
    }
    
};

class Food {
private:
    int r;
    int y;
    
public:
    
    void display() {
        ofSetColor(255, 0, 0);
        ofDrawCircle(r, y, 5, 5);
    }
    
    void reset() {
        r = ofRandom(50, 350);
    }
    
    int get_r() {
        return r;
    }
    
    Food() {
        this->r = ofRandom(50, 350);
        this->y = 200;
    }
    
    
    
};

class Poison {
    
private:
    
    int p;
    int y;
    
public:
    
    Poison() {
        this->p = ofRandom(50, 350);
        this->y = 200;
    }
    
    void reset() {
        p = ofRandom(50, 350);
    }
    
    int get_p() {
        return p;
    }
    
    void display() {
        ofNoFill();
        ofSetColor(255, 0, 0);
        ofDrawCircle(p, y, 5, 5);
        ofFill();
    }
    
};




class Agent {
private:
    int x;
    int y;
    int radius;
    float theta;
    int beta;
    int gamma;
    
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
    int direction;
    
    int endTime;
    int cycleTime;
    int t2;
    int totalTime;
    int avgTime;
    int count;
    
    
public:
    int eatCount;
    float energy;
    int deathCount;
    int maxSpeed;
    int startTime;
    int t1;
    int foodPos;
    int estPos;
    int returnStatus;
    
    Time timer;
    
    void bindTime(Time &timer){
        this->timer = timer;
    }
    
    Agent() {
        x = 100;
        y = 200;
        theta = 0;
        radius = 20;
        direction = 1;
        eatCount = 0;
        energy = -1;
        deathCount = 0;
        maxSpeed = 10;
        totalTime = 0;
        avgTime = 0;
        cycleTime = 0;
        t2 = 0;
        count = 1;
        startTime = timer.get_time();
        estPos = 0;
        returnStatus = 0;
    }
    
    Agent(int x, int y, float theta) {
        this->x = x;
        this->y = y;
        this->theta = 0;
        radius = 20;
        direction = 1;
        eatCount = 0;
        energy = -1;
        deathCount = 0;
        maxSpeed = 10;
        totalTime = 0;
        avgTime = 0;
        cycleTime = 0;
        t2 = 0;
        count = 1;
        startTime = timer.get_time();
        estPos = 0;
        returnStatus = 0;
    }
    
    
    int get_x() {
        return x;
    }
    
    int get_y() {
        return y;
    }
    
    int get_energy() {
        return energy;
    }
    
    void display() {
        beta = radius * cos(2 * PI / 9);
        gamma = radius * sin(2 * PI / 9);
        
        if (direction == 1) {
            ofSetColor(0, 0, (energy / 1000) * 255);
            ofDrawTriangle(x + radius, y, x - beta, y - gamma, x - beta, y + gamma);
            
            ofSetColor(0, 255, 0);
            ofDrawLine(x, y, x + 50, y);
            ofSetColor(0, 255, 255);
            ofDrawLine(x - 15 - radius, y, x + 30, y);
        }
        else if (direction == 0) {
            ofSetColor(0, 0, (energy / 1000) * 255);
            ofDrawTriangle(x - radius, y, x - beta + 2 * beta, y - gamma, x - beta + 2 * beta, y + gamma);
            
            ofSetColor(0, 255, 0);
            ofDrawLine(x - 50, y, x, y);
            ofSetColor(0, 255, 255);
            ofDrawLine(x - 30 - radius, y, x + 15, y);
        }
    }
    
    void displayText() {
        ofSetColor(255, 255, 255);
        ofDrawBitmapString("Total Time: " + to_string(t1 / 1000) + "s", 10, 300);
        ofDrawBitmapString("Average Time: " + to_string(avgTime / 1000) + "s", 10, 320);
        ofDrawBitmapString("Last cycle Time: " + to_string(cycleTime / 1000) + "s", 10, 340);
        if (rest() == 0) {
            ofSetColor(255, 255, 0);
            ofDrawBitmapString("ZZzz.. ", 250, 120);
        }
        
    }
    
    
    int flip() {
        
        if (direction == 1) {
            direction = 0;
        }
        else if (direction == 0) {
            direction = 1;
        }
        return direction;
    }
    
    int rest() {
        if (energy >= 900) {
            return 0;
        }
        return 1;
    }
    
    void move() {
        if (rest() == 1) {
            if (x >= 0 + radius && direction == 1) {
                x = x + 1;
            }
            else if (x <= 400 - radius && direction == 0) {
                x = x - 1;
            }
            
            if (x == 0 + radius) {
                this->flip();
            }
            else if (x == 400 - radius) {
                this->flip();
            }
        }
        
    }
    
    void displayTime() {
        ofDrawBitmapString("Time " + to_string(startTime), 10, 250);
    }
    
    void countCycleTime() {
        t1 = startTime;
        t2 = timer.get_time();
        cycleTime = t1 - t2;
        totalTime = totalTime + cycleTime;
        avgTime = totalTime / count;
        count = count + 1;
        startTime = t2;
    }
    
    void eat(Food &meal) {
        if (x == meal.get_r()) {
            countCycleTime();
            eatCount = eatCount + 1;
            meal.reset();
            energy = energy + 50;
        }
        
    }
    
    void eatPoison(Poison &pill) {
        if (x == pill.get_p()) {
            energy = energy - 100;
            pill.reset();
        }
        
    }
    
    
    void respawn() {
        x = ofRandom(0, 400);
        
    }
    
    void die() {
        if (energy <= 0) {
            respawn();
            energy = 1000;
            deathCount = deathCount + 1;
        }
    }
    
    int checkJumps(Food &meal, int pos1, int pos2) {
        
        foodPos = meal.get_r();
        
        if (direction == 1) {
            for (int i = pos1; i < pos2 + 1; i++) {
                if (i >= foodPos - 1 && i <= foodPos + 1) {
                    estPos = i; //estimated position
                }
            }
        }
        
        else if (direction == 0) {
            for (int j = pos2; j > pos1 - 1; j--) {
                if (j >= foodPos - 1 && j <= foodPos + 1) {
                    estPos = j;
                }
            }
        }
        return estPos;
        
    }
    
    
    int see(Food meal) {
        die();
        ofDrawLine(x, y, x + 50, y);
        if ((checkJumps(meal, x, x + 50) != 0) && direction == 1) { //checks for 50px awareness
            if ((checkJumps(meal, x, (x + (energy / 100))) != 0) && direction == 1) //checks for speed awareness
                if (energy <= 900) {
                    eat(meal);
                }
                else {
                    move();
                }
        }
        else if ((checkJumps(meal, x - 50, x) != 0) && direction == 0) {
            if ((checkJumps(meal, x - (energy / 100), x) != 0) && direction == 0)
                if (energy <= 900) {
                    eat(meal);
                }
                else {
                    move();
                }
        }
        else {
            move();
        }
        
        return estPos;
    }
    
    //This function checks if the food is within 30px ahead and 15 px behind his nose and flips direction to get there quicker.
    
    int smell(Food meal) {
        if ((checkJumps(meal, x, x + 30) != 0) && direction == 1) {
            if ((checkJumps(meal, x, (x + (energy / 100))) != 0) && direction == 1)
                if (energy <= 900) {
                    eat(meal);
                }
        }
        else if ((checkJumps(meal, x - 30, x) != 0) && direction == 0) {
            if ((checkJumps(meal, x - (energy / 100), x) != 0) && direction == 0)
                if (energy <= 900) {
                    eat(meal);
                }
            
            if ((checkJumps(meal, x - 15 + radius, x + radius) != 0) && direction == 1) {
                if ((checkJumps(meal, x, (x + (energy / 100))) != 0) && direction == 1)
                    if (energy <= 900) {
                        eat(meal);
                    }
            }
            else if ((checkJumps(meal, x + radius, x - 15 + radius) != 0) && direction == 0) { //checks for 50px awareness in -ve direction
                if ((checkJumps(meal, x - (energy / 100), x) != 0) && direction == 0) //checks for speed awareness -ve direction
                    if (energy <= 900) {
                        eat(meal);
                    }
            }
            return estPos;
        }
    }
    
    int avoidObstacle(Obstacle &Rock) {
        if (Rock.get_x() == x + 20 && direction == 1) {
            returnStatus = wait();
            return returnStatus;
            
        }
        if (Rock.get_x() == x - 20 && direction == 0) {
            returnStatus = wait();
            return returnStatus;
        }
    }
    
    int wait() {
        int waitTime=0;
        int beginTime = timer.get_time();
        while (waitTime-beginTime<3000){
            waitTime = timer.get_time();
        
       // if (myTimerStart <= 3000) {
            //return 0;
       // }
        //else if (myTimerStart > 3000) {
           // flip();
        //}
    }
    
    
    int avoidEdge(Food meal) {
        if (x >= 350 && see(meal) != 0 && direction == 1) {
            flip();
            return 1;
        }
        if (x <= 50 && see(meal) != 0 && direction == 0) { // if there is no food within 50 px of edge
            flip();
            return 1;
        }
        return 0;
    }
    
    
    
};
