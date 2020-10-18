#include<iostream>
using namespace std;
void bfs(int** g,int** s_tree,int* taken,int v)
{
    int edge=0,stack[v],idx=0;
    stack[idx++]=0;
    while(idx>0)
    {
        int temp=stack[--idx];
        cout<<temp<<endl;
        taken[temp]=0;
        for(int j=0;j<v;j++)
        {
            if(g[temp][j] && taken[j])
            {
                stack[idx++]=j;
                s_tree[edge][0]=temp;
                s_tree[edge++][1]=j;
                taken[j]=0;
            }
        }
    }
    cout<<"Spanning Tree:\n";
    for(int i=0;i<edge;i++)
    {
        cout<<s_tree[i][0]+1<<' '<<s_tree[i][1]+1<<endl;
    }
}

int main()
{
    int e,v;
    int **g,*taken;
    cin>>v>>e;
    g=new int*[v];
    taken=new int[v];
    for(int i=0;i<v;i++)
    {
        taken[i]=1;
        g[i]=new int[v];
        for(int j=0;j<v;j++)
        {
            g[i][j]=0;
        }
    }
    int **s_tree=new int*[v-1];
    for(int i=0;i<v-1;i++)
    {
        s_tree[i]=new int[2];
    }
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a-1][b-1]=1;
        g[b-1][a-1]=1;
    }
    bfs(g,s_tree,taken,v);
    return 0;
}