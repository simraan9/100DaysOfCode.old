/*
	The Autonomous Agent of Future
	Authors: Apoorva & Simran
	© 2019 Apoorva&Simran. All Rights Reserved.
*/

#pragma once
using namespace std;

/*
class Timer {
private:

public:
	int startTime;
	
	Timer() {
		startTime = ofGetElapsedTimeMillis();
	}
	
	void display() {
		ofDrawBitmapString("Time " + to_string(startTime), 10, 250);
	}
	void reset() {
		startTime = ofGetElapsedTimeMillis();
	}
}t;
*/

class Food {
private:
	int r;
	int y;

public:

	void display() {
		ofDrawCircle(r, y, 5, 5);
	}

	void reset() {
		r = ofRandom(5, 395);
	}

	int get_r() {
		return r;
	}

	Food() {
		this->r = ofRandom(5, 395);
		this->y = 200;
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

	Agent() {
		x = 100;
		y = 200;
		theta = 0;
		radius = 20;
		direction = 1;
		eatCount = 0;
		energy = 1000;
		deathCount = 0;
		maxSpeed = 10;
		totalTime = 0;
		avgTime = 0;
		cycleTime = 0;
		t2 = 0;
		count = 1;
		startTime = ofGetElapsedTimeMillis();
	}

	Agent(int x, int y, float theta) {
		this->x = x;
		this->y = y;
		this->theta = 0;
		radius = 20;
		direction = 1;
		eatCount = 0;
		energy = 1000;
		deathCount = 0;
		maxSpeed = 10;
		totalTime = 0;
		avgTime = 0;
		cycleTime = 0;
		t2 = 0;
		count = 1;
		startTime = ofGetElapsedTimeMillis();
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


		int x1 = x + (radius*(cos(theta)));
		int y1 = y + (radius*(sin(theta)));
		int x2 = x + (radius*(cos(theta + 2 * (PI / 3) + (PI / 8))));
		int y2 = y + (radius*(sin(theta + 2 * (PI / 3) + (PI / 8))));
		int x3 = x + (radius*(cos(theta + (-4)*(PI / 6) - (PI / 8))));
		int y3 = y + (radius*(sin(theta + (-4)*(PI / 6) - (PI / 8))));
		beta = radius*cos(2 * PI / 9);
		gamma = radius*sin(2 * PI / 9);

		if (direction == 1) {
			ofDrawTriangle(x + radius, y, x - beta, y - gamma, x - beta, y + gamma);
		}
		else if (direction == 0) {
			ofDrawTriangle(x - radius, y, x - beta + 2 * beta, y - gamma, x - beta + 2 * beta, y + gamma);
		}


		ofDrawBitmapString("Total Time: " + to_string(totalTime), 10, 300);
		ofDrawBitmapString("Average Time: " + to_string(avgTime), 10, 320);
		ofDrawBitmapString("Last cycle Time: " + to_string(cycleTime), 10, 340);


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

	void move() {
	
		if (x >= 0 && direction == 1) {
			x = x + 1;
		}
		else if (x <= 400 && direction == 0) {
			x = x - 1;
		}
	
		if (x == 0) {
			this->flip();
		}
		else if (x == 400){
			this->flip();
		}
		
	
	}

	void displayTime() {
		ofDrawBitmapString("Time " + to_string(startTime), 10, 250);
	}
	void resetTime() {
		startTime = ofGetElapsedTimeMillis();
	}

	void countCycleTime() {
		t1 = startTime;
		cycleTime = t1 - t2;
		totalTime = totalTime + cycleTime;
		avgTime = totalTime/count;
		t2 = t1;
		count = count + 1;
	}

	void eat(Food &meal) {
	
		if (x == meal.get_r()) {
			countCycleTime();
			eatCount = eatCount + 1;
			meal.reset();
			resetTime();
			energy = energy + 50;
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
};

