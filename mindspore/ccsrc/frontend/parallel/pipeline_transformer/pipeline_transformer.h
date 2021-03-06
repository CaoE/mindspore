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

#ifndef MINDSPORE_CCSRC_FRONTEND_PARALLEL_PIPELINE_TRANSFORMER_PIPELINE_TRANSFORMER_H_
#define MINDSPORE_CCSRC_FRONTEND_PARALLEL_PIPELINE_TRANSFORMER_PIPELINE_TRANSFORMER_H_

#include <utility>
#include "ir/value.h"
#include "ir/graph_utils.h"
#include "base/base.h"

namespace mindspore {
namespace parallel {
typedef struct {
  ValueListPtr shape;
  TypePtr type;
  AnfNodePtr depend;
} SendAttr;

class PipelineTransformer {
 public:
  PipelineTransformer(const FuncGraphManagerPtr &manager, const int &stage, const FuncGraphPtr &root,
                      const int64_t &global_rank, const int64_t &per_stage_rank_num)
      : manager_(manager),
        stage_(stage),
        root_(root),
        global_rank_(global_rank),
        per_stage_rank_num_(per_stage_rank_num) {}
  void Coloring();
  void BroadCastColoring();
  void HandleSharedParameter();
  void CutGraph();
  void ParameterColoring();
  void CoverSensShape();
  void ElimGraphStage();
  void ElimParameter();

 private:
  void DoBroadCast(const FuncGraphPtr &func);
  SendAttr InsertSend(const FuncGraphPtr &graph, const AnfNodePtr &parameter, const int &user_node_stage,
                      const int &node_stage);
  void InsertReceive(const FuncGraphPtr &graph, const AnfNodePtr &node, const AnfNodePtr &use_node, const int &index,
                     const int &user_node_stage, const int &node_stage);
  void CutBorder(const FuncGraphPtr &graph);
  void ElimRootParameter();
  bool IsStageNode(const CNodePtr &node);
  std::pair<CNodePtr, FuncGraphPtr> FindSensNode();
  FuncGraphManagerPtr manager_;
  int64_t stage_;
  FuncGraphPtr root_;
  int64_t global_rank_;
  int64_t per_stage_rank_num_;
  TypePtr type_ptr_;
  ValueListPtr shape_;
};
}  // namespace parallel
}  // namespace mindspore

#endif  // MINDSPORE_CCSRC_FRONTEND_PARALLEL_PIPELINE_TRANSFORMER_PIPELINE_TRANSFORMER_H_
