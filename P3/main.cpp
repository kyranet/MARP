// Antonio Román Cerezo
// MARP37

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>
#include <exception>

struct Person
{
	std::string name;
	size_t insertion;
	int64_t priority;
};

struct PersonOperator
{
	bool operator()(const Person &left, const Person &right) const
	{
		if (left.priority == right.priority)
			return left.insertion > right.insertion;
		return left.priority < right.priority;
	}
};

typedef std::priority_queue<Person, std::vector<Person>, PersonOperator> problem_priority_queue;

// función que resuelve el problema
void resolver(problem_priority_queue& datos, const size_t insertion)
{
	char type;
	std::cin >> type;

	if (type == 'I')
	{
		std::string name;
		int64_t priority;
		std::cin >> name >> priority;
		datos.push({name, insertion, priority});
	}
	else if (type == 'A')
	{
		const auto atendee = datos.top();
		datos.pop();
		std::cout << atendee.name << '\n';
	}
	else
	{
		throw std::domain_error("Unexpected char");
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
	for (size_t i = 0; i < length; ++i)
		resolver(priorityQueue, i);

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
