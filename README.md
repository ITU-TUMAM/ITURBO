# ITURBO

**Modern C++23 turbomachinery CFD solver**

ITURBO is an open-source, research-grade computational fluid dynamics library
targeting turbomachinery applications — compressors, turbines, and related
rotating-machinery flows. It is built from scratch in C++23 with a modular
architecture designed for both desktop pre/post-processing and large-scale
parallel HPC runs.

> **Status:** early development — the Core and Mesh modules are the foundation
> currently in place; solver, physics, and I/O modules are in progress.

---

## Features

- **C++23 throughout** — `std::format`, concepts, ranges, and structured
  bindings used where they reduce noise
- **Modular library design** — link only what you need (`ITURBO::Core`,
  `ITURBO::Mesh`, ...)
- **Parallel-ready** — optional MPI and OpenMP backends controlled at
  configure time; serial builds require no parallel runtime
- **Cross-platform** — Linux (GCC 13 / Clang 17), Windows (MSVC 2022),
  and cross-compiled Windows binaries from a Linux dev container
- **CMake presets** — one-command workflows for debug, release, CI, and
  cross-compilation via `CMakePresets.json`
- **LGPL-2.1** — library code is freely linkable from proprietary applications

---

## Module overview

| Module | Namespace | Status | Description |
|---|---|---|---|
| Core | `ITURBO::Core` | active | Types, error handling, exceptions, config, assertions |
| Mesh | `ITURBO::Mesh` | active | Node, Face, Cell, Mesh templates; tet/hex volume geometry |
| Geometry | `ITURBO::Geometry` | planned | Surface and volume geometry kernels |
| Physics | `ITURBO::Physics` | planned | Equation-of-state, thermodynamic relations |
| Numerics | `ITURBO::Numerics` | planned | Discretization schemes, gradient reconstruction |
| BC | `ITURBO::BC` | stub | Boundary condition framework |
| LinearAlgebra | `ITURBO::LinearAlgebra` | planned | Sparse linear algebra; PETSc back-end |
| Solver | `ITURBO::Solver` | planned | Steady/unsteady RANS and Euler solvers |
| Turbomachinery | `ITURBO::Turbomachinery` | planned | Stage interfaces, rotating-frame source terms |
| IO | `ITURBO::IO` | planned | CGNS and custom mesh I/O |
| Post | `ITURBO::Post` | planned | Post-processing utilities |
| Utils | `ITURBO::Utils` | planned | Logging, timers, string utilities |
| Parallel | `ITURBO::Parallel` | planned | MPI domain decomposition |

---

## Prerequisites

### Compiler

| Compiler | Minimum version | Notes |
|---|---|---|
| GCC | 13 | Primary Linux compiler |
| Clang | 17 | Alternative; also used for static analysis |
| MSVC | 19.34 (VS 2022 17.4) | Windows only |

All three require full C++23 `std::format` support.

### Build tools

- **CMake** ≥ 3.26
- **Ninja** (recommended; Makefiles also work)

### Optional dependencies

| Library | Feature flag | Notes |
|---|---|---|
| OpenMPI / MS-MPI | `ITURBO_ENABLE_MPI` | Parallel distributed runs |
| OpenMP | `ITURBO_ENABLE_OPENMP` | Shared-memory parallelism |
| PETSc ≥ 3.20 | `ITURBO_ENABLE_PETSC` | Sparse linear solver back-end |
| CGNS | `ITURBO_ENABLE_CGNS` | Mesh I/O (CFD General Notation System) |

