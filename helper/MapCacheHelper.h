//
// Created by mingj on 18-12-25.
//

#ifndef IP_NDN_STACK_CPP_CACHEHELPER_H
#define IP_NDN_STACK_CPP_CACHEHELPER_H

#include "../libpcapcapture/libpcap.h"
#include <unordered_map>
#include <iostream>
#include <boost/thread/pthread/shared_mutex.hpp>

using namespace std;

class MapCacheHelper {
public:
    MapCacheHelper(){}
    bool save(string key, tuple_p value);
    pair<tuple_p, bool> get(string key);
    unsigned int erase(string key);
    unsigned int erase(string key, tuple_p tuple);
private:
    unordered_map<string, tuple_p> ipPacketCache;
    tuple_p emptyTuple;
    boost::shared_mutex insertMutex;
    boost::shared_mutex deleteMutex;
};


#endif //IP_NDN_STACK_CPP_CACHEHELPER_H