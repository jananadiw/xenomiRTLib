#include<stdio.h>
#include <native/sem.h>
#define SEM_INIT 0 
#define SEM_MODE S_FIFO 
RT_SEM sem_desc;
void foo ()
{
int err;

err = rt_sem_create(&sem_desc,"MySemaphore",SEM_INIT,SEM_MODE);
for (;;) {

rt_sem_p(&sem_desc,TM_INFINITE);

rt_sem_v(&sem_desc);
}
}
void cleanup ()
{
rt_sem_delete(&sem_desc);
}

