#include "pch.h"
#include "CppUnitTest.h"
#include "../Program/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(met_count_strs)
		{
			char str[101] = ",--,--amm,--,--";
			Assert::AreEqual(count_strs(str), 4);
		}
	};
}
