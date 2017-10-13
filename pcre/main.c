#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pcre.h"
#define PCRE2_CODE_UNIT_WIDTH 8
#include "include/pcre2.h"

/* Add function signatures here */

int main(int argc, char **argv) {
	PCRE2_SPTR pattern;
	pcre2_code *re;
	PCRE2_SIZE *ovector;
	int crlf_is_newline;
	int errornumber;
	int erroroffset;
	int rc;
	pcre2_match_data *match_data;

	char *str_pattern = strdup("Mari[oa]");
	char * string = argv[1];
	pattern = str_pattern;
	
	re = pcre2_compile(
		pattern,
		PCRE2_ZERO_TERMINATED,
		0,					// Options (default)
		&errornumber,
		&erroroffset,
		NULL
	);
	
	match_data = pcre2_match_data_create_from_pattern(re, NULL);
	rc = pcre2_match(
		re,
		string,
		strlen(string),
		0,					// Offset
		0,					// Options (default)
		match_data,
		NULL			
	);

	if (rc < 0) {
		printf("There was an eror!\n");
		return 1;
	}

	ovector = pcre2_get_ovector_pointer(match_data);
	printf("Match succeeded at offset %d\n", (int) ovector[0]);

    return 0;
}
