#include <detectorsz/detectorsz.hpp>
namespace detectorsz {
ImageWrapper::ImageWrapper() {
  this->size = 0;
  this->rows = 0;
  this->cols = 0;
  this->cvType = CV_TYPE_DEFAULT;
  this->size = 0;
  this->data = nullptr;
}

ImageWrapper::ImageWrapper(int rows, int cols, size_t size) {
  this->size = size;
  this->rows = rows;
  this->cols = cols;
  this->cvType = CV_TYPE_DEFAULT;
  this->size = size;
  this->data = nullptr;
}

ImageWrapper::ImageWrapper(int rows, int cols, int cvType, size_t size) {
  this->size = size;
  this->rows = rows;
  this->cols = cols;
  this->cvType = cvType;
  this->size = size;
  this->data = nullptr;
}

ImageWrapper::~ImageWrapper() {
  data = nullptr;
  delete[] data;
}

unsigned char *ImageWrapper::getData() { return data; }

void ImageWrapper::copyData(unsigned char *_data) {
  //data = new unsigned char[size];
  data = _data;
  //memcpy(data, _data, size);
}
} // namespace detectorsz
