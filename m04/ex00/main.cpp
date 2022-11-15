#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	const Animal*		myAnimal = new Animal();
	const Animal*		myDog = new Dog();
	const Animal*		myCat = new Cat();
	const WrongAnimal*	myWrongAnimal = new WrongAnimal();
	const WrongCat*		myWrongCat = new WrongCat();

	std::cout << std::endl;

	std::cout << myAnimal->getType()		<< " " << std::endl;
	std::cout << myDog->getType()			<< " " << std::endl;
	std::cout << myCat->getType()			<< " " << std::endl;
	std::cout << myWrongAnimal->getType()	<< " " << std::endl;
	std::cout << myWrongCat->getType()		<< " " << std::endl;

	std::cout << std::endl;

    myAnimal->makeSound();
	myCat->makeSound();
	myDog->makeSound();
	myWrongAnimal->makeSound();
	myWrongCat->makeSound();

	return 0;
}
