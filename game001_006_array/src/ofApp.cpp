#include "ofApp.h"

// バー関連のパラメータ
class Bar {
public:
	ofVec2f size;
	ofVec2f pos;
	Bar() {
		size = ofVec2f(200,10);
	}
	void setPos(float x, float y) {
		pos.set(x,y);
	}
	void move(float x, float y) {
		pos += ofVec2f(x,y);
	}
	void draw() {
		ofRect(pos.x, pos.y, size.x, size.y);
	}
};

// ボール関連のパラメータ
class Ball {
public:
	float size;
	ofVec2f pos;
	ofVec2f force;
	ofVec2f velocity;
	bool miss;
	// 初期設定
	Ball() {
		size = 10;
		force = ofVec2f(0, 0);
		velocity = ofVec2f(0, 0);
	}
	void setPos(float x, float y) {
		pos.set(x,y);
	}
	void setForce(float x, float y) {
		force.set(x,y);
	}
	void updateForce() {
		// 速度と逆向きに力を加える（摩擦力）
		force += -velocity*0.98;
	}
	void updateVelocity() {
		velocity += force;
	}
	void updatePos() {
		pos += velocity;
	}
	// update〜系関数をまとめる
	void update(float bar_move) {
		// もし失敗していたら
		if(miss) {
			// 落下させる
			setForce(0, 0.3);
		}
		// 失敗していない場合は
		else {
			// バーの動きと逆方向に力がかかる（すべるような動き）
			setForce(-bar_move, 0);
			updateForce();
		}
		updateVelocity();
		updatePos();
	}
	void draw() {
		ofCircle(pos.x, pos.y, size);
	}
};

const int BALL_NUM = 5;
Bar bar;
Ball ball[BALL_NUM];

//--------------------------------------------------------------
// 初期設定
void ofApp::setup(){
	// バーの初期位置
	bar.setPos(ofGetWidth()/2, ofGetHeight()/2);
	// ボールの初期位置
	for(int i = 0; i < BALL_NUM; ++i) {
		ball[i].setPos(bar.pos.x+ofRandom(-bar.size.x/2.f, bar.size.x/2.f), bar.pos.y - (ball[i].size + bar.size.y/2));
	}
	
	// ofRectの座標指定方式の設定
	ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update(){
	// receiverの0番から-3〜3の範囲で値を受け取る
	float bar_move = receiver.getFloat(0, -3, 3);
	// バーを動かす
	bar.move(bar_move, 0);
	
	// ボールの更新
	for(int i = 0; i < BALL_NUM; ++i) {
		ball[i].update(bar_move);
	}
	
	// もしボールがバーの横幅をはみ出していたら
	for(int i = 0; i < BALL_NUM; ++i) {
		if(ball[i].pos.x < bar.pos.x - bar.size.x/2 || ball[i].pos.x > bar.pos.x + bar.size.x/2) {
			// 失敗
			ball[i].miss = true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	// バーを描画
	bar.draw();
	// ボールを描画
	for(int i = 0; i < BALL_NUM; ++i) {
		ball[i].draw();
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
