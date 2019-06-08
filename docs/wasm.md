
## Why WebAssembly is faster?


* Introdution
    * [A cartoon intro to WebAssembly](https://hacks.mozilla.org/2017/02/a-cartoon-intro-to-webassembly/)
* Background:
    * [A crash course in just-in-time (JIT) compilers](https://hacks.mozilla.org/2017/02/a-crash-course-in-just-in-time-jit-compilers/)
    * [A crash course in assembly](https://hacks.mozilla.org/2017/02/a-crash-course-in-assembly/)
* WebAssembly, the present:
    * [Creating and working with WebAssembly modules](https://hacks.mozilla.org/2017/02/creating-and-working-with-webassembly-modules/)
    * [What makes WebAssembly fast?](https://hacks.mozilla.org/2017/02/what-makes-webassembly-fast/)
* WebAssembly, the future:
    * [Where is WebAssembly now and what’s next?](https://hacks.mozilla.org/?p=30522)

This is the 1st article in a 3-part series:

* [Creating a WebAssembly module instance with JavaScript](https://hacks.mozilla.org/2017/07/creating-a-webassembly-module-instance-with-javascript/)
* [Memory in WebAssembly (and why it’s safer than you think]()
* [WebAssembly table imports… what are they?]()

## Articles

* https://rsms.me/wasm-intro
* https://hacks.mozilla.org/2018/10/webassemblys-pos    t-mvp-future/
* https://hacks.mozilla.org/2018/10/calls-between-javascript-and-webassembly-are-finally-fast-%f0%9f%8e%89/

https://rsms.me/wasm-intro
https://medium.com/leaningtech/even-better-source-maps-with-c-webassembly-and-cheerp-d872276b7d3c
https://hacks.mozilla.org/2018/01/oxidizing-source-maps-with-rust-and-webassembly/

## Tutorials

* [An Introduction to Web Assembly](https://codelabs.developers.google.com/codelabs/web-assembly-intro/#0)
* [WebAssembly Physics and DOM objects](https://codelabs.developers.google.com/codelabs/hour-chipmunk/index.html?index=..%2F..io2018#0) 
https://developers.google.com/web/updates/2019/02/hotpath-with-wasm
https://developers.google.com/web/updates/2018/10/wasm-threads
https://developers.google.com/web/updates/2018/08/wasm-av1
https://developers.google.com/web/updates/2018/04/loading-wasm
https://developers.google.com/web/updates/tags/webassembly

## Videos

* [Web Assembly - (The Standard, Ep. 13 - 2018)](https://www.youtube.com/watch?v=iPtMiqutNT4)
* [Using WebAssembly and Threads (Chrome Dev Summit 2018)](https://www.youtube.com/watch?v=zgOGZgAPUjQ&t=66s)
* [Lin Clark: A Cartoon Intro to WebAssembly | JSConf EU 2017](https://www.youtube.com/watch?v=HktWin_LPf4)
* [WebAssembly In Action - 2017](https://www.youtube.com/watch?v=DKHuEkmsx3M)
* [Compiling for the Web with WebAssembly (Google I/O '17)](https://www.youtube.com/watch?v=6v4E6oksar0&t=2s)


https://www.techrepublic.com/article/web-programming-languages-how-webassembly-will-change-the-way-you-build-web-apps/

## Applications

https://hacks.mozilla.org/2019/04/pyodide-bringing-the-scientific-python-stack-to-the-browser/?utm_source=dev-newsletter&utm_medium=email&utm_campaign=apr18-2019&utm_content=python


http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

https://github.com/emscripten-core/emscripten/issues/6312
https://github.com/Planeshifter/emscripten-examples/tree/master/01_PassingArrays


https://emscripten.org/docs/porting/connecting_cpp_and_javascript/embind.html

https://emscripten.org/docs/porting/guidelines/function_pointer_issues.html


https://github.com/opencv/opencv/blob/43467a2ac77207afd7bbc348e63d89692f838ad6/modules/js/src/core_bindings.cpp


https://github.com/emscripten-core/emscripten/issues/2074


https://docs.opencv.org/4.1.0/d3/d63/classcv_1_1Mat.html


TODO
 
How to build C with VS in Windows/Linux
How to build C++ with VS in Windows/Linux
How to build C in WebAssembly
How to build C++ in WebAssembly

Introduction to WebAssembly 
    What is?
    Run simple app
    Run WebAssembly from C++
    

Compiling






# nb. this differs from the codelab, as we compile code from the parent folder
emcc \
  -o output.js ../*.c \
  -s WASM=1 -s ONLY_MY_CODE=1 -s EXPORTED_FUNCTIONS="['_board_step','_board_init','_board_ref']"
  
em++ --bind --std=c++11 mandelbrot.cpp -s WASM=1 -s ALLOW_MEMORY_GROWTH=1 -o mandelbrot.js


--memory-init-file 0 -s TOTAL_MEMORY=134217728 -s ALLOW_MEMORY_GROWTH=1

-s MODULARIZE=1 -s SINGLE_FILE=1

-s EXPORT_NAME=\"'cv'\" -s DEMANGLE_SUPPORT=1

-s FORCE_FILESYSTEM=1 --use-preload-plugins --bind --post-js ${JS_HELPER} 


Fatal: error in validating output
shared:ERROR:  --mvp-features' failed (1)

Fatal: error in validating output
shared:ERROR: '/home/vagrant/emsdk/clang/e1.38.31_64bit/

7367770
933130
64000

8364900
