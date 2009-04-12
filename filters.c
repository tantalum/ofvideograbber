#include "filters.h"

void convert_to_greyscale(unsigned char* pixels, int width, int height, unsigned char* buffer){
	/*
	 * The idea here is simple.. Juast average out the rgb values for the greyscale
	 */
	for(int i = 0; i < width*height; i++){
		int j = i*3;
		unsigned int sum = (unsigned int)(pixels[j] + pixels[j+1] + pixels[j+2]);
		buffer[i] = (unsigned char)(sum/3);
	}
}

/*
 * Algorithm thanks to: http://www.pages.drexel.edu/~weg22/edge.html
 */
void edge_detect(unsigned char* pixels, int width, int height, unsigned char* buffer){
	unsigned char GX[3][3];
	unsigned char GY[3][3];
	/* 3x3 GX Sobel mask.  Ref: www.cee.hw.ac.uk/hipr/html/sobel.html */
	GX[0][0] = -1; GX[0][1] = 0; GX[0][2] = 1;
	GX[1][0] = -2; GX[1][1] = 0; GX[1][2] = 2;
	GX[2][0] = -1; GX[2][1] = 0; GX[2][2] = 1;
	
	/* 3x3 GY Sobel mask.  Ref: www.cee.hw.ac.uk/hipr/html/sobel.html */
	GY[0][0] =  1; GY[0][1] =  2; GY[0][2] =  1;
	GY[1][0] =  0; GY[1][1] =  0; GY[1][2] =  0;
	GY[2][0] = -1; GY[2][1] = -2; GY[2][2] = -1;
	
    int x, y;
    int sumX, sumY, sum;
	int i, j;
	/*
	 * This loop implements a weighted mean (You can google that term).
	 * The value for the pixel at (x,y) is average of value of the surrounding pixels 
	 * multipiled by its (the surrounding pixels) weight from the mask
	 */
    for(y=0; y < height; y++){
		for(x=0; x < width; x++){
			sumX = 0;
			sumY = 0;
			if(y==0  || y == (width -1)){
				sum = 0;
			}else if(x == 0 || (x == width - 1)){
				sum = 0;
			}else{
				for(i=-1; i<=1;i++){
					for(j=-1; j<=1; j++){
						sumX = sumX + (int)( (*(pixels + x + i + (y+j)*width)) + GX[i+1][j+1]);
					}												
				}
				for(i=-1; i<=1; i++){
					for(j=0; j<=1; j++){
						sumY = sumY + (int) ( (*(pixels + x + i + (y+j)*width)) * GY[i+1][j+1]);
					}
				}
				sum = abs(sumX)+abs(sumY);
			}
			buffer[x+(y*width)] = (char)sum;
		}
	}
}
