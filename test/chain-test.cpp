#include "../include/sink.h"
#include "../include/source.h"
#include "gtest/gtest.h"

TEST(ChainTests, CreateSource) {
    std::string message_A = "A@1";
    Source<std::string> a("A", message_A);
    EXPECT_EQ(a.get_message(), message_A);
    Source<int> b("B", 2333);
    EXPECT_EQ(b.get_message(), 2333);
}

TEST(ChainTests, Pull) {
    Source<std::string> a("A", "A@1");
    Sink<std::string> b("B");
    b.pull(a);
    EXPECT_NE(b.get_received(), "A@1");
}

TEST(ChainTests, DataStream) {
    Sink<std::string> c("C");
    Source<std::string> d("D", "D@1");
    c.pull(d);
    d.consume("D@1");
    EXPECT_EQ(c.get_received(), "D@1");
    d.consume("D@2");
    EXPECT_EQ(c.get_received(), "D@1");
    d.consume();
    EXPECT_EQ(c.get_received(), "D@2");
}

TEST(ChainTests, EndSource) {
    Source<std::string> a("A");
    Sink<std::string> b("B");
    b.pull(a);
    a.consume(State(true));
    a.consume("A@1");
    EXPECT_NE(b.get_received(), "A@1");    
}

TEST(ChainTests, EndSink) {
    Sink<std::string> a("A");
    Source<std::string> b("B");
    a.pull(b);
    a.request(State(true));
    b.consume("B@1");
    EXPECT_NE(a.get_received(), "B@1");    
}
