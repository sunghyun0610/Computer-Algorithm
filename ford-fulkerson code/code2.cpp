#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
const int INF = 123456789;
void set_graph(std::vector<std::vector<int>>& graph, const int u, const int v, const int c)
{
graph[u][v] = c;
graph[v][u] = -c;
}
bool bfs(const int s, const int t, const int n, const std::vector<std::vector<int>>& graph, std::vector<int>& prev, std::vector<bool>& visited)
{
// init value
for (int i = 0; i < n; i++)
visited[i] = false;
// create a queue for BFS
std::queue<int> q;
// mark s node as visited and enqueue it
q.push(s);
visited[s] = true;
int u{};
while (!q.empty()) {
u = q.front();
q.pop();
// get adjacent vertices
for (int v = 0; v < n; v++) {
if (visited[v] == false && graph[u][v] > 0) {
q.push(v);
visited[v] = true;
prev[v] = u;
}
}
}
return visited[t];
}
int edmonds_karp(const int source, const int sink, const int n, std::vector<std::vector<int>>& graph)
{
std::vector<bool> visited;
std::vector<int> prev;
// init value
visited.resize(n, false);
prev.resize(n, -1);
int max_flow{ 0 };
int path_flow{}, s{}, u{}, v{};
while (bfs(source, sink, n, graph, prev, visited)) {
path_flow = INF;
// find minimum capacity of the edges along the path by BFS
s = sink;
while (s != source) {
path_flow = std::min(path_flow, graph[prev[s]][s]);
s = prev[s];
}
// add path flow to overall flow
max_flow += path_flow;
// update residual copacities of the edges and reverse edges along the path
v = sink;
while (v != source) {
u = prev[v];
graph[u][v] -= path_flow;
graph[v][u] += path_flow;
v = prev[v];
}
}
return max_flow;
}
int main(int argc, char* argv[])
{
std::vector<std::vector<int>> graph;
// set graph
int n = 7; // source:0, sink:6
graph.resize(n, std::vector<int>(n, 0));
set_graph(graph, 0, 1, 2); // s-a
set_graph(graph, 0, 2, 1); // s-b
set_graph(graph, 0, 3, 4); // s-c
set_graph(graph, 1, 4, 2); // a-d
set_graph(graph, 2, 4, 1); // b-d
set_graph(graph, 3, 5, 5); // c-e
set_graph(graph, 4, 3, 1); // d-c
set_graph(graph, 4, 5, 0); // d-e
set_graph(graph, 4, 6, 2); // d-t
set_graph(graph, 5, 6, 5); // e-t
// start
auto result = edmonds_karp(0, n - 1, n, graph);
std::cout << "Maximum flow: " << result << "\n";
}

