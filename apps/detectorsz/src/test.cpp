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
#include <mutex>
#include <thread>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "detectorsz/detectorsz.hpp"

using namespace std;
using namespace cv;
using namespace chrono;
using namespace detectorsz;
namespace detectorsz {
// constants
enum ScaleResolution { SMALL, MEDIUM, LARGE };
enum Workload { FACE_DETECT, FACE_EYES_DETECT };
const cv::Size SMALL_RESOLUTION = Size(512, 384);  // 196,608
const cv::Size MEDIUM_RESOLUTION = Size(768, 480); // 368,640
const cv::Size LARGE_RESOLUTION = Size(1280, 720); // 921,600

// properties
mutex myMutex;
vector<cv::Mat> frameStack;
bool videoEnded = false;
bool procEnded = false;
unsigned int frameCount = 0;
unsigned int frameProcessed = 0;
int64 totalTime = 0;
FaceDetect faceDetect;

// parameters
string datasetName;
string datasetPath;
cv::Size scaleResoution;
Workload workloadSelected;
unsigned int fps;
string resolutionLabel;

void configureParams(int argc, char **argv);

void frameCapture();

void runWorkload();

void report();

void configureParams(int argc, char **argv) {
  int resolutionParam = ScaleResolution::SMALL;
  if (argc > 5) {
    datasetName = argv[1];
    datasetPath = argv[2];
    resolutionParam = stoi(argv[3]);
    fps = stoi(argv[4]);
    workloadSelected =
        stoi(argv[5]) == 0 ? Workload::FACE_DETECT : Workload::FACE_EYES_DETECT;
  } else {
    cout << "Invalid params!" << endl;
    cout << "Usage example: .\\detectorsz_test.exe DATASET_7"
         << " .\\dataset\\DATASET_7.mp4 0 24 0" << endl;
    return;
  }
  if (ScaleResolution::SMALL == resolutionParam) {
    scaleResoution = SMALL_RESOLUTION;
    resolutionLabel = "SMALL";
  } else if (ScaleResolution::MEDIUM == resolutionParam) {
    scaleResoution = MEDIUM_RESOLUTION;
    resolutionLabel = "MEDIUM";
  } else if (ScaleResolution::LARGE == resolutionParam) {
    scaleResoution = LARGE_RESOLUTION;
    resolutionLabel = "LARGE";
  } else {
    cout << "Resolution to scale not supported" << endl;
    return;
  }
  faceDetect.dataName = datasetName;
  cout << datasetName << "TCC WASM - Tests" << endl;
}

void frameCapture() {
  std::lock_guard<std::mutex> guard(myMutex);
  VideoCapture video(datasetPath);

  if (!video.isOpened()) {
    cout << "Error opening video stream or file" << endl;
    return;
  }

  while (1) {
    Mat frame;

    // Capture frame by frame
    video.read(frame);

    // cout << "Framestack size " << frameStack.size() << endl;
    if (frameCount > 0 && frameCount % 200 == 0) {
      cout << "Clear vector " << endl;
      vector<cv::Mat>().swap(frameStack);
    }
    // cout << "Frame count " << frameCount << endl;

    if (frame.empty()) {
      videoEnded = true;
      break;
    }

    frameCount++;

    Mat frameScaled{scaleResoution, frame.type()};
    resize(frame, frameScaled, frameScaled.size());

    frameStack.push_back(frameScaled);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000 / fps));
  }
}

void runWorkload() {
  unsigned int frameIndex = 0;
  while (1) {
    if (videoEnded) {
      frameProcessed = frameIndex;
      break;
    }
    auto start = high_resolution_clock::now();
    int frameID = -1;
    Mat frame;

    if (frameStack.size() <= 0) {
      continue;
    } else {
      frameID = frameStack.size() - 1;
      try {
        frameStack[frameID].copyTo(frame);
      } catch (const std::exception &e) {
        std::cout << e.what() << '\n';
      }
    }
    MatAdapter matWSrc{frame.rows, frame.cols, frame.type()};
    matWSrc.matImg.data = frame.data;

    if (Workload::FACE_EYES_DETECT == workloadSelected) {
      // Detect faces and eyes with log time
      faceDetect.faceAndEyesDetectWithLog(matWSrc);
    } else {
      // Detect faces with log time
      faceDetect.faceDetectWithLog(matWSrc);
    }

    // Display the resulting frame
    imshow("TCCWASM - Test", matWSrc.matImg);

    // Register total time for process and display image.
    auto end = high_resolution_clock::now();
    faceDetect.logs[frameIndex].totalTime =
        duration_cast<milliseconds>(end - start).count();
    // cout << "Frame index processed " << frameIndex << endl;
    frameIndex++;
    matWSrc.~MatAdapter();
    // Press ESC on keyboard to exit
    char c = (char)waitKey(25);
    if (c == 27)
      break;
  }
}

void report() {
  // Report logs in a CSV file.
  ofstream logFile;
  string workloadName = workloadSelected == Workload::FACE_DETECT
                            ? FACE_DETECT_NAME
                            : FACE_EYES_DETECT_NAME;
  string system = "WINDOWS_10_WIN32";
  string reportName = "LOG_" + workloadName + "_" + datasetName + "_" +
                      resolutionLabel + "_" + system;
  logFile.open(reportName + ".csv");
  string head = ",system,resolution_label";
  string columns = "," + system + "," + resolutionLabel;
  logFile << faceDetect.logsToStringAndAddCommon(head, columns) << endl;
  cout << "Report:" << reportName << ".csv" << endl;
  cout << "Workload: " << workloadName << endl;
  cout << "Dataset: " << datasetName << endl;
  cout << "System: " << system << endl;
  cout << "Total of frames : " << frameCount << endl;
  cout << "Total of frames processeds: " << frameProcessed << endl;
  cout << "Total time of test: " << totalTime << endl;
  logFile.close();
  cout << "workload,dataset,resolution,system,total_frames, "
          "total_frames_processeds,test_total_time_ms,log_file"
       << endl;
  cout << workloadName << "," << datasetName << "," << resolutionLabel << ","
       << system << "," << frameCount << "," << frameProcessed << ","
       << "," << totalTime << "," << reportName << ".csv" << endl;
}
} // namespace detectorsz

int main(int argc, char **argv) {
  auto start = high_resolution_clock::now();
  configureParams(argc, argv);
  thread t1(frameCapture);
  runWorkload();
  t1.join();
  auto end = high_resolution_clock::now();
  totalTime = duration_cast<milliseconds>(end - start).count();
  report();
  faceDetect.~FaceDetect();
  return 0;
}
