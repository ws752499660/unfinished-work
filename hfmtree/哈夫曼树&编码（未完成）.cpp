#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

typedef struct htnode
{
    int weight;     //权
    int parent,lkid,rkid;   //"指针"
}*huffmantree;

typedef char **huffmancode;

void select(huffmantree ht,int n,int &s1,int &s2)
{
    int min=ht[1].weight;
    s1=1;
    for(int i=1;i<=n;i++)
    {
        if(min>ht[i].weight && ht[i].parent==0)
        {
            min=ht[i].weight;
            s1=i;
        }
    }
    int min2=ht[1].weight;
    s2=2;
    for(int i=1;i<=n;i++)
    {
        if(ht[i].weight==min)
            continue;
        if(min2>ht[i].weight && ht[i].parent==0)
        {
            min2=ht[i].weight;
            s2=i;
        }
    }
}

void create_huffmantree(huffmantree ht,int *w,int n)
{
    if(n<=1)
        return;
    int m=2*n-1;
    ht=new htnode[m+1]; //No.0 will not be used but as a head node.
    int i;
    for(i=1;i<=n;i++)
    {
        ht[i].weight=w[i-1];
        ht[i].parent=0;
        ht[i].lkid=0;
        ht[i].rkid=0;
    }
    for(;i<=m;i++)
    {
        ht[i].weight=0;
        ht[i].parent=0;
        ht[i].lkid=0;
        ht[i].rkid=0;
    }
    int s1,s2;
    for(i=n+1;i<=m;i++)
    {
        select(ht,n,s1,s2);
        ht[s1].parent=i;
        ht[s2].parent=i;
        ht[i].lkid=s1;
        ht[i].rkid=s2;
        ht[i].weight=ht[s1].weight+ht[s2].weight;
    }
    //ofstream out ("E:\\WS\\hfmtree.txt");
    for(i=1;i<=m;i++)
    {
        cout<<ht[i].weight<<" ";
    }
    cout<<endl;
    for(i=1;i<=m;i++)
    {
        cout<<ht[i].parent<<" ";
    }
    cout<<endl;
    for(i=1;i<=m;i++)
    {
        cout<<ht[i].lkid<<" ";
    }
    cout<<endl;
    for(i=1;i<=m;i++)
    {
        cout<<ht[i].rkid<<" ";
    }
}

void create_huffmancode(huffmantree ht,huffmancode &hc,int n)
{

    hc=new char*[n+1];
    char *cd=new char[n]; //code workspace
    cd[n-1]='\0';
    for(int i=1;i<=n;i++)
    {
        int start=n-1;
        int c=i,f=ht[i].parent;
        while(f!=0)
        {
            if(ht[f].lkid==c)
                cd[start]='0';
            else
                cd[start]='1';
            start--;
            c=f;
            f=ht[c].parent;
        }
        hc[i]=new char[n-start];
        strcpy(hc[i],&cd[start]);
    }
    delete(cd);
}

int main()
{
    int n,*w;
    cin>>n;
    w=new int[n];
    char *cline=new char[n];
    for(int i=0;i<n;i++)
        cin>>w[i];
    cin>>cline;
    huffmantree ht;
    create_huffmantree(ht,w,n);
    return 0;
}