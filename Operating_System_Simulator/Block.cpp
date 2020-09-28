#include "Block.hpp"

Block::Block(int blockID, int start, int end) {
	this->blockID = blockID;
	this->start = start;
	this->end = end;
	this->size = end - start + 1;
	this->busy = false;
}
int Block::getBlockID() {
	return this->blockID;
}
int Block::getStart() {
	return this->start;
}
int Block::getEnd() {
	return this->end;
}
int Block::getSize() {
	return this->size;
}
bool Block::getBusy() {
	return this->busy;
}
void Block::setBlockID(int blockID) {
	this->blockID = blockID;
}
void Block::setStart(int start) {
	this->start = start;
}
void Block::setEnd(int end) {
	this->end = end;
}
void Block::setSize(int size) {
	this->size = size;
}
void Block::setBusy(bool busy) {
	this->busy = busy;
}