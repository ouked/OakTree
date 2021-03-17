# OakTree 🌳

A postfix notation expression evaluator, using a stack to build an abstract syntax tree.

This personal project has taught me a lot about data structures and pointers in C, and has given me an initial insight to the inner workings of compilers.

## Example input/output ⚙️

|                    Input| Output| Comments                                                                        |
| ----------------------: | :---: | ------------------------------------------------------------------------------- |
| `6`                     |  `6`  | There are no operators, so the last number is returned.                         | 
| ` 1 1 2 `               |  `2`  | The same as above: unused values are ignored.                                   |
| `1 2 + `                |  `3`  | `+` operator adds the two top values in the stack.                              |
| `1 2 3 + *`             |  `5`  | `2 3 +` gets evaluated to `5`, which then get's multiplied by the `1` (`1 5 *`) |
| `4 2 5 * + 1 3 2 * + /` |  `2`  | _See below_                                                                     |

**The final example is evaluated as follows:**

|   Evaluation   | Resulting expression    |
|   :--------:   | ----------------------- |
|                | `4 2 5 * + 1 3 2 * + /` |
|`2 5 *` → `10`  | `4 10 + 1 3 2 * + /`    |
| `4 10 +` → `14`| `14 1 3 2 * + /`        |
| `3 2 *` → `6`  |`14 1 6 + /`             |
| `1 6 +` → `7`  |`14 7 /`                 |
| `14 7 /` → `2` |`2`                      |

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

## Testing 🧪
To ensure new features/bug fixes don't break any existing functionality, I've written my own simple **unit testing framework**. If the tests are designed to be representative of all the functionality of the program, all of them passing means that nothing has been broken (probably).
```
Running tests...

Test 01 passed.
Test 02 passed.
Test 03 passed.
Test 04 passed.
Test 05 passed.
Test 06 passed.
Test 07 passed.
Test 08 passed.


Success! All 8 tests passed.
```

By writing these tests **before** new features were developed, this was an example of test driven development: I knew a feature was implemented properly (and hadn't broken existing features) when all tests passed.

I also learnt a lot from writing the test framework itself, including how testing frameworks I've used before work.

## Next steps 📈

The next steps will be to continue to head towards developing a stack-based language, like Forth or PostScript. I also want to make OakTree turing complete.

Specific features I'm considering include:
- character support
- variables
- functions


