#include "ofApp.h"

// バー関連のパラメータ
ofVec2f bar_size;
ofVec2f bar_pos;

// ボール関連のパラメータ
float ball_size;
ofVec2f ball_pos;
ofVec2f ball_force;
ofVec2f ball_velocity;

// 失敗したかどうか
bool miss;

//--------------------------------------------------------------
// 初期設定
void ofApp::setup(){
	// バーの位置は画面中央から
	bar_pos.x = ofGetWidth()/2;
	bar_pos.y = ofGetHeight()/2;
	// バーのサイズ
	bar_size.x = 200;
	bar_size.y = 10;
	
	// ボールのサイズ
	ball_size = 10;
	// ボールの位置はバーの真ん中
	ball_pos.x = bar_pos.x;
	ball_pos.y = bar_pos.y - ball_size - bar_size.y/2;
	// ボールは静止状態から
	ball_force.x = 0;
	ball_force.y = 0;
	ball_velocity.x = 0;
	ball_velocity.y = 0;
	
	// 失敗していない状態
	miss = false;

	// ofRectの座標指定方式の設定
	ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update(){
	// receiver0番から-3〜3の範囲で値を受け取る
	float bar_move = receiver.getFloat(0, -3, 3);
	// バーを動かす
	bar_pos.x += bar_move;
	
	// もし失敗していたら
	if(miss) {
		// 落下させる
		ball_force.x = 0;
		ball_force.y = 0.3;
	}
	// 失敗していない場合は
	else {
		// バーの動きと逆方向に力がかかる（すべるような動き）
		ball_force.x = -bar_move;
		ball_force.y = 0;
		// 速度と逆向きに力を加える（摩擦力）
		ball_force.x += -ball_velocity.x*0.98;
		ball_force.y += -ball_velocity.y*0.98;
	}
	// 速度を更新
	ball_velocity.x += ball_force.x;
	ball_velocity.y += ball_force.y;
	// 位置を更新
	ball_pos.x += ball_velocity.x;
	ball_pos.y += ball_velocity.y;
	
	// もしボールがバーの横幅をはみ出していたら
	if(ball_pos.x < bar_pos.x - bar_size.x/2 || ball_pos.x > bar_pos.x + bar_size.x/2) {
		// 失敗
		miss = true;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	// バーを描画
	ofRect(bar_pos.x, bar_pos.y, bar_size.x, bar_size.y);
	// ボールを描画
	ofCircle(ball_pos.x, ball_pos.y, ball_size);
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
