*This project has been created as part of the 42 curriculum by jwheatin.*

# Description
Push swap involves sorting given integers, using two stacks and a limited number of stack operations. Integers are given as an input to the program and have to be sorted into ascending order, with stack a containing the sorted integers and stack b empty. The output is a list of stack operations used that will successfully sort the input arguments into ascending order. The program additionally checks if the input is valid - the inputs have to valid integers (within int limits) and not contain duplicates.

The following stack operations are available: 
swap: swap the first two elements of stack. 
ss: swap the first two elements of each stack for both stacks. 
push: take the first element of one stack and push it to the top of the other. 
rotate: shift all elements in stack up by 1. 
rr: rotate on both stacks at once. 
reverse rotate: shift all elements in stack down by 1. 
rrr: reverse rotate on both stacks at once. 

# Instructions
The push_swap program can be compiled using:
```
make re
```
The program is then run by using the program name followed by the integer inputs, either as one string arguments or multiple arguments:
```
./push_swap 4 3 2 1
./push_swap "4 3 2 1"
```
You can also set the arguments as an environment variable and then run the program using that. For example:
```
ARG=$(shuf -i 0-250)
./push_swap $ARG
```
The output can be tested by piping it to the checker:
```
./push_swap $ARG | ./checker_linux $ARG
```
The Makefile contains standard rules: $(NAME), all, clean, fclean, re.

# Resources

# Implementation

The overall structure of the code is:
- Parse the input arguments into an array of ints (stack a), checking for errors.
- Rank the elements in stack a so that a ranks array has values 1 to n. This increases ease of sorting.
- Stack operations: the required stack operations are implemented as functions.
- Sorting - the ranks array is sorted using the stack operations in different ways, with operations written to standard output as they are called:
    - Using a basic sort for stacks of five or fewer integers.
    - Using Radix sort with bit shifting for stacks of more than five integers.


## Parsing

Parsing involves counting the number of input arguments and checking whether they are input as one string argument, or multiple arguments. The functions used to count the number of input arguments/integers also check for invalid input format.

Depending on the input type and assuming no errors thus far (i.e. only inputs are digits in a valid format), space is allocated on the heap using ```malloc``` for an integer array. The inputs are then converted from strings to integers using ps_atoi, checking whether the parsed integer exceeds int limits. If there are no errors, by this point we now have an array of integers converted from the inputs.

A final check is undertaken to ascertain if there are any duplicates within the integer array, before moving on to ranking.

## Ranking

A ranks array is allocated. The existing array of integers is looped through and ranks are obtained by looping through each element of the array and comparing to other elements in the array. From this point on, the ranks array is used for sorting.

## Stack Operations

Functions are included for stack operations. Depending on whether or not certain operations are used only on stack a or on both stacks, the written output of the operation may or may not be included within the stack operation functions.

Pointers to length of array are used in push so that the lengths of stack a and b can be updated.

No memory allocation or freeing is done within stack operations. Stacks a and b are allocated as length of stack a at start and the number of elements in each stack is kept track of.

## Sorting

In choose_sort, the sorting process is selected.

### Five or Fewer Integers

If there are two elements, they are swapped.

If there are three elements, sort3 is used.

If there are four elements, sort4 is used - rank 1 is found and pushed to b. a is then sorted using sort3. Element in b is then pushed back.

If there are five elements, sort5 is used - rank 1 and 2 are found and pushed to b. a is then sorted using sort3. Elements in b are then pushed back.

b is allocated and freed within sort4 and sort5. It is unnecessary for sort3.

### More than Five Integers

For more than five elements, a version of Radix sort is used. As we only have two stacks, we sort by looking at the bits of the integers (i.e. in their binary format) using bit shifting. We look at the rightermost bit first, and if it is 0, push to b. Loop through a doing this. Then we push everything back from b to a. This process is repeated until the correct order is obtained - the condition of the while loop checks whether stack a is in ascending order or not. b is freed after each loop.

# Potential Improvements
Linked lists would allow: 
- Not having to keep track of lengths of stacks.
- Being able to keep values and ranks in same node.
- Using lst_add_front, lst_add_back etc would simplify operations, as you don't then have to update the position of every other node like you do for equivalent in an array of ints.
- Keep overall information in head if needed.

Better sorting algorithms:
- Turk's: especially developed for 42 push_swap by 42 student.
- Longest increasing subsequence.
- Adaptive amendments to current Radix.

Allocate b in choose_sort as opposed to in each sort function.