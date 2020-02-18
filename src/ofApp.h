#pragma once

#include "ofMain.h"
class Dot {
public:
	void moveDot();
	void drawDots();
	void stop();
	Dot();
	~Dot();

	//vars
	int radius;
	//float xPos, yPos;
	vector<ofVec3f> currentDotPos;
	ofVec3f endPos;

	ofColor color;
	ofPoint dotPos;
	vector<ofVec3f>  dotList;
	float speed;
	float time;
};

//Using inheritance to make a child dot, i.e. the other dot with altered methods
class OtherDot : public Dot {
public:
	virtual void moveDot();
	virtual void drawDots();
	
};
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		float lerpAmount;
		float rotate;
		Dot dotOne;
		OtherDot dotTwo;

};