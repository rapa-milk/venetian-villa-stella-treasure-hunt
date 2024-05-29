#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 242, 204);
    ofSetFullscreen(true);
    
    //loading brand fonts
    bodyFont.load("fonts/EBGaramond-VariableFont_wght.ttf", 70,true,true,false, 1000.0f, 0);
    headFont.load("fonts/PlayfairDisplay-VariableFont_wght.ttf", 70);

    //loading first video
//    videoPlayer.load("videos/welcome.mp4");
    videoPlayer.setLoopState(OF_LOOP_NONE);
}

//--------------------------------------------------------------
void ofApp::update(){

    videoPlayer.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
//    headFont.drawString("Head, HEAD", 100,300);
//    bodyFont.drawString("Body", 100,100);
    
    if(videoPlayer.isLoaded() ){
        videoPlayer.draw(100,100, 500,500);
    }
    
    ofSetColor(88, 88, 4);

    ofRectangle(100,100,100,100);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'w':            
            videoPlayer.closeMovie();
            videoPlayer.load("videos/welcome.mp4");
            videoPlayer.play();
            break;
        case '1':
            videoPlayer.closeMovie();
            videoPlayer.load("videos/1-corn.mp4");
            videoPlayer.play();
            break;
        case '2':
            videoPlayer.closeMovie();
            videoPlayer.load("videos/2-cow.mp4");
            videoPlayer.play();
            break;
        case '3':
            videoPlayer.closeMovie();
            videoPlayer.load("videos/3-pigeon.mp4");
            videoPlayer.play();
            break;
        case '4':
            videoPlayer.closeMovie();
            videoPlayer.load("videos/4-candle.mp4");
            videoPlayer.play();
            break;
        case 'g':
            videoPlayer.closeMovie();
            videoPlayer.load("videos/goodbye.mp4");
            videoPlayer.play();
            break;
        default:
            break;
    }

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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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
