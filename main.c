#include <inttypes.h>


#include "BinS_Types.h"
#include "BinS.h"
#include <stdio.h>



int main(void)
{

    const BinS_I_TYPE len = UINT64_MAX >> 47ULL;
    BinS_ATYPE arr[ len ];

    BinS_I_TYPE i = 0;
    for(i = 0; i < len; i++)
    {
        arr[ i ] = i;
    }

    BinS_result result = BinS_BinSearch(len, arr, 0, NULL);

    return 0;
}
