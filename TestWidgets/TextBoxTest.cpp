#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Label/Label.h"
#include "../Panel/Panel.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestWidgets
{

	TEST_CLASS(TestWidgets)
	{
	public:

		TEST_METHOD(TestSetGetText)
		{
			Label l(10);
			l.SetText("Hello");

			Assert::AreEqual(l.GetText().c_str(), "Hello");
			Assert::AreNotEqual(l.GetText().c_str(), "Hello     ");
		}

		TEST_METHOD(TestFocus)
		{
			Label l(10);
			l.SetFocusFlag(true);
			Assert::IsTrue(l.GetFocusFlag());
			l.FocusEvent();
			Assert::IsTrue(l.GetBackground() == Color::White && l.GetForeground() == Color::Black);
			l.FocusEvent();
			Assert::IsFalse(l.GetBackground() == Color::White && l.GetForeground() == Color::Black);

			l.SetFocusFlag(false);
			Assert::IsFalse(l.GetFocusFlag());
			l.FocusEvent();
			Assert::IsFalse(l.GetBackground() == Color::White && l.GetForeground() == Color::Black);
		}

		TEST_METHOD(TestGetAllControl)
		{
			Label l(10);
			vector<Widget*> controls(0);
			l.GetAllControls(controls);

			Assert::IsTrue(&l == controls[controls.size() - 1]);
		}

		TEST_METHOD(TestEditable)
		{
			Label l(10);
			Assert::IsFalse(l.GetEditable());
			l.SetEditable(true);
			Assert::IsTrue(l.GetEditable());
		}

		TEST_METHOD(TestWidthHeight)
		{
			Label l(10);
			Assert::IsTrue(l.GetHeight() == 1);
			l.SetHeight(10);
			Assert::IsTrue(l.GetHeight() == 10);
			Assert::IsTrue(l.GetWidth() == 10);
			l.SetWidth(4);
			Assert::IsTrue(l.GetWidth() == 4);
		}

		TEST_METHOD(TestLayer)
		{
			Label l(10);
			Assert::IsTrue(l.GetLayer() == 0);
			l.SetLayer(3);
			Assert::IsTrue(l.GetLayer() == 3);
		}

		TEST_METHOD(TestPosition)
		{
			Label l(10);
			l.SetX(5);
			l.SetY(5);
			Assert::IsTrue(l.GetX() == 5 && l.GetY() == 5);
		}
	};
}

