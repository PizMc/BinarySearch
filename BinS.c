/**
 *  @Author: Self
 *  
 *  @Brief: Gives definitions for file BinS.h
 *          Creates functionality of binary search for any type
 * 
 *  @Usage: To make binary search on an array BinS_Search() should be used
 *          if type of arr elements is not standard int, int64 etc. 
 *          Typedef for BinS_ATY should be changed. By default is set 
 *          to uint32_t, but #define __BinS_ATY_TYPE__ overrides it
 * 
 *          Monotony() shows if the table is sorted in decrising
 *          or increasing order
 * 
 *  @Limitations:   With given implementation max length of array
 *                  is limited by max: BinS_I_TYPE
 *                  Another limitation is that array is by default 
 *                  taken as sorted. It is not checking against
 *                  that prediction.
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
 * @Date: 1.08.2018
 **/

/*******************************************************************************
 *                              INCLUDS
 ******************************************************************************/

/**
 *  @Brief: includs for types and declarations for binary search
 **/
#include "BinS.h"

/**
 *  @Brief: included for NULL declaration
 *  @Note: can be deleted when stdtypes powstanie
 **/
#include <stdlib.h>

/*******************************************************************************
 *                              DEFINE
 ******************************************************************************/

#define BinS_ARR_LEN(end, begin)   ((end) - (begin))

#define BinS_INIT(x) BinS_result x = {.index = 0U, \
                              /* casting is safe since 0 would be the same for all types */ \
                            .foundValue = (BinS_ATYPE)0U, \
                            .found = BinS_NOT_FOUND \
                           } \


/*******************************************************************************
 *                              TYPEDEF
 ******************************************************************************/

/*******************************************************************************
 *                              DECLARATIONS
 ******************************************************************************/


/**
 * @Name: BinSearch_BinS - BinSearch is the name of the file.
 * @Brief: binary search req. that array is sorted inthis function it's unimpotant of order in which it is sorted
 *          !!! It is CRUCIAL to notice, that                     !!!
 *          !!! data type of array is definied as BinS_ATYPE typedef  !!!
 *          !!! under preprocesor flag__BinS_ATYPE_TYPE__             !!!
 *          which is default set to int32_tby this file
 * @Param1: length of array that is in Param2, the length of array have to be lower than 2^32
 * @Param2: array that we will do binary search on
 * @Param3: given value that we will search for
 * @Param4: pointer to function in which we could compare objects if returned type is traditional(BinS_COMPARATORE,float,etc.)
 *          it is possible to set it to NULL, so standard compare would be make.
 *          Important to notice 1: comparator gets 2 arguments with type of BinS_ATYPE.
 *          Important to notice 2: comparator return type of binarySearch_result
 *          > comparator returns enum of BinS_MONOTONY enum
 * 
 * 
 * @Return: return structure wiich consist all important information from given search
 * 
 * @Limitations: Function does NOT sort arguments of givenArray_a they should be sorted before
 * @Note: Array can be sorted in either growing or decrising secuences
 * 
 **/ 
extern BinS_result BinS_Search(const BinS_I_TYPE lengthOfArray_cui32,
                               const BinS_ATYPE givenArray_a[ lengthOfArray_cui32 ],
                               const BinS_ATYPE wantedElement,
                               BinS_COMPARATORE(*comparator)(BinS_ATYPE arg1, BinS_ATYPE arg2)
                              );

/**
 * @Name: BinSearch_BinS - BinSearch is the name of the file.
 * @Brief: Gives monotony of sorted array Dec. INcr. Const.
 * @Param1: length of array that is in Param2, the length of array have to be lower than 2^32
 * @Param2: array that we will do binary search on 
 * @Param3: pointer to function in which we could compare objects if returned type is traditional(BinS_COMPARATORE,float,etc.)
 *          it is possible to set it to NULL, so standard compare would be make.
 *          Important to notice 1: comparator gets 2 arguments with type of BinS_ATYPE.
 *          Important to notice 2: comparator return type of binarySearch_result
 *          > comparator returns enum of BinS_MONOTONY enum
 * 
 * @Return: return structure wiich consist all important information from given search
 * 
 * @Limitations: Function does NOT sort arguments of givenArray_a they should be sorted before
 * @Note: Array can be sorted in either growing or decrising secuences
 * 
 **/ 
