# xenomiRTLib
Useful fundamental library for RTOS in C 


### Compile with: 
$ gcc -o semaphore_1 semaphore_1.c -I/usr/xenomai/include -lanalogy -lnative -lxenomai -lrt -lpthread -L/usr/xenomai/lib
### Execute with:
$./"semaphore_1.c"

### semaphore 
Wait and Signal Synchronization, Multi-task Wait and Signal Synchronization, Credit tracking Synchronization, Single-Shared-Resource-Access Synchronization

### mutex
Recursive Access a Shared Resource, Multiple tasks accessing equivalent shared Resources, Multiple tasks accessing equivalent shared resources using mutexes

Ref: Real Time Concepts for Embedded Systems 
     http://cneeraj.weebly.com/uploads/9/6/4/0/9640805/real-time_concepts_for_embedded_systems_by_qing_li.pdf


