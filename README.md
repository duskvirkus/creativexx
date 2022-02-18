# creativexx

[![Build Status](https://travis-ci.org/duskvirkus/creativexx.svg?branch=main)](https://travis-ci.org/duskvirkus/creativexx)

## Setup

```bash
git clone --recursive https://github.com/duskvirkus/creativexx.git
conda create -n creativexx python=3.8
conda activate creativexx
cd vendor/pytorch
pip install -r requirements.txt
# this step will take awhile it's compiling pytorch
python setup.py develop
```

```bash
./scripts/linux/hooks.sh
```

```bash
./scripts/linux/ubuntu-install.sh
```

## cli

Use the cli to build project, run tests, and assist in development.

```
python cli/cli.py --help
```
