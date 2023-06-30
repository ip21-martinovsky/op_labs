#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace lab7;

[STAThread]
void main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    MyForm form; 
    Application::Run(% form);
}