#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMS 8

/* Helper: draw text with background colour */
void drawTextWithBG(int x, int y, char *str, int textColor, int bgColor)
{
    setcolor(textColor);
    setbkcolor(bgColor);

    outtextxy(x, y, str);
}

int main()
{
    int gd = DETECT, gm;
    int x, y, i;

    initgraph(&gd, &gm, "");

    setbkcolor(GREEN);
    cleardevice();

    srand((unsigned)time(NULL));

    /* ---- Generate random sets A and B (numbers 1..50) ---- */
    int universe[50];
    for (i = 0; i < 50; i++) universe[i] = i + 1;

    int intersection[5];
    for (i = 0; i < 5; i++) {
        int idx = rand() % (50 - i);
        intersection[i] = universe[idx];
        universe[idx] = universe[49 - i];
    }

    int A_only[5];
    for (i = 0; i < 5; i++) {
        int idx = rand() % (50 - 5 - i);
        A_only[i] = universe[idx];
        universe[idx] = universe[49 - 5 - i];
    }

    int B_only[5];
    for (i = 0; i < 5; i++) {
        int idx = rand() % (50 - 10 - i);
        B_only[i] = universe[idx];
        universe[idx] = universe[49 - 10 - i];
    }

    int A[10], B[10];
    for (i = 0; i < 5; i++) A[i] = A_only[i];
    for (i = 0; i < 5; i++) A[5 + i] = intersection[i];
    for (i = 0; i < 5; i++) B[i] = B_only[i];
    for (i = 0; i < 5; i++) B[5 + i] = intersection[i];

    /* ---- Venn diagram with radius 140 ---- */
    int r = 140;
    int x1 = 200, y1 = 250;      // left circle centre
    int x2 = 340, y2 = 250;      // right circle centre

    /* Paint all regions pixel by pixel */
    for (x = 0; x < getmaxx(); x++) {
        for (y = 0; y < getmaxy(); y++) {
            int in1 = (((x - x1)*(x - x1) + (y - y1)*(y - y1)) <= r*r);
            int in2 = (((x - x2)*(x - x2) + (y - y2)*(y - y2)) <= r*r);
            int count = in1 + in2;

            if (count == 1) {
                if (in1) putpixel(x, y, LIGHTRED);      // A only
                else     putpixel(x, y, LIGHTBLUE);     // B only
            } else if (count == 2) {
                putpixel(x, y, YELLOW);                 // Intersection
            }
            // else background (GREEN)
        }
    }

    /* Circle outlines */
    setcolor(BLACK);
    setlinestyle(SOLID_LINE, 0, 2);
    circle(x1, y1, r);
    circle(x2, y2, r);

    /* ---- Display elements with large text (size 2) ---- */
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    /* A only (left lobe) */
    int posAonly[][2] = {
        {120, 200}, {120, 240}, {120, 280}, {120, 320},
        {160, 220}
    };
    for (i = 0; i < 5; i++) {
        char str[10];
        sprintf(str, "%d", A_only[i]);
        drawTextWithBG(posAonly[i][0], posAonly[i][1], str, WHITE, LIGHTRED);
    }

    /* B only (right lobe) */
    int posBonly[][2] = {
        {420, 200}, {420, 240}, {420, 280}, {420, 320},
        {380, 220}
    };
    for (i = 0; i < 5; i++) {
        char str[10];
        sprintf(str, "%d", B_only[i]);
        drawTextWithBG(posBonly[i][0], posBonly[i][1], str, WHITE, LIGHTBLUE);
    }

    /* Intersection (overlap) */
    int posInter[][2] = {
        {270, 200}, {270, 240}, {270, 280}, {270, 320},
        {230, 220}
    };
    for (i = 0; i < 5; i++) {
        char str[10];
        sprintf(str, "%d", intersection[i]);
        drawTextWithBG(posInter[i][0], posInter[i][1], str, BLACK, YELLOW);
    }

    /* Set names A and B */
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setbkcolor(GREEN);
    setcolor(WHITE);
    outtextxy(160, 100, "A");
    outtextxy(380, 100, "B");

    /* ---- Legend at bottom-right ---- */
    int legX = getmaxx() - 210;
    int legY = getmaxy() - 140;

    setfillstyle(SOLID_FILL, BLACK);
    bar(legX, legY, legX + 200, legY + 130);
    setcolor(WHITE);
    rectangle(legX, legY, legX + 200, legY + 130);

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    settextjustify(CENTER_TEXT, TOP_TEXT);
    outtextxy(legX + 100, legY + 15, "LEGEND");

    settextjustify(LEFT_TEXT, TOP_TEXT);

    setfillstyle(SOLID_FILL, LIGHTRED);
    bar(legX + 10, legY + 35, legX + 30, legY + 50);
    setcolor(WHITE);
    outtextxy(legX + 45, legY + 38, "A only");

    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(legX + 10, legY + 55, legX + 30, legY + 70);
    setcolor(WHITE);
    outtextxy(legX + 45, legY + 58, "B only");

    setfillstyle(SOLID_FILL, YELLOW);
    bar(legX + 10, legY + 75, legX + 30, legY + 90);
    setcolor(BLACK);
    outtextxy(legX + 45, legY + 78, "A n B");

    /* ---- Title ---- */
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setfillstyle(SOLID_FILL, BLACK);
    bar(140, 20, 500, 55);
    setcolor(WHITE);
    outtextxy(320, 38, "TWO SET VENN DIAGRAM");

    /* ---- Exit instruction (bottom centre, above legend) ---- */
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    setbkcolor(GREEN);
    outtextxy(getmaxx()/2, getmaxy() - 20, "Press any key to exit...");

    getch();
    closegraph();
    return 0;
}
