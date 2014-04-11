#include <linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>


int intVal = 0;
int intArr[2] = {0,0};
char *devName = NULL;

module_param(intVal, int, S_IRUSR | S_IWUSR|S_IRGRP|S_IWGRP);
MODULE_PARM_DESC(intVal, "This an integer param");

module_param_array(intArr, int, NULL,0000); //The left out blank is count
MODULE_PARM_DESC(intArr, "This is an int array");

module_param(devName, charp ,0000); //The left out blank is count
MODULE_PARM_DESC(p, "This is a string");

/*module_param_string();
MODULE_PARAM_DESC();*/


static int __init init_mod(void)
{
	printk(KERN_INFO "Hello world");
	return 0;
}

static void  __exit cleanup_mod(void)
{
	printk(KERN_INFO "Goodbye world");
}

module_init(init_mod);
module_exit(cleanup_mod);

MODULE_AUTHOR("Bhushan J");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Sample K program");
