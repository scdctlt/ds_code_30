#include<bits/stdc++.h>
using namespace std;
#define MaxSize 50
struct Sqlist
{
    int data[MaxSize];
    int length;
};

bool merge(Sqlist L1,Sqlist L2,Sqlist &L3){
    if (L1.length+L2.length>L3.length)
    {
        return false;
    }
    int i=0,j=0,k=0;
    while (i<L1.length&&j<L2.length)        //循环两两比较，小者存入结果表中，直到有一个表比较完为止
    {
        if (L1.data[i]<=L2.data[j])
        {
            L3.data[k++]=L1.data[i++];
        }
        else
        {
            L3.data[k++]=L2.data[j++];
        }    
    }
    while (i<L1.length)
    {
        L3.data[k++]=L1.data[i++];
    }
    while (j<L2.length)
    {
        L3.data[k++]=L2.data[j++];
    } 
    L3.length=k;
    return true;
}
