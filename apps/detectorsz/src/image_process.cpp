#include "detectorsz/detectorsz.hpp"

namespace detectorsz {

ImageProcess::ImageProcess() {}

ImageProcess::~ImageProcess() {}

void ImageProcess::gray(MatAdapter &srcImg, MatAdapter &destImg) {
  cv::cvtColor(srcImg.matImg, destImg.matImg, cv::COLOR_BGR2GRAY);
  convertAnyMatToRGBA(destImg.matImg, destImg.matImg);
}

void ImageProcess::hsv(MatAdapter &srcImg, MatAdapter &destImg) {
  cv::cvtColor(srcImg.matImg, destImg.matImg, cv::COLOR_RGBA2RGB);
  cv::cvtColor(destImg.matImg, destImg.matImg, cv::COLOR_RGB2HSV);
  convertAnyMatToRGBA(destImg.matImg, destImg.matImg);
}

} // namespace detectorsz
