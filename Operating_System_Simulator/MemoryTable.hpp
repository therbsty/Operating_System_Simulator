/*#ifndef MemoryTable_H
#define MemoryTable_H
#include <string>
#include <array>
using namespace std;

class MemoryTable {
private:
	string* memoryList;
public:
	MemoryTable(int memorySize);
	string* getMemoryList();
	string getInstruction(int address);
	void setInstruction(int address, string instruction);

};

#endif // !MemoryTable_H
*/