# get_next_line

## Overview
get_next_line is a function that reads a single line from a file descriptor each time it's called. This project demonstrates file I/O operations, memory management, and efficient string handling in C.

## Features
- **Line-by-Line Reading**: Reads one line at a time from file descriptors
- **Memory Efficient**: Uses minimal memory allocation and proper cleanup
- **Multiple File Support**: Can handle multiple file descriptors simultaneously
- **Buffer Management**: Efficient buffer handling for optimal performance
- **Error Handling**: Robust error handling for various edge cases

## Function Signature
```c
char *get_next_line(int fd);
```

## Parameters
- `fd`: File descriptor to read from

## Return Value
- Returns the line that was read (including the terminating `\n` character)
- Returns `NULL` if there's an error or if the end of file has been reached
- The returned string should be freed by the caller

## Project Structure
```
get_next_line/
├── get_next_line.h          # Header file with function declarations
├── get_next_line.c          # Main function implementation
├── get_next_line_utils.c    # Utility functions
├── Makefile                 # Build configuration
└── .git/                   # Git repository
```

## How It Works
1. **Buffer Management**: Uses a static buffer to store leftover data between calls
2. **Line Detection**: Searches for newline characters (`\n`) in the buffer
3. **Memory Allocation**: Dynamically allocates memory for each line
4. **File Reading**: Reads from file descriptor in chunks for efficiency
5. **Cleanup**: Properly manages memory and handles file errors

## Usage Example
```c
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    
    close(fd);
    return (0);
}
```



## Requirements
- GCC compiler
- Make utility
- Standard C libraries
- Libft library (dependency)

## Dependencies
This project depends on the Libft library for basic string and memory functions.

## Notes
- Follows 42 coding style (norminette)
- Handles multiple file descriptors correctly
- Memory-safe implementation with proper cleanup
- Efficient buffer management
- Compatible with standard file operations

## Author
shmohamm - 42 Abu Dhabi
