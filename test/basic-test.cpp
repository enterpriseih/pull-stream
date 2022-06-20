#include "../include/common.h"
#include "gtest/gtest.h"

TEST(BasicTests, CreateDuplex){
  int message = random();
  Duplex<int> a('A', message);
  EXPECT_EQ(a.get_id(), 'A');
  EXPECT_EQ(a.get_sink().get_id(), 'A');
  EXPECT_EQ(a.get_source().get_id(), 'A');
  EXPECT_EQ(a.get_message(), message);
  EXPECT_NE(a.get_sink().m_sink_cb, nullptr);
  EXPECT_NE(a.get_source().m_source, nullptr);
}

TEST(BasicTests, LinkDupex){
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  EXPECT_EQ(a.get_message(), message_A);
  EXPECT_EQ(b.get_message(), message_B);
  link(a, b);
  EXPECT_EQ(a.get_received(), message_B);
  EXPECT_EQ(b.get_received(), message_A);
}

