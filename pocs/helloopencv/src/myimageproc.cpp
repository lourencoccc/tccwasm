#include "helloopencv/myimageproc.hpp"
#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

namespace  helloopencv
{
  MyImageProc::MyImageProc()
  {
    this->cols = 512;
    this->rows = 512;
    dataResult =  nullptr;
    dataSrc =  nullptr;
    allocDataSrc();
  }

  MyImageProc::MyImageProc(int rows, int cols)
  {
    this->cols = cols;
    this->rows = rows;
    dataResult =  nullptr;
    dataSrc =  nullptr;
    allocDataSrc();
  }

  MyImageProc::~MyImageProc()
  {
    delete[] dataSrc;
    delete[] dataResult;
  }

  void MyImageProc::transformToGray(unsigned char* _dataSrc, unsigned char* dataDest)
  {
    Mat src{ rows, cols, CV_8UC3, _dataSrc};
    //imwrite("lena_src_transformToGray.jpg", src);
    Mat dest;
    cvtColor(src, dest, COLOR_BGR2GRAY);
    memcpy(dataDest, dest.data, dest.total());
    src.release();
    dest.release();
  }

  void MyImageProc::gray()
  {
    Mat src{ rows, cols, CV_8UC4, dataSrc};
    //imwrite("lena_src_gray.jpg", src);
    int type = src.type();
    string sst = typeToString(src.type());
    Mat dest;
    cvtColor(src, dest, COLOR_BGR2GRAY);

    // convert the mat type to cv.CV_8U
    Mat img;
    int depth = dest.type()%8;
    int scale = depth <= CV_8S? 1.0 : (depth <= CV_32S? 1.0/256.0 : 255.0);
    int shift = (depth == CV_8S || depth == CV_16S)? 128.0 : 0.0;
    dest.convertTo(img, CV_8U, scale, shift);
    cvtColor(img, img, COLOR_GRAY2RGBA);

    //imwrite("lena_dest_gray.jpg", dest);
    setDataResult(img);
    src.release();
    dest.release();
    img.release();
  }

  void MyImageProc::hsv()
  {
    Mat src{ rows, cols, CV_8UC4, dataSrc};
    //imwrite("lena_src_hsv.jpg", src);
    int type = src.type();
    string sst = typeToString(src.type());
    Mat dest;
    cvtColor(src, dest, COLOR_RGBA2RGB);
    cvtColor(dest, dest, COLOR_RGB2HSV);
    //imwrite("lena_dest_hsv.jpg", dest);

      // convert the mat type to cv.CV_8U
    Mat img;
    int depth = dest.type()%8;
    int scale = depth <= CV_8S? 1.0 : (depth <= CV_32S? 1.0/256.0 : 255.0);
    int shift = (depth == CV_8S || depth == CV_16S)? 128.0 : 0.0;
    dest.convertTo(img, CV_8U, scale, shift);
    cvtColor(img, img, COLOR_RGB2RGBA);

    setDataResult(img);
    src.release();
    dest.release();
    img.release();
  }

  void MyImageProc::setDataResult(cv::Mat& dest)
  {
    if(dataResult != nullptr)
    {
      delete[] dataResult;
    }
    this->sizeResult = dataSizeFrom(dest);
    dataResult = new unsigned char[this->sizeResult];
    memcpy(dataResult, dest.data, this->sizeResult);
  }

  void MyImageProc::allocDataSrc()
  {
    Mat src{ rows, cols, CV_8UC3};
    if(dataSrc != nullptr)
    {
      delete[] dataSrc;
    }
    this->sizeSrc = dataSizeFrom(src);
    dataSrc = new unsigned char[this->sizeSrc];
    src.release();
  }

  void MyImageProc::setDataSrc(unsigned char* _dataSrc, long _size)
  {
    if(dataSrc != nullptr)
    {
      delete[] dataSrc;
    }
    dataSrc = new unsigned char[_size];
    dataSrc = _dataSrc;
    this->sizeSrc = _size;
  }

  long MyImageProc::getSizeSrc()
  {
    return this->sizeSrc;
  }

  long MyImageProc::getSizeResult()
  {
    return this->sizeResult;
  }

  int MyImageProc::getCols()
  {
    return this->cols;
  }

  int MyImageProc::getRows()
  {
    return this->rows;
  }


  long dataSizeFrom(cv::Mat& mat)
  {
    return (mat.total()*mat.elemSize())/sizeof(unsigned char);
  }

}
