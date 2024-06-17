#include<stdio.h>
int main()
{
    int i,o,s,n,st=0;
    printf("Enter The Bucket Size,Outgoing Rate & No of Inputs :");
    scanf("%d %d %d",&s,&o,&n);
    while(n!=0)
    {
        printf("Enter The Incoming Packet Size :");
        scanf("%d",&i);
        printf("Incoming Packet Size : %d\n",i);
        if(i<=(s-st))
        {
            st+=i;
            printf("Bucket Buffer Size Is %d Out of %d\n",st,s);
        }
        else
        {
            printf("Dropped Number of Packets :%d\n",i-(s-st));
            st+=s-st;
            printf("Bucket Buffer Size is %d out of %d\n",st,s);
        }
        st=st-o;
        printf("After Outgoing,%d Packets Left out of %d in Buffer\n",st,s);
        printf("\n");
        n--;
    }
}