#pragma once
#include <iostream>
//diamond inheritance
class Stream
{
	std::string m_filename;
public:
	Stream(std::string filename) :m_filename(filename) {
		std::cout << "Stream(...)\n";
	}
	~Stream() {
		std::cout << "~Stream()\n";
	}
	void Getfilename() {
		std::cout << m_filename << "\n";
	}
};
class inStream:virtual public Stream
{
	
	int in;
public:
	inStream(std::string filename,int i) :Stream(filename),in(i) {
		std::cout << "inStream(...)\n";
	}
	~inStream() {
		std::cout << "~inStream()\n";
	}
};
class outStream :virtual public Stream
{
	
	int out;
public:
	outStream(std::string filename, int i) :Stream(filename), out(i) {
		std::cout << "outStream(...)\n";
	}
	~outStream() {
		std::cout << "~outStream()\n";
	}
};
class ioStream :public inStream,public outStream
{
	
public:
	ioStream(std::string filename, int i,int o) :Stream(filename),inStream(filename,i),outStream(filename,o){
		std::cout << "ioStream(...)\n";
	}
	~ioStream() {
		std::cout << "~ioStream()\n";
	}
};


