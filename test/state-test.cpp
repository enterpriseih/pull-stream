#include "../include/common.h"
#include "gtest/gtest.h"

TEST(StateTests, SourceAbortBefore) {
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  a.abort_source();
  link(a, b);
  EXPECT_EQ(a.get_received(), message_B);
  EXPECT_NE(b.get_received(), message_A);
  int message_A_1 = random();
  a.set_message(message_A_1);
  EXPECT_NE(b.get_received(), message_A_1);
}

TEST(StateTests, SourceAbortAfter) {
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  link(a, b);
  a.abort_source();
  int message_A_1 = random();
  a.set_message(message_A_1);
  EXPECT_NE(b.get_received(), message_A_1);
}

TEST(StateTests, SourceEndBefore) {
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  a.end_source();
  link(a, b);
  EXPECT_EQ(a.get_received(), message_B);
  EXPECT_NE(b.get_received(), message_A);
  int message_A_1 = random();
  a.set_message(message_A_1);
  EXPECT_NE(b.get_received(), message_A_1);
}

TEST(StateTests, SourceEndAfter) {
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  link(a, b);
  a.end_source();
  int message_A_1 = random();
  a.set_message(message_A_1);
  EXPECT_NE(b.get_received(), message_A_1);
}

TEST(StateTests, SinkAbortBefore) {
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  b.abort_sink();
  link(a, b);
  EXPECT_EQ(a.get_received(), message_B);
  EXPECT_NE(b.get_received(), message_A);
  int message_A_1 = random();
  a.set_message(message_A_1);
  EXPECT_NE(b.get_received(), message_A_1);
}

TEST(StateTests, SinkAbortAfter) {
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  link(a, b);
  b.abort_sink();
  int message_A_1 = random();
  a.set_message(message_A_1);
  EXPECT_NE(b.get_received(), message_A_1);
}

TEST(StateTests, SinkEndBefore) {
  std::string message_A = "A@1";
  std::string message_B = "B@1";
  Duplex<std::string> a('A', message_A);
  Duplex<std::string> b('B', message_B);
  b.end_sink();
  link(a, b);
  EXPECT_EQ(a.get_received(), message_B);
  EXPECT_NE(b.get_received(), message_A);
  std::string message_A_1 = "A@2";
  a.set_message(message_A_1);
  EXPECT_NE(b.get_received(), message_A_1);
  EXPECT_NE(b.get_received(), message_A);
}

TEST(StateTests, SinkEndAfter) {
  std::string message_A = "A@1";
  std::string message_B = "B@1";
  Duplex<std::string> a('A', message_A);
  Duplex<std::string> b('B', message_B);
  link(a, b);
  b.end_sink();
  std::string message_A_1 = "A@2";
  a.set_message(message_A_1);
  EXPECT_NE(b.get_received(), message_A_1);
  EXPECT_EQ(b.get_received(), message_A);
}

TEST(StateTests, DuplexAbortBefore) {
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  a.abort();
  link(a, b);
  EXPECT_NE(a.get_received(), message_B);
  EXPECT_NE(b.get_received(), message_A);
  int message_A_1 = random();
  a.set_message(message_A_1);
  EXPECT_NE(b.get_received(), message_A_1);
}

TEST(StateTests, DuplexAbortAfter) {
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  link(a, b);
  a.abort();
  int message_A_1 = random();
  a.set_message(message_A_1);
  EXPECT_NE(b.get_received(), message_A_1);
}

TEST(StateTests, DuplexEndBefore) {
  std::string message_A = "A@1";
  std::string message_B = "B@1";
  Duplex<std::string> a('A', message_A);
  Duplex<std::string> b('B', message_B);
  a.end();
  link(a, b);
  EXPECT_NE(a.get_received(), message_B);
  EXPECT_NE(b.get_received(), message_A);
  std::string message_A_1 = "A@2";
  a.set_message(message_A_1);
  EXPECT_NE(b.get_received(), message_A_1);
  std::string message_B_1 = "B@2";
  b.set_message(message_B_1);
  EXPECT_NE(a.get_received(), message_B_1);

}
TEST(StateTests, DuplexEndAfter) {
  std::string message_A = "A@1";
  std::string message_B = "B@1";
  Duplex<std::string> a('A', message_A);
  Duplex<std::string> b('B', message_B);
  link(a, b);
  a.end();
  std::string message_A_1 = "A@2";
  a.set_message(message_A_1);
  EXPECT_NE(b.get_received(), message_A_1);
  EXPECT_EQ(b.get_received(), message_A);
}

TEST(StateTests, AbortReconnect) {
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  link(a, b);
  EXPECT_EQ(a.get_received(), message_B);
  EXPECT_EQ(b.get_received(), message_A);
  a.abort();
  b.abort();
  a.set_message(1);
  b.set_message(2);
  EXPECT_NE(a.get_received(), 2);
  EXPECT_NE(b.get_received(), 1);
  reconnect(a, b);
  EXPECT_EQ(a.get_received(), 2);
  EXPECT_EQ(b.get_received(), 1);
}

TEST(StateTests, EndReconnect) {
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  link(a, b);
  EXPECT_EQ(a.get_received(), message_B);
  EXPECT_EQ(b.get_received(), message_A);
  a.end();
  b.end();
  a.set_message(1);
  b.set_message(2);
  EXPECT_NE(a.get_received(), 2);
  EXPECT_NE(b.get_received(), 1);
  reconnect(a, b);
  EXPECT_EQ(a.get_received(), 2);
  EXPECT_EQ(b.get_received(), 1);
}
