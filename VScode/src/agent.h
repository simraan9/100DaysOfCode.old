/*
 The Autonomous Agent of Future
 Authors: Apoorva & Simran
 © 2019 Apoorva&Simran. All Rights Reserved.
 */

#pragma once
using namespace std;

/*
This class initialises a timer, whose values can be captured any time by methods in other classes.
*/
class Time { 
public:
	float currentTime;

	void display() {
		ofDrawBitmapString("Class Time: " + to_string(currentTime) , 10, 10);
	}

	Time() {
		currentTime= ofGetElapsedTimef();
	}
};


/*
This class has all methods that make an obstacle. 
*/

class Obstacle {
private:
	int x;
	int y;

public:
	int time;
	int start;
	int end;

	void display() {				 //displays obstacle
		ofSetColor(100, 150, 100);
		ofDrawBitmapString("Time: " + to_string(start) + "  End" + to_string(end) + "s", 10, 380);
		

		if (controlDisplay() == 0) {
			ofDrawRectangle(x, y - 15, 10, 30);
		}
	}
	
	
	int get_x() {					 // returns x coordinate for obstacle
		return x;
	}
	
		
	void respawn() {				// resets the timer and gives new position to the obstacle
		x = ofRandom(20, 380);
		y = 200;
		ofResetElapsedTimeCounter();
	}

	int controlDisplay() {			//checks if time>10 seconds, returns a value to control obstacle display
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

	void appear() {					// picks time between 5-30 seconds, respawns the obstacle after
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


/*
This class has all methods that make food.
*/
class Food {
private:
	int r;
	int y;

public:

	void display() {	//displays food
		ofSetColor(255, 0, 0);
		ofDrawCircle(r, y, 5, 5);
	}

	void reset() {		//resets x coordinate for food
		r = ofRandom(50, 350);
	}

	int get_r() {		//returns x coordinate for food
		return r;
	}

	Food() {
		this->r = ofRandom(50, 350);
		this->y = 200;
	}



};

/*
This class has all methods that make posion.
*/

class Poison {

private:

	int p;
	int y;

public:

	Poison() {
		this->p = ofRandom(50, 350);
		this->y = 200;
	}

	void reset() {			//resets x position of poison
		p = ofRandom(50, 350);
	}

	int get_p() {			//returns x cooridinate for poison
		return p;
	}

	void display() {		//displays poison
		ofNoFill();
		ofSetColor(255, 0, 0);
		ofDrawCircle(p, y, 5, 5);
		ofFill();
	}

};


/*
This class has all methods that make an Agent.
*/

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
		startTime = ofGetElapsedTimeMillis();
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
		startTime = ofGetElapsedTimeMillis();
		estPos = 0;
		returnStatus = 0;
	}



	int get_x() {				//returns x coordinate for agent
		return x;
	}

	int get_y() {				//returns y coordinate for agent
		return y;
	}

	int get_energy() {			//returns energy for agent
		return energy;
	}

	void display() {			//checks direction before displaying agent

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

	void displayText() {			//displays text related to agent
		
		ofSetColor(255, 255, 255);
		ofDrawBitmapString("Total Time: " + to_string(t1 / 1000) + "s", 10, 300);
		ofDrawBitmapString("Average Time: " + to_string(avgTime / 1000) + "s", 10, 320);
		ofDrawBitmapString("Last cycle Time: " + to_string(cycleTime / 1000) + "s", 10, 340);
		
		if (rest() == 0) {			//displays feedback for rest
			ofSetColor(255, 255, 0);
			ofDrawBitmapString("ZZzz.. ", 250, 120);
		}

	}


	int flip() {					//reverses direction

		if (direction == 1) {
			direction = 0;
		}
		else if (direction == 0) {
			direction = 1;
		}
		return direction;
	}

	int rest() {					//makes the agent inactive if energy>=900
		if (energy >= 900) {
			return 0;
		}
		return 1;
	}

	void move() {					//makes agent move
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

	void displayTime() {		//displays time on canvas 
		ofDrawBitmapString("Time " + to_string(startTime), 10, 250);
	}

	void resetTime() {			//resets time for agent
		startTime = ofGetElapsedTimeMillis();
	}

	void countCycleTime() {		//calculates total, cycle and average time for agent to eat
		t1 = startTime;
		cycleTime = t1 - t2;
		totalTime = totalTime + cycleTime;
		avgTime = totalTime / count;
		t2 = t1;
		count = count + 1;
	}

	void eat(Food &meal) {		//consumes food, compares own position with food's. Increases energy and eat count; and resets time and food position after.
		if (x == meal.get_r()) {
			countCycleTime();
			eatCount = eatCount + 1;
			meal.reset();
			resetTime();
			energy = energy + 50;
		}

	}

	void eatPoison(Poison &pill) { //consumes poison, compares own position with it, reduces energy on eating and resets position for poison
		if (x == pill.get_p()) {
			energy = energy - 100;
			pill.reset();
		}

	}


	void respawn() {			//resets position for agent
		x = ofRandom(0, 400);

	}

	void die() {				//kills agent if energy < 0, creates new agent in place, increases death count
		if (energy <= 0) {
			respawn();
			energy = 1000;
			deathCount = deathCount + 1;
		}
	}

	int checkJumps(Food &meal, int pos1, int pos2) {	//this method checks for the presence of another object between two positions, returns estimated position of the object

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

	//This function checks if the food is within 50px ahead of his nose. Returns estimated position

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
		else if ((checkJumps(meal, x - 50, x) != 0) && direction == 0) { //checks for 50px awareness
			if ((checkJumps(meal, x - (energy / 100), x) != 0) && direction == 0) //checks for speed awareness
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



	//This function checks if the food is within 30px ahead and 15 px behind his nose. Returns estimated position

	int smell(Food meal) {
		if ((checkJumps(meal, x, x + 30) != 0) && direction == 1) { //checks for 30px awareness
			if ((checkJumps(meal, x, (x + (energy / 100))) != 0) && direction == 1)	//checks for speed awareness
				if (energy <= 900) {
					eat(meal);
				}
		}
		else if ((checkJumps(meal, x - 30, x) != 0) && direction == 0) {  //checks for 30px awareness
			if ((checkJumps(meal, x - (energy / 100), x) != 0) && direction == 0)	//checks for speed awareness
				if (energy <= 900) {
					eat(meal);
				}

			if ((checkJumps(meal, x - 15 + radius, x + radius) != 0) && direction == 1) {	//checks for -15px awareness
				if ((checkJumps(meal, x, (x + (energy / 100))) != 0) && direction == 1)		//checks for speed awareness
					if (energy <= 900) {
						eat(meal);
					}
			}
			else if ((checkJumps(meal, x + radius, x - 15 + radius) != 0) && direction == 0) { //checks for -15px awareness
				if ((checkJumps(meal, x - (energy / 100), x) != 0) && direction == 0) //checks for speed awareness
					if (energy <= 900) {
						eat(meal);
					}
			}
			return estPos;
		}
	}


	//This function compares agent position with the obstacle's, and returns int returnStatus which tells agent whether or not to wait

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


	//This function uses a timer to wait if time<3s and flip if time>3s

	int wait() {
		int myTimerStart = ofGetElapsedTimeMillis();

		if (myTimerStart <= 3000) {
			return 0;
		}
		else if (myTimerStart > 3000) {
			flip();
		}
	}

	//This function checks the first and last 50px of the canvas with the see(); to flip if there is no obstacle in the area. 

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
