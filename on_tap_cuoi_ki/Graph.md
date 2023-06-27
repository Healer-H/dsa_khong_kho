# Lý thuyết đồ thị

## Mã giả BFS

Đồ thị $G(V, E)$ với $v = |V|$ là số đỉnh có trong đồ thị G.
Duyệt theo chiều ngang với đỉnh bắt đầu là $source$

```
# declared
adj[u]: danh sach dinh ke voi dinh u
visited[u]: danh dau dinh u da tham hay chua
queue<vertex> BFS
vector<vertex> ans

# init
visited[1..v] <-- false
BFS.push(source)
ans.push_back(souce)
visited[source] = true

# excute
while: BFS.empty() == false // BFS con chua rong
    top = BFS.front()
    for: vertex : adj[top]
        if: visited[vertex] == false:
            visited[vertex] = true
            BFS.push(vertex)
            ans.push_back(vertex)
    BFS.pop()

print(ans)

```
## Mã giả DFS

```
adj[u]: danh sach dinh ke voi dinh u
visited[u]: danh dau dinh u da tham hay chua
stack<vertex> DFS
vector<vertex> ans

# init
visited[1..v] <-- false
DFS.push(source)
ans.push_back(souce)
visited[source] = true

#excute
while: DFS.empty() == false
    top = DFS.top()
    bool flag = false // flag = true: vẫn còn đỉnh chưa được thăm
    for vertex : adj[top]:
        if visited[vertex] == false:
            visited[vertex] = true
            DFS.push(vertex)
            ans.push_back(vertex)
            flag = true
            break
    if: flag == false
        DFS.pop()
            

```