

# SansBattle - 传说之下风格剧情游戏

这是一个使用 **Raylib** 框架开发的《传说之下》(Undertale) 风格的叙事游戏原型。包含动态菜单、开场动画、全局数据记录和随机背景音乐。

## 🎮 特性

- 主菜单（带随机背景音乐，每次进入不同）
- 完整开场剧情（渐入渐出、逐字文字、滚动结尾）
- 全局数据存储（玩家名称、HP等，可跨场景保留）
- 键盘操作（方向键选择，Z键确认）
- 自定义窗口图标和光标（可选）

## 📦 依赖环境

在运行或编译之前，请确保已安装以下工具：

- **Raylib** (5.0 或更高版本)  
  官方下载：https://www.raylib.com/
- **CMake** (3.10+)  
  官方下载：https://cmake.org/
- **C++17 编译器**  
  - Windows：MinGW-w64 或 Visual Studio
  - Linux：g++ 7+
  - macOS：clang
  - 这里推荐MinGW:

  - 官网：https://link.zhihu.com/?target=https%3A//www.mingw-w64.org/
  - github:https://github.com/niXman/mingw-builds-binaries/releases

下载好后再配置PATH环境！
## 🛠 编译与运行

### 方式一：使用提供的编译脚本（Windows）

项目根目录下提供了 `编译.bat` 脚本，双击运行即可自动完成构建、复制资源并启动游戏。

```batch
编译.bat
```

> 注意：需要将 Raylib 的 `include` 和 `lib` 文件夹放在项目根目录下的 `raylib/` 文件夹中（即 `/raylib/include` 和 `/raylib/lib`）。

### 方式二：手动 CMake 构建

```bash
# 克隆或解压项目后，进入根目录
cd SansBattle

# 创建并进入 build 目录
mkdir build && cd build

# 生成构建文件（Windows MinGW 示例）
cmake .. -G "MinGW Makefiles"

# 编译
cmake --build . --parallel

# 回到根目录，复制资源到 out 文件夹（如果脚本未自动执行）
xcopy /E /I /Y ..\res ..\out\res\

# 运行游戏
cd ../out
./SansBattle.exe
```

> 如果使用 Visual Studio，请将 `-G "MinGW Makefiles"` 替换为对应生成器，如 `-G "Visual Studio 17 2022"`。

### 方式三：将资源文件夹与 exe 放一起

编译成功后，确保 `res` 文件夹与生成的 `SansBattle.exe` 位于同一目录（`out/` 下），否则游戏无法加载图片和音乐。

## 🎮 操作说明

### 主菜单（房间 3）

- **↑ / ↓**：上下移动选项
- **Z**：确认选择  
  - **START** → 开始剧情  
  - **SETTINGS** → （开发中，暂时返回菜单）  
  - **RESET** → 重置游戏（返回菜单）

### 剧情模式（房间 1 和 2）

- **Z**：跳过当前图片的淡入淡出或文字显示，直接进入下一阶段（方便快速重看）
- 文字会自动逐字显示，支持 `#` 停顿和 `\n` 换行

## 📁 项目文件结构

```
SansBattle/
├── CMakeLists.txt           # CMake 构建配置
├── 编译.bat                  # Windows 一键编译运行脚本
├── raylib.rc                 # Windows 资源文件（exe 图标）
├── res/                      # 资源目录
│   ├── img/                  # 图片（标题、菜单、剧情图片、头像等）
│   ├── mus/                  # 音乐（mus_menu0~6.ogg, mus_story.ogg 等）
│   └── fx/                   # 音效（nsay.wav, choose.wav 等）
├── scr/                      # 源代码
│   ├── main.cpp              # 主循环和房间调度
│   ├── inc/                  # 头文件
│   │   ├── rooms/            # 房间类声明
│   │   └── things/           # 文字特效等组件
│   └── lib/                  # 实现文件
│       ├── rooms/
│       └── things/
└── out/                      # 编译输出（自动生成）
    ├── SansBattle.exe
    └── res/                  # 运行时需要的资源副本
```

## 🧩 已知问题与后期扩展

- **多房间切换**：部分房间返回值（4、5）尚未实现实际功能，目前会退出游戏。
- **设置页面**：菜单中的 SETTINGS 暂未开发，可自行添加新房间。
- **中文支持**：当前使用 `DrawText`，默认字体不支持中文，如需中文请加载自定义 TTF 字体。
- **存档功能**：尚未实现，可考虑将 `Data` 类数据存入文件。

## 📄 许可

本项目仅用于学习和个人交流，素材版权归原游戏（Undertale）所有。源代码采用 MIT 许可。

## 🙏 致谢

- Raylib 开发团队 - 提供简单易用的游戏库
- 游戏《Undertale》 - 灵感来源

---

Enjoy! 😊  
—— KICE