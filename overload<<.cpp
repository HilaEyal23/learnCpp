#include <iostream>

enum Color
{
	black,
	red,
	blue,
};

// Teach operator<< how to print a Color
std::ostream& operator<<(std::ostream& out, Color color)
{
	switch (color)
	{
	case black: out << "black";  break;
	case red:   out << "red";    break;
	case blue:  out << "blue";   break;
	default:    out << "???";    break;
	}

	return out;
}

int main()
{
	Color shirt{ blue };
	std::cout << "Your shirt is " << shirt; // it works!

	return 0;
}
