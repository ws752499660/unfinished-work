//
// Created by hasee on 2017/11/22.
//

#ifndef THREAD_BITREE_VER_CLASS_BTNODE_H
#define THREAD_BITREE_VER_CLASS_BTNODE_H

#include <iostream>
#include <cstdio>

using namespace std;

typedef thbtnode *thbitree;
typedef btnode *bitree;

class btnode
{
private:
    int data;
    btnode *lk,*rk;
public:
    btnode(){data=0;lk=NULL;rk=NULL;}
    btnode(btnode *b);
    static void creatbt(btnode* &b);
    void travel(btnode* b);
    void visit(btnode* b);
    void pointlk(btnode *lk);
    void pointrk(btnode *rk);
    btnode* returnlk();
    btnode* returnrk();
};

class thbtnode : public btnode
{
private:
    int ltype, rtype;    //type=1--link;type=0--thread
    thbtnode():btnode(){ltype=0;rtype=0;}
    thbtnode(btnode *b);
public:
    void
    void creatthbt(btnode *b,thbtnode* &tb);
    void travelthbt(bitree *b,thbtnode *tb);
};

#endif //THREAD_BITREE_VER_CLASS_BTNODE_H
