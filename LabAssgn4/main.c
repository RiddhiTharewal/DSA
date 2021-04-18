
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"Avl.h"
typedef enum month{January=1,February,March,April,May,June,July,August,September,October,November,December};

int main(){
    Avl p;
    int i,t;
    enum month d;
    char str[12] = {January,February,March,April,May,June,July,August,September,October,November,December};

    init_avl(&p);
    do{
        printf("\n*********Menu**********\n");
        printf("1) Insert Node\n");
        printf("2) Remove Node\n");
        printf("3) Inorder Traverse\n");
        printf("4) Destroy Tree\n");
        printf("Enter your Choice: ");
        scanf("%d",&i);
        switch(i){
        case 1:
            printf("0:January\n1:February\n2:March\n3:April\n4:May\n5:June\n6:July\n7:August\n8:September\n9:October\n10:November\n11:December\n");
            scanf("%d",&t);
            d = str[t-1];
            printf("%d",d);
            p = insert_Avl(p,d);
            break;
        case 2:printf("0:January\n1:February\n2:March\n3:April\n4:May\n5:June\n6:July\n7:August\n8:September\n9:October\n10:November\n11:December\n");
            scanf("%d",&t);
            p = remove_node(p,t);
            break;
        case 3:
            inOrder(p);
            break;
        case 4: p = Destroy(p);
            break;
        default:printf("Entered wrong choice\n");
            break;
        }
    }while(i < 5);
    return 0;
}
