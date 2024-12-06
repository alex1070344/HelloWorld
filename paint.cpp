#include <graphics.h>

void drawBird(int x, int y) {
    // Draw the body
    ellipse(x, y, 0, 360, 30, 20);

    // Draw the wings
    arc(x - 20, y - 10, 0, 180, 20);
    arc(x + 20, y - 10, 0, 180, 20);

    // Draw the beak
    line(x + 30, y, x + 40, y - 10);
    line(x + 40, y - 10, x + 30, y - 20);

    // Draw the eyes
    circle(x - 10, y - 5, 2);
    circle(x + 10, y - 5, 2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawBird(200, 200);

    getch();
    closegraph();
    return 0;
}