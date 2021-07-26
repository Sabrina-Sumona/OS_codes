#include<stdio.h>
#include<math.h>

int main()
{
    int i,j,n,pos,temp;
    float sum_TAT=0.0,sum_WT=0.0,avg_TAT=0.0,avg_WT=0.0;
    printf("Enter the no. of process:\n");
    scanf("%d",&n);
    int PNO[n],Prio[n],AT[n],BT[n],CT[n],TAT[n],WT[n];
    CT[0]=0;
    printf("Now enter the PNO, AT and BT one by one:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&PNO[i]);
        scanf("%d",&Prio[i]);
        scanf("%d",&AT[i]);
        scanf("%d",&BT[i]);
    }
    for(i=1;i<=n;i++)
    {
        pos=i;
        for(j=i+1;j<=n;j++)
        {
            if(Prio[j]<Prio[pos])
            pos=j;
        }

        temp=Prio[i];
        Prio[i]=Prio[pos];
        Prio[pos]=temp;

        temp=BT[i];
        BT[i]=BT[pos];
        BT[pos]=temp;

        temp=PNO[i];
        PNO[i]=PNO[pos];
        PNO[pos]=temp;

        temp=AT[i];
        AT[i]=AT[pos];
        AT[pos]=temp;

        CT[i]=BT[i]+CT[i-1];
        TAT[i]=CT[i]-AT[i];
        WT[i]=TAT[i]-BT[i];
    }
    for(i=1;i<=n;i++)
    {
        printf("process no: %d, Priority: %d, AT: %d, BT: %d, CT: %d, TAT: %d, WT: %d.\n",PNO[i],Prio[i],AT[i],BT[i],CT[i],TAT[i],WT[i]);
    }
    for(i=1;i<=n;i++)
    {
        sum_TAT=sum_TAT+TAT[i];
        sum_WT=sum_WT+WT[i];
    }
    avg_TAT=sum_TAT/n;
    avg_WT=sum_WT/n;
    printf("avg of TAT = %.2f\n",avg_TAT);
    printf("avg of WT = %.2f",avg_WT);
    return 0;
}
