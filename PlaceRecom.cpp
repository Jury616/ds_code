//
// Created by 12544 on 2024/5/28.
//

#include"DatabaseIF.h"
#include <string >
#include <stack>
# include <iostream>

struct placeInfo {
    int number;//场所数量
    int distance[500];//各场所到当前场所的距离数组
    std:: string ** names;//场所名称的数组
    std:: string ** labels;//场所类别的数组
    std:: string ** introductions;//场所介绍的数组
};





class interface_place_choosing{//场所推荐接口类
public:

    virtual void init_toursite(int index) =0;
    virtual void set_current_place(int index) =0;//设定当前场所
    virtual int get_number_of_places(int index) =0;//返回该景点的场所数
    virtual struct placeInfo get_nearby_places(int index)=0;//用查找算法查找索引为index的场所周围的场所，并用冒泡排序算法按距离排序；
    virtual struct placeInfo filter_nearby_places(std :: string label)=0;//按类别过滤附近的场所；
    virtual struct placeInfo get_nearby_places_by_label(int index,std :: string label )=0;//用查找算法查找索引为index的场所周围的类别为label场所，并用冒泡排序算法按距离排序

};

class implement_place_choosing : public interface_place_choosing {//场所推荐实现类
public:

    int current_place;
    Database_IF * database ;
    struct ToursiteTopo a;
    struct placeInfo info;

    implement_place_choosing(Database_IF * this_database) {
        this-> database = this_database;
    }

    void init_toursite(int index) override {
        this->a =  *(database-> get_toursite_topo(index));
    }

    void set_current_place(int index) override {
        current_place = index;
    }

    int get_number_of_places(int index) override {
        return a.place_num;
    }

    struct placeInfo get_nearby_places(int index) override {
        //用查找算法查找索引为index的场所周围的场所，并用冒泡排序算法按距离排序；
        info.number = 0;
        for (int i = 0; i < a.place_num; i++) {
            if (a.adjacent_matrix[index][i] != -1) {
                info.number++;
                info.distance[info.number - 1] = a.adjacent_matrix[index][i];
                info.names[info.number - 1] = a.places[i]->get_name();
                info.labels[info.number - 1] = a.places[i]->get_label();
                info.introductions[info.number - 1] = a.places[i]->get_introduction(); // 假设没有介绍信息
            }
        }
        // 使用冒泡排序算法按距离排序
        for (int i = 0; i < info.number - 1; i++) {
            for (int j = 0; j < info.number - 1 - i; j++) {
                if (info.distance[j] > info.distance[j + 1]) {
                    std::swap(info.distance[j], info.distance[j + 1]);
                    std::swap(info.names[j], info.names[j + 1]);
                    std::swap(info.labels[j], info.labels[j + 1]);
                    std::swap(info.introductions[j], info.introductions[j + 1]);
                }
            }
        }
        return info; // 返回填充好的info
    }

    struct placeInfo filter_nearby_places(std::string label) override {
        //按类别过滤附近的场所；
        info.number = 0;
        for (int i = 0; i < a.place_num; i++) {
            if (a.adjacent_matrix[current_place][i] != -1 && *a.places[i]->get_label() == label) {
                info.number++;
                info.distance[info.number - 1] = a.adjacent_matrix[current_place][i];
                info.names[info.number - 1] = a.places[i]->get_name();
                info.labels[info.number - 1] = a.places[i]->get_label();
                info.introductions[info.number - 1] = a.places[i]->get_introduction(); // 假设没有介绍信息
            }
        }
        // 使用冒泡排序算法按距离排序
        for (int i = 0; i < info.number - 1; i++) {
            for (int j = 0; j < info.number - 1 - i; j++) {
                if (info.distance[j] > info.distance[j + 1]) {
                    std::swap(info.distance[j], info.distance[j + 1]);
                    std::swap(info.names[j], info.names[j + 1]);
                    std::swap(info.labels[j], info.labels[j + 1]);
                    std::swap(info.introductions[j], info.introductions[j + 1]);
                }
            }
        }
        return info; // 返回填充好的info
    }

    struct placeInfo get_nearby_places_by_label(int index, std::string label) override {
        //用查找算法查找索引为index的场所周围的类别为label场所，并用冒泡排序算法按距离排序
        info.number = 0;
        for (int i = 0; i < a.place_num; i++) {
            if (a.adjacent_matrix[index][i] != -1 && *a.places[i]->get_label() == label) {
                info.number++;
                info.distance[info.number - 1] = a.adjacent_matrix[index][i];
                info.names[info.number - 1] = a.places[i]->get_name();
                info.labels[info.number - 1] = a.places[i]->get_label();
                info.introductions[info.number - 1] = a.places[i]->get_introduction(); // 假设没有介绍信息
            }
        }
        // 使用冒泡排序算法按距离排序
        for (int i = 0; i < info.number - 1; i++) {
            for (int j = 0; j < info.number - 1 - i; j++) {
                if (info.distance[j] > info.distance[j + 1]) {
                    std::swap(info.distance[j], info.distance[j + 1]);
                    std::swap(info.names[j], info.names[j + 1]);
                    std::swap(info.labels[j], info.labels[j + 1]);
                    std::swap(info.introductions[j], info.introductions[j + 1]);
                }
            }
        }
        return info; // 返回填充好的info
    }
};
