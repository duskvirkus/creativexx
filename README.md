# creativexx

[![Build Status](https://travis-ci.org/duskvirkus/creativexx.svg?branch=main)](https://travis-ci.org/duskvirkus/creativexx)

## Setup

```bash
git clone --recursive https://github.com/duskvirkus/creativexx.git
conda create -n creativexx python=3.8
conda activate creativexx
cd vendor/pytorch
pip install requirements.txt
# this step will take awhile it's compiling pytorch
python setup.py develop
```

#### Setup Git Hooks

```bash
./scripts/linux/hooks.sh
```

##### Ubuntu

```bash
./scripts/linux/ubuntu-install.sh

### Building the Project

You could use an editor that supports CMake like CLion or vscode but if not here's how to do it from the terminal.

```bash
# in root directory of project
mkdir cmake-build-debug
cd cmake-build-debug
cmake ..
make -j4
cd ..
```

The library is in /lib and binaries are in /bin.
