/*
 * StringToInteger.c
 *
 *  Created on: Aug 21, 2018
 *      Author: dichris
 */

#include "app.h"
#include <limits.h>

/*
 * 341: (0*10+3) + (3*10+4) + (
 */

int stringToInt (char *s) {

	long num = 0;
	int neg = 1;
	if (!s) {
		return 0;
	}
	int len = strlen(s);
	int i = 0;
	//get first character non-whitespace
	while (i < len) {
		if (s[i] == ' ') {
			i++;
			continue;
		} else {
			if ((s[i] < '0' || s[i] > '9') && (s[i] != '-') && (s[i] != '+')) {
				return 0;
			}
			if (s[i] == '-') {
				neg = -1;
				i++;
			} else if (s[i] == '+') {
				i++;
			}
			break;
		}
	}

	while (i < len) {
		if (s[i] < '0' || s[i] > '9') {
			break;
		}
		num = num*10 + (s[i] - '0');
		if (num >= INT_MAX) {
			break;
		}
		i++;
	}

	num = num*neg;
	if (num <= INT_MIN)
		return INT_MIN;
	else if (num >= INT_MAX)
		return INT_MAX;
	else
		return num;
}

int testatoi() {

	char str[] = "42";
	printf("%s: %d\n", str, stringToInt(str));

	char str1[] = "   -+42";
	printf("%s: %d\n", str1, stringToInt(str1));

	char str2[] = "4193 with words 90";
	printf("%s: %d\n", str2, stringToInt(str2));

	char str3[] = "words and 987";
	printf("%s: %d\n", str3, stringToInt(str3));

	char str4[] = "-91283472332";
	printf("%s: %d\n", str4, stringToInt(str4));

	char str5[] = "2147483648.1";
	printf("%s: %d\n", str5, stringToInt(str5));

	return 0;
}

