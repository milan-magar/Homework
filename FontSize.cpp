#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Calculate dimensions to arrange them in a clean 4x3 grid layout
    int screen_w = getmaxx();
    int screen_h = getmaxy();
    
    int col_width = screen_w / 4;
    int row_height = screen_h / 3;

    int size_index = 1; // BGI font sizes start at 1 and go up to 10

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            if (size_index > 10) break; // Stop after displaying size 10

            // Calculate grid positioning anchors
            int left = col * col_width + 10;
            int top  = row * row_height + 40;

            // 1. Draw a subtle dotted bounding box divider for each grid sector
            setcolor(DARKGRAY);
            setlinestyle(DOTTED_LINE, 0, NORM_WIDTH);
            rectangle(col * col_width, row * row_height, (col + 1) * col_width, (row + 1) * row_height);

            // 2. Set the font size using the loop index
            // DEFAULT_FONT (0), HORIZ_DIR (0), dynamic size_index
            settextstyle(DEFAULT_FONT, HORIZ_DIR, size_index);
            
            // 3. Cycle colors to make each size pop out visually
            setcolor((size_index % 15) + 1); // Bypasses 0 (Black)

            // 4. Format and display the sample text string
            char label[20];
            sprintf(label, "Size %d", size_index);
            outtextxy(left, top, label);

            size_index++;
        }
    }

    getch();
    closegraph();
    return 0;
}
