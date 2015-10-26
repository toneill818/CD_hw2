##Calculater##
###Thomas O'Neill###
###Compiler Design###

####How to compile####
Use CMake to configure a make file using the CMakeLists.txt file located in the root directory
of the project. This will generate a Makefile that can be used with make to build the library and the three executables. To build all of them at once simply enter make in the directory you specifed when using cmake. To build the library you can use the command "make lib". To build the executables you can enter make followed by the executables name (calc, calc2postfix, calc2sexpr). Or to simply build all at once run the command make.

####How to run the programs####
All three programs run the same way. You run them with no commandline arguments and pass in the expression to standard input. To run any of them type ./program_name and then enter you equation at the start of the program. It will output the result to standard output or exit if it encountered an error and hopefully print a usefull error message.

####Test cases####
To run the test case run the test.sh file and view its output. It should output nothing if all tests pass. If a test fails it should point you to the line at which it failed and you can view it in the tests.txt file to view which case failed. The test case calls the program with various input and stores it to a file then runs a diff with the expected output. 


#####Grammer#####
expr -> expr + factor | expr - factor | factor
factor -> factor * term | factor / term | factor % term | term 
term -> digit | (expr)
digit -> 0|1|...|9