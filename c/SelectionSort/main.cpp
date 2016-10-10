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

void SelectionSort(int data[], int length){
    int i, j, temp, min;
    for(i=0; i<length; i++){
        min = i;
        for(j=i; j<length; j++){
            if(less(data[j], data[min])){
                min = j;
            }
        }
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
}

void printArray(int data[], int length){
    int i;
    for(i=0; i<length; i++){
        printf("%d ", data[i]);
    }
}

int main()
{
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
    SelectionSort(data, length);
    /**************** end sort ****************/


    /**************** show result ****************/
    printf("after SelectionSort :");
    printArray(data, length);
    /**************** end show result ****************/


    free(data);
    return 0;
}