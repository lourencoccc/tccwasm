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
#include <chrono>
#include <fstream>
#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "detectorsz/detectorsz.hpp"

using namespace std;
using namespace cv;
using namespace chrono;
using namespace detectorsz;

void runTest(string workloadName, string workloadPath);

int main(int argc, char **argv) {
  string workloadName = "WORKLOAD_1";
  string workloadPath = "../dataset/WORKLOAD_1.mp4";
  if (argc > 2) {
    workloadName = argv[1];
    workloadPath = argv[2];
  }
  cout << workloadName << "TCC WASM - João Lourenço Souza Jr" << endl;
  cout << workloadName << " " << workloadPath << endl;
  runTest(workloadName, workloadPath);
  return 0;
}

void runTest(string workloadName, string workloadPath) {
  VideoCapture video(workloadPath);
  // Check if camera opened successfully
  if (!video.isOpened()) {
    cout << "Error opening video stream or file" << endl;
    return;
  }
  FaceDetect faceDetect(workloadName);
  unsigned int frameIndex = 0;
  while (1) {
    auto start = high_resolution_clock::now();
    Mat frame;

    // Capture frame by frame
    video.read(frame);

    // Scale image to 640*480
    Mat frameScaled{Size(640, 480), frame.type()};
    resize(frame, frameScaled, frameScaled.size());

    // If the frame is empty, break immediately
    if (frame.empty())
      break;

    // Get image data to process
    MatAdapter matWSrc{frameScaled.rows, frameScaled.cols, frameScaled.type()};
    matWSrc.matImg.data = frameScaled.data;

    // Detect faces and log time
    faceDetect.faceDetectWithLog(matWSrc);

    // Display the resulting frame
    imshow("TCCWASM - Test", matWSrc.matImg);

    // Register total time for process and display image.
    auto end = high_resolution_clock::now();
    faceDetect.logs[frameIndex].totalTime =
        duration_cast<milliseconds>(end - start).count();

    frameIndex++;

    // Press ESC on keyboard to exit
    char c = (char)waitKey(25);
    if (c == 27)
      break;
  }
  // Recorde logs in a CSV file.
  ofstream logFile;
  logFile.open(workloadName + ".csv");
  logFile << faceDetect.logsToString() << endl;
  faceDetect.~FaceDetect();
  cout << "Arquivo de log gravado em :" << workloadName << ".csv" << endl;
  cout << "Teste do Worload "<< workloadName << " concluido com SUCESSO! :)"<< endl;
}
