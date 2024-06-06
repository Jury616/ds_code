//
// Created by 12544 on 2024/5/28.
//

#include"DatabaseIF.h"
#include <string >
# include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

struct placeInfo { // 存储场所信息的结构
    int number; // 场所的数量
    int distance[500]; // 各场所到当前场所的距离数组
    std:: string ** names; // 存储场所名称的数组
    std:: string ** labels; // 存储场所类别的数组
    std:: string ** introductions; // 存储场所介绍的数组
};



struct path{ // 存储一条路径，路径的节点类型是场所
    Place ** places; // 存储路径的节点（场所）
    int num_places; // 路径的节点数
};


class PriorityQueue {
public:
    PriorityQueue() {}

    bool empty() const {
        return heap.empty();
    }

    void push(std::pair<int, int> element) {
        heap.push_back(element);
        sift_up(heap.size() - 1);
    }

    std::pair<int, int> top() const {
        if (empty()) {
            throw std::runtime_error("PriorityQueue is empty");
        }
        return heap[0];
    }

    void pop() {
        if (empty()) {
            throw std::runtime_error("PriorityQueue is empty");
        }
        std::swap(heap[0], heap.back());
        heap.pop_back();
        sift_down(0);
    }

private:
    std::vector<std::pair<int, int>> heap;

    void sift_up(size_t idx) {
        while (idx > 0) {
            size_t parent_idx = (idx - 1) / 2;
            if (heap[idx].first >= heap[parent_idx].first) {
                break;
            }
            std::swap(heap[idx], heap[parent_idx]);
            idx = parent_idx;
        }
    }

    void sift_down(size_t idx) {
        size_t left_child, right_child, min_idx;
        while ((left_child = 2 * idx + 1) < heap.size()) {
            right_child = left_child + 1;
            min_idx = idx;
            if (heap[left_child].first < heap[min_idx].first) {
                min_idx = left_child;
            }
            if (right_child < heap.size() && heap[right_child].first < heap[min_idx].first) {
                min_idx = right_child;
            }
            if (min_idx == idx) {
                break;
            }
            std::swap(heap[idx], heap[min_idx]);
            idx = min_idx;
        }
    }
};




class implement_place_navigation : public interface_place_navigation {
public:
    int current_place;
    Database_IF *database;
    struct ToursiteTopo a;
    struct path result_path;

    implement_place_navigation(Database_IF *this_database) {
        this->database = this_database;
    }

    void init_toursite(int index) override {
        this->a = *(database->get_toursite_topo(index));
    }

    void set_current_place(int index) override {
        current_place = index;
    }

    struct path get_route(int destination) override {
        int n = a.place_num;
        std::vector<int> dist(n, INT_MAX);
        std::vector<int> prev(n, -1);
        dist[current_place] = 0;
        PriorityQueue pq;
        pq.push({0, current_place});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (d > dist[u]) continue;

            for (int v = 0; v < n; ++v) {
                if (a.adjacent_matrix[u][v] != INT_MAX) {
                    int alt = d + a.adjacent_matrix[u][v];
                    if (alt < dist[v]) {
                        dist[v] = alt;
                        prev[v] = u;
                        pq.push({alt, v});
                    }
                }
            }
        }

        std::vector<Place*> path_places;
        for (int at = destination; at != -1; at = prev[at]) {
            path_places.push_back(a.places[at]);
        }
        std::reverse(path_places.begin(), path_places.end());

        struct path result;
        result.places = new Place*[path_places.size()];
        result.num_places = path_places.size();
        std::copy(path_places.begin(), path_places.end(), result.places);
        return result;
    }

    struct path get_route_mul(int destinations[], int cnt) override {
        int n = a.place_num;
        int all = (1 << cnt) - 1;
        std::vector<std::vector<int>> dp(1 << cnt, std::vector<int>(cnt, INT_MAX));
        std::vector<std::vector<int>> prev(1 << cnt, std::vector<int>(cnt, -1));
        std::vector<int> start_dist(cnt, INT_MAX);

        for (int i = 0; i < cnt; ++i) {
            start_dist[i] = a.adjacent_matrix[current_place][destinations[i]];
            dp[1 << i][i] = start_dist[i];
        }

        for (int mask = 0; mask < (1 << cnt); ++mask) {
            for (int u = 0; u < cnt; ++u) {
                if (!(mask & (1 << u))) continue;
                for (int v = 0; v < cnt; ++v) {
                    if (mask & (1 << v)) continue;
                    int next_mask = mask | (1 << v);
                    int dist = dp[mask][u] + a.adjacent_matrix[destinations[u]][destinations[v]];
                    if (dist < dp[next_mask][v]) {
                        dp[next_mask][v] = dist;
                        prev[next_mask][v] = u;
                    }
                }
            }
        }

        int end = -1, min_cost = INT_MAX;
        for (int i = 0; i < cnt; ++i) {
            int cost = dp[all][i] + a.adjacent_matrix[destinations[i]][current_place];
            if (cost < min_cost) {
                min_cost = cost;
                end = i;
            }
        }

        std::vector<Place*> path_places;
        for (int i = end, mask = all; i != -1; i = prev[mask][i]) {
            path_places.push_back(a.places[destinations[i]]);
            mask ^= (1 << i);
        }
        std::reverse(path_places.begin(), path_places.end());

        struct path result;
        result.places = new Place*[path_places.size() + 1];
        result.num_places = path_places.size() + 1;
        std::copy(path_places.begin(), path_places.end(), result.places);
        result.places[path_places.size()] = a.places[current_place];

        return result;
    }
};
