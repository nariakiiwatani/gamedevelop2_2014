#pragma once

#include "ofSerial.h"
#include "ofxGui.h"

class Serial
{
public:
	Serial();
	void setup();
	void close();
	void update();
	void draw();
	int size() { return CHANNEL_NUM; }
	int getInt(int index, int min=0, int max=255);
	float getFloat(int index, float min=0, float max=1);
	bool getBool(int index, int threshold=128);
private:
	static const int CHANNEL_NUM = 20;
	ofSerial serial_;
	ofxPanel value_panel_, scaler_panel_, input_panel_, offset_panel_;
	ofxSlider<float> scaler_[CHANNEL_NUM];
	ofxSlider<int> offset_[CHANNEL_NUM];
	ofxSlider<int> value_[CHANNEL_NUM];
	ofxSlider<int> input_[CHANNEL_NUM];
};