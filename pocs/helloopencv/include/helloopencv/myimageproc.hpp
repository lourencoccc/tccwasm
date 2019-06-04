#include "helloopencv/myimage.hpp"

#include <opencv2/opencv.hpp>

#ifndef MYIMAGEPROC_HPP
#define MYIMAGEPROC_HPP

namespace  helloopencv
{

  class MyImageProc
  {
    private:
      int rows;
      int cols;
      long sizeSrc;
      long sizeResult;

      void setDataResult(cv::Mat& mat);
      void allocDataSrc();

    public:
      unsigned char* dataSrc;
      unsigned char* dataResult;

      MyImageProc();

      MyImageProc(int rows, int cols);

      ~MyImageProc();

      void transformToGray(unsigned char* dataSrc, unsigned char* dataDest);

      void gray();

      void hsv();

      int getCols();

      int getRows();

      long getSizeSrc();

      long getSizeResult();

      void setDataSrc(unsigned char* dataSrc, long size);
  };

  long dataSizeFrom(cv::Mat& mat);

}

#endif




