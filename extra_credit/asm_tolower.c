/*
 * ls339
 * CS433
 * Extra Credit
 */
	
#include <stdio.h>
#include <string.h>

#define MAXSTRING 256

static inline char * asm_tolower(char *s) {
  char *dest;
  __asm __volatile ("movsb"
		   :
		   :"S"(s), "D"(dest)
		   : "memory"
		   );
  return dest;
}

int main(int argc,char **argv) {
  
  if ( argc < 2 ) {
    printf("Input string\n");
    return 0;
  }
  char *s = argv[1];
  printf("String : %s\n",asm_tolower(s));
}
