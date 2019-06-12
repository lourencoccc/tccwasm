
#include "detectorsz/detectorsz.hpp"
#include <emscripten/bind.h>

namespace dzweb {

emscripten::val matRows(detectorsz::MatAdapter &matW) {
  return emscripten::val(matW.matImg.rows);
}

emscripten::val matCols(detectorsz::MatAdapter &matW) {
  return emscripten::val(matW.matImg.cols);
}

emscripten::val matData(const detectorsz::MatAdapter &matW) {
  return emscripten::val(emscripten::memory_view<unsigned char>(
      detectorsz::matSize(matW.matImg), matW.matImg.data));
}

} // namespace dzweb

EMSCRIPTEN_BINDINGS(dzweb) {
  emscripten::register_vector<detectorsz::FaceEyesDetectLog>(
      "FaceEyesDetectLog");
  emscripten::class_<detectorsz::MatAdapter>("MatAdapter")
      .constructor<>()
      .constructor<int, int>()
      .function("getRows", &dzweb::matRows)
      .function("getCols", &dzweb::matCols)
      .property("data", &dzweb::matData);
  emscripten::class_<detectorsz::ImageProcess>("ImageProcess")
      .constructor<>()
      .function("gray", &detectorsz::ImageProcess::gray)
      .function("hsv", &detectorsz::ImageProcess::hsv);
  emscripten::class_<detectorsz::FaceDetect>("FaceDetect")
      .constructor<>()
      .function("getLogs", &detectorsz::FaceDetect::getLogs)
      .function("faceDetect", &detectorsz::FaceDetect::faceDetect)
      .function("faceAndEyesDetect", &detectorsz::FaceDetect::faceAndEyesDetect)
      .function("faceDetectWithLog", &detectorsz::FaceDetect::faceDetectWithLog)
      .function("faceAndEyesDetectWithLog",
                &detectorsz::FaceDetect::faceAndEyesDetectWithLog);
  emscripten::value_object<detectorsz::FaceEyesDetectLog>("FaceEyesDetectLog")
      .field("functionName", &detectorsz::FaceEyesDetectLog::functionName)
      .field("numberDetectedObjects",
             &detectorsz::FaceEyesDetectLog::numberDetectedFaces)
      .field("numberDetectedEyes",
             &detectorsz::FaceEyesDetectLog::numberDetectedEyes)
      .field("processTime", &detectorsz::FaceEyesDetectLog::processTime);
}
