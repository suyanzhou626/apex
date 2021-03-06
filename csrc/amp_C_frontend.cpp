#include <torch/extension.h>

void multi_tensor_scale_cuda(
  int chunk_size,
  at::Tensor noop_flag,
  std::vector<std::vector<at::Tensor>> tensor_lists,
  float scale);

void multi_tensor_axpby_cuda(
  int chunk_size,
  at::Tensor noop_flag,
  std::vector<std::vector<at::Tensor>> tensor_lists,
  float a,
  float b);

PYBIND11_MODULE(TORCH_EXTENSION_NAME, m) {
  m.def("multi_tensor_scale", &multi_tensor_scale_cuda,
        "Fused overflow check + scale for a list of contiguous tensors");
  m.def("multi_tensor_axpby", &multi_tensor_axpby_cuda,
        "out = a*x + b*y for a list of contiguous tensors");
}
