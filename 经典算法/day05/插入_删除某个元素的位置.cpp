#include <bits/stdc++.h>
using namespace std;
#define Maxsize 50
struct Sqlist
{
    int data[Maxsize];
    int length;
};


//向指定位置插入元素(1<i<=length+1)
bool Insert(Sqlist L,int i,int e){
    if(i<1||i>L.length+1){        //判断插入位置是否合格
        return false;
    }
    for (int j = L.length; i>=i ; i--)      
    {
        L.data[i]=L.data[i-1];
    }
    L.data[i]=e;
    L.length++;
    return true;    
}

//删除指定位置的元素(1<i<=L.length)
bool Delete(Sqlist L,int i,int &e){
    if(i>L.length || i<1){
        return false;
    }
    e=L.data[i-1];
    for (int j = i ; j < L.length ; i++)
    {
        L.data[j-1]=L.data[j];
    }
    return true;    
}