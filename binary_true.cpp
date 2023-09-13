#include<iostream>
using namespace std;
const int N = 28;
char pre[N];
char mid[N];
char post[N];


void solve(int PreL, int MidL, int PostL, int n)
{
    if(n == 0) return;//没有子树
    if(n == 1) {
       post[PostL] = pre[PreL]; //有一个子树叶子
       return;
    }
    post[PostL + n - 1] = pre[PreL];//先序的头pre[PreL]为root放在后序的最后
    
    int i;
    for(i = 0; i < n ; i ++)
    {
        if(mid[MidL + i] == pre[PreL]) break;
    }
    int L = i;//左子树的大小
    int R = n - L - 1; //右子树的大小，-1为减去root
    
    //分治递归
    solve(PreL + 1, MidL, PostL, L);
    solve(PreL + 1 + L, MidL + L + 1, PostL + L, R);
    
}

int main(){
    cin >> pre;
    // cout << pre;
    cin >> mid;
    cin >> post;
    int l =0;
    while(pre[l] != '\0') ++l;
    // cout << l;
    solve(0, 0, 0, l);
    cout << post;
}
