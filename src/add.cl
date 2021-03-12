__kernel void add(global const int *a, global int *b)
{
	int gid = get_global_id(0);
	b[gid] = a[gid]+a[gid];
}
