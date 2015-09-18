#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init hello_init(void) {

  printk(KERN_INFO "My Name: Loading Hello1 module using macros - Hello World 1\n");
  return 0;
}

static void __exit hello_exit(void) {
  printk(KERN_INFO "My Name: Exiting Hello1 module using macros - Goodbye World 1\n");
}

module_init(hello_init);
module_exit(hello_exit);
