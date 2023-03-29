#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetLineWidth(1.5);
	ofNoFill();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {


	auto span = 30;
	for (int x = 0; x <= 720; x += span) {

		for (int i = 0; i < 8; i++) {
		
			auto y = ofMap(ofNoise(x * 0.003 + (ofGetFrameNum() - i * 10) * 0.008), 0, 1, 0, 720);
			auto size = ofMap(i, 0, 5, span, span * 0.1);
			ofSetColor(255, ofMap(i, 0, 5, 255, 0));
			ofDrawRectangle(x, y, size, size);
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}