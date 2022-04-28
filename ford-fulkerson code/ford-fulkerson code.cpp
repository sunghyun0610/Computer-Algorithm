#include <iostream>
#include <vector>
#include <queue>

#define MAX 100
#define INF 1000000000

using namespace std;//C++ ������ ���� ����
int n=8,result;//��尳�� 8�� �� �ִ����� �������//
int c[MAX][MAX],f[MAX][MAX],d[MAX];//c:capacity,f:flow,d:��� �湮�ߴ��� Ȯ������//
vector<int> a[MAX];//������ ����//
void maxFlow(int begin, int end){
    while(1){
        fill(d,d+MAX,-1);
        queue<int> q;
        q.push(begin);
        while(!q.empty()){
            int x=q.front();
            q.pop();//ť ���� �Լ�
            for(int i=0;i<a[x].size();i++){//�ʺ�켱Ž�� !//
                int y=a[x][i];
                if(c[x][y]-f[x][y]>0&&d[y]==-1){//�湮���� ���� ��� �� �뷮�� ������� Ž��//
                    q.push(y);
                    d[y]=x;//��θ� �����Ѵ�!.//
                    if(y==end) break;//�������� ������ ���//
                }
            }
        }
        if(d[end]==-1) break;
        int flow=INF;
        for(int i=end;i!=begin;i=d[i]){
            flow=min(flow,c[d[i]][i]-f[d[i]][i]);
            //�ִ����� ã�� �Լ� min//
        }
        for(int i=end;i!=begin;i=d[i]){
            f[d[i]][i]+=flow;
            f[i][d[i]]-=flow;//���� ���� ������ֱ�!//
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
    printf("�ִ� ����:%d",result);
    return 0;

}//���� �ִ����� 10 ���ߴ�!//