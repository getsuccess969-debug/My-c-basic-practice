#include <iostream>
/*class Project {
	std::string name;
public:
	Project(std::string name) {
		this->name = name;
	}
	~Project() { std::cout << "~Project()\n"; }
	void display() {
		std::cout << "[Project name]" << name << "\n";
	}
	void change(std::string name) {
		this->name = name;
	}
};
class Employee {
	std::shared_ptr<Project> prj;
public:
	Employee(std::shared_ptr<Project> pr) {
		prj = pr;
	}
	~Employee() { std::cout << "~Employee()["<< prj.use_count()<<"]\n"; }
	void get_info() {
		prj->display();
	}
};
class Printer {
	std::weak_ptr<int> m_val;
public:
	void Set(std::weak_ptr<int>  ptr) {
		m_val = ptr;
	}
	void print() {
		if (m_val.expired()) {
			std::cout << "resource no longer available\n";
			return;
		}
		auto sp = m_val.lock();
		std::cout << "Value is :" << *sp << "\ncount:"<<sp.use_count()<<"\n";
	}
};*/
/*class Employee;
class Project {
	
public:
	std::weak_ptr<Employee> emp;
	Project() {
		std::cout << "Project()\n";
	}
	~Project() {
		std::cout << "~Project()\n";
	}
	
};
class Employee {
	
public:
	std::shared_ptr<Project> proj;
	Employee() {
		std::cout << "Employee()\n";
	}
	~Employee() {
		std::cout << "~Employee()\n";
	}
	
};*/
class Point {
	int x, y;
public:
	Point(int x, int y) {
		this->x = x;
		this->y = y;

	}
	double square(int x) {
		return x * x;
	}
	double distance(Point &a) {
		return sqrt(square(x - a.x) + square(y - a.y));
	}
	double slope(Point &a) {
		return (x - a.x) / (y - a.y);
	}
};
int main() {
	/*std::shared_ptr<Project> prj{new Project("Video Editing")};
	Employee e1(prj), e2(prj), e3(prj);
	prj->change("Hola mi amigos!");
	e1.get_info();
	e2.get_info();
	e3.get_info();
	std::cout<<prj.use_count()<<"\n";*/
	/*Printer p;
	int num;
	std::cin >> num;
	auto ptr = std::make_shared<int>(num);
	p.Set(ptr);
	if (*ptr > 10) {
		ptr = nullptr;
	}
	
	p.print();*/
	/*auto emp = std::make_shared<Employee>();
	auto proj = std::make_shared<Project>();
	emp->proj = proj;
	proj->emp = emp;
	std::cout << "\n" << proj.use_count() << "\n" << emp.use_count();
	std::unique_ptr<int[]> in{new int[5] {1, 2, 3, 4, 5} };
	for (int i = 0;i < 5;i++) {
		std::cout << "\nptr[" << i << "]=" << (in)[i]<<"\n";
	}*/
	Point a(2, 3);
	Point b(5, 6);
	auto c = std::make_shared<Point>(3, 4);

	std::cout << "distance:" << a.distance(*c);
	std::cout << "\nslope:" << a.slope(b);
	

}