#include "../include/common.h"
#include "gtest/gtest.h"

TEST(EndOrErrorTests, SourceEndOrError){
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  EXPECT_EQ(a.get_message(), message_A);
  EXPECT_EQ(b.get_message(), message_B);
  a.get_source().set_end_or_error(True);
  link(a, b);
  EXPECT_EQ(a.get_received(), message_B);
  EXPECT_NE(b.get_received(), message_A);
}

TEST(EndOrErrorTests, SinkEndOrError){
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  EXPECT_EQ(a.get_message(), message_A);
  EXPECT_EQ(b.get_message(), message_B);
  a.get_sink().set_end_or_error(True);
  link(a, b);
  EXPECT_NE(a.get_received(), message_B);
  EXPECT_EQ(b.get_received(), message_A);
}

TEST(EndOrErrorTests, BothEndOrError){
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  EXPECT_EQ(a.get_message(), message_A);
  EXPECT_EQ(b.get_message(), message_B);
  a.get_sink().set_end_or_error(True);
  a.get_source().set_end_or_error(True);
  link(a, b);
  EXPECT_NE(a.get_received(), message_B);
  EXPECT_NE(b.get_received(), message_A);
}
