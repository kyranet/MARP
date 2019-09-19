// Antonio Román Cerezo
// MARP37

#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"

typedef PriorityQueue<int64_t, std::less<int64_t>> priority_queue;

// función que resuelve el problema
int64_t resolver(priority_queue datos)
{
	if (datos.size() == 1)
		return 0;

	int64_t accumulator = 0;
	while (datos.size() > 1)
	{
		auto first = datos.top();
		datos.pop();
		auto second = datos.top();
		datos.pop();

		int64_t added = first + second;
		accumulator += added;
		datos.push(added);
	}

	return accumulator;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	size_t length;
	std::cin >> length;

	if (length == 0)
		return false;

	priority_queue priorityQueue;
	for (size_t i = 0; i < length; ++i)
	{
		int64_t number;
		std::cin >> number;
		priorityQueue.push(number);
	}

	auto sol = resolver(priorityQueue);
	std::cout << sol << '\n';

	return true;
}

int main()
{
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso())
		;

		// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
