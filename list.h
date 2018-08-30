/**
 *****************************************************************************
 * MODULE: C++ Programming Examples
 *
 * @author onyettr 
 * @file   list.h
 *
 * PURPOSE: Header file for simple linked list
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

/*! Single Linked List class */
class linked_list {
   private:
     list_element_t *pHead;            // Head of the Linked List
     list_element_t *pTail;            // Tail of the Linked List
     int list_count;                   // Number of nodes or Elements in the list
   public:
     ~linked_list();                   /*! linked list descrtuctor */
     linked_list();                    /*! linked list constructor */

    // Member functions
    void list_add_element (int value); // Add an element to the list
    void list_add_at_front(int value); // Add an element to the front of the list
    void list_add_at_back (int value); // Add an element to the back  of the list
    void list_emplace     (int position, int value); // Add an element at position
    void list_delete_element(list_element_t *pElement); // Delete element
    int  list_get_front   (void);      // return first list element
    int  list_get_back    (void);      // return tail list element  
    void list_sort        (list_element_t *pHead);      // Sort the list
    void list_dump        (list_element_t *pHead);      // Dump the contents of the linked list
    int  list_size        (void);       // Size of the list
    bool list_empty       (void);       // is the list empty?
#if 0    // TODO list

#endif  
    list_element_t *GetListHead(void) { // Obtain the head of the list.
      return pHead;
    }
};

#endif // __LIST_H__

