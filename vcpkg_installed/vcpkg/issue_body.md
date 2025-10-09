Package: glfw3:x64-linux@3.4#1

**Host Environment**

- Host: x64-linux
- Compiler: GNU 13.3.0
- CMake Version: 3.30.1
-    vcpkg-tool version: 2025-09-03-4580816534ed8fd9634ac83d46471440edd82dfe
    vcpkg-scripts version: unknown

**To Reproduce**

`vcpkg install `

**Failure logs**

```
-- Using cached glfw-glfw-3.4.tar.gz
-- Cleaning sources at /opt/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean. Use --editable to skip cleaning for the packages you specify.
-- Extracting source /opt/vcpkg/downloads/glfw-glfw-3.4.tar.gz
-- Using source at /opt/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean
GLFW3 currently requires the following libraries from the system package manager:
    xinerama
    xcursor
    xorg
    libglu1-mesa
    pkg-config

These can be installed on Ubuntu systems via sudo apt install libxinerama-dev libxcursor-dev xorg-dev libglu1-mesa-dev pkg-config

Alternatively, when targeting the Wayland display server, use the packages listed in the GLFW documentation here:

https://www.glfw.org/docs/3.3/compile.html#compile_deps_wayland
-- Configuring x64-linux
CMake Error at scripts/cmake/vcpkg_execute_required_process.cmake:127 (message):
    Command failed: /opt/vcpkg/downloads/tools/ninja/1.12.1-linux/ninja -v
    Working Directory: /opt/vcpkg/buildtrees/glfw3/x64-linux-rel/vcpkg-parallel-configure
    Error code: 1
    See logs for more information:
      /opt/vcpkg/buildtrees/glfw3/config-x64-linux-dbg-CMakeCache.txt.log
      /opt/vcpkg/buildtrees/glfw3/config-x64-linux-rel-CMakeCache.txt.log
      /opt/vcpkg/buildtrees/glfw3/config-x64-linux-dbg-CMakeConfigureLog.yaml.log
      /opt/vcpkg/buildtrees/glfw3/config-x64-linux-rel-CMakeConfigureLog.yaml.log
      /opt/vcpkg/buildtrees/glfw3/config-x64-linux-out.log

Call Stack (most recent call first):
  /home/reagan/Pathological/vcpkg_installed/x64-linux/share/vcpkg-cmake/vcpkg_cmake_configure.cmake:269 (vcpkg_execute_required_process)
  ports/glfw3/portfile.cmake:38 (vcpkg_cmake_configure)
  scripts/ports.cmake:206 (include)



```

<details><summary>/opt/vcpkg/buildtrees/glfw3/config-x64-linux-out.log</summary>

```
[1/2] "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/bin/cmake" -E chdir "../../x64-linux-dbg" "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/bin/cmake" "/opt/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean" "-G" "Ninja" "-DCMAKE_BUILD_TYPE=Debug" "-DCMAKE_INSTALL_PREFIX=/opt/vcpkg/packages/glfw3_x64-linux/debug" "-DFETCHCONTENT_FULLY_DISCONNECTED=ON" "-DGLFW_BUILD_EXAMPLES=OFF" "-DGLFW_BUILD_TESTS=OFF" "-DGLFW_BUILD_DOCS=OFF" "-DGLFW_BUILD_WAYLAND=OFF" "-DCMAKE_MAKE_PROGRAM=/opt/vcpkg/downloads/tools/ninja/1.12.1-linux/ninja" "-DCMAKE_SYSTEM_NAME=Linux" "-DBUILD_SHARED_LIBS=OFF" "-DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=/opt/vcpkg/scripts/toolchains/linux.cmake" "-DVCPKG_TARGET_TRIPLET=x64-linux" "-DVCPKG_SET_CHARSET_FLAG=ON" "-DVCPKG_PLATFORM_TOOLSET=external" "-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY=ON" "-DCMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP=TRUE" "-DCMAKE_VERBOSE_MAKEFILE=ON" "-DVCPKG_APPLOCAL_DEPS=OFF" "-DCMAKE_TOOLCHAIN_FILE=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake" "-DCMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION=ON" "-DVCPKG_CXX_FLAGS=" "-DVCPKG_CXX_FLAGS_RELEASE=" "-DVCPKG_CXX_FLAGS_DEBUG=" "-DVCPKG_C_FLAGS=" "-DVCPKG_C_FLAGS_RELEASE=" "-DVCPKG_C_FLAGS_DEBUG=" "-DVCPKG_CRT_LINKAGE=dynamic" "-DVCPKG_LINKER_FLAGS=" "-DVCPKG_LINKER_FLAGS_RELEASE=" "-DVCPKG_LINKER_FLAGS_DEBUG=" "-DVCPKG_TARGET_ARCHITECTURE=x64" "-DCMAKE_INSTALL_LIBDIR:STRING=lib" "-DCMAKE_INSTALL_BINDIR:STRING=bin" "-D_VCPKG_ROOT_DIR=/opt/vcpkg" "-D_VCPKG_INSTALLED_DIR=/home/reagan/Pathological/vcpkg_installed" "-DVCPKG_MANIFEST_INSTALL=OFF"
FAILED: ../../x64-linux-dbg/CMakeCache.txt 
"/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/bin/cmake" -E chdir "../../x64-linux-dbg" "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/bin/cmake" "/opt/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean" "-G" "Ninja" "-DCMAKE_BUILD_TYPE=Debug" "-DCMAKE_INSTALL_PREFIX=/opt/vcpkg/packages/glfw3_x64-linux/debug" "-DFETCHCONTENT_FULLY_DISCONNECTED=ON" "-DGLFW_BUILD_EXAMPLES=OFF" "-DGLFW_BUILD_TESTS=OFF" "-DGLFW_BUILD_DOCS=OFF" "-DGLFW_BUILD_WAYLAND=OFF" "-DCMAKE_MAKE_PROGRAM=/opt/vcpkg/downloads/tools/ninja/1.12.1-linux/ninja" "-DCMAKE_SYSTEM_NAME=Linux" "-DBUILD_SHARED_LIBS=OFF" "-DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=/opt/vcpkg/scripts/toolchains/linux.cmake" "-DVCPKG_TARGET_TRIPLET=x64-linux" "-DVCPKG_SET_CHARSET_FLAG=ON" "-DVCPKG_PLATFORM_TOOLSET=external" "-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY=ON" "-DCMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP=TRUE" "-DCMAKE_VERBOSE_MAKEFILE=ON" "-DVCPKG_APPLOCAL_DEPS=OFF" "-DCMAKE_TOOLCHAIN_FILE=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake" "-DCMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION=ON" "-DVCPKG_CXX_FLAGS=" "-DVCPKG_CXX_FLAGS_RELEASE=" "-DVCPKG_CXX_FLAGS_DEBUG=" "-DVCPKG_C_FLAGS=" "-DVCPKG_C_FLAGS_RELEASE=" "-DVCPKG_C_FLAGS_DEBUG=" "-DVCPKG_CRT_LINKAGE=dynamic" "-DVCPKG_LINKER_FLAGS=" "-DVCPKG_LINKER_FLAGS_RELEASE=" "-DVCPKG_LINKER_FLAGS_DEBUG=" "-DVCPKG_TARGET_ARCHITECTURE=x64" "-DCMAKE_INSTALL_LIBDIR:STRING=lib" "-DCMAKE_INSTALL_BINDIR:STRING=bin" "-D_VCPKG_ROOT_DIR=/opt/vcpkg" "-D_VCPKG_INSTALLED_DIR=/home/reagan/Pathological/vcpkg_installed" "-DVCPKG_MANIFEST_INSTALL=OFF"
-- The C compiler identification is GNU 13.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE
-- Including X11 support
-- Found X11: /usr/include
-- Looking for XOpenDisplay in /usr/lib/x86_64-linux-gnu/libX11.so;/usr/lib/x86_64-linux-gnu/libXext.so
-- Looking for XOpenDisplay in /usr/lib/x86_64-linux-gnu/libX11.so;/usr/lib/x86_64-linux-gnu/libXext.so - found
-- Looking for gethostbyname
-- Looking for gethostbyname - found
-- Looking for connect
-- Looking for connect - found
-- Looking for remove
-- Looking for remove - found
-- Looking for shmat
-- Looking for shmat - found
CMake Error at src/CMakeLists.txt:192 (message):
  Xinerama headers not found; install libxinerama development package


-- Configuring incomplete, errors occurred!
[2/2] "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/bin/cmake" -E chdir ".." "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/bin/cmake" "/opt/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean" "-G" "Ninja" "-DCMAKE_BUILD_TYPE=Release" "-DCMAKE_INSTALL_PREFIX=/opt/vcpkg/packages/glfw3_x64-linux" "-DFETCHCONTENT_FULLY_DISCONNECTED=ON" "-DGLFW_BUILD_EXAMPLES=OFF" "-DGLFW_BUILD_TESTS=OFF" "-DGLFW_BUILD_DOCS=OFF" "-DGLFW_BUILD_WAYLAND=OFF" "-DCMAKE_MAKE_PROGRAM=/opt/vcpkg/downloads/tools/ninja/1.12.1-linux/ninja" "-DCMAKE_SYSTEM_NAME=Linux" "-DBUILD_SHARED_LIBS=OFF" "-DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=/opt/vcpkg/scripts/toolchains/linux.cmake" "-DVCPKG_TARGET_TRIPLET=x64-linux" "-DVCPKG_SET_CHARSET_FLAG=ON" "-DVCPKG_PLATFORM_TOOLSET=external" "-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY=ON" "-DCMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP=TRUE" "-DCMAKE_VERBOSE_MAKEFILE=ON" "-DVCPKG_APPLOCAL_DEPS=OFF" "-DCMAKE_TOOLCHAIN_FILE=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake" "-DCMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION=ON" "-DVCPKG_CXX_FLAGS=" "-DVCPKG_CXX_FLAGS_RELEASE=" "-DVCPKG_CXX_FLAGS_DEBUG=" "-DVCPKG_C_FLAGS=" "-DVCPKG_C_FLAGS_RELEASE=" "-DVCPKG_C_FLAGS_DEBUG=" "-DVCPKG_CRT_LINKAGE=dynamic" "-DVCPKG_LINKER_FLAGS=" "-DVCPKG_LINKER_FLAGS_RELEASE=" "-DVCPKG_LINKER_FLAGS_DEBUG=" "-DVCPKG_TARGET_ARCHITECTURE=x64" "-DCMAKE_INSTALL_LIBDIR:STRING=lib" "-DCMAKE_INSTALL_BINDIR:STRING=bin" "-D_VCPKG_ROOT_DIR=/opt/vcpkg" "-D_VCPKG_INSTALLED_DIR=/home/reagan/Pathological/vcpkg_installed" "-DVCPKG_MANIFEST_INSTALL=OFF"
FAILED: ../CMakeCache.txt 
"/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/bin/cmake" -E chdir ".." "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/bin/cmake" "/opt/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean" "-G" "Ninja" "-DCMAKE_BUILD_TYPE=Release" "-DCMAKE_INSTALL_PREFIX=/opt/vcpkg/packages/glfw3_x64-linux" "-DFETCHCONTENT_FULLY_DISCONNECTED=ON" "-DGLFW_BUILD_EXAMPLES=OFF" "-DGLFW_BUILD_TESTS=OFF" "-DGLFW_BUILD_DOCS=OFF" "-DGLFW_BUILD_WAYLAND=OFF" "-DCMAKE_MAKE_PROGRAM=/opt/vcpkg/downloads/tools/ninja/1.12.1-linux/ninja" "-DCMAKE_SYSTEM_NAME=Linux" "-DBUILD_SHARED_LIBS=OFF" "-DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=/opt/vcpkg/scripts/toolchains/linux.cmake" "-DVCPKG_TARGET_TRIPLET=x64-linux" "-DVCPKG_SET_CHARSET_FLAG=ON" "-DVCPKG_PLATFORM_TOOLSET=external" "-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY=ON" "-DCMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP=TRUE" "-DCMAKE_VERBOSE_MAKEFILE=ON" "-DVCPKG_APPLOCAL_DEPS=OFF" "-DCMAKE_TOOLCHAIN_FILE=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake" "-DCMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION=ON" "-DVCPKG_CXX_FLAGS=" "-DVCPKG_CXX_FLAGS_RELEASE=" "-DVCPKG_CXX_FLAGS_DEBUG=" "-DVCPKG_C_FLAGS=" "-DVCPKG_C_FLAGS_RELEASE=" "-DVCPKG_C_FLAGS_DEBUG=" "-DVCPKG_CRT_LINKAGE=dynamic" "-DVCPKG_LINKER_FLAGS=" "-DVCPKG_LINKER_FLAGS_RELEASE=" "-DVCPKG_LINKER_FLAGS_DEBUG=" "-DVCPKG_TARGET_ARCHITECTURE=x64" "-DCMAKE_INSTALL_LIBDIR:STRING=lib" "-DCMAKE_INSTALL_BINDIR:STRING=bin" "-D_VCPKG_ROOT_DIR=/opt/vcpkg" "-D_VCPKG_INSTALLED_DIR=/home/reagan/Pathological/vcpkg_installed" "-DVCPKG_MANIFEST_INSTALL=OFF"
-- The C compiler identification is GNU 13.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE
-- Including X11 support
-- Found X11: /usr/include
-- Looking for XOpenDisplay in /usr/lib/x86_64-linux-gnu/libX11.so;/usr/lib/x86_64-linux-gnu/libXext.so
-- Looking for XOpenDisplay in /usr/lib/x86_64-linux-gnu/libX11.so;/usr/lib/x86_64-linux-gnu/libXext.so - found
-- Looking for gethostbyname
-- Looking for gethostbyname - found
-- Looking for connect
-- Looking for connect - found
-- Looking for remove
-- Looking for remove - found
-- Looking for shmat
-- Looking for shmat - found
CMake Error at src/CMakeLists.txt:192 (message):
  Xinerama headers not found; install libxinerama development package


-- Configuring incomplete, errors occurred!
ninja: build stopped: subcommand failed.
```
</details>

