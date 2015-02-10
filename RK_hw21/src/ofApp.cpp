#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(22, 22, 22, 255);
    
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    // Set initial ball position to the upper-right side of the window
    x = ofGetWidth() * 0.9;
    y = 10;
    vx = 0;
    vy = 0;
    
    plot = new ofxHistoryPlot(NULL, "Mouse Position", 500, false); // Create history plot
    plot->setRange(0, ofGetHeight()); //configure range to window
    plot->addHorizontalGuide(ofGetHeight()/2, ofColor(255,0,0)); //add reference guides halfway up
    
    plot->setColor( ofColor(46,165,243) ); //color of the plot line
    plot->setShowNumericalInfo(false);  //don't show the current value and the scale in the plot
    plot->setRespectBorders(true);	   //don't let the plot draw on top of text
    plot->setLineWidth(2);				//plot line width
    plot->setBackgroundColor(ofColor(0,220)); //custom bg color
    
    //Configure grid options
    plot->setDrawGrid(true);
    plot->setGridColor(ofColor(60)); //grid lines color
    plot->setGridUnit(20);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    currentFrameRate = ofGetFrameRate();
    
    /* Perform scaling of mouse's y-position to graphed scale */
    float difference = mouseY - 2193;
    
    float percentScale = (difference)/(12-2193);
    
    float scaledPlotValue = percentScale * (751-75)+75;
    int intPlotValue = int(scaledPlotValue);
    
    plot->update(scaledPlotValue);
    //    ofLog(OF_LOG_NOTICE, "percentScale is %f, Plotpoint is %f, MouseX is %i, MouseY is %i", percentScale, scaledPlotValue, mouseX, mouseY);
    
    /* Gravity characteristic for ball, provided by example_bounceMouse */
    vy += 0.3;
    vx *= 0.9;
    x += vx;
    y += vy;
    if (x < 5) {
        x = 10;
        vx *= -1;
        vx *= 0.7;
    }
    if (x > ofGetWidth() - 5) {
        x = ofGetWidth() - 5;
        vx *= -1;
        vx *= 0.7;
    }
    if (y < 5) {
        y = 10;
        vy *= -1;
    }
    if (y > ofGetHeight() - 5) {
        y = ofGetHeight() - 5;
        vy *= -1;
        //        vy *= 0.7;
        vy *= 0.7;
    }
    
    // set mouse position
    ofxMouseController::setPos(x * 3, y * 3);
    //ofLog(OF_LOG_NOTICE, "Mouse position values are x:%f, y:%f, vx:%f, vy:%f ", x,y,vx,vy);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // configure size and shape of ball
    ofFill();
    ofSetColor(46,165,243);
    ofCircle(x, y, 8);
    ofSetColor(255);
    
    plot->draw(10, 0, 760, 840); // configure area in which to plot history
    stringstream s;
    s << "  Up arrow bumps mouse pointer up" << endl;
    s << "  Esc exits";
    ofDrawBitmapString(s.str(), 760, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case OF_KEY_UP:     vy = -5;    break;
        case OF_KEY_LEFT:   vx -= 5;    break;
        case OF_KEY_RIGHT:  vx += 5;    break;
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
