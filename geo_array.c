#include <stdlib.h>

#include "geo_array.h"

geo_array *geo_array_ctor(int element_count)
{
	geo_array *tmp;

	tmp = malloc(sizeof(geo_array));
	tmp->count = element_count;
	tmp->status = calloc(1, element_count);
	tmp->x = (double*) calloc(1, element_count * sizeof(double));
	tmp->y = (double*) calloc(1, element_count * sizeof(double));

	return tmp;
}
	
void geo_array_dtor(geo_array *points)
{
	free(points->status);
	free(points->x);
	free(points->y);
	free(points);
}
