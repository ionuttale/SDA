#include "Patient.h"
#include "PriorityQueue.h"
#include <iostream>

int main() {
    PriorityQueue<struct Patient> patients(10);
    std::string buffer;
    struct Patient aux;
    while(std::cin>>buffer){
        if(buffer=="+"){
            std::cin>>aux.firstName>>aux.lastName>>aux.age>>aux.gender;
            uint32_t priority;
            std::cin>>priority;
            patients.push(aux, priority);
            continue;
        }
        if(buffer=="-"){
            aux=patients.pop();
            std::cout<<aux.firstName<<" "<<aux.lastName<<" "<<aux.age<<" "<<aux.gender<<std::endl;
            continue;
        }
        if(buffer=="*"){
            break;
        }
    }
    return 0;
}