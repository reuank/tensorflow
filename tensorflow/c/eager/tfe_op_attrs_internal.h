/* Copyright 2017 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#ifndef TENSORFLOW_C_EAGER_TFE_OP_ATTRS_INTERNAL_H_
#define TENSORFLOW_C_EAGER_TFE_OP_ATTRS_INTERNAL_H_

#include <algorithm>
#include <cstddef>
#include <map>
#include <memory>
#include <queue>
#include <string>
#include <vector>

#include "tensorflow/c/eager/tfe_context_internal.h"
#include "tensorflow/c/eager/tfe_op_internal.h"
#include "tensorflow/c/tf_status.h"
#include "tensorflow/core/common_runtime/eager/attr_builder.h"
#include "tensorflow/core/framework/attr_value.pb.h"

// An equivalent of a tensorflow::NameAttrList protocol buffer, but used in ways
// that sometimes do not require serialization.
struct TFE_OpAttrs {
  explicit TFE_OpAttrs() : attributes(nullptr) {}

  explicit TFE_OpAttrs(const tensorflow::AttrBuilder* value)
      : attributes(value) {}

  const tensorflow::AttrBuilder* attributes;
};

namespace tensorflow {
// Set an AttrValue on the op. Doesn't handle the list types.
void SetOpAttrValueScalar(TFE_Context* ctx, TFE_Op* op,
                          const tensorflow::AttrValue& default_value,
                          const char* attr_name, TF_Status* status);
}  // namespace tensorflow

#endif  // TENSORFLOW_C_EAGER_TFE_OP_ATTRS_INTERNAL_H_
