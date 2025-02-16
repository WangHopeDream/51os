# 8051 MCU 开发模板

基于 SDCC 编译器的 8051 微控制器开发模板，集成 VSCode 构建系统。

## 功能特性
- 自动化构建系统（Makefile + VSCode Tasks）
- 8051 特殊寄存器语法支持
- 输出文件自动管理
- 一键清理构建产物

## 开发环境要求
1. SDCC 编译器
   ```bash
   brew install sdcc  # macOS
   ```
2. Visual Studio Code 扩展
   - C/C++ (Microsoft)
   - Makefile Tools

## 项目结构
```
.
├── .vscode/            # IDE 配置
│   ├── tasks.json      # 构建任务定义
│   └── c_cpp_properties.json # 编译器配置
├── inc/                # 头文件目录
├── src/                # 源代码
│   └── main.c         # 主程序入口
├── output/             # 构建输出目录
├── Makefile            # 构建规则
└── .gitignore          # 版本控制排除配置
```

## 构建说明
### 命令行构建
```bash
make OUTDIR=output   # 完整构建
make clean           # 清理构建产物
```

### VSCode 构建
1. `Ctrl+Shift+B` 执行构建任务
2. 选择以下任务：
   - `build`: 完整构建流程（生成 main.hex）
   - `clean`: 清理构建产物

## 编译器配置
`c_cpp_properties.json` 包含以下关键配置：
```json
{
  "compilerPath": "/usr/local/bin/sdcc",
  "cStandard": "c99",
  "defines": [
    "__sfr=unsigned char",
    "__sbit=int",
    "__at(a)= ",
    "__data= ",
    "__xdata= "
  ]
}
```

## 代码示例（src/main.c）
```c
#include <8052.h>

#define LED P1_0

void delay(unsigned int cycles) {
    while(cycles--);
}

void main() {
    while(1) {
        LED = 0;
        delay(30000);
        LED = 1; 
        delay(30000);
    }
}
```

## 维护说明
- 构建产物自动输出到 `output/` 目录
- 修改编译选项需编辑 `Makefile` 中的 FLAGS 参数
- 新增源文件需更新 Makefile 的 SRC 变量
- 头文件应放置在 `inc/` 目录
