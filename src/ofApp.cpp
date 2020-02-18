#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableAlphaBlending();
	ofSetFrameRate(60);
	//ofSetBackgroundAuto(true);
	ofSetBackgroundColor(0);



	//ofRotateZDeg(360);


}

//--------------------------------------------------------------
void ofApp::update(){
	//rotate++;


	dotOne.moveDot();
	dotTwo.moveDot();


	for (int i=0; i < dotOne.dotList.size(); i++) {

		for (int j=0; j < dotTwo.dotList.size(); j++) {

			//cout << dotOne.dotList[i] << " " << dotTwo.dotList[i] << endl;
			if (ofDist(dotOne.dotList[i].x, dotOne.dotList[i].y, dotTwo.dotList[j].x, dotTwo.dotList[j].y) <= 1) {
				dotOne.stop();
				dotTwo.stop();
				ofSetBackgroundColor(0, 0, 255);
				cout << "touching!" << endl;
			}
		}
		
	}
	


	/*if (dotOne.dotPos.x == dotTwo.dotPos.x && dotOne.dotPos.y == dotTwo.dotPos.y) {
	if (dotOne.dotList[i] == dotTwo.dotList[j])
	if (dotTwo.dotPos.match(dotOne.dotPos, 1)) {
			dotOne.stop();
			dotTwo.stop();
			ofSetBackgroundColor(0, 0, 255);
			cout << "touching!" << endl;
		}
	if(dotTwo.dotList.any(dotOne.dotList, 1)) {
		dotOne.stop();
		dotTwo.stop();
		ofSetBackgroundColor(0, 0, 255);
		cout << "touching!" << endl;
	}

	}*/
	
	
}
	//https://openframeworks.cc/documentation/math/ofVec2f/#!show_match

	
	// To DO: 
	// If ( current.pos.x = any pos.x in array && current.pos.y = any pos.y in array) {
	//   dotOne.stop()
	//   dotTwo.stop()
	// }

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	
		dotOne.drawDots();
		dotTwo.drawDots();
	
}

void Dot::moveDot()
{
	time = ofGetElapsedTimef();
	//dotPos.x = ofNoise(time*speed + ofRandom(0, 110) + ofRandom(0, 15)) * ofGetWidth(); // creates a field of random dots
	//dotPos.y = ofNoise(time*speed + ofRandom(0, 55) + ofRandom(0, 35)) * ofGetHeight();
	
	//dotPos.x = ofNoise(time*speed + 104.3 + 14.6) * ofGetWidth();
	//dotPos.y = ofNoise(time*speed + 53.3 + 35.2) * ofGetHeight();
	dotPos = ofVec2f((ofNoise(time*speed + 200 + 75) * ofGetWidth()),(ofNoise(time*speed + 35.25+155) * ofGetHeight()/2));
	dotList.push_back(dotPos); // add our step into the list of steps
	currentDotPos.push_back(dotPos);
	

}

void Dot::drawDots() {

	//color = (; // draw dots white with alpha val
	ofSetColor(255, 255, 255, 15);
	for (int i = 0; i < dotList.size(); i++) {
		ofDrawCircle(dotList[i], radius);
	}
}

void Dot::stop()
{
	endPos = dotPos;
	endPos= ofVec2f(dotPos.x, dotPos.y);
	dotList.push_back(endPos); // add our step into the list of steps

}



Dot::Dot()
{
	speed = 0.15;
	radius = 5;
	//dotList.push_back(dotPos);
}

Dot::~Dot()
{
}

void OtherDot::moveDot()
{
	time = ofGetElapsedTimef();
	//dotPos.x = ofNoise(time*speed + ofRandom(0, 110) + ofRandom(0, 15)) * ofGetWidth(); // creates a field of random dots
	//dotPos.y = ofNoise(time*speed + ofRandom(0, 55) + ofRandom(0, 35)) * ofGetHeight();

	//dotPos.x = ofNoise(time*speed + 104.3 + 14.6) * ofGetWidth();
	//dotPos.y = ofNoise(time*speed + 53.3 + 35.2) * ofGetHeight();
	dotPos = ofVec2f((ofNoise(time*speed + 104.3 + 14.6) * ofGetWidth()), (ofNoise(time*speed + 53.3 + 35.25) * ofGetHeight()));
	dotList.push_back(dotPos); // add our step into the list of steps

}

void OtherDot::drawDots()
{
	// draw dots white with alpha val
	ofSetColor(255, 0, 0, 15);
	for (int i = 0; i < dotList.size(); i++) {
		ofDrawCircle(dotList[i], radius);
	}
}
