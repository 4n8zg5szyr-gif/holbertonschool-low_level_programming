
# Memory Analysis - Stack and Heap

## 1. Stack Example

### What does this program do?

The first program shows how the stack works when a function calls itself.

It uses two functions:
- `walk_stack()`
- `dump_frame()`

The function `walk_stack()` calls itself several times. Each time it is called, a new stack frame is created.

### What I observed when running the program

I ran the program with `./stack_example`.

The output showed four different levels:

| Depth | local_int | marker |
|---|---:|---:|
| 0 | 100 | 0 |
| 1 | 101 | 10 |
| 2 | 102 | 20 |
| 3 | 103 | 30 |

At each level, the program has its own local variables.

For example, the variable `marker` is not shared between all the calls. Each call has its own value.

### Understanding the pointers

Inside `dump_frame()`, there is this instruction:

`int *p_local = &local_int;`

It means that `p_local` stores the address of `local_int`.

When I looked at the output, I noticed that `&local_int` and `p_local` had exactly the same address.

This confirms that the pointer refers to the local variable.

The variable `local_int`, the array `local_buf` and the pointer `p_local` are local variables. They exist only while `dump_frame()` is running.

When the function finishes, these local variables no longer exist.

### How the recursion finishes

The program starts at depth 0 and goes down to depth 3.

When it reaches depth 3, the condition `depth < max_depth` is false.

The program then returns through the previous calls:

- First depth 3
- Then depth 2
- Then depth 1
- Finally depth 0

This explains why the output shows the exit messages in reverse order.

### My conclusion

This example helped me understand that each function call has its own local variables.

Even when a function calls itself, the variables from the previous call are still there until that call finishes.

There is no `malloc()` in this program, so it does not allocate memory on the heap.

---

## 2. Aliasing Example

### What does this program do?

The second program shows how two pointers can refer to the same memory location.

It also demonstrates an error called use-after-free.

### Step 1: Allocating memory

The function `make_numbers()` uses `malloc()` to reserve memory for five integers.

The array contains these values:

| Position | Value |
|---|---:|
| arr[0] | 0 |
| arr[1] | 11 |
| arr[2] | 22 |
| arr[3] | 33 |
| arr[4] | 44 |

This memory is allocated on the heap.

The function returns its address to `main()`.

Even if the local variable `arr` disappears when `make_numbers()` finishes, the allocated memory stays available.

### Step 2: Two pointers, one allocation

In `main()`, the program does this:

`a = make_numbers(n);`

Then:

`b = a;`

This means that `a` and `b` contain the same address.

There are two pointer variables, but only one allocated array.

Before calling `free()`, both pointers can access the same values.

For example:

- `a[2]` is 22.
- `b[2]` is also 22.

This is called pointer aliasing.

### Step 3: Freeing the memory

The program executes:

`free(a);`

This releases the allocated memory.

An important point is that `free(a)` does not automatically set `b` to NULL.

However, the memory itself has been released. Both pointers must no longer be used to access that allocation.

They are now dangling pointers.

### Step 4: The memory error

After `free(a)`, the program tries to execute:

`b[2]`

It also tries to write:

`b[3] = 1234;`

Both operations are invalid because the memory has already been freed.

This is called a use-after-free error.

When I ran the program, it displayed a negative number for `b[2]`.

This number is not predictable. The program is accessing memory that it is no longer allowed to use.

It could display a different value or even crash.

### My conclusion

This example helped me understand that freeing memory through one pointer also affects every other pointer referring to the same allocation.

Having another pointer to the same address does not protect the memory from being freed.

A good practice is to avoid using any pointer after the memory it refers to has been released.

---

## 3. AI Analysis and Correction

I used AI to help me understand the memory behavior of these programs.

One important point I checked was the relationship between pointers `a` and `b`.

An explanation could incorrectly suggest that only `a` becomes invalid after `free(a)` and that `b` can still access the array.

This is incorrect.

Both pointers refer to the same allocated memory. When that memory is released, neither pointer can safely access it anymore.

