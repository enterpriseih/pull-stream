#pragma once
#include "state.h"
#include <functional>
#include <string>
#include <iostream>
#include <vector>
#include <queue>

template <typename T>
using sink_callback = std::function<void (const State&, const T&)>;
template <typename T>
using sourceT = std::function<void (const State&, const sink_callback<T>&)>;
template <typename T>
using sinkT = std::function<void (const sourceT<T>&)>;