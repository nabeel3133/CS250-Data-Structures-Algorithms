/*
Name: Nabeel Hussain Syed
Class: BSCS-5A
Reg No: 122937
Task 2 (Circular Linked List)
*/

/* TASKS DESCRIPTION
For insertion at a particular location, press "a" in open GL window and it will tell how to add a node at a particular location.
For deletion of a circle from a particular location, press "x" in open GL windw and it will tell how to delete a node from a particular location.
For forward traversion, press right keyboard key in open GL window to traverse forward. When once the right key is pressed, it will traverse one position forward. Then it will ask you to choose the color of the circle you are standing on. The rest is self explanatory.
*/

//Circle drawing function reference
//http://www.gamedeception.net/threads/4723-Drawing-a-circle-in-OpenGL-%28simple!%29
//en.wikipedia.org/wiki/Circle

#include <iostream>
#include "glut.h"
#include <stdio.h>
#include <conio.h>
#include <math.h>

#define M_PI 3.14159265358979323846f
using namespace std;

int g_Width = 400;
int g_Height = 400;

int Mouse_Pressed = 0;
int Mx = 0;
int My = 0;
int length = 5;		//Global circle size
int gravity = 0;
int node_circle;

void init();
void myMouseFunction(int button, int state, int mouseX, int mouseY);
void myKeyboardFunction(unsigned char key, int mouseX, int mouseY);
void mySpecialKeysFunction(int key, int x, int y);
void myReshapeFunction(int width, int height);
void myTimerFunction(int val);
void myDisplayFunction();
void myMouseMoveFunction(int x, int y);



class Circle {

	int x;
	int y;
	int radius;
	GLfloat r, g, b;

public:
	Circle *next;
	static int num_of_objects;
	Circle() { num_of_objects++; cout << "constructor called\n"; }
	~Circle() { cout << "destructor called\n"; num_of_objects--; }

	Circle(int a, int b, int c)
	{
		x = a; y = b; radius = c;
		num_of_objects++;
		cout << "constructor called\n";
		r = 1; g = 1; b = 1;
	}

	void set_data(int a, int b, int c)
	{
		x = a; y = b; radius = c;
	}

	void add_gravity(int g)
	{
		y -= g;
	}

	void set_color(GLfloat r, GLfloat g, GLfloat b) {
		this->r = r;
		this->g = g;
		this->b = b;
	}

	void get_color() {
		cout << "RGB Values are " << r << " " << g << " " << b << endl;
	}

	void increase_size(int s)
	{
		radius = s;
	}
	void draw_circle()
	{
		float angle;
		glColor3f(r, g, b);
		glLineWidth(1.0f);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 100; i++) {
			angle = i * 2 * M_PI / 100;
			glVertex2f(x + (cos(angle) * radius), y + (sin(angle) * radius));
		}
		glEnd();
	}
};
int Circle::num_of_objects = 0;
Circle *first = NULL;
Circle *current = NULL;

//Function to Draw all circles
void draw_all_circles()
{
	Circle *temp;
	temp = first;
	if (temp == NULL)
		cout << "LIST Empty" << endl;
	else {
		do
		{
			temp->draw_circle();
			temp = temp->next;
		} while (temp != first);
	}

}
void add_gravity_effect()
{
	Circle *temp;
	temp = first;
	if (temp == NULL)
		cout << "LIST Empty" << endl;
	else {
		while (temp->next != first) {
			temp->add_gravity(gravity);
			temp = temp->next;
		}
	}

}

void add_size_effect()
{
	Circle *temp;
	temp = first;
	if (temp == NULL)
		cout << "LIST Empty" << endl;
	else {
		while (temp->next != first) {
			temp->increase_size(length);
			temp = temp->next;
		}
	}
}
void delete_all()
{
	Circle *t1, *t2;
	t1 = first;
	while (t1->next != first) {
		//temp->draw_circle();
		t2 = t1;
		t1 = t1->next;
		delete t2;
	}
	first = NULL;
	current = NULL;
	//t1 = NULL;
	//t2 = NULL;
}

