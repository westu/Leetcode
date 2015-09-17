// hdu 5438
// Author: Jinyu Tsan

#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
const int Nodes_num = 10000 + 5;

class Node {
private:
    int v;
public:
    vector<int> link_nodes;
    int pipes_num;
    bool is_deleted, is_counted; //BFS with tag to avoid search one node twice
    Node() {
        link_nodes.clear();
        pipes_num = 0;
        is_deleted = false;
        is_counted = false;
    }
    Node(int v) {
        this->v = v;
        link_nodes.clear();
        pipes_num = 0;
        is_deleted = false;
        is_counted = false;
    }
    ~Node() {
        // Todo
    }
    void set_v(int v) {
        this->v  = v;
    }
    void add_link_node(int no) {
        link_nodes.push_back(no);
    }
    int get_v() {
        return v;
    }
};

class Graph {
private:
    int nodes_num;
    Node nodes[Nodes_num];

    void get_part_v(long long &part_v, int &part_num, int n) {
        queue<int> part_nodes;
        part_nodes.push(n); 
        nodes[n].is_counted = true;
        while(!part_nodes.empty()) {
            int node = part_nodes.front(); 
            part_nodes.pop();

            part_num += 1;
            part_v += (long long)nodes[node].get_v();
            for(vector<int>::iterator it = nodes[node].link_nodes.begin(); 
                    it != nodes[node].link_nodes.end(); it++)
                if (nodes[*it].pipes_num >= 2 && !nodes[*it].is_counted) {
                    part_nodes.push(*it);
                    nodes[*it].is_counted = true; 
                }
        }
    }
public:
    Graph(int n) {
        nodes_num = n;
    }
    ~Graph() {
        // Todo
    }
    void set_node_v(int n, int v) {
        nodes[n].set_v(v);
    }
    void add_node_link_node(int n, int no) {
        nodes[n].add_link_node(no);
        nodes[n].pipes_num += 1;
        nodes[no].add_link_node(n);
        nodes[no].pipes_num += 1;
    }
    void delete_ponds() {
        queue<int> delete_wait_list;
        for (int i = 1; i <= nodes_num; i++) 
            if (nodes[i].pipes_num < 2 && !nodes[i].is_deleted) {
                delete_wait_list.push(i);
                nodes[i].is_deleted = true;
                while  (!delete_wait_list.empty()) {
                    int delete_now_node = delete_wait_list.front();
                    delete_wait_list.pop();

                    for(vector<int>::iterator it = nodes[delete_now_node].link_nodes.begin(); 
                                it != nodes[delete_now_node].link_nodes.end(); it++) {
                        nodes[*it].pipes_num -= 1;
                        if (nodes[*it].pipes_num < 2 && !nodes[*it].is_deleted) {
                            delete_wait_list.push(*it);
                            nodes[*it].is_deleted = true;
                        }
                    }
                }
        }
    }
    long long get_left_v() {
        long long ans = 0;
        for (int i = 1; i <= nodes_num; i++) 
            if (nodes[i].pipes_num >= 2 && !nodes[i].is_counted) {
                long long part_v = 0;
                int part_num = 0;
                get_part_v(part_v, part_num, i);
                // cout << part_v << ' ' << part_num << endl;
                if (part_num % 2 == 1) {
                    ans += part_v;
                }
        }

        return ans;
    }
};

int main() {
    //freopen("a.txt", "r", stdin);
    int case_num;
    scanf("%d", &case_num);
    while(case_num--) {
        int n, m;
        scanf("%d%d", &n, &m);
        Graph graph(n);
        for (int i = 1; i <= n; i++) {
            int v;
            scanf("%d", &v);
            graph.set_node_v(i, v);
        }
        for (int i = 1; i <= m; i++) {
            int p, q;
            scanf("%d%d", &p, &q);
            graph.add_node_link_node(p, q);
        }
        graph.delete_ponds();
        cout << graph.get_left_v() << endl;
    }

    return 0;
}
