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
 * @brief Linked List Test SIZE list empty
 */
TEST_F(LinkedListTest, ListSizeIsZero) {
  linked_list SizeTest;

  EXPECT_EQ(0, SizeTest.list_size());
}

/**
 * @brief Linked List Test SIZE one element
 */
TEST_F(LinkedListTest, ListSizeIsOne) {
  linked_list SizeTest;

  SizeTest.list_add_element(100);

  EXPECT_EQ(1, SizeTest.list_size());
}

/**
 * @brief Linked List Test list_empty TRUE
 */
TEST_F(LinkedListTest, ListIsEmpty) {
  linked_list EmptyTest;

  EXPECT_TRUE(EmptyTest.list_empty());
}

/**
 * @brief Linked List Test list_empty FALSE
 */
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
 * @brief Tests - front list is ok
 */
TEST_F(LinkedListTest, ListFrontOneElement) {
  linked_list FrontTest;

  FrontTest.list_add_element(200);
  EXPECT_EQ(200,FrontTest.list_get_front());
}

/**
 * @brief Tests - front list is ok
 */
TEST_F(LinkedListTest, ListFrontTwoElement) {
  linked_list FrontTest;

  FrontTest.list_add_element(200);
  FrontTest.list_add_element(300);  
  EXPECT_EQ(200,FrontTest.list_get_front());
}

/**
 * @brief Tests - front list is ok
 */
TEST_F(LinkedListTest, ListFrontExplicit) {
  linked_list FrontTest;

  FrontTest.list_add_element(200);
  FrontTest.list_add_element(300);
  FrontTest.list_add_at_front(111);    
  EXPECT_EQ(111,FrontTest.list_get_front());
}

/**
 * @brief Tests - back list is empty
 */
TEST_F(LinkedListTest, ListBackEmpty) {
  linked_list BackTest;

  try {
    BackTest.list_get_back();
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
 * @brief Tests - back list is ok
 */
TEST_F(LinkedListTest, ListTailOneElement) {
  linked_list BackTest;

  BackTest.list_add_element(201);
  EXPECT_EQ(201,BackTest.list_get_back());
}

/**
 * @brief Tests - back list is ok
 */
TEST_F(LinkedListTest, ListTailTwoElement) {
  linked_list BackTest;

  BackTest.list_add_element(201);
  BackTest.list_add_element(301);  
  EXPECT_EQ(301,BackTest.list_get_back());
}

/**
 * @brief Tests - back list is ok
 */
TEST_F(LinkedListTest, ListTailExplicitAddAtBack) {
  linked_list BackTest;

  BackTest.list_add_element(200);
  BackTest.list_add_element(300);
  BackTest.list_add_at_back(111);    
  EXPECT_EQ(111,BackTest.list_get_back());
}

/**
 * @brief Tests - add list is ok
 */
TEST_F(LinkedListTest, ListAddOneElement) {
  linked_list AddTest;

  AddTest.list_add_element(10);
  EXPECT_EQ(1,AddTest.list_size());
}

/**
 * @brief Tests - add more list is ok
 */
TEST_F(LinkedListTest, ListAddFourElement) {
  linked_list AddTest;

  AddTest.list_add_element(1);
  AddTest.list_add_element(2);
  AddTest.list_add_element(3);
  AddTest.list_add_element(4);
  EXPECT_EQ(4,AddTest.list_size());
}

/**
 * @brief Tests - add at position
 */
TEST_F(LinkedListTest, ListAddAtPosition) {
  linked_list AddTest;

  AddTest.list_add_element(1);
  AddTest.list_add_element(2);
  AddTest.list_add_element(3);
  AddTest.list_add_element(4);

  AddTest.list_add_position(2, 5);
  EXPECT_EQ(5,AddTest.list_size());
}

/**
 * @brief Tests - Get at position
 */
TEST_F(LinkedListTest, ListGetAtPosition) {
  linked_list AddTest;

  AddTest.list_add_element(1);
  AddTest.list_add_element(2);
  AddTest.list_add_element(3);
  AddTest.list_add_element(4);

  AddTest.list_add_position(2, 5);

  EXPECT_EQ(5,AddTest.list_get_position(2));
}
  
/**
 * @brief Tests - get list is empty
 */
TEST_F(LinkedListTest, ListGetEmpty) {
  linked_list GetTest;

  try {
    GetTest.list_get_position(1);
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
 * @brief Tests - Delete test
 */
TEST_F(LinkedListTest, ListDeleteOneElement) {
  linked_list DelTest;

  DelTest.list_add_element(202);
  DelTest.list_delete_element(DelTest.GetListHead()->pNext);
  EXPECT_EQ(0,DelTest.list_size());
}

/**
 * @brief Tests - Delete test at Position
 */
#if 0  
TEST_F(LinkedListTest, ListDeleteElementAtPosition) {
  linked_list DelTest;

  DelTest.list_add_element(202);
  DelTest.list_delete_element(delTest.GetListHead()->pNext);
  EXPECT_EQ(0,DelTest.list_size());
}
#endif
  
}
