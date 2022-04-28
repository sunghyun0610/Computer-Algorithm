#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 100
#define INF 1000000000

using namespace std;//C++ 문법을 쓴다 선언
int n=8 ,result;//노드개수 8개 와 최대유량 결과변수//
int c[MAX][MAX],f[MAX][MAX],d[MAX];//c:capacity,f:flow,d:노드 방문했는지 확인해줌//
vector<int> a[MAX];
void maxFlow(int start,int end){
    while(1){
        fill(d,d+MAX,-1);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i=0;i<a[x].size();i++){
                int y=a[x][i];
                if(c[x][y]-f[x][y]>0&&d[y]==-1){
                    q.push(y);
                    d[y]=x;
                    if(y==end) break;
                }
            }
        }
        if(d[end]==-1) break;
        int flow=INF;
        for(int i=end;i !=start;i=d[i]){
            flow=min(flow,c[d[i]][i]-f[d[i]][i]);
        }
        for(int i=end;i!=start;i=d[i]){
            f[d[i]][i]+=flow;
            f[i][d[i]]-=flow;
        }
        result+=flow;

    }
}

//S=1,A=2,B=3,C=4,D=5,E=6,F=7,T=8//
int main(void){
    //S->A :3
    a[1].push_back(2);
    a[2].push_back(1);
    c[1][2]=3;
    //S->B:4
    a[1].push_back(3);
    a[3].push_back(1);
    c[1][3]=4;
    //S->c:5
    a[1].push_back(4);
    a[4].push_back(1);
    c[1][4]=5;
    //A->D:1
    a[2].push_back(5);
    a[5].push_back(2);
    c[2][5]=1;
    //A->E :3
    a[2].push_back(6);
    a[6].push_back(2);
    c[2][6]=3;
    //B->E:2
    a[3].push_back(6);
    a[6].push_back(3);
    c[3][6]=2;
    //C->F:7
    a[4].push_back(7);
    a[7].push_back(4);
    c[4][7]=7;
    //D->T:3
    a[5].push_back(8);
    a[8].push_back(5);
    a[5][8]=3;
    //E->T:5
    a[6].push_back(8);
    a[8].push_back(6);
    c[6][8]=5;
    //F->E:1
    a[7].push_back(6);
    a[6].push_back(7);
    c[7][6]=1;
    //F->T:4
    a[7].push_back(8);
    a[8].push_back(7);
    c[7][8]=4;


    maxFlow(1,8);
    printf("%d",result);
    return 0;

}