extern BinS_MONOTONYE BinS_Monotony(const BinS_I_TYPE lengthOfArray_cui32,
                                    const BinS_ATYPE givenArray_a[ lengthOfArray_cui32 ],
                                    BinS_COMPARATORE(*comparator)(BinS_ATYPE arg1, BinS_ATYPE arg2)
                                   );



static BinS_result BinSearchStd(const BinS_I_TYPE lengthOfArray_cui32,
                                     const BinS_ATYPE givenArray_a[ lengthOfArray_cui32 ],
                                     const BinS_ATYPE wantedElement
                                    );
static BinS_result BinSearchUsr(const BinS_I_TYPE lengthOfArray_cui32,
                                     const BinS_ATYPE givenArray_a[ lengthOfArray_cui32 ],
                                     const BinS_ATYPE wantedElement,
                                     BinS_COMPARATORE(*comparator)(BinS_ATYPE arg1, BinS_ATYPE arg2)
                                 );
static BinS_result BinSearchStdDecr(const BinS_I_TYPE lengthOfArray_cui32,
                                 const BinS_ATYPE givenArray_a[ lengthOfArray_cui32 ],
                                 const BinS_ATYPE wantedElement
                                );
static BinS_result BinSearchStdIncr(const BinS_I_TYPE lengthOfArray_cui32,
                                 const BinS_ATYPE givenArray_a[ lengthOfArray_cui32 ],
                                 const BinS_ATYPE wantedElement
                                );
static BinS_result BinSearchUsrIncr(const BinS_I_TYPE lengthOfArray_cui32,
                                     const BinS_ATYPE givenArray_a[ lengthOfArray_cui32 ],
                                     const BinS_ATYPE wantedElement,
                                     BinS_COMPARATORE(*comparator)(BinS_ATYPE arg1, BinS_ATYPE arg2)
                                 );
static BinS_result BinSearchUsrDecr(const BinS_I_TYPE lengthOfArray_cui32,
                                     const BinS_ATYPE givenArray_a[ lengthOfArray_cui32 ],
                                     const BinS_ATYPE wantedElement,
                                     BinS_COMPARATORE(*comparator)(BinS_ATYPE arg1, BinS_ATYPE arg2)
                                 );                                                               
/********************************************************************************
*                               EXTERN DEFINITIONS
*********************************************************************************/
/**
 * @Name: BinSearch_BinS - BinSearch is the name of the file.
 * @Brief: binary search req. that array is sorted inthis function it's unimpotant of order in which it is sorted
 *          !!! It is CRUCIAL to notice, that                     !!!
 *          !!! data type of array is definied as BinS_ATYPE typedef  !!!
 *          !!! under preprocesor flag__BinS_ATYPE_TYPE__             !!!
 *          which is default set to int32_tby this file
 * @Param1: length of array that is in Param2, the length of array have to be lower than 2^32
 * @Param2: array that we will do binary search on
 * @Param3: given value that we will search for
 * @Param4: pointer to function in which we could compare objects if returned type is traditional(BinS_COMPARATORE,float,etc.)
 *          it is possible to set it to NULL, so standard compare would be make.
 *          Important to notice 1: comparator gets 2 arguments with type of BinS_ATYPE.
 *          Important to notice 2: comparator return type of BinS_COMPARATORE
 *                                 if arg2 is Biger then arg1 then BinS_BIGGER is returned
 *                                 if arg2 is Smaller then arg1 then BinS_SMALLER is returned
 *                                 if arg2 == arg1 then BinS_CONST is returned
 *                                 all values of BinS_MONOTONY enum
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
                                 )
{
   /* BinS_result result_s = Init(); now usingmacro */

   BinS_INIT(result_s);

    /* if comparator is eq. NULL then user function is not given,
    so my own comparasion is made */
    if(NULL == comparator)
    {
        result_s = BinSearchStd(lengthOfArray_cui32, givenArray_a, wantedElement);
    }
    else
    {
        result_s = BinSearchUsr(lengthOfArray_cui32, givenArray_a, wantedElement, comparator);
    }

    return result_s;
}

/**
 * @Name: BinS_Monotony - BinSearch is the name of the file.
 * @Brief: Function evaluate if given array is sorted in growing, or decrising order
 * @Param1: length of array that is in Param2, the length of array have to be lower than 2^32
 * @Param2: array on witch we will do evaluation
 * @Return: return enum type BinS_MONOTONYE which have natuarl desc. of returned values
 * 
 * @Limitations: Function does NOT sort arguments of givenArray_a they should be sorted before
 * @Note: Array can be sorted in either growing or decrising secuences
 * 
 **/ 
