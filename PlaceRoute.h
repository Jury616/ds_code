//
// Created by 12544 on 2024/5/20.
//

#ifndef DATASTR_PLACEROUTE_H
#define DATASTR_PLACEROUTE_H

#include"DatabaseIF.h"
#include"DatabaseIF.h"
#include <string >
# include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <fstream>
#include <random>
#include <time.h>

struct placeInfo { // 存储场所信息的结构
    int number; // 场所的数量
    int distance[500]; // 各场所到当前场所的距离数组
    std:: string *names[105]; // 存储场所名称的数组
    std:: string * labels[105]; // 存储场所类别的数组
    std:: string * introductions[105]; // 存储场所介绍的数组
};



struct path{ // 存储一条路径，路径的节点类型是场所
    Place * places[105]; // 存储路径的节点（场所）
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

class interface_place_navigation{//场所导航接口类
public:

    virtual void init_toursite(int index) =0;
    virtual  void set_current_place(int index) =0;
    virtual  struct path get_route(int destination) =0;
    virtual struct path get_route_mul(int destinations[], int cnt) =0;
    virtual void set_strategy_mode(int mode) =0;
    virtual void set_transport_mode(int mode) =0;
    virtual void reset_adjacency_matrix() =0;

};


class implement_place_navigation : public interface_place_navigation {
public:
    int current_place;
    Database_IF *database;
    struct ToursiteTopo a;
    struct path result_path;
    int strategyMode = 0;
    int transportMode = 0;

    implement_place_navigation(Database_IF *this_database) {
        this->database = this_database;
    }


    void init_toursite(int index) override {
        this->a = *(database->get_toursite_topo(index));
    }

    void set_current_place(int index) override {
        current_place = index;
    }

    void set_strategy_mode(int mode) override {
        strategyMode = mode;
    }

    void set_transport_mode(int mode) override {
        transportMode = mode;
    }

    void reset_adjacency_matrix() override {
        if ( strategyMode == 0){
            for (int i = 0; i < a.place_num; i++) {
                for (int j = 0; j < a.place_num; j++) {
                    if (transportMode == 0){
                        if( a.adjacent_matrix_walk[i][j] == 0){
                            a.adjacent_matrix[i][j] = 1000;
                        }else if(a.adjacent_matrix_walk[i][j] == 1){
                            a.adjacent_matrix[i][j] = a.adjacent_matrix[i][j] * 1;
                        }
                    }else if (transportMode == 1){
                        if(a.adjacent_matrix_bike[i][j] == 0){
                            a.adjacent_matrix[i][j] = 1000;
                        }else if(a.adjacent_matrix_bike[i][j] == 1){
                            a.adjacent_matrix[i][j] = a.adjacent_matrix[i][j] * 0.5;
                        }
                    }else if (transportMode == 2){
                        if(a.adjacent_matrix_ebike[i][j] == 0){
                            a.adjacent_matrix[i][j] = 1000;
                        }else if(a.adjacent_matrix_ebike[i][j] == 1){
                            a.adjacent_matrix[i][j] = a.adjacent_matrix[i][j] * 0.2;
                        }
                    }
                }
            }
        }else if(strategyMode == 1){
            for (int i = 0; i < a.place_num; i++) {
                for (int j = 0; j < a.place_num; j++) {
                    if (transportMode == 0){
                        if( a.adjacent_matrix_walk[i][j] == 0){
                            a.adjacent_matrix[i][j] = 1000;
                        }else if(a.adjacent_matrix_walk[i][j] == 1){
                            a.adjacent_matrix[i][j] = a.adjacent_matrix[i][j] * (0.1 + 0.01 * a.adjacent_matrix_congestion[i][j]);
                        }
                    }else if(transportMode == 1){
                        if(a.adjacent_matrix_bike[i][j] == 0){
                            a.adjacent_matrix[i][j] = 1000;
                        }else if(a.adjacent_matrix_bike[i][j] == 1){
                            a.adjacent_matrix[i][j] = a.adjacent_matrix[i][j] * (0.05 + 0.005 * a.adjacent_matrix_congestion[i][j]);
                        }
                    }else if(transportMode == 2){
                        if(a.adjacent_matrix_ebike[i][j] == 0){
                            a.adjacent_matrix[i][j] = 1000;
                        }else if(a.adjacent_matrix_ebike[i][j] == 1){
                            a.adjacent_matrix[i][j] = a.adjacent_matrix[i][j] * (0.02 + 0.002 * a.adjacent_matrix_congestion[i][j]);
                        }
                    }
                }
            }
        }
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
        result.num_places = path_places.size();
        std::copy(path_places.begin(), path_places.end(), result.places);
        return result;
    }

    struct path get_route_mul(int destinations[], int cnt) override {
        int n = a.place_num;
        std::vector<int> current_route(destinations, destinations + cnt);
        std::vector<int> best_route = current_route;
        double best_cost = EvaluateRoute(current_route, current_place);

        double T = 996.996;  // 初始温度
        double Tmin = 1e-7; // 最小温度
        double alpha = 0.99; // 降温系数

        std::default_random_engine generator(time(0));
        std::uniform_real_distribution<double> distribution(0.0, 1.0);

        while (T > Tmin) {
            for (int i = 0; i < 100; ++i) {
                // 随机选择两个位置并交换
                int pos1 = rand() % cnt;
                int pos2 = rand() % cnt;
                while (pos1 == pos2) {
                    pos2 = rand() % cnt;
                }
                std::swap(current_route[pos1], current_route[pos2]);

                double current_cost = EvaluateRoute(current_route, current_place);
                double delta_cost = current_cost - best_cost;

                if (delta_cost < 0 || distribution(generator) < exp(-delta_cost / T)) {
                    if (current_cost < best_cost) {
                        best_cost = current_cost;
                        best_route = current_route;
                    }
                } else {
                    // 恢复交换前的状态
                    std::swap(current_route[pos1], current_route[pos2]);
                }
            }
            T *= alpha;
        }

        std::vector<Place*> path_places;
        path_places.push_back(a.places[current_place]); // 加入起点
        for (int i = 0; i < cnt; ++i) {
            path_places.push_back(a.places[best_route[i]]);
        }
        path_places.push_back(a.places[current_place]); // 回到起点

        struct path result;
        result.num_places = path_places.size();
        std::copy(path_places.begin(), path_places.end(), result.places);
        return result;
    }

    double EvaluateRoute(const std::vector<int>& route, int start_place) {
        double total_distance = 0;
        total_distance += a.adjacent_matrix[start_place][route[0]]; // 从起点到第一个目的地
        for (size_t i = 0; i < route.size() - 1; ++i) {
            total_distance += a.adjacent_matrix[route[i]][route[i + 1]];
        }
        total_distance += a.adjacent_matrix[route.back()][start_place]; // 最后一个目的地回到起点
        return total_distance;
    }

};




#endif
