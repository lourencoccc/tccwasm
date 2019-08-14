# WebAssembly - Uma analise quantitativa utilizando processamento de imgem

Este repositorio contem todos os artefatos desenvolvidos para o meu trabalho de conclusão de curso.


## Estrutura de Diretorios

* **apps**: aplicações utilizdas no TCC.
* **arch**: Documentação da Analise e projeto
* **dataset**: Massa de dados de teste
* **docs**: Documentação prosuzida.
* **outcomes**: Dados coletados após execução dos cénarios de teste.
* **pocs**: Provas de conceito e experimentos diversos envolvendo WebAssembly e OpenCV
* **scripts**: Stripts uteis.

## Pré-requsitos

* [VirtualBox 6.0.4 Oracle VM VirtualBox Extension Pack](https://www.virtualbox.org/wiki/Downloads)
* [Vagrant](https://github.com/hashicorp/vagrant)

Iniciar maquina virutal:

    Vagrant up

## Pós-instalação

Por padrão o Vagrant cria um dsco virtual do tipo VMDK, que não pode ser redimendsionado como será preciso mais do que os 8 GB,
sugeridos como padrão, devemos proceder com a substituição do disco VMDK por VDI, conforme proceimento a seguir:

1. Acessar diretorio onde a maquina virtual está instalada e encontrar o arquivo com a extensão VMDK, exemplo;

        cd D:\VMBox

2. Em seguida proceder com os cmandos abaixo:
        VBoxManage clonemedium disk D:\VMBox\stretch\stretch_1.vmdk D:\VMBox\stretch\stretch_1.vdi --format VDI
        VBoxManage modifymedium disk "D:\VMBox\stretch\stretch_1.vdi" --resize 51200
        VBoxManage storageattach tccwasmvm --storagectl "SATA Controller" --port 0 --device 0 --type hdd --medium D:\VMBox\stretch\stretch_1.vdi

3.  Caso o disco VDK já tenha sido criado é possivel substituir:

        cd D:\VMBox\tccwasm_default_1551897915300_49204
        VBoxManage createmedium disk --filename .\tccwasm.vdi --format VDI --size 51200
        VBoxManage storageattach tccwasm_default_1551897915300_49204 --storagectl "SATA Controller" --port 0 --device 0 --type hdd --medium .\tccwasm.vdi
