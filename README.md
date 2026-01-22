*This project has been created as part of the 42 curriculum by iel-fadi.*

# Get Next Line

## Description

**Get Next Line** is a project at 42 that challenges students to create a function capable of reading a text file (or any file descriptor) one line at a time. The primary goal is to learn about **static variables** in C and gain a deeper understanding of memory management (allocations and leaks) and file descriptor manipulation.

This project implements a function called `get_next_line` that returns a line read from a file descriptor, handling repeated calls efficiently until the end of the file is reached.

## Instructions

Relevant information about compilation and execution:

### Compilation
To compile the project, you must compile the source files along with your main file. You can define the buffer size at compilation time using the `-D` flag.

**Standard Version:**
> `cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl`

**Bonus Version:**
> `cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus`

### Execution
Once compiled, you can run the executable normally:
> `./gnl`

## Resources

Classic references and AI usage description:

### References
* **man read (2)**: Documentation for the system call used to read file descriptors.
* **man malloc (3) / free (3)**: Reference for dynamic memory allocation.
* **C Static Variables**: Documentation regarding the scope, lifetime, and storage duration of static variables in C.

### AI Usage
As permitted by the subject, AI was used as a learning assistant for specific tasks:
* **System Calls**: Used to understand the detailed behavior of the `read()` and `open()` functions, specifically regarding file descriptors and return values.
* **C Concepts**: Used to understand the concept of static variables, their persistence in memory, and how they differ from standard local variables.

## Algorithm Explanation & Justification

A detailed explanation and justification of the algorithm selected for this project:

### The Approach
The core logic relies on a **static variable** to persist data between function calls.
1.  **Reading:** The function reads the file in chunks defined by `BUFFER_SIZE`. It appends these chunks to a static "backup" string using string manipulation functions. It repeats this process until a newline character (`\n`) is found or the End Of File (EOF) is reached.
2.  **Extraction:** Once a newline is detected, the function identifies the exact position of the break. It extracts the substring from the start up to the newline. This substring is the return value.
3.  **Cleaning Up:** The remaining part of the buffer (characters after the newline) is saved back into the static variable. This ensures the next call starts exactly where the previous one left off.

### Justification of Choices
* **Static Variable:** Selected because standard local variables lose their data when the function returns. The static variable is the only way to "remember" the file content that was read but not yet returned to the user (the "leftovers").
* **Single Loop Logic:** A single reading loop was chosen to minimize the number of `read()` system calls, optimizing performance by only reading what is strictly necessary to find the next newline.
* **Dynamic Buffer Management:** The algorithm manages memory dynamically to handle files of any size without overflowing the stack, adhering to the project's strict memory management rules.