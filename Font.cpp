#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Array of standard BGI font names for labeling
    char *font_names[] = {
        "0: DEFAULT_FONT",   "1: TRIPLEX_FONT", "2: SMALL_FONT", 
        "3: SANS_SERIF_FONT","4: GOTHIC_FONT",  "5: SCRIPT_FONT", 
        "6: SIMPLEX_FONT",   "7: TRIPLEX_SCR_FONT", "8: COMPLEX_FONT", 
        "9: EUROPEAN_FONT",  "10: BOLD_FONT"
    };

    int y_offset = 15; // Starting vertical position on the screen

    // Loop through all 11 standard font types
    for (int font_type = 0; font_type <= 10; font_type++) {
        
        // 1. Set font type dynamically, keeping direction horizontal (0), and size at a readable scale (2)
        // Note: SMALL_FONT (2) needs a slightly larger scale to be readable
        int font_size = (font_type == 2) ? 5 : 2;
        settextstyle(font_type, HORIZ_DIR, font_size);

        // 2. Cycle text colors to keep them distinct
        setcolor((font_type % 15) + 1); // Avoids 0 (Black)

        // 3. Format the display string
        char sample_text[50];
        sprintf(sample_text, "%s", font_names[font_type]);

        // 4. Print the text onto the screen
        outtextxy(20, y_offset, sample_text);

        // 5. Shift down based on the font height to prevent overlapping
        // Vector fonts (1-10) scale differently than the bitmapped default font (0)
        y_offset += textheight(sample_text) + 12;
    }

    getch();
    closegraph();
    return 0;
}
