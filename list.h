/**
 * MODULE: C++ Programming Examples
 *
 * @brief  Header file for simple linked list
 * @author onyettr 
 * @file   list.h
 * @version
 */

/*
******************************************************************************
Includes
******************************************************************************
*/
#ifndef __LIST_H__
#define __LIST_H__

/*
******************************************************************************
Private Constants
******************************************************************************
*/

/*
******************************************************************************
Private Types
******************************************************************************
*/

/*
******************************************************************************
Private variables (static)
******************************************************************************
*/

/*
******************************************************************************
Private Macros
******************************************************************************
*/

/*
******************************************************************************
Global variables
******************************************************************************
*/

/*
******************************************************************************
Exported Global variables
******************************************************************************
*/


/** @enum  list_element_t
 *  @brief Linked list "Element". 
 */
struct list_element_t {
  int element;
  list_element_t *pNext;
};

/**
 * @brief Single Linked List class 
 * @class linked_list
 */
class linked_list {
    public:
       linked_list();                     /*! linked list constructor */
       ~linked_list();                    /*! linked list destructor  */  

    // Member functions
    void list_add_element (int value);  // Add an element to the list, increases list size by 1
    void list_add_at_front(int value);  // Add an element to the front of the list, increases list size by 1
    void list_add_at_back (int value);  // Add an element to the back  of the list, increases list size by 1
    void list_add_position(int position, int value); // Add an element at position,increases list size by 1
    void list_delete_element(list_element_t *pElement); // Delete element, decreases list size by 1
    int  list_get_front   (void);       // return value of first list element
    int  list_get_back    (void);       // return value of tail list element  
    void list_sort        (void);       // Sort the list
    void list_dump        (void);       // Show the contents of the linked list
    int  list_size        (void);       // Number of elements in the list
    bool list_empty       (void);       // is the list empty?
    list_element_t *GetListHead(void) { // Obtain Head iterator pointing to first element
      return pHead;
    }
    list_element_t *GetListTail(void) { // Obtain Tail iterator pointing to last element
      return pTail;
    }
#if 0    // TODO list
    void list_delete_front(void);       // Delete first element of list, decreases list size by 1
    void list_delete_back (void);       // Delete last  element of list, decreases list size by 1
#endif  
  
   private:
       list_element_t *pHead;             // Head of the Linked List
       list_element_t *pTail;             // Tail of the Linked List
       int list_count;                    // Number of nodes or Elements in the list
};

#endif // __LIST_H__

