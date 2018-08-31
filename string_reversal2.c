#include "app.h"

char* stringReversal (char str[], int len) {

	if (!str || len == 0) {
		printf("Error: empty string\n");
		return NULL;
	}
	if (len == 1) {
		return str;
	}
	char tmp;
	int i, j;
	for (i=0,j=len-1; j > i; i++, j--) {
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
	return str;
}


int testStringReversal () {

	char str[] = "reversal";

	char *rev = stringReversal(str, strlen(str));
	printf("Reversed string: %s\n",rev);

	char str1[] = "test";
	rev = stringReversal(str1, strlen(str1));
	printf("Reversed string: %s\n",rev);

	char str2[] = "";
	rev = stringReversal(str2, strlen(str2));
	printf("Reversed string: %s\n",rev);

	char str3[] = "t";
	rev = stringReversal(str3, strlen(str3));
	printf("Reversed string: %s\n",rev);

	char str4[] = "tell him go to hell";
	rev = stringReversal(str4, strlen(str4));
	printf("Reversed string: %s\n",rev);

	char str5[] = "A man, a plan, a canal: Panama";
	rev = stringReversal(str5, strlen(str5));
	printf("Reversed string: %s\n",rev);

	return 0;
}

