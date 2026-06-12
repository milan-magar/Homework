#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

// Structure to hold circle data for printing later
typedef struct {
    int id;
    int x;
    int y;
    char zone[10];
} PackedCircle;

int main() {
    int R;
    int r = 14; // Radius of small circles

    // Get user input first before initializing graphics mode
    printf("Enter the radius of the large circle (e.g., 150 to 250): ");
    scanf("%d", &R);
    
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Find center of screen
    int cx = getmaxx() / 2;
    int cy = getmaxy() / 2;

    // Define centers of the two overlapping large circles
    int left_cx = cx - (R / 2);
    int right_cx = cx + (R / 2);

    // Draw the two large base circles in white
    setcolor(WHITE);
    circle(left_cx, cy, R);
    circle(right_cx, cy, R);

    // Allocate memory to track placed circles
    int max_circles = (4 * R * 2 * R) / (r * r); 
    PackedCircle *circles = (PackedCircle *)malloc(max_circles * sizeof(PackedCircle));
    int count = 0;

    // Counters for different zones
    int left_count = 0, right_count = 0, center_count = 0;

    // Bounding box: Sweep from the far left of Left Circle to far right of Right Circle
    for (int x = left_cx - R + r; x <= right_cx + R - r; x += 2 * r) {
        for (int y = cy - R + r; y <= cy + R - r; y += 2 * r) {
            
            // 1. Calculate distance from grid point to BOTH large circle centers
            double d_L = sqrt(pow(x - left_cx, 2) + pow(y - cy, 2));
            double d_R = sqrt(pow(x - right_cx, 2) + pow(y - cy, 2));

            // 2. Apply strict boundary logic
            int strict_left   = (d_L <= (R - r)) && (d_R >= (R + r));
            int strict_right  = (d_R <= (R - r)) && (d_L >= (R + r));
            int strict_center = (d_L <= (R - r)) && (d_R <= (R - r));

            if (strict_left || strict_right || strict_center) {
                int overlap = 0;

                // 3. Prevent overlapping with already placed small circles
                for (int i = 0; i < count; i++) {
                    double dist = sqrt(pow(x - circles[i].x, 2) + pow(y - circles[i].y, 2));
                    if (dist < 2 * r) {
                        overlap = 1;
                        break;
                    }
                }

                // 4. Draw, number, and catalog if the space is completely clear
                if (!overlap) {
                    circles[count].x = x;
                    circles[count].y = y;
                    circles[count].id = count + 1;

                    if (strict_center) {
                        setcolor(RED);
                        center_count++;
                        sprintf(circles[count].zone, "Center");
                    } else if (strict_left) {
                        setcolor(GREEN);
                        left_count++;
                        sprintf(circles[count].zone, "Left");
                    } else if (strict_right) {
                        setcolor(BLUE);
                        right_count++;
                        sprintf(circles[count].zone, "Right");
                    }

                    // Draw the small circle
                    circle(x, y, r);

                    // Convert ID number to string and display it inside the circle
                    char num_str[5];
                    sprintf(num_str, "%d", circles[count].id);
                    
                    // Adjust text alignment slightly so it centers well within the 14-radius circle
                    outtextxy(x - 5, y - 4, num_str);

                    count++;
                }
            }
        }
    }

    // Print statistics on the upper portion of the graphics screen
    char str[120];
    setcolor(WHITE);
    sprintf(str, "Left (Green): %d  |  Center (Red): %d  |  Right (Blue): %d", left_count, center_count, right_count);
    outtextxy(20, 20, str);

    getch();
    closegraph(); // Closes the graphics window

    // 5. Display the coordinates in the standard console window after closegraph()
    printf("\n=============================================\n");
    printf("       PACKED CIRCLES CENTER COORDINATES     \n");
    printf("=============================================\n");
    printf("%-6s | %-10s | %-6s | %-6s\n", "Circle", "Zone", "X-Coord", "Y-Coord");
    printf("---------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("#%-5d | %-10s | %-7d | %-7d\n", 
               circles[i].id, circles[i].zone, circles[i].x, circles[i].y);
    }
    printf("=============================================\n");
    printf("Total circles successfully generated: %d\n", count);

    // Clean up allocated memory
    free(circles);
    return 0;
}
