#include <GL/glut.h> // aiuta a gestire finestre, eventi e interazioni con OpenGL.
#include "game.h"
#include <GL/gl.h>  // libreria OpenGL di base

int gridX, gridY;

void initGrid(int x, int y) {
    gridX = x;
    gridY = y;
}

void drawSquare(int x, int y) {
    glLineWidth(2.0); // Imposta lo spessore della linea a 2.0
    glColor3f(1.0, 1.0, 1.0); // Imposta il colore del quadrato a bianco
    glBegin(GL_LINE_LOOP); // Inizia il disegno di un quadrato senza riempimento
    glVertex2f(x, y);
    glVertex2f(x + 1, y);
    glVertex2f(x + 1, y + 1);
    glVertex2f(x, y + 1);
    glEnd(); // Termina il disegno
}

// In ogni pixel della finestra, disegna un quadrato
void drawGrid() {
    for (int x = 0; x < gridX; x++) {
        for (int y = 0; y < gridY; y++) {
            drawSquare(x, y);
        }
    }
}
