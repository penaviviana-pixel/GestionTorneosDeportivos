// main.cpp - Punto de entrada de la aplicacion GestionTorneosView
#include "FormLogin.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    GestionTorneosView::FormLogin^ formLogin = gcnew GestionTorneosView::FormLogin();
    Application::Run(formLogin);

    return 0;
}

