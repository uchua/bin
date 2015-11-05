/*
 *	Simple Rail Fence Cipher
 *	Author: Ian Lantzy
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#ifndef MAX_CIPH_RAILS
#define MAX_CIPH_RAILS 256
#endif

#ifndef DEFAULT_NUM_RAILS
#define DEFAULT_NUM_RAILS 2
#endif

const char * USAGE_MESSAGE = "Usage: [OPTIONS] [PLAIN_TEXT]\n";

char * ciph_rails[MAX_CIPH_RAILS];
char * cipher_text;

inline void rail_num_invalid(int num_rails) {
	printf("Invalid number of cipher rails: %d\nMax number of cipher rails: %d\n", num_rails, MAX_CIPH_RAILS);
	fputs(USAGE_MESSAGE, stdout);
}

inline int rail_num_valid(int num_rails) {
	return (num_rails > 0 && num_rails < MAX_CIPH_RAILS);
}

inline void alloc_rails(int rail_size, int num_rails) {
	if (rail_num_valid(num_rails)) {
		for (int i = 0; i < num_rails; i++) {
			ciph_rails[i] = malloc(sizeof(char) * rail_size);
		}
	}
	else {
		rail_num_invalid(num_rails);
	}
}

inline int calc_rail_size(size_t pt_str_len, int num_rails) {
	int r = pt_str_len / num_rails;
	while ((pt_str_len - (r * num_rails)) > 0) {
		r++;
	}
	return r;
}

void encipher(char * pt, size_t pt_str_len, int num_rails) {
	char c;
	int pt_strnlen = strnlen(pt, pt_str_len);
	printf("%i\n",pt_strnlen);
	int rail_size = calc_rail_size(pt_strnlen, num_rails);
	printf("%i\n",rail_size);
	alloc_rails(rail_size, num_rails);
	cipher_text = malloc(pt_strnlen * sizeof(char));
	int i, j, k;
	k = 0;
	if (num_rails > 2) {
		fputs(">2\n",stdout);
		int s, t, u;
		s = num_rails - 2;
		t = num_rails + s;
		// First
		for (i = 0; i < num_rails; i++) {
			ciph_rails[i][0] = pt[i];
		}
		// Rest
		for (; i < pt_str_len; i+=t) {
			k++;
			u = i;
			for (j = s; j >= 0 && u < pt_str_len; j--) {
				ciph_rails[j][k] = pt[u];
				u++;
			}
			for (j = 1; j < num_rails && u < pt_str_len; j++) {
				ciph_rails[j][k+1] = pt[u];
				u++;
			}
		}
	}
	else { // Must be 2 rails
		fputs("=2\n",stdout);
		for (i = 0; i < pt_str_len; i+=2) {
			ciph_rails[0][k] = pt[i];
			fputc(ciph_rails[0][k], stdout);
			ciph_rails[1][k] = pt[i+1];
			fputc(ciph_rails[1][k], stdout);
			fputc('\n', stdout);
			k++;
		}
	}
	k = 0;
	for (i = 0; i < num_rails; i++) {
		for (j = 0; j < rail_size; j++) {
			if ((c = ciph_rails[i][j]) != '\0') {
				cipher_text[k] = c;
				fputc(c,stdout);
				k++;
			}
			else fputc('!',stdout);
		}
	}
}

int main(int argc, const char * argv[]) {
	char * pt = NULL; // Set to NULL to avoid segfault w/ getline
	size_t pt_str_len;
	int num_rails;
	if (argc == 1) {
		// Get plain text
		fputs("Plain Text: ", stdout);
		while (!(getline(&pt, &pt_str_len, stdin)));
		strtok(pt,"\n");

		// Get number of rails
		fputs("# of Rails: ", stdout);
		while(!(scanf("%i", &num_rails)));

		printf("PT: %s\nPT_STR_LEN: %d\nNUM_RAILS: %d\n",pt,(int)pt_str_len,num_rails);
		encipher(pt, pt_str_len, num_rails);

		return 0;
	}
	else {
		fputs(USAGE_MESSAGE, stdout);
		return 1;
	}
}
