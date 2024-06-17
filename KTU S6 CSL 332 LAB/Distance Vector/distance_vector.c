#include<stdio.h>
void main()
{
    int n,i,j,k;
    printf("Enter The Number Of Nodes :\n");
    scanf("%d",&n);
    int r_table[n][n];
    printf("Enter The Routing Table  :\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            printf("[%d][%d] :",i,j);
            scanf("%d",&r_table[i][j]);
        }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                if(r_table[i][j] > r_table[i][k] + r_table[k][j])
                    r_table[i][j] = r_table[i][k] + r_table[k][j];
    printf("\nDISTANCE VECTOR TABLE :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d\t",r_table[i][j]);
        printf("\n");
    }
}

