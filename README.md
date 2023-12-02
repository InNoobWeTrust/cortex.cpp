# Nitro - Embeddable AI
<p align="center">
  <img alt="nitrologo" src="https://raw.githubusercontent.com/janhq/nitro/main/assets/Nitro%20README%20banner.png">
</p>

<p align="center">
  <a href="https://nitro.jan.ai/docs">Documentation</a> - <a href="https://nitro.jan.ai/api">API Reference</a> 
  - <a href="https://github.com/janhq/nitro/releases/">Changelog</a> - <a href="https://github.com/janhq/nitro/issues">Bug reports</a> - <a href="https://discord.gg/AsJ8krTT3N">Discord</a>
</p>

> ⚠️ **Nitro is currently in Development**: Expect breaking changes and bugs!

## Features
- Fast Inference: Built on top of the cutting-edge inference library llama.cpp, modified to be production ready.
- Lightweight: Only 3MB, ideal for resource-sensitive environments.
- Easily Embeddable: Simple integration into existing applications, offering flexibility.
- Quick Setup: Approximately 10-second initialization for swift deployment.
- Enhanced Web Framework: Incorporates drogon cpp to boost web service efficiency.

## About Nitro

Nitro is a high-efficiency C++ inference engine for edge computing, powering [Jan](https://jan.ai/). It is lightweight and embeddable, ideal for product integration.

The binary of nitro after zipped is only ~3mb in size with none to minimal dependencies (if you use a GPU need CUDA for example) make it desirable for any edge/server deployment 👍.

> Read more about Nitro at https://nitro.jan.ai/

### Repo Structure

```
.
├── controllers
├── docs 
├── llama.cpp -> Upstream llama C++
├── nitro_deps -> Dependencies of the Nitro project as a sub-project
└── utils
```

## Quickstart

**Step 1: Install Nitro**

- For Linux and MacOS

  ```bash
  curl -sfL https://raw.githubusercontent.com/janhq/nitro/main/install.sh | sudo /bin/bash -
  ```

- For Windows

  ```bash
  powershell -Command "& { Invoke-WebRequest -Uri 'https://raw.githubusercontent.com/janhq/nitro/main/install.bat' -OutFile 'install.bat'; .\install.bat; Remove-Item -Path 'install.bat' }"
  ```

**Step 2: Downloading a Model**

```bash
mkdir model && cd model
wget -O llama-2-7b-model.gguf https://huggingface.co/TheBloke/Llama-2-7B-Chat-GGUF/resolve/main/llama-2-7b-chat.Q5_K_M.gguf?download=true
```

**Step 3: Run Nitro server**

```bash title="Run Nitro server"
nitro
```

**Step 4: Load model** 

```bash title="Load model"
curl http://localhost:3928/inferences/llamacpp/loadmodel \
  -H 'Content-Type: application/json' \
  -d '{
    "llama_model_path": "/model/llama-2-7b-model.gguf",
    "ctx_len": 512,
    "ngl": 100,
  }'
```

**Step 5: Making an Inference**

```bash title="Nitro Inference"
curl http://localhost:3928/v1/chat/completions \
  -H "Content-Type: application/json" \
  -d '{
    "messages": [
      {
        "role": "user",
        "content": "Who won the world series in 2020?"
      },
    ]
  }'
```

Table of parameters

| Parameter        | Type    | Description                                                  |
|------------------|---------|--------------------------------------------------------------|
| `llama_model_path` | String  | The file path to the LLaMA model.                            |
| `ngl`              | Integer | The number of GPU layers to use.                             |
| `ctx_len`          | Integer | The context length for the model operations.                 |
| `embedding`        | Boolean | Whether to use embedding in the model.                       |
| `n_parallel`       | Integer | The number of parallel operations. Uses Drogon thread count if not set. |
| `cont_batching`    | Boolean | Whether to use continuous batching.                          |
| `user_prompt`      | String  | The prompt to use for the user.                              |
| `ai_prompt`        | String  | The prompt to use for the AI assistant.                      |
| `system_prompt`    | String  | The prompt to use for system rules.                          |
| `pre_prompt`    | String  | The prompt to use for internal configuration.                          |
| `cpu_threads`   | Integer | The number of threads to use for inferencing (CPU MODE ONLY) |
| `n_batch`       | Integer | The batch size for prompt eval step |

***OPTIONAL***: You can run Nitro on a different port like 5000 instead of 3928 by running it manually in terminal
```zsh
./nitro 1 127.0.0.1 5000 ([thread_num] [host] [port])
```
- thread_num : the number of thread that nitro webserver needs to have
- host : host value normally 127.0.0.1 or 0.0.0.0
- port : the port that nitro got deployed onto

Nitro server is compatible with the OpenAI format, so you can expect the same output as the OpenAI ChatGPT API.

## Compile from source
To compile nitro please visit [Compile from source](docs/new/build-source.md)

### Contact

- For support, please file a GitHub ticket.
- For questions, join our Discord [here](https://discord.gg/FTk2MvZwJH).
- For long-form inquiries, please email hello@jan.ai.
