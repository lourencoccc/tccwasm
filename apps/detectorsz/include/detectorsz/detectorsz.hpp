
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

const string FACE_DETECT_NAME = "FACE_DETECT_NAME";
const string FACE_EYES_DETECT_NAME = "FACE_EYES_DETECT_NAME";

struct ProcessLog {
  string system;
  string workload;
  string function;
  int frameIndex;
  int numberDetectedObjects;
  long aquisitionTime;
  long processTime;
  long posProcessTime;
};

struct FaceEyesDetectLog {
  string functionName;
  int numberDetectedFaces;
  int numberDetectedEyes;
  int64 processTime;
};

class ImageWrapper {
private:


public:
  unsigned char *data;
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

void convertAnyMatToGray(cv::Mat &src, cv::Mat &dest);

void convertAnyMatTo8U(cv::Mat &src, cv::Mat &dest);

void copyMatToImageWrapper(cv::Mat &src, ImageWrapper &destImg);

size_t matSize(cv::Mat &mat);

class FaceDetect {
private:
  cv::CascadeClassifier faceCascade;
  cv::CascadeClassifier eyesCascade;
  vector<FaceEyesDetectLog> logs;

  // void faceDetectCount(unsigned char *data,
  //                      int &numberFaces);
  void faceDetectCount(ImageWrapper &srcImg, ImageWrapper &destImg,
                       int &numberFaces);
  void faceAndEyesDetectCount(ImageWrapper &srcImg, ImageWrapper &destImg,
                              int &numberFaces, int &numberEyes);

public:
  FaceDetect();
  ~FaceDetect();

  void faceDetect(ImageWrapper &srcImg, ImageWrapper &destImg);

  void faceDetectWithLog(ImageWrapper &srcImg, ImageWrapper &destImg);

  // unsigned char* faceDetectWithLog(unsigned char *data);

  void faceAndEyesDetect(ImageWrapper &srcImg, ImageWrapper &destImg);

  void faceAndEyesDetectWithLog(ImageWrapper &srcImg, ImageWrapper &destImg);

  vector<FaceEyesDetectLog> getLogs();
};



} // namespace detectorsz

#endif
