// Operating_System_Simulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include "Block.hpp"
#include "BlockTable.hpp"
using namespace std;

int main()
{

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