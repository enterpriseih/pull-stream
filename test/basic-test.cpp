#include "../include/duplex.h"
#include "gtest/gtest.h"

TEST(BasicTests, CreateDuplex) {
    std::string message_A = "A@1";
    Duplex<std::string> a("A", message_A);
    EXPECT_EQ(a.get_message(), message_A);
    Duplex<int> b("B", 2333);
    EXPECT_EQ(b.get_message(), 2333);
}

TEST(BasicTests, LinkDuplex) {
    Duplex<std::string> a("A", "A@1");
    Duplex<std::string> b("B");
    link(a, b);
    EXPECT_NE(b.get_received(), "A@1");
    EXPECT_EQ(a.get_received(), "");
}

TEST(BasicTests, ConsumeData) {
    Duplex<std::string> a("A", "A@1");
    Duplex<std::string> b("B");
    link(a, b);
    b.consume("B@1");
    EXPECT_EQ(a.get_received(), "B@1");
    a.consume();
    EXPECT_EQ(b.get_received(), "A@1");
}

TEST(BasicTests, DataStream) {
    Duplex<std::string> a("A");
    Duplex<std::string> b("B");
    link(a, b);
    b.consume("B@1");
    EXPECT_EQ(a.get_received(), "B@1");
    b.consume("B@2");
    EXPECT_EQ(a.get_received(), "B@2");
    b.consume("B@3");
    EXPECT_EQ(a.get_received(), "B@3");
}

TEST(BasicTests, EndSource) {
    Duplex<std::string> a("A");
    Duplex<std::string> b("B");
    link(a, b);
    a.end_source();
    a.consume("A@1");
    EXPECT_NE(b.get_received(), "A@1");    
}

TEST(BasicTests, EndSink) {
    Duplex<std::string> a("A");
    Duplex<std::string> b("B");
    link(a, b);
    a.end_sink();
    b.consume("B@1");
    EXPECT_NE(a.get_received(), "B@1");    
}

TEST(BasicTests, EndDuplex) {
    Duplex<std::string> a("A");
    Duplex<std::string> b("B");
    link(a, b);
    a.end();
    b.consume("B@1");
    EXPECT_NE(a.get_received(), "B@1");
    a.consume("A@1");
    EXPECT_NE(b.get_received(), "A@1"); 
}