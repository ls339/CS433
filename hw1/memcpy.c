#include <stdio.h>
#include <string.h>

int main() {
  char * src = "Thestringislong";
  char buff[5];
  memcpy(buff,&src[1],4);
  buff[4]='\0';
}
