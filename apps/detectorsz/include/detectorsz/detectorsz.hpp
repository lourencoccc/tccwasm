
#ifndef DETECTORSZ_HHP
#define DETECTORSZ_HHP

#include <iostream>
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace std;

namespace detectorsz {

const int CV_TYPE_DEFAULT = CV_8UC4;

const string FACE_CASCADE_PATH = "assets/haarcascade_frontalface_alt.xml";
const string EYES_CASCADE_PATH = "assets/haarcascade_eye_tree_eyeglasses.xml";

class ImageWrapper {
private:
  unsigned char *data;

public:
  int rows;
  int cols;
  int cvType;
  size_t size;

  ImageWrapper();

  ImageWrapper(int rows, int cols, size_t size);

  ImageWrapper(int rows, int cols, int cvType, size_t size);

  ~ImageWrapper();

  unsigned char *getData();

  void copyData(unsigned char *_data);
};

class ImageProcess {
private:
public:
  ImageProcess();
  ~ImageProcess();

  void gray(ImageWrapper &srcImg, ImageWrapper &destImg);

  void hsv(ImageWrapper &srcImg, ImageWrapper &destImg);
};

void convertAnyMatToRGBA(cv::Mat &src, cv::Mat &dest);

void convertAnyMatToRGB(cv::Mat &src, cv::Mat &dest);

void convertAnyMatTo8U(cv::Mat &src, cv::Mat &dest);

void copyMatToImageWrapper(cv::Mat &src, ImageWrapper &destImg);

size_t matSize(cv::Mat &mat);

class FaceDetect {
private:
  cv::CascadeClassifier faceCascade;
  cv::CascadeClassifier eyesCascade;

public:
  FaceDetect();
  ~FaceDetect();

  void faceDetect(ImageWrapper &srcImg, ImageWrapper &destImg);
};

} // namespace detectorsz

#endif
