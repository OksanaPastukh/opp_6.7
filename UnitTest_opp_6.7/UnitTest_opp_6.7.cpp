#include "pch.h"
#include "CppUnitTest.h"
#include "../Project_opp_6.7/Array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestopp67
{
	TEST_CLASS(UnitTestopp67)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[5] = { 1, -2, 0, 4, -5 };
			int b[5];
			replace_copy(&a[0], &a[5], &b[0], 4, 99);
			int c = b[3];
			Assert::AreEqual(c, 99);
		}
	};
}
