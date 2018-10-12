/**
 *  @Author: Self
 *  
 *  @Brief: File contains declarations of functions, that are used
 *          in BinS.c file
 *          
 * 
 *  @Usage: Function BinSearch_BinS should be used to binary search array
 *          Function BinarySearchInt8_Monotony can be used to test monotony
 *          of array
 * 
 *  @Limitations:  THERE IS A BRAVE ASSUMPTION THAT ARRAY IS SORTED
 *  
 *  @Violation: MISRA 2012 VIOLATION ! !-!-! !
 *              Casting smaller types on biger should not be done, but since
 *              BinS_ATYPE and BinS_I_TYPE can be any type.
 * 
 *              RESOLVET
 * 
 *              simple resolution for this violation is to use for exaple 1ULL 
 *              instead of 1U. And since those are literals optimisation from
 *              compiler side can be done.
 * 
 * @Date: 31.07.2018
 **/

#ifndef __BINSEARCH__
#define __BINSEARCH__

/*******************************************************************************
 *                              INCLUDS
 ******************************************************************************/

#include "BinS_Types.h"

/**
 *  @Brief: declaration of used in file type
 * 
 *  @Type: BINSCH - type that bin search will be done in
 * 
 **/

/*******************************************************************************
 *                              DEFINE
 ******************************************************************************/

#ifndef __BinS_NOT_FOUND__
#define __BinS_NOT_FOUND__
    #define BinS_NOT_FOUND (0U)  /* by exception that 0 is eq. to false */
#endif

#ifndef __BinS_FOUND__
#define __BinS_FOUND__
    #define BinS_FOUND (!NOT_FOUND)  /* logical negation of false is true which is DECRISING wanted value*/
#endif


#ifndef __FALSE__
#define __FALSE__
    #define FALSE (0U)  /* by exception that 0 is eq. to false */
#endif

#ifndef __TRUE__
#define __TRUE__
    #define TRUE (!FALSE)  /* logical negation of false is true which is DECRISING wanted value*/
#endif

/*******************************************************************************
 *                              TYPEDEF
 ******************************************************************************/

/**
 *  @Brief: structure declared as an output from binarySearch function
 *          gives all needed information about given search
 *  @param1: index - gives place in tab that first occour of element to search was found
 *  @param2: foundValue - value that was given to search for, placed here for consistency of 
 *           all needed informations. If value was not found it's set to 0
 *  @param3: found - says if value was found (FOUND) or not (NOT_FOUND)
 **/
typedef struct
{
    BinS_I_TYPE    index;
    BinS_ATYPE foundValue;
    bool        found;

} BinS_result;

/*******************************************************************************
 *                              ENUMS
 ******************************************************************************/

typedef enum
{
    BinS_DECRISING = 0U,
    BinS_INCRESING = 1U,
    BinS_CONST = 2U

} BinS_MONOTONYE;

typedef enum
{
    BinS_SMALLER = 0U,
    BinS_BIGGER = 1U,
    BinS_EQUAL = 2U

} BinS_COMPARATORE;

/*******************************************************************************
 *                              DECLARATIONS
 ******************************************************************************/

/**
 * @Name: BinSearch_BinS - BinSearch is the name of the file.
 * @Brief: binary search req. that array is sorted inthis function it's unimpotant of order in which it is sorted
 *          !!! It is CRUCIAL to notice, that                     !!!
 *          !!! data type of array is definied as BinS_ATY typedef  !!!
 *          !!! under preprocesor flag__BinS_ATY_TYPE__             !!!
 *          which is default set to int32_tby this file
 * @Param1: length of array that is in Param2, the length of array have to be lower than 2^32
 * @Param2: array that we will do binary search on
 * @Param3: given value that we will search for
 * @Param4: pointer to function in which we could compare objects if returned type is traditional(BinS_COMPARATORE,float,etc.)
 *          it is possible to set it to NULL, so standard compare would be make.
 *          Important to notice 1: comparator gets 2 arguments with type of BinS_ATY.
 *          Important to notice 2: comparator return type of binarySearch_result
 * @Return: return structure wiich consist all important information from given search
 * 
 * @Limitations: Function does NOT sort arguments of givenArray_a they should be sorted before
 * @Note: Array can be sorted in either growing or decrising secuences
 * 
 **/ 
extern BinS_result BinS_BinSearch(const BinS_I_TYPE lengthOfArray_cui32,
                                       const BinS_ATYPE givenArray_a[ lengthOfArray_cui32 ],
                                       const BinS_ATYPE wantedElement,
                                       BinS_COMPARATORE(*comparator)(BinS_ATYPE arg1, BinS_ATYPE arg2)
                                      );

/**
 * @Name: BinS_Monotony - BinSearch is the name of the file.
 * @Brief: Function evaluate if given array is sorted in growing, or decrising order
 * @Param1: length of array that is in Param2, the length of array have to be lower than 2^32
 * @Param2: array on witch we will do evaluation
 * @Return: return type bool in GROWING or DECRISING, with the natural meaning of eleemnts
 * 
 * @Limitations: Function does NOT sort arguments of givenArray_a they should be sorted before
 * @Note: Array can be sorted in either growing or decrising secuences
 * 
 **/ 
extern BinS_MONOTONYE BinS_Monotony(const BinS_I_TYPE lengthOfArray_cui32,
                            const BinS_ATYPE givenArray_a[ lengthOfArray_cui32 ],
                            BinS_COMPARATORE(*comparator)(BinS_ATYPE arg1, BinS_ATYPE arg2)
                           );

#endif /* __BINSEARCH__ */