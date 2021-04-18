
#include<stdio.h>
#include<stdlib.h>
#include"bst.h"
#include"queuen.h"
int main(){
    bst t;
    int j,i;
    initBST(&t);
    do{
        char *r=malloc(sizeof(char)*30);
        printf("1)Insert name and mis\n");
        printf("2)Remove Node\n");
        printf("3)search\n");
        printf("4)Postorder Traversal\n");
        printf("5)Display Level By Level\n");
        printf("6)Destroy\n");
        scanf("%d",&i);
        switch(i){
        case 1:
            printf("Enter mis && Name\n");
            scanf("%d %[^\n]",&j,r);
            insertNode(&t,j,r);
            break;
        case 2:
            removeNode(&t,5);
            break;
        case 3:
            printf("\nEnter the data to be searched");
            scanf("%d",&j);
            int p=search(t,j);
            if(p)
                printf("\n%d is present",j);
            else
                printf("\nNo such data");
            break;
        case 4:
            postOrder(t);
            break;
        case 5:
            Display_Level(t);
            break;
        case 6:
            Destroy(&t);
            initBST(&t);
            break;

        default:
            printf("\nWrong Choice");
            break;
        }
    }
    while(i<7);
    return 0;
}


