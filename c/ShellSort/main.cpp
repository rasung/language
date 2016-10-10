#include <stdio.h>
#include <stdlib.h>

int less(int a, int b){
    if(a<b){
        return 1;
    }
    else {
        return 0;
    }
}

void exch(int data[], int a, int b){
    int temp = data[a];
    data[a] = data[b];
    data[b] = temp;
}

void ShellSort(int data[], int length){
    int i,j;
    int h = 1;

    while(h < length/3){
        h=(3*h)+1;
    }

    for(; h >= 1; h/=3){
        for(i=h; i<length; i++){
            for(j=i; j>=h && less(data[j], data[j-h]); j-=h){
                exch(data,j,j-h);
            }
        }
    }
}

void printArray(int data[], int length){
    int i;
    for(i=0; i<length; i++){
        printf("%d ", data[i]);
    }
}

int main() {
    int *data;
    int i,length;

    /*************** user input ************/
    printf("test data length:");
    scanf("%d", &length);
    data = (int *)malloc(length * sizeof(int));

    printf("test data input:");
    for(i=0; i<length; i++){
        scanf("%d", data+i);
    }
    printf("test data:");
    printArray(data, length);
    /*************** end user input ****************/


    /**************** sort ****************/
    ShellSort(data, length);
    /**************** end sort ****************/


    /**************** show result ****************/
    printf("after ShellSort :");
    printArray(data, length);
    /**************** end show result ****************/


    free(data);
    return 0;
}