# comment_remover
A C and CPP **FSM** comment remover, that can be used with any file using this specific comment format

It supports, **multi-line C style comments**, **single line CPP style comments** aswell as **multi-line CPP style comments**.

Examples can be found under **src/test.c**.

## Build

Run `make` within the project directory to build the project.

## Usage

Currently input is read from `stdin` and output is written to `stdout`.
This can be easily changed if needed but for what I originally created it for, this was sufficient.

Run `./comment_remover < (input_file) > (output_file)` to remove comments from the input file and write the output to the output file.
