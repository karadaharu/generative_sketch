//
//  circle.h
//  sketch4
//
//  Created by knekokz on 2015/01/01.
//
//

#ifndef __sketch4__circle__
#define __sketch4__circle__

#include <stdio.h>
#include "ofMain.h"

class circle{
public:
    float x,y;
    float radius;
    ofColor fillcol, linecol;
    void draw();
    void setup();
};


#endif /* defined(__sketch4__circle__) */
