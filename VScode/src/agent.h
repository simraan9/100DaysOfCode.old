#pragma once

class Agent {
	private:
		int x;
		int y;
		int r;
		float theta;

		int x1;
		int y1;
		int x2;
		int y2;
		int x3;
		int y3;


	public:

	Agent() {
		x = 100;
		y = 100;
		theta = 0;
		r = 20;
	}

	Agent(int x, int y,float theta) {
		this->x = 100;
		this->y = 100;
		this->theta = 0;
		r = 20;
	}
	int get_x() {
		return x;
	}
	int get_y() {
		return y;
	}
	void display() {
		int x1 = x + (r*(cos(theta)));
		int y1 = y + (r*(sin(theta)));
		int x2 = x + (r*(cos(theta + 2 * (PI / 3) + (PI / 8))));
		int y2 = y + (r*(sin(theta + 2 * (PI / 3) + (PI / 8))));
		int x3 = x + (r*(cos(theta + (-4)*(PI / 6) - (PI / 8))));
		int y3 = y + (r*(sin(theta + (-4)*(PI / 6) - (PI / 8))));
		
		ofDrawTriangle(x1, y1, x2, y2, x3, y3);

	}


};