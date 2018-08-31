/*
 * RomanToInteger.c
 *
 *  Created on: Aug 28, 2018
 *      Author: dichris
 */

/*
 * Symbol       Value
 *	I             1
 *	V             5
 *	X             10
 *	L             50
 *	C             100
 *	D             500
 *	M             1000
 *
 *  I can be placed before V (5) and X (10) to make 4 and 9.
 *  X can be placed before L (50) and C (100) to make 40 and 90.
 *  C can be placed before D (500) and M (1000) to make 400 and 900.
 *
 *	Input is guaranteed to be within the range from 1 to 3999.
 */

#include "app.h"

int getRomanValue(char c) {

	switch(c) {
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	default:
		return 0;
	}
}

int romanToInt(char* s) {

	int result = 0;

	if (!s || strlen(s) == 0) {
		return 0;
	}

	int len = strlen(s);
	char c;
	int i = len-1;
	char next_char = '\0';
	while (i >= 0) {
		c = s[i];
		int val = getRomanValue(c);
		if (val == 0)
			return 0;

		if ((c == 'I' && (next_char == 'V' || next_char == 'X')) ||
			(c == 'X' && (next_char == 'L' || next_char == 'C')) ||
			(c == 'C' && (next_char == 'D' || next_char == 'M'))) {
			result -= val;
		} else {
			result += val;
		}
		next_char = c;
		i--;
	}

	return result;
}

int testRomanToInt() {

	printf("%s: %d\n", "III", romanToInt("III"));
	printf("%s: %d\n", "IV", romanToInt("IV"));
	printf("%s: %d\n", "IX", romanToInt("IX"));
	printf("%s: %d\n", "LVIII", romanToInt("LVIII"));
	printf("%s: %d\n", "MCMXCIV", romanToInt("MCMXCIV"));

	return 0;
}