[Catch2 v3](https://github.com/catchorg/Catch2) is fetched automatically by
CMake when tests are enabled — no manual installation needed.

---

## Quick start

### Dev container (recommended)

Open the repository in VS Code or Visual Studio and choose
**Reopen in Container**. Docker builds the image on first launch; afterwards
a fully configured environment is available with GCC 13, Clang 17, CMake,
Ninja, PETSc, and OpenMPI.

```bash
# configure + build + test in one command
cmake --workflow --preset dev
```

### Linux / WSL2 (manual)

```bash
git clone https://github.com/your-org/iturbo.git
cd iturbo

# configure
cmake --preset container-debug

# build
cmake --build --preset container-debug

# test
ctest --preset container-debug
```

### Windows (no PETSc)

```powershell
cmake --preset windows-debug
cmake --build --preset windows-debug
ctest --preset windows-debug
```

### Minimal build (no MPI, no OpenMP, no tests)

```bash
cmake -S . -B build \
    -DITURBO_ENABLE_MPI=OFF \
    -DITURBO_ENABLE_OPENMP=OFF \
    -DITURBO_ENABLE_TESTS=OFF
cmake --build build
```

---

## CMake options

| Option | Default | Description |
|---|---|---|
| `ITURBO_ENABLE_TESTS` | `ON` | Build Catch2 unit tests |
| `ITURBO_ENABLE_BENCHMARKS` | `OFF` | Build benchmarks |
| `ITURBO_ENABLE_APPS` | `ON` | Build command-line applications |
| `ITURBO_ENABLE_MPI` | `ON` | Enable MPI support |
| `ITURBO_ENABLE_OPENMP` | `ON` | Enable OpenMP support |
| `ITURBO_ENABLE_PETSC` | `OFF` | Enable PETSc linear solver back-end |
| `ITURBO_ENABLE_CGNS` | `OFF` | Enable CGNS mesh I/O |
| `ITURBO_ENABLE_WARNINGS` | `ON` | Enable compiler warnings |
| `ITURBO_ENABLE_WERROR` | `OFF` | Treat warnings as errors |
| `ITURBO_ENABLE_SANITIZERS` | `OFF` | Enable AddressSanitizer + UBSan (non-MSVC) |
| `ITURBO_ENABLE_LTO` | `OFF` | Enable link-time optimisation |
| `ITURBO_BUILD_SHARED_LIBS` | `OFF` | Build shared libraries instead of static |

---

## Repository layout

```
iturbo/
├── ITURBO/               # Public headers (include as "ITURBO/Core/Error.h")
│   ├── Core/             # Error, Types, Config, Enums, Assert, Exception
│   └── Mesh/             # Node, Face, Cell, Mesh, Volume, FaceGeometry
├── src/                  # Library implementation
│   ├── Core/             # Core library sources
│   ├── Mesh/             # Mesh library sources
│   └── BC/               # Boundary condition stub
├── test/                 # Catch2 tests
│   └── Mesh/
├── apps/                 # Command-line applications (planned)
├── docs/                 # Building and developer guides
├── scripts/              # Utility scripts
├── CMakeLists.txt        # Root build file
└── CMakePresets.json     # All configure/build/test/workflow presets
```

---

## Building and linking against ITURBO

After installing (or using CMake's build-tree export), link your targets with:

```cmake
find_package(ITURBO REQUIRED COMPONENTS Core Mesh)

target_link_libraries(my_app
    PRIVATE
        ITURBO::Core
        ITURBO::Mesh
)
```

Include paths are propagated automatically via the imported targets.

---

## Contributing

The project follows standard C++23 style with a few conventions:

- Types use `PascalCase`, functions and methods `PascalCase`, member variables
  `m_PascalCase`
- All public API symbols are annotated with the appropriate `ITURBO_*_API`
  export macro
- New modules go in `src/<Module>/` with public headers in `ITURBO/<Module>/`
  following the pattern established by Core and Mesh

Run clang-tidy before submitting:

```bash
cmake --preset container-clang-tidy
cmake --build --preset container-clang-tidy
```

---

## License

Copyright © 2026 Onur Tuncer, PhD — Istanbul Technical University

ITURBO is distributed under the
[GNU Lesser General Public License v2.1](LICENSE). You may link it into
proprietary applications under the terms of the LGPL.

---

## Author

**Prof. Dr. Onur Tuncer**  
Aerospace Engineering, Istanbul Technical University  
onur.tuncer@itu.edu.tr

<img src="assets/itu_logo.png" width="160" alt="Istanbul Technical University"/>
