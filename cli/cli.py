import os
import subprocess

import click
import shutil

def is_cxx_file(path):
    extension = path.split('.')[-1]
    return extension == 'hxx' or extension == 'cxx'

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
@click.pass_context
def cli(
    ctx,
    verbose,
    ci,
) -> None:
    ctx.ensure_object(dict)
    ctx.obj['VERBOSE'] = verbose
    ctx.obj['CI'] = ci
    ctx.obj['PROJECT_ROOT'] = os.path.abspath(os.path.join(os.path.abspath(__file__), '..', '..'))

    if ctx.obj['VERBOSE']:
        print(f'context: {ctx.obj}')


@cli.command()
@click.option(
    '--clean',
    is_flag=True,
    help='Deletes the previous build.',
)
@click.pass_context
def build(
    ctx,
    clean,
):
    ctx.obj['CLEAN'] = clean

    ctx.obj['BUILD_DIR'] = os.path.abspath(os.path.join(ctx.obj['PROJECT_ROOT'], 'build'))
    ctx.obj['BIN_DIR'] = os.path.abspath(os.path.join(ctx.obj['PROJECT_ROOT'], 'bin'))
    ctx.obj['PYTORCH_DIR'] = os.path.abspath(os.path.join(ctx.obj['PROJECT_ROOT'], 'vendor', 'pytorch'))
    ctx.obj['CORE_COUNT'] = os.cpu_count()

    if ctx.obj['VERBOSE']:
        print(f'context: {ctx.obj}')

    if ctx.obj['CLEAN']:
        if ctx.obj['VERBOSE']:
            print('Cleaning ...')
        if os.path.exists(ctx.obj['BUILD_DIR']):
            shutil.rmtree(ctx.obj['BUILD_DIR'])
        if os.path.exists(ctx.obj['BIN_DIR']):
            shutil.rmtree(ctx.obj['BIN_DIR'])

    os.makedirs(ctx.obj['BUILD_DIR'], exist_ok=True)
    os.chdir(ctx.obj['BUILD_DIR'])

    pytorch_dir = ctx.obj['PYTORCH_DIR']
    for out in execute(['cmake', f'-DCMAKE_PREFIX_PATH={pytorch_dir}', '..']):
        print(out, end="")

    core_count = ctx.obj['CORE_COUNT']
    for out in execute(['make', f'-j{core_count}']):
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
        for root, subdirs, files in os.walk(os.path.join(ctx.obj['PROJECT_ROOT'], dir)):
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
    ci
):
    test_dir = os.path.join(ctx.obj['PROJECT_ROOT'], 'bin', 'test')

    tests = []
    for _, _, files in os.walk(test_dir):
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

    
if __name__ == '__main__':
    cli(obj={})
