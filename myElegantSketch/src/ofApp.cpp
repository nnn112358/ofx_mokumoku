#include "ofApp.h"
#include "Header.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//ファイルの数
	long nn_max = 0;
	string fnamelist[1000];
	string dir, ff, ext;
	dir = ".\\data\\images\\";
	ext = "jpg";
	get_filelist(dir, fnamelist, nn_max, ext);

	currentFrame = 1;

	ofBackground(255, 255, 255);
	 max_frame = nn_max ;

	//連番がふられた画像を順番に読み込み
	for (int i = 0; i < max_frame; i++) {
		//ファイル名を一時的に格納する文字列
		char char1[1024];

		sprintf(char1, "images/%s", fnamelist[i].c_str());
		myImage_A[i].loadImage(char1);
		cout << char1 << ":read" << endl;

	}

	int width = myImage_A[0].getWidth();
	int height = myImage_A[0].getHeight();


	doFullScreen.addListener(this, &ofApp::setFullScreen);

	bShowHelp = true;


	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	camera.setDistance(400);
	ofSetCircleResolution(3);
	myFbo.allocate(1024, 1024);

	myGlitch.setup(&myFbo);

}

//--------------------------------------------------------------
void ofApp::update(){
	myFbo.begin();
	ofClear(0, 0, 0, 255);
	double scale = 0.5;

	float winW = ofGetWidth(), winH = ofGetHeight();

	float imgW = myImage_A[currentFrame].getWidth();
	float imgH = myImage_A[currentFrame].getHeight();

	float ratioW = winW / imgW,
		ratioH = winH / imgH;

	if (ratioW < ratioH)
		ratioMin = ratioW;
	else
		ratioMin = ratioH;

	myImage_A[currentFrame].setAnchorPercent(0.5, 0.5);
	myImage_A[currentFrame].draw(winW / 2, winH / 2, ratioMin*imgW*scale, ratioMin*imgH*scale);

	myFbo.end();

	//Sleep(100);
}

//--------------------------------------------------------------
void ofApp::draw(){
	//in_image.draw(0, 0);

	//double scale = 0.5;

	//float winW = ofGetWidth(), winH = ofGetHeight();

	//float imgW = myImage_A[currentFrame].getWidth();
	//float imgH = myImage_A[currentFrame].getHeight();

	//float ratioW = winW / imgW,
	//	ratioH = winH / imgH;

	//if (ratioW < ratioH)
	//	ratioMin = ratioW;
	//else
	//	ratioMin = ratioH;

	//myImage_A[currentFrame].setAnchorPercent(0.5, 0.5);
	//myImage_A[currentFrame].draw(winW / 2, winH / 2, ratioMin*imgW*scale, ratioMin*imgH*scale);




	/* Apply effects */
	myGlitch.generateFx();

	/* draw effected view */
	ofSetColor(255);
	myFbo.draw(0, 0);


	/* show information*/
	string info = "";
	info += "1 - 0 : Apply glitch effects.\n";
	info += "q - u : Apply color remap effects.\n";
	info += "L key : Switch 3Dview / 2DImage.\n";
	info += "H key : Hide or show this information.";

	if (bShowHelp) {
		ofSetColor(0, 200);
		ofRect(25, 17, 320, 60);
		ofSetColor(255);
		ofDrawBitmapString(info, 30, 30);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == '1') myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE, true);
	if (key == '2') myGlitch.setFx(OFXPOSTGLITCH_GLOW, true);
	if (key == '3') myGlitch.setFx(OFXPOSTGLITCH_SHAKER, true);
	if (key == '4') myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER, true);
	if (key == '5') myGlitch.setFx(OFXPOSTGLITCH_TWIST, true);
	if (key == '6') myGlitch.setFx(OFXPOSTGLITCH_OUTLINE, true);
	if (key == '7') myGlitch.setFx(OFXPOSTGLITCH_NOISE, true);
	if (key == '8') myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN, true);
	if (key == '9') myGlitch.setFx(OFXPOSTGLITCH_SWELL, true);
	if (key == '0') myGlitch.setFx(OFXPOSTGLITCH_INVERT, true);

		 if (key == 'x') {
			currentFrame++;
			if (currentFrame >= max_frame)currentFrame = 0;
			//page_status = 0;

		}


		 else if (key == 'f') {
			 doFullScreen.set(!doFullScreen.get());
		 }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == '1') myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE, false);
	if (key == '2') myGlitch.setFx(OFXPOSTGLITCH_GLOW, false);
	if (key == '3') myGlitch.setFx(OFXPOSTGLITCH_SHAKER, false);
	if (key == '4') myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER, false);
	if (key == '5') myGlitch.setFx(OFXPOSTGLITCH_TWIST, false);
	if (key == '6') myGlitch.setFx(OFXPOSTGLITCH_OUTLINE, false);
	if (key == '7') myGlitch.setFx(OFXPOSTGLITCH_NOISE, false);
	if (key == '8') myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN, false);
	if (key == '9') myGlitch.setFx(OFXPOSTGLITCH_SWELL, false);
	if (key == '0') myGlitch.setFx(OFXPOSTGLITCH_INVERT, false);
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
