#include<stdio.h>
int main()
{
    struct emp{
        char name[25];
        int flower_count;
        
    }f1,*f2;
    f1.flower_count=10;
    f1.name="ROSE";
    f2=&f1;
    printf("%d",f2.flower_count);
    return 0;
}