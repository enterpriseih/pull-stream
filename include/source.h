#pragma once
#include "common.h"

template<typename T>
class Source {
    public:
        /* Constructors */
        Source(const std::string& id): 
            m_id(id) {}
        Source(const std::string& id, const T& message): 
            m_id(id), m_message(message) {
                m_message_que.push(message);
            }

        /* Create streams*/
        sourceT<T> source() {return m_source; }

        /* Transmit data */
        void consume();
        void consume(const T& message);
        void consume(const State& state);
        void consume(const State& state, const T& message);

        T get_message() { return m_message; }
    private:
        State m_state;
        State m_peer_state;
        T m_message;
        std::string m_id;
        sourceT<T> m_source = [this] (const State& sink_state, 
                                      const sink_callback<T>& cb) {
            if (sink_state.finish()) {
                m_peer_state = sink_state;
                std::cout << m_id << "'s peer as Sink ended" << std::endl;
                return;
            }
            // cb(m_state, m_message);
            m_cb_que.push(cb);
            if (!m_message_que.empty()) {
                consume();
            }
        };
        std::queue<sink_callback<T>> m_cb_que;
        std::queue<T> m_message_que;
};

template<typename T>
void Source<T>::consume() {    
    /* Check peer state */
    if(m_peer_state.finish()) return;
    /* Check cbs */
    if(m_cb_que.empty()) {
        std::cout << m_id << " needs a request" << std::endl;
        return;
    }
    auto cb = m_cb_que.front();
    m_cb_que.pop();
    /* Check messages */
    if(!m_message_que.empty()) {
        // std::cout << "queue size: " << m_message_que.size() << std::endl;
        m_message = m_message_que.front();
        m_message_que.pop();
    } else {
        std::cout << m_id << " need more messages, use the latest one" << std::endl;
    }
    cb(m_state, m_message);
}

template<typename T>
void Source<T>::consume(const T& message) {
    m_message_que.push(message);
    consume();
}
template<typename T>
void Source<T>::consume(const State& state) {
    m_state = state;
    consume();
}
template<typename T>
void Source<T>::consume(const State& state, const T& message) {
    m_state = state;
    consume(message);
}