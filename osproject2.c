#include<stdio.h>
#include<string.h>

void main()

{
  char p_name[10][5],temp[5];
  int i,j,bt[10],w[10],tw=0,prio[10],temp1,n_p;
  float avgw;
 
printf("enter no of processes:- "); 
scanf("%d",&n_p);
printf("==========================");
 for(i=0;i<n_p;i++)
 {
  printf("\nenter process%d name:- ",i+1);
  scanf("%s",&p_name[i]);
  printf("enter Brust time:");
  scanf("%d",&bt[i]);
  printf("enter priority:");
  scanf("%d",&prio[i]);
  printf("===========================");
 }
  
for(i=0;i<n_p-1;i++)
{
 for(j=i+1;j<n_p;j++)
 {
   if(prio[i]>prio[j])
  {
   temp1=prio[i];
   prio[i]=prio[j];
   prio[j]=temp1;
   temp1=bt[i];
   bt[i]=bt[j];
   bt[j]=temp1;
   strcpy(temp,p_name[i]);
   strcpy(p_name[i],p_name[j]);
   strcpy(p_name[j],temp);
   }
  }
}
  
w[0]=0;
for(i=1;i<n_p;i++)
{
 w[i]=w[i-1]+bt[i-1];
 tw=tw+w[i];
  }
   
avgw=(float)tw/n_p;
 printf("\n");
 printf("\n========================================="); 
printf("\np_name    p_time    priority    w_time\n");
    
for(i=0;i<n_p;i++)
    
{
   printf("  %s  ||    %d  ||   %d      ||    %d\n" ,p_name[i],bt[i],prio[i],w[i]);
   }
printf("=========================================\n");
printf("\n**************************\n");
 printf("|| total waiting time=%d ||\n",tw);
printf("**************************\n");
printf("\n**************************\n");
 printf("|| avg waiting time=%f ||",avgw);
printf("\n**************************\n");
}

