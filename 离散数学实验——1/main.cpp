#include <iostream>
using namespace std;

struct node
{
    int data;   //元素自身
    int loc;    //元素在集合中的位置（下标）
};

int pickloc(int data,node *l,int n) //根据一个元素找出其在集合中的位置
{
    for(int i=0;i<n;i++)
        if(l[i].data==data)
            return l[i].loc;
}

void creategraph(int **&g,int n,int m)  //创建一个n*m的二维指针
{
    int i;
    g=new int*[n];
    for(i=0;i<n;i++)
        g[i]=new int[m];
}

void createlist(int &n,int &m,int **&g) //根据输入的信息创建关系矩阵
{
    cout<<"请输入集合1，集合2的元素个数："<< endl;
    cin>>n>>m;
    int i;
    node *l1=new node[n];   //存放集合中各个元素结构体的数组
    node *l2=new node[m];
    cout<<"请输入集合1的元素"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>l1[i].data;
        l1[i].loc=i;
    }
    cout<<"请输入集合2的元素"<<endl;
    for(i=0;i<m;i++)
    {
        cin>>l2[i].data;
        l2[i].loc=i;
    }
    creategraph(g,n,m);
    cout<<"请输入关系的数量:"<<endl;
    int t;
    cin>>t;
    cout<<"请输入关系："<<endl;
    int put1,put2; //用于输入关系
    for(i=0;i<t;i++)
    {
        cin>>put1>>put2;
        int q=pickloc(put1,l1,n);
        int p=pickloc(put2,l2,m);
        g[q][p]=1;
    }
}

bool DC_check(int **g,int n,int m)    //检测对称性
{
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(g[i][j]==1 && g[j][i]==0)
                return false;
            if(g[i][j]==0 && g[j][i]==1)
                return false;
        }
    }
    return true;
}

bool ZF_check(int **g,int n,int m)    //检测自反性
{
    int i,flag=0;   //flag用于检测是否关系中的每一个元素都有自反关系
    if(m>n) n=m;
    for(i=0;i<n;i++)
    {
        if(g[i][i]==1)
            flag++; //当检测到一个自反的关系时，flag+1
    }
    if(flag==n)
        return true;
    else
        return false;
}

bool CD_check(int **g,int n,int m)    //检测传递性
{
    int i,j,t;  //i代表当前的元素下标，j代表遍历中和i有关系的元素的下标，t是和j有关系的元素的下标
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(g[i][j]==1 && i!=j)
            {
                for(t=0;t<m;t++)
                {
                    if(g[j][t]==1 && g[i][t]==0)
                        return false;
                }
            }
    return true;
}

int main() {
    int **g;
    int n,m;
    createlist(n,m,g); //创建一个关系矩阵
    if(DC_check(g,n,m))
        cout<<"该关系具有对称性"<<endl;
    if(ZF_check(g,n,m))
        cout<<"该关系具有自反性"<<endl;
    if(CD_check(g,n,m))
        cout<<"该关系具有传递性"<<endl;
    return 0;
}