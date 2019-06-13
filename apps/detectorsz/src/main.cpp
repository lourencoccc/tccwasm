/*
Copyright 2019, Joao Lourenco Souza Junior, all rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

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
