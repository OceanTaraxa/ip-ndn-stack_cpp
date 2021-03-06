#include "util.h"
#include "tuple.h"

int cmp_lf(const void *a, const void *b) {
    return (*(double*)a) < (*(double*)b);
}

int cmp_ll(const void *a, const void *b) {
    return (*(long long*)a) < (*(long long*)b);
}

int cmp(const void *a, const void *b) {
    tuple_t* t1 = (tuple_t*)a;
    tuple_t* t2 = (tuple_t*)b;

    if (t1->size != t2->size) {
        return t1->size < t2->size;
    }

    if (t1->key.src_ip != t2->key.src_ip) {
        return t1->key.src_ip < t2->key.src_ip;
    }

    if (t1->key.dst_ip != t2->key.dst_ip) {
        return t1->key.dst_ip < t2->key.dst_ip;
    }

    if (t1->key.src_port != t2->key.src_port) {
        return t1->key.src_port < t2->key.src_port;
    }

    if (t1->key.dst_port != t2->key.dst_port) {
        return t1->key.dst_port < t2->key.dst_port;
    }

    return t1->key.proto < t2->key.proto;
}

