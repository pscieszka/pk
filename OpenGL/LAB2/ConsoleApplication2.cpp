#include <iostream>
#include "glut.h"



GLfloat x_angle = 0.0f, y_angle = 0.0f, v_angle =1.0f;

void KeyboardFunc(unsigned char key, int x, int y);

/* Funkcja do rysowania */
void DrawScene(void);
/* Prototyp funkcji rysuj¹cej osie uk³adu */
void DrawSceneAxes(void);

/* Funkcja do inicjacji OpenGLa */
void InitOpenGL(void);

/* Funkcja wywo³ywana w momentach zmiany rozmiarów okna */
void ReshapeWindow(int width, int height);

/* Globalny identyfikator g³ównego okna programu */
int mainWindow;

void TimerFunction(int value);



int main(int argc, char** argv)
{
	// Inicjujemy bibliotekê GLUT
	glutInit(&argc, argv);
	// Inicjujemy: format koloru, dwa bufory ramki
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	// Ustawiamy pocz¹tkowe wymiary okna
	glutInitWindowSize(800, 600);
	// Ustawiamy pozycjê okna - lewy górny naro¿nik
	glutInitWindowPosition(150, 150);
	// Tworzymy g³ówne okno programu
	mainWindow = glutCreateWindow("Transformacje czajnikowe");

	// Sprawdzamy powodzenie operacji
	if (mainWindow == 0) {
		puts("Nie mozna stworzyc okna!!!\nWyjscie z programu.\n");
		exit(-1);
	}
	// Aktywujemy okno g³ówne programu
	glutSetWindow(mainWindow);

	// Tutaj rejestrujemy funkcje narzêdziowe - tzw. callbacks
	glutDisplayFunc(DrawScene);
	glutReshapeFunc(ReshapeWindow);

	// Ustawienia pocz¹tkowe
	InitOpenGL();

	// W³¹czamy mechanizm usuwania niewidocznych powierzchni
	glEnable(GL_DEPTH_TEST);
	glutKeyboardFunc(KeyboardFunc);
	glutTimerFunc(100, TimerFunction, 1);


	// Wejœcie do pêtli programu
	glutMainLoop();

	return(0);
}

/* W tej funkcji okreœlamy to co ma byc narysowane na ekranie.
 * Jest wywo³ywana zawsze wtedy, gdy trzeba przerysowaæ ekran - bufor ramki.
 */
void DrawScene(void)
{
	// Czyœcimy okno aktualnym (domyœlnym) kolorem oraz resetujemy bufor g³êbi
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Rysujemy osie uk³adu
	DrawSceneAxes();

	// Komenda wykonania poleceñ rysuj¹cych - nie jest ju¿ potrzebna przy ustaweniu GLUT_DOUBLE
	//glFlush();

	// Zamieniamy bufory ramki
	glutSwapBuffers();

}

/* Ta funkcja jest wywo³ywana przez funkcjê DrawScene.
 * Jej zadaniem jest rysowanie konkretnych obiektów osi uk³adu
 * wspó³rzêdnych.
 */
void DrawSceneAxes(void)
{
	// Definiujemy nowy typ jako tablicê 3-elementow¹
	typedef float pt3d[3];

	// Pocz¹tek i koniec osi X
	pt3d x_beg = { -10.0f, 0.0f, 0.0f };
	pt3d x_end = { 10.0f, 0.0f, 0.0f };

	// Poczatek i koniec osi Y
	pt3d y_beg = { 0.0f, -10.0f, 0.0f };
	pt3d y_end = { 0.0f,  10.0f, 0.0f };

	// Pocz¹tek i koniec osi Z
	pt3d z_beg = { 0.0f, 0.0f, -10.0f };
	pt3d z_end = { 0.0f, 0.0f,  10.0f };

	

	// Rysujemy osie
	glBegin(GL_LINES);
	// Czerwony kolor dla osi X
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3fv(x_beg);
	glVertex3fv(x_end);

	// Zielony kolor dla osi Y
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3fv(y_beg);
	glVertex3fv(y_end);

	// Niebieski kolor dla osi Z
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3fv(z_beg);
	glVertex3fv(z_end);

	glEnd();
	
	glRotatef(x_angle, 1.0f, 0.0f, 0.0f);
	glRotatef(y_angle, 0.0f, 1.0f, 0.0f);


	glColor3f(0.5f, 0.5f, 0.5f);
	glutWireTeapot(4.0);

}

/* Ta funkcja s³u¿y do wstêpnej konfiguracji OpenGLa.
 * Zanim coœ narysujemy musimy wywo³aæ tê funkcjê.
 */
void TimerFunction(int value) {

	
	x_angle = v_angle;
	y_angle = v_angle;
	glutTimerFunc(100, TimerFunction, 1);

	glutPostRedisplay();
}
void InitOpenGL(void)
{
	// Ustawiamy domyœlny, czarny kolor t³a okna - bufor ramki malujemy na czarno
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

/* Tê funkcjê wywo³uje system w momencie gdy u¿ytkownik zmieni mysz¹
 * rozmiar g³ównego okna. jej zadaniem jest zachowanie proporcji wymiarów
 * rysowanych obiektów niezale¿nie od wymiarów okna.
 */
void KeyboardFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: 
		exit(0);
		break;
	case 'w':
		v_angle+=0.05f;
		break;
	case 'r': 
		v_angle-=0.05f;
		break;
	}
	glutPostRedisplay();
}

void ReshapeWindow(int width, int height)
{
	//printf("w: %d\n", width);
	//printf("h: %d\n", height);
	GLdouble nRange = 15.0f;
	// Na wypadek dzielenia przez 0
	if (height == 0)
	{
		height = 1;
	}

	if (width == 0)
	{
		width = 1;
	}

	// Ustawiamy wielkoœci okna urz¹dzenia w zakresie
	// od 0,0 do wysokoœæ, szerokoœæ
	glViewport(0, 0, width, height);

	// Ustawiamy uk³ad wspó³rzêdnych obserwatora
	glMatrixMode(GL_PROJECTION);

	// Resetujemy macierz projekcji
	glLoadIdentity();

	// Korekta
	if (width <= height)
		glOrtho(-nRange, nRange, -nRange * ((GLdouble)height / width), nRange * ((GLdouble)height / width), -1.0f, 10.0f);
	else
		glOrtho(-nRange * ((GLdouble)width / height), nRange * ((GLdouble)width / height), -nRange, nRange, -10.0f, 10.0f);


	// Ustawiamy macierz modelu
	glMatrixMode(GL_MODELVIEW);

	// Resetujemy macierz modelu
	glLoadIdentity();
}
