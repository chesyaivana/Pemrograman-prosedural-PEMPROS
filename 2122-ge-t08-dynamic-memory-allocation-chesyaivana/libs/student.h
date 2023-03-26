#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */

struct student_t {
    char id[50];
    char name[50];
    char year[50];
    enum gender_t gender;
};

struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender);

void print_student(struct student_t student);

#endif
