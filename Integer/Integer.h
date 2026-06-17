#pragma once
class Integer {
	int* ptr;
public:
	Integer();
	Integer(int i);
	Integer(Integer& i);
	Integer(Integer&& i);
	~Integer();
	void operator=(Integer& i);
	void operator=(Integer&& i);
	int get() {
		return *ptr;
	}
	void set_val(int i);
};