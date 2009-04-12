/*
 *  filters.h
 *  OFVideoGrabber
 *
 *  Created by Nabil Alsharif on 3/15/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __FILTERS_H
#define __FILTERS_H

extern void edge_detect(unsigned char* pixels, int width, int height, unsigned char* buffer);
extern void convert_to_greyscale(unsigned char* pixels, int width, int height, unsigned char* buffer);
extern void gaussian_smooth(unsigned char* pixels, int width, int height, unsigned char* buffer);
#include "filters.c"
#endif