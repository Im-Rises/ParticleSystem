# ParticleSystem

<p align="center">
      <img src="https://user-images.githubusercontent.com/59691442/183268126-b3d19e66-8f2d-463a-805e-ae6ef7cc6c01.png" alt="cmakeLogo" style="height:60px;"/>
      <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="cppLogo" style="height:60px;"/>
      <img src="https://user-images.githubusercontent.com/59691442/190315010-0a84e171-a2bc-42a4-91c8-bb850960209c.png" alt="openglLogo" style="height:60px;"/>
      <img src="https://user-images.githubusercontent.com/59691442/190315147-ec9dc33f-0090-4f0d-98ab-514eb1463e01.png" alt="glfwLogo" style="height:60px;"/>
</p>

## Description

This project is a particle system made in C++ using OpenGL and GLFW.

The UI is made using ImGui and allows you to modify some parameters of the particle system and the camera view.

## 🚀🚀[you can try the webgl build online by clicking here](https://im-rises.github.io/particle-system-webgl/) 🚀🚀

> **Note**  
> This project was made as a learning exercise to learn some OpenGL features.

## Features

- [x] Particle system
- [x] ImGui UI
- [x] Camera movement
- [x] Pausing the simulation
- [x] Different settings for the particle system
- [x] Different settings for the camera

## Images and Videos

