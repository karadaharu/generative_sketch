//
//  circle.cpp
//  sketch4
//
//  Created by knekokz on 2015/01/01.
//
//

#include "circle.h"


void circle::setup(){
    x = ofRandom(800);
    y = ofRandom(800);
    radius = ofRandom(100) + 10;
    linecol.set(ofRandom(255), ofRandom(255), ofRandom(255));
    fillcol.set(ofRandom(255), ofRandom(255), ofRandom(255));
}

void circle::draw(){
    ofNoFill();
    ofSetColor(200,200,0);
    ofCircle(x,y, radius);
    ofFill();
    ofSetColor(0,0,200);
    ofCircle(x,y, 10);
}

