#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_RAILS 11

#define CHAR_BACKWARDS 'A' > 'Z' // Check just in case

char shift(char c, int key);

#if CHAR_BACKWARDS
char shift(char c, int key) {
	char d = ((c + key) > 'A') ? ((c + key) - 26) : c + key;
	return d;
}
#else
char shift(char c, int key) {
	char d = ((c + key) > 'Z') ? ((c + key) - 26) : c + key;
	return d;
}
#endif

void derail(char * src, int len, int rails) {
	int i, j, jmp, k;
	jmp = (len / rails);
	if ((len - (jmp * rails)) > 0) {
		jmp++;
	}
	for (i = 0; i < jmp; i++) {
		for (j = 0; j < rails; j++) {
			if ((k = i+(j*jmp)) < len) {
				putc(src[k], stdout);
			}
			else break;
		}
	}
	putc('\n', stdout);
}

int main (int argc, const char ** argv) {
	if (argc > 1) {
		int len = 0;
		while (argv[1][len] != '\0') len++;
		char str[len+1];
		printf("%d\n", len);
		char caesar[25][len+1];

		int i, j;
		for (i = 0; i < len; i++) {
			str[i] = toupper(argv[1][i]);
		}
		str[len] = '\0';
		printf("%s\n\n", str);

		for (i = 0; i < 26; i++) {
			j = 0;
			while (str[j] != '\0' && j < len) {
				caesar[i][j] = shift(str[j], i+1);
				j++;
			}
			caesar[i][len] = '\0';
			for (j = 1; j <= MAX_RAILS; j++) {
				derail(caesar[i], len, j);
			}
			putc('\n', stdout);
		}

		return 0;
	}
	else {
		return 1;
	}
}
