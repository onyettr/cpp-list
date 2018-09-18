/**
 * MODULE: C++ Programming Examples
 *
 * @brief  Simple C++ linked list implementation
 * @author onyettr 
 * @file   list.cpp
 * @version
 */

/*
******************************************************************************
Includes
******************************************************************************
*/
#include <iostream>
#include <string.h>
#include "list.h"

using namespace std;

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
  
/*
******************************************************************************
Prototypes of all functions contained in this file (in order of occurance)
******************************************************************************
*/

/**
 * @fn        linked_list::linked_list(void)
 *
 * @brief     linked_list constructor
 *
 * @param     
 *
 * @return    None
 *
 * @note      constructor
 */
linked_list::linked_list(void) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: Basic Constructor called"  << endl;  
#endif

  pHead = nullptr;
  pTail = nullptr;
  list_count= 0;
}

/**
 * @fn        linked_list::~linked_list()
 *
 * @brief     linked_list destructor
 *
 * @param[in] none
 *
 * @return    None
 *
 * @note      dtor
 */
linked_list::~linked_list(void) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: Basic Destructor called "  << endl;  
#endif
  list_element_t *pNext;

  pNext = GetListHead();
  while (pNext) {
    list_element_t *pNodeToDelete;

    pNodeToDelete = pNext;
    pNext = pNext->pNext;
#if defined ( DEBUG_TRACE )
    cout << "<" << this << ">TRACE: deleting "  << pNodeToDelete << endl;  
#endif
    
    delete pNodeToDelete;

    list_count--;
  }
}

/**
 * @fn        void node::list_add_element(int value)
 *
 * @brief     Add a new list element
 *
 * @param[in] int   element to add
 *
 * @return    none
 *
 * @note      This adds to the TAIL of the list
 */
void linked_list::list_add_element (int value) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: list_add_element called "  << endl;  
#endif
  list_element_t *Temp;

  /*
   * Create a new element for the list
   */
  try {
    Temp = new list_element_t;
  }
  catch (std::bad_alloc& exp) {
    std::cerr << "Dynamic memory allocation failed!" << exp.what();

    return;
  }
    
  Temp->element = value;
  Temp->pNext = nullptr;

#if defined (DEBUG_TRACE)
  cout << "<" << this << ">TRACE: list_add_element Created new " << Temp << endl;
#endif
  
  if (pHead == nullptr) {
    /*
     * We are the first
     */
    pHead = Temp;
    pTail = Temp;
  } else {
    pTail->pNext = Temp;
    pTail = pTail->pNext;
  }
  list_count++;
#if defined (DEBUG_TRACE)  
  cout << "<" << this << ">TRACE: list_add_element Head " << pHead << endl;  
  cout << "<" << this << ">TRACE: list_add_element Tail " << pTail << endl;
#endif
}

/**
 * @fn        void linked_list::list_add_position(int position, int value)
 *
 * @brief     Add a new list element at Position in the list
 *
 * @param[in] int position   Place to insert the new element
 * @param[in] int value      element 
 *
 * @return    none
 *
 * @note      This will insert at Position. 
 */
void linked_list::list_add_position(int position, int value) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: list_emplace called "  << endl;  
#endif
  list_element_t *Temp;
  list_element_t *pCurrent;
  list_element_t *pPrevious;
  
  /*
   * Create a new element for the list
   */
  Temp = new list_element_t;
  Temp->element = value;
  Temp->pNext = nullptr;
#if defined (DEBUG_TRACE)
  cout << "<" << this << ">TRACE: list_emplace Created new " << Temp << endl;
#endif
  
  /*
   * Traverse the list until we get to position
   */
  pCurrent = pHead;  /* Start of the list */
  for (int i=1; i < position; i++) {
     pPrevious = pCurrent;
     pCurrent = pCurrent->pNext;
  }

  /* Now we are at Position, lets insert the new node */
  pPrevious->pNext = Temp;
  Temp->pNext      = pCurrent;
  
  list_count++;
}

/**
 * @fn        void node::list_add_at_front(int value)
 *
 * @brief     Add a new list value to the front of the list
 *
 * @param[in] int value 
 *
 * @return    none
 *
 * @note
 */
void linked_list::list_add_at_front(int value) {
#if defined ( DEBUG_TRACE )
    cout << "<" << this << ">TRACE: list_add_to_front called "  << endl;  
#endif
    list_element_t *Temp;

    /*
     * Create a new element for the list
     */
    try {
        Temp = new list_element_t;
    }
    catch (std::bad_alloc& exp) {
       std::cerr << "Dynamic memory allocation failed!" << exp.what();

       return;
    }

    Temp->element = value;
    Temp->pNext = pHead;            /* This element now points to the head */
    pHead = Temp;                   /* This moves the head to point to the new element, making it at the front */

    list_count++;                   /* increment the number in the list    */
  
#if defined (DEBUG_TRACE)
    cout << "<" << this << ">TRACE: list_add_to_front Created new " << Temp << endl;
    cout << "<" << this << ">TRACE: list_add_to_front Head " << pHead << endl;  
    cout << "<" << this << ">TRACE: list_add_to_front Tail " << pTail << endl;
#endif
}

