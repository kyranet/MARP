// Antonio Román Cerezo
// MARP37

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>

struct Person
{
	uint64_t id;
	uint64_t interval;
	uint64_t next;
};

struct PersonOperator
{
	bool operator()(const Person &left, const Person &right) const
	{
		if (left.next == right.next)
			return left.id > right.id;
		return left.next > right.next;
	}
};

typedef std::priority_queue<Person, std::vector<Person>, PersonOperator> problem_priority_queue;

// función que resuelve el problema
void resolver(problem_priority_queue& datos)
{
	size_t amount;
	std::cin >> amount;

	for (size_t i = 0; i < amount; ++i) {
		auto value = datos.top();
		datos.pop();

		// Print and patch
		std::cout << value.id << '\n';
		value.next += value.interval;
		datos.push(value);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	size_t length;
	std::cin >> length;

	if (length == 0)
		return false;

	problem_priority_queue priorityQueue;
	for (size_t i = 0; i < length; ++i) {
		uint64_t id, interval;
		std::cin >> id >> interval;
		priorityQueue.push({ id, interval, interval });
	}

	resolver(priorityQueue);
	std::cout << "---\n";

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
