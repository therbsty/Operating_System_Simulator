#ifndef BlockTable_H
#define BlockTable_H
#include <iterator> 
#include <map> 
#include <vector>
#include "Block.hpp"
using namespace std;

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
