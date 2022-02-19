// torch::Tensor read_image(const std::string& imageName)
// {
//     cv::Mat img = cv::imread(imageName);

//     cv::resize(img, img, cv::Size(224,224));

//     cv::cvtColor(img, img, cv::COLOR_BGR2RGB);

//     img.convertTo( img, CV_32FC3, 1/255.0 );

//     torch::Tensor img_tensor = torch::from_blob(img.data, {img.rows,
//     img.cols, 3}, torch::kFloat); img_tensor = img_tensor.permute({2, 0, 1});

//     img_tensor = torch::data::transforms::Normalize<>(norm_mean,
//     norm_std)(img_tensor);

//     return img_tensor.clone();
// }

#include "Image.hxx"

#include <opencv2/opencv.hpp>

namespace creative {
namespace image {

Image::Image(const nonstd::string_view& path) {
  cv::Mat img = cv::imread(to_string(path));
}

}  // namespace image
}  // namespace creative