extern BinS_MONOTONYE BinS_Monotony(const BinS_I_TYPE lengthOfArray_cui32,
                            const BinS_ATYPE givenArray_a[ lengthOfArray_cui32 ],
                            BinS_COMPARATORE(*comparator)(BinS_ATYPE arg1, BinS_ATYPE arg2)
                           )
{
    BinS_MONOTONYE monotony_e = BinS_DECRISING;
    BinS_I_TYPE first_ityp = 0U;
    BinS_I_TYPE last_ityp = lengthOfArray_cui32 - (BinS_I_TYPE)1ULL; /* bc array numering starts from 0 */
    BinS_COMPARATORE cprResult_e = BinS_EQUAL;

    /* if there is special comparator, then use it */
    if (NULL != comparator)
    {
        /* casting is safe, since it is essentialy same type, and difference is only in naming, also it is casting to smaller ty*/
        cprResult_e = (BinS_COMPARATORE)comparator(givenArray_a[ first_ityp ], givenArray_a[ last_ityp ]);

        if (BinS_SMALLER ==  cprResult_e)
        {
            monotony_e = BinS_DECRISING;
        }
        else if (BinS_EQUAL == cprResult_e)
        {
            monotony_e = BinS_CONST;
        }
        else    /* true: BinS_BIGGER == cprResult_e  */
        {
            monotony_e = BinS_INCRESING;
        }
    }
    /* there's nospecial cpr use standard comaparation */
    else
    {
        if (givenArray_a[ first_ityp ] > givenArray_a[ last_ityp ])
        {
            monotony_e = BinS_DECRISING;
        }
        else if (givenArray_a[ first_ityp ] < givenArray_a[ last_ityp ])
        {
            monotony_e = BinS_INCRESING;
        }
        else    /* true: arr[0] == arr[last] */
        {
            monotony_e = BinS_CONST;
        }
    }/* if (NULL == comparator) */

    return monotony_e;
}



/********************************************************************************
*                               STATIC DEFINITIONS
*********************************************************************************/
/*
static BinS_result BinSearchStdIncr(const BinS_I_TYPE lengthOfArray_cui32,
                                 const BinS_ATYPE givenArray_a[ lengthOfArray_cui32 ],
                                 const BinS_ATYPE wantedElement
                                );
*/


static BinS_result BinSearchStd(const BinS_I_TYPE lengthOfArray_cui32,
                                     const BinS_ATYPE givenArray_a[ lengthOfArray_cui32 ],
                                     const BinS_ATYPE wantedElement
                                    )
{
    BinS_result result_s = {
                            .index = 0U,
                            .foundValue = (BinS_ATYPE)0,
                            .found = FALSE
                         };
    /* unused variable
    BinS_I_TYPE index_ityp = lengthOfArray_cui32 / (BinS_I_TYPE)2U;*/ /* casting for proving intentional intiger divide */

    BinS_MONOTONYE monotony_e = BinS_Monotony(lengthOfArray_cui32, givenArray_a, NULL);

    if (BinS_DECRISING == monotony_e)
    {
        result_s = BinSearchStdDecr(lengthOfArray_cui32, givenArray_a, wantedElement);

    }/*true: BinS_DECRISING == monotony_e */
    else if (BinS_INCRESING == monotony_e)
    {
        result_s = BinSearchStdIncr(lengthOfArray_cui32, givenArray_a, wantedElement);

    }/* true: BinS_INCRESING == monotony_e */
    else
    /* true: BinS_CONST == monotony_e */
    {/* then all elements in givenArray_a are eq. */

        if(givenArray_a[ 0 ] == wantedElement)
        {
            result_s.index = 0U,
            result_s.foundValue = givenArray_a[ 0 ],
            result_s.found = TRUE;
        }
        else
        {
            /* this could be ommit, bc it was allraedy initialized */
            result_s.found = FALSE;  /* for constistency, compilator probbaly will get rid of that */                 
        }

    }/* true: BinS_CONST == monotony_e */

    return result_s;
}

