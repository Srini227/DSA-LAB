
#include <cstdio>
#include <cstdlib>
#include "checking.h"

int main(){
    int *input=(int *)malloc(sizeof(int));
    printf("Enter an integer:");
    scanf("%d", input);
    int *inp=(int *)malloc(sizeof(int));
    *inp=1;
    while (inp){
        printf("Enter 1 To check for Palindrom.\n");
        printf("Enter 2 To check for Armstrong number.\n");
        printf("Enter 3 To check for Perfect number.\n");
        printf("Enter 4 To Exit.\n");
        printf("Enter operation to perform: ");
        int *in=(int *)malloc(sizeof(int));
        scanf("%d", in);

        switch (*in)
        {
            case 1:
                if (Palindrome(input)){
                    printf("The given number is a Palindrome.\n");
                }
                else{
                    printf("The given number is not a Palindrome.\n");
                }
                break;
            case 2:
                if (Armstrong(input)){
                    printf("The given number is an Armstrong number.\n");
                }
                else{
                    printf("The given number is not an Armstrong number.\n");
                }
                break;
            case 3:
                if (Perfect(input)){
                    printf("The given number is an Perfect number.\n");
                }
                else{
                    printf("The given number is not an Perfect number.\n");
                }
                break;
            case 4:
                (*inp)=0;
                break;
        }
    }

}