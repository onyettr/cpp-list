/**
 *	@file    test_unittest.cpp
 *	@brief   simple c++ linked list harness using googletest
 *	@author
 *	@note
 */

/*
******************************************************************************
Includes
******************************************************************************
*/
#include "list.h"
#include "gtest/gtest.h"

namespace {
class LinkedListTest : public testing::Test {
   protected:
};

/**
 * @brief Linked List Test SIZE
 */
TEST_F(LinkedListTest, ListSizeIsZero) {
  linked_list SizeTest;

  // Test Empty List
  EXPECT_EQ(0, SizeTest.list_size());
}

TEST_F(LinkedListTest, ListSizeIsOne) {
  linked_list SizeTest;

  SizeTest.list_add_element(100);

  EXPECT_EQ(1, SizeTest.list_size());
}

TEST_F(LinkedListTest, ListIsEmpty) {
  linked_list EmptyTest;

  EXPECT_TRUE(EmptyTest.list_empty());
}

TEST_F(LinkedListTest, ListIsNotEmpty) {
  linked_list EmptyTest;

  EmptyTest.list_add_element(101);
  EXPECT_FALSE(EmptyTest.list_empty());
}

/**
 * @brief Tests - front list is empty
 */
TEST_F(LinkedListTest, ListFrontEmpty) {
  linked_list EmptyTest;

  try {
    EmptyTest.list_get_front();
  }
  catch (std::runtime_error& e) {
    SUCCEED();
    return;
  }
  catch (...) {
    FAIL() << "odd exception?";
  }
  ADD_FAILURE() << "Exception not thrown as expected";
}

/**
 * @brief Tests - front list is empty
 */
TEST_F(LinkedListTest, ListFrontSuccess) {
  linked_list FrontTest;

  FrontTest.list_add_element(200);
  EXPECT_EQ(200,FrontTest.list_get_front());
}
  
#if 0
/**
 * @brief StackTest PEEK
 */
TEST_F(StackTest, PeekingWithSomethingThere)
{
  Stack<int> peekme(3);  

  peekme.push(2001);
  peekme.push(2002);
  peekme.push(2003);

  EXPECT_EQ(2003, peekme.peek());  
}

TEST_F(StackTest, PeekingWithNothingThere)
{
  Stack<int> peekmeFail(1);      

  try {
     peekmeFail.peek();
  }
  catch (std::runtime_error& e) {
    SUCCEED();
    return;
  }
  catch (...) {
    FAIL() << "odd exception?";
  }
  ADD_FAILURE() << "Exception not thrown as expected";
}

/**
 * @brief StackTest PUSH
 */
TEST_F(StackTest, StackPushOneINTEGERItem) {
  Stack<int> MyStack(5);

  MyStack.push(100);
  EXPECT_EQ(1, MyStack.StackSize());
}

TEST_F(StackTest, StackPushOneCHARItem) {
  Stack<char> MyStack(5);

  MyStack.push('a');
  EXPECT_EQ(1, MyStack.StackSize());
}
  
TEST_F(StackTest, StackPushOneFLOATItem) {
  Stack<float> MyStack(5);

  MyStack.push(3.14);
  EXPECT_EQ(1, MyStack.StackSize());  
}

TEST_F(StackTest, StackPushOneDOUBLEItem) {
  Stack<double> MyStack(5);

  MyStack.push(3.1423);
  EXPECT_EQ(1, MyStack.StackSize());
}
  
TEST_F(StackTest, StackPushOneSTRINGItem) {
  Stack<string> MyStack(5);

  MyStack.push("hello");
  EXPECT_EQ(1, MyStack.StackSize());  
}

TEST_F(StackTest, StackPushOneBOOLEANItem) {
  Stack<bool> MyStack(5);

  MyStack.push(true);
  EXPECT_EQ(1, MyStack.StackSize());  
}
  
TEST_F(StackTest, StackPushToOverflow) {
  Stack<int> MyStack(5);

  try {
     MyStack.push(100);
     MyStack.push(101);
     MyStack.push(102);
     MyStack.push(103);
     MyStack.push(104);
     MyStack.push(105);
  }
  catch (std::runtime_error& e) {
    SUCCEED();
    return;
  }
  catch (...) {
    FAIL() << "odd exception?";
  }
  ADD_FAILURE() << "Exception not thrown as expected";

}

/**
 * @brief StackTest POP
 */
TEST_F(StackTest, StackPopOneINTEGERItem) {
  Stack<int> MyStack(5);

  MyStack.push(100);
  EXPECT_EQ(100, MyStack.pop());
}

TEST_F(StackTest, StackPopOneFLOATItem) {
  Stack<float> MyStack(5);

  MyStack.push(3.14);
  EXPECT_FLOAT_EQ(3.14, MyStack.pop());  
}

TEST_F(StackTest, StackPopOneCHARItem) {
  Stack<char> MyStack(5);

  MyStack.push('a');
  EXPECT_EQ('a', MyStack.pop());  
}
  
TEST_F(StackTest, StackPopOneSTRINGItem) {
  Stack<string> MyStack(5);

  MyStack.push("hello");
  EXPECT_EQ("hello", MyStack.pop());  
}

TEST_F(StackTest, StackPopOneBOOLEANItem) {
  Stack<bool> MyStack(5);

  MyStack.push(true);
  EXPECT_TRUE(MyStack.pop());  
}
  
TEST_F(StackTest, StackPopUnderflow) {
  Stack<int> MyStack(5);

  try {
     MyStack.pop();
  }
  catch (std::runtime_error& e) {
    SUCCEED();
    return;
  }
  catch (...) {
    FAIL() << "odd exception?";
  }
  ADD_FAILURE() << "Exception not thrown as expected";
}
#endif
}
