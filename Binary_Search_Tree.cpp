#include<iostream>
using namespace std;

#define EMPTY -999999
#define max_ver 10000

class BST{
    int** tree;
    int ver;
    int root_ver;
public:
    BST();
    void insert(int);
    int locate(int);
    int get_root_ver(){return root_ver;}
    void show_BST();
};
BST::BST()
{
    tree=new int*[max_ver];
    tree[0]=NULL;
    ver=0;
    root_ver=0;
}
void BST::insert(int x)
{
    if(tree[root_ver]==NULL)
    {
        tree[ver]=new int[5]; // parent..left child..left index..right child..right index
        tree[ver][0]=x;
        for(int i=1;i<5;i++)
        {
            tree[ver][i]=EMPTY;
        }
        cout<<"Successfully inserted "<<x<<endl;
        ver++;
    }
    else
    {
        int temp_root=root_ver,child;
        while(1)
        {
            child=x<tree[temp_root][0]?1:3;
            if(tree[temp_root][child]==EMPTY)
            {
                tree[temp_root][child]=x;
                tree[temp_root][child+1]=ver;
                tree[ver]=new int[5];
                tree[ver][0]=x;
                for(int i=1;i<5;i++)
                {
                    tree[ver][i]=EMPTY;
                }
                ver++;
                cout<<"Successfully Inserted "<<x<<endl;
                break;
            }
            else
            {
                temp_root=tree[temp_root][child+1];
            }
        }
    }
}

int BST::locate(int x)
{
    int temp_root=root_ver,child;
    while(1)
    {
        if(tree[temp_root][0]==x)
        {
            return 1;
        }
        child=x<tree[temp_root][0]?1:3;
        if(tree[temp_root][child]==EMPTY)
        {
            return 0;
        }
        else
        {
            temp_root=tree[temp_root][child+1];
        }
    }
}
void BST::show_BST()
{
    cout<<"edges:\n";
    for(int i=0;i<ver;i++)
    {
        cout<<tree[i][0]<<' '<<tree[i][1]<<endl;
        cout<<tree[i][0]<<' '<<tree[i][3]<<endl;
    }
}

int main()
{
    int v,*val;
    cin>>v;
    val=new int[v];
    for(int i=0;i<v;i++)
    {
        cin>>val[i];
    }
    BST g;
    for(int i=0;i<v;i++)
    {
        g.insert(val[i]);
    }
    g.show_BST();
    cout<<g.locate(8)<<endl;
    cout<<g.locate(7)<<endl;
    cout<<g.locate(4)<<endl;
    return 0;
}