// NIM - Name
// NIM - Name

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int _argv, char **_argc)
{
  char input[255];
  char kata[255];
  int index = 0;
  int angka;
  kata[0] = '\0';

  while(1){
    char huruf = getchar();

    if(huruf != '\r' && huruf != '\n'){
      kata[index] = huruf;
      kata[++index] = '\0';
    }else{
      if(huruf == '\r'){
        continue;
      }

      if(huruf == '\n'){
        break;
      }
    }
  }

  scanf("%d",&angka);
  angka = angka % 255;
  strcpy(input,kata);
  
  for(int i = 0 ; i < strlen(input) ; ++i){
    printf("%03d",input[i] + angka);
    input[i] = (char) input[i] + angka;
  }
  printf("\n");

  printf("%s\n",input);
  return 0;
}
