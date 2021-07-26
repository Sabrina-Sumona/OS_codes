#include<stdio.h>

int main()
{
  int AT[10],BT[10],RT[10];
  int count,i,j,n,time=0,remain,flag=0,TQ;
  float sum_TAT=0.0,sum_WT=0.0,avg_TAT=0.0,avg_WT=0.0;

  printf("Enter the no of process:\n");
  scanf("%d",&n);
  remain=n;

  printf("Now enter the AT and BT one by one:\n");
  for(count=0;count<n;count++)
  {
        scanf("%d",&AT[count]);
        scanf("%d",&BT[count]);
        RT[count]=BT[count];
  }

  printf("And enter the TQ:\n");
  scanf("%d",&TQ);
  printf("PNO\tAT\tBT\tCT\tTAT\tWT\n");
  for(time=0,count=0;remain!=0;)
  {
    if(RT[count]<=TQ && RT[count]>0)
    {
      time=time+RT[count];
      RT[count]=0;
      flag=1;
    }
    else if(RT[count]>0)
    {
      RT[count]=RT[count]-TQ;
      time=time+TQ;
    }
    if(RT[count]==0 && flag==1)
    {
      remain--;
      printf("P%d\t%d\t%d\t%d\t%d\t%d\n",count+1,AT[count],BT[count],time,time-AT[count],time-AT[count]-BT[count]);
      sum_WT=sum_WT+time-AT[count]-BT[count];
      sum_TAT=sum_TAT+time-AT[count];
      flag=0;
    }
    if(count==n-1)
      count=0;
    else if(AT[count+1]<=time)
      count++;
    else
      count=0;
  }
  avg_TAT=sum_TAT/n;
  avg_WT=sum_WT/n;
  printf("avg of TAT = %.2f\n",avg_TAT);
  printf("avg of WT = %.2f",avg_WT);

  return 0;
}
