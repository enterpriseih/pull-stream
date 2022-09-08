#pragma once
#include "state.h"
#include <functional>
#include <string>
#include <iostream>
#include <vector>
#include <queue>

template <class T>
using sink_callback = std::function<void (const State&, const T&)>;
template <class T>
using sourceT = std::function<void (const State&, const sink_callback<T>&)>;
template <class T>
using sinkT = std::function<void (const sourceT<T>&)>;