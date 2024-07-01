#include "ofApp.h"
int stage = 0; //the game has different phases to make sure all the context is correct for each phase this struct handles it


ofTrueTypeFont bodyFont;
ofTrueTypeFont headFont;

ofVideoPlayer videoPlayer;

int playX ,playY, playSize;

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
    playX = ofGetWidth()/2;
    playY = ofGetHeight()/2;
    playSize=100;

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
    
    ofRectangle(100,100,100,100);

    if(codeMode){
        
        
        
        if(stage==0){
            ofSetColor(88, 88, 4);

            ofDrawEllipse(ofGetWidth()/2, ofGetHeight()/2, 100, 100);
            ofSetColor(243, 214, 186);

            bodyFont.drawString(">", ofGetWidth()/2-15, ofGetHeight()/2+20);

        }else if(stage>0){
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
            
            ofSetColor(88, 88, 4);
            ofDrawRectRounded(ofGetWidth()/2-100, ofGetHeight()/2-50, 200, 100, 40);

            ofSetColor(243, 214, 186);
            bodyFont.drawString(codeText, ofGetWidth()/2-90, ofGetHeight()/2+30);
        }
    }else{
        
        //logic for serial com with rfid
        
        
    }
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
                    
            
            inCode[iCode] = key-48;
            cout<<inCode[iCode]<<" ,"<<codes[stage*4][iCode]<<endl;
            iCode ++;

            if(iCode >= 4 ){
                if( isCode(0,inCode ,codes)){

                    stageVideoPlayer(stage++, &videoPlayer);//stage++ because the 0th video is the intro
                    stage+=1;
                }
                iCode = 0;
                for(int i=0; i<4; i++) {
                    inCode[i] = 0;
                }
            }
        }
    }

}


void ofApp::stageVideoPlayer(int appStage, ofVideoPlayer *appVideoPlayer){
    cout<<"stageVideoPlayer func:"<<appStage<<endl;
    appVideoPlayer->closeMovie();

    switch (appStage) {
        case 0:
            appVideoPlayer->load("videos/welcome.mp4");
            break;
            
        case 1:
            appVideoPlayer->load("videos/1-corn.mp4");
            break;
            
        case 2:
            appVideoPlayer->load("videos/2-cow.mp4");
            break;
        case 3:
            appVideoPlayer->load("videos/3-pigeon.mp4");
            break;
            
        case 4:
            appVideoPlayer->load("videos/4-candle.mp4");
            break;
            
        case 5:
            
            appVideoPlayer->load("videos/goodbye.mp4");
            break;
            
        default:
            break;
    }
    appVideoPlayer->play();

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
    cout<<"x: "<<playX-playSize/2<<">="<<x<<"<="<<playX+playSize/2<<endl;
    cout<<"y: "<<playY-playSize/2<<">="<<y<<"<="<<playY+playSize/2<<endl;

    if(x >= playX-playSize/2 && x <= playX+playSize/2 && y >= playY-playSize/2 && y <= playY+playSize/2){
        stageVideoPlayer(0, &videoPlayer);//play the intro
        stage+=1;
        cout<<"in if, stage:"<<stage<<endl;
    }

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
