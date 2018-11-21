#include <GL/freeglut.h>

#ifdef _DEBUG
#ifdef _WIN32
#pragma comment(lib, "glew32.lib")
#elif _WIN64
#pragma comment(lib, "glew32.lib")
#endif
#else
#ifdef _WIN64
#pragma comment(lib, "glew32.lib")
#elif _WIN32N
#pragma comment(lib, "glew32.lib")
#endif
#endif
#include <iostream>
#include <Windows.h>
#include "Sound.h"
#include "stdafx.h"
#include "BACKGROUND.h"
#include "CHARACTER.h"
#include "EFFECT.h"
#include "PublicDATA.h"

CSound snd;
using namespace std;

GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);
void Timer(int value);
void Mouse(int button, int state, int x, int y);
void Motion(int x, int y);
void PMotion(int x, int y);
void Keyboard(unsigned char key, int x, int y);
void printtext(int x, int y, string String);

void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);	// 디스플레이 모드 설정 
	glutInitWindowPosition(100, 100);	// 윈도우의 위치지정 
	glutInitWindowSize(1920, 1080);	// 윈도우의 크기 지정 
	glutCreateWindow("NUM11");	// 윈도우 생성 (윈도우 이름) 
	glutFullScreenToggle();
	glutDisplayFunc(drawScene);	// 출력 함수의 지정
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(Mouse);
	glutPassiveMotionFunc(PMotion);
	glutMotionFunc(Motion);
	glutTimerFunc(10, Timer, 1);
	glutTimerFunc(1000, Timer, 2);
	

	glutMainLoop();
}

// 윈도우 출력 함수
GLvoid drawScene(GLvoid)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);	// 바탕색을 'black' 으로 지정 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// 설정된 색으로 전체를 칠하기 
	//출력 전후
	glEnable(GL_DEPTH_TEST);

	

	glPushMatrix(); {
		gluLookAt(CameraPostion.x, CameraPostion.y, 1, 2, 0, 0,0,1, 0);
		glTranslated(0, 0, -350);
		glPushMatrix();
		glRotated(Global_Rotate, 0, 1, 0);
		glRotated(Global_Rotate/2, 1, 0, 0);
		glColor4ub(255, 255, 255, 255);
		for (int i = 255; i > 3; i-=3) {
			glColor4ub(255-i,i, 255-(i/2), 255);
			glutWireCube(i);
		}
		glPopMatrix();
	}glPopMatrix();
	char string[64];
	sprintf(string, "FPS %d FPSCOUNT %d", FPS, FPSCOUNT);
	printtext(10, 20, string);
	sprintf(string, "Q : EXIT");
	printtext(10, 35, string);




	glutSwapBuffers(); // 화면에 출력하기
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (float)1920/1080, 1.0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Timer(int value) {
	switch (value) {
	case 1:
		Global_Rotate++;
		FPSCOUNT++;
		glutPostRedisplay();
		glutTimerFunc(10, Timer, 1);
		break;
	case 2:
		FPS = FPSCOUNT;
		FPSCOUNT = 0;
		glutTimerFunc(1000, Timer, 2);
		break;
	}
}

void Mouse(int button, int state, int x, int y) {


}
void Motion(int x, int y) {

}

void PMotion(int x, int y) {

}

void Keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case'q':
		glutDestroyWindow(1);
		break;
	case 'a':
		CameraPostion.x--;
		break;
	case 'd':
		CameraPostion.x++;
		break;
	case 'w':
		CameraPostion.y++;
		break;
	case 's':
		CameraPostion.y--;
		break;
	case 'b':
		snd.pSound[0]->release();
		snd.Add_sound();
		snd.Play(0);
		break;
	case 'B':
		break;
	}
}

void printtext(int x, int y, string String)
{
	//(x,y) is from the bottom left of the window
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, 1920, 1080, 0, -1.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glPushAttrib(GL_DEPTH_TEST);
	glDisable(GL_DEPTH_TEST);
	glRasterPos2i(x, y);
	for (int i = 0; i < String.size(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, String[i]);
	}
	glPopAttrib();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}
