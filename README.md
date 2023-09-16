# Hangman ![CI](https://github.com/sneddonlewis/hangman/actions/workflows/ci.yml/badge.svg?branch=main)

CLI hangman game

## Structure
``` text
.
├── CMakeLists.txt
├── app
│   └── main.cpp
├── include
|   |── exampleConfig.h.in
|   |── example.h
|   |── engine.h
|   |── game.h
|   |── word.h
│   └── wordFactory.h
├── src
|   |── engine.cpp
|   |── example.cpp
|   |── game.cpp
|   |── word.cpp
│   └── wordFactory.cpp
└── tests
    ├── dummy.cpp
    └── main.cpp
```

## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Example:

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release]
make
./main
make test      # Makes and runs the tests.
make coverage  # Generate a coverage report.
make doc       # Generate html documentation.
```

