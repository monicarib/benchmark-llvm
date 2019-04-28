#include "whetstone.h"

int main(int argc, char *argv[])
{
    int resultado = whetstone(argc, argv);
    if (resultado - (long)9300000 > 0)
        return 1;

	return(10);
}
