#include "Serial.h"
#include "Dialog.h"
#include "ofUtils.h"

//----------------------------------------------------------------
static bool isDeviceArduino( ofSerialDeviceInfo & A ){
	return ( ofIsStringInString(A.getDeviceName(), "usbserial") ||
		 ofIsStringInString(A.getDeviceName(), "usbmodem") );
}
static string filename = "serialname";

Serial::Serial()
{
	int x = 10;
	int y = 10;
	int w = 100;
	int h = 18;
	int dx = 10;
	input_panel_.setup("input", "input.xml", x, y);
	input_panel_.setSize(w, h);
	for(int i = 0; i < CHANNEL_NUM; ++i) {
		input_panel_.add(input_[i].setup("value"+ofToString(i), 0, 0, 255, w, h));
	}
	x += w+dx;
	offset_panel_.setup("offset", "offset.xml", x, y);
	offset_panel_.setSize(w, h);
	for(int i = 0; i < CHANNEL_NUM; ++i) {
		offset_panel_.add(offset_[i].setup("value"+ofToString(i), 0, -255, 255, w, h));
	}
	x += w+dx;
	scaler_panel_.setup("scaler", "scaler.xml", x, y);
	scaler_panel_.setSize(w, h);
	for(int i = 0; i < CHANNEL_NUM; ++i) {
		scaler_panel_.add(scaler_[i].setup("value"+ofToString(i), 1.f, 0.f, 5.f, w, h));
	}
	x += w+dx;
	value_panel_.setup("output", "output.xml", x, y);
	value_panel_.setSize(w, h);
	for(int i = 0; i < CHANNEL_NUM; ++i) {
		value_panel_.add(value_[i].setup("value"+ofToString(i), 0, 0, 255, w, h));
	}
	
	offset_panel_.loadFromFile("offset.xml");
	scaler_panel_.loadFromFile("scaler.xml");
}
void Serial::setup()
{
	if(serial_.isInitialized()) {
		close();
	}
	vector<ofSerialDeviceInfo> list = serial_.getDeviceList();
	vector<string> namelist;
	string defaultname = ofBufferFromFile(filename);
	for(int i = 0; i < list.size(); ++i) {
		if(isDeviceArduino(list[i])) {
			if(defaultname == list[i].getDeviceName()) {
				serial_.setup(defaultname, 9600);
				return;
			}
			namelist.push_back(list[i].getDeviceName());
		}
	}
	if(!namelist.empty()) {
		string selected = systemComboBoxSelector("select device", namelist);
		serial_.setup(selected, 9600);
		ofBuffer file(selected);
		ofBufferToFile(filename, file);
	}
}
void Serial::close()
{
	serial_.close();
}
void Serial::update()
{
	if(serial_.isInitialized()) {
		while(true) {
			int index = serial_.readByte();
			if(index < 0 || CHANNEL_NUM <= index) {
				break;
			}
			int data = serial_.readByte();
			if(data < 0) {
				break;
			}
			input_[index] = data;
		}
	}
	for(int i = 0; i < CHANNEL_NUM; ++i) {
		value_[i] = (input_[i]+offset_[i])*scaler_[i];
	}
}
void Serial::draw()
{
	input_panel_.draw();
	offset_panel_.draw();
	scaler_panel_.draw();
	value_panel_.draw();
}
int Serial::getInt(int index, int min, int max)
{
	return ofMap(value_[index], 0, 255, min, max, true);
}
float Serial::getFloat(int index, float min, float max)
{
	return ofMap(value_[index], 0, 255, min, max, true);
}
bool Serial::getBool(int index, int threshold)
{
	return value_[index] >= threshold;
}
