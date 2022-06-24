#ifndef DECLARATIONS_H
#define DECLARATIONS_H
#include <functional>
#include <assert.h>
#include <exception>
#include <string>

template <class T>
using source_callback = std::function<void (const State&, const T&)>;
template <class T>
using sourceT = std::function<void (const State&, const source_callback<T>&)>;
template <class T>
using sinkT = std::function<void (const sourceT<T>&)>;

template<typename T> 
struct sinkOptions {
  char id;
  source_callback<T> sink_cb = nullptr;
};

template<typename T> 
struct sourceOptions {
  char id;
  sourceT<T> source = nullptr;
  T message;
};


#endif