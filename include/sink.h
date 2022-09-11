#pragma once
#include "common.h"
#include "source.h"

template<typename T>
class Sink {
    public:
        /* Constructors */
        Sink(const std::string& id): m_id(id) {}

        /* Create streams*/
        sinkT<T> sink() {
            return [this](const sourceT<T>& source) {
                m_peer_source = source;
                request();
            };
        }

        void pull(Source<T>& source) {
            sink()(source.source());
        }
        
        /* Transmit data */
        void request();
        void request(const State& state);

        T get_received() { return m_received; }
    private:
        State m_state;
        std::string m_id;
        T m_received;
        sink_callback<T> m_sink_cb = [this] (const State& source_state, 
                                             const T& message) {
            if(source_state.finish()) {
                std::cout << m_id << "'s peer as Source ended" << std::endl;
                return;
            }
            m_received = message;
            std::cout << m_id << " received message: " << m_received << std::endl;
            request();
        };
        sourceT<T> m_peer_source;
};

template<typename T>
void Sink<T>::request() {
    m_peer_source(m_state, m_sink_cb);
}
template<typename T>
void Sink<T>::request(const State& state) {
    m_state = state;
    m_peer_source(m_state, m_sink_cb);
}