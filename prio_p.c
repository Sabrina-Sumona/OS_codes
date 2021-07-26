#include<stdio.h>
int main()
{
    int AT[10],BT[10],Prio[10],RT[10];
    int n,i,j,endTime,smallest,remain=0,time,pos,temp;
    float sum_TAT=0.0,sum_WT=0.0,avg_TAT=0.0,avg_WT=0.0;
    printf("Enter the no. of process:\n");
    scanf("%d",&n);

    printf("Now enter the Priority, AT and BT one by one:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&Prio[i]);
        scanf("%d",&AT[i]);
        scanf("%d",&BT[i]);
        RT[i]=BT[i];
    }
    printf("PNO\tPrio\tAT\tBT\tCT\tTAT\tWT\n");
    Prio[9]=9999;
    for(time=0;remain!=n;time++)
    {
        smallest=9;
        for(i=0;i<n;i++)
        {
            if(AT[i]<=time && Prio[i]<Prio[smallest] && RT[i]>0)
            {
                smallest=i;
            }
        }
        RT[smallest]--;
        if(RT[smallest]==0)
        {
            remain++;
            endTime=time+1;
            printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",smallest+1,Prio[smallest],AT[smallest],BT[smallest],endTime,endTime-AT[smallest],endTime-BT[smallest]-AT[smallest]);
            sum_TAT=sum_TAT+(endTime-AT[smallest]);
            sum_WT=sum_WT+(endTime-BT[smallest]-AT[smallest]);
        }
    }
    avg_TAT=sum_TAT/n;
    avg_WT=sum_WT/n;
    printf("avg of TAT = %.2f\n",avg_TAT);
    printf("avg of WT = %.2f",avg_WT);
    return 0;
}
