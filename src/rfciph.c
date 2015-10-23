/*
 * Simple Rail Fence Cipher
 * Author: Ian Lantzy
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef MAX_CIPH_RAILS
#define MAX_CIPH_RAILS 256
#endif

#ifndef DEFAULT_NUM_RAILS
#define DEFAULT_NUM_RAILS 2
#endif

char * ciph_rails[MAX_CIPH_RAILS];
char * cipher_text;

void rail_num_invalid(int num_rails) {
	printf("Invalid number of cipher rails: %d\n", num_rails);
}

int rail_num_valid(int num_rails) {
	return (num_rails > 0 && num_rails < MAX_CIPH_RAILS);
}

void alloc_rails(int rail_size, int num_rails) {
	if (rail_num_valid(num_rails)) {
		int i = 0;
		while (i < num_rails) {
			ciph_rails[i] = malloc(rail_size * sizeof(char));
			i++;
		}
	}
	else {
		rail_num_invalid(num_rails);
	}
}

int calc_rail_size(size_t pt_str_len, int num_rails) {
	int r = pt_str_len / num_rails;
	while ((pt_str_len - (r * num_rails)) > 0) {
		r++;
	}
	return r;
}

void encipher(char * pt, size_t pt_str_len, int num_rails) {
	char c;
	int rail_size = calc_rail_size(pt_str_len, num_rails);
	alloc_rails(rail_size, num_rails);
	cipher_text = malloc(pt_str_len * sizeof(char));
	int i, j, k;
	k = 0;
	for (i = 0; i < pt_str_len; i+=num_rails) {
		for (j = 0; j < num_rails && (i+j) < pt_str_len; j++) {
			ciph_rails[j][k] = pt[i+j];
		}
		k++;
	}
	for (i = 0; i < j; i++) {
		ciph_rails[i][k] = '\0';
	}
	while (j < num_rails) {
		ciph_rails[j][k-1] = '\0';
		j++;
	}
	k = 0;
	for (i = 0; i < num_rails; i++) {
		j = 0;
		while ((c = ciph_rails[i][j]) != '\0') {
			cipher_text[k] = c;
			j++;
			k++;
		}
	}
}

int main(int argc, const char * argv[]) {
	char * pt;
	size_t pt_str_len;
	int num_rails;
	if (argc == 1) {
		fputs("Input Plain Text Here: ", stdout);
		getline(&pt, &pt_str_len, stdin);
		strtok(pt,"\n");
		fputs("Input Number of Rails: ", stdout);
		scanf("%d", &num_rails);
		encipher(pt, pt_str_len, num_rails);
		printf("%s\n", cipher_text);
		return 0;
	}
	else if (argc > 1) {
		return 0;
	}
	else {
		return 1;
	}
}
