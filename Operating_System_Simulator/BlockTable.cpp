
#include <iterator> 
#include <map> 
#include <vector> 
#include "Block.hpp"
#include "BlockTable.hpp"
using namespace std;

BlockTable::BlockTable(vector<int> blocksizes) {
	int currentPos = 0;
	int newID = 0;
	for (auto currentSize = blocksizes.begin(); currentSize != blocksizes.end(); ++currentSize) {
		Block newBlock(newID, currentPos, currentPos + *currentSize - 1);
		blockTable.insert({ newBlock.getBlockID(),newBlock });
		currentPos += *currentSize;
		newID++;
	}
}

Block* BlockTable::findBestFitFreeBlock(int jobSize){
	Block* bestFitFreeBlock = NULL;

	for (auto iterator = blockTable.begin(); iterator != blockTable.end(); ++iterator) {
		int currentSize = iterator->second.getSize();
		int sizeDifference = currentSize - jobSize;
		if (bestFitFreeBlock == NULL && sizeDifference >= 0) {
			bestFitFreeBlock = &(iterator->second);
		}
		else if (sizeDifference >= 0 && currentSize < bestFitFreeBlock->getSize()) {
			bestFitFreeBlock = &(iterator->second);
		}
	}
	return bestFitFreeBlock;
}

void BlockTable::freeBlock(Block* block) {
	block->setBusy(false);
}
