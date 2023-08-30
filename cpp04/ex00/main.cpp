#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

/* 
Example of polymorphism and virtaul function in Inheritance 
  class Animal
  {
     public:
        virtual void makeSound()
        {
          cout << "Some generic animal sound" << endl;
        }
  };

  class Dog : public Animal
  {
     public:
        void makeSound()
        {
          cout << "Woof!" << endl;
        }
  };

  int main()
  {
    Animal *animal = new Animal();
    animal->makeSound();  // Outputs: "Some generic animal sound"

    animal = new Dog();
    animal->makeSound();  // Outputs: "Woof!"

    return 0;
  }
*/

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); // Output: Meow! Meow!
    j->makeSound(); // Output: Woof! Woof!
    meta->makeSound(); // Output: Animal sound
    wrong->makeSound(); // Output: WrongAnimal sound
    wrongCat->makeSound(); // Output: WrongAnimal sound

    delete meta;
    delete j;
    delete i;
    delete wrong;
    delete wrongCat;

    return 0;
}
