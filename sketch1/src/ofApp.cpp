#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofSetFrameRate(10);
    radius = 10;
    once = false;
    angleJump = 10;
    mfbo.allocate(800, 400);
    mfbo.begin();
    mfbo.end();
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
//    ofBackground(255, 255, 255);
    //if (once) {
        drawCirle();
    //}
}

void ofApp::drawCirle(){
    ofBackground(255, 255, 255);
    radius = 700;

    
    radiusNoise = ofRandom(10);
    angle = 5;
    angleNoise = ofRandom(20);
    angleSwitch = 1;
    alpha = ofRandom(255);
    
    cx = 0;
    cy = 0;
    cNoise = ofRandom(10);
    
    lastx = 0;
    lasty = 10;
    for(float ang = 0; ang< 360; ang+= 0.3){
        radiusNoise += 0.04;
        float thisRadius = radius + ofNoise(radiusNoise) * 200 - 100;
        
        cNoise += 0.04;
        cx = ofNoise(cNoise) * 200 - 100;
        cy = ofNoise(cNoise) * 200 - 100;
        
        if(ofRandom(1) > 0.99){
            angleSwitch = -1 * angleSwitch;
        }
        angle +=  angleSwitch * 0.3;
        
        angleNoise += 0.03;
        if(ofRandom(1) > 0.99){
            angle += angleJump;
            cout << "jump" << endl;
        }
        angle += ofNoise(angleNoise) * 1 - 0.5;

        float rad = 2 * PI * angle / 360;
        
        x1 = cx + thisRadius * cos(rad);
        y1 = cy + thisRadius * sin(rad);

        float ops = rad + PI;
        x2 = cx + thisRadius * cos(ops);
        y2 = cy + thisRadius * sin(ops);
        
        ofSetColor(10 + alpha * 0.1, 10, 10 + alpha * 0.8, alpha);
        
        alpha += 0.5;
        if(alpha > 50){
            alpha = ofRandom(50);
        }
        ofLine(x1, y1, x2, y2);
//        ofLine(x1, y1, 0, 0);
        radius += 0.1;
    }
    once = false;

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == 'a'){
         once = true;   
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
