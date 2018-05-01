
#include <gl/glew.h>
#include <gl/glut.h>

#include <math.h>
#include <stdio.h>
#include <iostream>
#include <vector>
void drawCricel();
const int n = 70;
const GLfloat Pi = 3.1415926536f;
const GLfloat R = 0.5f;

static GLubyte Mask[128] =

{

	0x00, 0x00, 0x00, 0x00,    //   �����������һ��

	0x00, 0x00, 0x00, 0x00,

	0x03, 0x80, 0x01, 0xC0,    //   ��

	0x06, 0xC0, 0x03, 0x60,    //   ��

	0x04, 0x60, 0x06, 0x20,    //   ��

	0x04, 0x30, 0x0C, 0x20,    //   ��

	0x04, 0x18, 0x18, 0x20,    //   ʼ

	0x04, 0x0C, 0x30, 0x20,    //   ��

	0x04, 0x06, 0x60, 0x20,    //   ��

	0x44, 0x03, 0xC0, 0x22,    //   ��

	0x44, 0x01, 0x80, 0x22,    //   ��

	0x44, 0x01, 0x80, 0x22,    //   ��

	0x44, 0x01, 0x80, 0x22,    //   ʹ

	0x44, 0x01, 0x80, 0x22,    //   ��

	0x44, 0x01, 0x80, 0x22,

	0x44, 0x01, 0x80, 0x22,

	0x66, 0x01, 0x80, 0x66,

	0x33, 0x01, 0x80, 0xCC,

	0x19, 0x81, 0x81, 0x98,

	0x0C, 0xC1, 0x83, 0x30,

	0x07, 0xE1, 0x87, 0xE0,

	0x03, 0x3F, 0xFC, 0xC0,

	0x03, 0x31, 0x8C, 0xC0,

	0x03, 0x3F, 0xFC, 0xC0,

	0x06, 0x64, 0x26, 0x60,

	0x0C, 0xCC, 0x33, 0x30,

	0x18, 0xCC, 0x33, 0x18,

	0x10, 0xC4, 0x23, 0x08,

	0x10, 0x63, 0xC6, 0x08,

	0x10, 0x30, 0x0C, 0x08,

	0x10, 0x18, 0x18, 0x08,

	0x10, 0x00, 0x00, 0x08    // �����������һ��

};
void drawPolgon()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_POLYGON_STIPPLE);

	glPolygonStipple(Mask);

	glRectf(-0.5f, -0.5f, 0.0f, 0.0f);   // �����·�����һ�����ο�Ч����������

	glDisable(GL_POLYGON_STIPPLE);

	glRectf(0.0f, 0.0f, 0.5f, 0.5f);     // �����Ϸ�����һ�����ο�Ч����������

	glFlush();
}

void drawColor()
{
	int i;
	glShadeModel(GL_FLAT);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.0f, 0.0f);
	for (i = 0; i <= 8; ++i)
	{
		glColor3f(i & 0x04, i & 0x02, i & 0x01);
		glVertex2f(cos(i*Pi / 4), sin(i*Pi / 4));
	}
	glEnd();
	glFlush();
}
void drawOther()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPolygonMode(GL_FRONT, GL_FILL); // ��������Ϊ���ģʽ

	glPolygonMode(GL_BACK, GL_LINE);   // ���÷���Ϊ����ģʽ

	glFrontFace(GL_CCW);               // ������ʱ�뷽��Ϊ����

	glBegin(GL_POLYGON);               // ����ʱ�����һ�������Σ������·�

	glVertex2f(-0.5f, -0.5f);

	glVertex2f(0.0f, -0.5f);

	glVertex2f(0.0f, 0.0f);

	glVertex2f(-0.5f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);               // ��˳ʱ�����һ�������Σ������Ϸ�

	glVertex2f(0.0f, 0.0f);

	glVertex2f(0.0f, 0.5f);

	glVertex2f(0.5f, 0.5f);

	glVertex2f(0.5f, 0.0f);

	glEnd();
}

// ̫�������������
// ����ÿ���¶���30��
// һ��12���£�����360��
static int day = 200; // day�ı仯����0��359
void myDisplay(void)
{
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75, 1, 1, 400000000);
	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
	gluLookAt(0, -200000000, 200000000, 0, 0, 0, 0, 0, 1);

	// ���ƺ�ɫ�ġ�̫����
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(69600000, 20, 20);
	// ������ɫ�ġ�����
	glColor3f(0.0f, 0.0f, 1.0f);
	glRotatef(day / 360.0*360.0, 0.0f, 0.0f, -1.0f);
	glTranslatef(150000000, 0.0f, 0.0f);
	glutSolidSphere(15945000, 20, 20);
	// ���ƻ�ɫ�ġ�������
	glColor3f(1.0f, 1.0f, 0.0f);
	glRotatef(day / 30.0*360.0 - day / 360.0*360.0, 0.0f, 0.0f, -1.0f);
	glTranslatef(38000000, 0.0f, 0.0f);
	glutSolidSphere(4345000, 20, 20);

	glFlush();
}
void drawStripLine()
{

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(2, 0x333);

	glLineWidth(5.0f);
	glBegin(GL_LINES);
	glVertex2f(0.0f,0.0f);
	glVertex2f(0.0f,0.5f);
	glEnd();

}

