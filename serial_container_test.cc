#include "serial_container.hpp"
#include <gtest/gtest.h>

TEST(SerialContainer, Constructor)
{
  SerialContainer<int> _cnt;
  ASSERT_EQ(_cnt.size(), 0);
}

TEST(SerialContainer, push_back)
{
  SerialContainer<int> _cnt;
  _cnt.push_back(999);
  ASSERT_EQ(_cnt[0], 999);
}

TEST(SerialContainer, insert_begin)
{
  SerialContainer<int> _cnt;
  _cnt.push_back(1);
  _cnt.push_back(2);

  _cnt.insert(0, 999);
  ASSERT_EQ(_cnt[0], 999);
}

TEST(SerialContainer, insert_middle)
{
  SerialContainer<int> _cnt;
  for (int i = 0; i < 10; ++i)
  {
    _cnt.push_back(i);
  }

  _cnt.insert(5, 999);
  ASSERT_EQ(_cnt[5], 999);
}

TEST(SerialContainer, erase_end)
{
  SerialContainer<int> _cnt;
  for (int i = 0; i < 10; ++i)
  {
    _cnt.push_back(i);
  }
  ASSERT_EQ(_cnt.size(), 10);
  _cnt.erase(10);
  ASSERT_EQ(_cnt.size(), 9);
  ASSERT_EQ(_cnt[_cnt.size()], 9);
}

TEST(SerialContainer, erase_begin)
{
  SerialContainer<int> _cnt;
  for (int i = 0; i < 10; ++i)
  {
    _cnt.push_back(i);
  }
  _cnt.erase(1);
  ASSERT_EQ(_cnt[0], 1);
}

TEST(SerialContainer, erase_middle)
{
  SerialContainer<int> _cnt;
  for (int i = 0; i < 10; ++i)
  {
    _cnt.push_back(i);
  }
  _cnt.erase(5);
  ASSERT_EQ(_cnt[5], 6);
}

TEST(SerialContainer, size)
{
  SerialContainer<int> _cnt;
  for (int i = 0; i < 10; ++i)
  {
    _cnt.push_back(i);
  }
  ASSERT_EQ(_cnt.size(), 10);
}

TEST(SerialContainer, size_container)
{
  SerialContainer<int> _cnt;
  for (int i = 0; i < 10; ++i)
  {
    _cnt.push_back(i);
  }
  ASSERT_EQ(_cnt.size(), 10);
}

TEST(SerialContainer, at_index) 
{
  SerialContainer<int> _cnt;
  for (int i = 0; i < 10; ++i) 
  {
    _cnt.push_back(i);
  }
  ASSERT_EQ(_cnt[0], 0);
  ASSERT_EQ(_cnt[7], 7);
}
