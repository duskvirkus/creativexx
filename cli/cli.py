import os
import subprocess

import click
import shutil

def is_cxx_file(path):
    extension = path.split('.')[-1]
    return extension == 'hxx' or extension == 'cxx'

def get_default_jobs():
    return int((os.cpu_count() / 2) - 1)

def execute(cmd):
    popen = subprocess.Popen(cmd, stdout=subprocess.PIPE, universal_newlines=True)
    for stdout_line in iter(popen.stdout.readline, ""):
        yield stdout_line 
    popen.stdout.close()
    return_code = popen.wait()
    if return_code:
        raise subprocess.CalledProcessError(return_code, cmd)

@click.group()
@click.option('--verbose', is_flag=True)
@click.option(
    '--ci',
    is_flag=True,
    help='Run as continuous integration test.',
)
@click.option(
    '--debug',
    'build_type',
    flag_value='DEBUG',
)
@click.option(
    '--release',
    'build_type',
    flag_value='RELEASE',
)
@click.pass_context
def cli(
    ctx,
    verbose,
    ci,
    build_type,
) -> None:
    ctx.ensure_object(dict)
    ctx.obj['VERBOSE'] = verbose
    ctx.obj['CI'] = ci
    ctx.obj['PROJECT_ROOT'] = os.path.abspath(os.path.join(os.path.abspath(__file__), '..', '..'))
    if build_type is not None:
        ctx.obj['BUILD_TYPE'] = build_type
    else:
        print('No build_type specified setting --debug as default.')
        ctx.obj['BUILD_TYPE'] = 'DEBUG'

    if ctx.obj['VERBOSE']:
        print(f'context: {ctx.obj}')


@cli.command()
@click.option(
    '--clean',
    is_flag=True,
    help='Deletes the previous build.',
)
@click.option(
    '--jobs',
    type=int,
    help='Number of jobs (essentially threads) to use for make.',
    default=get_default_jobs(),
    show_default=True,
)
@click.pass_context
def build(
    ctx,
    clean,
    jobs,
):
    build_dir = os.path.abspath(os.path.join(ctx.obj['PROJECT_ROOT'], 'build', ctx.obj['BUILD_TYPE'].lower()))
    bin_dir = os.path.abspath(os.path.join(ctx.obj['PROJECT_ROOT'], 'bin', ctx.obj['BUILD_TYPE'].lower()))

    if clean:
        if os.path.exists(build_dir):
            if ctx.obj['VERBOSE']:
                print(f'Cleaning {build_dir}')
            shutil.rmtree(build_dir)
        if os.path.exists(bin_dir):
            if ctx.obj['VERBOSE']:
                print(f'Cleaning {bin_dir}')
            shutil.rmtree(bin_dir)

    os.makedirs(build_dir, exist_ok=True)
    os.chdir(build_dir)

    pytorch_dir = os.path.abspath(os.path.join(ctx.obj['PROJECT_ROOT'], 'vendor', 'pytorch'))
    opencv_dir = os.path.abspath(os.path.join(ctx.obj['PROJECT_ROOT'], 'vendor', 'opencv', 'build'))

    build_type = ctx.obj['BUILD_TYPE']
    for out in execute(['cmake', f'-DCMAKE_PREFIX_PATH={pytorch_dir};{opencv_dir}', f'-DCMAKE_BUILD_TYPE={build_type}', '../..']): # 
        print(out, end="")

    for out in execute(['make', f'-j{jobs}']):
        print(out, end="")

    assets_src = os.path.abspath(os.path.join(ctx.obj['PROJECT_ROOT'], 'assets'))
    assets_dest = os.path.abspath(os.path.join(bin_dir, 'test'));
    for out in execute(['cp', '-r', f'{assets_src}', f'{assets_dest}']):
        print(out, end="")


@cli.command()
@click.option(
    '--files-only',
    is_flag=True,
    help='Just prints the files that will be formatted.',
)
@click.option(
    '--dry-run',
    is_flag=True,
    help='Adds dry run argument to clang format.',
)
@click.pass_context
def format(
    ctx,
    files_only,
    dry_run,
):

    if ctx.obj['VERBOSE']:
        print('ARGUMENTS')
        print(f'files_only: {files_only}')
        print(f'dry_run: {dry_run}')

    dirs_to_format = [
        'src',
        'test',
        'include',
        'examples',
    ]
    
    files_to_format = []
    for dir in dirs_to_format:
        for root, _, files in os.walk(os.path.join(ctx.obj['PROJECT_ROOT'], dir)):
            for f in files:
                files_to_format.append(os.path.join(root, f))

    files_to_format = list(filter(lambda path: is_cxx_file(path), files_to_format))

    format_command = ['clang-format', '-style=Chromium', '--Werror']
    if dry_run or ctx.obj['CI']:
        format_command.append('--dry-run')
    else:
        format_command.append('-i') # inplace
    format_command.extend(files_to_format)

    if ctx.obj['VERBOSE']:
        print('SCRIPT GENERATED VARIABLES')
        print(f'dirs_to_format: {dirs_to_format}')
        print(f'files_to_format: {files_to_format}')
        print(f'format_command: {format_command}')

    if not files_only:
        os.chdir(ctx.obj['PROJECT_ROOT'])

        for out in execute(format_command):
            print(out, end="")

@cli.command()
@click.pass_context
def all_tests(
    ctx,
):
    test_dir = os.path.join(ctx.obj['PROJECT_ROOT'], 'bin', ctx.obj['BUILD_TYPE'].lower(), 'test')

    tests = []
    for root, subdirs, files in os.walk(test_dir):
        if root.split('/')[-1] != 'assets':
            tests.extend(files)

    if ctx.obj['CI']:
        incompatible = ['LinuxWindow.spec']
        if ctx.obj['VERBOSE']:
            print(f'Running in ci mode removing tests because they require a desktop to run. {incompatible}')

        tests = filter(lambda t: incompatible.count(t) <= 0, tests)

    for test in tests:
        test_path = os.path.join(test_dir, test)
        if ctx.obj['VERBOSE']:
            print(f'Running {test} from {test_path}')
        for out in execute(test_path):
            print(out, end="")

@cli.command()
@click.option(
    '--clean',
    is_flag=True,
    help='Deletes the previous build.',
)
@click.option(
    '--jobs',
    type=int,
    help='Number of jobs (essentially threads) to use for make.',
    default=get_default_jobs(),
    show_default=True,
)
@click.pass_context
def opencv_build(
    ctx,
    clean,
    jobs,
):
    opencv_build_dir = os.path.join(ctx.obj['PROJECT_ROOT'], 'vendor', 'opencv', 'build')

    if clean:
        if ctx.obj['VERBOSE']:
            print('Cleaning ...')
        if os.path.exists(opencv_build_dir):
            shutil.rmtree(opencv_build_dir)

    os.makedirs(opencv_build_dir, exist_ok=True)
    os.chdir(opencv_build_dir)

    for out in execute(['cmake', '..']):
        print(out, end="")

    for out in execute(['make', f'-j{jobs}']):
        print(out, end="")
    
if __name__ == '__main__':
    cli(obj={})
