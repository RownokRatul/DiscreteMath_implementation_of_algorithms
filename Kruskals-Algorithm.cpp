#include<iostream>
using namespace std;
#define INF 99999999
int** kruskal(int **g,int e,int v)
{
    int tree_no=1;
    int *ver=new int[v];
    for(int i=0;i<v;i++)
    {
        ver[i]=0;
    }
    int *take=new int[e];
    for(int i=0;i<e;i++)
    {
        take[i]=0;
    }
    
    int **min_tree=new int*[v-1];
    for(int i=0;i<v-1;i++)
    {
        int min=INF,a=0,b=0;
        int idx=0,t=0,change_t=0;
        min_tree[i]=new int[2];
        for(int j=0;j<e;j++)
        {
            if(min>g[j][2] && !take[j])
            {
                if(ver[g[j][0]] && ver[g[j][1]]) //both non zero
                {
                    if(ver[g[j][0]] != ver[g[j][1]])
                    {
                        idx=j;
                        min=g[j][2];
                        t=ver[g[j][0]];
                        change_t=ver[g[j][1]];
                        a=g[j][0];
                        b=g[j][1];
                    }
                }
                else if(!ver[g[j][0]] && !ver[g[j][1]]) //both zero
                {
                    idx=j;
                    min=g[j][2];
                    a=g[j][0];
                    b=g[j][1];
                    t=tree_no;
                }
                else
                {
                    idx=j;
                    min=g[j][2];
                    a=g[j][0];
                    b=g[j][1];
                    t=ver[g[j][0]]?ver[g[j][0]]:ver[g[j][1]];
                }
            }
        }
        min_tree[i][0]=a;
        min_tree[i][1]=b;
        take[idx]=1;
        if(t==tree_no)
        {
            tree_no++;
        }
        if(change_t)
        {
            for(int k=0;k<v;k++)
            {
                ver[k]=(ver[k]==change_t)?t:ver[k];
            }
        }
        else
        {
            ver[g[idx][0]]=ver[g[idx][1]]=t;
        }
    }
    for(int i=0;i<v;i++)
    {
        cout<<ver[i]<<' ';
    }
    cout<<endl;
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
    int** min_stree=kruskal(edge,e,v);
    for(int i=0;i<v-1;i++)
    {
        for(int j=0;j<2;j++)
            cout<<min_stree[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
