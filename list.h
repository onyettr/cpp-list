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
 * NAME: Richard Onyett 
 * EMAIL: 
 *
 * PURPOSE: 
 * Header file for simple linked list
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


/*
 * linked list classs
 */
struct list_element_t {
  //  void *element;
  int element;
};

class node {
   private:
     void *node_prev;
     void *node_next;
     int node_count;
     list_element_t record;
   public:
     ~node();                   // dtor
     node();                    // ctor

    // Member functions
    void list_add_element ( list_element_t *lp);
    void list_dump        ( node *p );
    int  getNodecount     ();
    int  setNodecount     (int);
};

#endif // __LIST_H__

