import click
import os
import subprocess

import shutil

def get_build_dir():
    file_path = os.path.abspath(__file__)
    build_dir = os.path.abspath(os.path.join(file_path, '..', '..', '..', 'cmake_build'))
    return build_dir

def get_pytorch_dir():
    file_path = os.path.abspath(__file__)
    build_dir = os.path.abspath(os.path.join(file_path, '..', '..', '..', 'vendor', 'pytorch'))
    return build_dir

def execute(cmd):
    popen = subprocess.Popen(cmd, stdout=subprocess.PIPE, universal_newlines=True)
    for stdout_line in iter(popen.stdout.readline, ""):
        yield stdout_line 
    popen.stdout.close()
    return_code = popen.wait()
    if return_code:
        raise subprocess.CalledProcessError(return_code, cmd)

@click.command()
@click.option(
    '--clean',
    is_flag=True,
    help='Cleans the previous creativexx build. See --deep-clean to clean and rebuild dependencies.',
)
def build(
    clean
):

    print('ARGUMENTS')
    print(f'clean: {clean}')

    build_dir = get_build_dir()
    pytorch_dir = get_pytorch_dir()
    core_count = os.cpu_count()
    
    print('SCRIPT GENERATED VARIABLES')
    print(f'build_dir: {build_dir}')
    print(f'pytorch_dir: {pytorch_dir}')
    print(f'core_count: {core_count}')

    if clean:
        assert(build_dir != '/')
        shutil.rmtree(build_dir)

    os.makedirs(build_dir, exist_ok=True)
    os.chdir(build_dir)

    for out in execute(['cmake', f'-DCMAKE_PREFIX_PATH={pytorch_dir}', '..']):
        print(out, end="")

    for out in execute(['make', f'-j{core_count}']):
        print(out, end="")
    

if __name__ == '__main__':
    build()