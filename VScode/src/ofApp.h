/*
	The Autonomous Agent of Future
	Authors: Apoorva & Simran
	© 2019 Apoorva&Simran. All Rights Reserved.
*/

#pragma once

#include "ofMain.h"
#include "agent.h"
#include "ofxGui.h" //Library for timer

class ofApp : public ofBaseApp{

	public:
		Agent A;
		Food meal;
		void setup();
		void update();
		void draw();
		
		//timer
		float startTime;
		bool timerEnd;

		ofxPanel gui;
		ofParameter<float> endTime;



		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
