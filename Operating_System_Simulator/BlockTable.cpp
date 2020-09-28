
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
		this->blockTable.insert({ newBlock.getBlockID(),newBlock });
		currentPos += *currentSize;
		newID++;
	}
}

map<int, Block>* BlockTable::getBlockTable() {
	return &(this->blockTable);
}

Block* BlockTable::findBestFitFreeBlock(int jobSize){
	Block* bestFitFreeBlock = nullptr;

	for (auto iterator = blockTable.begin(); iterator != blockTable.end(); ++iterator) {
		int currentSize = iterator->second.getSize();
		int sizeDifference = currentSize - jobSize;
		if (sizeDifference >= 0 && bestFitFreeBlock == nullptr && iterator->second.getBusy() == false) {
			bestFitFreeBlock = &(iterator->second);
		}
		else if (bestFitFreeBlock == nullptr) {
			continue;
		}
		else if (sizeDifference >= 0 && iterator->second.getBusy() == false && currentSize < bestFitFreeBlock->getSize()) {
			bestFitFreeBlock = &(iterator->second);
		}
	}
	return bestFitFreeBlock;
}

void BlockTable::assignBlock(Block* block) {
	block->setBusy(true);
}

void BlockTable::freeBlock(Block* block) {
	block->setBusy(false);
}
