#include <GLFW/glfw3.h>
#include<iostream>
#include <cstring>
#include <stdlib.h> 
#include <thread>         
#include <chrono>    
#include "math.h"
#include<vector>
#include"Header.h"
using namespace std;
mypainter2D my_painter;

void drawOnPixelBuffer()
{
	std::fill_n(my_painter.pixels, my_painter.width*my_painter.height * 3, 1.0f);
}
class GeometricObjectinterface
{
public:
	virtual void draw() 
	{}
};
class circle
{
public:
	int mid_x, mid_y, r_radius;
	float red, green, blue;

	circle() {}
	circle(int _mid_x, int _mid_y, int _r_radius, float _red, float _green, float _blue) :
		mid_x(_mid_x), mid_y(_mid_y), r_radius(_r_radius), red(_red), green(_green), blue(_blue)
	{}
public:
	void draw()
	{
		int z, k;
		mid_x = 200; mid_y = 200; r_radius = 80; red = 0; green = 255;  blue = 0;
		for (z = mid_y - 100; z < mid_y + 100; z++)
		{
			for (k = mid_x - 100; k < mid_x + 100; k++)
			{
				if ((k - mid_x)*(k - mid_x) + (z - mid_y)*(z - mid_y) < r_radius * r_radius)
				{
					my_painter.drawPixel(k, z, red, green, blue);
				}
			}
		}
	};
};
class Box
{
public:
	int start_x, start_y;
	int end_x, end_y;
	float red, green, blue;

	Box() {}
	Box(int _start_x, int _start_y, int _end_x, int _end_y, float _red, float _green, float _blue)
		:start_x(_start_x), start_y(_start_y), end_x(_end_x), end_y(_end_y), red(_red), green(_green), blue(_blue) {}

	void draw()
	{
		start_x = 300; start_y = 200; end_x = 400; end_y = 300; red = 255; green = blue = 0;
		for (int i = start_y; i < end_y; i++)
			my_painter.drawLine(start_x, i, end_x, i, red, green, blue);
	}
};

template<class T>
class GeometricObjectcolor :public GeometricObjectinterface
{
public:
	virtual void draw()
	{
		T draw_circle_box;
		draw_circle_box.draw();
	}
};

int main(void)
{
	int i, j;
	my_painter.initalize();

	std::vector<GeometricObjectinterface*> obj_list;
	obj_list.push_back(new GeometricObjectcolor<Box>);
	obj_list.push_back(new GeometricObjectcolor<circle>);

	while (!glfwWindowShouldClose(my_painter.window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		drawOnPixelBuffer();

		for (auto itr : obj_list)
			itr->draw();

		glDrawPixels(my_painter.width, my_painter.height, GL_RGB, GL_FLOAT, my_painter.pixels);
		glfwSwapBuffers(my_painter.window);
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
	glfwTerminate();

	return 0;
}