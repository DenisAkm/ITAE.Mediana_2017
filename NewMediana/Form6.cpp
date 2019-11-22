#include "Header.h"
#include "Form6.h"
#include "Form5.h"
#include "Form1.h"

namespace NewMediana
{
	System::Void Form6::ProcessBarInitialization(int num)
{
		this->Show();
		progressBar1->Maximum = num;
		progressBar1->Value = 0;
		//label1->Text = "Выполняю..";
}
}


