#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    once = false;
    ofSetBackgroundAuto(false);
    
    ofSetFrameRate(20);
    
    xstart = ofRandom(10);
    ystart = ofRandom(10);
    
    xStartNoise = ofRandom(10);
    yStartNoise = ofRandom(10);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    if(once){
        drawOnce();
    }
}

void ofApp::drawOnce(){
    ofBackground(235, 250, 253);

    xStartNoise += 0.01;
    yStartNoise += 0.01;
    
    ystart += ofNoise(xStartNoise) * 0.5 - 0.25;
    xstart += ofNoise(yStartNoise) * 0.5 - 0.25;
    
    ynoise = ystart;
    xnoise = xstart;
    
    cnoise = ofRandom(255);
    
    int skip = 10;
    for(int y = 0; y < ofGetHeight(); y+=skip){
        ynoise += 0.02;
        xnoise = xstart;
        for(int x=0; x<ofGetWidth(); x+=skip){
            xnoise += 0.02;
            cnoise += 0.03;
            int alph = int(ofNoise(xnoise, ynoise) * 100);
            ofPushMatrix();
            ofTranslate(x, y);
            ofRotateZ(ofNoise(xnoise,ynoise)*360);
            ofSetColor(0, (x+y)%255, ofNoise(xnoise) * 100 + 50,alph);
            ofTranslate(-x, -y);
            ofLine(x, y, x+ofNoise(cnoise)*100+100, y+ofNoise(cnoise)*100+100);
            ofPopMatrix();

        }
    }
    
    once = false;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='a'){
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
