#include "student.h"

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

// Lakukan hal yang sama dengan yang ada pada DORM
struct student_t create_student(char *_id, char *_name, char *_year,
                                enum gender_t _gender) {
    struct student_t new_student;

    // Clearing
    memset(new_student.id, '\0', sizeof(new_student.id));
    memset(new_student.name, '\0', sizeof(new_student.name));
    memset(new_student.year, '\0', sizeof(new_student.year));

    // Set
    strncpy(new_student.id, _id, strlen(_id));
    strncpy(new_student.name, _name, strlen(_name));
    strncpy(new_student.year, _year, strlen(_year));

    // Set
    new_student.gender = _gender;
    new_student.dorm = NULL;

    return new_student;
}

void print_student(struct student_t student) {
    switch (student.gender) {
        case GENDER_MALE :
            if (student.dorm == NULL) {
                printf("%s|%s|%s|%s|%s\n", student.id, student.name, student.year, "male", "unassigned");
                break;
            }
            printf("%s|%s|%s|%s|%s\n", student.id, student.name, student.year, "male", student.dorm->name);
            break;

        case GENDER_FEMALE :
            if (student.dorm == NULL) {
                printf("%s|%s|%s|%s|%s\n", student.id, student.name, student.year, "female", "unassigned");
                break;
            }
            printf("%s|%s|%s|%s|%s\n", student.id, student.name, student.year, "female", student.dorm->name);
            break;
    }
}

void assign_to_dorm(struct student_t *student, struct dorm_t *dorm) {
    if (student->dorm == NULL) {
        student->dorm = dorm;
        if ((student->gender == dorm->gender) && (dorm->capacity > dorm->residents_num)) {
            dorm->residents_num += 1;
            student->dorm = dorm;
        }
    }
}