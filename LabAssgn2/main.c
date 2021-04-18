#include<stdio.h>
#include<stdlib.h>
#include"bstArray.h"
int main(){
    bst t;
    int i,j,k;
    init_bst();
    do{
        printf("\nQuestion 1");
        printf("\nQuestion 2");
        printf("\nEnter choice");
        scanf("%d",&k);
        switch(k){
        case 1:
        do{
            printf("\n1)Insert_bst");
            printf("\n2)InOrder Traversal");
            printf("\n3)Preorder Traversal");
            printf("\n4)Postorder Traversal");
            printf("\n5)Check if is Complete BST");

            printf("\nEnter Choice ");
            scanf("%d",&i);
            switch(i){
            case 1:
                printf("\nEnter the Element");
                int d;
                scanf("%d",&d);
                insert(d);
                break;
            case 2:
                inOrder(0);
                break;
            case 3:
                preOrder(0);
                break;
            case 4:
                postOrder(0);
                break;
            case 5:
                j=isCompletebst(0,count(0));
                if(j==1)
                    printf("\nComplete BST");
                else
                    printf("\nNot Complete BST");
                break;
            }
        }while(i<6);
        break;
        case 2:
            initbst(&t);
            int arr[Q];
            int l;
            printf("\nEnter Number of element");
            scanf("%d",&l);
            printf("\nEnter postorder sequence");
            for(int m=0;m<l;m++){
                scanf("%d",&arr[m]);
            }
            generatebst(&t,arr,0,l-1);
            printf("\nInorder sequence is: ");
            inOrderbst(t);
            break;
        }
    }while(k<3);

    return 0;
}
