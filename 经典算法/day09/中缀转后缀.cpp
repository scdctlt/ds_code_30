#include<bits/stdc++.h>
using namespace std;

void transfer(){
    int top=-1,i,V[300];
    char Stack[999],R[999];
    V['(']=0,V['+']=V['-']=1,V['*']=V['/']=2,V['^']=3;
    scanf("%d",R);
    for (int i = 0; R[i] !='\0'; i++)
    {
        //如果是小写字母，直接输出
        if (R[i]>'a'&&R[i]<='z') printf("%c",R[i]);
        //若是左括号，直接入栈
        else if(R[i]=='(') Stack[++top] = R[i];
        //若是右括号，则输出栈内元素，直到栈顶元素是左括号，之后将左括号出栈（但不输出）
        else if(R[i]==')'){
            while (Stack[top]!='(') printf("%c",Stack[top--]);
            top--;            
        }
        else{
            //若是操作符且该操作符优先级小于等于栈顶操作符优先级
            //输出栈顶元素，直到栈空或者该操作符优先级比栈顶操作符优先级高
            while (top!=-1&&V[R[i]]<=V[Stack[top]])
            {
                printf("%c",Stack[top--]);
            }
            Stack[++top] = R[i];
        }
    }
    //输出栈内剩余元素
    while (top!=1) printf("%c",Stack[top--]);
    printf("\n");    
}
