#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	const int DEFAULT_X = 10;
	const int DEFAULT_Y = 10;
	int x = DEFAULT_X;
	int y = DEFAULT_X;
	int dx = 100;
	int dy = 10;
	ofDrawBitmapString("int", x, y);
	y += dy;
	for(int i = 0; i < receiver_.size(); ++i) {
		ofDrawBitmapString(ofToString(receiver_.getInt(i)), x, y);
		y += dy;
	}
	x += dx;
	y = DEFAULT_Y;
	ofDrawBitmapString("float", x, y);
	y += dy;
	for(int i = 0; i < receiver_.size(); ++i) {
		ofDrawBitmapString(ofToString(receiver_.getFloat(i)), x, y);
		y += dy;
	}
	x += dx;
	y = DEFAULT_Y;
	ofDrawBitmapString("bool", x, y);
	y += dy;
	for(int i = 0; i < receiver_.size(); ++i) {
		ofDrawBitmapString(ofToString(receiver_.getBool(i)?"true":"false"), x, y);
		y += dy;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
