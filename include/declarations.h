#ifndef DECLARATIONS_H
#define DECLARATIONS_H
#include <functional>

struct EndOrError
{
  bool end = false;
  bool error = false;
};

template <class T>
using source_callback = std::function<void (EndOrError, T)>;
template <class T>
using sourceT = std::function<void (EndOrError, source_callback<T>)>;
template <class T>
using sinkT = std::function<void (sourceT<T>)>;

template<typename T> 
struct sinkOptions {
  char id;
  source_callback<T> sink_cb = nullptr;
};

template<typename T> 
struct sourceOptions {
  char id;
  sourceT<T> source = nullptr;
};


#endif