void drawTriangle()
{

	//shader  
//	GLSLShader shader;

	//�����������Ͷ��㻺��������
	GLuint vaoID;
	GLuint vboVerticesID;
	GLuint vboIndicesID;
#if 1
	// �����ӿڲ���
	glViewport(0, 0, 400,400);


	/////////////////// Create the VBO ////////////////////
	float positionData[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f };

	float colorData[] = {
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f };



	// Create and set-up the vertex array object
	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);


	// Create and populate the buffer objects
	GLuint vboHandles[2];
	glGenBuffers(2, vboHandles);
	GLuint positionBufferHandle = vboHandles[0];
	GLuint colorBufferHandle = vboHandles[1];

	glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), positionData, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), colorData, GL_STATIC_DRAW);


	glEnableVertexAttribArray(0);  // Vertex position
	glEnableVertexAttribArray(1);  // Vertex color

	glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);

	glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);

	// Section2 ׼����ɫ������
	// Step1: ׼����ɫ��Դ����
	const GLchar* vertexShaderSource = "#version 330\n"
		"layout(location = 0) in vec3 position;\n"
		"void main()\n"
		"{\n gl_Position = vec4(position, 1.0);\n}";
	const GLchar* fragShaderSource = "#version 330\n"
		"out vec4 color;\n"
		"void main()\n"
		"{\n color = vec4(0.8, 0.8, 0.0, 1.0);\n}";
	// Step2 ����Shader object
	// ������ɫ��
	GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderId, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShaderId);
	GLint compileStatus = 0;
	glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &compileStatus); // ������״̬
	if (compileStatus == GL_FALSE) // ��ȡ���󱨸�
	{
		GLint maxLength = 0;
		glGetShaderiv(vertexShaderId, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<GLchar> errLog(maxLength);
		glGetShaderInfoLog(vertexShaderId, maxLength, &maxLength, &errLog[0]);
		std::cout << "Error::shader vertex shader compile failed," << &errLog[0] << std::endl;
	}
	// ƬԪ��ɫ��
	GLuint fragShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShaderId, 1, &fragShaderSource, NULL);
	glCompileShader(fragShaderId);
	glGetShaderiv(fragShaderId, GL_COMPILE_STATUS, &compileStatus);
	if (compileStatus == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(fragShaderId, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<GLchar> errLog(maxLength);
		glGetShaderInfoLog(fragShaderId, maxLength, &maxLength, &errLog[0]);
		std::cout << "Error::shader fragment shader compile failed," << &errLog[0] << std::endl;
	}
	// Step3 �����γ� shader program object
	GLuint shaderProgramId = glCreateProgram();
	glAttachShader(shaderProgramId, vertexShaderId);
	glAttachShader(shaderProgramId, fragShaderId);
	glLinkProgram(shaderProgramId);
	GLint linkStatus;
	glGetProgramiv(shaderProgramId, GL_LINK_STATUS, &linkStatus);
	if (linkStatus == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(shaderProgramId, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<GLchar> errLog(maxLength);
		glGetProgramInfoLog(shaderProgramId, maxLength, &maxLength, &errLog[0]);
		std::cout << "Error::shader link failed," << &errLog[0] << std::endl;
	}
	// ������ɺ�detach
	glDetachShader(shaderProgramId, vertexShaderId);
	glDetachShader(shaderProgramId, fragShaderId);
	// ����Ҫ���ӵ���������ʱ �ͷſռ�
	glDeleteShader(vertexShaderId);
	glDeleteShader(fragShaderId);

	// �����ɫ������ ����Ϊָ����ɫ
	glClearColor(0.18f, 0.04f, 0.14f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// ������д�������ƴ���
	glBindVertexArray(vaoID);
	glUseProgram(shaderProgramId);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glBindVertexArray(0);
	glUseProgram(0);
#endif
}
void display(void)
{	

#if 0
	glPointSize(2.0f);
	glLineWidth(2.0f);
	glLineStipple(33,2);
	glBegin(GL_LINES); // GL_LINES ��ĸ���������2 �ı���
	glVertex2f(0.0f,0.0f);
	glVertex2f(0.0f, 0.3f);
	glVertex2f(-0.3f,0.0f);
	glVertex2f(0.0f, 0.3f);
	glVertex2f(-0.3f, 0.0f);
	glVertex2f(0.0f, 0.0f);
//	glVertex2f(-1.0f,1.0f);
	glEnd();
#endif
//	drawCricel();
	//glutFullScreen();
	//drawStripLine();
	//drawOther();
	//drawPolgon();
//	drawColor();
	drawTriangle();

	glutFullScreen();
	glFlush();
}
void drawCricel()
{
	int i;
	glBegin(GL_POLYGON);
	for (i = 0; i<n; ++i)
		glVertex2f(R*cos(2 * Pi / n*i), R*sin(2 * Pi / n*i));
	glEnd();
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);

	glutInitWindowPosition(100,100);

	glutInitWindowSize(800,600);
	
	glutCreateWindow("opengl point");

	const GLubyte * name = glGetString(GL_VENDOR);
	const GLubyte * biaoshifu = glGetString(GL_RENDERER);
	const GLubyte * OpenGLVersion = glGetString(GL_VERSION);
	const GLubyte * gluVersion = gluGetString(GLU_VERSION);
	printf("OpenGLʵ�ֳ��̵����֣�%s\n", name);
	printf("��Ⱦ����ʶ����%s\n", biaoshifu);
	printf("OOpenGLʵ�ֵİ汾�ţ�%s\n", OpenGLVersion);
	printf("OGLU���߿�汾��%s\n", gluVersion);
	glutDisplayFunc(&myDisplay);

	glutMainLoop();

	return 0;
}