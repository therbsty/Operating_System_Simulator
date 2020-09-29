#ifndef MemoryTable_H
#define MemoryTable_H
#include <string>
#include <vector>
using namespace std;

class MemoryTable {
private:
	vector<string> memoryList;
public:
	MemoryTable(int memorySize);
	int getMemoryListSize();
	vector<string>* getMemoryList();
	string getInstruction(int address);
	void setInstruction(int address, string instruction);

};

#endif // !MemoryTable_H