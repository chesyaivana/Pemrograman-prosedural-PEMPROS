// 12S21053 - Chesya Ivana J. M Sitorus
// 12S21025 - Noni Jelia

#include <stdio.h>
#include "./libs/student.h"

int main(int _argc, char **_argv)
{
    char input[100];
    struct student_t students[100];
    int std_index = 0;
    int command_index = 0;
    int print_command[50];
    

    while(1){
        int pointers = 0;

        // Input Area
        while (1)
        {
            char karakter = getchar();

            if (karakter != '\r' && karakter != '\n')
            {
                input[pointers] = karakter;
                input[++pointers] = '\0';
            }
            else
            {
                if (karakter == '\r')
                {
                    continue;
                }

                if (karakter == '\n')
                {
                    break;
                }
            }
        }

        // printf("%s\n",input);
        if(strcmp(input,"---") == 0){
            break;
        }else{
            // Tokenize
            int counter = 0;
            char inputBuffer[5][30];
            // memisahkan tanda # dengan menggunakan strtok
            char *token = strtok(input,"#");
            while (token != NULL)
            {
                /* code */
                // printf("%s\n",token);
                strcpy(inputBuffer[counter],token);
                counter++;
                token = strtok(NULL,"#");
            }
            // Always clear the stdin after tokenize
            // In order to minimize trash value.            
            fflush(stdin);

            // Check if inputBuffer[0] contains string "student-print-all"
            // If it is then save last student_index to print_command and continue the loop
            if(strcmp(inputBuffer[0],"student-print-all") == 0){
                // save last index
                print_command[command_index] = std_index;
                command_index++;
                continue;
            }
            
            if(strcmp(inputBuffer[0],"student-add") == 0){
                if(strcmp(inputBuffer[4],"male") == 0){
                    students[std_index] = create_student(
                        inputBuffer[1],
                        inputBuffer[2],
                        inputBuffer[3],
                        GENDER_MALE
                    ); 
                }
                
                if(strcmp(inputBuffer[4],"female") == 0){
                    // printf("female");
                    students[std_index] = create_student(
                        inputBuffer[1],
                        inputBuffer[2],
                        inputBuffer[3],
                        GENDER_FEMALE
                    ); 
                }
                std_index++;
                continue;
            }
        }
    }

    for(int i = 0 ; i < command_index ; ++i){
        int start_index = 0;
        for(start_index = 0 ; start_index < print_command[i] ; ++start_index){
            print_student(students[start_index]);
        }
    }
    
    return 0;
}