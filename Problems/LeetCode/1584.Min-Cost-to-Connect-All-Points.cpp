// https://leetcode.com/problems/min-cost-to-connect-all-points/

class Solution {
    class DSU {
        vector<int> par, siz;
    public:
        DSU(int n) {
            par.resize(n);
            iota(par.begin(), par.end(), 0);
            siz.resize(n, 1);
        }
        int findParent(int u) {
            return u == par[u]? u : par[u] = findParent(par[u]);
        }
        bool join(int u, int v) {
            u = findParent(u);
            v = findParent(v);
            if(u == v) return false;
            if(siz[v] > siz[u]) swap(u, v);
            par[v] = u;
            siz[u] += siz[v];
            siz[v] = 1;
            return true;
        }
    };

    struct Edge {
        int from, to, cost;
        Edge(int from, int to, int cost): from(from), to(to), cost(cost) {}
        bool operator <(const Edge& other) {
            return cost < other.cost;
        }
    };

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<Edge> edges;
        for(int i = 0; i < points.size(); ++i) {
            for(int j = i + 1; j < points.size(); ++j) {
                edges.emplace_back(i, j, distance(points[i], points[j]));
            }
        }
        sort(edges.begin(), edges.end());
        DSU dsu(points.size());
        int total_cost = 0;
        for(const Edge& edge : edges) {
            total_cost += dsu.join(edge.from, edge.to) * edge.cost;
        }
        return total_cost;
    }
    int distance(const vector<int>& p1, const vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
};
