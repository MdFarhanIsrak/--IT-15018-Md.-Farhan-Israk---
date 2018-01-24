#include<stdio.h>
int main()
{
    int Allocation[100][100],max[100][100],
    Available[100],NeedMatrix[100][100],i,j,k=0,
    order[100],n,m,count=0;
    int finish[100]={0};
    printf("Enter Number of process:");
    scanf("%d",&n);
    printf("\nEnter Number of Resources:");
      scanf("%d",&m);
    printf("\nEnter Allocation Matrix:\n");
    for(i=0;i<n;i++)
  for(j=0;j<m;j++)
          scanf("%d",&Allocation[i][j]);
    printf("\nEnter Max Allocation Matrix:\n");
     for(i=0;i<n;i++)
        for(j=0;j<m;j++)
          scanf("%d",&max[i][j]);
    printf("\nEnter Available:\n");
    for(j=0;j<m;j++)
    scanf("%d",&Available[j]);
    printf("\n\nNeed Matrix is:\n");
     for(i=0;i<n;i++)
       {
          for(j=0;j<m;j++){
            NeedMatrix[i][j]=max[i][j]-Allocation[i][j];
            printf("%d ",NeedMatrix[i][j]);
          }
          printf("\n");
       }
   begin:
   for(i=0;i<n;i++){
        count=0;
    if(finish[i]==0){
        for(j=0;j<m;j++){
            if(Available[j]>=NeedMatrix[i][j])
              count++;
            else
    break;
 }
        if(count==m){
            finish[i]=1;
            for(j=0;j<m;j++){
                Available[j]=Available[j]+Allocation[i][j];
            }
            order[k++]=i;
        }
    }
   }
for(i=0;i<n;i++)
{if(finish[i]==0)
      goto begin;
}

printf("\n\nSequence is:\n\n");
for(i=0;i<n;i++){
printf("p%d",order[i]);
    if(i<n-1)
        printf("->");
    }

    printf("\n\n");
return 0;
}
