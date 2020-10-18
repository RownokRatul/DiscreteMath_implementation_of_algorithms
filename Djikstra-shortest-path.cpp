#include<iostream>
using namespace std;
int mn(int a,int b)
{
    return a<b?a:b;
}
void djikstra(int **g,int *ver,int *cost,int s,int v)
{
    int count=0,nxt_idx=s-1;
    cost[s-1]=0;
    for(;count<v;count++)
    {
        ver[nxt_idx]=0;
        for(int i=0;i<v;i++)
        {
            if(g[nxt_idx][i] && ver[i])
            {
                if(cost[i]==-1)
                {
                    cost[i]=g[nxt_idx][i]+cost[nxt_idx];
                }
                else
                {
                    cost[i]=mn(cost[i],g[nxt_idx][i]+cost[nxt_idx]);
                }
            }
        }
        int mn=9999999,temp;
        for(int i=0;i<v;i++)
        {
            if(ver[i] && cost[i] != -1 && mn >= cost[i])
            {
                mn=cost[i];
                temp=i;
            }
        }
        nxt_idx=temp;
    }
}
int main()
{
    int v,e;
    cin>>v>>e;
    int **g,*ver,*cost;
    g=new int*[v];
    ver=new int[v];
    cost=new int[v];
    for(int i=0;i<v;i++)
    {
        ver[i]=1;
        cost[i]=-1;
        g[i]=new int[v];
        for(int j=0;j<v;j++)
        {
            g[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        g[a-1][b-1]=w;
        g[b-1][a-1]=w;
    }
    int source;
    cin>>source;
    djikstra(g,ver,cost,source,v);
    for(int i=0;i<v;i++)
    {
        cout<<i+1<<": "<<cost[i]<<'\t';
    }
    cout<<endl;
    return 0;
}