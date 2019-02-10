/*
	The Autonomous Agent of Future
	Authors: Apoorva & Simran
	© 2019 Apoorva&Simran. All Rights Reserved.
*/

#pragma once

#include "ofMain.h"
#include "agent.h"


class ofApp : public ofBaseApp{

	public:
		Agent A;
		Food meal;
		//Timer TimeCount;
		void setup();
		void update();
		void draw();
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
