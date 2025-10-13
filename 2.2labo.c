#include <stdio.h>
#include <stdlib.h>

int main(){
  char cmd[256];
  char buffer[256];
  
 for (int i = 0; i < 46; i++){
    snprintf(cmd, sizeof(cmd), "echo \"e5ed313192776744b9b93b1320b5e268\" ~/ISSKS/\"Laborategia 2\"/imagen/imagen%d.jpg | md5sum ~/ISSKS/\"Laborategia 2\"/imagen/imagen%d.jpg", i, i);
    FILE *fp = popen(cmd, "r");
    if (!fp){
      perror("popen");
      exit(1);
    }
    
    while(fgets(buffer, sizeof(buffer), fp) != NULL){
      printf("%s", buffer);
    }
    pclose(fp);
  }
  return 0;
}
