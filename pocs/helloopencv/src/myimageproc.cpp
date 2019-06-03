#include "helloopencv/myimageproc.hpp"
#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

namespace  helloopencv
{

  MyImageProc::MyImageProc(int cols, int rows)
  {
    this->cols = cols;
    this->rows = rows;
    dataResult =  nullptr;
    dataSrc =  nullptr;
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
    Mat src{ rows, cols, CV_8UC3, dataSrc};
    //imwrite("lena_src_gray.jpg", src);
    int type = src.type();
    string sst = typeToString(src.type());
    Mat dest;
    cvtColor(src, dest, COLOR_BGR2GRAY);
    //imwrite("lena_dest_gray.jpg", dest);
    setDataResult(dest);
    src.release();
    dest.release();
  }

  void MyImageProc::hsv()
  {
    Mat src{ rows, cols, CV_8UC3, dataSrc};
    //imwrite("lena_src_hsv.jpg", src);
    int type = src.type();
    string sst = typeToString(src.type());
    Mat dest;
    cvtColor(src, dest, COLOR_RGBA2RGB);
    cvtColor(dest, dest, COLOR_RGB2HSV);
    //imwrite("lena_dest_hsv.jpg", dest);
    setDataResult(dest);
    src.release();
    dest.release();
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

  long helloopencv::dataSizeFrom(cv::Mat& mat)
  {
    return (mat.total()*mat.elemSize())/sizeof(unsigned char);
  }

}
