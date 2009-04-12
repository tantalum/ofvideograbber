/*
 *  OFVideoGrabberApp.cpp
 *  OFVideoGrabber
 *
 *  Created by Nabil Alsharif on 2/22/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "OFVideoGrabberApp.h"
#include "filters.h"

void OFVideoGrabberApp::setup(){
	camWidth = 400;
	camHeight = 320;
	f_down = 0;
	videoGrabber.initGrabber(camWidth, camHeight);
    filterBuffer = new unsigned char[camWidth*camHeight*3];
    filteredTexture.allocate(camWidth, camHeight, GL_LUMINANCE);
}

void OFVideoGrabberApp::update(){
	unsigned char *buffer = (unsigned char*)malloc(camWidth*camHeight);
	ofBackground(80, 80, 80);
	videoGrabber.grabFrame();
    if(videoGrabber.isFrameNew()){
        unsigned char* pixels = videoGrabber.getPixels();
		convert_to_greyscale(pixels, camWidth, camHeight, buffer);
		edge_detect(buffer, camWidth, camHeight, filterBuffer);
        filteredTexture.loadData(filterBuffer, camWidth, camHeight, GL_LUMINANCE);
    }
	free(buffer);
}

void OFVideoGrabberApp::draw(){
    filteredTexture.draw(0, 0, ofGetWidth(), ofGetHeight());
}

void OFVideoGrabberApp::exit(){ 
    delete filterBuffer;
}

void OFVideoGrabberApp::keyPressed(int key){
	if(key == 'f'){
		if(!f_down){
			ofToggleFullscreen();
		}
		f_down = 1;
	}
}

void OFVideoGrabberApp::keyReleased(int key){
	if(key == 'f'){
		f_down = 0;
	}
}