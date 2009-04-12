#ifndef _OF_VIDEO_GRABBER_APP
#define _OF_VIDEO_GRABBER_APP

#include "ofMain.h"

class OFVideoGrabberApp : public ofSimpleApp{
	
public:
	void setup();
	void update();
	void draw();
	void exit();
	void keyPressed(int key);
	void keyReleased(int key);
    
	ofVideoGrabber videoGrabber;
    ofTexture filteredTexture;
    unsigned char* filterBuffer;
	
private:
	int camWidth, camHeight;
	int f_down;
};

#endif

