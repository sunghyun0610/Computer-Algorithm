💻Computer Algorithm mid-term assingment💻
===========================================
by 201901671 문성현
-----------------------
## List
- 1.Ford-Fulkerson 알고리즘 개념 및 설명
    - 1-1. 네트워크 플로우 알고리즘과 용어 정리(사전지식)
    - 1-2. 프로그램의 목적
    - 1-3. Ford-Fulkerson 알고리즘 설명
- 2.Ford-Fulkerson 알고리즘 구현(C++) 및 동작방식 설명
- 3.코드 결과 및 성능 분석
- 4.개선점과 하면서 느꼈던 점

## 1-1 네트워크 플로우 알고리즘과 용어 정리(사전지식)
#### 정의: 네트워크 플로우(Network Flow)는 특정한 지점에서 다른 지점으로 데이터가 얼마나 많이 흐르고 있는가를 측정하는 알고리즘이다.
#### 간단한 그림 예시로 이해를 돕겠다.
![Alt text](https://github.com/sunghyun0610/Computer-Algorithm/blob/main/%EB%84%A4%ED%8A%B8%EC%9B%8C%ED%81%AC%20%ED%94%8C%EB%A1%9C%EC%9A%B0.gif)
<img src=" https://github.com/sunghyun0610/Computer-Algorithm/blob/main/%EB%84%A4%ED%8A%B8%EC%9B%8C%ED%81%AC%20%ED%94%8C%EB%A1%9C%EC%9A%B0.gif " height="200px" width="300px">
#### 위 사진에서 보이는 것과 같이 부평에서 10명을 보내면 인천대에서는 4명밖에 수용하지 못하기 때문에 성립되지않고 4명이하를 보내야 성립한다. 이를 네트워크에 적용해보면 간선들들 중 최소값이 흐를 수 있는 최대유량이 된다. 표현방식은 (유량=flow/용량=capacity)으로 표현한다.

