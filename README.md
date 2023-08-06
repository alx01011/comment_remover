# comment_remover
A C and CPP style comment remover, that can be used with any file using this specific comment format

## Build

Run `make` within the project directory to build the project.

## Usage

Currently input is read from `stdin` and output is written to `stdout`.
This can be easily changed, if needed but for what I needed it for, this was enough.

Run `./comment_remover < <input_file> > <output_file>` to remove comments from the input file and write the output to the output file.