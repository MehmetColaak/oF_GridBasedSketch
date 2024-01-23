#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

    gui.setup();
    gui.add(gridRes.setup("Grid Resolution", 50, 10, 100));
    gui.add(textureChng.setup("Texture Change", 1, 1, 9));
    gui.add(noiseScale.setup("Noise Scale", 0.01, 0.001, 0.1));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    int witdh = ofGetWidth();
    int height = ofGetHeight();
    int res = gridRes;
    int txtr = textureChng + ofGetElapsedTimef();
    int cols = witdh / res;
    int rows = height / res;

    for(int i = 1; i < witdh; i += cols)
    {
        for(int j = 1; j < height; j += rows)
        {
            // ofDrawLine(i, 0, i, height);
            // ofDrawLine(0, j, witdh, j);

            int colIndex = i / cols;
            int rowIndex = j / rows;

            float noiseValue = 1; //ofNoise(i * 0.2 * noiseScale, j * 0.2 * noiseScale); //perlin noise texture add.

            if ((colIndex + rowIndex) % txtr == 0) 
            {
                ofSetColor(0); 
            } 
            else 
            {
                ofSetColor(255 * noiseValue); 
            }
            ofDrawRectangle(i, j, cols, rows);
        }
    }
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::exit(){

}