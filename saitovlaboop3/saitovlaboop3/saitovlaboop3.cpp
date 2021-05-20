#include <iostream>
#include <Windows.h>
#include <string>
#include <math.h>

class Vector
{
protected:
	int x, y;

public:
	Vector() { x = y = 0; }

	Vector(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void set_vector(int x, int y) {
		this->x = x;
		this->y = y;	
	}

	int getx() { return x; }
	int gety() { return y; }
	void setx(int x) { this->x = x; }
	void sety(int y) { this->y = y; }
};

class VectorFigure : public Vector
{
private:
	Vector _vertexes[4];
public:
	VectorFigure()
	{
		_vertexes[0].set_vector(-50, 50);
		_vertexes[1].set_vector(50, 50);
		_vertexes[2].set_vector(50, -50);
		_vertexes[3].set_vector(-50, -50);
	}

	void draw(int shiftx = 0, int shifty = 0, bool fill = false)
	{
		int centerx = 200;
		int centery = 200;
		system("cls");
		HDC screen = GetDC(GetConsoleWindow());
		HPEN pen = CreatePen(0, 3, RGB(250, 250, 250));
		HPEN pen1 = CreatePen(0, 3, RGB(0, 250, 0));
		HPEN pen2 = CreatePen(0, 3, RGB(250, 0, 0));
		HPEN pen3 = CreatePen(0, 3, RGB(0, 0, 250));
		SelectObject(screen, pen);
		MoveToEx(screen, _vertexes[0].getx() + centerx + shiftx, _vertexes[0].gety() + centery + shifty, NULL);
		LineTo(screen, _vertexes[1].getx() + centerx + shiftx, _vertexes[1].gety() + centery + shifty);
		SelectObject(screen, pen1);
		LineTo(screen, _vertexes[2].getx() + centerx + shiftx, _vertexes[2].gety() + centery + shifty);
		SelectObject(screen, pen2);
		LineTo(screen, _vertexes[3].getx() + centerx + shiftx, _vertexes[3].gety() + centery + shifty);
		SelectObject(screen, pen3);
		LineTo(screen, _vertexes[0].getx() + centerx + shiftx, _vertexes[0].gety() + centery + shifty);

		if (fill)
		{
			SelectObject(screen, pen);
			for (int i = 0; i < 50; i++)
			{
				LineTo(screen, _vertexes[1].getx() + centerx + shiftx - i, _vertexes[1].gety() + centery + shifty - i);
				LineTo(screen, _vertexes[2].getx() + centerx + shiftx - i, _vertexes[2].gety() + centery + shifty + i);
				LineTo(screen, _vertexes[3].getx() + centerx + shiftx + i, _vertexes[3].gety() + centery + shifty + i);
				LineTo(screen, _vertexes[0].getx() + centerx + shiftx + i, _vertexes[0].gety() + centery + shifty - i);
			}
		}
	}

	void turn(double angle)
	{
		double anglerad = 3.14 / 180.0 * angle;
		for (int i = 0; i < 4; i++)
		{
			int newx = _vertexes[i].getx() * cos(anglerad) - _vertexes[i].gety() * sin(anglerad);
			int newy = _vertexes[i].getx() * sin(anglerad) + _vertexes[i].gety() * cos(anglerad);
			_vertexes[i].setx(newx);
			_vertexes[i].sety(newy);
		}
		draw();
	}

	void erase()
	{
		system("cls");
	}
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	VectorFigure rectangle;
	rectangle.draw();
	Sleep(1000);
	rectangle.turn(45.0);
	Sleep(1000);
	rectangle.draw(200, 150);
	Sleep(1000);
	rectangle.turn(-45.0);
	rectangle.draw(0, 0, true);

    return 0;
}