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


// Teach operator>> how to input a Color
std::istream& operator>> (std::istream& in, Color &color)
{
    int input{};
    in >> input; // input an integer

    color = static_cast<Pet>(input);
    return in;
}


int main()
{
	std::cout << "Enter the color of your shirt (0=black, 1=red, 2=blue): ";
    	Color shirt{};
    	std::cin >> shirt; 
	std::cout << "Your shirt is " << shirt; 

	return 0;
}


