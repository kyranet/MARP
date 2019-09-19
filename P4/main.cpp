// Antonio Román Cerezo
// MARP37

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>

struct Till
{
	size_t id;
	int64_t next;
};

struct TillOperator
{
	bool operator()(const Till &left, const Till &right) const
	{
		if (left.next == right.next)
			return left.id > right.id;
		return left.next > right.next;
	}
};

typedef std::priority_queue<Till, std::vector<Till>, TillOperator> problem_priority_queue;

// función que resuelve el problema
void resolver(problem_priority_queue& datos, const uint64_t delay)
{
	auto value = datos.top();
	datos.pop();
	value.next += delay;
	datos.push(value);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	size_t tills, clients;
	std::cin >> tills >> clients;

	if (tills == 0 && clients == 0)
		return false;

	problem_priority_queue priorityQueue;
	for (size_t i = 0; i < tills; ++i)
		priorityQueue.push({ i + 1, 0 });

	for (size_t i = 0; i < clients; ++i)
	{
		uint64_t delay;
		std::cin >> delay;
		resolver(priorityQueue, delay);
	}

	std::cout << priorityQueue.top().id << '\n';

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
