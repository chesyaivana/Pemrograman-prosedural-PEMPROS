#include "dorm.h"

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */
struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender){
   
    struct dorm_t newDorm;

    memset(newDorm.name,'\0',strlen(newDorm.name));
    
    strcpy(newDorm.name,_name);

    newDorm.capacity = _capacity;
    newDorm.gender = _gender;
    newDorm.residents_num = 0;

    return newDorm;
}

void print_dorm_all_detail(struct dorm_t *dorms,int size){
    for(int indeks = 0 ; indeks < size ; indeks++){
        switch (dorms[indeks].gender)
        {
        case GENDER_MALE:
            if(dorms[indeks].residents_num != 0){
                printf("%s|%d|male|%d\n",dorms[indeks].name,dorms[indeks].capacity,dorms[indeks].residents_num);
            
                break;
            }
            printf("%s|%d|male|0\n",dorms[indeks].name,dorms[indeks].capacity);
            
            break;
        
        case GENDER_FEMALE:
            if(dorms[indeks].residents_num != 0){
                printf("%s|%d|female|%d\n",dorms[indeks].name,dorms[indeks].capacity,dorms[indeks].residents_num);
             
                break;
            }
            printf("%s|%d|female|0\n",dorms[indeks].name,dorms[indeks].capacity);
  
            break;
        }
    }
}

