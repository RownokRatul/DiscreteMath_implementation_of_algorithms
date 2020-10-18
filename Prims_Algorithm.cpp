#include<iostream>
using namespace std;
#define INF 99999999
int** prim(int **g,int e,int v)
{
    int *ver=new int[v];
    for(int i=0;i<v;i++)
    {
        ver[i]=1;
    }
    int *take=new int[e];
    for(int i=0;i<e;i++)
    {
        take[i]=1;
    }
    
    int **min_tree=new int*[v-1];
    min_tree[0]=new int[2];

    int min=g[0][2],a=g[0][0],b=g[0][1],idx=0;
    for(int i=0;i<e;i++)
    {
        if(min>g[i][2])
        {
            a=g[i][0];
            b=g[i][1];
            min=g[i][2];
            idx=i;
        }
    }
    min_tree[0][0]=a;
    min_tree[0][1]=b;
    take[idx]=0;
    ver[a]=ver[b]=0;

    for(int i=1;i<v-1;i++)
    {
        min=INF,idx=0;
        min_tree[i]=new int[2];
        for(int j=0;j<e;j++)
        {
            if(min>g[j][2] && take[j] && (ver[g[j][0]] ^ ver[g[j][1]]))
            {
                min=g[j][2];
                a=g[j][0];
                b=g[j][1];
                idx=j;
            }
        }
        min_tree[i][0]=a;
        min_tree[i][1]=b;
        ver[a]=ver[b]=0;
        take[idx]=0;
    }
    return min_tree;
}
int main()
{
    int v,e;
    cin>>v>>e;
    int **edge=new int*[e];
    for(int i=0;i<e;i++)
    {
        edge[i]=new int[3];
        for(int j=0;j<3;j++)
        {
            cin>>edge[i][j];
        }
    }
    int** min_stree=prim(edge,e,v);
    for(int i=0;i<v-1;i++)
    {
        for(int j=0;j<2;j++)
            cout<<min_stree[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}