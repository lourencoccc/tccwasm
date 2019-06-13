/*
Copyright 2019, Joao Lourenco Souza Junior, all rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <chrono>
#include <iostream>
#include <stdexcept>

#include "detectorsz/detectorsz.hpp"
// #include "opencv2/highgui.hpp"

using namespace std;
using namespace cv;
using namespace chrono;

namespace detectorsz {

FaceDetect::FaceDetect() {
  std::cout << "FaceDetect Consructor" << endl;
  if (!faceCascade.load(FACE_CASCADE_PATH)) {
    std::cerr << "--(!)Error loading face cascade\n" << endl;
    throw runtime_error("--(!)Error loading face cascade\n");
    return;
  };
  if (!eyesCascade.load(EYES_CASCADE_PATH)) {
    std::cerr << "--(!)Error loading eyes cascade\n" << endl;
    throw runtime_error("--(!)Error loading eyes cascade\n");
    return;
  };
}

FaceDetect::~FaceDetect() {
  std::cout << "FaceDetect Destructor" << endl;
  faceCascade.~CascadeClassifier();
  eyesCascade.~CascadeClassifier();
  if (logs.size()) {
    logs.shrink_to_fit();
  }
}

vector<FaceEyesDetectLog> FaceDetect::getLogs() { return this->logs; }

void FaceDetect::faceDetect(MatAdapter &srcImg) {
  int numFaces = 0;
  faceDetectCount(srcImg, numFaces);
}

void FaceDetect::faceAndEyesDetect(MatAdapter &srcImg) {
  int numFaces, numEyes = 0;
  faceAndEyesDetectCount(srcImg, numFaces, numEyes);
}

void FaceDetect::faceDetectWithLog(MatAdapter &srcImg) {
  FaceEyesDetectLog log;
  log.functionName = FACE_DETECT_NAME;
  auto start = high_resolution_clock::now();
  faceDetectCount(srcImg, log.numberDetectedFaces);
  auto end = high_resolution_clock::now();
  log.processTime = duration_cast<milliseconds>(end - start).count();
  logs.push_back(log);
}

void FaceDetect::faceAndEyesDetectWithLog(MatAdapter &srcImg) {
  FaceEyesDetectLog log;
  log.functionName = FACE_EYES_DETECT_NAME;
  auto start = high_resolution_clock::now();
  faceAndEyesDetectCount(srcImg, log.numberDetectedFaces,
                         log.numberDetectedEyes);
  auto end = high_resolution_clock::now();
  log.processTime = duration_cast<milliseconds>(end - start).count();
  logs.push_back(log);
}

void FaceDetect::faceDetectCount(MatAdapter &srcImg, int &numberFaces) {
  Mat dest;
  convertAnyMatToGray(srcImg.matImg, dest);
  equalizeHist(dest, dest);
  //-- Detect faces
  std::vector<Rect> faces;
  faceCascade.detectMultiScale(dest, faces);
  numberFaces = faces.size();
  for (size_t i = 0; i < faces.size(); i++) {
    Point center(faces[i].x + faces[i].width / 2,
                 faces[i].y + faces[i].height / 2);
    ellipse(srcImg.matImg, center,
            Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360,
            Scalar(255, 0, 255), 4);
  }
  convertAnyMatToRGBA(srcImg.matImg, srcImg.matImg);
  dest.release();
}

void FaceDetect::faceAndEyesDetectCount(MatAdapter &srcImg, int &numberFaces,
                                        int &numberEyes) {
  Mat dest;
  convertAnyMatToGray(srcImg.matImg, dest);
  equalizeHist(dest, dest);
  //-- Detect faces
  std::vector<Rect> faces;
  faceCascade.detectMultiScale(dest, faces);
  numberFaces = faces.size();
  for (size_t i = 0; i < faces.size(); i++) {
    Point center(faces[i].x + faces[i].width / 2,
                 faces[i].y + faces[i].height / 2);
    ellipse(srcImg.matImg, center,
            Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360,
            Scalar(255, 0, 255), 4);
    Mat faceROI = dest(faces[i]);
    //-- In each face, detect eyes
    std::vector<Rect> eyes;
    eyesCascade.detectMultiScale(faceROI, eyes);
    numberEyes = eyes.size();
    for (size_t j = 0; j < eyes.size(); j++) {
      Point eye_center(faces[i].x + eyes[j].x + eyes[j].width / 2,
                       faces[i].y + eyes[j].y + eyes[j].height / 2);
      int radius = cvRound((eyes[j].width + eyes[j].height) * 0.25);
      circle(srcImg.matImg, eye_center, radius, Scalar(255, 0, 0), 4);
      std::cout << "Eyes " << j << endl;
    }
  }
  convertAnyMatToRGBA(srcImg.matImg, srcImg.matImg);
  dest.release();
}
} // namespace detectorsz
