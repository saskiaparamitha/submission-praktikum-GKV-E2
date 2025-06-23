/*	Nama  : Saskia Putri Paramitha
	  NIM   : 24060123140144
	  Lab   : GKV E2
    Tugas : TugasPraktikum1
*/

#include <GL/glut.h>

/* 1. Selain membuat titik menggunakan GL_POINT, garis menggunakan GL_LINES,   
buatlah program yang memanfaatkan fungsi GL_LINE_STRIP, GL_LINE_LOOP, 
GL_TRIANGLE_FAN, GL_TRIANGLE_STRIP, GL_QUADS, dan GL_QUAD_STRIP. */

// a. GL_LINE_STRIP
/*
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f); // Warna putih
    
    // GL_LINE_STRIP - menggambar garis yang saling terhubung
    glLineWidth(2.0f);
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0f, 0.0f, 0.0f); // Merah
        glVertex2f(-0.7f, 0.5f);
        glColor3f(0.0f, 1.0f, 0.0f); // Hijau
        glVertex2f(-0.3f, 0.2f);
        glColor3f(0.0f, 0.0f, 1.0f); // Biru
        glVertex2f(-0.5f, -0.3f);
        glColor3f(1.0f, 1.0f, 0.0f); // Kuning
        glVertex2f(-0.8f, -0.2f);
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Background hitam
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GL_LINE_STRIP Example");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
*/

// b. GL_LINE_LOOP
/*
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f); // Warna putih
    
    // GL_LINE_LOOP - sama seperti LINE_STRIP tapi ditambah garis yang menghubungkan titik terakhir ke titik pertama
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
        glColor3f(1.0f, 0.0f, 0.0f); // Merah
        glVertex2f(0.3f, 0.5f);
        glColor3f(0.0f, 1.0f, 0.0f); // Hijau
        glVertex2f(0.7f, 0.2f);
        glColor3f(0.0f, 0.0f, 1.0f); // Biru
        glVertex2f(0.5f, -0.3f);
        glColor3f(1.0f, 1.0f, 0.0f); // Kuning
        glVertex2f(0.2f, -0.2f);
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Background hitam
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GL_LINE_LOOP Example");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
*/

// c. GL_TRIANGLE_FAN
/*
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // GL_TRIANGLE_FAN - Membuat triangles yang berbagi vertex pertama (seperti kipas)
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f); // Vertex pusat (putih)
        glVertex2f(0.0f, 0.0f);      // Vertex pusat
        
        glColor3f(1.0f, 0.0f, 0.0f); // Merah
        glVertex2f(-0.5f, 0.5f);
        
        glColor3f(0.0f, 1.0f, 0.0f); // Hijau
        glVertex2f(0.0f, 0.5f);
        
        glColor3f(0.0f, 0.0f, 1.0f); // Biru
        glVertex2f(0.5f, 0.5f);
        
        glColor3f(1.0f, 1.0f, 0.0f); // Kuning
        glVertex2f(0.5f, -0.5f);
        
        glColor3f(1.0f, 0.0f, 1.0f); // Magenta
        glVertex2f(-0.5f, -0.5f);
        
        glColor3f(1.0f, 0.5f, 0.0f); // Orange
        glVertex2f(-0.5f, 0.5f);     // Kembali ke vertex pertama untuk menutup kipas
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Background hitam
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GL_TRIANGLE_FAN Example");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
*/

// d. GL_TRIANGLE_STRIP
/*
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // GL_TRIANGLE_STRIP - Menggambar rangkaian segitiga yang saling terhubung
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(1.0f, 0.0f, 0.0f); // Merah
        glVertex2f(-0.7f, -0.5f);
        
        glColor3f(0.0f, 1.0f, 0.0f); // Hijau
        glVertex2f(-0.7f, 0.5f);
        
        glColor3f(0.0f, 0.0f, 1.0f); // Biru
        glVertex2f(-0.2f, -0.5f);
        
        glColor3f(1.0f, 1.0f, 0.0f); // Kuning
        glVertex2f(-0.2f, 0.5f);
        
        glColor3f(1.0f, 0.0f, 1.0f); // Magenta
        glVertex2f(0.3f, -0.5f);
        
        glColor3f(0.0f, 1.0f, 1.0f); // Cyan
        glVertex2f(0.3f, 0.5f);
        
        glColor3f(1.0f, 0.5f, 0.0f); // Orange
        glVertex2f(0.8f, -0.5f);
        
        glColor3f(0.5f, 0.5f, 0.5f); // Abu-abu
        glVertex2f(0.8f, 0.5f);
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Background hitam
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GL_TRIANGLE_STRIP Example");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
*/

// e. GL_QUADS
/*
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // GL_QUADS - Menggambar segiempat
    glBegin(GL_QUADS);
        // Segiempat pertama
        glColor3f(1.0f, 0.0f, 0.0f); // Merah
        glVertex2f(-0.7f, 0.2f);
        
        glColor3f(0.0f, 1.0f, 0.0f); // Hijau
        glVertex2f(-0.3f, 0.2f);
        
        glColor3f(0.0f, 0.0f, 1.0f); // Biru
        glVertex2f(-0.3f, -0.2f);
        
        glColor3f(1.0f, 1.0f, 0.0f); // Kuning
        glVertex2f(-0.7f, -0.2f);
        
        // Segiempat kedua
        glColor3f(1.0f, 0.0f, 1.0f); // Magenta
        glVertex2f(0.3f, 0.5f);
        
        glColor3f(0.0f, 1.0f, 1.0f); // Cyan
        glVertex2f(0.7f, 0.5f);
        
        glColor3f(0.5f, 0.5f, 0.5f); // Abu-abu
        glVertex2f(0.7f, 0.0f);
        
        glColor3f(1.0f, 0.5f, 0.0f); // Orange
        glVertex2f(0.3f, 0.0f);
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Background hitam
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GL_QUADS Example");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
*/

