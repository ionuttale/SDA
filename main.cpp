#include <iostream>
#include <unordered_set>

int hammingDist(std::string s1, std::string s2){
    int nr=0;
    for(int i=0;i<s1.size();i++){
        if(s1[i]!=s2[i]){
            nr++;
        }
    }
    return nr;
}

int main() {
    std::unordered_multiset<std::string> words;
    std::string begin, end, aux;
    std::cin>>begin>>end;
    while(std::cin>>aux){
        words.insert(aux);
    }
    aux=begin;
    bool k=true;
    while(begin!=end){
        if(!k || words.empty()) {
            std::cout << 0;
            return 0;
        }
        for(std::string i : words) {
            if (hammingDist(i, begin) == 1) {
                aux += " -> ";
                aux += i;
                if(words.count(begin)){
                    words.erase(begin);
                }
                begin = i;
                k = true;
                words.erase(i);
                break;
            }
            k = false;
        }
    }
    std::cout<<aux<<'\n';
    return 0;
}
