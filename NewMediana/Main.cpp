#include "Header.h"
#include "Form1.h" //the header name for your form

using namespace NewMediana; //name of your project

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew Form1());
	return 0;
}