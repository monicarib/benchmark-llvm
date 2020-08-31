/* Sorts an array using quicksort */
void Quicksort( int a[], int l, int r) {
	/* quicksort the array A from start to finish */
	int i,j,x,w;

	i=l; j=r;
	x=a[(l+r) / 2];
	do {
	    while ( a[i]<x ) i = i+1;
	    while ( x<a[j] ) j = j-1;
	    if ( i<=j ) {
			w = a[i];
			a[i] = a[j];
			a[j] = w;
			i = i+1;    j= j-1;
		}
	} while ( i<=j );
	if ( l <j ) Quicksort(a,l,j);
	if ( i<r ) Quicksort(a,i,r);
}


void quicksort (int srtelements, int *sortlist) {
    Quicksort(sortlist,0,srtelements-1);  
}

