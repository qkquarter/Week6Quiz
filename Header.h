#pragma once
#include <GLFW/glfw3.h>
#include<iostream>

class mypainter2D
{
public:
	GLFWwindow* window;
	float *pixels;
	const int width;// = 640;
	const int height;// = 480;

	mypainter2D() :width(640), height(480)
	{
		pixels = new float[width*height * 3];
	}
	~mypainter2D() { if (pixels != nullptr)delete[] pixels; }
	void initalize()
	{
		if (!glfwInit())
		{
			std::cout << "glfw warning<" << std::endl;
			exit(1);
		}

		window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			std::cout << "window warning" << std::endl;
			exit(1);
		}
		glfwMakeContextCurrent(window);
	}

	void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
	{
		pixels[(i + width* j) * 3 + 0] = red;
		pixels[(i + width* j) * 3 + 1] = green;
		pixels[(i + width* j) * 3 + 2] = blue;
	}
	void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
	{
		if (i0 == i1 && j1 != j0)
		{
			for (int j = j0; j <= j1; j++)
			{
				const int i = (i1 - i0)*(j - j0) / (j1 - j0) + i0;

				drawPixel(i, j, red, green, blue);
			}
		}
		else if (j1 == j0 && i0 != i1)
		{
			for (int i = i0; i <= i1; i++)
			{
				const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

				drawPixel(i, j, red, green, blue);
			}
		}
		else
		{
			for (int i = i0; i <= i1; i++)
			{
				const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

				drawPixel(i, j, red, green, blue);
			}

		}
	}
};