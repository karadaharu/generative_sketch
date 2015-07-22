#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    float x,y;
    float radius;
    float radiusNoise;
    float lastx, lasty;
    float x1, y1, x2, y2;
    bool once;
    float angleNoise;
    float angle;
    float angleJump;
    int angleSwitch;
    float alpha;
    ofFbo mfbo;
    void drawCirle();
    float cx, cy;
    float cNoise;
};
