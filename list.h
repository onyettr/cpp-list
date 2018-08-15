/******************************************************************************
 * 
 * MODULE: C++ Programming Examples
 *
 * $Header: $
 * $Archive:$
 * 
 * $Workfile: $
 *
 * $Author: Onyettr $
 *
 * PURPOSE: Header file for simple linked list
 * 
 * $Revision:$
 * $History: $
 *
 ***************************************************************************** 
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

class linked_list {
   private:
     list_element_t *pHead;            // Head of the Linked List
     list_element_t *pTail;            // Tail of the Linked List
     int list_count;                   // Number of nodes or Elements in the list
   public:
     ~linked_list();                   // dtor
     linked_list();                    // ctor

    // Member functions
    void list_add_element (int value); // Add an element to the list
    void list_add_at_front(int value); // Add an element to the front of the list
    void list_delete_element(list_element_t *pElement); // Delete element 
    void list_dump        (list_element_t *pHead);      // Dump the contents of the linked list
    list_element_t *GetListHead(void) { // Obtain the head of the list.
      return (list_element_t *)pHead;
    }
};

#endif // __LIST_H__

