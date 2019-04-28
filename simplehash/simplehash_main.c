int simplehash(int argc, char *argv[]);
#pragma DATA_ALIGN(x, 8);  
int main(int argc, char *argv[]) {
 #pragma monitor start
    int result = (int)simplehash(argc,argv);
 #pragma monitor stop
    printf("resultado deve ser %d\n", result);
    if( result != 159){
        return 1;
    }
    return 10;
}

