# CSCI3060U-Project
To run:\
 -Open directory containing files in command line\
 -Run make\
 -Run a.out and enter arguments for the program from the command line\
  -Format of the argv array: (./a.out, sessiontype, name, accountnum, transaction, input1, input2 ...)<br/> 
  -e.g ./a.out 1 Sheldon 1 withdrawl 10\
  -e.g ./a.out 1 John 2 deposit 500\
  -e.g ./a.out 1 Sheldon 1 transfer 2 100\
  -e.g ./a.out 1 Sheldon 1 paybill EC 21\
  -e.g ./a.out 0 Sheldon 1 logout\
  -e.g ./a.out 0 John 2 create chan 3 900\
  -e.g ./a.out 0 John 2 delete chan 3\
  -e.g ./a.out 0 John 2 disable Sheldon 1\
  -e.g ./a.out 0 John 2 changePlan Sheldon 1 SP\
