/*
 ============================================================================
 Name        : QuickSort.c
 Author      : ki
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

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

void printArray(int data[], int length){
    int i;
    for(i=0; i<length; i++){
        printf("%d ", data[i]);
    }
}
void testdata(int data[], int length){
    int i;
	for(i=0; i<length; i++){
        printf("%d", data[i]);
	}
	printf(" ");
}

void QuickSort(int data[], int lo, int hi){
	int i = lo;
	int j = hi+1;

	if(lo >= hi){
        return;
	}
	while(i<j){
		while(less(data[++i], data[lo])){
			if(i==hi){
			    break;
			}
		}
		while(less(data[lo], data[--j])){
			if(j==lo){
			    break;
			}
		}
		if(i>=j){
			break;
		}
		exch(data, i, j);

	}
	exch(data, lo, j);

	QuickSort(data, lo, j-1);
	QuickSort(data, j+1, hi);
}

int main(){
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
    QuickSort(data, 0, length-1);
    /**************** end sort ****************/


    /**************** show result ****************/
    printf("after QuickSort :");
    printArray(data, length);
    /**************** end show result ****************/


    free(data);
    return 0;
}
