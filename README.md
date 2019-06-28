# tccwasm
Web Assembly - Uma analise quantitativa e qualitativa



Ambiente de desenvolvimento é o Linux que pode ser configurado automaticamente com Vagrante usando o Virtual Box

Pré-requsitos:

* [VirtualBox 6.0.4 Oracle VM VirtualBox Extension Pack](https://www.virtualbox.org/wiki/Downloads)
* [Vagrant](https://github.com/hashicorp/vagrant)

Iniciar maquina virutal:

    Vagrant up

Após instalação:

Por padrão o Vagrant cria um dsco virtual do tipo VMDK, que não pode ser redimendsionado como será preciso mais do que os 8 GB,
sugeridos como padrão, devemos proceder com a substituição do disco VMDK por VDI, conforme proceimento a seguir:

1. Acessar diretorio onde a maquina virtual está instalada e encontrar o arquivo com a extensão VMDK, exemplo;

        cd D:\VMBox

2. Em seguida proceder com os cmandos abaixo:
        VBoxManage clonemedium disk D:\VMBox\stretch\stretch_1.vmdk D:\VMBox\stretch\stretch_1.vdi --format VDI
        VBoxManage modifymedium disk "D:\VMBox\stretch\stretch_1.vdi" --resize 51200
        VBoxManage storageattach tccwasmvm --storagectl "SATA Controller" --port 0 --device 0 --type hdd --medium D:\VMBox\stretch\stretch_1.vdi

3.  Caso o disco VDK já tenha sido criado é possivel substituir:




em++   -s WASM=1    -fsigned-char -W -Wall -Werror=return-type -Werror=non-virtual-dtor -Werror=address -Werror=sequence-point -Wformat -Werror=format-security -Wmissing-declarations -Wmissing-prototypes -Wstrict-prototypes -Wundef -Winit-self -Wpointer-arith -Wshadow -Wsign-promo -Wuninitialized -Winit-self -Winconsistent-missing-override -Wno-narrowing -Wno-delete-non-virtual-dtor -Wno-unnamed-type-template-args -Wno-comment -fdiagnostics-show-option -pthread -Qunused-arguments -ffunction-sections -fdata-sections  -fvisibility=hidden -fvisibility-inlines-hidden -DNDEBUG -O2  -DNDEBUG    -Wl,--gc-sections -O2   --memory-init-file 0 -s TOTAL_MEMORY=134217728 -s ALLOW_MEMORY_GROWTH=1 -s MODULARIZE=1 -s SINGLE_FILE=1 -s EXPORT_NAME="'cv'" -s DEMANGLE_SUPPORT=1 -s FORCE_FILESYSTEM=1 --use-preload-plugins --bind --post-js /home/vagrant/opencv/modules/js/src/helpers.js  -Wno-missing-prototypes @CMakeFiles/opencv_js.dir/objects1.rsp  -o ../../bin/opencv_js.js @CMakeFiles/opencv_js.dir/linklibs.rsp


        cd D:\VMBox\tccwasm_default_1551897915300_49204
        VBoxManage createmedium disk --filename .\tccwasm.vdi --format VDI --size 51200
        VBoxManage storageattach tccwasm_default_1551897915300_49204 --storagectl "SATA Controller" --port 0 --device 0 --type hdd --medium .\tccwasm.vdi


Media, mediana, Desvio padrão por systema, 
