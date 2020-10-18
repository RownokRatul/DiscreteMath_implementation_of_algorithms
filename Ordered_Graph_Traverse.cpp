#include<iostream>
#include<cstdlib>
using namespace std;

void pre_order(int** g,int v,int* p,int *taken,int root,int &idx)
{
    p[idx]=root;
    taken[root]=0;
    cout<<(char)(p[idx]+'a')<<' ' ;
    for(int i=0;i<v;i++)
    {
        if(g[root][i] && taken[i])
        {
            pre_order(g,v,p,taken,i,++idx);
        }
    }  
}

void post_order(int** g,int v,int* p,int *taken,int root,int &idx)
{
    taken[root]=0;
    for(int i=0;i<v;i++)
    {
        if(g[root][i] && taken[i])
        {
            post_order(g,v,p,taken,i,idx);
            idx++;
        }
    }
    p[idx]=root;
    cout<<(char)(p[idx]+'a')<<' ';
}

void in_order(int** g,int v,int* p,int* taken,int root,int &idx)
{
    taken[root]=0;
    for(int i=0;i<v;i++)
    {
        if(g[root][i] && taken[i])
        {
            in_order(g,v,p,taken,i,idx);
            idx++;
            break;
        }
    }
    p[idx]=root;
    cout<<(char)(p[idx]+'a')<<' ';
    for(int i=0;i<v;i++)
    {
        if(g[root][i] && taken[i])
        {
            in_order(g,v,p,taken,i,++idx);
        }
    }
}

int main()
{
    int **g,v,e,*taken,idx=0;
    cin>>v>>e;
    g=new int*[v];
    taken=new int[v];
    for(int i=0;i<v;i++)
    {
        taken[i]=1;
        g[i]=new int[v];
    }
    for(int i=0;i<e;i++)
    {
        char a,b;
        cin>>a>>b;
        g[a-'a'][b-'a']=1;
        g[b-'a'][a-'a']=1;
    }
    int *p_order=new int[v];
    
    //pre_order(g,v,p_order,taken,0,idx);
    /*for(int i=0;i<v;i++)
    {
        cout<<(char)(p_order[i]+'a')<<' ';
    }*/
    //cout<<endl;
    
    //idx=0;
    //post_order(g,v,p_order,taken,0,idx);
    /*for(int i=0;i<v;i++)
    {
        cout<<(char)(p_order[i]+'a')<<' ';
    }*/
    //cout<<endl;
    
    //idx=0;
    in_order(g,v,p_order,taken,0,idx);
    /*for(int i=0;i<v;i++)
    {
        cout<<(char)(p_order[i]+'a')<<' ';
    }*/
    cout<<endl;
    return 0;
}