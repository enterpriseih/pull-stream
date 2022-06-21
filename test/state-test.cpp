#include "../include/common.h"
#include "gtest/gtest.h"

TEST(StateTests, SourceAbort) {
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

TEST(StateTests, SourceEnd) {
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  a.end_source();
  link(a, b);
  EXPECT_EQ(a.get_received(), message_B);
  EXPECT_EQ(b.get_received(), message_A);
  int message_A_1 = random();
  a.set_message(message_A_1);
  EXPECT_NE(b.get_received(), message_A_1);
}

TEST(StateTests, SinkAbort) {
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  b.abort_sink();
  link(a, b);
  EXPECT_EQ(a.get_received(), message_B);
  EXPECT_NE(b.get_received(), message_A);
}

TEST(StateTests, SinkEnd) {
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  b.end_sink();
  link(a, b);
  EXPECT_EQ(a.get_received(), message_B);
  EXPECT_EQ(b.get_received(), message_A);
  int message_A_1 = random();
  a.set_message(message_A_1);
  EXPECT_NE(b.get_received(), message_A_1);
  EXPECT_EQ(b.get_received(), message_A);
}

TEST(StateTests, DuplexAbort) {
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  a.abort();
  link(a, b);
  EXPECT_NE(a.get_received(), message_B);
  EXPECT_NE(b.get_received(), message_A);
}

TEST(StateTests, DuplexEnd) {
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  a.end();
  link(a, b);
  EXPECT_EQ(a.get_received(), message_B);
  EXPECT_EQ(b.get_received(), message_A);
  a.set_message(1);
  b.set_message(2);
  EXPECT_NE(a.get_received(), 2);
  EXPECT_NE(b.get_received(), 1);
}

TEST(StateTests, Reconnect) {
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
  a.init();
  b.init();
  link(a, b);
  EXPECT_EQ(a.get_received(), 2);
  EXPECT_EQ(b.get_received(), 1);
}
