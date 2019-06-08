
#include "detectorsz/detectorsz.hpp"
#include <emscripten/bind.h>

namespace dzweb {

emscripten::val copyData(detectorsz::ImageWrapper &img, intptr_t dataSrc) {
  img.copyData(reinterpret_cast<unsigned char *>(dataSrc));
  return emscripten::val::undefined();
}

emscripten::val getData(detectorsz::ImageWrapper &img) {
  return emscripten::val(
      emscripten::memory_view<unsigned char>(img.size, img.getData()));
}

} // namespace dzweb

EMSCRIPTEN_BINDINGS(dzweb) {
  emscripten::class_<detectorsz::ImageWrapper>("ImageWrapper")
      .constructor<>()
      .constructor<int, int, size_t>()
      .property("rows", &detectorsz::ImageWrapper::rows)
      .property("cols", &detectorsz::ImageWrapper::cols)
      .property("size", &detectorsz::ImageWrapper::size)
      .function("getData", &dzweb::getData)
      .function("copyData", &dzweb::copyData, emscripten::allow_raw_pointers());
  emscripten::class_<detectorsz::ImageProcess>("ImageProcess")
      .constructor<>()
      .function("gray", &detectorsz::ImageProcess::gray)
      .function("hsv", &detectorsz::ImageProcess::hsv);
  emscripten::class_<detectorsz::FaceDetect>("FaceDetect")
      .constructor<>()
      .function("faceDetect", &detectorsz::FaceDetect::faceDetect);
}
