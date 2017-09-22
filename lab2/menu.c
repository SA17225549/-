#include<stdio.h>
#include<stdlib.h>
void menu(){
}
void hello(){
printf("my name is sa17225549");
}
int main(){
  char cmd[256];
  while(1)
  {
    scanf("%s",cmd);
    if(strcmp(cmd,"hello")==0)
    {
      hello();
    }
    else
    {
      printf("error command");
    }
  }
}
