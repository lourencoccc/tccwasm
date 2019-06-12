#include <detectorsz/detectorsz.hpp>

namespace detectorsz {

MatAdapter::MatAdapter() {}

MatAdapter::MatAdapter(int rows, int cols) {
  matImg.create(rows, cols, CV_8UC4);
}

MatAdapter::MatAdapter(int rows, int cols, int cvType) {
  matImg.create(rows, cols, cvType);
}

MatAdapter::~MatAdapter() { matImg.release(); }

unsigned char *MatAdapter::getData() { return matImg.data; }

void MatAdapter::setData(unsigned char *_data) { matImg.data = _data; }

} // namespace detectorsz