void change_circle_size_specific(int n, int s)
{
	int count = 0;
	Circle *temp;
	temp = first;
	if (temp == NULL)
		cout << "LIST Empty" << endl;
	else {
		while (++count != n) {

			temp = temp->next;
		}
		temp->increase_size(s);


	}
}
void change_circle_color_specific(int n, char c)
{
	int count = 0;
	Circle *temp;
	temp = first;
	if (temp == NULL)
		cout << "LIST Empty" << endl;
	else {
		while (++count != n) {

			temp = temp->next;
		}
		if (c == 'r')
		{
			temp->set_color(1.0f, 0.0f, 0.0f);
		}
		else if (c == 'g')
		{
			temp->set_color(0.0f, 1.0f, 0.0f);
		}
		else if (c == 'b')
		{
			temp->set_color(0.0f, 0.0f, 0.1f);
		}
		else if (c == 'y')
		{
			temp->set_color(1.0f, 1.0f, 0.0f);
		}
		else if (c == 'o')
		{
			temp->set_color(1.0f, 0.5f, 0.0f);
		}
		else if (c == 'w')
		{
			temp->set_color(1.0f, 1.0f, 1.0f);
		}
	}
}

void insert_circle_specific(int n, int x, int y)
{
	int count = 0;
	Circle *temp, *prev;
	temp = first;
	prev = first;
	Circle *newC = new Circle(x, y, 5);
	if (temp == NULL)
		cout << "LIST Empty" << endl;
	else {
		while (++count != n) {
			prev = temp;
			temp = temp->next;
		}
		if (temp == first) {		//If you want to insert a circle at the first node
			newC->next = first;
			current->next = newC;
			first = newC;

		}
		else if (temp->next != first)	//If you want to insert a circle in between
		{
			prev->next = newC;
			newC->next = temp;
		}
		else if (temp->next->next == first)	//If you want to insert a circle at the second last node
		{
			Circle *temp2 = temp->next;
			temp->next = newC;
			newC = temp;
			newC->next = temp2;
			newC->next->next = first;
			temp2->next = first;
		}
	}
}

