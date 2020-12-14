#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>


/*
 ######################### 
# auto type                 
# sort_vector               
 ######################### 
*/


void populate(auto &data) {
    data.insert({"a",{1,4}});
    data.insert({"b",{3,1}});
    data.insert({"c",{2,3}});
}

auto merge(auto data, auto upcoming_data) {
    auto result = data;
    for (auto it: upcoming_data) {
        result.insert(it);
    }
    return result;
}

void create_map() {
    std::map<std::string, std::pair<int, int>> data;
    populate(data);

    std::map<std::string, std::pair<int, int>> upcoming_data;
    upcoming_data.insert({"d",{5,3}});
    upcoming_data.insert({"f",{1,1}});

    auto final_data = merge(data, upcoming_data);

    for (auto itr: final_data) {
        // [v1, v2] = // c++17
        auto [v1, v2] = itr.second;
        std::cout << itr.first << " " << v1 << " " << v2 << std::endl;
    }
}

void sort_vector() {
    std::vector<std::pair<int,int>> data = {{1, 3}, {7, 6}, {12, 4}};
    std::sort(std::begin(data), std::end(data), [](auto a, auto b) { 
        return (a.second < b.second); 
    });
    for (auto p: data) {
        std::cout << p.first << ", " << p.second << std::endl;
    }
}

/* ######################### */
/* lambda                    */
/* ######################### */


void lambda1() {
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7};
    int factor = 7;
    for_each( std::begin(data), std::end(data), [&factor](int &val){
        val = val + factor;
        factor--;
    });

    for(int val: data) {
        std::cout << val << " ";
    }
    std::cout << " - " << factor << std::endl;
}

/* ######################### */
/* Init statements inside if & switch */
/* ######################### */

void initStatementsInsideIF() {
    std::set<int> input = {1, 5, 7, 6};

    // initialize the variable and check inside the if
    if (auto it = input.find(7); it==input.end()) {
        std::cout << 7 << "not found!" << std::endl;
    }
    else {
        std::cout << 7 << " is there!" << std::endl;
    }
}

/*
 #########################
# constexpr function => if you get constant arguments, 
#  the compiler can precalculate the function at compile time
 #########################
*/

constexpr double fat(int n) {
    if (n == 1) return 1;
    return fat(n-1) * n;
}

void exampleConstexp() {
    const long long bigval = fat(20);
    std::cout << bigval << std::endl;
}