<details><summary>/opt/vcpkg/buildtrees/glfw3/config-x64-linux-dbg-CMakeConfigureLog.yaml.log</summary>

```

---
events:
  -
    kind: "message-v1"
    backtrace:
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/CMakeDetermineSystem.cmake:205 (message)"
      - "CMakeLists.txt:3 (project)"
    message: |
      The system is: Linux -  - x86_64
  -
    kind: "message-v1"
    backtrace:
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/CMakeDetermineCompilerId.cmake:17 (message)"
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/CMakeDetermineCompilerId.cmake:64 (__determine_compiler_id_test)"
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/CMakeDetermineCCompiler.cmake:123 (CMAKE_DETERMINE_COMPILER_ID)"
      - "CMakeLists.txt:3 (project)"
    message: |
      Compiling the C compiler identification source file "CMakeCCompilerId.c" succeeded.
      Compiler: /usr/bin/cc 
      Build flags: -fPIC
      Id flags:  
      
      The output was:
      0
      
      
      Compilation of the C compiler identification source "CMakeCCompilerId.c" produced "a.out"
      
      The C compiler identification is GNU, found in:
        /opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/3.30.1/CompilerIdC/a.out
      
  -
    kind: "try_compile-v1"
    backtrace:
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/CMakeDetermineCompilerABI.cmake:74 (try_compile)"
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/CMakeTestCCompiler.cmake:26 (CMAKE_DETERMINE_COMPILER_ABI)"
      - "CMakeLists.txt:3 (project)"
    checks:
      - "Detecting C compiler ABI info"
    directories:
      source: "/opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-tpUHQp"
      binary: "/opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-tpUHQp"
    cmakeVariables:
      CMAKE_C_FLAGS: "-fPIC"
      CMAKE_C_FLAGS_DEBUG: "-g"
      CMAKE_EXE_LINKER_FLAGS: ""
      VCPKG_CHAINLOAD_TOOLCHAIN_FILE: "/opt/vcpkg/scripts/toolchains/linux.cmake"
      VCPKG_CRT_LINKAGE: "dynamic"
      VCPKG_CXX_FLAGS: ""
      VCPKG_CXX_FLAGS_DEBUG: ""
      VCPKG_CXX_FLAGS_RELEASE: ""
      VCPKG_C_FLAGS: ""
      VCPKG_C_FLAGS_DEBUG: ""
      VCPKG_C_FLAGS_RELEASE: ""
      VCPKG_INSTALLED_DIR: "/home/reagan/Pathological/vcpkg_installed"
      VCPKG_LINKER_FLAGS: ""
      VCPKG_LINKER_FLAGS_DEBUG: ""
      VCPKG_LINKER_FLAGS_RELEASE: ""
      VCPKG_PREFER_SYSTEM_LIBS: "OFF"
      VCPKG_TARGET_ARCHITECTURE: "x64"
      VCPKG_TARGET_TRIPLET: "x64-linux"
      Z_VCPKG_ROOT_DIR: "/opt/vcpkg"
    buildResult:
      variable: "CMAKE_C_ABI_COMPILED"
      cached: true
      stdout: |
        Change Dir: '/opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-tpUHQp'
        
        Run Build Command(s): /opt/vcpkg/downloads/tools/ninja/1.12.1-linux/ninja -v cmTC_9eacb
        [1/2] /usr/bin/cc   -fPIC    -v -o CMakeFiles/cmTC_9eacb.dir/CMakeCCompilerABI.c.o -c /opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/CMakeCCompilerABI.c
        Using built-in specs.
        COLLECT_GCC=/usr/bin/cc
        OFFLOAD_TARGET_NAMES=nvptx-none:amdgcn-amdhsa
        OFFLOAD_TARGET_DEFAULT=1
        Target: x86_64-linux-gnu
        Configured with: ../src/configure -v --with-pkgversion='Ubuntu 13.3.0-6ubuntu2~24.04' --with-bugurl=file:///usr/share/doc/gcc-13/README.Bugs --enable-languages=c,ada,c++,go,d,fortran,objc,obj-c++,m2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-13 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/libexec --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-bootstrap --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-libstdcxx-backtrace --enable-gnu-unique-object --disable-vtable-verify --enable-plugin --enable-default-pie --with-system-zlib --enable-libphobos-checking=release --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --disable-werror --enable-cet --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none=/build/gcc-13-fG75Ri/gcc-13-13.3.0/debian/tmp-nvptx/usr,amdgcn-amdhsa=/build/gcc-13-fG75Ri/gcc-13-13.3.0/debian/tmp-gcn/usr --enable-offload-defaulted --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu --with-build-config=bootstrap-lto-lean --enable-link-serialization=2
        Thread model: posix
        Supported LTO compression algorithms: zlib zstd
        gcc version 13.3.0 (Ubuntu 13.3.0-6ubuntu2~24.04) 
        COLLECT_GCC_OPTIONS='-fPIC' '-v' '-o' 'CMakeFiles/cmTC_9eacb.dir/CMakeCCompilerABI.c.o' '-c' '-mtune=generic' '-march=x86-64' '-dumpdir' 'CMakeFiles/cmTC_9eacb.dir/'
...
Skipped 263 lines
...
      source: "/opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-uwe4FH"
      binary: "/opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-uwe4FH"
    cmakeVariables:
      CMAKE_C_FLAGS: "-fPIC"
      CMAKE_C_FLAGS_DEBUG: "-g"
      CMAKE_EXE_LINKER_FLAGS: ""
      CMAKE_MODULE_PATH: "/opt/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean/CMake/modules"
      VCPKG_CHAINLOAD_TOOLCHAIN_FILE: "/opt/vcpkg/scripts/toolchains/linux.cmake"
      VCPKG_CRT_LINKAGE: "dynamic"
      VCPKG_CXX_FLAGS: ""
      VCPKG_CXX_FLAGS_DEBUG: ""
      VCPKG_CXX_FLAGS_RELEASE: ""
      VCPKG_C_FLAGS: ""
      VCPKG_C_FLAGS_DEBUG: ""
      VCPKG_C_FLAGS_RELEASE: ""
      VCPKG_INSTALLED_DIR: "/home/reagan/Pathological/vcpkg_installed"
      VCPKG_LINKER_FLAGS: ""
      VCPKG_LINKER_FLAGS_DEBUG: ""
      VCPKG_LINKER_FLAGS_RELEASE: ""
      VCPKG_PREFER_SYSTEM_LIBS: "OFF"
      VCPKG_TARGET_ARCHITECTURE: "x64"
      VCPKG_TARGET_TRIPLET: "x64-linux"
      Z_VCPKG_ROOT_DIR: "/opt/vcpkg"
    buildResult:
      variable: "X11_LIB_X11_SOLO"
      cached: true
      stdout: |
        Change Dir: '/opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-uwe4FH'
        
        Run Build Command(s): /opt/vcpkg/downloads/tools/ninja/1.12.1-linux/ninja -v cmTC_63f3c
        [1/2] /usr/bin/cc   -fPIC -DCHECK_FUNCTION_EXISTS=XOpenDisplay -o CMakeFiles/cmTC_63f3c.dir/CheckFunctionExists.c.o -c /opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-uwe4FH/CheckFunctionExists.c
        [2/2] : && /usr/bin/cc -fPIC -DCHECK_FUNCTION_EXISTS=XOpenDisplay  CMakeFiles/cmTC_63f3c.dir/CheckFunctionExists.c.o -o cmTC_63f3c  /usr/lib/x86_64-linux-gnu/libX11.so  /usr/lib/x86_64-linux-gnu/libXext.so && :
        
      exitCode: 0
  -
    kind: "try_compile-v1"
    backtrace:
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/CheckFunctionExists.cmake:86 (try_compile)"
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/FindX11.cmake:708 (check_function_exists)"
      - "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake:898 (_find_package)"
      - "src/CMakeLists.txt:181 (find_package)"
    checks:
      - "Looking for gethostbyname"
    directories:
      source: "/opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-JvWWSK"
      binary: "/opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-JvWWSK"
    cmakeVariables:
      CMAKE_C_FLAGS: "-fPIC"
      CMAKE_C_FLAGS_DEBUG: "-g"
      CMAKE_EXE_LINKER_FLAGS: ""
      CMAKE_MODULE_PATH: "/opt/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean/CMake/modules"
      VCPKG_CHAINLOAD_TOOLCHAIN_FILE: "/opt/vcpkg/scripts/toolchains/linux.cmake"
      VCPKG_CRT_LINKAGE: "dynamic"
      VCPKG_CXX_FLAGS: ""
      VCPKG_CXX_FLAGS_DEBUG: ""
      VCPKG_CXX_FLAGS_RELEASE: ""
      VCPKG_C_FLAGS: ""
      VCPKG_C_FLAGS_DEBUG: ""
      VCPKG_C_FLAGS_RELEASE: ""
      VCPKG_INSTALLED_DIR: "/home/reagan/Pathological/vcpkg_installed"
      VCPKG_LINKER_FLAGS: ""
      VCPKG_LINKER_FLAGS_DEBUG: ""
      VCPKG_LINKER_FLAGS_RELEASE: ""
      VCPKG_PREFER_SYSTEM_LIBS: "OFF"
      VCPKG_TARGET_ARCHITECTURE: "x64"
      VCPKG_TARGET_TRIPLET: "x64-linux"
      Z_VCPKG_ROOT_DIR: "/opt/vcpkg"
    buildResult:
      variable: "CMAKE_HAVE_GETHOSTBYNAME"
      cached: true
      stdout: |
        Change Dir: '/opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-JvWWSK'
        
        Run Build Command(s): /opt/vcpkg/downloads/tools/ninja/1.12.1-linux/ninja -v cmTC_48dba
        [1/2] /usr/bin/cc   -fPIC -DCHECK_FUNCTION_EXISTS=gethostbyname -o CMakeFiles/cmTC_48dba.dir/CheckFunctionExists.c.o -c /opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-JvWWSK/CheckFunctionExists.c
        [2/2] : && /usr/bin/cc -fPIC -DCHECK_FUNCTION_EXISTS=gethostbyname  CMakeFiles/cmTC_48dba.dir/CheckFunctionExists.c.o -o cmTC_48dba   && :
        
      exitCode: 0
  -
    kind: "try_compile-v1"
    backtrace:
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/CheckFunctionExists.cmake:86 (try_compile)"
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/FindX11.cmake:722 (check_function_exists)"
      - "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake:898 (_find_package)"
      - "src/CMakeLists.txt:181 (find_package)"
    checks:
      - "Looking for connect"
    directories:
      source: "/opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-kZhIG3"
      binary: "/opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-kZhIG3"
    cmakeVariables:
      CMAKE_C_FLAGS: "-fPIC"
      CMAKE_C_FLAGS_DEBUG: "-g"
      CMAKE_EXE_LINKER_FLAGS: ""
      CMAKE_MODULE_PATH: "/opt/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean/CMake/modules"
      VCPKG_CHAINLOAD_TOOLCHAIN_FILE: "/opt/vcpkg/scripts/toolchains/linux.cmake"
      VCPKG_CRT_LINKAGE: "dynamic"
      VCPKG_CXX_FLAGS: ""
      VCPKG_CXX_FLAGS_DEBUG: ""
      VCPKG_CXX_FLAGS_RELEASE: ""
      VCPKG_C_FLAGS: ""
      VCPKG_C_FLAGS_DEBUG: ""
      VCPKG_C_FLAGS_RELEASE: ""
      VCPKG_INSTALLED_DIR: "/home/reagan/Pathological/vcpkg_installed"
      VCPKG_LINKER_FLAGS: ""
      VCPKG_LINKER_FLAGS_DEBUG: ""
      VCPKG_LINKER_FLAGS_RELEASE: ""
      VCPKG_PREFER_SYSTEM_LIBS: "OFF"
      VCPKG_TARGET_ARCHITECTURE: "x64"
      VCPKG_TARGET_TRIPLET: "x64-linux"
      Z_VCPKG_ROOT_DIR: "/opt/vcpkg"
    buildResult:
      variable: "CMAKE_HAVE_CONNECT"
      cached: true
      stdout: |
        Change Dir: '/opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-kZhIG3'
        
        Run Build Command(s): /opt/vcpkg/downloads/tools/ninja/1.12.1-linux/ninja -v cmTC_0b0f6
        [1/2] /usr/bin/cc   -fPIC -DCHECK_FUNCTION_EXISTS=connect -o CMakeFiles/cmTC_0b0f6.dir/CheckFunctionExists.c.o -c /opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-kZhIG3/CheckFunctionExists.c
        [2/2] : && /usr/bin/cc -fPIC -DCHECK_FUNCTION_EXISTS=connect  CMakeFiles/cmTC_0b0f6.dir/CheckFunctionExists.c.o -o cmTC_0b0f6   && :
        
      exitCode: 0
  -
    kind: "try_compile-v1"
    backtrace:
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/CheckFunctionExists.cmake:86 (try_compile)"
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/FindX11.cmake:731 (check_function_exists)"
      - "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake:898 (_find_package)"
      - "src/CMakeLists.txt:181 (find_package)"
    checks:
      - "Looking for remove"
    directories:
      source: "/opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-lhMOWt"
      binary: "/opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-lhMOWt"
    cmakeVariables:
      CMAKE_C_FLAGS: "-fPIC"
      CMAKE_C_FLAGS_DEBUG: "-g"
      CMAKE_EXE_LINKER_FLAGS: ""
      CMAKE_MODULE_PATH: "/opt/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean/CMake/modules"
      VCPKG_CHAINLOAD_TOOLCHAIN_FILE: "/opt/vcpkg/scripts/toolchains/linux.cmake"
      VCPKG_CRT_LINKAGE: "dynamic"
      VCPKG_CXX_FLAGS: ""
      VCPKG_CXX_FLAGS_DEBUG: ""
      VCPKG_CXX_FLAGS_RELEASE: ""
      VCPKG_C_FLAGS: ""
      VCPKG_C_FLAGS_DEBUG: ""
      VCPKG_C_FLAGS_RELEASE: ""
      VCPKG_INSTALLED_DIR: "/home/reagan/Pathological/vcpkg_installed"
      VCPKG_LINKER_FLAGS: ""
      VCPKG_LINKER_FLAGS_DEBUG: ""
      VCPKG_LINKER_FLAGS_RELEASE: ""
      VCPKG_PREFER_SYSTEM_LIBS: "OFF"
      VCPKG_TARGET_ARCHITECTURE: "x64"
      VCPKG_TARGET_TRIPLET: "x64-linux"
      Z_VCPKG_ROOT_DIR: "/opt/vcpkg"
    buildResult:
      variable: "CMAKE_HAVE_REMOVE"
      cached: true
      stdout: |
        Change Dir: '/opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-lhMOWt'
        
        Run Build Command(s): /opt/vcpkg/downloads/tools/ninja/1.12.1-linux/ninja -v cmTC_9b8cd
        [1/2] /usr/bin/cc   -fPIC -DCHECK_FUNCTION_EXISTS=remove -o CMakeFiles/cmTC_9b8cd.dir/CheckFunctionExists.c.o -c /opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-lhMOWt/CheckFunctionExists.c
        [2/2] : && /usr/bin/cc -fPIC -DCHECK_FUNCTION_EXISTS=remove  CMakeFiles/cmTC_9b8cd.dir/CheckFunctionExists.c.o -o cmTC_9b8cd   && :
        
      exitCode: 0
  -
    kind: "try_compile-v1"
    backtrace:
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/CheckFunctionExists.cmake:86 (try_compile)"
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/FindX11.cmake:740 (check_function_exists)"
      - "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake:898 (_find_package)"
      - "src/CMakeLists.txt:181 (find_package)"
    checks:
      - "Looking for shmat"
    directories:
      source: "/opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-uZAkjG"
      binary: "/opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-uZAkjG"
    cmakeVariables:
      CMAKE_C_FLAGS: "-fPIC"
      CMAKE_C_FLAGS_DEBUG: "-g"
      CMAKE_EXE_LINKER_FLAGS: ""
      CMAKE_MODULE_PATH: "/opt/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean/CMake/modules"
      VCPKG_CHAINLOAD_TOOLCHAIN_FILE: "/opt/vcpkg/scripts/toolchains/linux.cmake"
      VCPKG_CRT_LINKAGE: "dynamic"
      VCPKG_CXX_FLAGS: ""
      VCPKG_CXX_FLAGS_DEBUG: ""
      VCPKG_CXX_FLAGS_RELEASE: ""
      VCPKG_C_FLAGS: ""
      VCPKG_C_FLAGS_DEBUG: ""
      VCPKG_C_FLAGS_RELEASE: ""
      VCPKG_INSTALLED_DIR: "/home/reagan/Pathological/vcpkg_installed"
      VCPKG_LINKER_FLAGS: ""
      VCPKG_LINKER_FLAGS_DEBUG: ""
      VCPKG_LINKER_FLAGS_RELEASE: ""
      VCPKG_PREFER_SYSTEM_LIBS: "OFF"
      VCPKG_TARGET_ARCHITECTURE: "x64"
      VCPKG_TARGET_TRIPLET: "x64-linux"
      Z_VCPKG_ROOT_DIR: "/opt/vcpkg"
    buildResult:
      variable: "CMAKE_HAVE_SHMAT"
      cached: true
      stdout: |
        Change Dir: '/opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-uZAkjG'
        
        Run Build Command(s): /opt/vcpkg/downloads/tools/ninja/1.12.1-linux/ninja -v cmTC_2a6ac
        [1/2] /usr/bin/cc   -fPIC -DCHECK_FUNCTION_EXISTS=shmat -o CMakeFiles/cmTC_2a6ac.dir/CheckFunctionExists.c.o -c /opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-uZAkjG/CheckFunctionExists.c
        [2/2] : && /usr/bin/cc -fPIC -DCHECK_FUNCTION_EXISTS=shmat  CMakeFiles/cmTC_2a6ac.dir/CheckFunctionExists.c.o -o cmTC_2a6ac   && :
        
      exitCode: 0
...
```
</details>

