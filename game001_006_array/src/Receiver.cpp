//
//  Receiver.cpp
//  SimpleReceiver
//
//  Created by Iwatani Nariaki on 2014/11/22.
//
//

#include "Receiver.h"

Receiver::Receiver()
{
	resize(20);
	osc_.setup(12345);
	ofAddListener(ofEvents().update, this, &Receiver::update);
}
Receiver::~Receiver()
{
	ofRemoveListener(ofEvents().update, this, &Receiver::update);
}
void Receiver::update(ofEventArgs &args)
{
	while(osc_.hasWaitingMessages()) {
		ofxOscMessage msg;
		osc_.getNextMessage(&msg);
		const string &address = msg.getAddress();
		if(address == "/serial") {
			int index = msg.getArgAsInt32(0);
			if(index < 0 || data_.size() <= index) {
				continue;
			}
			data_[index] = msg.getArgAsInt32(1);
		}
	}
}
void Receiver::resize(int size)
{
	data_.resize(size);
}
int Receiver::size()
{
	return data_.size();
}
int Receiver::getInt(int index, int min, int max)
{
	return ofMap(data_[index], 0, 255, min, max, true);
}
float Receiver::getFloat(int index, float min, float max)
{
	return ofMap(data_[index], 0, 255, min, max, true);
}
bool Receiver::getBool(int index, int threshold)
{
	return data_[index] >= threshold;
}
