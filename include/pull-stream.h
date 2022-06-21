#ifndef PULL_STREAM_H
#define PULL_STREAM_H

#include "common.h"

template<class T>
inline void pull(sinkT<T> sink, sourceT<T> source) {
    sink(source);
}


template<class Message>
inline void link(Duplex<Message>& a, Duplex<Message>& b) {
    pull(a.get_sink().sink(), b.get_source().source());
    pull(b.get_sink().sink(), a.get_source().source());
}
template<class Message>
inline void reconnect(Duplex<Message>& a, Duplex<Message>& b) {
    a.init();
    b.init();
    link(a, b);
}

#endif