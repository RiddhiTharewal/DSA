/*
Name: Riddhi Ganesh Tharewal
Mis No: 111903068
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"heap.h"
int main(int argc,char* argv[]){
   FILE* fp = fopen(argv[1],"r");
    if(fp == NULL){
        printf("\nFILE DOES NOT EXIST");
        return 0;
    }

    Heap p;
    int i;
    init(&p, 10);
    while(fscanf(fp,"%d",&i)!=-1){
        insert(&p,i);
    }
    printf("The Max Heap is : ");
    display(p);
    delete(&p);
    printf("\n");
    display(p);

    printf("\nThe Heap Sort is : ");
    sort(p);
    display(p);
    fclose(fp);
}
