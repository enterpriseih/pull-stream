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
        // void request() { m_sink.request(); } /* hide this interface */
        void consume() { m_source.consume(); }
        void consume(const T& message) { m_source.consume(message); }

        /* Stream control */
        void end_source();
        void end_sink();
        void end();

        /* Message */
        T get_message() { return m_source.get_message(); }
        T get_received() { return m_sink.get_received(); }

    private:
        std::string m_id;
        Sink<T> m_sink;
        Source<T> m_source;
};

template<typename T>
void Duplex<T>::end_source() {
    m_source.consume(State(true));
}
template<typename T>
void Duplex<T>::end_sink() {
    m_sink.request(State(true));
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