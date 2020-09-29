#include <string>
#include "MemoryTable.hpp"
using namespace std;

MemoryTable::MemoryTable(int memorySize) {
	memoryList.resize(memorySize, "");
}

int MemoryTable::getMemoryListSize() {
	return memoryList.size();
}

vector<string>* MemoryTable::getMemoryList() {
	return &memoryList;
}

string MemoryTable::getInstruction(int address) {
	return this->memoryList[address];
}

void MemoryTable::setInstruction(int address, string instruction) {
	this->memoryList[address] = instruction;
}