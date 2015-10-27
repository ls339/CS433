/*
 * ls339
 * CS433
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>

static char *my_name = "A Default Name";
static char *my_street = "123 Default Street";
static char *my_city = "Anytown";
static long int my_zip = 55555;

module_param(my_name, charp, S_IRUSR);
module_param(my_street, charp, S_IRUSR);
module_param(my_city, charp, S_IRUSR);
module_param(my_zip, long, S_IRUSR);

static int __init hello3_init(void) {
  printk(KERN_INFO "Loading Hello 3: Hello World 3\n");
  printk(KERN_INFO "==============================\n");
  printk(KERN_INFO "Name : %s\n",my_name);
  printk(KERN_INFO "Street : %s\n", my_street);
  printk(KERN_INFO "City : %s\n", my_city);
  printk(KERN_INFO "Zip : %ld\n", my_zip);
  return 0;
}

static void __exit hello3_exit(void) {
  printk(KERN_INFO "ls339: Exiting Hello3 module\n");
  printk(KERN_INFO "==============================\n");
}

module_init(hello3_init);
module_exit(hello3_exit);
