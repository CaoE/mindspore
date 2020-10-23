/**
 * Copyright 2020 Huawei Technologies Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "minddata/dataset/include/transforms.h"
#include "minddata/dataset/include/vision.h"
#include "minddata/dataset/kernels/image/image_utils.h"

// Kernel image headers (in alphabetical order)
#include "minddata/dataset/kernels/image/center_crop_op.h"
#include "minddata/dataset/kernels/image/crop_op.h"
#include "minddata/dataset/kernels/image/cutmix_batch_op.h"
#include "minddata/dataset/kernels/image/cut_out_op.h"
#include "minddata/dataset/kernels/image/decode_op.h"
#include "minddata/dataset/kernels/image/hwc_to_chw_op.h"
#include "minddata/dataset/kernels/image/mixup_batch_op.h"
#include "minddata/dataset/kernels/image/normalize_op.h"
#include "minddata/dataset/kernels/image/pad_op.h"
#include "minddata/dataset/kernels/image/random_affine_op.h"
#include "minddata/dataset/kernels/image/random_color_op.h"
#include "minddata/dataset/kernels/image/random_color_adjust_op.h"
#include "minddata/dataset/kernels/image/random_crop_and_resize_op.h"
#include "minddata/dataset/kernels/image/random_crop_op.h"
#include "minddata/dataset/kernels/image/random_crop_decode_resize_op.h"
#include "minddata/dataset/kernels/image/random_horizontal_flip_op.h"
#include "minddata/dataset/kernels/image/random_posterize_op.h"
#include "minddata/dataset/kernels/image/random_rotation_op.h"
#include "minddata/dataset/kernels/image/random_sharpness_op.h"
#include "minddata/dataset/kernels/image/random_solarize_op.h"
#include "minddata/dataset/kernels/image/random_vertical_flip_op.h"
#include "minddata/dataset/kernels/image/rescale_op.h"
#include "minddata/dataset/kernels/image/resize_op.h"
#include "minddata/dataset/kernels/image/rgba_to_bgr_op.h"
#include "minddata/dataset/kernels/image/rgba_to_rgb_op.h"
#include "minddata/dataset/kernels/image/swap_red_blue_op.h"
#include "minddata/dataset/kernels/image/uniform_aug_op.h"

namespace mindspore {
namespace dataset {
namespace api {

// Transform operations for computer vision.
namespace vision {

// FUNCTIONS TO CREATE VISION TRANSFORM OPERATIONS
// (In alphabetical order)

// Function to create CenterCropOperation.
std::shared_ptr<CenterCropOperation> CenterCrop(std::vector<int32_t> size) {
  auto op = std::make_shared<CenterCropOperation>(size);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create CropOperation.
std::shared_ptr<CropOperation> Crop(std::vector<int32_t> coordinates, std::vector<int32_t> size) {
  auto op = std::make_shared<CropOperation>(coordinates, size);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create CutMixBatchOperation.
std::shared_ptr<CutMixBatchOperation> CutMixBatch(ImageBatchFormat image_batch_format, float alpha, float prob) {
  auto op = std::make_shared<CutMixBatchOperation>(image_batch_format, alpha, prob);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create CutOutOp.
std::shared_ptr<CutOutOperation> CutOut(int32_t length, int32_t num_patches) {
  auto op = std::make_shared<CutOutOperation>(length, num_patches);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create DecodeOperation.
std::shared_ptr<DecodeOperation> Decode(bool rgb) {
  auto op = std::make_shared<DecodeOperation>(rgb);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create HwcToChwOperation.
std::shared_ptr<HwcToChwOperation> HWC2CHW() {
  auto op = std::make_shared<HwcToChwOperation>();
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create MixUpBatchOperation.
std::shared_ptr<MixUpBatchOperation> MixUpBatch(float alpha) {
  auto op = std::make_shared<MixUpBatchOperation>(alpha);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create NormalizeOperation.
std::shared_ptr<NormalizeOperation> Normalize(std::vector<float> mean, std::vector<float> std) {
  auto op = std::make_shared<NormalizeOperation>(mean, std);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create PadOperation.
std::shared_ptr<PadOperation> Pad(std::vector<int32_t> padding, std::vector<uint8_t> fill_value,
                                  BorderType padding_mode) {
  auto op = std::make_shared<PadOperation>(padding, fill_value, padding_mode);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create RandomAffineOperation.
std::shared_ptr<RandomAffineOperation> RandomAffine(const std::vector<float_t> &degrees,
                                                    const std::vector<float_t> &translate_range,
                                                    const std::vector<float_t> &scale_range,
                                                    const std::vector<float_t> &shear_ranges,
                                                    InterpolationMode interpolation,
                                                    const std::vector<uint8_t> &fill_value) {
  auto op = std::make_shared<RandomAffineOperation>(degrees, translate_range, scale_range, shear_ranges, interpolation,
                                                    fill_value);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create RandomColorOperation.
std::shared_ptr<RandomColorOperation> RandomColor(float t_lb, float t_ub) {
  auto op = std::make_shared<RandomColorOperation>(t_lb, t_ub);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

std::shared_ptr<TensorOp> RandomColorOperation::Build() {
  std::shared_ptr<RandomColorOp> tensor_op = std::make_shared<RandomColorOp>(t_lb_, t_ub_);
  return tensor_op;
}

// Function to create RandomColorAdjustOperation.
std::shared_ptr<RandomColorAdjustOperation> RandomColorAdjust(std::vector<float> brightness,
                                                              std::vector<float> contrast,
                                                              std::vector<float> saturation, std::vector<float> hue) {
  auto op = std::make_shared<RandomColorAdjustOperation>(brightness, contrast, saturation, hue);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create RandomCropOperation.
std::shared_ptr<RandomCropOperation> RandomCrop(std::vector<int32_t> size, std::vector<int32_t> padding,
                                                bool pad_if_needed, std::vector<uint8_t> fill_value,
                                                BorderType padding_mode) {
  auto op = std::make_shared<RandomCropOperation>(size, padding, pad_if_needed, fill_value, padding_mode);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create RandomCropDecodeResizeOperation.
std::shared_ptr<RandomCropDecodeResizeOperation> RandomCropDecodeResize(std::vector<int32_t> size,
                                                                        std::vector<float> scale,
                                                                        std::vector<float> ratio,
                                                                        InterpolationMode interpolation,
                                                                        int32_t max_attempts) {
  auto op = std::make_shared<RandomCropDecodeResizeOperation>(size, scale, ratio, interpolation, max_attempts);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create RandomHorizontalFlipOperation.
std::shared_ptr<RandomHorizontalFlipOperation> RandomHorizontalFlip(float prob) {
  auto op = std::make_shared<RandomHorizontalFlipOperation>(prob);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create RandomPosterizeOperation.
std::shared_ptr<RandomPosterizeOperation> RandomPosterize(const std::vector<uint8_t> &bit_range) {
  auto op = std::make_shared<RandomPosterizeOperation>(bit_range);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create RandomResizedCropOperation.
std::shared_ptr<RandomResizedCropOperation> RandomResizedCrop(std::vector<int32_t> size, std::vector<float> scale,
                                                              std::vector<float> ratio, InterpolationMode interpolation,
                                                              int32_t max_attempts) {
  auto op = std::make_shared<RandomResizedCropOperation>(size, scale, ratio, interpolation, max_attempts);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create RandomRotationOperation.
std::shared_ptr<RandomRotationOperation> RandomRotation(std::vector<float> degrees, InterpolationMode resample,
                                                        bool expand, std::vector<float> center,
                                                        std::vector<uint8_t> fill_value) {
  auto op = std::make_shared<RandomRotationOperation>(degrees, resample, expand, center, fill_value);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create RandomSharpnessOperation.
std::shared_ptr<RandomSharpnessOperation> RandomSharpness(std::vector<float> degrees) {
  auto op = std::make_shared<RandomSharpnessOperation>(degrees);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create RandomSolarizeOperation.
std::shared_ptr<RandomSolarizeOperation> RandomSolarize(std::vector<uint8_t> threshold) {
  auto op = std::make_shared<RandomSolarizeOperation>(threshold);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create RandomVerticalFlipOperation.
std::shared_ptr<RandomVerticalFlipOperation> RandomVerticalFlip(float prob) {
  auto op = std::make_shared<RandomVerticalFlipOperation>(prob);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create RescaleOperation.
std::shared_ptr<RescaleOperation> Rescale(float rescale, float shift) {
  auto op = std::make_shared<RescaleOperation>(rescale, shift);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create ResizeOperation.
std::shared_ptr<ResizeOperation> Resize(std::vector<int32_t> size, InterpolationMode interpolation) {
  auto op = std::make_shared<ResizeOperation>(size, interpolation);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create RgbaToBgrOperation.
std::shared_ptr<RgbaToBgrOperation> RGBA2BGR() {
  auto op = std::make_shared<RgbaToBgrOperation>();
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create RgbaToRgbOperation.
std::shared_ptr<RgbaToRgbOperation> RGBA2RGB() {
  auto op = std::make_shared<RgbaToRgbOperation>();
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create SwapRedBlueOperation.
std::shared_ptr<SwapRedBlueOperation> SwapRedBlue() {
  auto op = std::make_shared<SwapRedBlueOperation>();
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

// Function to create UniformAugOperation.
std::shared_ptr<UniformAugOperation> UniformAugment(std::vector<std::shared_ptr<TensorOperation>> transforms,
                                                    int32_t num_ops) {
  auto op = std::make_shared<UniformAugOperation>(transforms, num_ops);
  // Input validation
  if (!op->ValidateParams()) {
    return nullptr;
  }
  return op;
}

/* ####################################### Validator Functions ############################################ */
Status ValidateVectorPositive(const std::string &dataset_name, const std::vector<int32_t> &size) {
  for (int i = 0; i < size.size(); ++i) {
    if (size[i] <= 0) {
      std::string err_msg =
        dataset_name + ": Non-positive size value: " + std::to_string(size[i]) + " at element: " + std::to_string(i);
      MS_LOG(ERROR) << err_msg;
      RETURN_STATUS_SYNTAX_ERROR(err_msg);
    }
  }

  return Status::OK();
}

