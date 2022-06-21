#include "../include/common.h"
#include "gtest/gtest.h"

TEST(StateTests, Aborting) {
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  a.get_source().get_state().ask_abort();
  link(a, b);
  EXPECT_EQ(a.get_received(), message_B);
  EXPECT_NE(b.get_received(), message_A);
  int message_A_1 = random();
  a.set_message(message_A_1);
  EXPECT_NE(b.get_received(), message_A_1);
}

TEST(StateTests, Ending) {
  int message_A = random();
  int message_B = random();
  Duplex<int> a('A', message_A);
  Duplex<int> b('B', message_B);
  a.get_source().get_state().ask_end();
  link(a, b);
  EXPECT_EQ(a.get_received(), message_B);
  EXPECT_EQ(b.get_received(), message_A);
  int message_A_1 = random();
  a.set_message(message_A_1);
  EXPECT_NE(b.get_received(), message_A_1);
}