# tccwasm
Desenvolvimento do Trabalho de Conclusão de Curso 2019.1 - Web Assembly


Why WebAssembly is faster?


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

https://rsms.me/wasm-intro
https://hacks.mozilla.org/2018/10/webassemblys-post-mvp-future/
https://hacks.mozilla.org/2018/10/calls-between-javascript-and-webassembly-are-finally-fast-%f0%9f%8e%89/

This is the 1st article in a 3-part series:

* [Creating a WebAssembly module instance with JavaScript](https://hacks.mozilla.org/2017/07/creating-a-webassembly-module-instance-with-javascript/)
* [Memory in WebAssembly (and why it’s safer than you think]()
* [WebAssembly table imports… what are they?]()


Development base enviroment

This porject use the Debian 9.7.0 as base enviroment.

Command to install basic tools for linux:

```shell
    apt-get update
    apt-get install git -y
    apt-get install util-linux -y
    apt-get install htop -y
    apt-get install zsh -y
    apt-get install zip -y
    apt-get install curl -y
    apt-get install dkms -y
    apt-get install sudo -y
    apt-get install net-tools -y
    apt-get instlal openssh-server -y
    apt-get install apt-transport-https -y
    # to c++
    apt-get install build-essential -y
    apt-get install linux-headers-$(uname -r) -y
    apt-get install cmake -y
    # to opencv
    apt-get install libgtk2.0-dev -y 
    apt-get install pkg-config -y
    apt-get install ibavcodec-dev -y
    apt-get install libavformat-dev -y
    apt-get install libswscale-dev -y
```

On Windows 10, is necessary to install VirtualBox and Vagrant, then proceed the previus linux command.
This project provide the Vagrantfile.


Visusal Studio Code

For build opencv

libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev



cenario de teste 1

2GB de arquivos de texto

1. arquivo de texto 
2. 

2GB de arquivos de imagem


2GB de arquivos de imaem e video.

Dado est cenari será disparado processo e carregamento e compressão dos arquivos, calculando o tempo de processameno decorrido
a partir 


Other benchmarks

https://attractivechaos.github.io/plb/
https://salsa.debian.org/benchmarksgame-team/benchmarksgame
https://salsa.debian.org/benchmarksgame-team/benchmarksgame/blob/master/public/download/benchmarksgame-sourcecode.zip
https://benchmarksgame-team.pages.debian.net/benchmarksgame/dont-jump-to-conclusions.html
http://www.cleveralgorithms.com/nature-inspired/advanced/racing_algorithms.html
http://benchmark.r-forge.r-project.org/
https://julialang.org/benchmarks/
https://github.com/JuliaLang/Microbenchmarks


https://hacks.mozilla.org/2017/09/bootcamps-webassembly-and-computer-vision/
https://codepen.io/huningxin/pen/NvjdeN
https://github.com/shamadee/web-dsp