bool CmpFloat(const float &a, const float &b, float epsilon = 0.0000000001f) { return (std::fabs(a - b) < epsilon); }

/* ####################################### Derived TensorOperation classes ################################# */

// (In alphabetical order)

// CenterCropOperation
CenterCropOperation::CenterCropOperation(std::vector<int32_t> size) : size_(size) {}

Status CenterCropOperation::ValidateParams() {
  if (size_.empty() || size_.size() > 2) {
    std::string err_msg = "CenterCrop: size vector has incorrect size.";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  // We have to limit crop size due to library restrictions, optimized to only iterate over size_ once
  for (int i = 0; i < size_.size(); ++i) {
    if (size_[i] <= 0) {
      std::string err_msg = "CenterCrop: invalid size, size must be greater than 0, got: " + std::to_string(size_[i]);
      MS_LOG(ERROR) << err_msg;
      RETURN_STATUS_SYNTAX_ERROR(err_msg);
    }
    if (size_[i] == INT_MAX) {
      std::string err_msg = "CenterCrop: invalid size, size too large, got: " + std::to_string(size_[i]);
      MS_LOG(ERROR) << err_msg;
      RETURN_STATUS_SYNTAX_ERROR(err_msg);
    }
  }
  return Status::OK();
}

std::shared_ptr<TensorOp> CenterCropOperation::Build() {
  int32_t crop_height = size_[0];
  int32_t crop_width = 0;

  // User has specified crop_width.
  if (size_.size() == 2) {
    crop_width = size_[1];
  }

  std::shared_ptr<CenterCropOp> tensor_op = std::make_shared<CenterCropOp>(crop_height, crop_width);
  return tensor_op;
}

// CropOperation.
CropOperation::CropOperation(std::vector<int32_t> coordinates, std::vector<int32_t> size)
    : coordinates_(coordinates), size_(size) {}

Status CropOperation::ValidateParams() {
  // Do some input validation.
  if (coordinates_.size() != 2) {
    std::string err_msg = "Crop: coordinates must be a vector of two values";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  // we don't check the coordinates here because we don't have access to image dimensions
  if (size_.empty() || size_.size() > 2) {
    std::string err_msg = "Crop: size must be a vector of one or two values";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  // We have to limit crop size due to library restrictions, optimized to only iterate over size_ once
  for (int i = 0; i < size_.size(); ++i) {
    if (size_[i] <= 0) {
      std::string err_msg = "Crop: invalid size, size must be greater than 0, got: " + std::to_string(size_[i]);
      MS_LOG(ERROR) << err_msg;
      RETURN_STATUS_SYNTAX_ERROR(err_msg);
    }
    if (size_[i] == INT_MAX) {
      std::string err_msg = "Crop: invalid size, size too large, got: " + std::to_string(size_[i]);
      MS_LOG(ERROR) << err_msg;
      RETURN_STATUS_SYNTAX_ERROR(err_msg);
    }
  }
  for (int j = 0; j < coordinates_.size(); ++j) {
    if (coordinates_[j] < 0) {
      std::string err_msg =
        "Crop: invalid coordinates, coordinates must be greater than 0, got: " + std::to_string(coordinates_[j]);
      MS_LOG(ERROR) << err_msg;
      RETURN_STATUS_SYNTAX_ERROR(err_msg);
    }
  }
  return Status::OK();
}

std::shared_ptr<TensorOp> CropOperation::Build() {
  int32_t x, y, height, width;

  x = coordinates_[0];
  y = coordinates_[1];

  height = size_[0];
  width = size_[0];
  if (size_.size() == 2) {
    width = size_[1];
  }

  std::shared_ptr<CropOp> tensor_op = std::make_shared<CropOp>(x, y, height, width);
  return tensor_op;
}

// CutMixBatchOperation
CutMixBatchOperation::CutMixBatchOperation(ImageBatchFormat image_batch_format, float alpha, float prob)
    : image_batch_format_(image_batch_format), alpha_(alpha), prob_(prob) {}

Status CutMixBatchOperation::ValidateParams() {
  if (alpha_ <= 0) {
    std::string err_msg =
      "CutMixBatch: alpha must be a positive floating value however it is: " + std::to_string(alpha_);
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (prob_ < 0 || prob_ > 1) {
    std::string err_msg = "CutMixBatch: Probability has to be between 0 and 1.";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  return Status::OK();
}

std::shared_ptr<TensorOp> CutMixBatchOperation::Build() {
  std::shared_ptr<CutMixBatchOp> tensor_op = std::make_shared<CutMixBatchOp>(image_batch_format_, alpha_, prob_);
  return tensor_op;
}

// CutOutOperation
CutOutOperation::CutOutOperation(int32_t length, int32_t num_patches) : length_(length), num_patches_(num_patches) {}

Status CutOutOperation::ValidateParams() {
  if (length_ < 0) {
    std::string err_msg = "CutOut: length cannot be negative";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (num_patches_ < 0) {
    std::string err_msg = "CutOut: number of patches cannot be negative";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  return Status::OK();
}

std::shared_ptr<TensorOp> CutOutOperation::Build() {
  std::shared_ptr<CutOutOp> tensor_op = std::make_shared<CutOutOp>(length_, length_, num_patches_, false, 0, 0, 0);
  return tensor_op;
}

// DecodeOperation
DecodeOperation::DecodeOperation(bool rgb) : rgb_(rgb) {}

Status DecodeOperation::ValidateParams() { return Status::OK(); }

std::shared_ptr<TensorOp> DecodeOperation::Build() { return std::make_shared<DecodeOp>(rgb_); }

// HwcToChwOperation
Status HwcToChwOperation::ValidateParams() { return Status::OK(); }

std::shared_ptr<TensorOp> HwcToChwOperation::Build() { return std::make_shared<HwcToChwOp>(); }

// MixUpOperation
MixUpBatchOperation::MixUpBatchOperation(float alpha) : alpha_(alpha) {}

Status MixUpBatchOperation::ValidateParams() {
  if (alpha_ <= 0) {
    std::string err_msg =
      "MixUpBatch: alpha must be a positive floating value however it is: " + std::to_string(alpha_);
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }

  return Status::OK();
}

std::shared_ptr<TensorOp> MixUpBatchOperation::Build() { return std::make_shared<MixUpBatchOp>(alpha_); }

// NormalizeOperation
NormalizeOperation::NormalizeOperation(std::vector<float> mean, std::vector<float> std) : mean_(mean), std_(std) {}

Status NormalizeOperation::ValidateParams() {
  if (mean_.size() != 3) {
    std::string err_msg = "Normalize: mean vector has incorrect size: " + std::to_string(mean_.size());
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (std_.size() != 3) {
    std::string err_msg = "Normalize: std vector has incorrect size: " + std::to_string(std_.size());
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  // check std value
  for (int i = 0; i < std_.size(); ++i) {
    if (std_[i] < 0.0f || std_[i] > 255.0f || CmpFloat(std_[i], 0.0f)) {
      std::string err_msg = "Normalize: std vector has incorrect value: " + std::to_string(std_[i]);
      MS_LOG(ERROR) << err_msg;
      RETURN_STATUS_SYNTAX_ERROR(err_msg);
    }
  }
  return Status::OK();
}

std::shared_ptr<TensorOp> NormalizeOperation::Build() {
  return std::make_shared<NormalizeOp>(mean_[0], mean_[1], mean_[2], std_[0], std_[1], std_[2]);
}

// PadOperation
PadOperation::PadOperation(std::vector<int32_t> padding, std::vector<uint8_t> fill_value, BorderType padding_mode)
    : padding_(padding), fill_value_(fill_value), padding_mode_(padding_mode) {}

Status PadOperation::ValidateParams() {
  if (padding_.empty() || padding_.size() == 3 || padding_.size() > 4) {
    std::string err_msg = "Pad: padding vector has incorrect size: padding.size()";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }

  if (fill_value_.empty() || (fill_value_.size() != 1 && fill_value_.size() != 3)) {
    std::string err_msg = "Pad: fill_value vector has incorrect size: fill_value.size()";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  return Status::OK();
}

std::shared_ptr<TensorOp> PadOperation::Build() {
  int32_t pad_top, pad_bottom, pad_left, pad_right;
  switch (padding_.size()) {
    case 1:
      pad_left = padding_[0];
      pad_top = padding_[0];
      pad_right = padding_[0];
      pad_bottom = padding_[0];
      break;
    case 2:
      pad_left = padding_[0];
      pad_top = padding_[1];
      pad_right = padding_[0];
      pad_bottom = padding_[1];
      break;
    default:
      pad_left = padding_[0];
      pad_top = padding_[1];
      pad_right = padding_[2];
      pad_bottom = padding_[3];
  }
  uint8_t fill_r, fill_g, fill_b;

  fill_r = fill_value_[0];
  fill_g = fill_value_[0];
  fill_b = fill_value_[0];

  if (fill_value_.size() == 3) {
    fill_r = fill_value_[0];
    fill_g = fill_value_[1];
    fill_b = fill_value_[2];
  }

  std::shared_ptr<PadOp> tensor_op =
    std::make_shared<PadOp>(pad_top, pad_bottom, pad_left, pad_right, padding_mode_, fill_r, fill_g, fill_b);
  return tensor_op;
}

// RandomAffineOperation
RandomAffineOperation::RandomAffineOperation(const std::vector<float_t> &degrees,
                                             const std::vector<float_t> &translate_range,
                                             const std::vector<float_t> &scale_range,
                                             const std::vector<float_t> &shear_ranges, InterpolationMode interpolation,
                                             const std::vector<uint8_t> &fill_value)
    : degrees_(degrees),
      translate_range_(translate_range),
      scale_range_(scale_range),
      shear_ranges_(shear_ranges),
      interpolation_(interpolation),
      fill_value_(fill_value) {}

Status RandomAffineOperation::ValidateParams() {
  // Degrees
  if (degrees_.size() != 2) {
    std::string err_msg =
      "RandomAffine: degrees expecting size 2, got: degrees.size() = " + std::to_string(degrees_.size());
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (degrees_[0] > degrees_[1]) {
    std::string err_msg =
      "RandomAffine: minimum of degrees range is greater than maximum: min = " + std::to_string(degrees_[0]) +
      ", max = " + std::to_string(degrees_[1]);
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  // Translate
  if (translate_range_.size() != 2 && translate_range_.size() != 4) {
    std::string err_msg = "RandomAffine: translate_range expecting size 2 or 4, got: translate_range.size() = " +
                          std::to_string(translate_range_.size());
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (translate_range_[0] > translate_range_[1]) {
    std::string err_msg = "RandomAffine: minimum of translate range on x is greater than maximum: min = " +
                          std::to_string(translate_range_[0]) + ", max = " + std::to_string(translate_range_[1]);
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (translate_range_[0] < -1 || translate_range_[0] > 1) {
    std::string err_msg = "RandomAffine: minimum of translate range on x is out of range of [-1, 1], value = " +
                          std::to_string(translate_range_[0]);
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (translate_range_[1] < -1 || translate_range_[1] > 1) {
    std::string err_msg = "RandomAffine: maximum of translate range on x is out of range of [-1, 1], value = " +
                          std::to_string(translate_range_[1]);
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (translate_range_.size() == 4) {
    if (translate_range_[2] > translate_range_[3]) {
      std::string err_msg = "RandomAffine: minimum of translate range on y is greater than maximum: min = " +
                            std::to_string(translate_range_[2]) + ", max = " + std::to_string(translate_range_[3]);
      MS_LOG(ERROR) << err_msg;
      RETURN_STATUS_SYNTAX_ERROR(err_msg);
    }
    if (translate_range_[2] < -1 || translate_range_[2] > 1) {
      std::string err_msg = "RandomAffine: minimum of translate range on y is out of range of [-1, 1], value = " +
                            std::to_string(translate_range_[2]);
      MS_LOG(ERROR) << err_msg;
      RETURN_STATUS_SYNTAX_ERROR(err_msg);
    }
    if (translate_range_[3] < -1 || translate_range_[3] > 1) {
      std::string err_msg = "RandomAffine: maximum of translate range on y is out of range of [-1, 1], value = " +
                            std::to_string(translate_range_[3]);
      MS_LOG(ERROR) << err_msg;
      RETURN_STATUS_SYNTAX_ERROR(err_msg);
    }
  }
  // Scale
  if (scale_range_.size() != 2) {
    std::string err_msg = "RandomAffine: scale_range vector has incorrect size: scale_range.size() = " +
                          std::to_string(scale_range_.size());
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (scale_range_[0] > scale_range_[1]) {
    std::string err_msg =
      "RandomAffine: minimum of scale range is greater than maximum: min = " + std::to_string(scale_range_[0]) +
      ", max = " + std::to_string(scale_range_[1]);
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  // Shear
  if (shear_ranges_.size() != 2 && shear_ranges_.size() != 4) {
    std::string err_msg = "RandomAffine: shear_ranges expecting size 2 or 4, got: shear_ranges.size() = " +
                          std::to_string(shear_ranges_.size());
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (shear_ranges_[0] > shear_ranges_[1]) {
    std::string err_msg = "RandomAffine: minimum of horizontal shear range is greater than maximum: min = " +
                          std::to_string(shear_ranges_[0]) + ", max = " + std::to_string(shear_ranges_[1]);
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (shear_ranges_.size() == 4 && shear_ranges_[2] > shear_ranges_[3]) {
    std::string err_msg = "RandomAffine: minimum of vertical shear range is greater than maximum: min = " +
                          std::to_string(shear_ranges_[2]) + ", max = " + std::to_string(scale_range_[3]);
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  // Fill Value
  if (fill_value_.size() != 3) {
    std::string err_msg =
      "RandomAffine: fill_value vector has incorrect size: fill_value.size() = " + std::to_string(fill_value_.size());
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  return Status::OK();
}

std::shared_ptr<TensorOp> RandomAffineOperation::Build() {
  if (shear_ranges_.size() == 2) {
    shear_ranges_.resize(4);
  }
  if (translate_range_.size() == 2) {
    translate_range_.resize(4);
  }
  auto tensor_op = std::make_shared<RandomAffineOp>(degrees_, translate_range_, scale_range_, shear_ranges_,
                                                    interpolation_, fill_value_);
  return tensor_op;
}

// RandomColorOperation.
RandomColorOperation::RandomColorOperation(float t_lb, float t_ub) : t_lb_(t_lb), t_ub_(t_ub) {}

Status RandomColorOperation::ValidateParams() {
  // Do some input validation.
  if (t_lb_ > t_ub_) {
    std::string err_msg = "RandomColor: lower bound must be less or equal to upper bound";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  return Status::OK();
}

// RandomColorAdjustOperation.
RandomColorAdjustOperation::RandomColorAdjustOperation(std::vector<float> brightness, std::vector<float> contrast,
                                                       std::vector<float> saturation, std::vector<float> hue)
    : brightness_(brightness), contrast_(contrast), saturation_(saturation), hue_(hue) {}

Status RandomColorAdjustOperation::ValidateParams() {
  // Do some input validation.
  if (brightness_.empty() || brightness_.size() > 2) {
    std::string err_msg = "RandomColorAdjust: brightness must be a vector of one or two values";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (contrast_.empty() || contrast_.size() > 2) {
    std::string err_msg = "RandomColorAdjust: contrast must be a vector of one or two values";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (saturation_.empty() || saturation_.size() > 2) {
    std::string err_msg = "RandomColorAdjust: saturation must be a vector of one or two values";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (hue_.empty() || hue_.size() > 2) {
    std::string err_msg = "RandomColorAdjust: hue must be a vector of one or two values";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  return Status::OK();
}

std::shared_ptr<TensorOp> RandomColorAdjustOperation::Build() {
  float brightness_lb, brightness_ub, contrast_lb, contrast_ub, saturation_lb, saturation_ub, hue_lb, hue_ub;

  brightness_lb = brightness_[0];
  brightness_ub = brightness_[0];

  if (brightness_.size() == 2) brightness_ub = brightness_[1];

  contrast_lb = contrast_[0];
  contrast_ub = contrast_[0];

  if (contrast_.size() == 2) contrast_ub = contrast_[1];

  saturation_lb = saturation_[0];
  saturation_ub = saturation_[0];

  if (saturation_.size() == 2) saturation_ub = saturation_[1];

  hue_lb = hue_[0];
  hue_ub = hue_[0];

  if (hue_.size() == 2) hue_ub = hue_[1];

  std::shared_ptr<RandomColorAdjustOp> tensor_op = std::make_shared<RandomColorAdjustOp>(
    brightness_lb, brightness_ub, contrast_lb, contrast_ub, saturation_lb, saturation_ub, hue_lb, hue_ub);
  return tensor_op;
}

// RandomCropOperation
RandomCropOperation::RandomCropOperation(std::vector<int32_t> size, std::vector<int32_t> padding, bool pad_if_needed,
                                         std::vector<uint8_t> fill_value, BorderType padding_mode)
    : size_(size),
      padding_(padding),
      pad_if_needed_(pad_if_needed),
      fill_value_(fill_value),
      padding_mode_(padding_mode) {}

Status RandomCropOperation::ValidateParams() {
  if (size_.empty() || size_.size() > 2) {
    std::string err_msg = "RandomCrop: size vector has incorrect size: " + std::to_string(size_.size());
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }

  if (padding_.empty() || padding_.size() != 4) {
    std::string err_msg = "RandomCrop: padding vector has incorrect size: padding.size()";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }

  if (fill_value_.empty() || fill_value_.size() != 3) {
    std::string err_msg = "RandomCrop: fill_value vector has incorrect size: fill_value.size()";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  return Status::OK();
}

std::shared_ptr<TensorOp> RandomCropOperation::Build() {
  int32_t crop_height = size_[0];
  int32_t crop_width = 0;

  int32_t pad_top = padding_[0];
  int32_t pad_bottom = padding_[1];
  int32_t pad_left = padding_[2];
  int32_t pad_right = padding_[3];

  uint8_t fill_r = fill_value_[0];
  uint8_t fill_g = fill_value_[1];
  uint8_t fill_b = fill_value_[2];

  // User has specified the crop_width value.
  if (size_.size() == 2) {
    crop_width = size_[1];
  }

  auto tensor_op = std::make_shared<RandomCropOp>(crop_height, crop_width, pad_top, pad_bottom, pad_left, pad_right,
                                                  padding_mode_, pad_if_needed_, fill_r, fill_g, fill_b);
  return tensor_op;
}

// RandomCropDecodeResizeOperation
RandomCropDecodeResizeOperation::RandomCropDecodeResizeOperation(std::vector<int32_t> size, std::vector<float> scale,
                                                                 std::vector<float> ratio,
                                                                 InterpolationMode interpolation, int32_t max_attempts)
    : size_(size), scale_(scale), ratio_(ratio), interpolation_(interpolation), max_attempts_(max_attempts) {}

Status RandomCropDecodeResizeOperation::ValidateParams() {
  if (size_.empty() || size_.size() > 2) {
    std::string err_msg = "RandomCropDecodeResize: size vector has incorrect size: " + std::to_string(size_.size());
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }

  if (scale_.empty() || scale_.size() != 2) {
    std::string err_msg = "RandomCropDecodeResize: scale vector has incorrect size: " + std::to_string(scale_.size());
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }

  if (scale_[0] > scale_[1]) {
    std::string err_msg = "RandomCropDecodeResize: scale should be in (min,max) format. Got (max,min).";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }

  if (ratio_.empty() || ratio_.size() != 2) {
    std::string err_msg = "RandomCropDecodeResize: ratio vector has incorrect size: " + std::to_string(ratio_.size());
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }

  if (ratio_[0] > ratio_[1]) {
    std::string err_msg = "RandomCropDecodeResize: ratio should be in (min,max) format. Got (max,min).";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }

  if (max_attempts_ < 1) {
    std::string err_msg = "RandomCropDecodeResize: max_attempts must be greater than or equal to 1.";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  return Status::OK();
}

std::shared_ptr<TensorOp> RandomCropDecodeResizeOperation::Build() {
  int32_t crop_height = size_[0];
  int32_t crop_width = size_[0];

  // User has specified the crop_width value.
  if (size_.size() == 2) {
    crop_width = size_[1];
  }

  float scale_lower_bound = scale_[0];
  float scale_upper_bound = scale_[1];

  float aspect_lower_bound = ratio_[0];
  float aspect_upper_bound = ratio_[1];

  auto tensor_op =
    std::make_shared<RandomCropDecodeResizeOp>(crop_height, crop_width, scale_lower_bound, scale_upper_bound,
                                               aspect_lower_bound, aspect_upper_bound, interpolation_, max_attempts_);
  return tensor_op;
}

// RandomHorizontalFlipOperation
RandomHorizontalFlipOperation::RandomHorizontalFlipOperation(float probability) : probability_(probability) {}

Status RandomHorizontalFlipOperation::ValidateParams() {
  if (probability_ < 0.0 || probability_ > 1.0) {
    std::string err_msg = "RandomHorizontalFlip: probability must be between 0.0 and 1.0.";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }

  return Status::OK();
}

std::shared_ptr<TensorOp> RandomHorizontalFlipOperation::Build() {
  std::shared_ptr<RandomHorizontalFlipOp> tensor_op = std::make_shared<RandomHorizontalFlipOp>(probability_);
  return tensor_op;
}

// RandomPosterizeOperation
RandomPosterizeOperation::RandomPosterizeOperation(const std::vector<uint8_t> &bit_range) : bit_range_(bit_range) {}

Status RandomPosterizeOperation::ValidateParams() {
  if (bit_range_.size() != 2) {
    std::string err_msg =
      "RandomPosterize: bit_range needs to be of size 2 but is of size: " + std::to_string(bit_range_.size());
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (bit_range_[0] < 1 || bit_range_[0] > 8) {
    std::string err_msg = "RandomPosterize: min_bit value is out of range [1-8]: " + std::to_string(bit_range_[0]);
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (bit_range_[1] < 1 || bit_range_[1] > 8) {
    std::string err_msg = "RandomPosterize: max_bit value is out of range [1-8]: " + std::to_string(bit_range_[1]);
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (bit_range_[1] < bit_range_[0]) {
    std::string err_msg = "RandomPosterize: max_bit value is less than min_bit: max =" + std::to_string(bit_range_[1]) +
                          ", min = " + std::to_string(bit_range_[0]);
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  return Status::OK();
}

std::shared_ptr<TensorOp> RandomPosterizeOperation::Build() {
  std::shared_ptr<RandomPosterizeOp> tensor_op = std::make_shared<RandomPosterizeOp>(bit_range_);
  return tensor_op;
}

// RandomResizedCropOperation
RandomResizedCropOperation::RandomResizedCropOperation(std::vector<int32_t> size, std::vector<float> scale,
                                                       std::vector<float> ratio, InterpolationMode interpolation,
                                                       int32_t max_attempts)
    : size_(size), scale_(scale), ratio_(ratio), interpolation_(interpolation), max_attempts_(max_attempts) {}
Status RandomResizedCropOperation::ValidateParams() {
  if (size_.size() != 2 && size_.size() != 1) {
    std::string err_msg = "RandomResizedCrop: size variable must have a length of 1 or 2 but it has a length of: " +
                          std::to_string(size_.size());
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (size_[0] < 0 || (size_.size() == 2 && size_[1] < 0)) {
    std::string err_msg = "RandomResizedCrop: size variable must only contain positive integers.";
    MS_LOG(ERROR) << "RandomResizedCrop: size variable must only contain positive integers. However, it is: " << size_;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (scale_.size() != 2 || scale_[1] < scale_[0]) {
    std::string err_msg = "RandomResizedCrop: scale variable must have a size of two in the format of (min, max).";
    MS_LOG(ERROR)
      << "RandomResizedCrop: scale variable must have a size of two in the format of (min, max). However, it is: "
      << scale_;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (ratio_.size() != 2 || ratio_[1] < ratio_[0]) {
    std::string err_msg = "RandomResizedCrop: ratio variable must be in the format of (min, max).";
    MS_LOG(ERROR) << "RandomResizedCrop: ratio variable must be in the format of (min, max). However , it is: "
                  << ratio_;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  return Status::OK();
}

std::shared_ptr<TensorOp> RandomResizedCropOperation::Build() {
  int32_t height = size_[0], width = size_[0];
  if (size_.size() == 2) width = size_[1];
  std::shared_ptr<RandomCropAndResizeOp> tensor_op = std::make_shared<RandomCropAndResizeOp>(
    height, width, scale_[0], scale_[1], ratio_[0], ratio_[1], interpolation_, max_attempts_);
  return tensor_op;
}

// Function to create RandomRotationOperation.
RandomRotationOperation::RandomRotationOperation(std::vector<float> degrees, InterpolationMode interpolation_mode,
                                                 bool expand, std::vector<float> center,
                                                 std::vector<uint8_t> fill_value)
    : degrees_(degrees),
      interpolation_mode_(interpolation_mode),
      expand_(expand),
      center_(center),
      fill_value_(fill_value) {}

Status RandomRotationOperation::ValidateParams() {
  if (degrees_.empty() || degrees_.size() != 2) {
    std::string err_msg = "RandomRotation: degrees vector has incorrect size: degrees.size()";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (center_.empty() || center_.size() != 2) {
    std::string err_msg = "RandomRotation: center vector has incorrect size: center.size()";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (fill_value_.empty() || fill_value_.size() != 3) {
    std::string err_msg = "RandomRotation: fill_value vector has incorrect size: fill_value.size()";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  return Status::OK();
}

std::shared_ptr<TensorOp> RandomRotationOperation::Build() {
  std::shared_ptr<RandomRotationOp> tensor_op =
    std::make_shared<RandomRotationOp>(degrees_[0], degrees_[1], center_[0], center_[1], interpolation_mode_, expand_,
                                       fill_value_[0], fill_value_[1], fill_value_[2]);
  return tensor_op;
}

// Function to create RandomSharpness.
RandomSharpnessOperation::RandomSharpnessOperation(std::vector<float> degrees) : degrees_(degrees) {}

Status RandomSharpnessOperation::ValidateParams() {
  if (degrees_.empty() || degrees_.size() != 2) {
    std::string err_msg = "RandomSharpness: degrees vector has incorrect size: degrees.size()";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  return Status::OK();
}

std::shared_ptr<TensorOp> RandomSharpnessOperation::Build() {
  std::shared_ptr<RandomSharpnessOp> tensor_op = std::make_shared<RandomSharpnessOp>(degrees_[0], degrees_[1]);
  return tensor_op;
}

// RandomSolarizeOperation.
RandomSolarizeOperation::RandomSolarizeOperation(std::vector<uint8_t> threshold) : threshold_(threshold) {}

Status RandomSolarizeOperation::ValidateParams() {
  if (threshold_.size() != 2) {
    std::string err_msg = "RandomSolarize: threshold vector has incorrect size: " + std::to_string(threshold_.size());
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  if (threshold_.at(0) > threshold_.at(1)) {
    std::string err_msg = "RandomSolarize: threshold must be passed in a min, max format";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  return Status::OK();
}

std::shared_ptr<TensorOp> RandomSolarizeOperation::Build() {
  std::shared_ptr<RandomSolarizeOp> tensor_op = std::make_shared<RandomSolarizeOp>(threshold_);
  return tensor_op;
}

// RandomVerticalFlipOperation
RandomVerticalFlipOperation::RandomVerticalFlipOperation(float probability) : probability_(probability) {}

Status RandomVerticalFlipOperation::ValidateParams() {
  if (probability_ < 0.0 || probability_ > 1.0) {
    std::string err_msg = "RandomVerticalFlip: probability must be between 0.0 and 1.0.";
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }

  return Status::OK();
}

std::shared_ptr<TensorOp> RandomVerticalFlipOperation::Build() {
  std::shared_ptr<RandomVerticalFlipOp> tensor_op = std::make_shared<RandomVerticalFlipOp>(probability_);
  return tensor_op;
}

// RescaleOperation
RescaleOperation::RescaleOperation(float rescale, float shift) : rescale_(rescale), shift_(shift) {}

Status RescaleOperation::ValidateParams() {
  if (rescale_ < 0) {
    std::string err_msg =
      "Rescale: rescale must be greater than or equal to 0, got: rescale = " + std::to_string(rescale_);
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }
  return Status::OK();
}

std::shared_ptr<TensorOp> RescaleOperation::Build() {
  std::shared_ptr<RescaleOp> tensor_op = std::make_shared<RescaleOp>(rescale_, shift_);
  return tensor_op;
}

// ResizeOperation
ResizeOperation::ResizeOperation(std::vector<int32_t> size, InterpolationMode interpolation)
    : size_(size), interpolation_(interpolation) {}

Status ResizeOperation::ValidateParams() {
  if (size_.empty() || size_.size() > 2) {
    std::string err_msg = "Resize: size vector has incorrect size: " + std::to_string(size_.size());
    MS_LOG(ERROR) << err_msg;
    RETURN_STATUS_SYNTAX_ERROR(err_msg);
  }

  RETURN_IF_NOT_OK(ValidateVectorPositive("Resize", size_));

  return Status::OK();
}

std::shared_ptr<TensorOp> ResizeOperation::Build() {
  int32_t height = size_[0];
  int32_t width = 0;

  // User specified the width value.
  if (size_.size() == 2) {
    width = size_[1];
  }

  return std::make_shared<ResizeOp>(height, width, interpolation_);
}

// RgbaToBgrOperation.
RgbaToBgrOperation::RgbaToBgrOperation() {}

Status RgbaToBgrOperation::ValidateParams() { return Status::OK(); }

std::shared_ptr<TensorOp> RgbaToBgrOperation::Build() {
  std::shared_ptr<RgbaToBgrOp> tensor_op = std::make_shared<RgbaToBgrOp>();
  return tensor_op;
}

// RgbaToRgbOperation.
RgbaToRgbOperation::RgbaToRgbOperation() {}

Status RgbaToRgbOperation::ValidateParams() { return Status::OK(); }

std::shared_ptr<TensorOp> RgbaToRgbOperation::Build() {
  std::shared_ptr<RgbaToRgbOp> tensor_op = std::make_shared<RgbaToRgbOp>();
  return tensor_op;
}

// SwapRedBlueOperation.
SwapRedBlueOperation::SwapRedBlueOperation() {}

Status SwapRedBlueOperation::ValidateParams() { return Status::OK(); }

std::shared_ptr<TensorOp> SwapRedBlueOperation::Build() {
  std::shared_ptr<SwapRedBlueOp> tensor_op = std::make_shared<SwapRedBlueOp>();
  return tensor_op;
}

// UniformAugOperation
UniformAugOperation::UniformAugOperation(std::vector<std::shared_ptr<TensorOperation>> transforms, int32_t num_ops)
    : transforms_(transforms), num_ops_(num_ops) {}

Status UniformAugOperation::ValidateParams() { return Status::OK(); }

std::shared_ptr<TensorOp> UniformAugOperation::Build() {
  std::vector<std::shared_ptr<TensorOp>> tensor_ops;
  (void)std::transform(transforms_.begin(), transforms_.end(), std::back_inserter(tensor_ops),
                       [](std::shared_ptr<TensorOperation> op) -> std::shared_ptr<TensorOp> { return op->Build(); });
  std::shared_ptr<UniformAugOp> tensor_op = std::make_shared<UniformAugOp>(tensor_ops, num_ops_);
  return tensor_op;
}

}  // namespace vision
}  // namespace api
}  // namespace dataset
}  // namespace mindspore
