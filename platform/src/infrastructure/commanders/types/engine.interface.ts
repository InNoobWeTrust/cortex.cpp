export enum Engines {
  llamaCPP = 'cortex.llamacpp',
  onnx = 'cortex.onnx',
  tensorrtLLM = 'cortex.tensorrt-llm',

  // Remote engines
  groq = 'groq',
  mistral = 'mistral',
  openai = 'openai',
  anthropic = 'anthropic',
  openrouter = 'openrouter',
  cohere = 'cohere',
  martian = 'martian',
  nvidia = 'nvidia',
}

export const EngineNamesMap: {
  [key in string]: string;
} = {
  [Engines.llamaCPP]: 'llamacpp',
  [Engines.onnx]: 'onnx',
  [Engines.tensorrtLLM]: 'tensorrt-llm',
};

export const RemoteEngines: Engines[] = [
  Engines.groq,
  Engines.mistral,
  Engines.openai,
  Engines.anthropic,
  Engines.openrouter,
  Engines.cohere,
  Engines.martian,
  Engines.nvidia,
];
