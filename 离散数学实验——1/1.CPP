#include <iostream>
using namespace std;

int g[6][6]={   //存放各元素间关系的矩阵
        1,0,1,1,0,1,
        0,1,0,1,1,1,
        0,0,1,0,0,1,
        0,0,0,1,0,1,
        0,0,0,0,1,1,
        0,0,0,0,0,1
};

bool DC_check(int g[6][6])
{
    int i=0,j=0;
    bool flag[6]={false};
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if(g[i][j]==1 && g[j][i]==0)
                return false;
            if(g[i][j]==0 && g[j][i]==1)
                return false;
        }
    }
    return true;
}

bool ZF_check(int g[6][6])
{
    int i,flag=0;
    for(i=0;i<6;i++)
    {
        if(g[i][i]==1)
            flag++;
    }
    if(flag==6)
        return true;
    else
        return false;
}

bool CD_check(int g[6][6])
{
    int i,j,t;
    for(i=0;i<6;i++)
        for(j=0;j<6;j++)
            if(g[i][j]==1 && i!=j)
            {
                for(t=0;t<6;t++)
                {
                    if(g[j][t]==1 && g[i][t]==0)
                        return false;
                }
            }
    return true;
}

int main() {
    if(DC_check(g))
        cout<<"CD"<<endl;
    if(ZF_check(g))
        cout<<"ZF"<<endl;
    if(CD_check(g))
        cout<<"CD"<<endl;
    return 0;
}