// f. GL_QUAD_STRIP
/*
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // GL_QUAD_STRIP - Menggambar rangkaian segiempat yang saling terhubung
    glBegin(GL_QUAD_STRIP);
        glColor3f(1.0f, 0.0f, 0.0f); // Merah
        glVertex2f(-0.8f, 0.3f);
        
        glColor3f(0.0f, 1.0f, 0.0f); // Hijau
        glVertex2f(-0.8f, -0.3f);
        
        glColor3f(0.0f, 0.0f, 1.0f); // Biru
        glVertex2f(-0.4f, 0.3f);
        
        glColor3f(1.0f, 1.0f, 0.0f); // Kuning
        glVertex2f(-0.4f, -0.3f);
        
        glColor3f(1.0f, 0.0f, 1.0f); // Magenta
        glVertex2f(0.0f, 0.3f);
        
        glColor3f(0.0f, 1.0f, 1.0f); // Cyan
        glVertex2f(0.0f, -0.3f);
        
        glColor3f(0.5f, 0.5f, 0.5f); // Abu-abu
        glVertex2f(0.4f, 0.3f);
        
        glColor3f(1.0f, 0.5f, 0.0f); // Orange
        glVertex2f(0.4f, -0.3f);
        
        glColor3f(0.5f, 0.0f, 0.5f); // Ungu tua
        glVertex2f(0.8f, 0.3f);
        
        glColor3f(0.0f, 0.5f, 0.0f); // Hijau tua
        glVertex2f(0.8f, -0.3f);
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Background hitam
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GL_QUAD_STRIP Example");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
*/


/* 2. Buat Gambar Kubus bertingkat dari objek primitif 
sekreatif mungkin. (minimal 5 kubus) */ 

void drawColoredSquare(float x, float y, float size, float r, float g, float b) {
    // Draw the colored square fill
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y + size);
        glVertex2f(x, y + size);
    glEnd();
    
    // Draw the black border
    glColor3f(0.0f, 0.0f, 0.0f);  // Black color
    glLineWidth(2.0f);            // Make the line thicker for visibility
    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y + size);
        glVertex2f(x, y + size);
    glEnd();
}

// Main display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    float squareSize = 0.1f;
    float startX = -0.25f;
    float startY = -0.4f;
    
    // Row 1 (bottom) - 6 squares
    drawColoredSquare(startX, startY, squareSize, 1.0f, 0.0f, 1.0f);                 // Magenta
    drawColoredSquare(startX + squareSize, startY, squareSize, 1.0f, 0.0f, 0.0f);    // Red
    drawColoredSquare(startX + 2*squareSize, startY, squareSize, 1.0f, 1.0f, 0.0f);  // Yellow
    drawColoredSquare(startX + 3*squareSize, startY, squareSize, 0.0f, 0.0f, 1.0f);  // Blue
    drawColoredSquare(startX + 4*squareSize, startY, squareSize, 0.0f, 1.0f, 0.0f);  // Green
    drawColoredSquare(startX + 5*squareSize, startY, squareSize, 1.0f, 1.0f, 1.0f);  // White
    
    // Row 2 - 5 squares
    startX += squareSize/2;
    startY += squareSize;
    drawColoredSquare(startX, startY, squareSize, 1.0f, 0.0f, 0.0f);                 // Red
    drawColoredSquare(startX + squareSize, startY, squareSize, 0.0f, 1.0f, 1.0f);    // Cyan
    drawColoredSquare(startX + 2*squareSize, startY, squareSize, 1.0f, 0.0f, 1.0f);  // Magenta
    drawColoredSquare(startX + 3*squareSize, startY, squareSize, 0.0f, 0.0f, 1.0f);  // Blue
    drawColoredSquare(startX + 4*squareSize, startY, squareSize, 1.0f, 1.0f, 0.0f);  // Yellow
    
    // Row 3 - 4 squares
    startX += squareSize/2;
    startY += squareSize;
    drawColoredSquare(startX, startY, squareSize, 1.0f, 1.0f, 0.0f);                 // Yellow
    drawColoredSquare(startX + squareSize, startY, squareSize, 1.0f, 1.0f, 1.0f);    // White
    drawColoredSquare(startX + 2*squareSize, startY, squareSize, 1.0f, 0.0f, 0.0f);  // Red
    drawColoredSquare(startX + 3*squareSize, startY, squareSize, 0.0f, 0.0f, 1.0f);  // Blue
    
    // Row 4 - 3 squares
    startX += squareSize/2;
    startY += squareSize;
    drawColoredSquare(startX, startY, squareSize, 0.0f, 1.0f, 0.0f);                 // Green
    drawColoredSquare(startX + squareSize, startY, squareSize, 0.0f, 0.0f, 1.0f);    // Blue
    drawColoredSquare(startX + 2*squareSize, startY, squareSize, 1.0f, 0.0f, 1.0f);  // Magenta
    
    // Row 5 - 2 squares
    startX += squareSize/2;
    startY += squareSize;
    drawColoredSquare(startX, startY, squareSize, 0.0f, 1.0f, 1.0f);                 // Cyan
    drawColoredSquare(startX + squareSize, startY, squareSize, 0.0f, 1.0f, 0.0f);    // Green
    
    // Row 6 (top) - 1 square
    startX += squareSize/2;
    startY += squareSize;
    drawColoredSquare(startX, startY, squareSize, 1.0f, 1.0f, 0.0f);                 // Yellow
    
    glFlush();
}

// Initialization function
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Colored Blocks Pyramid with Borders");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
