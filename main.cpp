#include <iostream>
#include <set>

int main() {
    std::multiset<int> mult;
    int x;
    while(std::cin>>x){
        mult.emplace(x);
    }
    while(mult.size()>1){
        if(*mult.rbegin() != *(++mult.rbegin())){
            int aux = *mult.rbegin() - *(++mult.rbegin());
            mult.erase((std::prev(mult.end())));
            mult.erase((std::prev(mult.end())));
            mult.insert(aux);
            continue;
        }
        mult.erase((std::prev(mult.end())));
        mult.erase((std::prev(mult.end())));
    }
    if(mult.size()==0){
        std::cout<<-1;
    }
    else {
        std::cout << *mult.begin();
    }
    return 0;
}
