#include <stdio.h>
#include <string.h>

#define MAXSTRING 256

static inline char * sub_str(char * dest, char *src, int s_idx, int e_idx){
  char buff[(e_idx-s_idx)];
  memcpy(buff,&src[s_idx],(e_idx-s_idx)+1);
  buff[(e_idx-s_idx)+1] = '\0';
  dest = buff;
  return dest;
}

static inline char * asm_sub_str(char * dest, char *src, int s_idx, int e_idx) {
  char buff[(e_idx-s_idx)];
  int d0, d1, d2;

  
  asm volatile ("cld\n\t"
		"rep\n\t"
		"movsb"
		:
		: "c" (e_idx - s_idx + 1), "S" (src + s_idx), "D" (dest)
		: "memory"
		);
  
/*
  __asm__ __volatile__ (   "1:\tlodsb\n\t"
		   "stosb\n\t"
		   "testb %%al,%%al\n\t"
		   "jne 1b"
		 : "=&S" (d0), "=&D" (d1), "=&a" (d2)
		 : "0" (src + s_idx),"1" (dest)
		 : "memory");
*/  
/*
  __asm__ __volatile__( "cld\n\t"
		 "rep\n\t"
		 "movsb"
		 :
		 :"S"(src + s_idx), "D"(dest), "c"(e_idx - s_idx + 1)
		 );
*/
  return dest;
}

int main(int argc,char **argv) {
  /*
  get a string and starting and ending indices from the command line,
    call a C function, d1=sub_str(d,s,s_idx,e_idx),
    call a C function, d2=asm_sub_str(d,s,s_idx,e_idx) using inlining,
  compare the two strings d1 and d2 and return the result.
  */
  if ( argc < 4 ) return 0;
  char * d1;
  char * d2;
//char * dest;
  char dest[MAXSTRING];
  char asm_dest[MAXSTRING];
  char * s = argv[1];
  int s_idx = atoi(argv[2]);
  int e_idx = atoi(argv[3]);

  //printf("Before sub_str : %s\n",d1);
  //printf("Length: %d\n",strlen(d1));
  printf("Input String : %s\n",s);
  printf("Input Starting Index : %d\n",s_idx);
  printf("Input Ending Index : %d\n",e_idx);
  d1 = sub_str(dest,s,s_idx,e_idx);
  printf("\tResult of function sub_str() : %s\n", d1);
  printf("\tLength: %d\n",strlen(d1));
  d2 = asm_sub_str(asm_dest,s,s_idx,e_idx);
  printf("\tResult of function asm_sub_str() : %s\n", d2);
  printf("\tLength: %d\n",strlen(d2));
  if(*d1!=*d2) {
    printf("\tResults do not match.\n");
  } else {
    printf("\tResults match.\n");
  }
}