I compared this explanation with the source code and the program output.

This helped me understand the difference between a pointer variable and the memory allocation it refers to.

---

## 4. Final Summary

After studying these two programs, I understand the following points better:

- The stack stores local variables and function calls.
- Recursive calls create separate stack frames.
- Local variables stop existing when their function returns.
- `malloc()` allocates memory on the heap.
- `free()` releases an allocation.
- Two pointers can refer to the same memory.
- Accessing memory after `free()` causes undefined behavior.

The most important thing I learned is that a pointer does not own or preserve memory just because it contains an address.


## 3. Valgrind Test Results

I also tested the aliasing program with Valgrind to check if my explanation was correct.

I used this command:

`valgrind --leak-check=full --track-origins=yes ./aliasing_example`

Valgrind reported 3 memory errors.

### Errors found

- Line 42: Invalid read when accessing `b[2]`.
- Line 44: Invalid write when trying to change `b[3]`.
- Line 45: Invalid read when displaying `b[3]`.

All these errors happen after `free(a)`.

Valgrind also showed that the memory block was originally allocated by `malloc()` in `make_numbers()` and released by `free()` in `main()`.

### Memory leaks

Valgrind reported:

- 2 allocations.
- 2 frees.
- 0 bytes still allocated at exit.
- No memory leaks.

This is important because a program can have no memory leaks and still contain serious memory errors.

### What I learned from this test

Before running Valgrind, I understood that using `b` after `free(a)` was incorrect.

Valgrind confirmed this by reporting invalid reads and an invalid write.

I also noticed that the program still displayed the old value 22. This does not mean the memory was still valid. It only means that the old data was still visible when the program accessed the released memory.

The test helped me understand that memory leaks and use-after-free are two different problems.


## 3. Heap Example

### What does this program do?

This program shows how dynamic memory allocation works with `malloc()` and `free()`.

It creates two persons: Alice and Bob.

Each person has a name and an age. The structure and the name are allocated separately in memory.

### Step 1: Creating Alice and Bob

The function `person_new()` uses `malloc()` two times for each person.

The first allocation reserves memory for the `Person` structure.

The second allocation reserves memory for the person's name.

For example, Alice has:

- One memory block for her Person structure.
- One memory block for the string "Alice".
- An age value of 30.

Bob has the same memory organization, with his own name and age.

### Step 2: Understanding the memory

In `main()`, the variables `alice` and `bob` are local pointers.

They are stored in the stack, but they point to structures allocated on the heap.

The `name` fields contain pointers to other heap allocations.

This means that each person uses two separate heap allocations.

### Step 3: Freeing Bob

The program executes:

`free(bob->name);`

Then:

`free(bob);`

This is correct because the name is released first, followed by the structure.

Bob's two allocations are properly released.

### Step 4: The problem with Alice

For Alice, the program calls:

`person_free_partial(alice);`

Inside this function, there is only:

`free(p);`

The structure is released, but the memory allocated for `alice->name` is not released.

After the structure is freed, the program also loses the pointer that allowed it to access Alice's name allocation.

This causes a memory leak.

### Step 5: Valgrind results

I ran the program using:

`valgrind --leak-check=full --show-leak-kinds=all ./heap_example`

Valgrind reported:

- 5 allocations.
- 4 frees.
- 6 bytes still allocated.
- 1 memory leak.
- 0 indirectly lost bytes.

The leaked block was allocated in `person_new()`, at line 21.

It was called from `main()`, at line 51, when Alice was created.

The 6 bytes correspond to the string "Alice":

- 5 characters.
- 1 final null character (`\0`).

### How I would correct the problem

The function `person_free_partial()` should also release the name before freeing the structure.

The correct order is:

1. Free `p->name`.
2. Free `p`.

This avoids losing the address of the name allocation.

### My conclusion

This example helped me understand that freeing a structure does not automatically free the memory pointed to by its fields.

Each allocation made with `malloc()` must be released separately.

I also learned that a program can run normally and still contain a memory leak. Valgrind helped me identify the exact allocation that was not released.

