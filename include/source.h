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

        void consume();
        void consume(const T& message);

    private:
        State m_state;
        T m_message;
        std::string m_id;
        sourceT<T> m_source = [this] (const State& sink_state, 
                                      const sink_callback<T>& cb) {
            if (sink_state.finish()) {
                std::cout << m_id << "'s peer as Sink end or error" << std::endl;
                return;
            }
            // cb(m_state, m_message);
            m_cb_que.push(cb);
        };
        std::queue<sink_callback<T>> m_cb_que;
};

template<typename T>
void Source<T>::consume() {
    if(m_cb_que.empty()) {
        std::cout << m_id << " need a request" << std::endl;
        return;
    }
    auto cb = m_cb_que.front();
    m_cb_que.pop();
    cb(m_state, m_message);
}

template<typename T>
void Source<T>::consume(const T& message) {
    m_message = message;
    consume();
}