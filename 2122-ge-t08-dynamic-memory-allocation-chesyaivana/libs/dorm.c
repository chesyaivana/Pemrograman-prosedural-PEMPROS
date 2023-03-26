#include "dorm.h"
#include<string.h>
#include<stdio.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

/*
 * Fungsi ini akan meminta beberapa parameter diantaranya :
 *  1. char pointer _name
 *  2. unsigned short _capacity
 *  3. enum gender_t _gender
 * */
struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender) {
    // Deklarasikan sebuah variabel dorm dengan nama new_dorm;
    struct dorm_t new_dorm;

    // Bersihkan field new_dorm.name
    memset(new_dorm.name, '\0', sizeof(new_dorm.name));
    // Copy w/ strncpy
    strncpy(new_dorm.name, _name, strlen(_name));

    // Tambahkan semua attribut sisa
    new_dorm.capacity = _capacity;
    new_dorm.gender = _gender;

    // Kembalikan variabel new_dorm sebagai nilai kembalian dari fungsi create_dorm]
    return new_dorm;
}

void print_dorm(struct dorm_t dorm) {
    switch (dorm.gender) {
        case GENDER_MALE :
            printf("%s|%d|%s\n", dorm.name, dorm.capacity, "male");
            break;

        case GENDER_FEMALE :
            printf("%s|%d|%s\n", dorm.name, dorm.capacity, "female");
            break;
    }
}