[![Watch the video](https://user-images.githubusercontent.com/59691442/216751976-c06c492d-5dfb-466c-afe9-ec44e94e5db9.png)](https://www.youtube.com/watch?v=h5X1RaElC7Y)

[![Watch the video](https://user-images.githubusercontent.com/59691442/216753254-f3315a71-f073-420e-b4e3-86a024913683.png)](https://www.youtube.com/watch?v=h5X1RaElC7Y)

Click on the images to watch the video.

## Dependencies

- C++ 14
- C++ compiler (MSVC, Mingw, ...)
- CMake
- Glad
- GLFW (3.3.8)
- OpenGl (3.3)
- Dear ImGui (1.88)
- glm (0.9.8.5)
- stb (2.28)

## Table of Contents

1. [Description](#description)
2. [Features](#features)
3. [Images and Videos](#images-and-videos)
4. [Dependencies](#dependencies)
5. [Table of Contents](#table-of-contents)
6. [Project Architecture](#project-architecture)
7. [Quickstart](#quickstart)
	1. [Windows](#windows)
	2. [Linux](#linux)
	3. [MacOs](#macos)
8. [Controls](#controls)
9. [Compilation](#compilation)
	1. [Windows](#windows)
	2. [Linux](#linux)
	3. [MacOs](#macos)
10. [GitHub-Actions](#github-actions)
11. [Documentation](#documentation)
12. [Contributors](#contributors)

## Project Architecture

<details>
<summary>Click to expand</summary>

~~~
ParticleSystem
├── .github
|  ├── labels.yml
|  ├── release.yml
│  ├── workflows
│  │   |── cmake.yml
│  │   |── codeql.yml
│  │   |── cpp-cmake-publish.yml
│  │   |── cpp-linter.yml
│  │   |── dependency-review.yml
│  │   |── flawfinder.yml
│  │   |── greetings.yml
│  │   |── label.yml
│  │   |── msvc.yml
│  │   |── stale.yml
├── dependencies
|  ├── glad
|  ├── glfw
|  ├── glm
|  ├── imgui
|  ├── stb
├── ParticleSystem
|  ├── Shader
│  │   |── *
|  ├── Texture
│  │   |── *
|  ├── Scene
│  │   |── *
|  ├── CMakeLists.txt
|  ├── InputManager.cpp
|  ├── InputManager.h
|  ├── main.cpp
|  ├── ParticleSystemLauncher.cpp
|  ├── ParticleSystemLauncher.h
├── .clang-format
├── .clang-tidy
├── .editorconfig
├── .gitattributes
├── .gitignore
├── CMakelists.txt
├── CMakePresets.json
├── CMakeSettings.json
├── imgui.ini
├── README.md
~~~

</details>

## Quickstart

To download the app, you can click one of the icons below (depending on your operating system). You can also click the
release section of the GitHub page.

Depending on you `operating system` you will need to install some libs, they are installed differently depending on your
system, please follow one of the section below `Windows` or `Linux` or `MacOs`.

For the compilation, follow the section `Compilation`.

The controls are described in the section `Controls`.

> **Warning**
> Be sure to put the `imgui.ini` file in the same folder as the executable.
> You can find it in the `root` of the project. If you don't do this, the UI will not be displayed correctly.

### Windows

<a href="https://github.com/Im-Rises/ParticleSystem/releases/latest"><img src="https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white" alt="cmakeLogo" style="height:40px;"/></a>

For Windows users you don't need to install the libs. You can just download the app and run it.

```bash
.\ParticleSystem.exe
```

### Linux

<a href="https://github.com/Im-Rises/ParticleSystem/releases/latest"><img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" alt="cmakeLogo" style="height:40px;"/></a>

For Linux users, you need to install the GLFW lib, to do so type one of the following commands:

```bash
sudo apt-get install libglfw3
```

or if you're a developer and want to compile the app, please install this version of GLFW:

```bash
sudo apt-get install libglfw3-dev
```

Then you can start by double-clicking the executable of typing the following command next to it:

```bash
./ParticleSystem
```

### MacOs

<a href="https://github.com/Im-Rises/ParticleSystem/releases/latest"><img src="https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=apple&logoColor=white" alt="cmakeLogo" style="height:40px;"/></a>

For macOS users you will need to install Brew, please follow the instruction in the link below:  
<https://brew.sh>

Once it is installed, you can type the following command to install GLFW.

```bash
brew install glfw
```

Then you can start by double-clicking the executable of typing the following command next to it:

```bash
./ParticleSystem
```

## Controls

The speed and some parameters can be modified directly in the ImGui windows.

| Action              | Key                                 |
|---------------------|-------------------------------------|
| Translate camera    | WASD (← → ↑ ↓)                      |
| Pause/Resume        | P                                   |
| Move up/down camera | SPACE/SHIFT                         |
| Rotate camera       | Right Mouse Button + Mouse movement |
| Exit app            | ESC                                 |

> **Note**
> You can the inputs by changing their attribution in the `InputManager.cpp` file,
> if so you'll need to compile the project.

## Compilation

To compile the app, the first thing you need to do is install a C++ compiler:

- Visual Studio (MSVC)
- Mingw
- ...

You also need to install Cmake:  
<https://cmake.org>

Once your environment is set up, depending on your operating system you'll need to install some libs before compiling
the project. Refer to the section below `Windows` or `Linux` or `MacOs`.

### Windows

Windows users can directly compile the project by typing the following command at the project root folder:

```bash
cmake -B . -DCMAKE_BUILD_TYPE=<Debug/Release>
```

then

```bash
cmake --build . --config <Debug/Release>
```

You need to replace `<Debug/Release>` by the build type you want to use.

> **Note**  
> If you're using Visual Studio, you can install CMake directly from the IDE (Visual Studio Installer).
> Then you need to open the Project as a CMake Project, not a Visual Studio Project!

> **Warning**  
> The project is set up to be built using CMake and vc2019 for Windows. If you want to modify the
> compiler for vc2022 or other you will need to change the CMakeLists.txt .lib linking file accordingly to your vc20**
> version.

### Linux

Linux's users need to install some libs before compiling the project:

First thing to do is to install CMake, type the following command to install it.

```bash
sudo apt-get install cmake
```

You also need to install the GLFW lib. Type the following command at the project root.

```bash
sudo apt-get install libglfw3-dev
```

You are now able to compile the project. Go to the project root and type the following command:

```bash
cmake -B . -DCMAKE_BUILD_TYPE=Release
```

### MacOs

For macOS user, you should install brew package manager by following the instructions in the link below:  
<https://brew.sh>

Then type the following command to install cmake:

```bash
brew install cmake
```

and this one to install GLFW

```bash
brew install glfw
```

You are now able to compile the project. Go to the project root and type the following command:

```bash
cmake -B . -DCMAKE_BUILD_TYPE=Release
```

## Github-Actions

[![CodeQL](https://github.com/Im-Rises/ParticleSystem/actions/workflows/codeql.yml/badge.svg?branch=main)](https://github.com/Im-Rises/ParticleSystem/actions/workflows/codeql.yml)
[![CMake](https://github.com/Im-Rises/ParticleSystem/actions/workflows/cmake.yml/badge.svg?branch=main)](https://github.com/Im-Rises/ParticleSystem/actions/workflows/cmake.yml)
[![Cpp Cmake Publish](https://github.com/Im-Rises/ParticleSystem/actions/workflows/cpp-cmake-publish.yml/badge.svg?branch=main)](https://github.com/Im-Rises/ParticleSystem/actions/workflows/cpp-cmake-publish.yml)
[![flawfinder](https://github.com/Im-Rises/ParticleSystem/actions/workflows/flawfinder.yml/badge.svg?branch=main)](https://github.com/Im-Rises/ParticleSystem/actions/workflows/flawfinder.yml)
[![Microsoft C++ Code Analysis](https://github.com/Im-Rises/ParticleSystem/actions/workflows/msvc.yml/badge.svg?branch=main)](https://github.com/Im-Rises/ParticleSystem/actions/workflows/msvc.yml)
[![cpp-linter](https://github.com/Im-Rises/ParticleSystem/actions/workflows/cpp-linter.yml/badge.svg?branch=main)](https://github.com/Im-Rises/ParticleSystem/actions/workflows/cpp-linter.yml)

The project is set with a set of different scripts:

- CodeQL: This script is used to check the code for security issues.
- CMake: This script is used to build the project.
- Cpp Cmake Publish: This script is used to publish the project on GitHub.
- Flawfinder: This script is used to check the code for security issues.
- Microsoft C++ Code Analysis: This script is used to check the code for security issues.
- Cpp Linter: This script is used to check the code for security issues.

## Libraries

glfw:  
<https://www.glfw.org/docs/latest/>

glm:  
<https://glm.g-truc.net/0.9.9/index.html>

glad:  
<https://glad.dav1d.de/>

stb (stb_image):  
<https://github.com/nothings/stb/blob/master/stb_image.h>

Dear imgui:  
<https://github.com/ocornut/imgui>

OpenGL:  
<https://www.opengl.org/>

## Documentation

learnopengl (OpenGL tutorial):  
<https://learnopengl.com/In-Practice/2D-Game/Particles>

opengl-tutorial (OpenGL tutorial):  
<http://www.opengl-tutorial.org/intermediate-tutorials/billboards-particles/particles-instancing/>

3dgep:  
<https://www.3dgep.com/simulating-particle-effects-using-opengl/>

levelup (Particle Generation):  
<https://levelup.gitconnected.com/how-to-create-instanced-particles-in-opengl-24cb089911e2>

unrealistic.dev (Change CMake working directory):  
<https://unrealistic.dev/posts/setting-debug-parameters-with-cmake-tools-for-visual-studio>

## Contributors

Quentin MOREL:

- @Im-Rises
- <https://github.com/Im-Rises>

[![GitHub contributors](https://contrib.rocks/image?repo=Im-Rises/ParticleSystem)](https://github.com/Im-Rises/ParticleSystem/graphs/contributors)
