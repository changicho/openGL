#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <math.h>
#include <stdio.h>


GLboolean left_click = false;    //클릭하고있는지보기위해
GLboolean right_click = false;
GLdouble click_rotation_X = 0, click_rotation_Y = 0;
GLUquadricObj *p;    //quadric 객체선언

static float Base;    //베이스
static float Lower_Arm;    //아래팔뚝
static float Upper_Arm;    //팔



void base(void)
{
	glPushMatrix();            //물체값들푸시
	glColor3f(1, 0, 0);
	glTranslatef(0, -0.8, 0);        //현재좌표계를Y축으로-1.0만큼이동

	glRotatef(-90, 1, 0, 0); //x축으로90도회전
							 //glRotatef(Base, 0, 0, 1);    //Base 값만큼z축으로회전
	
	glScalef(0.4, 1.0, 0.8);
	glutWireCube(1);

	

	glPopMatrix();            //물체값들팝
}


void lower_arm(void)
{

	glPushMatrix();        //물체값들푸시
	glColor3f(0, 1, 1);
	//glRotatef(Base, 0, 1, 0);    //Base 값만큼y축으로회전
	glTranslatef(0, -0.4, 0);    //현재좌표계를Y축으로-0.7만큼이동
	glRotatef(Lower_Arm, 0, 0, 1);    //Lower_Arm 값만큼z축으로회전
	glTranslatef(0, 0.4, 0);    //현재좌표계를Y축으로0.5만큼이동
	glScalef(0.2, 0.4, 0.2);        //1의정육면체를축소하여그리기
	glutWireCube(1);            //길이1인정육면체그리기
	glPopMatrix();

	glPushMatrix();            //물체값들푸시
	glTranslatef(0, 0.4, 0);

	glPushMatrix();
	
	glColor3f(0.5, 0.2, 0.3);
	//glRotatef(Base, 0, 1, 0);    //Base 값만큼y축으로회전
	glTranslatef(0, -1.0, 0);    //현재좌표계를Y축으로-0.7만큼이동
	glRotatef(Lower_Arm, 0, 0, 1);    //Lower_Arm 값만큼z축으로회전
	//glRotatef(Upper_Arm, 0, 0, 1);    //Upper_Arm 값만큼z축으로회전
	glTranslatef(0, 1.0, 0);    //현재좌표계를Y축으로1.0만큼이동

								 //glTranslatef(0, 0.4, 0);    //현재좌표계를Y축으로0.4만큼이동
	glScalef(0.2, 0.6, 0.2);    //1의정육면체를축소하여그리기
	glutWireCube(1);            //길이1인정육면체그리기
	

	glPopMatrix();



	glPopMatrix();    //물체값들팝
}

void upper_arm(void)
{
	
	//glPushMatrix();            //물체값들푸시
	//glTranslatef(0, 0.4, 0);
	//glColor3f(0.5, 0.2, 0.3);
	////glRotatef(Base, 0, 1, 0);    //Base 값만큼y축으로회전
	//glTranslatef(0, -0.6, 0);    //현재좌표계를Y축으로-0.7만큼이동
	//glRotatef(Lower_Arm, 0, 0, 1);    //Lower_Arm 값만큼z축으로회전
	////glRotatef(Upper_Arm, 0, 0, 1);    //Upper_Arm 값만큼z축으로회전
	//glTranslatef(0, 0.45, 0);    //현재좌표계를Y축으로1.0만큼이동
	//
	////glTranslatef(0, 0.4, 0);    //현재좌표계를Y축으로0.4만큼이동
	//glScalef(0.2, 0.6, 0.2);    //1의정육면체를축소하여그리기
	//glutWireCube(1);            //길이1인정육면체그리기
	//glPopMatrix();        //물체값들팝
}

void OnDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLoadIdentity();
	glRotatef(click_rotation_X, 1, 0, 0);    //click_rotation_X값만큼X축으로회전
	glRotatef(click_rotation_Y, 0, 1, 0);    //click_rotation_Y값만큼Y축으로회전
											 //gluLookAt(0.5, 0.5, 0.5, 0, 0, 0, 0, 1, 0);        //비스듭하게보임
	gluLookAt(0.5, 0.0, 0.0, 0, 0, 0, 0, 1, 0);     //정면을보자
													//카메라시점설정

	glPushMatrix();
	glRotatef(Base, 0, 1, 0);
	base();
	glTranslatef(0.0, 0.0, 0.45);
	lower_arm();
	upper_arm();

	glTranslatef(0.0, 0.0, -0.3);
	lower_arm();
	upper_arm();

	glTranslatef(0.0, 0.0, -0.3);
	lower_arm();
	upper_arm();

	glTranslatef(0.0, 0.0, -0.3);
	lower_arm();
	upper_arm();

	glPopMatrix();


	glutSwapBuffers(); //버퍼교환
}


void Key_Function(int key, int x, int y)
{
	switch (key)
	{
	case 'q' | 'Q':exit(0); break;

	case VK_ESCAPE:    gluDeleteQuadric(p); exit(0); break;
		//생성된객체삭제후종료

	case GLUT_KEY_RIGHT: //베이스판회전
		Base += 2.0;
		break;

	case GLUT_KEY_LEFT:
		Base -= 2.0;
		break;

	case GLUT_KEY_DOWN:    //팔뚝회전
		Lower_Arm -= 2.0;
		break;

	case GLUT_KEY_UP:
		Lower_Arm += 2.0;
		break;

	case GLUT_KEY_PAGE_DOWN://손목회전
		Upper_Arm -= 2.0;
		break;

	case GLUT_KEY_PAGE_UP:
		Upper_Arm += 2.0;
		break;

	default:break;

	}
	glutPostRedisplay();
}



void timer(int value)
{
	//오른쪽버튼클릭(유지)시팔이원상태로돌아감(모션)
	if (right_click == true)
	{

		if (Lower_Arm < 0)
			Lower_Arm += 2;

		else if (Lower_Arm >0)
			Lower_Arm -= 2;

		if (Upper_Arm < 0)
			Upper_Arm += 2;

		else if (Upper_Arm >0)
			Upper_Arm -= 2;

		if (Base < 0)
			Base += 2;

		else if (Base >0)
			Base -= 2;

	}

	//팔이꺽을수없는각도위해값조절

	if (Lower_Arm >= 90.0)

		Lower_Arm = 90.0;

	if (Lower_Arm <= -90.0)

		Lower_Arm = -90.0;

	if (Upper_Arm >= 90.0)

		Upper_Arm = 90.0;

	if (Upper_Arm <= -90.0)

		Upper_Arm = -90;

	glutTimerFunc(33, timer, 1);    //타이머함수호출
	glutPostRedisplay();    //다시그리기
}


void init(void)
{
	p = gluNewQuadric();    //객체할당(메모리생성)
	gluQuadricDrawStyle(p, GLU_LINE);    //그리기스타일옵션
	Base = 0; Lower_Arm = 0; Upper_Arm = 0;
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);    //깊이정보에따라이미지를나눈다.
}


void OnReshape(int w, int h)    //화면크기변경시Reshape
{
	if (h == 0)
		h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0*(float)w / (float)h, 2.0*(float)w / (float)h, -2.0, 2.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void OnMouseClick(int button, int state, int xx, int yy)
{    //(왼쪽,오른쪽)마우스가눌러져있으면true


	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		left_click = true;

	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		left_click = false;

	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		right_click = true;

	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
		right_click = false;

	}

	glutPostRedisplay();

}


void OnMouseMove(int x, int y)
{    //static선언하여값이변하지않게함
	static int static_X = x, static_Y = y;

	if (left_click == true) {
		click_rotation_X = y - static_Y;
		click_rotation_Y = x - static_X;
		glutPostRedisplay();
	}

	if (right_click == true)
	{
		static_X = x; static_Y = y;
		glutPostRedisplay();
	}

}

void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutCreateWindow("201413256 CHOCHANGI");
	glutDisplayFunc(OnDisplay);
	glutReshapeFunc(OnReshape);
	glutMouseFunc(OnMouseClick);
	glutMotionFunc(OnMouseMove);
	glutPassiveMotionFunc(OnMouseMove);
	glutTimerFunc(33, timer, 1);
	glutSpecialFunc(Key_Function);
	init();
	glutMainLoop();
}