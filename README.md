# Monty

`monty` is an interpreter for Monty ByteCodes files, which is a scripting language just like Python.

## About the Monty language
This is a language that contains specific instructions to manipulate data information (stacks or queues). Each instruction (*called opcode*) are called `opcodes` and are sent once per line in the file containing the `bytecodes`. This files have extension .m, this is not neccessary as it is just a naming convention.

Example (`monty.m`):
```bash
$ cat monty.m
# Push elements to the stack
push 1
push 2
push 3
# Printing all elements
pall
push 4
push 5
# Remove/pop last element
pop
# Print all elements again
pall
# Print the last element on the stack
4
```

## Technologies
* Interpreter was written with C language
* C files are compiled using `gcc 4.8.4`
* C files are written according to the C90 standard
* Tested on Ubuntu 14.04 LTS

## Usage
To compile all files:

```bash
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
$
```

The **synopsis** of the interpreter is the following:

```bash
$ ./monty [filename]
$
```

To run the interpreter:

```bash
$ ./monty file.m
1
2
3
1
2
3
4
$
```

## Features
### Opcodes
`monty` executes the following opcodes:

| Opcode | Description |
| -------- | ----------- |
| `push` | Pushes an element to the stack |
| `pall` | Prints all the values on the stack |
| `pint` | Prints the value at the top of the stack |
| `pop` | Removes the top element of the stack |

Comments, indicated with `#`, are not executed by the interpreter.

When a **nonextistent opcode** is passed, the interpreter prints an error message and stops:

```bash
$ cat errorfile.m
push 1
pall
pushe 2
$ ./monty errorfile.m
1
L3: unknown instruction pushe
```

### Return value
When there is no errors, `monty` returns `0`. Otherwise, returns `1`

## Authors
* Timothy Adeleke
* Omotayo Omotosho
