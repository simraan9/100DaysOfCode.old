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


	Agent() {
		this->x = 400;
		this->y = 400;

	}
	
 };
