# Libasm (C functions recreated in ASM)

**Libasm** is an optional project in the 42 curriculum where you build a static library entirely in x86_64 assembly language. Many standard C library functions are re-implemented from scratch. All functions are written using NASM with Intel syntax.


## Implemented Functions

- **strlen** – Computes the length of a string.
- **strcpy** – Copies a string from source to destination.
- **strcmp** – Compares two strings.
- **write** – Writes data to a file descriptor.
- **read** – Reads data from a file descriptor.
- **strdup** – Duplicates a string.

![Screenshot from 2025-03-29 02-30-15](https://github.com/user-attachments/assets/c9b241f4-a681-449f-ad40-1382c5b167e1)

## Compilation and Execution

Simply run `make` in the project root to build the library and compile the test program. The Makefile will:

1. Build the library (`libasm.a`) using the inner Makefile in the `lib/` directory.
2. Compile `main.c` and link it with `libasm.a` to produce the executable, `test_program`.

### For macOS

On macOS, make sure to use the appropriate architecture flags, as noted in the comments of both Makefiles. Please note that building the library with x86_64 Intel syntax assembly on macOS can be less stable due to platform-specific toolchain limitations. If you encounter issues, consider testing in a Linux environment.