/**
 * @fn        void node::list_add_at_back(int value)
 *
 * @brief     Add a new list value to the back of the list
 *
 * @param[in] int value 
 *
 * @return    none
 *
 * @note
 */
void linked_list::list_add_at_back(int value) {
#if defined ( DEBUG_TRACE )
    cout << "<" << this << ">TRACE: list_add_to_back called "  << endl;  
#endif
    list_element_t *Temp;

    /*
     * Create a new element for the list
     */
    try {
       Temp = new list_element_t;
    }
    catch (std::bad_alloc& exp)
    {
       std::cerr << "Dynamic memory allocation failed!" << exp.what();

       return;
    }

    Temp->element = value;
    Temp->pNext = nullptr;          /* This element points at nothing as its now at the back                  */
    pTail->pNext = Temp;            /* Make the current last element point to the new Tail                    */
    pTail = Temp;                   /* This moves the Tail to point to the new element, making it at the back */
  
    list_count++;
    
#if defined ( DEBUG_TRACE )
    cout << "<" << this << ">TRACE: list_add_to_back Created new " << Temp << endl;  
    cout << "<" << this << ">TRACE: list_add_to_front Head " << pHead << endl;  
    cout << "<" << this << ">TRACE: list_add_to_front Tail " << pTail << endl;
#endif    
}

/**
 * @fn        void linked_list::list_delete_element(list_element_t *lp)
 *
 * @brief     Remove a list element
 *
 * @param[in] list_element_t *lp    Pointer to list element to delete
 *
 * @return    none
 *
 * @note
 */
void linked_list::list_delete_element (list_element_t *pElement) {
#if defined ( DEBUG_TRACE )
    cout << "<" << this << ">TRACE: list_delete_element called "  << endl;  
#endif

    list_count--;

#if defined ( DEBUG_TRACE )  
    cout << "<" << this << ">TRACE: list_delete_element Head " << pHead << endl;  
    cout << "<" << this << ">TRACE: list_delete_element Tail " << pTail << endl;
#endif  
}

/**
 * @fn        void linked_list::list_sort(void)
 *
 * @brief     Sort the list
 *
 * @param
 *
 * @return    none
 *
 * @note
 */
void linked_list::list_sort (void) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: list_sort called "  << endl;  
#endif
  
}

/**
 * @fn        int linked_list::list_size(void)
 *
 * @brief     return the size of the list
 *
 * @param
 *
 * @return    Size of the list
 *
 * @note
 */
int linked_list::list_size (void) {
#if defined ( DEBUG_TRACE_1 )
  cout << "<" << this << ">TRACE: list_size called "  << endl;  
#endif

  return list_count;
}

/**
 * @fn        bool linked_list::list_empty(void)
 *
 * @brief     Is the list empty?
 *
 * @param[in] none
 *
 * @return    bool TRUE = Empty, FALSE = Not empty
 *
 * @note
 */
bool linked_list::list_empty(void) {
#if defined ( DEBUG_TRACE_1 )
  cout << "<" << this << ">TRACE: list_empty called "  << endl;  
#endif

  if (list_count == 0) {
    return true;
  }
  return false;
}

/**
 * @fn        int linked_list::list_get_front(void)
 *
 * @brief     return front list value
 *
 * @param[in] none
 *
 * @return    <T> (int)   Front list value
 *
 * @note
 */
int linked_list::list_get_front(void) {
  int value = 0;  
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: list_get_front called "  << endl;  
#endif

  if (list_count == 0) {
    cout << "Error: No elements in linked list" << endl;
  }
  else {
    value = pHead->element;
  }

  return value;
}

/**
 * @fn        int linked_llist::list_get_back(void)
 *
 * @brief     return the back/tail list value
 *
 * @param[in] none
 *
 * @return    <T> (int)   back list value
 *
 * @note
 */
int linked_list::list_get_back(void) {
  int value = 0;  
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: list_get_back called "  << endl;  
#endif

  if (list_count == 0) {
    cout << "Error: No elements in linked list" << endl;
  }
  else {
    value = pTail->element;
  }

  return value;
}

/**
 * @fn        void linked_list::list_dump(void) 
 *
 * @brief     Print out the single linked list
 *
 * @param
 *
 * @return    none
 *
 * @note
 */
void linked_list::list_dump (void) {
   list_element_t *pCurrent;
  
   if ( !list_empty() ) {
      pCurrent = GetListHead();

      cout << "   Address   \tValue\t   pNext\tNumber of Nodes = " << list_count << endl;
      while (pCurrent != nullptr) {
         cout << "[" << pCurrent << "]\t";
         cout << pCurrent->element << "\t[" << pCurrent->pNext << "]" << endl;

         pCurrent = pCurrent->pNext;
    }
  }
  else {
     cout << "Error: No elements in linked list" << endl;
  }
}
