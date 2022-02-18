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
```

### Building the Project

```bash
python scripts/build.py
# options
python scripts/build.py --help
```
