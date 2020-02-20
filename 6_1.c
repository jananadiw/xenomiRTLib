#include<stdio.h>
#include<native/sem.h>
#include<native/task.h>
#define SEM_INIT 0
#define SEM_MODE S_FIFO

RT_SEM my_sem;
RT_TASK task1;
RT_TASK task2;

void twaitTask()
{
 while(1)
 {
  printf("Aquire a Semaphore\n");
  printf("Waiting....\n");
  rt_sem_p(&my_sem,TM_INFINITE);
  printf("Get!!\n");
  rt_task_sleep(1000000000);
  }
}

void tsignalTask()
{
 while(1)
  {
   rt_sem_v(&my_sem);
   printf("release semaphore\n");
   rt_task_sleep(1000000000);
   }
}

void init()
{

 int err;

 err=rt_sem_create(&my_sem,"my_sem",SEM_INIT,SEM_MODE);
  if(!err)
  {
   err=rt_task_create(&task1,"wait_task",0,98,0);
   if(!err)
     rt_task_start(&task1,&twaitTask,NULL);
      err=rt_task_create(&task2,"signal_task",0,99,0);
     if(!err)
    rt_task_start(&task2,&tsignalTask,NULL);
   }
 }


void main()
{
   init();
   printf("program end\n");
   pause();
}
 
      
