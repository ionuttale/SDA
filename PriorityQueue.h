/** ************************************************************************
 *
 * Fisier header pentru functiile necesare pentru cozile cu prioritati.
 *
 ***************************************************************************/

#pragma once

#include <cstdint>
#include <queue>
#include <unordered_map>

template <class T>
class PriorityQueue {
    std::unordered_map<uint32_t, std::queue<T>> mPatients;
    uint32_t mKey=0;
public:
    PriorityQueue(uint32_t maxPriorityValue) : mPatients(std::unordered_map<uint32_t, std::queue<T>>(maxPriorityValue)) {

    }

    uint32_t size() {
        return mPatients.size();
    }

    bool empty() {
        return mPatients.empty();
    }

    void push(T value, uint32_t priority) {
        mPatients[priority].push(value);
    }


    T pop() {
        T patient;
        while(mPatients[mKey].empty() && mKey<mPatients.size()){
            mKey++;
        }
        if(!mPatients[mKey].empty()){
            patient=mPatients[mKey].front();
            mPatients[mKey].pop();
        }
        return patient;
    }


    ~PriorityQueue() {

    }
};