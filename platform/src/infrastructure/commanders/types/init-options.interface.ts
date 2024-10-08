export interface InitOptions {
  runMode?: 'CPU' | 'GPU';
  gpuType?: 'Nvidia' | 'Others (Vulkan)';
  instructions?: 'AVX' | 'AVX2' | 'AVX512' | undefined;
  cudaVersion?: '11' | '12';
  silent?: boolean;
  vulkan?: boolean;
  version?: string;
}
