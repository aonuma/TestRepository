#include <iostream>
#include <cstring>

// print bit pattern of argument inArg (which can be any type)

// this header file includes implementation, not just declaration
// assuming that it will be complied by g++
// which can not compile cpp files including templates

template <typename T> void BitPrint(T inArg)
{
	int lBytes = sizeof(T);
	int lBits = lBytes * 8;
	char lContainer[lBytes]; // data container, using that the size of char is 1 byte

	memcpy(lContainer, &inArg, lBytes);

	int i, j, lTmp;
	for(i=lBytes-1; i>=0; i--)
	{
		for(j=sizeof(lContainer[i])*8-1; j>=0; j--)
		{
			lTmp = lContainer[i] & (1<<j);
			std::cout << (lTmp?1:0); // false: 0, true: otherwise
		}
		std::cout << " ";
	}
	std::cout << std::endl;
}
