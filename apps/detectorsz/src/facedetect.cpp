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

void FaceDetect::faceDetect(ImageWrapper &srcImg, ImageWrapper &destImg) {
  int numFaces = 0;
  faceDetectCount(srcImg, destImg, numFaces);
}

void FaceDetect::faceAndEyesDetect(ImageWrapper &srcImg,
                                   ImageWrapper &destImg) {
  int numFaces, numEyes = 0;
  faceAndEyesDetectCount(srcImg, destImg, numFaces, numEyes);
}

void FaceDetect::faceDetectWithLog(ImageWrapper &srcImg,
                                   ImageWrapper &destImg) {
  FaceEyesDetectLog log;
  log.functionName = FACE_DETECT_NAME;
  auto start = high_resolution_clock::now();
  faceDetectCount(srcImg, destImg, log.numberDetectedFaces);
  auto end = high_resolution_clock::now();
  log.processTime = duration_cast<milliseconds>(end - start).count();
  logs.push_back(log);
}

// unsigned char* FaceDetect::faceDetectWithLog(unsigned char *data){
//   FaceEyesDetectLog log;
//   log.functionName = FACE_DETECT_NAME;
//   auto start = high_resolution_clock::now();
//   unsigned char* dataDest = faceDetectCount(data, log.numberDetectedFaces);
//   auto end = high_resolution_clock::now();
//   log.processTime = duration_cast<milliseconds>(end - start).count();
//   logs.push_back(log);
// }

void FaceDetect::faceAndEyesDetectWithLog(ImageWrapper &srcImg,
                                          ImageWrapper &destImg) {
  FaceEyesDetectLog log;
  log.functionName = FACE_EYES_DETECT_NAME;
  auto start = high_resolution_clock::now();
  faceAndEyesDetectCount(srcImg, destImg, log.numberDetectedFaces,
                         log.numberDetectedEyes);
  auto end = high_resolution_clock::now();
  log.processTime = duration_cast<milliseconds>(end - start).count();
  logs.push_back(log);
}

void FaceDetect::faceDetectCount(ImageWrapper &srcImg, ImageWrapper &destImg,
                                 int &numberFaces) {
  Mat src{srcImg.rows, srcImg.cols, srcImg.cvType, srcImg.getData()};
  Mat dest;
  convertAnyMatToGray(src, dest);
  equalizeHist(dest, dest);
  //imwrite("img_face_1.jpg", dest);
  //-- Detect faces
  std::vector<Rect> faces;
  faceCascade.detectMultiScale(dest, faces);
  numberFaces = faces.size();
  for (size_t i = 0; i < faces.size(); i++) {
    Point center(faces[i].x + faces[i].width / 2,
                 faces[i].y + faces[i].height / 2);
    ellipse(src, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0,
            360, Scalar(255, 0, 255), 4);
  }
  //imwrite("img_face_2.jpg", src);
  convertAnyMatToRGBA(src, src);
  copyMatToImageWrapper(src, destImg);
  src.release();
  dest.release();
}

// unsigned char* FaceDetect::faceDetectCount(unsigned char *data) {
//   Mat src{srcImg.rows, srcImg.cols, srcImg.cvType, data};
//   Mat dest;
//   convertAnyMatToGray(src, dest);
//   equalizeHist(dest, dest);
//   //-- Detect faces
//   std::vector<Rect> faces;
//   faceCascade.detectMultiScale(dest, faces);
//   numberFaces = faces.size();
//   for (size_t i = 0; i < faces.size(); i++) {
//     Point center(faces[i].x + faces[i].width / 2,
//                  faces[i].y + faces[i].height / 2);
//     ellipse(src, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0,
//             360, Scalar(255, 0, 255), 4);
//   }
//   convertAnyMatToRGBA(src, src);
//   copyMatToImageWrapper(src, destImg);
// }

void FaceDetect::faceAndEyesDetectCount(ImageWrapper &srcImg,
                                        ImageWrapper &destImg, int &numberFaces,
                                        int &numberEyes) {
  Mat src{srcImg.rows, srcImg.cols, srcImg.cvType, srcImg.getData()};
  Mat dest;
  convertAnyMatToGray(src, dest);
  equalizeHist(dest, dest);
  //-- Detect faces
  std::vector<Rect> faces;
  faceCascade.detectMultiScale(dest, faces);
  numberFaces = faces.size();
  for (size_t i = 0; i < faces.size(); i++) {
    Point center(faces[i].x + faces[i].width / 2,
                 faces[i].y + faces[i].height / 2);
    ellipse(src, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0,
            360, Scalar(255, 0, 255), 4);
    Mat faceROI = dest(faces[i]);
    //-- In each face, detect eyes
    std::vector<Rect> eyes;
    eyesCascade.detectMultiScale(faceROI, eyes);
    numberEyes = eyes.size();
    for (size_t j = 0; j < eyes.size(); j++) {
      Point eye_center(faces[i].x + eyes[j].x + eyes[j].width / 2,
                       faces[i].y + eyes[j].y + eyes[j].height / 2);
      int radius = cvRound((eyes[j].width + eyes[j].height) * 0.25);
      circle(src, eye_center, radius, Scalar(255, 0, 0), 4);
      std::cout << "Eyes " << j << endl;
    }
  }
  convertAnyMatToRGBA(src, src);
  copyMatToImageWrapper(src, destImg);
  src.release();
  dest.release();
}
} // namespace detectorsz
