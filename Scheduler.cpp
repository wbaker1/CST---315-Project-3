//Wesley Baker and Adam Ringwell's Project 3 Short-Term Scheduler.
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <pthread.h>
#include <algorithm>

using namespace std;

int timeQuantum = 15;

enum states {
    RUN, READY, WAIT
};

struct Process { // Struct provides the best way to make user defined processes.
    string name;
    int pid;  // process id
    pthread_t tid;  // thread id
    string type;  // process type "I/O" or "user"
    enum states state;  // process state
    void* (*func)(void*); 
};

// functions for each process
void *exec1(void *) {
    string P1exe;
    cout << "Enter the file name of Process 1: ";
    cin >> P1exe;
    cout << endl;
    cout << "Process 1: executing..." << endl;
   
    system(P1exe.c_str()); // system(); executes the command passed into the method.

    cout << "Process 1: finished." << endl;
    return NULL;
}

void *exec2(void *) {
    string P2exe;
    cout << "Enter the file name of Process 2: ";
    cin >> P2exe;
    cout << endl;
    cout << "Process 2: executing..." << endl;
    
    system(P2exe.c_str());

    cout << "Process 2: finished." << endl;
    return NULL;
}

void *exec3(void *) {
    string P3exe;
    cout << "Enter the file name of Process 3: ";
    cin >> P3exe;
    cout << endl;
    cout << "Process 3: executing..." << endl;

    system(P3exe.c_str());

    cout << "Process 3: finished." << endl;
    return NULL;
}
void *exec4(void*){
    string P4exe;
    cout << "Enter the file name of Process 4: ";
    cin >> P4exe;
    cout << endl;
    
    cout << "Process 4: executing..." << endl;
    
    system(P4exe.c_str());

    cout << "Process 4: finished." << endl;
    return NULL;
}
void *exec5(void*){
    string P5exe;
    cout << "Enter the file name of Process 5: ";
    cin >> P5exe;
    cout << endl;
    
    cout << "Process 5: executing..." << endl;

    system(P5exe.c_str());

    cout << "Process 5: finished." << endl;
    return NULL;
}

int main() {

    vector<Process> ready;  // Vector holds all Processes in ready.

    pthread_t p1, p2, p3, p4, p5;
    string pdFt1, pdFt2, pdFt3, pdFt4, pdFt5; //Process types
    cout << "Before the Scheduler begins, please define whether the five executables you'd like to run are either (I/O) or (user) processes." << endl;
    cout << "First file type: ";
    cin >> pdFt1;
    cout << "Second file type: ";
    cin >> pdFt2;
    cout << "Third file type: ";
    cin >> pdFt3;
    cout << "Fourth file type: ";
    cin >> pdFt4;
    cout << "Fifth file type: ";
    cin >> pdFt5;
	
    // Define Process variables
    Process process1;
    process1.name = "Process 1";
    process1.pid = 1;
    process1.tid = p1;
    process1.type = pdFt1;
    process1.state = READY;
    process1.func = exec1;

    Process process2;
    process2.name = "Process 2";
    process2.pid = 2;
    process2.tid = p2;
    process2.type = pdFt2;
    process2.state = READY;
    process2.func = exec2;

    Process process3;
    process3.name = "Process 3";
    process3.pid = 3;
    process3.tid = p3;
    process3.type = pdFt3;
    process3.state = READY;
    process3.func = exec3;

    Process process4;
    process4.name = "Process 4";
    process4.pid = 4;
    process4.tid = p4;
    process4.type = pdFt4;
    process4.state = READY;
    process4.func = exec4;
    
    Process process5;
    process5.name = "Process 5";
    process5.pid = 5;
    process5.tid = p5;
    process5.type = pdFt5;
    process5.state = READY;
    process5.func = exec5;

    ready.push_back(process1);
    ready.push_back(process2);
    ready.push_back(process3);
    ready.push_back(process4);
    ready.push_back(process5);
    
    // while there are Processes in the ready or wait queues
    while(!ready.empty()) {
        
        // Check if processes are present in the ready queue
        if(!ready.empty()) {
			cout << "*SCHEDULER* starting " << ready.front().name.c_str() << " then wait " << timeQuantum << endl;

            pthread_create(&ready.front().tid, NULL, ready.front().func, NULL);  // start RUN Process at front of ready queue

            ready.front().state = RUN;  // update process state
            cout << "-- Moving " << ready.front().name.c_str() << " from READY to RUN state --" << endl;

            sleep(timeQuantum);  // allocate time to wait.

            // check if the ready queue only has 1 process remaining, and has the input type.
            if(ready.size() == 1 && ready.front().type == "I/O") {
                sleep(15);  // allocate more time to wait.
            }

            // Once a process has finished, remove from the ready vector.
            if (pthread_cancel(ready.front().tid) != 0) {
                cout << "-- Process " << ready.front().name.c_str() << " stalling --" << endl;
                cout << "-- Removing " << ready.front().name.c_str() << " from READY queue --" << endl;
                ready.erase(ready.begin()); // delete thread from the front of the ready vector
            }
            else { // If it has not finish allocate more time for it to finish
                cout << "-- Moving " << ready.front().name.c_str() << " from RUN to WAIT state --" << endl;
                ready.front().state = WAIT;  
                cout << "-- Allocating WAIT time for " << ready.front().name.c_str() << " and moving from WAIT to Ready state --" << endl;
                ready.front().state = READY;
				ready.front().state = RUN;
				sleep(10);
            }
        }
    }

    cout << "*SCHEDULER* finished, all processes have finished executing" << endl;

    return 0;
}