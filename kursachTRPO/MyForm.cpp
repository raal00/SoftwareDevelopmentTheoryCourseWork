#include "MyForm.h"
using namespace kursachTRPO;
using namespace System;

[STAThread]
int main(void) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	MyForm form;
	Application::Run(% form);
	return 0;
}