#include "Singleton.h"
int main()
{
	Singleton* s1 = Singleton::GetInstance();
	Singleton* s2 = Singleton::GetInstance();

	if (s1 == s2) {
		std::cout << "Both are same" << std::endl;
	}
}