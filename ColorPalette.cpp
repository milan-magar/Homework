#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Array of standard BGI color names for labeling
    char *color_names[] = {
        "0: BLACK", "1: BLUE", "2: GREEN", "3: CYAN",
        "4: RED", "5: MAGENTA", "6: BROWN", "7: LIGHTGRAY",
        "8: DARKGRAY", "9: LIGHTBLUE", "10: LIGHTGREEN", "11: LIGHTCYAN",
        "12: LIGHTRED", "13: LIGHTMAGENTA", "14: YELLOW", "15: WHITE"
    };

    // Calculate height for each color bar based on max screen height
    int max_y = getmaxy();
    int bar_height = max_y / 16;
    int max_x = getmaxx();

    for (int i = 0; i < 16; i++) {
        // Calculate the top and bottom coordinates of the current bar
        int top = i * bar_height;
        int bottom = (i + 1) * bar_height;

        // Set the fill color for the current bar
        setfillstyle(SOLID_FILL, i);
        bar(0, top, max_x, bottom);

        // Adjust text color so it remains readable against the background
        // For white and light colors, text is set to black (0). Otherwise, it's white (15).
        if (i == 7 || i == 15 || i == 11 || i == 14) {
            setcolor(BLACK);
        } else {
            setcolor(WHITE);
        }

        // Print the color name slightly indented inside the bar
        outtextxy(20, top + (bar_height / 3), color_names[i]);
    }

    getch();
    closegraph();
    return 0;
}
