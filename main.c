
#include  <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Alphabet 52
#define After_Z 91
#define Difference 39
#define Z 90
#define INIT_SIZE 20
// char* control_input( char* arr_first, int*length_1);
int control_input( char** arr_first, size_t * size, size_t *capacity);

void shift(char* arr_first, const char * arr_second, int offset, char* letters[]);
int compare(const char *str1, const char *str2);
char rotate(char original[], int offset,  char* letters[]);

// int* error_func(int *ret, char input);

int main(void) {
    size_t size = 0;
    size_t capacity = INIT_SIZE;
    int length_1 =0,length_2 = 0;
    int ret = EXIT_SUCCESS;
    int offset = 0;
    char *arr_first = (char*)malloc(sizeof(char) * capacity);
    char *arr_second  = (char*)malloc(sizeof(char) * capacity);
    // char* arr_first [15];
    if (arr_first != NULL && arr_second != NULL) { //if not empty
        control_input(&arr_first, &size, &capacity);
        printf("ret = %d\n", ret);
        // printf("res is %d\n", res);
        // control_input(&arr_first, size, capacity);
        // printf("%c", k);
        // printf("ABC %c\n", arr_first[0]);
        // control_input(&arr_second, &length_2);
    }else {
        free ( arr_first );
        // free ( arr_second );
    }
    char * letters[] ={"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
        "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
        "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
        "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"
    };
    // char letter = (arr_first[3] - 'a' + offset)%26 +'a';
    // printf("First %c\n", letter);
    // printf("%c\n",letters[51]);

    if(arr_first == NULL) {
        ret = EXIT_FAILURE;
        free (arr_first);
    }
    //Check for length

    // if(length_1 != length_2) {
    //     fprintf(stderr,"Chybna delka vstupu!\n");
    //     free(arr_first);
    //     free(arr_second);
    //     ret = 101;
    // }

    // if(ret == EXIT_SUCCESS)
        // shift(arr_first,  arr_second, offset, letters);

    free(arr_first);
    // free(arr_second);

    return ret;
}


void shift(char* arr_first, const char * arr_second, int offset, char* letters[]) { // WHY TF IT HAS CHANGED AFTER I ADDED []
    int counter = 0;
    offset = 0;
    int max_same = 0;
    char tamp;
    // while(offset != 52){
    // char re = letters[('a' - 'a' + 2) ];
    // printf("A%c", letters[28]);
    // printf("re is %c\n", re);
    size_t size = strlen(arr_first);

    for (int j = 0; j < Alphabet; j++) {
        for (int i = 0; i < size-1; i++) {//////dont forget
            // int posun = (j + (arr_first[i] - 'a'));//%52
            // tamp = letters[posun];
            // printf("arr i %c is i %d, j is %d ", arr_first[i], i, j);
            // printf("tamp=%c ", tamp);

            if(arr_first[i] < After_Z && j + arr_first[i] > Z) {
                tamp = *letters[j + arr_first[i] - After_Z];
            }
            else if (arr_first[i] < After_Z) {
                tamp = *letters[j + arr_first[i] - Difference];
            }
            else {
                int new_letter = j + (arr_first[i] - 'a');
                tamp = *letters[new_letter];
            }
            if(tamp == arr_second[i]) {
                counter ++;
            }
            // printf("arr i %c is i %d, j is %d ", arr_first[i], i, j);
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

char rotate(char original[], int offset, char* letters[]) {
    char tamp;
    size_t size = strlen(original);
    for(int i = 0; i < size-1; i++) {
        if(original[i] < After_Z && offset + original[i] > Z) {
            tamp = *letters[offset + original[i] - After_Z];
        }
        else if (original[i] < After_Z) {
            tamp = *letters[offset + original[i] - Difference];
        }
        else {
            int new_letter = offset + (original[i] - 'a');
            tamp = *letters[new_letter];
        }

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
int control_input(char** arr_first, size_t * size, size_t *capacity) {
    //also works for arr2 if i dont change it here ???
    int ret = EXIT_SUCCESS;
    char input;
    while(1) {
        printf("First %lu\n", *size);
        input = getchar();
        if(input == '\n') {
            break;
        }
        if ((input < 'A' || (input > 'Z' && input < 'a') || input > 'z')){ //CHECK for \n, free
            fprintf(stderr, "Error: Chybny vstup!\n");
            ret =100;
            break;
        }
            if (*size >= *capacity) {
                char *temp = (char*)realloc(*arr_first, sizeof(char) * (*capacity) * 2);
                if (temp == NULL) {
                    free(*arr_first);
                    break;
                }else {
                    *capacity = *capacity * 2;
                    *arr_first = temp;
                }

            }
        printf("Second %lu\n", *size);
        printf("size3 %lu, capacity3 %lu\n", *size, *capacity);
        (*arr_first)[*size] = input;/// -  (*arr_first) AAAAAAAAAAAAAAA
        (*size)++;
    }
    
    printf("size3 %lu, capacity3 %lu\n", *size, *capacity);
    char k = *arr_first[4];
    char k2 = *arr_first[21];
    printf("Leter %c \n", *(arr_first)[21]);
    printf("k %c, k2 %c \n", k,k2);
    // int velikost = sizeof(*arr_first)/sizeof(char);
    // printf("Velikost %d \n", velikost);
    // printf("Array size  %lu\n",sizeof(*arr_first));
    return ret;
}
// int* error_func(int *ret, char input) {
//     if (input != '\n' && (input < 'A' || (input > 'Z' && input < 'a') || input > 'z')) { //CHECK for \n, free
//         // free(arr_first);
//         fprintf(stderr, "Error: Chybny vstup!\n");
//         *ret = 100;
//     }
//     return ret;
// }


