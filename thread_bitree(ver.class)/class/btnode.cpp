// Created by hasee on 2017/11/22.
//
#include <iostream>
#include "btnode.h"
using  namespace std;

//function of btnode----------

btnode::btnode(btnode *b)
{
    data=b->data;
    lk=b->lk;
    rk=b->rk;
}

void btnode::creatbt(btnode* &b)
{
    char c=getchar();
    if(c!='#')
    {
        btnode *t=new btnode;
        b=t;
        b->data=c-'0';
        creatbt(b->lk);
        creatbt(b->rk);
    }
    else
    {
        b=NULL;
    }
}

void btnode::visit(btnode *b)
{
    cout<<b->data<<" ";
}

void btnode::travel(btnode *b)
{
    if(b)
    {
        travel(b->lk);
        visit(b);
        travel(b->rk);
    }
}

void btnode::pointlk(btnode *lk)
{
    this->lk=lk;
}

void btnode::pointrk(btnode *rk)
{
    this->rk=rk;
}

btnode* btnode::returnlk()
{
    return this->lk;
}

btnode* btnode::returnrk()
{
    return this->rk;
}

//function of thbtnode-------------------

thbtnode::thbtnode(btnode *b):btnode(b)  //创建头结点
{
    if (b->returnlk())
        ltype = 1;
    else
        ltype = 0;
    if (b->returnrk())
        rtype = 1;
    else
        rtype = 0;
    this->pointrk(this);
    if(!b)
    {
        this->pointlk(this);
    }
    else
    {
        this->pointlk(b);
        thbtnode *pre=this;
        creatthbt(b,pre);
    }
}

void thbtnode::creatthbt(btnode* b,thbtnode* &pre)
{
    if(b)
    {
        creatthbt(b->returnlk(),pre);
        if(!b->returnlk())
        {

        }
    }
}