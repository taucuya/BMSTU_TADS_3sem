#ifndef _ERR_H_
#define _ERR_H_

// Success
#define SUCCESS 0

// Errors while choosing action

#define ERR_ACTION 1

// Errors while reading

#define ERR_SURNAME_READ 2
#define ERR_BOOK_NAME_READ 3
#define ERR_PUBLICATION_READ 4
#define ERR_PAGE_NUMBER_READ 5
#define ERR_LITERATURE_TYPE_READ 6

#define ERR_BRANCH_READ 7
#define ERR_COUNTRY_READ 8
#define ERR_YEAR_READ 9

#define ERR_TYPE_ART_READ 10

#define ERR_MIN_AGE_READ 11
#define ERR_TYPE_CHILD_READ 12

#define ERR_FILE_OPEN 13
#define ERR_EMPTY_FILE 14

// Errors while deleting row and searching

#define ERR_NO_MATCHES 15

// Errors while filling key struct array

#define ERR_KEY_FILL 16

// Errors while ending programm 

#define ERR_SAVING 17

// Сommand

#define ERR_COMMAND 22222

#endif