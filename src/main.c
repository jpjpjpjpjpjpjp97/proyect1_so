#include <linux/module.h>       // Needed by all modules
#include <linux/kernel.h>       // KERN_INFO
#include <linux/sched.h>        // for_each_process, pr_info
#include <linux/sched/signal.h> 

void procs_info_print(void)
{

    struct task_struct *task;
 
    for_each_process(task)
    {
        printk(KERN_INFO "pid: %d | pname: %s | state: %ld\n", task->pid, task->comm, task->state);

}

}

int init_module(void)
{
        printk(KERN_INFO "[ INICIA ==\n");

        procs_info_print();

        return 0;
}

void cleanup_module(void)
{
        printk(KERN_INFO "== LIMPIAR ]\n");
}

MODULE_LICENSE("MIT");