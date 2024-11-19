
#include  <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Alphabet 52
#define After_Z 91
#define Difference 39
#define Z 90
#define INIT_SIZE 20
int control_input( char** arr_first, unsigned long* size, unsigned long *capacity, unsigned long* length);

void shift(char* arr_first, const char * arr_second);
int compare(const char *str1, const char *str2);
void rotate(char original[], int offset,  const char* letters);


int main(void) {
    unsigned long size = 0;
    unsigned long capacity = INIT_SIZE;
    unsigned long length_1 =0;
    unsigned long length_2 = 0;
    int ret = EXIT_SUCCESS;
    char *arr_first = (char*)calloc(capacity, sizeof(char));
    char *arr_second = (char*)calloc(capacity, sizeof(char));
    if (arr_first != NULL && arr_second != NULL) { //if not empty
        control_input(&arr_first, &size, &capacity, &length_1);
        size = 0;
        capacity = INIT_SIZE;
        control_input(&arr_second, &size, &capacity, &length_2);
    }else {
        free ( arr_first );
        free ( arr_second );
    }

    if(arr_first == NULL) {
        ret = EXIT_FAILURE;
        free (arr_first);
    }
    //Check for length

    // printf("rrr2 %c\n", arr_second[2]);
    if(length_1 != length_2 ) {
        fprintf(stderr,"Error: Chybna delka vstupu!\n");
        free(arr_first);
        free(arr_second);
        return  101;
    }

    if(ret == EXIT_SUCCESS)
        shift(arr_first,  arr_second);

    free(arr_first);
    free(arr_second);

    return ret;
}


void shift(char* arr_first, const char * arr_second) { // WHY TF IT HAS CHANGED AFTER I ADDED []
    int counter = 0;
    int offset = 0;
    int max_same = 0;
    char tamp = 0;
    int new_letter = 0;
    char letters[] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    unsigned long size = strlen(arr_first);
    // printf("leters=%s\n", letters[3]);
    // printf("leters=%c\n", letters[2]);
    for (int j = 0; j < 26; j++) {
        // if(j == arr_first[0] - 'a') {
        //     printf("Break at %c\n",j);
        //     break;
        // }
        for (int i = 0; i < size; i++) {//////dont forget
            // int posun = (j + (arr_first[i] - 'a'));//%52
            // tamp = letters[posun];
            // printf("arr i %c is i %d, j is %d ", arr_first[i], i, j);
            // printf("tamp=%c ", tamp);

            if(arr_first[i] < After_Z && j + arr_first[i] > Z) {
                tamp = letters[j + arr_first[i] - After_Z];
            }
            else if (arr_first[i] < After_Z) {
                tamp = letters[j + arr_first[i] - Difference];
            }
            else {
                new_letter = j + (arr_first[i] - 'a');
                tamp = letters[new_letter];
            }
            if(tamp == arr_second[i]) {
                counter ++;
            }
            // printf("tamp=%c\n", tamp);
            // printf("new_letter=%d\n", new_letter);
            // printf("arr_second=%c\n", arr_second[i]);
            // printf("leters=%c\n", letters[new_letter]);

            // printf("arr_1 %c is in i %d, j is %d ", arr_first[i], i, j);
            // printf("tamp=%c ", tamp);
            // printf("counter=%d\n", counter);

        }
        if (counter >= max_same) {
            offset = j;
            max_same = counter;
        }
        counter = 0;
        // printf("\n");
    }

    rotate(arr_first, offset, letters);///////////////////////////////////////
    // printf("max_same %d\n", max_same);
    // printf("offset is %d\n", offset);
}
//qrstuvwxyz
//aHcQefghWj
void rotate(char original[], const int offset, const char* letters) {
    char tamp;
    unsigned long size = strlen(original);//VALGRIN
    for(int i = 0; i < size; i++) {
        if(original[i] < After_Z && offset + original[i] > Z) {
            tamp = letters[offset + original[i] - After_Z];
        }
        else if (original[i] < After_Z) {
            tamp = letters[offset + original[i] - Difference];
        }
        else {
            int new_letter = offset + (original[i] - 'a');
            tamp = letters[new_letter];
        }
        // printf("original%c\n", original[i]);

        printf("%c", tamp);
    }
    printf("\n");
}


// abcdefjhij  xUbbemehbT  XYlloworld
//mnoXYhnJLJ JCudvgtXRi


// char* control_input(char* arr_first, int * length_1) { //also works for arr2 if i dont change it here ???
//     // int index = 0;
//     int counter = 0;
//     char input=0;
//     // int size = strlen(arr_first);
//     int size = 15;
//     while((input = getchar()) != EOF) {
//         counter ++;
//         // input = getchar();
//         // if(error_func(*ret, input)) {
//         //     free(arr_first);
//         //     exit(100);
//         // }
//         // printf("%c", input);
//         if ((input < 'A' || (input > 'Z' && input < 'a') || input > 'z') && input !='\n'){ //CHECK for \n, free
//             fprintf(stderr, "Error: Chybny vstup!\n");
//             free(arr_first);
//             exit (100);
//         }
//         if (counter >= size) {
//             char* temp = (char*)realloc(arr_first, sizeof(char) * size*2);
//             free(arr_first);
//             if (temp == NULL) {
//                 free(arr_first);
//                 break;
//             }
//             arr_first = temp;
//         }
//
//         // Add valid input to arr_first
//         arr_first[counter++] = input;
//     }
//
//     // Null-terminate the string
//     arr_first[counter] = '\0';
//
//     *length_1 = counter-1;
//     return arr_first;
// }
int control_input(char** arr_first, unsigned long* size, unsigned long *capacity, unsigned long* length) {
    //also works for arr2 if i dont change it here ???
    int ret = EXIT_SUCCESS;
    while(1) {
        // printf("First %lu\n", *size);
        char input = getchar();
        if(input == '\n') {
            break;
        }
        if ((input < 'A' || (input > 'Z' && input < 'a') || input > 'z')){ //CHECK for \n, free
            fprintf(stderr, "Error: Chybny vstup!\n");
            exit(100);
            // ret =100;
            // break;
        }
            if (*size >= *capacity) {
                char *temp = (char*)realloc(*arr_first, sizeof(char) * (*capacity) * 2);
                if (temp == NULL) {
                    free(*arr_first);
                    *arr_first = NULL;
                    // return EXIT_FAILURE;
                    break;
                }else {
                    *arr_first = temp;
                    *capacity = *capacity * 2;
                }

            }
        // printf("Second %lu\n", *size);
        // printf("size3 %lu, capacity3 %lu\n", *size, *capacity);
        (*arr_first)[*size] = input;/// -  (*arr_first) AAAAAAAAAAAAAAA
        // printf("prvek is %c \n",  (*arr_first)[*size]);
        (*size)++;
    }
    char *tamp = (char*)realloc(*arr_first, sizeof(char) * (*size+1)); //for \n
    if (tamp == NULL) {
        free(*arr_first);
        *arr_first = NULL;
        ret = 108;
        return ret;
    }
    *arr_first = tamp;
    *length = *size;
    return ret;
}


