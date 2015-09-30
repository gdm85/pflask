/*
 * The process in the flask.
 *
 * Copyright (c) 2013, gdm85
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <string.h>

#include "cmdline.h"

#include "printf.h"
#include "util.h"
#include "toml.h"

struct flask {
	char name[256];
	struct gengetopt_args_info args;
};

// I once had a bad dream about a function called like this
char *file_get_contents(char *file_name, long *adj_bufsize) {
	int rc;
	char *source = NULL;
	FILE *fp = fopen(file_name, "r");
	sys_fail_if(fp == NULL, "could not open file");

	// seek EOF
	rc = fseek(fp, 0L, SEEK_END);
       	sys_fail_if(rc != 0, "fseek error");

	long bufsize = ftell(fp);
        sys_fail_if(bufsize == -1, "ftell error");

	// quit if file is too large
	sys_fail_if(bufsize > 64 * 1024, "file larger than 64K");

	*adj_bufsize = bufsize + 1;

	source = malloc(sizeof(char) * *adj_bufsize);
        sys_fail_if(source == NULL, "OOM error");

	source[bufsize] = '\0';

	// rewind
	rc = fseek(fp, 0L, SEEK_SET);
       	sys_fail_if(rc != 0, "fseek error");

	// be brave: read entire file into memory
        size_t size = fread(source, sizeof(char), bufsize, fp);
        sys_fail_if(size == 0, "file read error");

	fclose(fp);

	return source;
}

void read_flask(char *file_name, char *flask_name) {
	long size;
	char *source = file_get_contents(file_name, &size);

	struct toml_node *root;
	struct toml_node *node;

	toml_init(&root);
	toml_parse(root, source, size);

	node = toml_get(root, flask_name);

	if (node == NULL) {
		fail_printf("Cannot find flask '%s'", flask_name);
		return;
	}

	node = toml_get(node, "user");
	if (node == NULL) {
		fail_printf("Cannot find user field");
		return;
	}

	toml_dump(node, stdout);
	toml_free(root);

	free(source);
}
