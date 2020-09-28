#include "Block.hpp"
#include <iterator> 
#include <map> 
#include <vector>
using namespace std;

#ifndef BlockTable_H
#define BlockTable_H

class BlockTable {
private:
	map<int, Block> blockTable;
public:
	BlockTable(vector<int> blocksizes);
	map<int, Block>* getBlockTable();
	Block* findBestFitFreeBlock(int jobSize);
	void assignBlock(Block* block);
	void freeBlock(Block* block);
};

#endif // !BlockTable_H
