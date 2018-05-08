/*
 * Copyright (C) 2016 Chi-kwan Chan
 * Copyright (C) 2016 Steward Observatory
 *
 * This file is part of lux.
 *
 * lux is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * lux is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
 * License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with lux.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <CL/opencl.h>
#include <stdio.h>

int main()
{
	cl_platform_id p[8];
	cl_uint i, np;

	cl_int f = clGetPlatformIDs(sizeof(p)/sizeof(cl_platform_id), p, &np);
	if(f) {
		fprintf(stderr, "Failed to obtain platform IDs\n");
		return -1;
	}

	printf("%d platform%s found:\n", np, np > 1 ? "s are" : " is");
	for(i = 0; i < np; ++i) {
		char   buf[1024];
		size_t l;

		f = clGetPlatformInfo(p[i], CL_PLATFORM_NAME,
		                      sizeof(buf), buf, &l);
		if(np == 1)
			printf("\t* %s ", buf);
		else
			printf("\t%d. %s ", i, buf);

		f = clGetPlatformInfo(p[i], CL_PLATFORM_VENDOR,
		                      sizeof(buf), buf, &l);
		printf("by %s: ", buf);

		f = clGetPlatformInfo(p[i], CL_PLATFORM_VERSION,
		                      sizeof(buf), buf, &l);
		printf("%s\n", buf);
	}

	return 0;
}
