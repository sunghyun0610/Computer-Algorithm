💻Computer Algorithm mid-term assingment💻
===========================================
by 201901671 문성현
-----------------------
# List
- **1.Ford-Fulkerson 알고리즘 개념 및 설명**
    - *1-1. 네트워크 플로우 알고리즘 목적과 소개*
    - *1-2. 용어 정리(사전지식) 및 특징*
    - *1-3. Ford-Fulkerson 알고리즘 설명*
- 2.**Ford-Fulkerson 알고리즘 구현(C++) 및 동작방식 설명**
- **3.코드 결과 및 성능 분석**
- **4.개선점과 하면서 새로 배우고 느낀 점**

## 1-1 네트워크 플로우 알고리즘 목적과 소개
### 정의: 네트워크 플로우(Network Flow)는 특정한 지점에서 다른 지점으로 데이터가 얼마나 많이 흐르고 있는가를 측정하는 알고리즘이다.
#### 간단한 그림 예시로 이해를 돕겠다.
![Alt text](https://github.com/sunghyun0610/Computer-Algorithm/blob/main/%EB%84%A4%ED%8A%B8%EC%9B%8C%ED%81%AC%20%ED%94%8C%EB%A1%9C%EC%9A%B0.gif)
#### 위 사진에서 보이는 것과 같이 부평에서 10명을 보내면 인천대에서는 4명밖에 수용하지 못하기 때문에 성립되지않고 4명이하를 보내야 성립한다. 이를 네트워크에 적용해보면 간선들 중 유량의 최소값이 흐를 수 있는 최대유량이 된다.그 이상을 보내면 "정체현상:이 발생한다. 표현방식은 (유량=flow/용량=capacity)으로 표현한다.
#### 즉,네트워크 플로우는 시작점에서 도착점까지 유량을 최대로 흘려보내는 것이 목적이고 Ford-Fulkerson알고리즘은 최대유량을 구하는 알고리즘 중 하나이다.
## 1.2 용어 정리(사전지식) 및 특징
### 용어정리:  
- source :시작점
- sink : 도착점
- capacity : 용량
- flow : 유량
- c(a,b): 정점 a에서 b로, 소화 가능한(남은)용량 값
- f(a,b)정점 a에서 b로, 사용하고 있는(쓴)유량 값
### 네트워크 유량 알고리즘 특징:
1. 용량의 제한
- 각 간선에 흐르는 유량은 그 간선의 용량을 넘을 수 없다. f(a,b) <=c(a,b)
2. 유량의 보존
- 어떤 정점을 기준으로 보았을떄, 해당 정점에(들어오는 유량의 총합 == 나가는 유량의 총합) 예) a->b->c일때 , f(a,b)=f(b,c)
3. <u>**유량의 대칭(음의 유량)**</u>
- f(a,b)=5라고한다면 f(b,a)=-5이다. ->이게 가능한 이유는 b->a는 실제로는 없기 때문에 capacity는 0이라고 가정하기 때문. 즉,(a,b)로 이미 흐른 유량을 역방향으로 흐르는 양만큼 "취소"한다고 생각하면 될 것같다.
- 음의 유량개념을 적용함으로써 경로를 더 찾을 수 있게된다.

