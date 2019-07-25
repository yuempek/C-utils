#include <stdio.h>

int main(void) {
  while(1){
    char command[1<<20];
    fgets(command, sizeof(command), stdin);  
    system(command);
  }
}
