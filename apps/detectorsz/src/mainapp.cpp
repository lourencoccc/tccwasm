#include <detectorsz/detectorsz.hpp>
#include <iostream>

using namespace std;
using namespace cv;
using namespace detectorsz;

// OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

unsigned char *_data = nullptr;

void copyMatData(Mat &src){
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

    // Display the resulting frame
    ImageWrapper src {frame.rows, frame.cols, frame.type(), matSize(frame)};
    src.data = frame.data;

    ImageWrapper dest;
    faceDetect.faceDetect(src, dest);

    Mat cvDestFace{dest.rows, dest.cols, dest.cvType, dest.data};

    imshow("Frame", frame);

    imshow("Frame cvDestFace", cvDestFace);

    //frame.release();
    //src.~ImageWrapper();
    //dest.~ImageWrapper();
    // Press  ESC on keyboard to exit
    char c = (char)waitKey(25);
    if (c == 27)
      break;
  }
  //src.~ImageWrapper();

  faceDetect.~FaceDetect();
  return 0;
}
