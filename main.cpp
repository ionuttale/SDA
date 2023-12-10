#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    size_t cols, rows, groups;
    std::cin>>cols>>rows>>groups;
    std::vector<std::unordered_set<uint16_t>> c(cols);
    std::vector<std::unordered_set<uint16_t>> r(rows);
    std::vector<std::unordered_set<uint16_t>> g(groups);
    //aux[0]- rows aux[1]- cols aux[2]- groups
    for(size_t i=0;i<rows;i++){
        for(size_t j=0;j<cols;j++){
            int x1, x2, x3, x4;
            std::cin>>x1>>x2>>x3>>x4;
            c[x1].insert(x4);
            r[x2].insert(x4);
            g[x3].insert(x4);
        }
    }
    for(size_t i=0;i<r.size();i++){
        if(c[i].size()!=cols || r[i].size()!=rows){
            std::cout<<0;
            exit(0);
        }
    }
    for(size_t i=0;i<g.size()-1;i++){
        if(g[i].size()!=g[i+1].size()){
            std::cout<<0;
            exit(0);
        }
    }
    std::cout<<1;
    return 0;
}
