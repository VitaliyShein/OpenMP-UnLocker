#pragma once
#include <iostream>
#include <random>

void GenerateLock(unsigned long int numbers[], int tens)
{
	std::random_device rd;
	for (int i = 0; i < tens; i++)
	{
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, 9);
		numbers[i] = dis(gen);
	}
}

//Все непонятные функции относятся к библиотеке random и нужны для генерации цифры