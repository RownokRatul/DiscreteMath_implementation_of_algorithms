#include<iostream>
using namespace std;
void dfs(int **g,int **s_tree,int *taken,int cur,int &e,int v)
{
    if(e==v-1)
    {
        cout<<"Spanning Tree:\n";
        for(int i=0;i<v-1;i++)
        {
            cout<<s_tree[i][0]+1<<" "<<s_tree[i][1]+1<<endl;
        }
        return ;
    }
    taken[cur]=0;
    for(int i=0;i<v;i++)
    {
        if(e>=v-1)
        {
            break;
        }
        if(g[cur][i] && taken[i])
        {
            s_tree[e][0]=cur;
            s_tree[e][1]=i;
            e++;
            dfs(g,s_tree,taken,i,e,v);
        }
    }
}
int main()
{
    int e,v;
    int **g,*taken;
    cin>>v;
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
    cin>>e;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a-1][b-1]=1;
        g[b-1][a-1]=1;
    }
    int eSearch=0;
    dfs(g,s_tree,taken,0,eSearch,v);
    return 0;
}