<details><summary>/opt/vcpkg/buildtrees/glfw3/config-x64-linux-rel-CMakeConfigureLog.yaml.log</summary>

```

---
events:
  -
    kind: "message-v1"
    backtrace:
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/CMakeDetermineSystem.cmake:205 (message)"
      - "CMakeLists.txt:3 (project)"
    message: |
      The system is: Linux -  - x86_64
  -
    kind: "message-v1"
    backtrace:
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/CMakeDetermineCompilerId.cmake:17 (message)"
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/CMakeDetermineCompilerId.cmake:64 (__determine_compiler_id_test)"
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/CMakeDetermineCCompiler.cmake:123 (CMAKE_DETERMINE_COMPILER_ID)"
      - "CMakeLists.txt:3 (project)"
    message: |
      Compiling the C compiler identification source file "CMakeCCompilerId.c" succeeded.
      Compiler: /usr/bin/cc 
      Build flags: -fPIC
      Id flags:  
      
      The output was:
      0
      
      
      Compilation of the C compiler identification source "CMakeCCompilerId.c" produced "a.out"
      
      The C compiler identification is GNU, found in:
        /opt/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/3.30.1/CompilerIdC/a.out
      
  -
    kind: "try_compile-v1"
    backtrace:
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/CMakeDetermineCompilerABI.cmake:74 (try_compile)"
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/CMakeTestCCompiler.cmake:26 (CMAKE_DETERMINE_COMPILER_ABI)"
      - "CMakeLists.txt:3 (project)"
    checks:
      - "Detecting C compiler ABI info"
    directories:
      source: "/opt/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-pZjtvt"
      binary: "/opt/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-pZjtvt"
    cmakeVariables:
      CMAKE_C_FLAGS: "-fPIC"
      CMAKE_C_FLAGS_DEBUG: "-g"
      CMAKE_EXE_LINKER_FLAGS: ""
      VCPKG_CHAINLOAD_TOOLCHAIN_FILE: "/opt/vcpkg/scripts/toolchains/linux.cmake"
      VCPKG_CRT_LINKAGE: "dynamic"
      VCPKG_CXX_FLAGS: ""
      VCPKG_CXX_FLAGS_DEBUG: ""
      VCPKG_CXX_FLAGS_RELEASE: ""
      VCPKG_C_FLAGS: ""
      VCPKG_C_FLAGS_DEBUG: ""
      VCPKG_C_FLAGS_RELEASE: ""
      VCPKG_INSTALLED_DIR: "/home/reagan/Pathological/vcpkg_installed"
      VCPKG_LINKER_FLAGS: ""
      VCPKG_LINKER_FLAGS_DEBUG: ""
      VCPKG_LINKER_FLAGS_RELEASE: ""
      VCPKG_PREFER_SYSTEM_LIBS: "OFF"
      VCPKG_TARGET_ARCHITECTURE: "x64"
      VCPKG_TARGET_TRIPLET: "x64-linux"
      Z_VCPKG_ROOT_DIR: "/opt/vcpkg"
    buildResult:
      variable: "CMAKE_C_ABI_COMPILED"
      cached: true
      stdout: |
        Change Dir: '/opt/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-pZjtvt'
        
        Run Build Command(s): /opt/vcpkg/downloads/tools/ninja/1.12.1-linux/ninja -v cmTC_1f6f6
        [1/2] /usr/bin/cc   -fPIC    -v -o CMakeFiles/cmTC_1f6f6.dir/CMakeCCompilerABI.c.o -c /opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/CMakeCCompilerABI.c
        Using built-in specs.
        COLLECT_GCC=/usr/bin/cc
        OFFLOAD_TARGET_NAMES=nvptx-none:amdgcn-amdhsa
        OFFLOAD_TARGET_DEFAULT=1
        Target: x86_64-linux-gnu
...
Skipped 309 lines
...
    checks:
      - "Looking for gethostbyname"
    directories:
      source: "/opt/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-qcYivR"
      binary: "/opt/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-qcYivR"
    cmakeVariables:
      CMAKE_C_FLAGS: "-fPIC"
      CMAKE_C_FLAGS_DEBUG: "-g"
      CMAKE_EXE_LINKER_FLAGS: ""
      CMAKE_MODULE_PATH: "/opt/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean/CMake/modules"
      VCPKG_CHAINLOAD_TOOLCHAIN_FILE: "/opt/vcpkg/scripts/toolchains/linux.cmake"
      VCPKG_CRT_LINKAGE: "dynamic"
      VCPKG_CXX_FLAGS: ""
      VCPKG_CXX_FLAGS_DEBUG: ""
      VCPKG_CXX_FLAGS_RELEASE: ""
      VCPKG_C_FLAGS: ""
      VCPKG_C_FLAGS_DEBUG: ""
      VCPKG_C_FLAGS_RELEASE: ""
      VCPKG_INSTALLED_DIR: "/home/reagan/Pathological/vcpkg_installed"
      VCPKG_LINKER_FLAGS: ""
      VCPKG_LINKER_FLAGS_DEBUG: ""
      VCPKG_LINKER_FLAGS_RELEASE: ""
      VCPKG_PREFER_SYSTEM_LIBS: "OFF"
      VCPKG_TARGET_ARCHITECTURE: "x64"
      VCPKG_TARGET_TRIPLET: "x64-linux"
      Z_VCPKG_ROOT_DIR: "/opt/vcpkg"
    buildResult:
      variable: "CMAKE_HAVE_GETHOSTBYNAME"
      cached: true
      stdout: |
        Change Dir: '/opt/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-qcYivR'
        
        Run Build Command(s): /opt/vcpkg/downloads/tools/ninja/1.12.1-linux/ninja -v cmTC_9148a
        [1/2] /usr/bin/cc   -fPIC -DCHECK_FUNCTION_EXISTS=gethostbyname -o CMakeFiles/cmTC_9148a.dir/CheckFunctionExists.c.o -c /opt/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-qcYivR/CheckFunctionExists.c
        [2/2] : && /usr/bin/cc -fPIC -DCHECK_FUNCTION_EXISTS=gethostbyname  CMakeFiles/cmTC_9148a.dir/CheckFunctionExists.c.o -o cmTC_9148a   && :
        
      exitCode: 0
  -
    kind: "try_compile-v1"
    backtrace:
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/CheckFunctionExists.cmake:86 (try_compile)"
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/FindX11.cmake:722 (check_function_exists)"
      - "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake:898 (_find_package)"
      - "src/CMakeLists.txt:181 (find_package)"
    checks:
      - "Looking for connect"
    directories:
      source: "/opt/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-rgya9y"
      binary: "/opt/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-rgya9y"
    cmakeVariables:
      CMAKE_C_FLAGS: "-fPIC"
      CMAKE_C_FLAGS_DEBUG: "-g"
      CMAKE_EXE_LINKER_FLAGS: ""
      CMAKE_MODULE_PATH: "/opt/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean/CMake/modules"
      VCPKG_CHAINLOAD_TOOLCHAIN_FILE: "/opt/vcpkg/scripts/toolchains/linux.cmake"
      VCPKG_CRT_LINKAGE: "dynamic"
      VCPKG_CXX_FLAGS: ""
      VCPKG_CXX_FLAGS_DEBUG: ""
      VCPKG_CXX_FLAGS_RELEASE: ""
      VCPKG_C_FLAGS: ""
      VCPKG_C_FLAGS_DEBUG: ""
      VCPKG_C_FLAGS_RELEASE: ""
      VCPKG_INSTALLED_DIR: "/home/reagan/Pathological/vcpkg_installed"
      VCPKG_LINKER_FLAGS: ""
      VCPKG_LINKER_FLAGS_DEBUG: ""
      VCPKG_LINKER_FLAGS_RELEASE: ""
      VCPKG_PREFER_SYSTEM_LIBS: "OFF"
      VCPKG_TARGET_ARCHITECTURE: "x64"
      VCPKG_TARGET_TRIPLET: "x64-linux"
      Z_VCPKG_ROOT_DIR: "/opt/vcpkg"
    buildResult:
      variable: "CMAKE_HAVE_CONNECT"
      cached: true
      stdout: |
        Change Dir: '/opt/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-rgya9y'
        
        Run Build Command(s): /opt/vcpkg/downloads/tools/ninja/1.12.1-linux/ninja -v cmTC_bd1ed
        [1/2] /usr/bin/cc   -fPIC -DCHECK_FUNCTION_EXISTS=connect -o CMakeFiles/cmTC_bd1ed.dir/CheckFunctionExists.c.o -c /opt/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-rgya9y/CheckFunctionExists.c
        [2/2] : && /usr/bin/cc -fPIC -DCHECK_FUNCTION_EXISTS=connect  CMakeFiles/cmTC_bd1ed.dir/CheckFunctionExists.c.o -o cmTC_bd1ed   && :
        
      exitCode: 0
  -
    kind: "try_compile-v1"
    backtrace:
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/CheckFunctionExists.cmake:86 (try_compile)"
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/FindX11.cmake:731 (check_function_exists)"
      - "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake:898 (_find_package)"
      - "src/CMakeLists.txt:181 (find_package)"
    checks:
      - "Looking for remove"
    directories:
      source: "/opt/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-cvzwOd"
      binary: "/opt/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-cvzwOd"
    cmakeVariables:
      CMAKE_C_FLAGS: "-fPIC"
      CMAKE_C_FLAGS_DEBUG: "-g"
      CMAKE_EXE_LINKER_FLAGS: ""
      CMAKE_MODULE_PATH: "/opt/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean/CMake/modules"
      VCPKG_CHAINLOAD_TOOLCHAIN_FILE: "/opt/vcpkg/scripts/toolchains/linux.cmake"
      VCPKG_CRT_LINKAGE: "dynamic"
      VCPKG_CXX_FLAGS: ""
      VCPKG_CXX_FLAGS_DEBUG: ""
      VCPKG_CXX_FLAGS_RELEASE: ""
      VCPKG_C_FLAGS: ""
      VCPKG_C_FLAGS_DEBUG: ""
      VCPKG_C_FLAGS_RELEASE: ""
      VCPKG_INSTALLED_DIR: "/home/reagan/Pathological/vcpkg_installed"
      VCPKG_LINKER_FLAGS: ""
      VCPKG_LINKER_FLAGS_DEBUG: ""
      VCPKG_LINKER_FLAGS_RELEASE: ""
      VCPKG_PREFER_SYSTEM_LIBS: "OFF"
      VCPKG_TARGET_ARCHITECTURE: "x64"
      VCPKG_TARGET_TRIPLET: "x64-linux"
      Z_VCPKG_ROOT_DIR: "/opt/vcpkg"
    buildResult:
      variable: "CMAKE_HAVE_REMOVE"
      cached: true
      stdout: |
        Change Dir: '/opt/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-cvzwOd'
        
        Run Build Command(s): /opt/vcpkg/downloads/tools/ninja/1.12.1-linux/ninja -v cmTC_2b72e
        [1/2] /usr/bin/cc   -fPIC -DCHECK_FUNCTION_EXISTS=remove -o CMakeFiles/cmTC_2b72e.dir/CheckFunctionExists.c.o -c /opt/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-cvzwOd/CheckFunctionExists.c
        [2/2] : && /usr/bin/cc -fPIC -DCHECK_FUNCTION_EXISTS=remove  CMakeFiles/cmTC_2b72e.dir/CheckFunctionExists.c.o -o cmTC_2b72e   && :
        
      exitCode: 0
  -
    kind: "try_compile-v1"
    backtrace:
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/CheckFunctionExists.cmake:86 (try_compile)"
      - "/opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/share/cmake-3.30/Modules/FindX11.cmake:740 (check_function_exists)"
      - "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake:898 (_find_package)"
      - "src/CMakeLists.txt:181 (find_package)"
    checks:
      - "Looking for shmat"
    directories:
      source: "/opt/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-2Zduw1"
      binary: "/opt/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-2Zduw1"
    cmakeVariables:
      CMAKE_C_FLAGS: "-fPIC"
      CMAKE_C_FLAGS_DEBUG: "-g"
      CMAKE_EXE_LINKER_FLAGS: ""
      CMAKE_MODULE_PATH: "/opt/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean/CMake/modules"
      VCPKG_CHAINLOAD_TOOLCHAIN_FILE: "/opt/vcpkg/scripts/toolchains/linux.cmake"
      VCPKG_CRT_LINKAGE: "dynamic"
      VCPKG_CXX_FLAGS: ""
      VCPKG_CXX_FLAGS_DEBUG: ""
      VCPKG_CXX_FLAGS_RELEASE: ""
      VCPKG_C_FLAGS: ""
      VCPKG_C_FLAGS_DEBUG: ""
      VCPKG_C_FLAGS_RELEASE: ""
      VCPKG_INSTALLED_DIR: "/home/reagan/Pathological/vcpkg_installed"
      VCPKG_LINKER_FLAGS: ""
      VCPKG_LINKER_FLAGS_DEBUG: ""
      VCPKG_LINKER_FLAGS_RELEASE: ""
      VCPKG_PREFER_SYSTEM_LIBS: "OFF"
      VCPKG_TARGET_ARCHITECTURE: "x64"
      VCPKG_TARGET_TRIPLET: "x64-linux"
      Z_VCPKG_ROOT_DIR: "/opt/vcpkg"
    buildResult:
      variable: "CMAKE_HAVE_SHMAT"
      cached: true
      stdout: |
        Change Dir: '/opt/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-2Zduw1'
        
        Run Build Command(s): /opt/vcpkg/downloads/tools/ninja/1.12.1-linux/ninja -v cmTC_0101f
        [1/2] /usr/bin/cc   -fPIC -DCHECK_FUNCTION_EXISTS=shmat -o CMakeFiles/cmTC_0101f.dir/CheckFunctionExists.c.o -c /opt/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-2Zduw1/CheckFunctionExists.c
        [2/2] : && /usr/bin/cc -fPIC -DCHECK_FUNCTION_EXISTS=shmat  CMakeFiles/cmTC_0101f.dir/CheckFunctionExists.c.o -o cmTC_0101f   && :
        
      exitCode: 0
...
```
</details>

