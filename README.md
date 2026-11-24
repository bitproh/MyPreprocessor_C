# MyPreprocessor_C


A preprocessor tool named mypreprocessor that
processes a C source file by performing comment removal, file
inclusion, and macro substitution.
The preprocessor should generate an extended source file with a
.i extension.



## Project Structure

- `main.c` — Entry point; opens input/temporary/output streams and orchestrates the preprocessing stages.

- `header.h` — Function prototypes and common headers.
             
- `comment_removal.c` — Removes single-line (`//`) and multi-line (`/* ... */`) comments.


- `file_inclusion.c` — Expands `#include` directives by reading included files.


- `macro_handler.c` — Parses `#define` macros and substitutes macro names in the source code.


- `Makefile` — Build configuration to compile the `mypreprocessor` executable.

## How to Build

- for compiling the program run the command `make` on the terminal. Make sure the system has makefile as predownloaded.

- For executing the program, run the command `./mypreprocessor <input_file.c>` on the terminal

- the output file with .i extension is saved to the present working directory as `output.i`

 