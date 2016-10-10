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

void InsertionSort(int data[], int length){
    int i,j,temp;
    for(i=1; i<length; i++){
        j=i;
        temp = data[j];
        while(j>0 && less(temp, data[j-1])){
            data[j] = data[j-1];
            j--;
        }
        data[j] = temp;
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
    /*************** end input ****************/


    /**************** sort ****************/
    InsertionSort(data, length);
    /**************** end sort ****************/


    /**************** show result ****************/
    printf("after InsertionSort :");
    printArray(data, length);
    /**************** end show result ****************/


    free(data);




    return 0;
}