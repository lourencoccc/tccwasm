#include <iostream>
#include <stdexcept>

#include "detectorsz/detectorsz.hpp"

using namespace std;
using namespace cv;

namespace detectorsz {
FaceDetect::FaceDetect() {
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
  faceCascade.~CascadeClassifier();
  eyesCascade.~CascadeClassifier();
}

void FaceDetect::faceDetect(ImageWrapper &srcImg, ImageWrapper &destImg) {
  Mat src{srcImg.rows, srcImg.cols, srcImg.cvType, srcImg.getData()};
  // // Mat src;
  // // cvtColor(src0, src, COLOR_RGB2RGBA);
  convertAnyMatToRGB(src, src);
  // imwrite("lena_dest_face_1.jpg", src);
  Mat dest;
  cvtColor(src, dest, COLOR_RGB2GRAY);
  // imwrite("lena_dest_face_2.jpg", dest);
  equalizeHist(dest, dest);
  // imwrite("lena_dest_face_3.jpg", dest);
  //-- Detect faces
  std::vector<Rect> faces;
  faceCascade.detectMultiScale(dest, faces);
  for (size_t i = 0; i < faces.size(); i++) {
    Point center(faces[i].x + faces[i].width / 2,
                 faces[i].y + faces[i].height / 2);
    ellipse(src, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0,
            360, Scalar(255, 0, 255), 4);
    Mat faceROI = dest(faces[i]);
    //-- In each face, detect eyes
    // std::vector<Rect> eyes;
    // eyesCascade.detectMultiScale(faceROI, eyes);
    // for (size_t j = 0; j < eyes.size(); j++) {
    //   Point eye_center(faces[i].x + eyes[j].x + eyes[j].width / 2,
    //                    faces[i].y + eyes[j].y + eyes[j].height / 2);
    //   int radius = cvRound((eyes[j].width + eyes[j].height) * 0.25);
    //   circle(src, eye_center, radius, Scalar(255, 0, 0), 4);
    //   std::cout << "Eyes " << j << endl;
    // }
  }
  convertAnyMatToRGBA(src, src);
  copyMatToImageWrapper(src, destImg);
  src.release();
  dest.release();
}

} // namespace detectorsz
