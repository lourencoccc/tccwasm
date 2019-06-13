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

unsigned char *_data = nullptr;

void copyMatData(Mat &src) {
  _data = nullptr;
  delete[] _data;
  _data = new unsigned char[matSize(src)];
  _data = src.data;
}

int main(int argc, char **argv) {

  VideoCapture video("D:/imgdata/McgillReal-worldDatabase.mp4");
  // Check if camera opened successfully
  if (!video.isOpened()) {
    cout << "Error opening video stream or file" << endl;
    return -1;
  }

  FaceDetect faceDetect;

  while (1) {
    Mat frame;
    // Capture frame-by-frame
    video.read(frame);

    // If the frame is empty, break immediately
    if (frame.empty())
      break;

    // Display the resulting frame]
    MatAdapter matWSrc{frame.rows, frame.cols, frame.type()};
    matWSrc.matImg.data = frame.data;

    faceDetect.faceDetectWithLog(matWSrc);

    imshow("Frame", matWSrc.matImg);

    // Press  ESC on keyboard to exit
    char c = (char)waitKey(25);
    if (c == 27)
      break;
  }
  faceDetect.~FaceDetect();
  return 0;
}
