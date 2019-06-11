
#include "detectorsz/detectorsz.hpp"
#include <emscripten/bind.h>

namespace dzweb {

emscripten::val copyData(detectorsz::ImageWrapper &img, intptr_t dataSrc) {
  img.copyData(reinterpret_cast<unsigned char *>(dataSrc));
  return emscripten::val::undefined();
}

// template<typename T>
// emscripten::val imgData(const detectorsz::ImageWrapper &img) {
//   return emscripten::val(
//       emscripten::memory_view<T>(img.size, (T*)img.data));
// }

emscripten::val getData(detectorsz::ImageWrapper &img) {
  return emscripten::val(
      emscripten::memory_view<unsigned char>(img.size, img.getData()));
}

} // namespace dzweb

EMSCRIPTEN_BINDINGS(dzweb) {
  emscripten::register_vector<detectorsz::FaceEyesDetectLog>("FaceEyesDetectLog");
  emscripten::class_<detectorsz::ImageWrapper>("ImageWrapper")
      .constructor<>()
      .constructor<int, int, size_t>()
      .property("rows", &detectorsz::ImageWrapper::rows)
      .property("cols", &detectorsz::ImageWrapper::cols)
      .property("size", &detectorsz::ImageWrapper::size)
      // .property("data", &dzweb::imgData<unsigned char>)
      .function("getData", &dzweb::getData)
      .function("copyData", &dzweb::copyData, emscripten::allow_raw_pointers());
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
      .field("numberDetectedObjects", &detectorsz::FaceEyesDetectLog::numberDetectedFaces)
      .field("numberDetectedEyes", &detectorsz::FaceEyesDetectLog::numberDetectedEyes)
      .field("processTime", &detectorsz::FaceEyesDetectLog::processTime);
}
