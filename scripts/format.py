import click
import os
import subprocess

def get_project_root():
    file_path = os.path.abspath(__file__)
    project_root = os.path.abspath(os.path.join(file_path, '..', '..'))
    return project_root

def execute(cmd):
    popen = subprocess.Popen(cmd, stdout=subprocess.PIPE, universal_newlines=True)
    for stdout_line in iter(popen.stdout.readline, ""):
        yield stdout_line 
    popen.stdout.close()
    return_code = popen.wait()
    if return_code:
        # raise subprocess.CalledProcessError(return_code, cmd)
        print(f'command: {cmd} returned code: {return_code}')

@click.command()
@click.option(
    '--files-only',
    is_flag=True,
    help='Cleans the previous creativexx build. See --deep-clean to clean and rebuild dependencies.',
)
@click.option(
    '--dry-run',
    is_flag=True,
    help='Adds dry run argument to clang format.',
)
@click.option(
    '-v',
    '--verbose',
    is_flag=True,
    help='Prints more information.',
)
def format(
    files_only,
    dry_run,
    verbose
):

    print(f'verbose: {verbose}')

    if verbose:
        print('ARGUMENTS')
        print(f'files_only: {files_only}')
        print(f'dry_run: {dry_run}')

    project_root = get_project_root()

    dirs_to_format = [
        'src',
        'test',
        'include',
        'examples',
    ]
    
    files_to_format = []
    for dir in dirs_to_format:
        for root, subdirs, files in os.walk(os.path.join(project_root, dir)):
            for f in files:
                files_to_format.append(os.path.join(root, f))

    format_command = ['clang-format', '-style=Chromium', '--Werror']
    if dry_run:
        format_command.append('--dry-run')
    format_command.extend(files_to_format)

    if verbose:
        print('SCRIPT GENERATED VARIABLES')
        print(f'project_root: {project_root}')
        print(f'dirs_to_format: {dirs_to_format}')
        print(f'files_to_format: {files_to_format}')
        print(f'format_command: {format_command}')

    if not files_only:
        os.chdir(project_root)

        for out in execute(format_command):
            print(out, end="")
    

if __name__ == '__main__':
    format()