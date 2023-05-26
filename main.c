#include <linux/module.h>
#include <linux/init.h>   
#include <linux/printk.h>
#include <linux/sched/signal.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Suhas_K");
MODULE_DESCRIPTION("Lists All Tasks And Their States");


static int __init init_fn(void) 
{	
	struct task_struct *task;
	long state, exit_state;
	
    	pr_info("============================================_FUNCTION_START_============================================\n");
	
	for_each_process(task) {
		pr_info("Task's - PID: {%d}, Name: {%s}\n\tState: ", task->pid, task->comm);
		state = task->__state;
		exit_state = task->exit_state;
		
		if (state & TASK_RUNNING) {
			pr_info("Running ");
		}
		if (state & TASK_INTERRUPTIBLE) {
			pr_info("Interruptible ");
		}
		if (state & TASK_UNINTERRUPTIBLE) {
			pr_info("UnInterruptible ");
		}
		if (state & __TASK_STOPPED) {
			pr_info("Stopped ");
		}
		if (state & __TASK_TRACED) {
			pr_info("Traced ");
		}
		if (exit_state & EXIT_DEAD) {
			pr_info("Exit_Dead ");
		}
		if (state & TASK_PARKED) {
			pr_info("Parked ");
		}
		if (state & TASK_DEAD) {
			pr_info("Dead ");
		}
		if (state & TASK_WAKEKILL) {
			pr_info("Wakekill ");
		}
		if (state & TASK_WAKING) {
			pr_info("Waking ");
		}
		if (state & TASK_NOLOAD) {
			pr_info("No_Load ");
		}
		if (state & TASK_NEW) {
			pr_info("New ");
		}
		if (state & TASK_RTLOCK_WAIT) {
			pr_info("RT_Locked ");
		}
		if (state & TASK_KILLABLE) {
			pr_info("Killable ");
		}
		if (state & TASK_STOPPED) {
			pr_info("Stopped ");
		}
		if (state & TASK_TRACED) {
			pr_info("Traced ");
		}
		if (state & TASK_IDLE) {
			pr_info("Idle ");
		}
		if (state & TASK_NORMAL) {
			pr_info("Normal ");
		}
		if (state & TASK_REPORT) {
			pr_info("Report ");
		}
		if (is_special_task_state(state)) {
			pr_info("***SPECIAL TASK***");
		}
		pr_info("\n");
	}	
	    
    	return 0;
}

static void __exit exit_fn(void) 
{
    	pr_info("============================================_FUNCTION_END_==============================================\n");
}


module_init(init_fn);
module_exit(exit_fn);

