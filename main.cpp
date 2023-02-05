#include <iostream>

class ComplexNum {
	public:
		double real;
		double imag;

		ComplexNum add(ComplexNum other){
			ComplexNum result;
			result.real = real + other.real;
			result.imag = imag + other.imag;
			return result;
		}

		ComplexNum multiply(ComplexNum other){
			ComplexNum result;
			result.real = (real * other.real) - (imag * other.imag);
			result.imag = (real * other.imag) + (imag * other.real);
			return result;
		}

		ComplexNum negate() {
			ComplexNum result;
			result.real = -real;
			result.imag = -imag;
			return result;
		}

		ComplexNum inversion() {
			ComplexNum result;
			result.real = real / (real*real + imag*imag);
			result.imag = -imag / (real*real + imag*imag);
			return result;
		}

		friend std::ostream& operator<<(std::ostream& os, const ComplexNum& num)
		{
			std::string op;
			if (num.imag > 0) {
				op = " + ";
				os << num.real << " + " << num.imag << 'i';
			} else {
				os << num.real << " - " << -num.imag << 'i';
			}

			return os;
		}
};

int main(int argc, char* const argv[]) {
	ComplexNum a, b;
	a.real = 1;
	a.imag = 2;
	b.real = -3;
	b.imag = 4;

	ComplexNum sum = a.add(b);
	ComplexNum prod = a.multiply(b);
	ComplexNum neg = a.negate();
	ComplexNum diff = a.add(b.negate());
	ComplexNum inverse = a.inversion();

	std::cout << "Complex Number a is " << a << std::endl;
	std::cout << "Complex Number b is " << b << std::endl;
	std::cout << "a + b is " << sum << std::endl;
	std::cout << "a - b is " << diff << std::endl;
	std::cout << "a * b is " << prod << std::endl;
	std::cout << "a negated is " << neg << std::endl;
	std::cout << "a inverse is " << inverse << std::endl;
}