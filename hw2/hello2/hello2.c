/*
 * ls339
 * CS433
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int hello2_data __initdata = 2;

static int __init hello2_init(void) {

  printk(KERN_INFO "ls339: Loading Hello2 module - Hello World %d\n", hello2_data);
  return 0;
}

static void __exit hello2_exit(void) {
  printk(KERN_INFO "ls339: Exiting Hello2 module - Goodbye World 2\n");
}

module_init(hello2_init);
module_exit(hello2_exit);