static BinS_result BinSearchUsr(const BinS_I_TYPE lengthOfArray_cui32,
                                     const BinS_ATYPE givenArray_a[ lengthOfArray_cui32 ],
                                     const BinS_ATYPE wantedElement,
                                     BinS_COMPARATORE(*comparator)(BinS_ATYPE arg1, BinS_ATYPE arg2)
                                    )
{
    BinS_result result_s = {
                            .index = 0U,
                            .foundValue = (BinS_ATYPE)0,
                            .found = FALSE
                         };
    /* unused variable
    BinS_I_TYPE index_ityp = lengthOfArray_cui32 / (BinS_I_TYPE)2U;*/ /* casting for proving intentional intiger divide */

    BinS_MONOTONYE monotony_e = BinS_Monotony(lengthOfArray_cui32, givenArray_a, comparator);

    if (BinS_DECRISING == monotony_e)
    {
        result_s = BinSearchUsrDecr(lengthOfArray_cui32, givenArray_a, wantedElement, comparator);

    }/*true: BinS_DECRISING == monotony_e */
    else if (BinS_INCRESING == monotony_e)
    {
        result_s = BinSearchUsrIncr(lengthOfArray_cui32, givenArray_a, wantedElement, comparator);

    }/* true: BinS_INCRESING == monotony_e */
    else
    /* true: BinS_CONST == monotony_e */
    {/* then all elements in givenArray_a are eq. */

        if(givenArray_a[ 0 ] == wantedElement)
        {
            result_s.index = 0U,
            result_s.foundValue = givenArray_a[ 0 ],
            result_s.found = TRUE;
        }
        else
        {
            /* this could be ommit, bc it was allraedy initialized */
            result_s.found = FALSE;  /* for constistency, compilator probbaly will get rid of that */                 
        }

    }/* true: BinS_CONST == monotony_e */

    return result_s;
}


static BinS_result BinSearchStdDecr(const BinS_I_TYPE lengthOfArray_cui32,
                                     const BinS_ATYPE givenArray_a[ lengthOfArray_cui32 ],
                                     const BinS_ATYPE wantedElement
                                    )
{
    //BinS_result result_s = BinS_Init();
    BinS_INIT(result_s);

    BinS_I_TYPE index_ityp = 0U ;
    BinS_I_TYPE head_ityp = lengthOfArray_cui32 - (BinS_I_TYPE)1ULL; /* -1 bc numering array starts from 0 not from 1 */
    BinS_I_TYPE tail_ityp = 0U;
    
    while (head_ityp >= tail_ityp)
    {
        index_ityp = (head_ityp + tail_ityp) / (BinS_I_TYPE)2ULL;

        if (wantedElement > givenArray_a[ index_ityp ])
        {
            head_ityp = index_ityp - (BinS_I_TYPE)1ULL;
        }
        else if (wantedElement < givenArray_a[ index_ityp ])
        {
            tail_ityp = index_ityp + (BinS_I_TYPE)1ULL;
        }
        else/* exit loop */
        {
            /* misra violation */
            /* reason: The self readability of this loop is hight,
                and that break makes it faster and easier to read  */

            break;
        }
    }/* while (FALSE == result_s.found) */

    
    if (givenArray_a[ index_ityp ] == wantedElement)
    {
        result_s.found = TRUE;
        result_s.foundValue = givenArray_a[ index_ityp ];
        result_s.index = index_ityp;
    }

    return result_s;
}


static BinS_result BinSearchStdIncr(const BinS_I_TYPE lengthOfArray_cui32,
                                     const BinS_ATYPE givenArray_a[ lengthOfArray_cui32 ],
                                     const BinS_ATYPE wantedElement
                                    )
{
    //BinS_result result_s = BinS_Init();
    BinS_INIT(result_s);

    BinS_I_TYPE index_ityp = 0U ;
    BinS_I_TYPE head_ityp = lengthOfArray_cui32 - (BinS_I_TYPE)1ULL; /* -1 bc numering array starts from 0 not from 1 */
    BinS_I_TYPE tail_ityp = 0U;
    
    while (head_ityp >= tail_ityp)
    {
        index_ityp = (head_ityp + tail_ityp) / (BinS_I_TYPE)2ULL;

        if (wantedElement > givenArray_a[ index_ityp ])
        {
            tail_ityp = index_ityp + (BinS_I_TYPE)1ULL;
        }
        else if (wantedElement < givenArray_a[ index_ityp ])
        {
            head_ityp = index_ityp - (BinS_I_TYPE)1ULL;
        }
        else/*exit loop*/
        {
            /* misra violation */
            /* reason: The self readability of this loop is hight,
                and that break makes it faster and easier to read  */

            break;
        }
    }/* while (FALSE == result_s.found) */

    
    if (givenArray_a[ index_ityp ] == wantedElement)
    {
        result_s.found = TRUE;
        result_s.foundValue = givenArray_a[ index_ityp ];
        result_s.index = index_ityp;
    }

    return result_s;
}


