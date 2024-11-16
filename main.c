
#include  <stdio.h>
#include <stdlib.h>
#define Alphabet 52
char* control_input(int *ret, char* arr_first, int*length_1);

void shift(char* arr_first, char * arr_second, int offset, char* letters[]);
int compare(const char *str1, const char *str2);
char rotate(char original[], int offset,  char* letters[]);


int main(void) {
    int size = 15;
    int length_1 =0,length_2 = 0;
    int ret = EXIT_SUCCESS;
    int offset = 0;
    char* arr_first = (char*)malloc(sizeof(char) * size);
    char* arr_second  = (char*)malloc(sizeof(char) * size);
    char * letters[] ={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n','o', 'p', 'q', 'r', 's', 't', 'u', 'v','w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
        'W', 'X', 'Y', 'Z'
    };
    // char letter = (arr_first[3] - 'a' + offset)%26 +'a';
    // printf("First %c\n", letter);
    // printf("%c\n",letters[51]);
    if (arr_first != NULL && arr_second != NULL) { //if not empty
        control_input(&ret,arr_first, &length_1);
        control_input(&ret,arr_second, &length_2);
    }else
        free ( arr_first );

    //Check for length
    if(length_1 != length_2) {
        free(arr_first);
        free(arr_second);
        fprintf(stderr,"Chybna delka vstupu!\n");
        ret = 101;
    }
    shift(arr_first,  arr_second, offset, letters);
    return ret;
}


void shift(char* arr_first, char * arr_second, int offset, char* letters[]) { // WHY TF IT HAS CHANGED AFTER I ADDED []
    int counter = 0;
    offset = 0;
    int max_same = 0;
    char tamp;
    // while(offset != 52){
    // char re = letters[('a' - 'a' + 2) ];
    // printf("A%c", letters[28]);
    // printf("re is %c\n", re);

    for (int j = 0; j < Alphabet; j++) {
        for (int i = 0; i < 10; i++) {//////dont forget
            int posun = (j + (arr_first[i] - 'a'));//%52
            tamp = letters[posun];
            // printf("arr i %c\n", arr_first[i]);
            // printf("tamp = %c", tamp);
            if(tamp == arr_second[i]) {
                counter ++;
            }

        }
        if (counter > max_same) {
            offset = j;
            max_same = counter;
            counter = 0;
        }
    }
    rotate(arr_first, offset, letters);///////////////////////////////////////
    printf("max_same %d\n", max_same);
    printf("offset is %d\n", offset);
}

char rotate(char original[], int offset, char* letters[]) {
    char tamp;
    for(int i = 0; i < 10; i++) {
        if(original[i] < 91 && offset + original[i] > 90) {
            tamp = letters[offset + original[i] - 91];
        }
        else if (original[i] < 91) {
            tamp = letters[offset + original[i] - 39];
        }
        else {
            int new_letter = offset + (original[i] - 'a');
            tamp = letters[new_letter];
        }

        printf("%c", tamp);
    }
    printf("\n");
}


// abcdefjhij  xUbbemehbT  XYlloworld
//mnoXYhnJLJ JCudvgtXRi


char* control_input(int *ret,char* arr_first, int * length_1) { //also works for arr2 if i dont change it here ???
    int index = 0;


    char input =0 ;
    while(input != '\n') {
        input = getchar();
        *length_1 ++;
        if (input != '\n' && (input < 'A' || (input > 'Z' && input < 'a') || input > 'z')) { //CHECK for \n, free
            free(arr_first);
            fprintf(stderr, "Error: Chybny vstup!\n");
            exit(100);
        }
        arr_first[index] = input;
        index ++;
    }
    return arr_first, length_1;
}
