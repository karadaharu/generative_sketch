#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    once = true;
//    ofSetBackgroundAuto(false);
    mesh.setMode(OF_PRIMITIVE_LINES);
    
    xstart = ofRandom(20);
    ystart = ofRandom(20);
    zstart = ofRandom(20);
    xnoise = xstart;
    ynoise = ystart;
    znoise = zstart;
    
    sphere.set(5, 5);
    
    //位置セット
    cam.setPosition(ofGetWidth()/2, ofGetHeight()/2, -100);
    
    //どこを見るのか
    lookVec = ofVec3f(0,0,0);
    
    //GUI
    drawgui = true;
    gui.setup();
    gui.add(lookPos.setup("View Vector", ofVec3f(0,0,0),ofVec3f(-1000, -1000, -1000), ofVec3f(1000,1000,1000)));
    gui.add(rad.setup("view distance",500.0,0.0001,1000.0));
    gui.add(theta.setup("Theta",45.0, 0.0001, 180.0));
    gui.add(phai.setup("Phai",0.0001, 0.0001, 360.0));
    gui.add(sstep.setup("s step",1, 0.1, 180));
    gui.add(tstep.setup("t step",1, 0.01, 10));
}

//--------------------------------------------------------------
void ofApp::update(){

    camPos.y = cos(theta * 2 * M_PI / 360.0) * rad;
    camPos.z = cos(phai * 2 * M_PI / 360.0) * sin(theta * 2 * M_PI / 360.0) * rad;
    camPos.x = sin(phai * 2 * M_PI / 360.0) * sin(theta * 2 * M_PI / 360.0) * rad;
    
    cam.setPosition(camPos);
    cam.lookAt(lookPos);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    if(drawgui){
        gui.draw();
    }
    
    
    cam.begin();
    if(once){

        drawOnce();
//        once = false;
    }
    mesh.draw();
    cam.end();
}

void ofApp::drawOnce(){
    mesh.clearVertices();
    mesh.clearIndices();
    float s = 0;
    float t = 0;
    float radius = 200;
    
    lastx = 0;
    lasty = 0;
    lastz = 0;
    ofSetColor(255,255,255);
    
    xstart += 0.01;
    xnoise = xstart;
    
    int cnt = 0;
    while (t < 180){
        s += sstep;
        t += tstep;
        float radianS = ofDegToRad(s);
        float radianT = ofDegToRad(t);
        
        radius += ofNoise(xnoise)*3 - 1.5;
        xnoise += 0.4;
        
        float thisx = 0 + (radius * cos(radianS) * sin(radianT));
        float thisy = 0 + (radius * sin(radianS) * sin(radianT));
        float thisz = 0 + (radius * cos(radianT));
        
//        if(lastx != 0 ){
//            ofLine(thisx, thisy, thisz, lastx, lasty, lastz);
//        }
        
//        ofSetColor(200, 200, 200);
//        sphere.setPosition(thisx, thisy, thisz);
//        sphere.draw();
        
        ofVec3f thispos(thisx, thisy, thisz);
        mesh.addVertex(thispos);
        mesh.addColor(ofFloatColor(0.5,0.8,0.7));
//        mesh.addIndex(cnt++);
//        lastx = thisx;
//        lasty = thisy;
//        lastz = thisz;
    }

    
    int numver = mesh.getNumVertices();
    for(int i = 0; i < numver; i++){
        mesh.addIndex(i);
        if(i != numver -1){
            mesh.addIndex(i+1);
        }
        int randind = i + ofRandom(10) - 5;
        if(randind >= numver){
            randind = randind - numver;
        }
        if(randind < 0){
            randind = 0 - randind;
        }
        mesh.addIndex(randind);
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'a'){
        once = true;
    }
    if(key=='f'){
        drawgui =  !drawgui;
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
