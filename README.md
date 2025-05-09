# wolf-os-cpp

A C++ system test application for Wolf-OS but could be suited for other (Linux-based) boards supported by dockcross.  
This project is designed to validate compilation and linking of standard C++17 libraries alongside common Linux/POSIX system headers and syscalls.

## Features

- Uses modern C++17 (e.g., std::thread, std::optional, std::function)
- Tests Linux syscalls: fork, socket, open, readdir, etc.
- Targets **ARMv5** via cross-compilation using `dockcross`: https://github.com/dockcross/dockcross?tab=readme-ov-file

### What It Tests

- STL containers, algorithms, threading, atomics
- Linux syscalls: file I/O, sockets, processes, memory mapping
- C++ and system header inclusion and linking

## Prerequisites

- Docker installed
- Git
- Optional CMake ≥ 3.30 for host compilation

## Setup and Build

### 1. Clone the Repository

```
git clone https://github.com/kptr-juku/wolf-os-cpp.git
cd wolf-os-cpp
```

### 2. Set Up `dockcross` for ARMv5

```
docker run --rm dockcross/linux-armv5 > ./dockcross
chmod +x dockcross
```

### 3. Build the Project with `dockcross`

```
./dockcross cmake -Bbuild .
./dockcross cmake --build build
```

The resulting binary (`wolf-cpp`) will be cross-compiled for ARMv5 and placed in the `build/` directory.

### 4. Upload to the device or include in the distro

Upload and test now:

`scp -O build/wolf-cpp root@<IP>:/tmp/`

Include in the distro - https://github.com/FoxIoT-EU/foxiot-wolf-os/blob/docs/docs/developer-quick-start.md#adding-your-application-to-the-firmware

## Customization

To test additional libraries or headers, modify `main.cc` and rebuild using the same commands above.

## 📚 Resources

- Wolf-OS: https://github.com/FoxIoT-EU/foxiot-wolf-os
- Dockcross: https://github.com/dockcross/dockcross?tab=readme-ov-file
- CMake: https://cmake.org/documentation/
- Crosstool-NG / GCC: https://crosstool-ng.github.io/

---

Happy compiling 🚀

