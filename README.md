# 42-minishell

The objective of this project is to create a simple shell, inspired by bash.<br>
It was the first group project and done in a team of 2.<br>
"_As beautiful as a shell_"

## How to use
<b>Requirements</b>
- GCC / CLANG Compiler
- GNU Make
- GNU Readline library

```
# Clone the repository
git clone https://github.com/nichideropa/42-minishell.git

cd 42-minishell && make

# run the shell
./minishell
```

## Prerequisites
The project allowed us to use GNU's readline library to handle terminal interactions (reading input and history). Otherwise we were only allowd to use a few low-level functions, as well as a few POSIX system calls.

## Features
### Basic
- History of previous commands
- Launch executables using a relative or absolute path, based on `PATH` variable
- Basic signal handling
- Single and double quotes (`'` and `"`) to prevent interpretation of meta-characters
- Expansion of environment variables (`$` followed by a sequence of characters)<br> for eample `$?` expands to the last exit status
- Pipes `|` to connect commands together

### Redirection
- `< file` redirect input
- `<< delimiter` here document (multiline input in the terminal)
- `> file` redirect output
- `>> file` append redirected output

### Builtins
- `echo` with option `-n`
- `cd` with relative or absolute path 
- `pwd` without options
- `export` without options
- `unset` without options
- `env` without options
- `exit [status]` without options 

## Testing
A beautiful tester developed by [tjensen42](https://github.com/tjensen42) and [hepple42](https://github.com/hepple42) is included in the project. It provides the options to check the implementation with valgrind for memory leaks.
