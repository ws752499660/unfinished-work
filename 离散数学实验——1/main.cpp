#include <iostream>
using namespace std;

struct node
{
    int data;   //Ԫ������
    int loc;    //Ԫ���ڼ����е�λ�ã��±꣩
};

int pickloc(int data,node *l,int n) //����һ��Ԫ���ҳ����ڼ����е�λ��
{
    for(int i=0;i<n;i++)
        if(l[i].data==data)
            return l[i].loc;
}

void creategraph(int **&g,int n,int m)  //����һ��n*m�Ķ�άָ��
{
    int i;
    g=new int*[n];
    for(i=0;i<n;i++)
        g[i]=new int[m];
}

void createlist(int &n,int &m,int **&g) //�����������Ϣ������ϵ����
{
    cout<<"�����뼯��1������2��Ԫ�ظ�����"<< endl;
    cin>>n>>m;
    int i;
    node *l1=new node[n];   //��ż����и���Ԫ�ؽṹ�������
    node *l2=new node[m];
    cout<<"�����뼯��1��Ԫ��"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>l1[i].data;
        l1[i].loc=i;
    }
    cout<<"�����뼯��2��Ԫ��"<<endl;
    for(i=0;i<m;i++)
    {
        cin>>l2[i].data;
        l2[i].loc=i;
    }
    creategraph(g,n,m);
    cout<<"�������ϵ������:"<<endl;
    int t;
    cin>>t;
    cout<<"�������ϵ��"<<endl;
    int put1,put2; //���������ϵ
    for(i=0;i<t;i++)
    {
        cin>>put1>>put2;
        int q=pickloc(put1,l1,n);
        int p=pickloc(put2,l2,m);
        g[q][p]=1;
    }
}

bool DC_check(int **g,int n,int m)    //���Գ���
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

bool ZF_check(int **g,int n,int m)    //����Է���
{
    int i,flag=0;   //flag���ڼ���Ƿ��ϵ�е�ÿһ��Ԫ�ض����Է���ϵ
    if(m>n) n=m;
    for(i=0;i<n;i++)
    {
        if(g[i][i]==1)
            flag++; //����⵽һ���Է��Ĺ�ϵʱ��flag+1
    }
    if(flag==n)
        return true;
    else
        return false;
}

bool CD_check(int **g,int n,int m)    //��⴫����
{
    int i,j,t;  //i����ǰ��Ԫ���±꣬j��������к�i�й�ϵ��Ԫ�ص��±꣬t�Ǻ�j�й�ϵ��Ԫ�ص��±�
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
    createlist(n,m,g); //����һ����ϵ����
    if(DC_check(g,n,m))
        cout<<"�ù�ϵ���жԳ���"<<endl;
    if(ZF_check(g,n,m))
        cout<<"�ù�ϵ�����Է���"<<endl;
    if(CD_check(g,n,m))
        cout<<"�ù�ϵ���д�����"<<endl;
    return 0;
}