<details><summary>/opt/vcpkg/buildtrees/glfw3/config-x64-linux-rel-CMakeCache.txt.log</summary>

```
# This is the CMakeCache file.
# For build in directory: /opt/vcpkg/buildtrees/glfw3/x64-linux-rel
# It was generated by CMake: /opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/bin/cmake
# You can edit this file to change values found and used by cmake.
# If you do not want to change any of the values, simply exit the editor.
# If you do want to change a value, simply edit, save, and exit the editor.
# The syntax for the file is as follows:
# KEY:TYPE=VALUE
# KEY is the name of a variable in the cache.
# TYPE is a hint to GUIs for the type of VALUE, DO NOT EDIT TYPE!.
# VALUE is the current value for the KEY.

########################
# EXTERNAL cache entries
########################

//Build shared libraries
BUILD_SHARED_LIBS:BOOL=OFF

//Path to a program.
CMAKE_ADDR2LINE:FILEPATH=/usr/bin/addr2line

//Path to a program.
CMAKE_AR:FILEPATH=/usr/bin/ar

//Choose the type of build, options are: None Debug Release RelWithDebInfo
// MinSizeRel ...
CMAKE_BUILD_TYPE:STRING=Release

CMAKE_CROSSCOMPILING:BOOL=OFF

//C compiler
CMAKE_C_COMPILER:FILEPATH=/usr/bin/cc

//A wrapper around 'ar' adding the appropriate '--plugin' option
// for the GCC compiler
CMAKE_C_COMPILER_AR:FILEPATH=/usr/bin/gcc-ar-13

//A wrapper around 'ranlib' adding the appropriate '--plugin' option
// for the GCC compiler
CMAKE_C_COMPILER_RANLIB:FILEPATH=/usr/bin/gcc-ranlib-13

//Flags used by the C compiler during all build types.
CMAKE_C_FLAGS:STRING=-fPIC

//Flags used by the C compiler during DEBUG builds.
CMAKE_C_FLAGS_DEBUG:STRING=-g

//Flags used by the C compiler during MINSIZEREL builds.
CMAKE_C_FLAGS_MINSIZEREL:STRING=-Os -DNDEBUG

//Flags used by the C compiler during RELEASE builds.
CMAKE_C_FLAGS_RELEASE:STRING=-O3 -DNDEBUG

//Flags used by the C compiler during RELWITHDEBINFO builds.
CMAKE_C_FLAGS_RELWITHDEBINFO:STRING=-O2 -g -DNDEBUG

//Path to a program.
CMAKE_DLLTOOL:FILEPATH=CMAKE_DLLTOOL-NOTFOUND

//No help, variable specified on the command line.
CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION:UNINITIALIZED=ON

//Flags used by the linker during all build types.
CMAKE_EXE_LINKER_FLAGS:STRING=

//Flags used by the linker during DEBUG builds.
CMAKE_EXE_LINKER_FLAGS_DEBUG:STRING=

//Flags used by the linker during MINSIZEREL builds.
CMAKE_EXE_LINKER_FLAGS_MINSIZEREL:STRING=

//Flags used by the linker during RELEASE builds.
CMAKE_EXE_LINKER_FLAGS_RELEASE:STRING=

//Flags used by the linker during RELWITHDEBINFO builds.
CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO:STRING=

//Enable/Disable output of compile commands during generation.
CMAKE_EXPORT_COMPILE_COMMANDS:BOOL=

//No help, variable specified on the command line.
CMAKE_EXPORT_NO_PACKAGE_REGISTRY:UNINITIALIZED=ON

//No help, variable specified on the command line.
CMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY:UNINITIALIZED=ON

//No help, variable specified on the command line.
CMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY:UNINITIALIZED=ON

//Value Computed by CMake.
CMAKE_FIND_PACKAGE_REDIRECTS_DIR:STATIC=/opt/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/pkgRedirects

//No help, variable specified on the command line.
CMAKE_INSTALL_BINDIR:STRING=bin

//Read-only architecture-independent data (DATAROOTDIR)
CMAKE_INSTALL_DATADIR:PATH=

//Read-only architecture-independent data root (share)
CMAKE_INSTALL_DATAROOTDIR:PATH=share

//Documentation root (DATAROOTDIR/doc/PROJECT_NAME)
CMAKE_INSTALL_DOCDIR:PATH=

//C header files (include)
CMAKE_INSTALL_INCLUDEDIR:PATH=include

//Info documentation (DATAROOTDIR/info)
CMAKE_INSTALL_INFODIR:PATH=

//No help, variable specified on the command line.
CMAKE_INSTALL_LIBDIR:STRING=lib

//Program executables (libexec)
CMAKE_INSTALL_LIBEXECDIR:PATH=libexec

//Locale-dependent data (DATAROOTDIR/locale)
CMAKE_INSTALL_LOCALEDIR:PATH=

//Modifiable single-machine data (var)
CMAKE_INSTALL_LOCALSTATEDIR:PATH=var

//Man documentation (DATAROOTDIR/man)
CMAKE_INSTALL_MANDIR:PATH=

//C header files for non-gcc (/usr/include)
CMAKE_INSTALL_OLDINCLUDEDIR:PATH=/usr/include

//Install path prefix, prepended onto install directories.
CMAKE_INSTALL_PREFIX:PATH=/opt/vcpkg/packages/glfw3_x64-linux

//Run-time variable data (LOCALSTATEDIR/run)
CMAKE_INSTALL_RUNSTATEDIR:PATH=

//System admin executables (sbin)
CMAKE_INSTALL_SBINDIR:PATH=sbin

//Modifiable architecture-independent data (com)
CMAKE_INSTALL_SHAREDSTATEDIR:PATH=com

//Read-only single-machine data (etc)
CMAKE_INSTALL_SYSCONFDIR:PATH=etc

...
Skipped 945 lines
...
//ADVANCED property for variable: X11_Xrender_LIB
X11_Xrender_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xshape_INCLUDE_PATH
X11_Xshape_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xss_INCLUDE_PATH
X11_Xss_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xss_LIB
X11_Xss_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xt_INCLUDE_PATH
X11_Xt_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xt_LIB
X11_Xt_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xtst_INCLUDE_PATH
X11_Xtst_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xtst_LIB
X11_Xtst_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xutil_INCLUDE_PATH
X11_Xutil_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xv_INCLUDE_PATH
X11_Xv_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xv_LIB
X11_Xv_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xxf86misc_INCLUDE_PATH
X11_Xxf86misc_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xxf86misc_LIB
X11_Xxf86misc_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xxf86vm_INCLUDE_PATH
X11_Xxf86vm_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xxf86vm_LIB
X11_Xxf86vm_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_dpms_INCLUDE_PATH
X11_dpms_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_INCLUDE_PATH
X11_xcb_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_LIB
X11_xcb_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_composite_INCLUDE_PATH
X11_xcb_composite_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_composite_LIB
X11_xcb_composite_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_cursor_INCLUDE_PATH
X11_xcb_cursor_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_cursor_LIB
X11_xcb_cursor_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_damage_INCLUDE_PATH
X11_xcb_damage_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_damage_LIB
X11_xcb_damage_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dpms_INCLUDE_PATH
X11_xcb_dpms_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dpms_LIB
X11_xcb_dpms_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dri2_INCLUDE_PATH
X11_xcb_dri2_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dri2_LIB
X11_xcb_dri2_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dri3_INCLUDE_PATH
X11_xcb_dri3_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dri3_LIB
X11_xcb_dri3_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_errors_INCLUDE_PATH
X11_xcb_errors_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_errors_LIB
X11_xcb_errors_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_ewmh_INCLUDE_PATH
X11_xcb_ewmh_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_ewmh_LIB
X11_xcb_ewmh_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_glx_INCLUDE_PATH
X11_xcb_glx_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_glx_LIB
X11_xcb_glx_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_icccm_INCLUDE_PATH
X11_xcb_icccm_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_icccm_LIB
X11_xcb_icccm_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_image_INCLUDE_PATH
X11_xcb_image_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_image_LIB
X11_xcb_image_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_keysyms_INCLUDE_PATH
X11_xcb_keysyms_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_keysyms_LIB
X11_xcb_keysyms_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_present_INCLUDE_PATH
X11_xcb_present_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_present_LIB
X11_xcb_present_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_randr_INCLUDE_PATH
X11_xcb_randr_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_randr_LIB
X11_xcb_randr_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_record_INCLUDE_PATH
X11_xcb_record_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_record_LIB
X11_xcb_record_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_render_INCLUDE_PATH
X11_xcb_render_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_render_LIB
X11_xcb_render_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_render_util_INCLUDE_PATH
X11_xcb_render_util_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_render_util_LIB
X11_xcb_render_util_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_res_INCLUDE_PATH
X11_xcb_res_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_res_LIB
X11_xcb_res_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_screensaver_INCLUDE_PATH
X11_xcb_screensaver_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_screensaver_LIB
X11_xcb_screensaver_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_shape_INCLUDE_PATH
X11_xcb_shape_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_shape_LIB
X11_xcb_shape_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_shm_INCLUDE_PATH
X11_xcb_shm_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_shm_LIB
X11_xcb_shm_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_sync_INCLUDE_PATH
X11_xcb_sync_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_sync_LIB
X11_xcb_sync_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_util_INCLUDE_PATH
X11_xcb_util_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_util_LIB
X11_xcb_util_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xf86dri_INCLUDE_PATH
X11_xcb_xf86dri_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xf86dri_LIB
X11_xcb_xf86dri_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xfixes_INCLUDE_PATH
X11_xcb_xfixes_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xfixes_LIB
X11_xcb_xfixes_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xinerama_INCLUDE_PATH
X11_xcb_xinerama_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xinerama_LIB
X11_xcb_xinerama_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xinput_INCLUDE_PATH
X11_xcb_xinput_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xinput_LIB
X11_xcb_xinput_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xkb_LIB
X11_xcb_xkb_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xrm_INCLUDE_PATH
X11_xcb_xrm_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xrm_LIB
X11_xcb_xrm_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xtest_INCLUDE_PATH
X11_xcb_xtest_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xtest_LIB
X11_xcb_xtest_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xv_INCLUDE_PATH
X11_xcb_xv_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xv_LIB
X11_xcb_xv_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xvmc_INCLUDE_PATH
X11_xcb_xvmc_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xvmc_LIB
X11_xcb_xvmc_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbcommon_INCLUDE_PATH
X11_xkbcommon_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbcommon_LIB
X11_xkbcommon_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbcommon_X11_INCLUDE_PATH
X11_xkbcommon_X11_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbcommon_X11_LIB
X11_xkbcommon_X11_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbfile_INCLUDE_PATH
X11_xkbfile_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbfile_LIB
X11_xkbfile_LIB-ADVANCED:INTERNAL=1
//Making sure VCPKG_MANIFEST_MODE doesn't change
Z_VCPKG_CHECK_MANIFEST_MODE:INTERNAL=OFF
//Vcpkg root directory
Z_VCPKG_ROOT_DIR:INTERNAL=/opt/vcpkg
//linker supports push/pop state
_CMAKE_LINKER_PUSHPOP_STATE_SUPPORTED:INTERNAL=TRUE
//CMAKE_INSTALL_PREFIX during last run
_GNUInstallDirs_LAST_CMAKE_INSTALL_PREFIX:INTERNAL=/opt/vcpkg/packages/glfw3_x64-linux
```
</details>

