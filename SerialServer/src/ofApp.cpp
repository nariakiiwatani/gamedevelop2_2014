#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	serial_.setup();
	osc_.setup("localhost", 12345);
}

//--------------------------------------------------------------
void ofApp::update(){
	serial_.update();
	for(int i = 0; i < serial_.size(); ++i) {
		ofxOscMessage msg;
		msg.setAddress("/serial");
		msg.addIntArg(i);
		msg.addIntArg(serial_.getInt(i));
		osc_.sendMessage(msg);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	serial_.draw();
}

//--------------------------------------------------------------
void ofApp::exit(){
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
