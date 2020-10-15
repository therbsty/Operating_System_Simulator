#include "pch.h"
#include "CppUnitTest.h"
#include "../Operating_System_Simulator/BlockTable.cpp"
#include "../Operating_System_Simulator/Block.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BlockTableTests
{
	TEST_CLASS(BlockTableTests)
	{
	public:
		
		TEST_METHOD(TestConstructor)
		{
			vector<int> inPutBlockSizes;
			inPutBlockSizes.push_back(17);
			inPutBlockSizes.push_back(8);
			inPutBlockSizes.push_back(34);
			BlockTable blockTable(inPutBlockSizes);

			Assert::AreEqual(3, (int)blockTable.getBlockTable()->size());

			Assert::AreEqual(0, blockTable.getBlockTable()->at(0).getBlockID());
			Assert::AreEqual(1, blockTable.getBlockTable()->at(1).getBlockID());
			Assert::AreEqual(2, blockTable.getBlockTable()->at(2).getBlockID());

			Assert::AreEqual(0, blockTable.getBlockTable()->at(0).getStart());
			Assert::AreEqual(17, blockTable.getBlockTable()->at(1).getStart());
			Assert::AreEqual(25, blockTable.getBlockTable()->at(2).getStart());

			Assert::AreEqual(16, blockTable.getBlockTable()->at(0).getEnd());
			Assert::AreEqual(24, blockTable.getBlockTable()->at(1).getEnd());
			Assert::AreEqual(58, blockTable.getBlockTable()->at(2).getEnd());

			Assert::AreEqual(17, blockTable.getBlockTable()->at(0).getSize());
			Assert::AreEqual(8, blockTable.getBlockTable()->at(1).getSize());
			Assert::AreEqual(34, blockTable.getBlockTable()->at(2).getSize());

			Assert::AreEqual(false, blockTable.getBlockTable()->at(0).getBusy());
			Assert::AreEqual(false, blockTable.getBlockTable()->at(1).getBusy());
			Assert::AreEqual(false, blockTable.getBlockTable()->at(2).getBusy());

		}

		TEST_METHOD(TestFindBestFitFreeBlock)
		{
			vector<int> inPutBlockSizes;
			inPutBlockSizes.push_back(17);
			inPutBlockSizes.push_back(8);
			inPutBlockSizes.push_back(34);
			BlockTable blockTable(inPutBlockSizes);

			blockTable.assignBlock(&(blockTable.getBlockTable()->at(1)));


			Assert::AreEqual(blockTable.getBlockTable()->at(0).getBlockID(), blockTable.findBestFitFreeBlock(5)->getBlockID());
		}

		TEST_METHOD(TestAssignBlock)
		{
			vector<int> inPutBlockSizes;
			inPutBlockSizes.push_back(17);
			inPutBlockSizes.push_back(8);
			inPutBlockSizes.push_back(34);
			BlockTable blockTable(inPutBlockSizes);

			blockTable.assignBlock(&(blockTable.getBlockTable()->at(0)));
			blockTable.assignBlock(&(blockTable.getBlockTable()->at(1)));
			blockTable.assignBlock(&(blockTable.getBlockTable()->at(2)));


			Assert::AreEqual(true, blockTable.getBlockTable()->at(0).getBusy());
			Assert::AreEqual(true, blockTable.getBlockTable()->at(1).getBusy());
			Assert::AreEqual(true, blockTable.getBlockTable()->at(2).getBusy());
		}

		TEST_METHOD(TestFreeBlock)
		{
			vector<int> inPutBlockSizes;
			inPutBlockSizes.push_back(17);
			inPutBlockSizes.push_back(8);
			inPutBlockSizes.push_back(34);
			BlockTable blockTable(inPutBlockSizes);

			blockTable.assignBlock(&(blockTable.getBlockTable()->at(0)));
			blockTable.assignBlock(&(blockTable.getBlockTable()->at(1)));
			blockTable.assignBlock(&(blockTable.getBlockTable()->at(2)));

			blockTable.freeBlock(&(blockTable.getBlockTable()->at(0)));
			blockTable.freeBlock(&(blockTable.getBlockTable()->at(1)));
			blockTable.freeBlock(&(blockTable.getBlockTable()->at(2)));


			Assert::AreEqual(false, blockTable.getBlockTable()->at(0).getBusy());
			Assert::AreEqual(false, blockTable.getBlockTable()->at(1).getBusy());
			Assert::AreEqual(false, blockTable.getBlockTable()->at(2).getBusy());
		}
	};	
}
