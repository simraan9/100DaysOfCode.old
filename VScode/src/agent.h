#pragma once


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

public:
	int eatCount;
	float energy;
	int deathCount;

	Agent() {
		x = 100;
		y = 200;
		theta = 0;
		radius = 20;
		direction = 1;
		eatCount = 0;
		energy = 100;
		deathCount = 0;
	}

	Agent(int x, int y, float theta) {
		this->x = x;
		this->y = y;
		this->theta = 0;
		radius = 20;
		direction = 1;
		eatCount = 0;
		energy = 100;
		deathCount = 0;
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

	void eat(Food &meal) {
	
		if (x == meal.get_r()) {
			eatCount = eatCount + 1;
			meal.reset();
			energy = energy + 50;
		}
		
	}
	void respawn() {
		x = ofRandom(0, 400);

	}

	void die() {
		if (energy <= 0) {
			respawn();
			energy = 100;
			deathCount = deathCount + 1;
	}
	}
};

