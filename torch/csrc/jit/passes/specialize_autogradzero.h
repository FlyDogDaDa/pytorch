#pragma once

#include <torch/csrc/jit/ir/ir.h>

namespace torch::jit {

// propagate autograd zero information through a gradient graph and
// remove grad_of blocks if present.
// Note: this is a very limited pass. It only propagates autograd zeros for
// operations generated by the symbolic autodiff code and cleans up
// AutogradAdds when possible. Outputs of other nodes are conservatively
// marked Unknown and not optimized.
TORCH_API void specializeAutogradZero(std::shared_ptr<Graph> g);

struct ProfilingRecord;

TORCH_API void InsertProfileNodesForSpecializeAutogradZero(ProfilingRecord* pr);

} // namespace torch::jit
