#include "student.h"

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */
void print_student_detail(struct student_t *student,int size){
    for(int indeks = 0 ; indeks < size ; indeks++){
        switch (student[indeks].gender)
        {
            case GENDER_FEMALE:
                if(student[indeks].dorm != NULL && strcmp(student[indeks].dorm->name,"LEFT") != 0){
                    printf("%s|%s|%s|female|%s\n",student[indeks].id,student[indeks].name,student[indeks].year,student[indeks].dorm->name);
                    break;
                }

                if(student[indeks].dorm != NULL && strcmp(student[indeks].dorm->name,"LEFT") == 0){
                    printf("%s|%s|%s|female|left\n",student[indeks].id,student[indeks].name,student[indeks].year);
                    break;
                }
                printf("%s|%s|%s|female|unassigned\n",student[indeks].id,student[indeks].name,student[indeks].year);
            break;
            
            case GENDER_MALE:
                if(student[indeks].dorm != NULL && strcmp(student[indeks].dorm->name,"LEFT") != 0){
                        printf("%s|%s|%s|male|%s\n",student[indeks].id,student[indeks].name,student[indeks].year,student[indeks].dorm->name);
                        break;
                }
                if(student[indeks].dorm != NULL && strcmp(student[indeks].dorm->name,"LEFT") == 0){
                    printf("%s|%s|%s|male|left\n",student[indeks].id,student[indeks].name,student[indeks].year);
                    break;
                }
                printf("%s|%s|%s|male|unassigned\n",student[indeks].id,student[indeks].name,student[indeks].year);
            break;
        }
    }
}

void assign_student(struct student_t *student,struct dorm_t *dorm){
    if(student->gender == dorm->gender){
        if(dorm->capacity > dorm->residents_num){
            dorm->residents_num++;
            student->dorm = dorm;
        }else{
            student->dorm = NULL;
        }
    }   
}


struct student_t create_student(char *_id, char *_name, char *_year,enum gender_t _gender){
    struct student_t newStudent;

    memset(newStudent.id,'\0',strlen(newStudent.id));
    memset(newStudent.name,'\0',strlen(newStudent.name));
    memset(newStudent.year,'\0',strlen(newStudent.year));

    strcpy(newStudent.id,_id);
    strcpy(newStudent.name,_name);
    strcpy(newStudent.year,_year);

    newStudent.gender = _gender;
    newStudent.dorm = NULL;

    return newStudent;
}


void student_leave(struct student_t *student,struct dorm_t *leave){
    if(student->dorm->residents_num > 0){
        // printf("Leave\n");
        student->dorm->residents_num--;
        student->dorm = leave;
    }
}