#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
    
    float xstart, ystart, zstart;
    float xnoise, ynoise, znoise;
    float lastx, lasty, lastz;
    void drawOnce();
    bool once;
    ofSpherePrimitive sphere;
    ofVboMesh mesh;
    
    ofCamera cam;
    ofVec3f camPos;
    ofVec3f lookVec;
    ofxVec3Slider camPosTest;
    ofxVec3Slider lookPos;
    ofxPanel gui;
    ofxFloatSlider rad;
    ofxFloatSlider theta;
    ofxFloatSlider phai;
    ofxVec3Slider upVector;
    ofxFloatSlider sstep;
    ofxFloatSlider tstep;
    bool drawgui;
};
