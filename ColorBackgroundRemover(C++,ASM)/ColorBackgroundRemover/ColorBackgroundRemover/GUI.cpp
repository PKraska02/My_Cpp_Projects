#include "GUI.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int Main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Create the main form and run the application
    ColorBackgroundRemover::GUI form;
    Application::Run(% form);

    return 0;
}
