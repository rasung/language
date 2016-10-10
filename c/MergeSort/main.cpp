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

void MergeSort(int data[], int copy[], int lo, int hi){
    if((hi-lo)>0){
        int mid = lo+(hi-lo)/2;
        int k, i, j;

        MergeSort(data, copy, lo, mid);
        MergeSort(data, copy, mid+1, hi);

        for(k=lo; k<=hi; k++){
            copy[k] = data[k];
        }

        i = lo, j = mid+1;
        for(k=lo; k<=hi; k++){
            if(i>mid){
                data[k] = copy[j++];
            } else if(j>hi){
                data[k] = copy[i++];
            } else if(less(copy[i], copy[j])) {
                data[k] = copy[i++];
            } else {
                data[k] = copy[j++];
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
    int *copy;
    int i,length;

    /*************** user input ************/
    printf("test data length:");
    scanf("%d", &length);
    data = (int *)malloc(length * sizeof(int));
    copy = (int *)malloc(length * sizeof(int));

    printf("test data input:");
    for(i=0; i<length; i++){
        scanf("%d", data+i);
    }
    printf("test data:");
    printArray(data, length);
    /*************** end user input ****************/


    /**************** sort ****************/
    MergeSort(data, copy, 0, length-1);
    /**************** end sort ****************/


    /**************** show result ****************/
    printf("after MergeSort :");
    printArray(data, length);
    /**************** end show result ****************/


    free(data);
    free(copy);
    return 0;
}