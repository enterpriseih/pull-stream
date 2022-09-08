#pragma once
#include "common.h"

template<typename T>
class Source {
    public:
        Source(const std::string& id): 
            m_id(id) {}
        Source(const std::string& id, const T& message): 
            m_id(id), m_message(message) {}
        sourceT<T> source() {return m_source; }
    private:
        State m_state;
        T m_message;
        std::string m_id;
        sourceT<T> m_source = 
            [this] (const State& sink_state, 
                    const sink_callback<T>& cb) {
                if (sink_state.finish()) {
                    std::cout << m_id << "'s peer as Sink end or error" 
                              << std::endl;
                    return;
                }
                cb(m_state, m_message);
            };
};