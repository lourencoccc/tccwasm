#include <iostream>
#include <stdexcept>

#include "detectorsz/detectorsz.hpp"

using namespace std;
using namespace cv;

namespace detectorsz {

ImageProcess::ImageProcess() {}

ImageProcess::~ImageProcess() {}

void ImageProcess::gray(ImageWrapper &srcImg, ImageWrapper &destImg) {
  Mat src{srcImg.rows, srcImg.cols, srcImg.cvType, srcImg.getData()};
  Mat dest;
  cvtColor(src, dest, COLOR_BGR2GRAY);
  convertAnyMatToRGBA(dest, dest);
  copyMatToImageWrapper(dest, destImg);
  src.release();
  dest.release();
}

void ImageProcess::hsv(ImageWrapper &srcImg, ImageWrapper &destImg) {
  Mat src{srcImg.rows, srcImg.cols, srcImg.cvType, srcImg.getData()};
  Mat dest;
  cvtColor(src, dest, COLOR_RGBA2RGB);
  cvtColor(dest, dest, COLOR_RGB2HSV);
  convertAnyMatToRGBA(dest, dest);
  copyMatToImageWrapper(dest, destImg);
  src.release();
  dest.release();
}

void convertAnyMatToRGBA(cv::Mat &src, cv::Mat &dest) {
  convertAnyMatTo8U(src, dest);
  // convert the img type to cv.CV_8UC4
  switch (dest.type()) {
  case CV_8UC1:
    cvtColor(dest, dest, COLOR_GRAY2RGBA);
    break;
  case CV_8UC3:
    cvtColor(dest, dest, COLOR_RGB2RGBA);
    break;
  case CV_8UC4:
    break;
  default:
    throw runtime_error(
        "Bad number of channels (Source image must have 1, 3 or 4 channels)");
    return;
  }
}

void convertAnyMatToRGB(cv::Mat &src, cv::Mat &dest) {
  convertAnyMatTo8U(src, dest);
  // convert the img type to cv.CV_8UC3
  switch (dest.type()) {
  case CV_8UC1:
    cvtColor(dest, dest, COLOR_GRAY2RGB);
    break;
  case CV_8UC3:
    break;
  case CV_8UC4:
    cvtColor(dest, dest, COLOR_RGBA2RGB);
    break;
  default:
    throw runtime_error(
        "Bad number of channels (Source image must have 1, 3 or 4 channels)");
    return;
  }
}

void convertAnyMatTo8U(cv::Mat &src, cv::Mat &dest){
  // convert the mat type to cv.CV_8U
  int depth = src.type() % 8;
  int scale = depth <= CV_8S ? 1.0 : (depth <= CV_32S ? 1.0 / 256.0 : 255.0);
  int shift = (depth == CV_8S || depth == CV_16S) ? 128.0 : 0.0;
  src.convertTo(dest, CV_8U, scale, shift);
}

void copyMatToImageWrapper(cv::Mat &src, ImageWrapper &destImg) {
  destImg.rows = src.rows;
  destImg.cols = src.cols;
  destImg.cvType = src.type();
  destImg.size = matSize(src);
  destImg.copyData(src.data);
}

size_t matSize(cv::Mat &mat) {
  return (mat.total() * mat.elemSize()) / sizeof(unsigned char);
}

} // namespace detectorsz
