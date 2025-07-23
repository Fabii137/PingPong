# 🏓 PingPong Game

A simple PingPong (Pong-style) game developed using **C++**, **SFML 3.0.1**, and **CMake**.  
Built with static SFML linking and supports both development and production modes.

---

## 📦 Features

- Built with **SFML 3.0.1** (statically linked)
- Uses **CMake** for build configuration
- Switchable `PRODUCTION_BUILD` mode for release builds

---

## 🛠 Requirements

- C++17 compatible compiler (MSVC recommended for this setup)
- [SFML 3.0.1](https://github.com/SFML/SFML) (included in `thirdparty/SFML-3.0.1`)
- [CMake 3.16+](https://cmake.org/download/)

---

## 📁 Project Structure
```
PingPong/
├── CMakeLists.txt
├── include/
│ └── ... # Header files 
├── src/
│ └── ... # Source files
├── resources/
│ └── ... # fonts, configs, etc.
├── thirdparty/
│ └── SFML-3.0.1/ # SFML source folder
```

---

## 🚀 Build Instructions

### Build via Visual Studio

- Right click in the project folder and click **Open With Visual Studio**
- Wait for it to load
- **Debug:** Leave on x64-Debug
- **Release:** Make a x64-Release Config 
- Press **CTRL + B** to build
- You can run it via **Visual Studio** 
- Or via the executable in **./out/build/x64-Debug/** or **./out/build/x64-Release/**

---

