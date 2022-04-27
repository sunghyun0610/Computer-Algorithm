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
### 경로 1)S->A->E->T를 찾았다.<br>경로를 찾는법은 정해져 있지 않다.(BFS:너비 우선 탐색 or DFS:깊이 우선 탐색 이용)
-----
**2. 찾아낸 경로에 보낼 수 있는 최대 flow 찾는다.**
    <br>-최대 flow는 경로상에 간선들의 남은 용량의 최솟값이라고 첫번째 그림에서 설명한적 있다.
    <br>![logo](https://gseok.gitbooks.io/algorithm/content/assets/network-flow3.png)
<br>S->A->E->T에서 최대 flow=3.
**<br>3. 찾아낸 경로에, 2에서 구한 최대 flow를 실제로 흘려보냄.**
<br>![logo](https://gseok.gitbooks.io/algorithm/content/assets/network-flow4.png)
### 현재 sink(T)에 도달한 유량은 3.


 