static BinS_result BinSearchUsrIncr(const BinS_I_TYPE lengthOfArray_cui32,
                                const BinS_ATYPE givenArray_a[ lengthOfArray_cui32 ],
                                const BinS_ATYPE wantedElement,
                                BinS_COMPARATORE(*comparator)(BinS_ATYPE arg1, BinS_ATYPE arg2)
                                )
{
    //BinS_result result_s = BinS_Init();
   BinS_INIT(result_s);

    BinS_I_TYPE index_ityp = 0U ;
    BinS_I_TYPE head_ityp = lengthOfArray_cui32 - (BinS_I_TYPE)1ULL; /* -1 bc numering array starts from 0 not from 1 */
    BinS_I_TYPE tail_ityp = 0U;
    
    while (head_ityp >= tail_ityp)
    {
        index_ityp = (head_ityp + tail_ityp) / (BinS_I_TYPE)2ULL;

        //if (wantedElement > givenArray_a[ index_ityp ])
        if ( BinS_SMALLER == (BinS_COMPARATORE)comparator(wantedElement, givenArray_a[ index_ityp ]))
        {
            tail_ityp = index_ityp + (BinS_I_TYPE)1ULL;
        }
        else if (BinS_BIGGER == (BinS_COMPARATORE)comparator(wantedElement, givenArray_a[ index_ityp ]))
        {
            head_ityp = index_ityp - (BinS_I_TYPE)1ULL;
        }
        else/*exit loop*/
        {
            /* misra violation */
            /* reason: The self readability of this loop is hight,
                and that break makes it faster and easier to read  */

            break;
        }
    }/* while (FALSE == result_s.found) */

    
    if (givenArray_a[ index_ityp ] == wantedElement)
    {
        result_s.found = TRUE;
        result_s.foundValue = givenArray_a[ index_ityp ];
        result_s.index = index_ityp;
    }

    return result_s;
}


static BinS_result BinSearchUsrDecr(const BinS_I_TYPE lengthOfArray_cui32,
                                const BinS_ATYPE givenArray_a[ lengthOfArray_cui32 ],
                                const BinS_ATYPE wantedElement,
                                BinS_COMPARATORE(*comparator)(BinS_ATYPE arg1, BinS_ATYPE arg2)
                                )
{
    //BinS_result result_s = BinS_Init();
   BinS_INIT(result_s);

    BinS_I_TYPE index_ityp = 0U ;
    BinS_I_TYPE head_ityp = lengthOfArray_cui32 - (BinS_I_TYPE)1ULL; /* -1 bc numering array starts from 0 not from 1 */
    BinS_I_TYPE tail_ityp = 0U;
    
    while (head_ityp >= tail_ityp)
    {
        index_ityp = (head_ityp + tail_ityp) / (BinS_I_TYPE)2ULL;

        //if (wantedElement > givenArray_a[ index_ityp ])
        if ( BinS_SMALLER == (BinS_COMPARATORE)comparator(wantedElement, givenArray_a[ index_ityp ]))
        {
            head_ityp = index_ityp - (BinS_I_TYPE)1ULL;
        }
        else if (BinS_BIGGER == (BinS_COMPARATORE)comparator(wantedElement, givenArray_a[ index_ityp ]))
        {
            tail_ityp = index_ityp + (BinS_I_TYPE)1ULL;
        }
        else/*exit loop*/
        {
            /* misra violation */
            /* reason: The self readability of this loop is hight,
                and that break makes it faster and easier to read  */

            break;
        }
    }/* while (FALSE == result_s.found) */

    
    if (givenArray_a[ index_ityp ] == wantedElement)
    {
        result_s.found = TRUE;
        result_s.foundValue = givenArray_a[ index_ityp ];
        result_s.index = index_ityp;
    }

    return result_s;
}


/****
 *      TODO
 * 
 * 
 *  ADD COMENTS
 * ADD RULE HOW TO CREATE USER DEFINE COMPARATOR
 * TEST PROGRAM
 *
 * comparator should propbably return type of enum BinS_COMPARATORE not like now BinS_MONOTONY
 **********/