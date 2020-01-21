# Get_Next_Line
## Summary
The aim of this project is to make a function that returns a line ending with a newline, read from a file descriptor.
## Parameters
1. File descriptor for reading
2. The value of what has been read
## Return values
* 1 : A line has been read
* 0 : EOF has been reached
* -1 : An error happened
## Compilation
```
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=## get_next_line.c get_next_line_utils.c main.c
```
## Execution
```
./a.out [file_path]
```
* If no argument: standard input
* If 1 argument: use single fd
* If 2 arguments: use 2 fd
* Possibility to use more arguments for multi fd tests
