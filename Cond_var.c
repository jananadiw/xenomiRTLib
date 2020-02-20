Cond_var.c

#include <native/mutex.h>
#include <native/cond.h>
RT_COND cond_desc;
RT_MUTEX mutex_desc;
int shared_event = 0;

void foo (void)
{
int err;
err = rt_mutex_create(&mutex_desc,"MyCondMutex");
err = rt_cond_create(&cond_desc,"MyCondVar");
rt_mutex_acquire(&mutex_desc,TM_INFINITE);
while (!shared_event && !err)
err = rt_cond_wait(&cond_desc,&mutex_desc,TM_INFINITE);
rt_mutex_release(&mutex_desc);
}

void bar (void)
{
rt_mutex_acquire(&mutex_desc,TM_INFINITE);
shared_event = 1;
rt_cond_signal(&cond_desc);
rt_mutex_release(&mutex_desc);
}

void cleanup (void)
{
rt_cond_delete(&cond_desc);
rt_mutex_delete(&mutex_desc);
}

