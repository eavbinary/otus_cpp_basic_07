#include "line_container.hpp"
#include <gtest/gtest.h>

TEST(LineContainer, Constructor)
{
  LineContainer<int> _cnt;
  ASSERT_EQ(_cnt.size(), 0);
}

TEST(LineContainer, push_back)
{
  LineContainer<int> _cnt;
  _cnt.push_back(999);
  ASSERT_EQ(_cnt[0], 999);
}

TEST(LineContainer, insert_begin)
{
  LineContainer<int> _cnt;
  _cnt.push_back(1);
  _cnt.push_back(2);

  _cnt.insert(0, 999);
  ASSERT_EQ(_cnt[0], 999);
}

TEST(LineContainer, insert_middle)
{
  LineContainer<int> _cnt;
  for (int i = 0; i < 10; ++i)
  {
    _cnt.push_back(i);
  }

  _cnt.insert(5, 999);
  ASSERT_EQ(_cnt[5], 999);
}

TEST(LineContainer, erase_end)
{
  LineContainer<int> _cnt;
  for (int i = 0; i < 10; ++i)
  {
    _cnt.push_back(i);
  }
  ASSERT_EQ(_cnt.size(), 10);
  _cnt.erase(10);
  ASSERT_EQ(_cnt.size(), 9);
  ASSERT_EQ(_cnt[_cnt.size() - 1], 8);
}

TEST(LineContainer, erase_begin)
{
  LineContainer<int> _cnt;
  for (int i = 0; i < 10; ++i)
  {
    _cnt.push_back(i);
  }
  _cnt.erase(0);
  ASSERT_EQ(_cnt[0], 1);
}

TEST(LineContainer, erase_middle)
{
  LineContainer<int> _cnt;
  for (int i = 0; i < 10; ++i)
  {
    _cnt.push_back(i);
  }
  _cnt.erase(5);
  ASSERT_EQ(_cnt[5], 6);
}

TEST(LineContainer, size)
{
  LineContainer<int> _cnt;
  for (int i = 0; i < 10; ++i)
  {
    _cnt.push_back(i);
  }
  ASSERT_EQ(_cnt.size(), 10);
}

TEST(LineContainer, size_container)
{
  LineContainer<int> _cnt;
  for (int i = 0; i < 10; ++i)
  {
    _cnt.push_back(i);
  }
  ASSERT_EQ(_cnt.size(), 10);
}

TEST(LineContainer, at_index) 
{
  LineContainer<int> _cnt;
  for (int i = 0; i < 10; ++i) 
  {
    _cnt.push_back(i);
  }
  ASSERT_EQ(_cnt[0], 0);
  ASSERT_EQ(_cnt[7], 7);
}
