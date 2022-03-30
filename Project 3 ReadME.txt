ReadME for Wesley Baker and Adam Ringwell's Project 3

In order to execute P1.c make sure the file is on your machine. 
Next open up the command prompt and type: gcc P1.c -o P1
Following this, type: "./P1" to execute the compiled program. You should be able to run any batch file
the one we ran is included. 

Then in order to execute the Scheduler make sure the file is on your machine.
Next in the command prompt under the same directory as the P1.c compile by entering: g++ ShortTermScheduler.cpp -pthread -o Scheduler
Following this, type: "./Scheduler" to execute the compiled program. You should be able to run any batch file and program. 

However, we will attach the 5 programs we used to test our program if you would like to do the same download them onto your machine and run each of them by compiling them first.

For BFA.cpp
Compile by entering: g++ BFA.cpp -o BFA, then in the scheduler type ./BFA

For Add.cpp
Compile by entering: g++ Add.cpp -o Add, then in the scheduler type ./Add

For DA.c
Compile by entering: gcc DA.c -pthread -o DA, then in the scheduler type ./DA

For Semaphore.c
Compile by entering: gcc Semaphore.c -pthread -o Semaphore, then in the scheduler type ./Semaphore

For Monitor.c
Compile by entering: gcc Monitor.c -o Monitor, then in the scheduler type ./Monitor

For the Batch file
Make sure the file is on your machine, then run in the scheduler by typing ./ShellScript1