typedef struct geo_array {
	double  *x;
	double  *y;
	char    *status;
	int      count;
} geo_array;

geo_array *geo_array_ctor(int element_count);
void geo_array_dtor(geo_array *points);
