#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,i,j,k,count=0;

    cout<<"Please enter the no of processes and no of resource types:"<<endl;
    cin>>n>>m;

    int available[m],maximum[n][m],allocation[n][m],need[n][m],work[m],finish[n],safeseq[n];

    cout<<"Enter the available instances:"<<endl;
    for(i=0;i<m;i++)
    {
        cin>>available[i];
    }

    cout<<"Enter the max matrix:"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>maximum[i][j];
        }
    }

    cout<<"Enter the allocation matrix:"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>allocation[i][j];
        }
    }

    cout<<endl<<"Here the need matrix:"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=maximum[i][j]-allocation[i][j];
            cout<<need[i][j]<<' ';
        }
        cout<<endl;
    }

    for(i=0;i<m;i++)
    {
        work[i]=available[i];
    }

    for(i=0;i<n;i++)
    {
        finish[i]=0;
    }

    while(count<n)
    {
        int temp=0;
        for(i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>work[j])
                    {
                        break;

                    }
                }
                if(j==m)
                {
                    for(k=0;k<m;k++)
                    {
                        work[k]=work[k]+allocation[i][k];
                    }
                    safeseq[count++]=i;
                    finish[i]=1;
                    temp=1;
                }
            }
        }
        if(temp==0)
        {
            cout<<endl<<"System is not in safe state"<<endl;
            break;
        }
    }

    cout<<endl<<"System is in safe state"<<endl<<endl<<"The safe sequence is: < ";
    for (i=0;i<n;i++)
    {
        cout<<'P'<<safeseq[i]<<' ';
    }

    cout<<'>'<<endl<<endl<<"Total instance: { "<<' ';
    for(i=0;i<m;i++)
    {
        cout<<work[i]<<' ';
    }
    cout<<'}'<<endl;

    return 0;
}
