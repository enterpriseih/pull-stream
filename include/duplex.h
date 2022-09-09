#pragma once
#include "common.h"
#include "sink.h"
#include "source.h"

template<typename T>
class Duplex {
    public:
        /* Constructors */
        Duplex(const std::string& id):
            m_id(id), m_sink(id), m_source(id) {}
        Duplex(const std::string& id, const T& message): 
            m_id(id), m_sink(id), m_source(id, message) {}

        /* Create streams*/
        Source<T>& get_source() { return m_source; }
        Sink<T>& get_sink() { return m_sink; }
        
        /* Transmit message */
        void request() { m_sink.request(); }
        void consume() { m_source.consume(); }
        void consume(const T& message) { m_source.consume(message); }

        /* Stream control */
        void end_source();
        void end_sink();
        void end();

    private:
        std::string m_id;
        Sink<T> m_sink;
        Source<T> m_source;
};

template<typename T>
void Duplex<T>::end_source() {
    std::cout << "end_source" << std::endl;
    m_source.consume(true);
}
template<typename T>
void Duplex<T>::end_sink() {
    std::cout << "end_sink" << std::endl;
    m_sink.request(true);
}
template<typename T>
void Duplex<T>::end() {
    end_sink();
    end_source();
}

template<typename T>
inline void pull(const sinkT<T>& sink, const sourceT<T>& source) {
    sink(source);
}
template<typename T>
inline void link(Duplex<T>& a, Duplex<T>& b) {
    pull(a.get_sink().sink(), b.get_source().source());
    pull(b.get_sink().sink(), a.get_source().source());
}
template<typename T>
inline void reconnect(Duplex<T>& a, Duplex<T>& b) {
    
}
