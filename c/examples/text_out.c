/*****************************************************************************
* | File      	:   EPD_2IN13_V2_test.c
* | Author      :   Waveshare team, drat70
* | Function    :   2.13inch e-paper(V2), write out some basic numbers
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2020-06-06
* | Info        :
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include "EPD_Test.h"
#include "EPD_2in13_V2.h"

int text_out(void)
{
    printf("EPD_2IN13_V2_test Demo\r\n");
    if(DEV_Module_Init()!=0){
        return -1;
    }

    printf("e-Paper Init and Clear...\r\n");
    EPD_2IN13_V2_Init(EPD_2IN13_V2_FULL);
    EPD_2IN13_V2_Clear();
    DEV_Delay_ms(500);

    //Create a new image cache
    UBYTE *BlackImage;
    /* you have to edit the startup_stm32fxxx.s file and set a big enough heap size */
    UWORD Imagesize = ((EPD_2IN13_V2_WIDTH % 8 == 0)? (EPD_2IN13_V2_WIDTH / 8 ): (EPD_2IN13_V2_WIDTH / 8 + 1)) * EPD_2IN13_V2_HEIGHT;
    if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        return -1;
    }
    printf("Paint_NewImage\r\n");
    Paint_NewImage(BlackImage, EPD_2IN13_V2_WIDTH, EPD_2IN13_V2_HEIGHT, 270, WHITE);
    Paint_SelectImage(BlackImage);
    Paint_SetMirroring(MIRROR_HORIZONTAL); //
    Paint_Clear(WHITE);



#if 1   // Drawing on the image
    printf("Drawing\r\n");
    //1.Select Image
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);

    // 2.Drawing on the image
    
    Temp = 95;
    RH = 12;
    
    Paint_DrawString_EN(10, 10, "Temp:", &Font24, WHITE, BLACK);
    Paint_DrawString_EN(10, 60, "RH:", &Font24, WHITE, BLACK);
    
    Paint_DrawNum(80, 10, Temp, &Font24, BLACK, WHITE);
    Paint_DrawNum(80, 60, RH, &Font24, BLACK, WHITE);

    // Paint_DrawLine(20, 10, 70, 60, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    // Paint_DrawLine(70, 10, 20, 60, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    // Paint_DrawRectangle(20, 10, 70, 60, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
    // Paint_DrawRectangle(85, 10, 135, 60, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);

    // Paint_DrawLine(45, 15, 45, 55, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
    // Paint_DrawLine(25, 35, 70, 35, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
    // Paint_DrawCircle(45, 35, 20, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
    // Paint_DrawCircle(110, 35, 20, WHITE, DOT_PIXEL_1X1, DRAW_FILL_FULL);

    // Paint_DrawString_EN(140, 15, "waveshare", &Font16, BLACK, WHITE);
    // Paint_DrawNum(140, 40, 123456789, &Font16, BLACK, WHITE);

    // Paint_DrawString_CN(140, 60, "ÄãºÃabc", &Font12CN, BLACK, WHITE);
    // Paint_DrawString_CN(5, 65, "Î¢Ñ©µç×Ó", &Font24CN, WHITE, BLACK);

    EPD_2IN13_V2_Display(BlackImage);
    DEV_Delay_ms(2000);
#endif


//    printf("Clear...\r\n");

//   EPD_2IN13_V2_Init(EPD_2IN13_V2_FULL);
//    EPD_2IN13_V2_Clear();
//    DEV_Delay_ms(2000);//Analog clock 1s

    printf("Goto Sleep...\r\n");
    EPD_2IN13_V2_Sleep();
    free(BlackImage);
    BlackImage = NULL;
    DEV_Delay_ms(1000);//Analog clock 1s

    // close 5V
    printf("close 5V, Module enters 0 power consumption ...\r\n");
    DEV_Module_Exit();
    
    return 0;
}

