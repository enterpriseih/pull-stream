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

TEST(BasicTests, TransMessageFlow){
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  link(a, b);
  EXPECT_EQ(a.get_received(), message_B);
  EXPECT_EQ(b.get_received(), message_A);
  int message_A_1 = random();
  a.set_message(message_A_1);
  EXPECT_EQ(b.get_received(), message_A_1);
}

TEST(BasicTests, CreateDuplexString){
  std::string message = "A";
  Duplex<std::string> a('A', message);
  EXPECT_EQ(a.get_id(), 'A');
  EXPECT_EQ(a.get_sink().get_id(), 'A');
  EXPECT_EQ(a.get_source().get_id(), 'A');
  EXPECT_EQ(a.get_message(), message);
  EXPECT_NE(a.get_sink().m_sink_cb, nullptr);
  EXPECT_NE(a.get_source().m_source, nullptr);
}

TEST(BasicTests, LinkDupexString){
  std::string message_A = "AA";
  std::string message_B = "BB";
  Duplex<std::string> a('A', message_A);
  Duplex<std::string> b('B', message_B);
  EXPECT_EQ(a.get_message(), message_A);
  EXPECT_EQ(b.get_message(), message_B);
  link(a, b);
  EXPECT_EQ(a.get_received(), message_B);
  EXPECT_EQ(b.get_received(), message_A);
}

TEST(BasicTests, TransMessageFlowString){
  std::string message_A = "A@1";
  std::string message_B = "B1";
  Duplex<std::string> a('A', message_A);
  Duplex<std::string> b('B', message_B);
  link(a, b);
  EXPECT_EQ(a.get_received(), message_B);
  EXPECT_EQ(b.get_received(), message_A);
  std::string message_A_1 = "A@2";
  a.set_message(message_A_1);
  EXPECT_EQ(b.get_received(), message_A_1);
}

