#include "helloopencv/myimageproc.hpp"
#include <emscripten/bind.h>

using namespace helloopencv;

namespace myimageprocjs
{
  emscripten::val hello(MyImageProc& proc, int a)
  {
    return emscripten::val(proc.hello(a));
  }

} // namespace myimageprocjs


EMSCRIPTEN_BINDINGS(myimageprocjs) {
  emscripten::class_<MyImageProc>("MyImageProc")
    .constructor<>()
    .function("hello", &myimageprocjs::hello);
}
