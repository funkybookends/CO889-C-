#include "numbits.hpp"

unsigned int num1bits(int i)
{
    // Convert i to unsigned, because the behaviour of right-shift is
    // implementation-dependent for negative values of signed integer
    // types.  Conversion of plain int to unsigned int is governed by
    // ISO14882:2011 Sec. 4.7 Para 2.
    unsigned int u = i;
    unsigned int ans = 0;
    while (u > 0) {
	ans += (u&1);
	u >>= 1;
    }
    return ans;
}

unsigned int num0bits(int i)
{
    
	return num1bits(~i); //returns the toggled count
}
