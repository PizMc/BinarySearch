/**
 *  @Author: Self
 *  
 *  @Brief: File include standard types used in BinS files 
 *          And additional typedefs for array and index of array
 * 
 *  @Usage: It have to be include to all files using BinS functions,
 *          macros, or enums or any other element declared/ defined in BinS.h 
 * 
 *  @Limitations:   Please note that user can give floating point number
 *                  for indexing array, which is undesirable
 *  
 * 
 * @Date: 28.08.2018
 **/

#ifndef __BINS_TYPES_H__
#define __BINS_TYPES_H__

/*******************************************************************************
 *                              INCLUDS
 ******************************************************************************/

/**
 *  @Brief: includs for different int types
 *  @Note: it could be done probably by one of them,
 *         given 2 for consistency with different compilers
 *  @TODO: check if one of (stdint or inttypes) is enoug
 **/
#include <stdint.h>
#include <inttypes.h>

/** 
 * @Breief: for floating points types
 **/
#include <float.h>

/**
 * @Brief: for boolean typ consistency
 **/
#include <stdbool.h>


/*******************************************************************************
 *                              TYPEDEF
 ******************************************************************************/

/**
 *  @Brief: declaring new type for usage in binary search as default type - int32_t
 *  @Usage: If different type is wanted to be used in binary search, then it have to be
 *          ! typedef with name BinS_ATYPE
 *          ! and compilation flag __BinS_BINSTYPE_ATYPE__
 *          ! declared before including BinS_Types.h
 * 
 *          If diferent type for indexing array is needed:
 *          ! Shoulde be declared before include of file BinS_Types.h
 *          ! With #define compilation flag  __BinS_BINSTYPE_I_TYPE__
 *          ! and typedef name BinS_I_TYPE
 **/

#ifndef __BinS_BINSTYPE_ATYPE__
#define __BinS_BINSTYPE_ATYPE__
    typedef uint32_t BinS_ATYPE;    /* type of array elements */
#endif

#ifndef __BinS_BINSTYPE_I_TYPE__
#define __BinS_BINSTYPE_I_TYPE__
    typedef uint64_t BinS_I_TYPE;   /* type for indexing */
#endif


#endif /* __BINS_TYPES_H__ */