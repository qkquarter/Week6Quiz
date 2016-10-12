#include <iostream>
#include <string>

template<class T_CLASS>
class Vector2D
{
public:
	T_CLASS x_, y_;

	Vector2D(const T_CLASS& x_input, const T_CLASS& y_input)
		: x_(x_input), y_(y_input)
	{}

	void print()
	{
		std::cout << x_ << " " << y_ << std::endl;
	}
};

int main()
{
	Vector2D<int> int_vector(1, 1);
	int_vector.print();

	Vector2D<float> float_vector(1.5, 1.5);
	float_vector.print();

	Vector2D<double> double_vector(1.156, 1.156);
	double_vector.print();


	return 0;
}