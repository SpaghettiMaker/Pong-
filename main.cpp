#include <GL/glut.h>
#include <GL/gl.h>
#include "game.h"

#define COLUMNS 10  
#define ROWS 10     
#define FPS 10

int index = 0;
// Funzione per disegnare qualcosa nella finestra
void display() {
    glClear(GL_COLOR_BUFFER_BIT);                   // Pulisce il buffer
    drawGrid();                                     // Disegna la griglia
    glRectf(index, index, index+1, index+1);     // Disegna un rettangolo
    index++;
    if (index >= COLUMNS) {
        index = 0;
    }
    glFlush();                                      // Esegue il rendering immediato
}

// Funzione di callback per il ridimensionamento della finestra
void reshape(int w, int h) {
    glViewport(0, 0, w, h);                         // Imposta la viewport
    glMatrixMode(GL_PROJECTION);                    // Imposta la matrice di proiezione, sistema a coordinate 2D
    glLoadIdentity();                               // Carica la matrice identità, significa che nessuna trasformazione è attiva finché non ne applichi una nuova.
    gluOrtho2D(0.0, COLUMNS, 0.0, ROWS);            // Imposta il sistema di coordinate
}

// Funzione per inizializzare OpenGL

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);               // Imposta il colore di sfondo (nero opaco)
    initGrid(COLUMNS, ROWS);                        // Inizializza la griglia con le dimensioni specificate
}


void timer(int) {
    /*
    Informa GLUT che la finestra deve essere ridisegnata.
    Questo richiama la funzione display(), che viene impostata con glutDisplayFunc().
    Utile per creare animazioni continue senza bisogno di input dell'utente.
    */
    glutPostRedisplay();                            // Richiama la funzione di rendering
    /*
    Imposta un ritardo di esecuzione per la funzione timer().
    1000 / FPS calcola l'intervallo tra i frame in millisecondi.
    Ad esempio, se FPS = 60, l'intervallo è 1000 / 60 = 16 ms, quindi la funzione verrà eseguita ogni 16 millisecondi per simulare un framerate di 60 FPS.
    La funzione timer() viene chiamata ricorsivamente per mantenere l'aggiornamento costante.
    */
    glutTimerFunc(1000 / FPS, timer, 0);            // Imposta il timer per richiamare la funzione di rendering a una frequenza specifica
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                          // Inizializza la libreria GLUT e passa i comandi da riga di comando
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // GLUT_SINGLE → Usa un buffer singolo per il rendering. GLUT_RGB → Usa il modello di colore RGB.
    glutInitWindowSize(500, 500);                   // Imposta la dimensione della finestra a 500x500 pixel
    glutCreateWindow("OpenGL Grid");                // Crea una finestra con il titolo specificato
    glutTimerFunc(0, timer, 0);                     // Imposta la funzione di callback per il timer, il primo parametro indica quanto ms devono passare prima di richianmare timer, ion questo caso 0
    init();                                         // Inizializza impostazioni grafiche
    glutDisplayFunc(display);                       // Imposta la funzione di rendering
    glutReshapeFunc(reshape);                       // Imposta la funzione di callback per il ridimensionamento della finestra
    glutMainLoop();                                 // Entra nel loop principale di GLUT, in cui il programma rimane in esecuzione gestendo eventi (es. input da tastiera, ridimensionamento finestra, rendering).
    return 0;                                       
}
