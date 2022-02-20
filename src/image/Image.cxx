#include "Image.hxx"

#include <opencv2/opencv.hpp>

namespace creative {
namespace image {

Image::Image(const nonstd::string_view& path) {
  cv::Mat img = cv::imread(to_string(path));
  cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
  img.convertTo(img, CV_32FC3, 1 / 255.0);
  torch::Tensor img_tensor =
      torch::from_blob(img.data, {img.rows, img.cols, 3}, torch::kFloat);
  img_tensor = img_tensor.permute({2, 0, 1});
  m_tensor_ptr = new torch::Tensor(img_tensor);
  std::cout << *m_tensor_ptr << '\n';
}

// size_t Image::width() const {

// }

// size_t Image::height() const {

// }

// size_t Image::channels() const {

// }

}  // namespace image
}  // namespace creative

// std::ostream& operator<<(std::ostream& os, const creative::image::Image&
// image)
// {
//     os << *(image.m_tensor_ptr);
//     return os;
// }
