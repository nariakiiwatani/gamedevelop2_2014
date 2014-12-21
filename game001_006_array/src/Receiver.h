#pragma once

#include "ofUtils.h"
#include "ofxOscReceiver.h"

class Receiver
{
public:
	Receiver();
	~Receiver();
	void resize(int size);
	int size();
	int getInt(int index, int min=0, int max=255);
	float getFloat(int index, float min=0, float max=1);
	bool getBool(int index, int threshold=128);
private:
	void update(ofEventArgs &args);
	vector<int> data_;
	ofxOscReceiver osc_;
};