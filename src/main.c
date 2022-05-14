#include <linux/module.h>       // Needed by all modules
#include <linux/kernel.h>       // KERN_INFO
#include <linux/sched.h>        // for_each_process, pr_info
#include <linux/sched/signal.h>  //

void print_process_list(void)
{

    struct task_struct *task;  //es una estructura de tipo task_struct
 
    for_each_process(task) //este metodo esta recorriendo la lista de procesos de task
    {
        printk(KERN_INFO "PID: %d | PNAME: %s | STATE: %ld\n", task->pid, task->comm, task->state);
        //KERN_INFO es el niver de severidad de lo que se esta logueando - 
        //se estan imprimiendo campos de datos de task de tipo task_struct
        //pid es el proccess id, comm el es el nombre del proceso(nombre del ejecutable) y state es el estado en el que se encuentra

}

}


//esta funcion carga todos los parametros necesarios, antes de inicializar el modulo y se ejecuta cuando se usa el comando insmod
int init_module(void)
{
        printk(KERN_INFO "[ **************************************************************** \n");

        print_process_list();

        return 0;
}
//esta funcion  lo que hace es remover el modulo del kernel y se ejecuta cuando se usa el comando rmmod
void cleanup_module(void)
{
        printk(KERN_INFO " **************************************************************** ]\n");
}

