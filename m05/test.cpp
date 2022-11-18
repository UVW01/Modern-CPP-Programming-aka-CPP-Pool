#include <stdexcept>
#include <limits>
#include <iostream>

class Bureaucrat
{
	private:
		const std::string name_;
		int grade_;

	public:
		Bureaucrat(std::string name, int grade) : name_(name), grade_(grade)
		{
			std::cout << this << std::endl;
			if (grade > 150)
				throw Bureaucrat::GradeL();
			else if (grade < 1)
				throw Bureaucrat::GradeH();
		};
		~Bureaucrat(void){
			std::cout << "Quitting" << std::endl;
		};

		class GradeH : public std::exception
		{
			public:
				virtual const char *what() const throw() {
					return ("too high\n");
				};
		};
		class GradeL : public std::exception
		{
			public:
				virtual const char *what() const throw() {
					return ("too low\n");
				};
		};
		void print(void) {
			std::cout << "hello world" << std::endl;
		}
		void info(void) {
			std::cout << "name: " << name_ << std::endl;
			std::cout << "grade: " << grade_ << std::endl;
		}
};

int main()
{
	Bureaucrat *c;
	try
	{
		c = new Bureaucrat("hello", 151); // cause an exception to throw
	}

	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << c << std::endl;
	c->info();
	//...
	return 0;
}