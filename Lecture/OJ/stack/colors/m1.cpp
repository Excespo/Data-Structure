#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>
using namespace std;

const int INF=0x3f3f3f3f;
const double eps=1e-10;
const double PI=acos(-1.0);
#define maxn 1100
struct Sta
{
    char word[maxn];
    int cnt = 0;
};
Sta sta[100];
char a[1200];
int main()
{
    cin.getline(a,1200);
    {
        int k = 1;
        int cnt1 = 0;
        int cnt2 = 0;
        int cnt3 = 0;
        int j;
        for(int i = 0; a[i] != '\0'; i++)
        {
            if(a[i] == ' ')
                continue;
            int k1 = 0;
            int flag = 0;
            if(a[i]=='<')
            {
                k++;
                for(j = i+1; a[j] != '>'; j++)
                {
                    if(a[j]=='/')
                        flag = 1;
                    sta[k].word[k1++] = a[j];
                }
                
                sta[k].word[k1] = '\0';
                i=j;
                
                if(flag)
                {
                    if(strcmp(sta[k-1].word,"yellow")== 0)
                            cnt1 += sta[k-1].cnt;
                    if(strcmp(sta[k-1].word,"blue")== 0)
                            cnt2 += sta[k-1].cnt;
                    if(strcmp(sta[k-1].word,"red")== 0)
                            cnt3 += sta[k-1].cnt;
                    sta[k-1].cnt = sta[k].cnt = 0;
                    k=k-2;
                }
                continue;
            }
            sta[k].cnt++;
        }
           printf("%d %d %d\n", cnt3,cnt1,cnt2);
    }
    return 0;
}
/*<yellow>aaa<blue>bbb  </blue>ccc</yellow>dddd<red>abc</red>*/