Parker Householder -CS485G Program Assignment 1

Program Description: This program is meant to parse through a file that contains a series of data chunks, each being 4 bytes long. The first chunk specifies the amount of remaining chunks. The program stores these chunks into an array of integers with size specified by the first 4 byte chunk in the file. The user is then able to type a various amount of commands, 1 command per line, each of which either make various comparisons between the elements in the array or just print a certain element out in either hex, decimal, or octal. This program is also meant to deal with various kinds of errors such as invalid commands, index numbers, etc.

Bugs: There are no known bugs with the Program

Files that will be submitted:
makefile
prog1.c
README.txt

Testing Process:
My testing for this project consisted of several step by step testing of certain chunks. For example after creating the chunk to read my file and store it into the array I printed out the array to ensure it working properly. I did something of this nature with every crucial chunk of code.

I then started to try various incorrect inputs, such as invalid commands, correct commands but with no arguments, correct commands with invalid arguments, etc.
Upon ridding my program of any potential segmentation fault, I proceeded to compare the outputs of my program with the working Program given. I would also hand compute a lot of the tests just to make sure.

This was essentially my testing process in a nutshell. It was pretty basic but I must have ran thousands of different cases throughout this process (being that there were quite a few ways to reach a critical error such as seg faulting). 
