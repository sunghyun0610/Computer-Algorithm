#include <iostream>
#include <vector>
#include <queue>

#define MAX 100
#define INF 1000000000

using namespace std;//C++ 문법을 쓴다 선언
int n=8,result;//노드개수 8개 와 최대유량 결과변수//
int c[MAX][MAX],f[MAX][MAX],d[MAX];//c:capacity,f:flow,d:노드 방문했는지 확인해줌//
vector<int> a[MAX];//간선들 연결//
void maxFlow(int begin, int end){
    while(1){
        fill(d,d+MAX,-1);
        queue<int> q;
        q.push(begin);
        while(!q.empty()){
            int x=q.front();
            q.pop();//큐 구현 함수
            for(int i=0;i<a[x].size();i++){//너비우선탐색 !//
                int y=a[x][i];
                if(c[x][y]-f[x][y]>0&&d[y]==-1){//방문하지 않은 노드 중 용량이 남은경우 탐색//
                    q.push(y);
                    d[y]=x;//경로를 저장한다!.//
                    if(y==end) break;//도착지에 도달한 경우//
                }
            }
        }
        if(d[end]==-1) break;
        int flow=INF;
        for(int i=end;i!=begin;i=d[i]){
            flow=min(flow,c[d[i]][i]-f[d[i]][i]);
            //최대유량 찾는 함수 min//
        }
        for(int i=end;i!=begin;i=d[i]){
            f[d[i]][i]+=flow;
            f[i][d[i]]-=flow;//음의 유량 고려해주기!//
        }
        result+=flow;
    }
}

int main(void){
    //S=1,A=2,B=3,C=4,D=5,E=6,F=7,T=8
    //S->A:3
    a[1].push_back(2);
    a[2].push_back(1);
    c[1][2]=3;
    //S->B:4
    a[1].push_back(3);
    a[3].push_back(1);
    c[1][3]=4;
    //S->C:5
    a[1].push_back(4);
    a[4].push_back(1);
    c[1][4]=5;
    //A->D:1
    a[2].push_back(5);
    a[5].push_back(2);
    c[2][5]=1;
    //A->E:3
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
    //F->E:1
    a[7].push_back(6);
    a[6].push_back(7);
    c[7][6]=1;
    //D->T:3
    a[5].push_back(8);
    a[8].push_back(5);
    c[5][8]=3;
    //E->T:5
    a[6].push_back(8);
    a[8].push_back(6);
    c[6][8]=5;
    //F->T:4
    a[7].push_back(8);
    a[8].push_back(7);
    c[7][8]=4;

    maxFlow(1,8);
    printf("최대 유량:%d",result);
    return 0;

}//드디어 최대유량 10 구했다!//