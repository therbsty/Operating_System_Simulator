#include <iostream>
#include <vector>
#include <map>
#include "Block.hpp"
#include "BlockTable.hpp"
#include "MemoryTable.hpp"
using namespace std;

void testBlockTable() {
    vector<int> inPutBlockSizes;
    inPutBlockSizes.push_back(17);
    inPutBlockSizes.push_back(8);
    inPutBlockSizes.push_back(34);

    BlockTable blockTable(inPutBlockSizes);
    map<int, Block>* ptr_blockTable = blockTable.getBlockTable();
    Block* block;
    cout << "------------------------------------------------------------------\nORIGINAL\n";
    for (auto iterator = ptr_blockTable->begin(); iterator != ptr_blockTable->end(); ++iterator) {
        cout << "\nID: " << iterator->first << "\t Start: " << iterator->second.getStart() << "\t End: " << iterator->second.getEnd() << "\t Size: " << iterator->second.getSize() << "\t Busy: " << iterator->second.getBusy() << "\n";
    }
    cout << "------------------------------------------------------------------\nADDING 35\n";

    block = blockTable.findBestFitFreeBlock(35);
    if (block == NULL) { cout << "that wont fit"; }
    else { blockTable.assignBlock(block); }
    for (auto iterator = ptr_blockTable->begin(); iterator != ptr_blockTable->end(); ++iterator) {
        cout << "\nID: " << iterator->first << "\t Start: " << iterator->second.getStart() << "\t End: " << iterator->second.getEnd() << "\t Size: " << iterator->second.getSize() << "\t Busy: " << iterator->second.getBusy() << "\n";
    }
    cout << "------------------------------------------------------------------\nADDING 15\n";

    block = blockTable.findBestFitFreeBlock(15);
    if (block == NULL) { cout << "that wont fit"; }
    else { blockTable.assignBlock(block); }
    for (auto iterator = ptr_blockTable->begin(); iterator != ptr_blockTable->end(); ++iterator) {
        cout << "\nID: " << iterator->first << "\t Start: " << iterator->second.getStart() << "\t End: " << iterator->second.getEnd() << "\t Size: " << iterator->second.getSize() << "\t Busy: " << iterator->second.getBusy() << "\n";
    }
    cout << "------------------------------------------------------------------\nADDING 9\n";

    block = blockTable.findBestFitFreeBlock(9);
    if (block == NULL) { cout << "that wont fit"; }
    else { blockTable.assignBlock(block); }
    for (auto iterator = ptr_blockTable->begin(); iterator != ptr_blockTable->end(); ++iterator) {
        cout << "\nID: " << iterator->first << "\t Start: " << iterator->second.getStart() << "\t End: " << iterator->second.getEnd() << "\t Size: " << iterator->second.getSize() << "\t Busy: " << iterator->second.getBusy() << "\n";
    }
    cout << "------------------------------------------------------------------\nADDING 12\n";

    block = blockTable.findBestFitFreeBlock(12);
    if (block == NULL) { cout << "that wont fit"; }
    else { blockTable.assignBlock(block); }
    for (auto iterator = ptr_blockTable->begin(); iterator != ptr_blockTable->end(); ++iterator) {
        cout << "\nID: " << iterator->first << "\t Start: " << iterator->second.getStart() << "\t End: " << iterator->second.getEnd() << "\t Size: " << iterator->second.getSize() << "\t Busy: " << iterator->second.getBusy() << "\n";
    }
    cout << "------------------------------------------------------------------\n";
}

void testMemoryTable() {
    cout << "------------------------------------------------------------------\nnew list\n";
    MemoryTable memoryTable(10);
    vector<string>* memoryList = memoryTable.getMemoryList();

    for (int i = 0; i < memoryTable.getMemoryListSize(); i++) {
        cout << "Address: " << i << "\t Instruction: " << memoryTable.getInstruction(i) << "\t empty: " << memoryTable.getInstruction(i).empty() << "\n";
    }

    cout << "------------------------------------------------------------------\nsetting 0-a,4-b,9-c\n";
    memoryTable.setInstruction(0, "a");
    memoryTable.setInstruction(4, "b");
    memoryTable.setInstruction(9, "c");

    for (int i = 0; i < memoryTable.getMemoryListSize(); i++) {
        cout << "Address: " << i << "\t Instruction: " << memoryTable.getInstruction(i) << "\t empty: " << memoryTable.getInstruction(i).empty() << "\n";
    }

    cout << "------------------------------------------------------------------\nremoving 4\n";
    memoryTable.setInstruction(4, "");

    for (int i = 0; i < memoryList->size(); i++) {
        cout << "Address: " << i << "\t Instruction: " << memoryList->at(i) << "\t empty: " << memoryList->at(i).empty() << "\n";
    }

}