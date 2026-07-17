#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <functional>
#include <map>
#include <unordered_set>
void Array() {
	std::array<int, 5> arr;
	for (int i = 0;i < arr.size();i++) {
		arr[i] = i;
	}
	auto itr = arr.begin();
	while (itr != arr.end()) {
		std::cout << *itr << " ";
		itr++;
	}
}
void Vector() {
	std::vector<int> vec{ 1,2,3,4 };
	for (int i = 0;i < 5;i++) {
		vec.push_back(i * 10);
		vec.erase(vec.begin());
		std::cout << "size:"<<vec.size() << "\n";
	}
}
void Set() {
	//std::set<int,std::greater<int>> set{ 67,6,7,3,2 };
	std::multiset<int, std::greater<int>> set{ 67,6,7,3,2 };
	set.insert(10);
	set.insert(2);
	set.insert(10);
	set.insert(15);
	set.insert(15);
	set.insert(15);
	set.insert(15);
	set.erase(10);
	set.erase(set.begin());
	for (auto x : set) {
		std::cout << ":" << x << " ";
	}
	auto found = set.equal_range(15);
	while (found.first != found.second) {
		std::cout << *found.first<<" ,";
		++found.first;
	}
}

void Map() {
	std::map<int, std::string> map{ {1,"superman"},
									{2,"batman"},
									{3,"green lantern"},
									{4,"ponaldo"},
									{5,"pessi"} };
	map[0] = "falsh";
	map.insert(std::pair<int,std::string>{ 7,"mordric" });
	map.insert({ 6,"aquaman" });
	map.insert({ 6,"aquamen" });//will not overwrite because it does not allow duplicate keys
	std::cout << map[30];//creates a key value and a default value for the second object in pair
	for (auto x : map) {
		std::cout <<x.first << ":" << x.second << "\n";
	}
	
}
void MultiMap() {
	std::multimap<int, std::string> map{ {1,"superman"},
									{2,"batman"},
									{3,"green lantern"},
									{4,"ponaldo"},
									{5,"pessi"} };
	
	map.insert(std::pair<int, std::string>{ 7, "mordric" });
	map.insert({ 6,"aquaman" });
	map.insert({ 6,"aquamen" });//will  overwrite because it does not allow duplicate keys
	
	for (auto x : map) {
		std::cout << x.first << ":" << x.second << "\n";
	}

}
void Unset() {
	std::unordered_set<std::string> coll;
	coll.insert("Batman");
	coll.insert("Superman ");
	coll.insert("Aquaman ");
	coll.insert("Spider-man ");
	coll.insert("Iron Man ");
	coll.insert("Thor");
	coll.insert("Hulk");
	coll.insert("Flash");
	coll.insert("Flashi");
	coll.insert("Kid-Flash");
	coll.insert("Loki");
	coll.insert("Ragnarok");
	coll.insert("Odin");
	coll.insert("Aarush");
	coll.insert("Dakshesh");
	coll.insert("Dakshesh");
	coll.insert("Dakshesh");
	coll.insert("Aslam");
	coll.insert("Amit");
	for (auto x : coll) {
		std::cout << "Bucket #:"<<coll.bucket(x)<<" contains:" << x << "\n";
	}
	std::cout << "\nBucket count:" << coll.bucket_count() << '\n';
	std::cout << "Number of elements:" << coll.size();
	std::cout << "\nLoad Factor:" << coll.load_factor() << "\n";

}
void Unmultiset() {
	std::unordered_multiset<std::string> coll;
	coll.insert("Batman");
	coll.insert("Superman ");
	coll.insert("Aquaman ");
	coll.insert("Spider-man ");
	coll.insert("Iron Man ");
	coll.insert("Thor");
	coll.insert("Hulk");
	coll.insert("Flash");
	coll.insert("Flashi");
	coll.insert("Kid-Flash");
	coll.insert("Loki");
	coll.insert("Ragnarok");
	coll.insert("Odin");
	coll.insert("Aarush");
	coll.insert("Dakshesh");
	coll.insert("Dakshesh");
	coll.insert("Dakshesh");
	coll.insert("Aslam");
	coll.insert("Amit");
	for (auto x : coll) {
		std::cout << "Bucket #:" << coll.bucket(x) << " contains:" << x << "\n";
	}
	std::cout << "\nBucket count:" << coll.bucket_count() << '\n';
	std::cout << "Number of elements:" << coll.size();
	std::cout << "\nLoad Factor:" << coll.load_factor() << "\n";

}
void Hashes() {
	std::hash<std::string> h;
	std::cout << "Hash:" << h("Hello") << '\n';
}

int main() {
	Array();
	std::cout << "\n";
	Vector();
	std::cout << "\n";
	Set();
	std::cout << "\n";
	Map();
	std::cout << "\n";
	MultiMap();
	std::cout << "\n";
	Unset();
	std::cout << "\n";
	Unmultiset();
	std::cout << "\n";
	Hashes();
}