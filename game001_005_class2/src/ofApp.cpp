#include "ofApp.h"

// バー関連のパラメータ
class Bar {
public:
	ofVec2f size;
	ofVec2f pos;
};

// ボール関連のパラメータ
class Ball {
public:
	float size;
	ofVec2f pos;
	ofVec2f force;
	ofVec2f velocity;
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
};

Bar bar;
Ball ball;
// 失敗したかどうか
bool miss;

//--------------------------------------------------------------
// 初期設定
void ofApp::setup(){
	// バーの位置は画面中央から
	bar.pos = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
	// バーのサイズ
	bar.size = ofVec2f(200, 10);
	
	// ボールのサイズ
	ball.size = 10;
	// ボールの位置はバーの真ん中
	ball.pos = bar.pos;
	ball.pos.y -= ball.size + bar.size.y/2;
	// ボールは静止状態から
	ball.force = ofVec2f(0, 0);
	ball.velocity = ofVec2f(0, 0);
	
	// 失敗していない状態
	miss = false;

	// ofRectの座標指定方式の設定
	ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update(){
	// receiverの0番から-3〜3の範囲で値を受け取る
	float bar_move = receiver.getFloat(0, -3, 3);
	// バーを動かす
	bar.pos.x += bar_move;
	
	// もし失敗していたら
	if(miss) {
		// 落下させる
		ball.setForce(0, 0.3);
	}
	// 失敗していない場合は
	else {
		// バーの動きと逆方向に力がかかる（すべるような動き）
		ball.setForce(-bar_move, 0);
		// 力を更新
		ball.updateForce();
	}
	// 速度を更新
	ball.updateVelocity();
	// 位置を更新
	ball.updatePos();
	
	// もしボールがバーの横幅をはみ出していたら
	if(ball.pos.x < bar.pos.x - bar.size.x/2 || ball.pos.x > bar.pos.x + bar.size.x/2) {
		// 失敗
		miss = true;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	// バーを描画
	ofRect(bar.pos.x, bar.pos.y, bar.size.x, bar.size.y);
	// ボールを描画
	ofCircle(ball.pos.x, ball.pos.y, ball.size);
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
