//
// Created by 董子雄 on 2022/6/29.
//

#ifndef LEETCODE_CPP_HEADER_TEMPLATE_H
#define LEETCODE_CPP_HEADER_TEMPLATE_H

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <set>
#include <bitset>

#define um unordered_map
#define pq priority_queue
#define fr(x) freopen(x, "r", stdin)
#define fw(x) freopen(x, "w", stdout)
#define cont continue
#define _CRT_SECURE_NO_WARNINGS 1

using ll = long long;
using ull = unsigned long long;
using namespace std;

// 回文串
bool check(std::string a) {
    std::string b = a;
    reverse(a.begin(), a.end());
    return b == a;
}

//并查集
class UF {
public:
    std::vector<int> parents;
    int cnt;

    UF(int n) {
        cnt = n;
        for (int i = 0; i < n; i++)
            parents.push_back(i);
    };

    int find(int i) {
        std::cout << i << " " << parents[i] << std::endl;
        if (parents[i] != i) return parents[i] = find(parents[i]);
        return parents[i];
    }

    void un(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj) return;
        parents[ri] = rj;
        cnt--;
    }

    int count() {
        return cnt;
    }

    bool connected(int p, int q){
        return find(p) == find(q);
    }
};

// 最小生成树
class Prim{
private:
    class Edge{
    public:
        int from, to, weight;
        Edge(int f, int t, int w){
            from = f; to = t; weight = w;
        }
    };

    struct cmp{
        bool operator()(Edge &a,Edge &b){
            return a.weight > b.weight;
        }
    };

    std::priority_queue<Edge, std::vector<Edge>, cmp> pq;
    std::bitset<1001> inMST; std::vector<std::vector<Edge>> graph;
    int weightSum = 0;

    void push(int s){
        inMST[s] = true;
        for (auto x:graph[s]){
            if (inMST[x.to]) continue;
            pq.push(x);
        }
    }

    void init(int n){
        while (!pq.empty()) pq.pop();
        weightSum = 0;
        for (int i = 0; i < n; i++) inMST[i] = false;
    }
public:
    int prim(const std::vector<std::vector<int>>& g){
        init(g.size());
        graph = build_points(g); int n = graph.size();

        push(0);
        while (!pq.empty()){
            Edge edge = pq.top(); pq.pop();
            if (inMST[edge.to]) continue;
            weightSum += edge.weight;
            push(edge.to);
        }
        return weightSum;
    }

    std::vector<std::vector<Edge>> build_points(const std::vector<std::vector<int>> &points){
        std::vector<std::vector<Edge>> g(points.size());
        for (int i = 0; i < points.size(); i++){
            for (int j = i+1; j < points.size(); j++){
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                g[i].push_back(Edge(i, j, weight));
                g[j].push_back(Edge(j, i, weight));
            }
        }
        return g;
    }
};

// 差分数组
class Difference{
public:
    std::vector<int> diff;
    Difference(std::vector<int> &nums) {
        // 根据初始数组构造差分数组
        diff.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            diff.push_back(nums[i] - nums[i - 1]);
        }
    }

    Difference(int n){
        for (int i = 0; i < n; i++){
            diff.push_back(0);
        }
    }

    void increment(int i, int j, int val) {
        diff[i] += val;
        if (j + 1 < diff.size()) {
            diff[j + 1] -= val;
        }
    }

    std::vector<int> get() {
        std::vector<int> res;
        // 根据差分数组构造结果数组
        res.push_back(diff[0]);
        for (int i = 1; i < diff.size(); i++) {
            res.push_back(res[i - 1] + diff[i]);
        }
        return res;
    }
};

// dijkstra
class dijkstra{
private:
    class Edge{
    public:
        int to, weight;
        Edge(int t, int w){
            to = t; weight = w;
        }
    };

    class State{
    public:
        int id, weight;
        State(int i, int w){
            id = i; weight = w;
        }
    };

    struct cmp{
        bool operator()(State &a,State &b){
            return a.weight > b.weight;
        }
    };

    std::vector<std::vector<Edge>> build_times(int n, const std::vector<std::vector<int>> &times){
        std::vector<std::vector<Edge>> graph(n+1);
        for (auto x:times){
            graph[x[0]].push_back(Edge(x[1], x[2]));
        }
        return graph;
    }
public:
    std::vector<int> Dijkstra(int n, int start, const std::vector<std::vector<int>> &times){
        std::vector<std::vector<Edge>> graph = build_times(n, times);
        std::vector<int> dist(n+1, INT_MAX);
        std::priority_queue<State, std::vector<State>, cmp> pq;

        dist[start] = 0;
        pq.push(State(start, 0));
        while (!pq.empty()){
            State state = pq.top(); pq.pop();
            int Dist = state.weight;
            if (Dist > dist[state.id]) continue;

            for (auto neighbor: graph[state.id]){
                int Dist2 = Dist + neighbor.weight;
                if (dist[neighbor.to] > Dist2){
                    dist[neighbor.to] = Dist2;
                    pq.push(State(neighbor.to, Dist2));
                }
            }
        }
        return dist;
    }
};

// 等于
template<typename A, typename B>
bool eq(A a, B b) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

std::string to_string(std::string v) {
    return '"' + v + '"';
}

// exgcd
template<typename A, typename B>
ull exgcd(A a, B b, A& x, B& y) {
    if (b == 0)
    {
        x = 1; y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    int temp = y;
    y = x - (a / b) * y;
    x = temp;
    return r;
}

// to_string大集合
template<typename A>
std::string to_string(A v) {
    bool first = true;
    std::string res = "{";
    for (const auto& x : v) {
        if (!first)
            res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template<typename A>
std::string to_string(std::map<A,A> v) {
    bool first = true;
    std::string res = "{";
    for (const auto& x : v) {
        if (!first)
            res += ", ";
        first = false;
        res += to_string(x.first);
        res += ":";
        res += to_string(x.second);

    }
    res += "}";
    return res;
}

std::string to_string(char* a) {
    std::string res = a;
    return '"'+res+'"';
}

// gcd
template<typename A,typename B>
inline ull gcd(A a, B b) {
    return b > 0 ? gcd(b, a % b) : a;
}

// 文件操作
std::vector<std::string> read(const char *name) {
    if (fr(name) == NULL) {
        std::cout << "\a";
        abort();
    }
    std::vector<std::string> r;
    std::string a;
    while (getline(std::cin, a))
    {
        r.push_back(a);
    }
    fclose(stdin);
    return r;
}

bool write(const char *name,const char* mode, std::string text) {
    if (freopen(name, mode, stdout) == NULL) {
        std::cout << "\a";
        return false;
    }
    std::cout << text;
    return true;
}

// 快速冥
ull quick_pow(ull x, ull n, ull m) {
    ull res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}

#endif //LEETCODE_CPP_HEADER_TEMPLATE_H
