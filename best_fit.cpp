#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,N,i,j;

    cout<<"Please enter the no of memory partitions:"<<endl;
    cin>>n;

    int m[n];

    cout<<"Enter the sizes of memory partitions:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>m[i];
    }

    cout<<"Enter the no of processes:"<<endl;
    cin>>N;

    int p[N],a[N];

    cout<<"Enter the sizes of process memory:"<<endl;
    for(i=0;i<N;i++)
    {
        cin>>p[i];
    }

    for(i=0;i<N;i++)
    {
        int b=-1;
        for(j=0;j<n;j++)
        {
            if(m[j]>=p[i])
            {
                if(b==-1)
                {
                    b=j;
                }
                else if(m[b]>m[j])
                {
                    b=j;
                }
            }
        }
        if(b!=-1)
        {
            a[i]=b;
            m[b]=m[b]-p[i];
        }
        else
        {
            a[i]=-1;
        }
    }

    for(i=0;i<N;i++)
    {
        if(a[i]!=-1)
        {
            cout<<endl<<p[i]<<" takes "<<a[i]<<" index"<<endl;
        }
        else
        {
            cout<<endl<<p[i]<<" is invalid"<<endl;
        }
    }

    cout<<endl<<"The remaining memory of the partitions:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<m[i]<<' ';
    }
    cout<<endl;

    return 0;
}
