#include <string>
#include "utils/semantic_version_utils.h"

namespace cuda_toolkit_utils {
// those semantic versions are based on: https://docs.nvidia.com/deeplearning/cudnn/latest/reference/support-matrix.html#f1
inline std::string GetCompatibleCudaToolkitVersion(
    const std::string& driver_semantic_version, const std::string& os,
    const std::string& engine) {

  if (engine == "cortex.tensorrt-llm") {
    // if the engine is cortex.tensorrt-llm, the minimum required CUDA version is 12.4
    if (os == "windows") {
      if (semantic_version_utils::CompareSemanticVersion(
              driver_semantic_version, "527.41") >= 0) {
        return "12.4";
      } else {
        throw std::runtime_error(
            "GPU driver version not supported. Minimum "
            "required driver version is 527.41");
      }
    } else if (os == "linux") {
      if (semantic_version_utils::CompareSemanticVersion(
              driver_semantic_version, "525.60.13") >= 0) {
        return "12.4";
      } else {
        throw std::runtime_error(
            "GPU driver version not supported. Minimum required driver version "
            "is 525.60.13");
      }
    } else {
      throw std::runtime_error("Unsupported OS");
    }
  }

  if (os == "windows") {
    if (semantic_version_utils::CompareSemanticVersion(driver_semantic_version,
                                                       "527.41") >= 0) {
      return "12.4";
    } else if (semantic_version_utils::CompareSemanticVersion(
                   driver_semantic_version, "452.39") >= 0) {
      return "11.7";
    } else {
      throw std::runtime_error(
          "GPU driver version not supported. Minimum "
          "required driver version is 452.39");
    }
  } else if (os == "linux") {
    if (semantic_version_utils::CompareSemanticVersion(driver_semantic_version,
                                                       "525.60.13") >= 0) {
      return "12.4";
    } else if (semantic_version_utils::CompareSemanticVersion(
                   driver_semantic_version, "450.80.02") >= 0) {
      return "11.7";
    } else {
      throw std::runtime_error(
          "GPU driver version not supported. Minimum "
          "required driver version is 450.80.02");
    }
  } else {
    throw std::runtime_error("Unsupported OS");
  }
}
}  // namespace cuda_toolkit_utils