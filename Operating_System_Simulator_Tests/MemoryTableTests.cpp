#include "pch.h"
#include "CppUnitTest.h"
#include "../Operating_System_Simulator/MemoryTable.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MemoryTableTests
{
	TEST_CLASS(MemoryTableTests)
	{
	public:

		TEST_METHOD(TestConstructor)
		{
			MemoryTable memoryTable(10);
			Assert::AreEqual(string(""), memoryTable.getInstruction(0));
			Assert::AreEqual(string(""), memoryTable.getInstruction(4));
			Assert::AreEqual(string(""), memoryTable.getInstruction(9));
			Assert::AreEqual(10, memoryTable.getMemoryListSize());
		}

		TEST_METHOD(TestSetInstruction)
		{
			MemoryTable memoryTable(10);

			memoryTable.setInstruction(0, "first");
			memoryTable.setInstruction(4, "second");
			memoryTable.setInstruction(9, "third");

			Assert::AreEqual(string("first"), memoryTable.getInstruction(0));
			Assert::AreEqual(string("second"), memoryTable.getInstruction(4));
			Assert::AreEqual(string("third"), memoryTable.getInstruction(9));
		}

		TEST_METHOD(TestClearInstruction)
		{
			MemoryTable memoryTable(10);

			memoryTable.setInstruction(0, "first");
			memoryTable.setInstruction(4, "second");
			memoryTable.setInstruction(9, "third");
			memoryTable.setInstruction(0, "");
			memoryTable.setInstruction(4, "");
			memoryTable.setInstruction(9, "");

			Assert::AreEqual(string(""), memoryTable.getInstruction(0));
			Assert::AreEqual(string(""), memoryTable.getInstruction(4));
			Assert::AreEqual(string(""), memoryTable.getInstruction(9));
		}

		TEST_METHOD(TestGetInstruction)
		{
			MemoryTable memoryTable(10);

			memoryTable.setInstruction(0, "first");
			memoryTable.setInstruction(4, "second");
			memoryTable.setInstruction(9, "third");

			Assert::AreEqual(string("first"), memoryTable.getInstruction(0));
			Assert::AreEqual(string("second"), memoryTable.getInstruction(4));
			Assert::AreEqual(string("third"), memoryTable.getInstruction(9));

		}
	};
}
