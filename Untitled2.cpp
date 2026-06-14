#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int main()
{
    int gd = DETECT, gm;
    int x, y;

    initgraph(&gd, &gm, "");

    setbkcolor(GREEN);
    cleardevice();

    /* Radius */
    int r = 70;

    /* Circle centers */
    int x1 = 220, y1 = 180;
    int x2 = 320, y2 = 180;
    int x3 = 270, y3 = 270;

    /* Paint all regions */
    for(x = 0; x < getmaxx(); x++)
    {
        for(y = 0; y < getmaxy(); y++)
        {
            int in1, in2, in3;
            int count;

            in1 = ((x-x1)*(x-x1) +
                   (y-y1)*(y-y1) <= r*r);

            in2 = ((x-x2)*(x-x2) +
                   (y-y2)*(y-y2) <= r*r);

            in3 = ((x-x3)*(x-x3) +
                   (y-y3)*(y-y3) <= r*r);

            count = in1 + in2 + in3;

            if(count == 1)
            {
                if(in1)
                    putpixel(x,y,LIGHTRED);
                else if(in2)
                    putpixel(x,y,LIGHTBLUE);
                else
                    putpixel(x,y,LIGHTMAGENTA);
            }
            else if(count == 2)
            {
                if(in1 && in2)
                    putpixel(x,y,YELLOW);
                else if(in1 && in3)
                    putpixel(x,y,LIGHTCYAN);
                else if(in2 && in3)
                    putpixel(x,y,WHITE);
            }
            else if(count == 3)
            {
                putpixel(x,y,LIGHTGREEN);
            }
        }
    }

    /* Circle outlines */
    setcolor(BLACK);
    setlinestyle(SOLID_LINE, 0, 2);
    
    circle(x1,y1,r);
    circle(x2,y2,r);
    circle(x3,y3,r);

    /* Set text properties */
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    setcolor(WHITE);
    settextjustify(CENTER_TEXT, CENTER_TEXT);

    /* Region 1: A only (LIGHTRED background) */
    setfillstyle(SOLID_FILL, LIGHTRED);
    bar(155, 155, 185, 175);
    outtextxy(170, 165, "1");

    /* Region 2: B only (LIGHTBLUE background) */
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(365, 155, 395, 175);
    outtextxy(380, 165, "2");

    /* Region 3: C only (LIGHTMAGENTA background) */
    setfillstyle(SOLID_FILL, LIGHTMAGENTA);
    bar(275, 335, 305, 355);
    outtextxy(290, 345, "3");

    /* Region 4: AnB only (YELLOW background) */
    setfillstyle(SOLID_FILL, YELLOW);
    bar(255, 150, 285, 170);
    setcolor(BLACK);
    outtextxy(270, 160, "4");
    setcolor(WHITE);

    /* Region 5: AnC only (LIGHTCYAN background) */
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    bar(195, 240, 225, 260);
    outtextxy(210, 250, "5");

    /* Region 6: BnC only (WHITE background) */
    setfillstyle(SOLID_FILL, WHITE);
    bar(315, 240, 345, 260);
    setcolor(BLACK);
    outtextxy(330, 250, "6");
    setcolor(WHITE);

    /* Region 7: AnBnC (LIGHTGREEN background) */
    setfillstyle(SOLID_FILL, LIGHTGREEN);
    bar(255, 215, 285, 235);
    setcolor(BLACK);
    outtextxy(270, 225, "7");
    setcolor(WHITE);

    /* Set labels for sets (A, B, C) with backgrounds */
    /* Label A */
    setfillstyle(SOLID_FILL, LIGHTRED);
    bar(155, 135, 185, 155);
    outtextxy(170, 145, "A");
    
    /* Label B */
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(365, 135, 395, 155);
    outtextxy(380, 145, "B");
    
    /* Label C */
    setfillstyle(SOLID_FILL, LIGHTMAGENTA);
    bar(280, 365, 310, 385);
    outtextxy(295, 375, "C");

    /* Legend */
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, BLACK);
    bar(5, 5, 200, 175);
    setcolor(WHITE);
    rectangle(5, 5, 200, 175);
    outtextxy(100, 20, "LEGEND");
    
    /* Legend items with their colored backgrounds */
    setfillstyle(SOLID_FILL, LIGHTRED);
    bar(15, 35, 35, 50);
    outtextxy(50, 42, "A only (1)");
    
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(15, 55, 35, 70);
    outtextxy(50, 62, "B only (2)");
    
    setfillstyle(SOLID_FILL, LIGHTMAGENTA);
    bar(15, 75, 35, 90);
    outtextxy(50, 82, "C only (3)");
    
    setfillstyle(SOLID_FILL, YELLOW);
    bar(15, 95, 35, 110);
    setcolor(BLACK);
    outtextxy(50, 102, "AnB only (4)");
    setcolor(WHITE);
    
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    bar(15, 115, 35, 130);
    outtextxy(50, 122, "AnC only (5)");
    
    setfillstyle(SOLID_FILL, WHITE);
    bar(15, 135, 35, 150);
    setcolor(BLACK);
    outtextxy(50, 142, "BnC only (6)");
    setcolor(WHITE);
    
    setfillstyle(SOLID_FILL, LIGHTGREEN);
    bar(15, 155, 35, 170);
    setcolor(BLACK);
    outtextxy(50, 162, "AnBnC (7)");
    setcolor(WHITE);

    /* Title */
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setfillstyle(SOLID_FILL, BLACK);
    bar(140, 25, 460, 55);
    setcolor(WHITE);
    outtextxy(300, 40, "THREE SET VENN DIAGRAM");
    
    /* Instructions */
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    setfillstyle(SOLID_FILL, BLACK);
    bar(150, getmaxy() - 35, 450, getmaxy() - 15);
    outtextxy(300, getmaxy() - 25, "Press any key to exit...");

    getch();
    closegraph();
    return 0;
}
