#include "revert_string.h"
#include <string.h>
void RevertString(char *str)
{
	char buf;
	for (int i = 0; i < strlen(str)/2; i++) {
		buf=str[i];
		str[i]=str[strlen(str)-i-1];
		str[strlen(str) - i-1]=buf;
	}
}

