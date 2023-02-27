#include <iostream>
#include <vector>
#include <fstream>

class Worker {
	std::string name;
	double salary;
	double percent;
public:
	Worker(std::string _name, double _salary, double _percent) {
		name = _name;
		salary = _salary;
		percent = _percent;
	}
	void print() {
		std::cout << name << '\n' << salary << '\n' << percent << '\n';
	}
	void money() {
		double tmp = (salary / 100) + percent;
		std::cout << "Full salary" << " " << salary + tmp;
	}
};

int main() 
{
	std::vector<Worker> workers;

	std::ifstream in("workers.txt");
	if (in.is_open()) {
		std::string workMan = " ";
		double sum = 0;
		double num = 0;
		while (true) {
			in >> workMan;
			if (in.eof()) {
				break;
			}
			in >> sum;
			in >> num;
			Worker tempWorker(workMan, sum, num);
			workers.push_back(tempWorker);
		}
	}
	in.close();
	for (auto& worker : workers) {
		worker.print();
		std::cout << '\n';
	}
}