void delete_circle_specific(int n)
{
	int count = 0;
	Circle *temp, *prev;
	temp = first;
	prev = first;
	if (temp == NULL)
		cout << "LIST Empty" << endl;
	else {
		while (++count != n) {
			prev = temp;
			temp = temp->next;
		}
		if (temp == first) {		//If you want to delete the first node
			first = temp->next;
			current->next = first;
			delete temp;
			temp = NULL;
		}
		else if (temp->next != first)	//If you want to delete a node in between 
		{
			prev->next = temp->next;
			delete temp;
			temp = NULL;
		}
		else if (temp->next == first)	//If you want to delete the last node
		{
			prev->next = first;
			current = prev;
			delete temp;
			temp = NULL;
		}
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(g_Width, g_Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Circles");

	init();//you dont have to worry abt this one

	glutMouseFunc(myMouseFunction);
	glutKeyboardFunc(myKeyboardFunction);
	glutSpecialFunc(mySpecialKeysFunction);
	glutMotionFunc(myMouseMoveFunction);

	glutReshapeFunc(myReshapeFunction);
	glutDisplayFunc(myDisplayFunction);
	glutTimerFunc(33, myTimerFunction, 0);
	//glutFullScreen();
	//glutSetCursor( GLUT_CURSOR_NONE );



	glutMainLoop();

	return 0;
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0.0, g_Width, 0.0, g_Height, -1.0, 1.0);
}

void myMouseFunction(int button, int state, int mouseX, int mouseY)
{
	Mx = mouseX;
	My = mouseY;
	Mouse_Pressed = state;
	if (state == 1 && button == 0) {
		if (first == NULL) {								//if list is empty
			first = new Circle(mouseX, 400 - mouseY, length);	//Create first circle
			first->next = first;							//set the next of first to itself
			current = first;								//set the current as first
			//first->draw_circle();
		}
		else {
			Circle *temp = new Circle(mouseX, 400 - mouseY, length);	//At the end create a temporary Circle
			current->next = temp;						//Add the new circle at the end of the list
			current = current->next;					//Update the current pointer to the new one
			current->next = first;						//Point the last next pointer to first

		}
	}

}

void myKeyboardFunction(unsigned char key, int mouseX, int mouseY)
{
	if (key == 'r') // i.e. Esc key	//Cjamge specific circle color
	{
		//display_circle_data(s);
		char c;
		int n;
		cout << "Which circle color do you want to change" << endl;
		cin >> n;
		cout << "Which color do you want to choose (r:red, g:green, b:blue, y:yellow, o:orange, w:white)" << endl;
		cin >> c;
		change_circle_color_specific(n, c);
	}
	else if (key == 's')		//Change specific circle size
	{
		int s;
		int n;
		cout << "Which circle size do you want to change" << endl;
		cin >> n;
		cout << "Enter size" << endl;
		cin >> s;
		change_circle_size_specific(n, s);
	}
	else if (key == 'x')		//Delete specific circle from linked list
	{

		int n;
		cout << "Which node circle do you want to delete: ";
		cin >> n;
		delete_circle_specific(n);
	}

	else if (key == 'a')
	{
		int node, x_cord, y_cord;
		cout << "In which node do you want to insert the circle: ";
		cin >> node;
		cout << "\nX coordinate of the circle's position: ";
		cin >> x_cord;
		cout << "\nY coordinate of the circle's position: ";
		cin >> y_cord;
		glutMouseFunc(myMouseFunction);
		insert_circle_specific(node, x_cord, y_cord);
	}

	else if (key == 'n')		//Display  number of current circles
		cout << "\n Number of current circles is " << Circle::num_of_objects << endl;
	else if (key == 'd')		//Delete all circles
		delete_all();
	else if (key == '+')		//Increase falling effect for all circles
		gravity++;
	else if (key == '-')		//Decrease falling effect for all circles
		gravity--;
	else if (key == 27)		//Escape key to exit
		exit(0);
}

void mySpecialKeysFunction(int key, int x, int y)
{
	char color_choose;
	switch (key)
	{
	case GLUT_KEY_UP:
		length++;
		break;
	case GLUT_KEY_DOWN:
		length--;
		break;
	case GLUT_KEY_LEFT:
		break;
	case GLUT_KEY_RIGHT:
		if (node_circle == 0)
		{
			current = first;
			cout << "\nYou have successfully traversed one position to the right";
			cout << "\nChoose color of the circle you are standing on (r:red, g:green, b:black, y:yellow, o:orange, w:white)" << endl;
			cin >> color_choose;
			if (color_choose == 'r')
			{
				current->set_color(1.0f, 0.0f, 0.0f);
			}
			else if (color_choose == 'g')
			{
				current->set_color(0.0f, 1.0f, 0.0f);
			}
			else if (color_choose == 'b')
			{
				current->set_color(0.0f, 0.0f, 0.1f);
			}
			else if (color_choose == 'y')
			{
				current->set_color(1.0f, 1.0f, 0.0f);
			}
			else if (color_choose == 'o')
			{
				current->set_color(1.0f, 0.5f, 0.0f);
			}
			else if (color_choose == 'w')
			{
				current->set_color(1.0f, 1.0f, 1.0f);
			}
			node_circle++;
		}
		else
		{
			Circle *temp;
			temp = current;
			if (current->next != NULL)
			{
				current = current->next;
				cout << "\nYou have successfully traversed one position to the right";
				cout << "\nChoose color of the circle you are standing on (r:red, g:green, b:black, y:yellow, o:orange, w:white)" << endl;
				cin >> color_choose;
				if (color_choose == 'r')
				{
					current->set_color(1.0f, 0.0f, 0.0f);
				}
				else if (color_choose == 'g')
				{
					current->set_color(0.0f, 1.0f, 0.0f);
				}
				else if (color_choose == 'b')
				{
					current->set_color(0.0f, 0.0f, 0.1f);
				}
				else if (color_choose == 'y')
				{
					current->set_color(1.0f, 1.0f, 0.0f);
				}
				else if (color_choose == 'o')
				{
					current->set_color(1.0f, 0.5f, 0.0f);
				}
				else if (color_choose == 'w')
				{
					current->set_color(1.0f, 1.0f, 1.0f);
				}
			}
		}
		break;
	case GLUT_KEY_HOME:
		break;
	case GLUT_KEY_END:
		break;
	case GLUT_KEY_PAGE_UP:
		break;
	case GLUT_KEY_PAGE_DOWN:
		break;
	}
}

void myReshapeFunction(int width, int height)
{
	glClear(GL_COLOR_BUFFER_BIT);

	g_Width = width;
	g_Height = height;

	glViewport(0, 0, g_Width, g_Height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, g_Width, 0.0, g_Height, -1.0, 1.0);
}

void myTimerFunction(int val)
{
	glutTimerFunc(33, myTimerFunction, 0);
	myDisplayFunction();
}
int i = 0;

void myDisplayFunction()
{
	glClear(GL_COLOR_BUFFER_BIT);
	if (first != NULL) {
		draw_all_circles();
		add_gravity_effect();
		//add_size_effect();
	}
	glutSwapBuffers();

}

void myMouseMoveFunction(int x, int y)
{
	//printf("Mouse moved at x:%d y:%d",x,y);
}