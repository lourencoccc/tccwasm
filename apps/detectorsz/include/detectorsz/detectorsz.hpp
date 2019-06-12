
#ifndef DETECTORSZ_HHP
#define DETECTORSZ_HHP

#include <iostream>
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace std;

namespace detectorsz {

/********* Constants ******/

const int CV_TYPE_DEFAULT = CV_8UC4;

const string FACE_CASCADE_PATH = "assets/haarcascade_frontalface_alt.xml";
const string EYES_CASCADE_PATH = "assets/haarcascade_eye_tree_eyeglasses.xml";

const string FACE_DETECT_NAME = "FACE_DETECT_NAME";
const string FACE_EYES_DETECT_NAME = "FACE_EYES_DETECT_NAME";

/********* Utils ******/

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

void convertAnyMatToRGBA(cv::Mat &src, cv::Mat &dest);

void convertAnyMatToRGB(cv::Mat &src, cv::Mat &dest);

void convertAnyMatToGray(cv::Mat &src, cv::Mat &dest);

void convertAnyMatTo8U(cv::Mat &src, cv::Mat &dest);

size_t matSize(const cv::Mat &mat);

/********* Image Processs ******/

class MatAdapter {
public:
  cv::Mat matImg;
  MatAdapter();
  MatAdapter(int rows, int cols);
  MatAdapter(int rows, int cols, int cvType);
  ~MatAdapter();
  unsigned char *getData();
  void setData(unsigned char *_data);

private:
};

class ImageProcess {
public:
  ImageProcess();
  ~ImageProcess();
  void gray(MatAdapter &srcImg, MatAdapter &destImg);
  void hsv(MatAdapter &srcImg, MatAdapter &destImg);

private:
};

class FaceDetect {
public:
  FaceDetect();
  ~FaceDetect();
  void faceDetect(MatAdapter &src);
  void faceDetectWithLog(MatAdapter &src);
  void faceAndEyesDetect(MatAdapter &src);
  void faceAndEyesDetectWithLog(MatAdapter &src);
  vector<FaceEyesDetectLog> getLogs();

private:
  cv::CascadeClassifier faceCascade;
  cv::CascadeClassifier eyesCascade;
  vector<FaceEyesDetectLog> logs;
  void faceDetectCount(MatAdapter &src, int &numFaces);
  void faceAndEyesDetectCount(MatAdapter &src, int &numFaces, int &numEyes);
};

} // namespace detectorsz

#endif