<details><summary>/opt/vcpkg/buildtrees/glfw3/config-x64-linux-dbg-CMakeCache.txt.log</summary>

```
# This is the CMakeCache file.
# For build in directory: /opt/vcpkg/buildtrees/glfw3/x64-linux-dbg
# It was generated by CMake: /opt/vcpkg/downloads/tools/cmake-3.30.1-linux/cmake-3.30.1-linux-x86_64/bin/cmake
# You can edit this file to change values found and used by cmake.
# If you do not want to change any of the values, simply exit the editor.
# If you do want to change a value, simply edit, save, and exit the editor.
# The syntax for the file is as follows:
# KEY:TYPE=VALUE
# KEY is the name of a variable in the cache.
# TYPE is a hint to GUIs for the type of VALUE, DO NOT EDIT TYPE!.
# VALUE is the current value for the KEY.

########################
# EXTERNAL cache entries
########################

//Build shared libraries
BUILD_SHARED_LIBS:BOOL=OFF

//Path to a program.
CMAKE_ADDR2LINE:FILEPATH=/usr/bin/addr2line

//Path to a program.
CMAKE_AR:FILEPATH=/usr/bin/ar

//Choose the type of build, options are: None Debug Release RelWithDebInfo
// MinSizeRel ...
CMAKE_BUILD_TYPE:STRING=Debug

CMAKE_CROSSCOMPILING:BOOL=OFF

//C compiler
CMAKE_C_COMPILER:FILEPATH=/usr/bin/cc

//A wrapper around 'ar' adding the appropriate '--plugin' option
// for the GCC compiler
CMAKE_C_COMPILER_AR:FILEPATH=/usr/bin/gcc-ar-13

//A wrapper around 'ranlib' adding the appropriate '--plugin' option
// for the GCC compiler
CMAKE_C_COMPILER_RANLIB:FILEPATH=/usr/bin/gcc-ranlib-13

//Flags used by the C compiler during all build types.
CMAKE_C_FLAGS:STRING=-fPIC

//Flags used by the C compiler during DEBUG builds.
CMAKE_C_FLAGS_DEBUG:STRING=-g

//Flags used by the C compiler during MINSIZEREL builds.
CMAKE_C_FLAGS_MINSIZEREL:STRING=-Os -DNDEBUG

//Flags used by the C compiler during RELEASE builds.
CMAKE_C_FLAGS_RELEASE:STRING=-O3 -DNDEBUG

//Flags used by the C compiler during RELWITHDEBINFO builds.
CMAKE_C_FLAGS_RELWITHDEBINFO:STRING=-O2 -g -DNDEBUG

//Path to a program.
CMAKE_DLLTOOL:FILEPATH=CMAKE_DLLTOOL-NOTFOUND

//No help, variable specified on the command line.
CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION:UNINITIALIZED=ON

//Flags used by the linker during all build types.
CMAKE_EXE_LINKER_FLAGS:STRING=

//Flags used by the linker during DEBUG builds.
CMAKE_EXE_LINKER_FLAGS_DEBUG:STRING=

//Flags used by the linker during MINSIZEREL builds.
CMAKE_EXE_LINKER_FLAGS_MINSIZEREL:STRING=

//Flags used by the linker during RELEASE builds.
CMAKE_EXE_LINKER_FLAGS_RELEASE:STRING=

//Flags used by the linker during RELWITHDEBINFO builds.
CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO:STRING=

//Enable/Disable output of compile commands during generation.
CMAKE_EXPORT_COMPILE_COMMANDS:BOOL=

//No help, variable specified on the command line.
CMAKE_EXPORT_NO_PACKAGE_REGISTRY:UNINITIALIZED=ON

//No help, variable specified on the command line.
CMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY:UNINITIALIZED=ON

//No help, variable specified on the command line.
CMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY:UNINITIALIZED=ON

//Value Computed by CMake.
CMAKE_FIND_PACKAGE_REDIRECTS_DIR:STATIC=/opt/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/pkgRedirects

//No help, variable specified on the command line.
CMAKE_INSTALL_BINDIR:STRING=bin

//Read-only architecture-independent data (DATAROOTDIR)
CMAKE_INSTALL_DATADIR:PATH=

//Read-only architecture-independent data root (share)
CMAKE_INSTALL_DATAROOTDIR:PATH=share

//Documentation root (DATAROOTDIR/doc/PROJECT_NAME)
CMAKE_INSTALL_DOCDIR:PATH=

//C header files (include)
CMAKE_INSTALL_INCLUDEDIR:PATH=include

//Info documentation (DATAROOTDIR/info)
CMAKE_INSTALL_INFODIR:PATH=

//No help, variable specified on the command line.
CMAKE_INSTALL_LIBDIR:STRING=lib

//Program executables (libexec)
CMAKE_INSTALL_LIBEXECDIR:PATH=libexec

//Locale-dependent data (DATAROOTDIR/locale)
CMAKE_INSTALL_LOCALEDIR:PATH=

//Modifiable single-machine data (var)
CMAKE_INSTALL_LOCALSTATEDIR:PATH=var

//Man documentation (DATAROOTDIR/man)
CMAKE_INSTALL_MANDIR:PATH=

//C header files for non-gcc (/usr/include)
CMAKE_INSTALL_OLDINCLUDEDIR:PATH=/usr/include

//Install path prefix, prepended onto install directories.
CMAKE_INSTALL_PREFIX:PATH=/opt/vcpkg/packages/glfw3_x64-linux/debug

//Run-time variable data (LOCALSTATEDIR/run)
...
Skipped 968 lines
...
//ADVANCED property for variable: X11_Xtst_INCLUDE_PATH
X11_Xtst_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xtst_LIB
X11_Xtst_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xutil_INCLUDE_PATH
X11_Xutil_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xv_INCLUDE_PATH
X11_Xv_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xv_LIB
X11_Xv_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xxf86misc_INCLUDE_PATH
X11_Xxf86misc_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xxf86misc_LIB
X11_Xxf86misc_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xxf86vm_INCLUDE_PATH
X11_Xxf86vm_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xxf86vm_LIB
X11_Xxf86vm_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_dpms_INCLUDE_PATH
X11_dpms_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_INCLUDE_PATH
X11_xcb_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_LIB
X11_xcb_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_composite_INCLUDE_PATH
X11_xcb_composite_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_composite_LIB
X11_xcb_composite_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_cursor_INCLUDE_PATH
X11_xcb_cursor_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_cursor_LIB
X11_xcb_cursor_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_damage_INCLUDE_PATH
X11_xcb_damage_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_damage_LIB
X11_xcb_damage_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dpms_INCLUDE_PATH
X11_xcb_dpms_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dpms_LIB
X11_xcb_dpms_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dri2_INCLUDE_PATH
X11_xcb_dri2_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dri2_LIB
X11_xcb_dri2_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dri3_INCLUDE_PATH
X11_xcb_dri3_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dri3_LIB
X11_xcb_dri3_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_errors_INCLUDE_PATH
X11_xcb_errors_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_errors_LIB
X11_xcb_errors_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_ewmh_INCLUDE_PATH
X11_xcb_ewmh_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_ewmh_LIB
X11_xcb_ewmh_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_glx_INCLUDE_PATH
X11_xcb_glx_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_glx_LIB
X11_xcb_glx_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_icccm_INCLUDE_PATH
X11_xcb_icccm_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_icccm_LIB
X11_xcb_icccm_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_image_INCLUDE_PATH
X11_xcb_image_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_image_LIB
X11_xcb_image_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_keysyms_INCLUDE_PATH
X11_xcb_keysyms_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_keysyms_LIB
X11_xcb_keysyms_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_present_INCLUDE_PATH
X11_xcb_present_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_present_LIB
X11_xcb_present_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_randr_INCLUDE_PATH
X11_xcb_randr_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_randr_LIB
X11_xcb_randr_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_record_INCLUDE_PATH
X11_xcb_record_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_record_LIB
X11_xcb_record_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_render_INCLUDE_PATH
X11_xcb_render_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_render_LIB
X11_xcb_render_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_render_util_INCLUDE_PATH
X11_xcb_render_util_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_render_util_LIB
X11_xcb_render_util_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_res_INCLUDE_PATH
X11_xcb_res_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_res_LIB
X11_xcb_res_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_screensaver_INCLUDE_PATH
X11_xcb_screensaver_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_screensaver_LIB
X11_xcb_screensaver_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_shape_INCLUDE_PATH
X11_xcb_shape_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_shape_LIB
X11_xcb_shape_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_shm_INCLUDE_PATH
X11_xcb_shm_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_shm_LIB
X11_xcb_shm_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_sync_INCLUDE_PATH
X11_xcb_sync_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_sync_LIB
X11_xcb_sync_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_util_INCLUDE_PATH
X11_xcb_util_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_util_LIB
X11_xcb_util_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xf86dri_INCLUDE_PATH
X11_xcb_xf86dri_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xf86dri_LIB
X11_xcb_xf86dri_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xfixes_INCLUDE_PATH
X11_xcb_xfixes_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xfixes_LIB
X11_xcb_xfixes_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xinerama_INCLUDE_PATH
X11_xcb_xinerama_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xinerama_LIB
X11_xcb_xinerama_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xinput_INCLUDE_PATH
X11_xcb_xinput_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xinput_LIB
X11_xcb_xinput_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xkb_LIB
X11_xcb_xkb_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xrm_INCLUDE_PATH
X11_xcb_xrm_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xrm_LIB
X11_xcb_xrm_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xtest_INCLUDE_PATH
X11_xcb_xtest_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xtest_LIB
X11_xcb_xtest_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xv_INCLUDE_PATH
X11_xcb_xv_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xv_LIB
X11_xcb_xv_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xvmc_INCLUDE_PATH
X11_xcb_xvmc_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xvmc_LIB
X11_xcb_xvmc_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbcommon_INCLUDE_PATH
X11_xkbcommon_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbcommon_LIB
X11_xkbcommon_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbcommon_X11_INCLUDE_PATH
X11_xkbcommon_X11_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbcommon_X11_LIB
X11_xkbcommon_X11_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbfile_INCLUDE_PATH
X11_xkbfile_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbfile_LIB
X11_xkbfile_LIB-ADVANCED:INTERNAL=1
//Making sure VCPKG_MANIFEST_MODE doesn't change
Z_VCPKG_CHECK_MANIFEST_MODE:INTERNAL=OFF
//Vcpkg root directory
Z_VCPKG_ROOT_DIR:INTERNAL=/opt/vcpkg
//linker supports push/pop state
_CMAKE_LINKER_PUSHPOP_STATE_SUPPORTED:INTERNAL=TRUE
//CMAKE_INSTALL_PREFIX during last run
_GNUInstallDirs_LAST_CMAKE_INSTALL_PREFIX:INTERNAL=/opt/vcpkg/packages/glfw3_x64-linux/debug
```
</details>

**Additional context**

<details><summary>vcpkg.json</summary>

```
{
  "dependencies": [
    "glew",
    "glfw3",
    "opengl"
  ]
}

```
</details>
