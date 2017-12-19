#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>

#include "ofMain.h"
#include "ofxPostGlitch.h"


#define FRAMENUM 300 //ì«Ç›çûÇﬁâÊëúÇÃñáêî

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		bool			bShowHelp;

		ofImage in_image;
		ofImage myImage_A[FRAMENUM];
		int currentFrame;
		double	ratioMin;
		int max_frame;
		ofParameter<bool>	doFullScreen;
		void				setFullScreen(bool& _value) { ofSetFullscreen(_value); }

		ofFbo			myFbo;
		ofEasyCam		camera;

		ofTexture		texture;
		ofxPostGlitch	myGlitch;

};
