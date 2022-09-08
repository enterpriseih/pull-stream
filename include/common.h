#pragma once

#include <functional>

template <class T>
using source_callback = std::function<void (const State&, const T&)>;
template <class T>
using sourceT = std::function<void (const State&, const source_callback<T>&)>;
template <class T>
using sinkT = std::function<void (const sourceT<T>&)>;