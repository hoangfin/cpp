#include <iostream>
#include "iter.hpp"

class Person {
	public:
		std::string name;
		int age;

		Person(const std::string& name, int age) : name(name), age(age) {}

		void introduce() const {
			std::cout << "Hi, I'm " << name << " and I'm " << age << " years old.\n";
		}
};

static void printElement(int x) {
    std::cout << x << " ";
}

int main() {
	{
		int array[] = {1, 2, 3, 4, 5};
		size_t length = sizeof(array) / sizeof(array[0]);

		iter<int, void(*)(int)>(array, length, printElement);
	}

	std::cout << "\nSecond example:\n";

	{
		Person people[] = {
			Person("Alice", 30),
			Person("Bob", 25),
			Person("Charlie", 35)
		};

		size_t length = sizeof(people) / sizeof(people[0]);

		std::cout << "Using a lambda function:\n";
		iter<Person>(people, length, [](Person& person) {
			std::cout << person.name << "\n";
		});

		std::cout << "\nUsing a member function pointer:\n";
		iter<Person>(people, length, [](Person& person) {
			person.introduce();
		});
	}

	std::cout << std::endl;
	return 0;
}
