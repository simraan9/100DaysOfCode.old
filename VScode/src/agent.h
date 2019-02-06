#pragma once

class Agent {
private:
	int x;
	int y;
	int radius;
	float theta;

	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;
	int direction;


public:

	Agent() {
		x = 100;
		y = 100;
		theta = 0;
		radius = 20;
		direction = 1;
	}

	Agent(int x, int y, float theta) {
		this->x = 100;
		this->y = 100;
		this->theta = 0;
		radius = 20;
		direction = 1;
	}
	int get_x() {
		return x;
	}
	int get_y() {
		return y;
	}
	void display() {
		int x1 = x + (radius*(cos(theta)));
		int y1 = y + (radius*(sin(theta)));
		int x2 = x + (radius*(cos(theta + 2 * (PI / 3) + (PI / 8))));
		int y2 = y + (radius*(sin(theta + 2 * (PI / 3) + (PI / 8))));
		int x3 = x + (radius*(cos(theta + (-4)*(PI / 6) - (PI / 8))));
		int y3 = y + (radius*(sin(theta + (-4)*(PI / 6) - (PI / 8))));

		ofDrawTriangle(x1, y1, x2, y2, x3, y3);

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
};

class Food {
private:
	int r;
	int y;
	
public:

	Food(){
		this->r= 50;
		this->y= 100;
	}
	
	void displayFood(){
		ofDrawCircle(this->r, this->y, 10, 10);
	}

};