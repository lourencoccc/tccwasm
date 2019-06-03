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

    public:
      unsigned char* dataSrc;
      unsigned char* dataResult;

      MyImageProc(int cols, int rows);

      ~MyImageProc();

      void transformToGray(unsigned char* dataSrc, unsigned char* dataDest);

      void gray();

      void hsv();

      long getSizeSrc();

      long getSizeResult();

      unsigned char* getDataSrc();

      void setDataSrc(unsigned char* dataSrc, long size);
  };

  long dataSizeFrom(cv::Mat& mat);

}

#endif




