// NIM - Name
// NIM - Name

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa_t
{
  char NIM[10];
  char Name[35];
  float IPK;
}Mahasiswa;

Mahasiswa createMahasiswa(char nim[], char name[], float ipk){
  
  Mahasiswa MahasiswaBaru;

  strcpy(MahasiswaBaru.NIM, nim);
  strcpy(MahasiswaBaru.Name, name);
  MahasiswaBaru.IPK = ipk;

  return MahasiswaBaru;
}

int main(int _argc, char **_argv)
{

  struct Mahasiswa_t DataMahasiswa[100];

  for(int i= 0; i<100; i++){
    if(DataMahasiswa!="---"){
      scanf(DataMahasiswa->NIM, DataMahasiswa->Name, DataMahasiswa->IPK);
    }
   else(DataMahasiswa = "---"){
     break;
   }
  }

  printf("NIM\t: %s\nName\t: %s\nIPK\t: %f", DataMahasiswa.NIM, DataMahasiswa.Name, DataMahasiswa.IPK);

  return 0;
}
