# TCC WebAsembly - Provas de Conceito

## Opção 1 - Aplicação otimizada de gerenciamento de dados na nuvem

### Descrição: 
Aplicação otimizada de gerenciamento de dados na nuvem, reduzindo o trafego de dados 
aplicando algoritimo compressão em arquivos para upload e descompressão quanado for solicitado
download destes arquivos.

### Vialbilidade 
A prova de conceito pode ser feita implementando um simples gerecenciador de pasta do Dropbox.
Onde é esperado uma economia  no fluxo de tranferência de dados de aproximadamente 25% 
a depender das carateristicas dos arquivos armazenados.

### Justificativa
O volume de dados produzidos e armazenados por pessoa tem crescido constantemente
bem como uso de provedores de armazen de dados como Dropbox, Google Drive, OneDrive, entre outros.
A manuteção e trafego destes dados acarreta em custos de varias naturezas para todos
os envolvidos, provedores de internet, provedores de amarzen de dados e consumidores finais.
Ser capaz de executar algoritimos de compressão de dados com eficiência, sem perdas significates de
performance comprova a capacidade do WebAssembly. Alem disso com a redução dos dados trafegados 
esperasse uma redução destes custos.

### Cenarios de teste

* C1 - Comprimir e descomprimir 100 MB de imagens TIFF
* C2 - Comprimir e descomprimir 200 MB de imagens TIFF
* C3 - Comprimir e descomprimir 300 MB de imagens TIFF
* C4 - Comprimir e descomprimir 500 MB de imagens TIFF
* C5 - Comprimir e descomprimir 800 MB de imagens TIFF

### Analise: 
Contabilizar os tempos e para compresão e decompressão e taxas de compressão.
Comparar resultados entre browsers com WebAssembly e aplicação nativa.

## Opção 2 - Sistema de Extração de Faces com Opencv 

### Descrição
A partir do metodo Haar Cascades implmentado na versão 4.0.1 do 
opencv será feito a extração de faces de um video ou conjunto de imagens.

### Vialbilidade
O openCV é um concjunto de biblioteca de processmantos de imagens e visão computacional,
o qual fornece uma implmentação padrão do [Haar Cascades](https://docs.opencv.org/4.0.1/d7/d8b/tutorial_py_face_detection.html).

### Justificativa
Atualmente promover uma melhor experiência dos ususarios de aplicações é um fator crucial para o sucesso ou não. 
Com isso as aplicações web estão ficando cada vez mais sofisticadas e exigentes de recursos computacionais, ser capaz de executar 
processas de reconhecimento de imagem com eficiência no browser comprava que o WebAssembly de fato é capaz de promover maior 
poder computacional as aplicações web.

### Cenarios de teste

* C1 - Extrair faces de conjunto de 100 MB de imagens
* C2 - Extrair faces de conjunto de 200 MB de imagens
* C3 - Extrair faces de conjunto de 300 MB de imagens
* C4 - Extrair faces de conjunto de 500 MB de imagens
* C5 - Extrair faces de conjunto de 800 MB de imagens

### Analise

Contabilizar o tempo de execução para extração das faces.
Comparar resultados entre browsers com WebAssembly e aplicação nativa.


https://www.analyticsvidhya.com/blog/2018/07/top-10-pretrained-models-get-started-deep-learning-part-1-computer-vision/

https://medium.com/@jonathan_hui/real-time-object-detection-with-yolo-yolov2-28b1b93e2088

https://pjreddie.com/darknet/yolo/


http://www.viratdata.org/

http://www.lvc.ele.puc-rio.br/projects/video_surveillance/databases.html
https://sites.google.com/site/meltemdemirkus/mcgill-unconstrained-face-video-database


http://www.cvpapers.com/datasets.html


http://www.cs.tau.ac.il/~wolf/ytfaces/

Login: wolftau
Password: wtal997


https://www.gti.ssr.upm.es/data/vicocos3d.html

https://www.gti.ssr.upm.es/research/gti-data/databases
