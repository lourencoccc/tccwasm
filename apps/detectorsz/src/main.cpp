#include <detectorsz/detectorsz.hpp>
#include <iostream>

using namespace std;
using namespace cv;
using namespace detectorsz;

// OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

int main(int argc, char **argv) {

  // Mat color = imread(
  //     "D:/Users/joao_lourenco/labs/tccwasm/pocs/helloopencv/images/lena.png",
  //     IMREAD_COLOR);

  // if (!color.data) // Check for invalid input
  // {
  //   cout << "Could not open or find the image" << std::endl;
  //   return -1;
  // }

  // ImageWrapper src{color.rows, color.cols, color.type(), matSize(color)};
  // src.copyData(color.data);
  // ImageWrapper dest;
  // ImageProcess imgprc;

  // imgprc.gray(src, dest);

  // Mat cvDest{dest.rows, dest.cols, dest.cvType, dest.getData()};
  // imwrite("lenaGray.jpg", cvDest);

  // FaceDetect faceDetect;
  // faceDetect.faceDetect(src, dest);
  // Mat cvDestFace{dest.rows, dest.cols, dest.cvType, dest.getData()};
  // imwrite("lenaFace.jpg", cvDestFace);

  // color.release();
  // cvDest.release();
  // cvDestFace.release();
  // src.~ImageWrapper();
  // dest.~ImageWrapper();
  // imgprc.~ImageProcess();
  // faceDetect.~FaceDetect();

  // destroyAllWindows();

  return 0;
}
