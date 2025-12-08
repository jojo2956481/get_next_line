This project has been created as part of the 42 curriculum by lebeyssa

## 📄 get_next_line


**get_next_line** is a project from 42 School  
whose objective is to implement a function capable of reading a file  
line by line, without losing any characters,  
while efficiently managing a buffer of variable size


## Implement the following function:
```
char *get_next_line(int fd);
```
## This function must:

return the next line read from the file descriptor fd,

work properly across multiple successive calls,

correctly handle the end of file (EOF),

adapt to any value of BUFFER_SIZE.

## 📁 Project Structure

```
.
├── get_next_line.h        # Prototypes + includes
├── get_next_line_utils.c  # Utility functions
└── get_next_line.c        # Main function
```
## 🔧 Compilation

To compile your project with a custom buffer size:
```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
    get_next_line.c get_next_line_utils.c main.c -o gnl
```
You can change the buffer size:

```
-D BUFFER_SIZE=1
-D BUFFER_SIZE=1000
```
## 📝 Example of use

```
int     fd = open("test.txt", O_RDONLY);
char    *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

## 🧪 Testing the program

Create a test file:
```
echo -e "Hello\nWorld\n42!" > test.txt
```
Compile and run:
```
./gnl test.txt
```
Test with Valgrind:
```
valgrind --leak-check=full ./gnl test.txt
```
## 📜 Resources

The project was based on the topic covered in the 42 curriculum. 
For pedagogical purposes, 
the use of AI was limited to creating this Readme.





