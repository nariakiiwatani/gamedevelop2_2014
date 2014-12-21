#include "ofApp.h"

// バー関連のパラメータ
float bar_size_x, bar_size_y;
float bar_pos_x, bar_pos_y;

// ボール関連のパラメータ
float ball_size;
float ball_pos_x, ball_pos_y;
float ball_force_x, ball_force_y;
float ball_velocity_x, ball_velocity_y;

// 失敗したかどうか
bool miss;

//--------------------------------------------------------------
// 初期設定
void ofApp::setup(){
	// バーの位置は画面中央から
	bar_pos_x = ofGetWidth()/2;
	bar_pos_y = ofGetHeight()/2;
	// バーのサイズ
	bar_size_x = 200;
	bar_size_y = 10;
	
	// ボールのサイズ
	ball_size = 10;
	// ボールの位置はバーの真ん中
	ball_pos_x = bar_pos_x;
	ball_pos_y = bar_pos_y - ball_size - bar_size_y/2;
	// ボールは静止状態から
	ball_force_x = 0;
	ball_force_y = 0;
	ball_velocity_x = 0;
	ball_velocity_y = 0;
	
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
	bar_pos_x += bar_move;
	
	// もし失敗していたら
	if(miss) {
		// 落下させる
		ball_force_x = 0;
		ball_force_y = 0.3;
	}
	// 失敗していない場合は
	else {
		// バーの動きと逆方向に力がかかる（すべるような動き）
		ball_force_x = -bar_move;
		ball_force_y = 0;
		// 速度と逆向きに力を加える（摩擦力）
		ball_force_x += -ball_velocity_x*0.98;
		ball_force_y += -ball_velocity_y*0.98;
	}
	// 速度を更新
	ball_velocity_x += ball_force_x;
	ball_velocity_y += ball_force_y;
	// 位置を更新
	ball_pos_x += ball_velocity_x;
	ball_pos_y += ball_velocity_y;
	
	// もしボールがバーの横幅をはみ出していたら
	if(ball_pos_x < bar_pos_x - bar_size_x/2 || ball_pos_x > bar_pos_x + bar_size_x/2) {
		// 失敗
		miss = true;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	// バーを描画
	ofRect(bar_pos_x, bar_pos_y, bar_size_x, bar_size_y);
	// ボールを描画
	ofCircle(ball_pos_x, ball_pos_y, ball_size);
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
