#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <math.h>
#include <stdio.h>


GLboolean left_click = false;    //Ŭ���ϰ��ִ�����������
GLboolean right_click = false;
GLdouble click_rotation_X = 0, click_rotation_Y = 0;
GLUquadricObj *p;    //quadric ��ü����

static float Base;    //���̽�
static float Lower_Arm;    //�Ʒ��ȶ�
static float Upper_Arm;    //��



void base(void)
{
	glPushMatrix();            //��ü����Ǫ��
	glColor3f(1, 0, 0);
	glTranslatef(0, -0.8, 0);        //������ǥ�踦Y������-1.0��ŭ�̵�

	glRotatef(-90, 1, 0, 0); //x������90��ȸ��
							 //glRotatef(Base, 0, 0, 1);    //Base ����ŭz������ȸ��
	
	glScalef(0.4, 1.0, 0.8);
	glutWireCube(1);

	

	glPopMatrix();            //��ü������
}


void lower_arm(void)
{

	glPushMatrix();        //��ü����Ǫ��
	glColor3f(0, 1, 1);
	//glRotatef(Base, 0, 1, 0);    //Base ����ŭy������ȸ��
	glTranslatef(0, -0.4, 0);    //������ǥ�踦Y������-0.7��ŭ�̵�
	glRotatef(Lower_Arm, 0, 0, 1);    //Lower_Arm ����ŭz������ȸ��
	glTranslatef(0, 0.4, 0);    //������ǥ�踦Y������0.5��ŭ�̵�
	glScalef(0.2, 0.4, 0.2);        //1��������ü������Ͽ��׸���
	glutWireCube(1);            //����1��������ü�׸���
	glPopMatrix();

	glPushMatrix();            //��ü����Ǫ��
	glTranslatef(0, 0.4, 0);

	glPushMatrix();
	
	glColor3f(0.5, 0.2, 0.3);
	//glRotatef(Base, 0, 1, 0);    //Base ����ŭy������ȸ��
	glTranslatef(0, -1.0, 0);    //������ǥ�踦Y������-0.7��ŭ�̵�
	glRotatef(Lower_Arm, 0, 0, 1);    //Lower_Arm ����ŭz������ȸ��
	//glRotatef(Upper_Arm, 0, 0, 1);    //Upper_Arm ����ŭz������ȸ��
	glTranslatef(0, 1.0, 0);    //������ǥ�踦Y������1.0��ŭ�̵�

								 //glTranslatef(0, 0.4, 0);    //������ǥ�踦Y������0.4��ŭ�̵�
	glScalef(0.2, 0.6, 0.2);    //1��������ü������Ͽ��׸���
	glutWireCube(1);            //����1��������ü�׸���
	

	glPopMatrix();



	glPopMatrix();    //��ü������
}

void upper_arm(void)
{
	
	//glPushMatrix();            //��ü����Ǫ��
	//glTranslatef(0, 0.4, 0);
	//glColor3f(0.5, 0.2, 0.3);
	////glRotatef(Base, 0, 1, 0);    //Base ����ŭy������ȸ��
	//glTranslatef(0, -0.6, 0);    //������ǥ�踦Y������-0.7��ŭ�̵�
	//glRotatef(Lower_Arm, 0, 0, 1);    //Lower_Arm ����ŭz������ȸ��
	////glRotatef(Upper_Arm, 0, 0, 1);    //Upper_Arm ����ŭz������ȸ��
	//glTranslatef(0, 0.45, 0);    //������ǥ�踦Y������1.0��ŭ�̵�
	//
	////glTranslatef(0, 0.4, 0);    //������ǥ�踦Y������0.4��ŭ�̵�
	//glScalef(0.2, 0.6, 0.2);    //1��������ü������Ͽ��׸���
	//glutWireCube(1);            //����1��������ü�׸���
	//glPopMatrix();        //��ü������
}

void OnDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLoadIdentity();
	glRotatef(click_rotation_X, 1, 0, 0);    //click_rotation_X����ŭX������ȸ��
	glRotatef(click_rotation_Y, 0, 1, 0);    //click_rotation_Y����ŭY������ȸ��
											 //gluLookAt(0.5, 0.5, 0.5, 0, 0, 0, 0, 1, 0);        //�񽺵��ϰԺ���
	gluLookAt(0.5, 0.0, 0.0, 0, 0, 0, 0, 1, 0);     //����������
													//ī�޶��������

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


	glutSwapBuffers(); //���۱�ȯ
}


void Key_Function(int key, int x, int y)
{
	switch (key)
	{
	case 'q' | 'Q':exit(0); break;

	case VK_ESCAPE:    gluDeleteQuadric(p); exit(0); break;
		//�����Ȱ�ü����������

	case GLUT_KEY_RIGHT: //���̽���ȸ��
		Base += 2.0;
		break;

	case GLUT_KEY_LEFT:
		Base -= 2.0;
		break;

	case GLUT_KEY_DOWN:    //�ȶ�ȸ��
		Lower_Arm -= 2.0;
		break;

	case GLUT_KEY_UP:
		Lower_Arm += 2.0;
		break;

	case GLUT_KEY_PAGE_DOWN://�ո�ȸ��
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
	//�����ʹ�ưŬ��(����)�����̿����·ε��ư�(���)
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

	//���̲��������°������ذ�����

	if (Lower_Arm >= 90.0)

		Lower_Arm = 90.0;

	if (Lower_Arm <= -90.0)

		Lower_Arm = -90.0;

	if (Upper_Arm >= 90.0)

		Upper_Arm = 90.0;

	if (Upper_Arm <= -90.0)

		Upper_Arm = -90;

	glutTimerFunc(33, timer, 1);    //Ÿ�̸��Լ�ȣ��
	glutPostRedisplay();    //�ٽñ׸���
}


void init(void)
{
	p = gluNewQuadric();    //��ü�Ҵ�(�޸𸮻���)
	gluQuadricDrawStyle(p, GLU_LINE);    //�׸��⽺Ÿ�Ͽɼ�
	Base = 0; Lower_Arm = 0; Upper_Arm = 0;
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);    //���������������̹�����������.
}


void OnReshape(int w, int h)    //ȭ��ũ�⺯���Reshape
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
{    //(����,������)���콺��������������true


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
{    //static�����Ͽ����̺������ʰ���
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