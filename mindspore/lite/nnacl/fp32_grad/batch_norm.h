/**
 * Copyright 2019 Huawei Technologies Co., Ltd
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

#ifndef MINDSPORE_LITE_NNACL_FP32_BATCH_NORM_H_
#define MINDSPORE_LITE_NNACL_FP32_BATCH_NORM_H_

#include "nnacl/op_base.h"

typedef struct BNGradParameter {
  OpParameter op_parameter_;
  float epsilon_;
  float momentum_;
} BNGradParameter;

#ifdef __cplusplus
extern "C" {
#endif

void sumSpatialBatch(const float *in, int size, int ch, float *out);
void scaleBias(const float *scales, int batch, int n, int size, float *output);
void normalize(const float *x, const float *mean, const float *invar, int batch, int filters, int spatial, float *out);
void backwardScale(const float *x, const float *mean, const float *invar, const float *delta, int batch, int n,
                   int size, float *scale_updates);
void meanVar(const float *in, int batch, int size, int ch, float eps, float *mean, float *invar);
void meanDelta(float *yt, int size, int ch, float *invar, float *mean_delta);
void varianceDelta(const float *x, const float *delta, const float *mean, const float *invar, int batch, int ch,
                   int spatial, float *variance_delta);
void meanAdd(const float *x, const float *mean, const float *variance_delta, int batch, int filters, int spatial,
             float *mean_add, float *mean_delta);
void NormalizeDelta(const float *x, const float *mean, const float *invar, const float *mean_delta,
                    const float *variance_delta, int batch, int filters, int spatial, float *delta);
#ifdef __cplusplus
}
#endif

#endif  // MINDSPORE_LITE_NNACL_FP32_BATCH_NORM_H_