# Open CV

## Instalação 

Baixar cósdigo fonte e fazer build na plataforma alvo.

    git clone https://github.com/opencv/opencv.git
    git clone https://github.com/opencv/opencv_contrib.git


Necessario configurar os repositorios para versão 4.0.1

    cd opencv
    git checkout tags/4.0.1

## Linux

    cd opencv
    mkdir build
    cd build
    cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local -DBUILD_SHARED_LIBS=OFF ..

## Windows

    Configurar cmake e fazer build com Visual Studio Community, versão 15 ou superior.

## Referências

* [OpenCV no Linus](https://docs.opencv.org/3.4/d7/d9f/tutorial_linux_install.html)
* [OpenCV no Windows](https://perso.uclouvain.be/allan.barrea/opencv/cmake_config.html)
