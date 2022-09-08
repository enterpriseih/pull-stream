#pragma once
#include "common.h"

template<typename T>
class Sink {
    public:
        Sink(const std::string& id): m_id(id) {}
        sinkT<T> sink() {
            return [this](const sourceT<T>& source) {
                source(m_state, m_sink_cb);
            };
        }
    private:
        State m_state;
        std::string m_id;
        T m_received;
        sink_callback<T> m_sink_cb = 
            [this] (const State& source_state, const T& message) {
                if(source_state.finish()) {
                    std::cout << m_id << "'s peer as Source end or error" << std::endl;
                    return;
                }
                m_received = message;
                std::cout << m_id << " received message: " << m_received << std::endl;
            };
};