#include "MyForm.h"
#include <ctime> 
#include <cstdlib> 
using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	RandomNumbers::MyForm form;
	Application::Run(%form);
}
