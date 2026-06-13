#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Array of standard BGI fill style names for labeling
    char *style_names[] = {
        "EMPTY_FILL",   "SOLID_FILL",    "LINE_FILL",      "LTSLASH_FILL",
        "SLASH_FILL",   "BKSLASH_FILL",  "LTBKSLASH_FILL", "HATCH_FILL",
        "XHATCH_FILL",  "INTERLEAVE_FILL","WIDE_DOT_FILL", "CLOSE_DOT_FILL"
    };

    // Calculate dimensions to arrange them in a clean 4x3 grid layout
    int screen_w = getmaxx();
    int screen_h = getmaxy();
    
    int col_width = screen_w / 4;
    int row_height = screen_h / 3;

    int style_index = 0;

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            if (style_index >= 12) break;

            // Calculate bounding box for each pattern block
            int left   = (col * col_width) + 15;
            int top    = (row * row_height) + 40;
            int right  = ((col + 1) * col_width) - 15;
            int bottom = ((col + 1) * row_height) - 15;

            // 1. Set fill pattern style using the loop index, and color to GREEN (2)
            setfillstyle(style_index, 2);
            
            // 2. Draw the filled bar
            bar(left, top, right, bottom);

            // 3. Draw a white border outline around the bar to see its bounds
            setcolor(WHITE);
            rectangle(left, top, right, bottom);

            // 4. Print the name of the fill style right above the bar
            char label[30];
            sprintf(label, "%d: %s", style_index, style_names[style_index]);
            outtextxy(left, top - 20, label);

            style_index++;
        }
    }

    getch();
    closegraph();
    return 0;
}
