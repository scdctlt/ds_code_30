#include <bits/stdc++.h>
using namespace std;
#define Maxsize 50
struct Sqlist
{
    int data[Maxsize];
    int length;
};

bool delete_same(Sqlist L){
    if (L.length==0)
    {
        return false;
    }
    int i,j;        //i存储第一个不同的元素，j为工作指针
    for (int j = 0; j < L.length; i++)
    {
        if (L.data[i]!=L.data[j])
        {
            L.data[++i]=L.data[j];
        }        
    }
    L.length=i+1;
    return true;
}