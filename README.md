# Stack-machine
Task from "Algorithms and data structures" subject.


Content of the command:

Write a program that performs the following operations on the integer stack. 
Stack should be implemented as a unidirectional list.

number - inserting a number into a stack
p - print stack (from top to bottom)
s - swapping places with two numbers at the top of the stack
x - removing an item from the top of the stack
+ - remove the two numbers from the stack and insert thei sum on the stack
p - remuve a 'n' number from the top of stack, moving the number to the nth place of the stack (counting from the top). 
    0 r and 1 r do nothing, 2 r is the same as 's', 3 r turns 3 2 1 to 2 1 3.
q - quit

Note: s and r operations may only modify pointers.



Input:
At the output will be given a string of commands. Each command will consist of a single character.

Output:
Should be written to the output result of the command p, separated by newlines characters.



Example:

Input:
1 p
2 p
3 p
4 p
5 p
x p
x p
x p
x p
x p
1 2 3 4 5 p
+ p
+ p
+ p
+ p
x p
1 2 3 4 5 p
s p
s p
1 r p
2 r p
2 r p
3 r p
3 r p
3 r p
4 r p
4 r p
4 r p
4 r p
5 r p
5 r p
5 r p
5 r p
5 r p
q

Output:
1 
2 1 
3 2 1 
4 3 2 1 
5 4 3 2 1 
4 3 2 1 
3 2 1 
2 1 
1 

5 4 3 2 1 
9 3 2 1 
12 2 1 
14 1 
15 

5 4 3 2 1 
4 5 3 2 1 
5 4 3 2 1 
5 4 3 2 1 
4 5 3 2 1 
5 4 3 2 1 
4 3 5 2 1 
3 5 4 2 1 
5 4 3 2 1 
4 3 2 5 1 
3 2 5 4 1 
2 5 4 3 1 
5 4 3 2 1 
4 3 2 1 5 
3 2 1 5 4 
2 1 5 4 3 
1 5 4 3 2 
5 4 3 2 1
