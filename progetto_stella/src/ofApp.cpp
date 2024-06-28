#include "ofApp.h"
struct stage; //the game has different phases to make sure all the context is correct for each phase this struct handles it


ofTrueTypeFont bodyFont;
ofTrueTypeFont headFont;

ofVideoPlayer videoPlayer;

int videoNum = 0;

/**
 0: intro
 1: corn
 2: cow
 3: pigeon
 4: candle
 5: outro
 */
bool videoPlaying = false;

//    string ofSystemTextBoxDialog(string question, string text);
int inCode[4];//4 integers form the code e.g. 1234

int iCode = 0;
bool codeMode = true;


int codes[4][4]= {
    {1,5,7,3},//corn
    {8,5,2,9},//cow
    {4,3,7,1},//candle
    {3,8,2,6}};//pigeon
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
    
//    if(e.widget->getName() == "InputPhrase")
//        {
//            ofxUITextInput *textInput = (ofxUITextInput *) e.widget;
//            inputPhrase = textInput->getTextString();
//            cout<<"InputPhrase: " + inputPhrase<<endl;
//        }
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
    
   
    ofDrawRectRounded(ofGetWidth()/2-100, ofGetHeight()/2-50, 200, 100, 40);
    
    ofSetColor(243, 214, 186);

    string codeText ;
    if(inCode[0] == 0){
        codeText.append("- ");
    }else{
        codeText.append(to_string(inCode[0]));
    }
    if(inCode[1] == 0){
        codeText.append("- ");
    }else{
        codeText.append(to_string(inCode[1]));
    }
    if(inCode[2] == 0){
        codeText.append("- ");
    }else{
        codeText.append(to_string(inCode[2]));
    }
    if(inCode[3] == 0){
        codeText.append("- ");
    }else{
        codeText.append(to_string(inCode[3]));
    }
  
    bodyFont.drawString(codeText, ofGetWidth()/2-90, ofGetHeight()/2+30);

}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    /*
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
    }*/
    
    cout<<key<<endl;
    //0-9 --> 48-57 --> key-48 = num
    
    if(codeMode){
        if(key>=48 && key<=57){
            auto isCode = [] (int n, int incodeArray[4], int codesArray[4][4]) {
                for(int i = 0; i<4; i++){
                    if(incodeArray[i] != codesArray[n][i]){
                        cout<<"wrong code"<<endl;
                        return false;
                        break;
                    }else if(i == 3){
                        cout<<"right code"<<endl;
                        return true;
                    }
                }
                return false;
            };
                    
            if(iCode >= 4 ){
                if( isCode(0,inCode ,codes)){
                    videoPlayer.closeMovie();
                    videoPlayer.load("videos/1-corn.mp4");
                    videoPlayer.play();

                }
                iCode = 0;
                for(int i=0; i<4; i++) {
                    inCode[i] = 0;
                }
            }
            inCode[iCode] = key-48;
            cout<<inCode[iCode]<<" ,"<<codes[0][iCode]<<endl;

            iCode ++;
        }
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