## 1.3 Ford-Fulkerson 알고리즘 설명
#### 그림 예시와 함께 Ford-Fulkerson알고리즘을 이해해 보겠다.
![logo](https://gseok.gitbooks.io/algorithm/content/assets/network-flow1.png)
***
**1. Source(출발점)에서 Sink(목적지)로 가는 경로를 찾는다.**
    <br>- 이떄 해당 경로에 반드시 용량이 남아 있어야 함.c(a,b)>f(a,b)
![logo](https://gseok.gitbooks.io/algorithm/content/assets/network-flow2.png)
### 경로 1)S->A->E->T를 찾았다.<br>경로를 찾는법은 정해져 있지 않다.(BFS사용: 에드먼 카프 , DFS사용:ford-fulkerson라한다.)
-----
**2. 찾아낸 경로에 보낼 수 있는 최대 flow 찾는다.**
    <br>-최대 flow는 경로상에 간선들의 남은 용량의 최솟값이라고 첫번째 그림에서 설명한적 있다.
    <br>![logo](https://gseok.gitbooks.io/algorithm/content/assets/network-flow3.png)
<br>S->A->E->T에서 최대 flow=3.
**<br>3. 찾아낸 경로에, 2에서 구한 최대 flow를 실제로 흘려보냄.**
<br>![logo](https://gseok.gitbooks.io/algorithm/content/assets/network-flow4.png)
<br> 현재 sink(T)에 도달한 유량은 3.
<br>**4. 경로를 더이상 찾지 못할때 까지 1~3과정 다시 반복한다**
![logo](https://gseok.gitbooks.io/algorithm/content/assets/network-flow6.png)
<br>최종 sink(T)까지 도달한 유량은 "9"이다.
<br>**5.실제 정답과 비교**
<br> 하지만 실제 정답은9가아니다. S->A->E의 값을 2로 줄이고 S->A->D->T에 1유량을 흘려준다. 그러면 S->C->F->E->T에 추가로 1의 유량을 더 흘려보낼 수 있다. 즉 Total 10의 유량이 나오게된다.
<br>![logo](https://gseok.gitbooks.io/algorithm/content/assets/network-flow7.png)
<br>즉 total 10이 되게 하려면:
<br> A->E의 유량을 3->2가되게 하고, 남은 유량 1을 A->E->T로 흐르게 하면 된다.
<br>이는 1.2-3번에서 설명한 유량의 대칭(음의 유량)을 이용하면 된다. 역간선이 존재한다 설정하고 다시한번 위의 (1~3)을 반복해보면
<br>![logo](https://gseok.gitbooks.io/algorithm/content/assets/network-flow12.png)
<br>역간선을 이용하면 S->C->F->E->A->D->T라는 새로운 증강경로를 찾을 수 있다. 1의 용량을 흘려보낼 수 있고,즉 최대유량은 10이된다.
## **2.Ford-Fulkerson 알고리즘 구현(C++) 및 동작방식 설명**
```C++
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
            for(int i=0;i<a[x].size();i++){ //너비우선탐색 !//
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
```
<br>여기까지 큐(queue)를 이용해서 ford-fulkerson알고리즘 구현
```C++
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
```
이상 코드끝.
<br>**3.코드 결과 및 성능 분석**
## 결과 출력 화면
![logo](https://github.com/sunghyun0610/Computer-Algorithm/blob/main/ford-fulkerson%20code/ford-fulkerson%20%EA%B2%B0%EA%B3%BC%ED%99%94%EB%A9%B4.png)
<br>시간복잡도
- ford-fulkerson: O((V+E)F)
- 에드몬카프: O(VE^2)

<br>**4.개선점과 하면서 느낀 점**
<br>우선 네트워크 플로우 알고리즘의 대표적인 2가지 ford-fulkerson 알고리즘과 에드먼카프 알고리즘이 모두 최대 유량을 구하는 알고리즘인 것은 이해를 했다. 하지만 ford-fulkerson알고리즘은 DFS(깊이 우선탐색),에드먼카프 알고리즘은BFS(너비 우선탐색)으로만 해야하는 것인가 정확하지 않았다. 내가 구현한 코드는 BFS로 구현하였는데 그럼 이건 ford-fulkerson알고리즘이 아닌것인가..? 그래서 DFS방법으로도 구현해봤다. 이것은 혼자힘으로는 버거워서 구글코드를 인용하겠다.
```
 public static int capacity[][];
    public static int flow[][];
    public static int path[]; // 
    public static boolean visited[];
    public static LinkedList<Integer> graph[];

    public static boolean dfs(int start) {
        if (start == Sink) {
            return true;
        }

        visited[start] = true;
        LinkedList<Integer> nexts = graph[start];
        for (int next: nexts) {
            if ( !visited[next] && capacity[start][next] - flow[start][next] > 0) {
                path[next] = start;

                if (dfs(next)) { // 경로를 끝까지 찾으면 탈출, 아니면, 끝까지 찾기 재시도
                    return true;
                }
            }
        }
        return false;
    }
     // O((V+E)F)
    public static int FordFulkerson() {
        int total = 0;
        while (dfs(Source)) { // dfs로 경로 찾기(증가경로), 경로가 더이상 없으면 종료임.
            // 찾은 경로에서 차단 간선 찾기 min (capacity[u][v] - flow[u][v])
            // 결국 의미는 경로에서 흘릴수 있는 최대의 유량(flow)을 찾기
            int flowNum = Integer.MAX_VALUE;
            for(int i = Sink; i != Source; i = path[i]) {
                int from = path[i];
                int to = i;
                flowNum = Math.min(flowNum, (capacity[from][to]) - flow[from][to]);
            }
            // 찾은 경로에 유량을 흘려보내기, 역방향도 반드시!!!!
            for(int i = Sink; i != Source; i = path[i]) {
                int from = path[i];
                int to = i;

                flow[from][to] += flowNum;
                flow[to][from] -= flowNum;
            }

            total += flowNum;

            // 찾은 경로를 초기화해서 dfs로 경로 찾기를 Source > Sink 까지 다시 할 수 있게 함.
            Arrays.fill(path, -1);
            Arrays.fill(visited, false);
        }
        return total;
    }
  ```
  DFS를 이용해 ford-fulkerson구현 코드
  <br>출처 https://gseok.gitbooks.io/algorithm/content/b124-d2b8-c6cc-d06c-d50c-b85c-c6b0/d3ec-b4dc-d480-cee4-c2a828-ford-fulkerson-c560-b4dc-baac-b4dc-ce74-d50428-edmonds-karp.html
  <br>부족하지만 읽어주셔서 감사합니다!^___^ 이상 201901671 문성현.