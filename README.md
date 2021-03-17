# OakTree 🌳

A postfix notation expression evaluator, using a stack to build an abstract syntax tree.

This personal project has taught me a lot about data structures and pointers in C, and has given me an initial insight to the inner-working of compilers.

## Example input/output ⚙️

|Input|Output|
| ---: | :---: |
| `6` | `6`  |
| ` 1 1 2 ` | `2` |
| `1 2 + ` | `3` 
| `1 2 3 + *` | `5` |
| `4 2 5 * + 1 3 2 * + /` | `2` |


## How does it work? 🔎

After an expression is entered (currently through a file), the program reads it from left to right, and behaves according to the character that it reads.

- If the character is a **digit**...

  - The digit is added to the buffer.
 
- If the character is a **space**...

  - The contents of the buffer is used to create a new **number node**.
  - The node is pushed to the stack.
  - The buffer is cleared.

- If the character is an **operator**...

  - The stack is checked to verify there are enough nodes (For example, an addition operator requires two nodes, but a negation operator requires only 1)
  - The stack is popped.
  - A new **operator node** is made, with the nodes from the stack as children.

- If the character is an **EOF**...

  - If the buffer is not empty, the values are pushed to the stack.

Now that we have built an abstract syntax tree, we can **evaluate** it. 

This is done by starting at the root node and recursively querying the value of both the left and the right child, before performing the operation (if any). 

## Next steps 🌱

The next steps will be to continue to head towards developing a stack-based language, like Forth or PostScript. I also want to make OakTree turing complete.

Specific features I'm considering include:
- character support
- variables
- functions


