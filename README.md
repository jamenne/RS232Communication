# Libary to talk via RS232
 Author: Janine Müller

## Description
This Software allows to talk to devices via RS232. 
It opens a RS232 port and checks all comports.

The repository contains the source code as well as CMakeLists.

## How to compile it

1.) Compile source code:

```bash
mkdir build
cd build
cmake ..
make
```

## How to use it

1.) e.g. in `CMakeLists.txt` of `LEDClass`:

```bash
add_library(LED ../LEDClass/LED.cpp ../RS232com/RS232communication.cpp)
```