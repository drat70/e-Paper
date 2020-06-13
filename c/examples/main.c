#include <stdlib.h>     //exit()
#include <signal.h>     //signal()
#include "EPD_Test.h"   //Examples
#include "EPD_3in7.h"
void  Handler(int signo)
{
    //System Exit
    printf("\r\nHandler:exit\r\n");
    DEV_Module_Exit();

    exit(0);
}



int main(int argc, char **argv)
{


    // Exception handling:ctrl + c
    signal(SIGINT, Handler);
    int num = (rand() % (30 + 20 + 1)) - 20;   
    int num2 = (rand() % (100 - 0 + 1)) + 0;
    text_out(num,num2);
    // text_out(atoi(argv[1]),atoi(argv[2]));
    //EPD_2in13_V2_test();

    

    
    return 0;
}
