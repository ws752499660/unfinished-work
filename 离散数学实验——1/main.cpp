#include <iostream>
using namespace std;

void creategraph(int **&g,int &n,int &m)
{
    cin>>n>>m;
    int i,j;
    g=new int*[n];
    for(i=0;i<n;i++)
        g[i]=new int[m];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            cin>>g[i][j];
}

bool DC_check(int **g,int n,int m)    //检测对称性
{
    int i=0,j=0;
    bool flag[6]={false};
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
    int i,flag=0;
    if(m>n) n=m;
    for(i=0;i<n;i++)
    {
        if(g[i][i]==1)
            flag++;
    }
    if(flag==n)
        return true;
    else
        return false;
}

bool CD_check(int **g,int n,int m)    //检测传递性
{
    int i,j,t;
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
    creategraph(g,n,m); //创建一个关系矩阵
    if(DC_check(g,n,m))
        cout<<"该关系具有对称性"<<endl;
    if(ZF_check(g,n,m))
        cout<<"该关系具有自反性"<<endl;
    if(CD_check(g,n,m))
        cout<<"该关系具有对称性"<<endl;
    return 0;
}
