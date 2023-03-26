#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct course{
    char Course_ID[30];
    char Course_Name[30];
    int Course_SKS;
};

struct asdos{
    struct course Course;
    char Nama[30];
    char NIM[10];
};

struct course createcourse(char Course_ID[], char Course_Name[], int Course_SKS){

    struct course coursebaru;
    strcpy(coursebaru.Course_ID, Course_ID);
    strcpy(coursebaru.Course_Name, Course_Name);
    coursebaru.Course_SKS = Course_SKS;

    return coursebaru;
}

struct asdos createasdos(struct course course, char Nama[], char NIM[]){

    struct asdos asdosbaru;
    asdosbaru.Course=course;
    strcpy(asdosbaru.Nama,Nama);
    strcpy(asdosbaru.NIM, NIM);

    return asdosbaru;
}

int main(){

    struct asdos Viny;

    Viny= createasdos(createcourse("PEM123", "PEMPROS", 25), "Viny", "12345");

    printf("Nama Asdos\t: %s\n", Viny.Nama);
    printf("NIM Asdos\t: %s\n", Viny.NIM);
    printf("Mata Kuliah\t: \n");
    printf("ID\t: %s\n", Viny.Course.Course_ID);
    printf("Nama\t: %s\n", Viny.Course.Course_Name);
    printf("SKS\t: %d\n", Viny.Course.Course_SKS);
}