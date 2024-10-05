#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "revert_string.h"

void* getFunctionPointer(void* lib, const char* funcName) {
	void* fptr = dlsym(lib, funcName);
	if (!fptr) {
		fprintf(stderr, "Could not get function pointer for %s\n  error is: %s\n\n", funcName, dlerror());
		return NULL;
	}
	return fptr;
}

int main(int argc, char *argv[])
{
/*
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
	void (*fptr_null)(int);
#pragma GCC diagnostic pop
	void (*fptr_RevertString)(char*);
	

	void* tq84_lib = dlopen("libtq84.a", RTLD_LAZY | RTLD_GLOBAL);
	if (!tq84_lib) {
		fprintf(stderr, "Could not open libtq84.so\n");
		exit(1);
	}

	fptr_RevertString = getFunctionPointer(tq84_lib, "RevertString");
	fptr_null = getFunctionPointer(tq84_lib, "doesNotExist");
	if (argc != 2)
	{
		printf("Usage: %s string_to_revert\n", argv[0]);
		return -1;
	}
	*/
	char *reverted_str = malloc(sizeof(char) * (strlen(argv[1]) + 1));
	strcpy(reverted_str, argv[1]);

	RevertString(reverted_str);

	printf("Reverted: %s\n", reverted_str);
	free(reverted_str);
	return 0;
}

