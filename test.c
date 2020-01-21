#include <stdio.h>
#include <sys/types.h>

unsigned short hstate = 0xC0;
 
unsigned short hnext() {
	unsigned short next =
		((hstate & 0x08) >> 3) ^
		((hstate & 0x10) >> 4) ^
		((hstate & 0x20) >> 5) ^
		((hstate & 0x80) >> 7);
	hstate = (hstate >> 1) | (next << 15);
	return( hstate );
}

int main( char** argv, int argc ) {
	int i;
	for( i = 0; i < 65535; i++ ) {
		printf("%d\n", hnext());
	}
}