#pragma once
#include "FormMain.h"

namespace GestionTorneosView {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace GestionTorneosModel;

    public ref class FormLogin : public Form {
    private:
        Label^      lblTitulo;
        Label^      lblSubtitulo;
        Label^      lblCorreo;
        Label^      lblPassword;
        TextBox^    txtCorreo;
        TextBox^    txtPassword;
        Button^     btnIngresar;
        Button^     btnCancelar;
        Panel^      panelHeader;
        Panel^      panelForm;
        Label^      lblError;
        CheckBox^   chkMostrarPassword;

        System::Collections::Generic::List<Usuario^>^ usuarios;

        void InitializeComponent() {
            this->lblTitulo          = gcnew Label();
            this->lblSubtitulo       = gcnew Label();
            this->lblCorreo          = gcnew Label();
            this->lblPassword        = gcnew Label();
            this->txtCorreo          = gcnew TextBox();
            this->txtPassword        = gcnew TextBox();
            this->btnIngresar        = gcnew Button();
            this->btnCancelar        = gcnew Button();
            this->panelHeader        = gcnew Panel();
            this->panelForm          = gcnew Panel();
            this->lblError           = gcnew Label();
            this->chkMostrarPassword = gcnew CheckBox();

            this->Text            = L"Gestion de Torneos - Iniciar Sesion";
            this->Size            = Drawing::Size(450, 560);
            this->StartPosition   = FormStartPosition::CenterScreen;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox     = false;
            this->BackColor       = Color::FromArgb(245, 247, 250);

            this->panelHeader->Dock      = DockStyle::Top;
            this->panelHeader->Height    = 140;
            this->panelHeader->BackColor = Color::FromArgb(26, 82, 118);

            this->lblTitulo->Text      = L"GESTION DE TORNEOS";
            this->lblTitulo->Font      = gcnew Drawing::Font(L"Segoe UI", 16, FontStyle::Bold);
            this->lblTitulo->ForeColor = Color::White;
            this->lblTitulo->AutoSize  = false;
            this->lblTitulo->Width     = 450;
            this->lblTitulo->Height    = 40;
            this->lblTitulo->Location  = Point(0, 40);
            this->lblTitulo->TextAlign = ContentAlignment::MiddleCenter;

            this->lblSubtitulo->Text      = L"Sistema Universitario de Deportes";
            this->lblSubtitulo->Font      = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Regular);
            this->lblSubtitulo->ForeColor = Color::FromArgb(174, 214, 241);
            this->lblSubtitulo->AutoSize  = false;
            this->lblSubtitulo->Width     = 450;
            this->lblSubtitulo->Height    = 25;
            this->lblSubtitulo->Location  = Point(0, 85);
            this->lblSubtitulo->TextAlign = ContentAlignment::MiddleCenter;

            this->panelForm->Location    = Point(30, 160);
            this->panelForm->Size        = Drawing::Size(390, 330);
            this->panelForm->BackColor   = Color::White;
            this->panelForm->BorderStyle = BorderStyle::FixedSingle;

            this->lblCorreo->Text     = L"Correo electronico:";
            this->lblCorreo->Font     = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            this->lblCorreo->Location = Point(25, 30);
            this->lblCorreo->AutoSize = true;

            this->txtCorreo->Location = Point(25, 55);
            this->txtCorreo->Size     = Drawing::Size(340, 28);
            this->txtCorreo->Font     = gcnew Drawing::Font(L"Segoe UI", 10);
            this->txtCorreo->Text     = L"usuario@universidad.edu";
            this->txtCorreo->ForeColor = Color::Gray;
            this->txtCorreo->GotFocus  += gcnew EventHandler(this, &FormLogin::txtCorreo_GotFocus);
            this->txtCorreo->LostFocus += gcnew EventHandler(this, &FormLogin::txtCorreo_LostFocus);

            this->lblPassword->Text     = L"Contrasena:";
            this->lblPassword->Font     = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            this->lblPassword->Location = Point(25, 100);
            this->lblPassword->AutoSize = true;

            this->txtPassword->Location     = Point(25, 125);
            this->txtPassword->Size         = Drawing::Size(340, 28);
            this->txtPassword->Font         = gcnew Drawing::Font(L"Segoe UI", 10);
            this->txtPassword->PasswordChar = '*';

            this->chkMostrarPassword->Text     = L"Mostrar contrasena";
            this->chkMostrarPassword->Location = Point(25, 165);
            this->chkMostrarPassword->AutoSize = true;
            this->chkMostrarPassword->Font     = gcnew Drawing::Font(L"Segoe UI", 8);
            this->chkMostrarPassword->ForeColor = Color::Gray;
            this->chkMostrarPassword->CheckedChanged += gcnew EventHandler(this, &FormLogin::chkMostrarPassword_CheckedChanged);

            this->lblError->Text      = L"";
            this->lblError->ForeColor = Color::Red;
            this->lblError->Font      = gcnew Drawing::Font(L"Segoe UI", 8, FontStyle::Italic);
            this->lblError->Location  = Point(25, 193);
            this->lblError->AutoSize  = false;
            this->lblError->Size      = Drawing::Size(340, 20);
            this->lblError->TextAlign = ContentAlignment::MiddleCenter;

            this->btnIngresar->Text      = L"INGRESAR";
            this->btnIngresar->Location  = Point(25, 225);
            this->btnIngresar->Size      = Drawing::Size(340, 45);
            this->btnIngresar->Font      = gcnew Drawing::Font(L"Segoe UI", 11, FontStyle::Bold);
            this->btnIngresar->BackColor = Color::FromArgb(26, 82, 118);
            this->btnIngresar->ForeColor = Color::White;
            this->btnIngresar->FlatStyle = FlatStyle::Flat;
            this->btnIngresar->FlatAppearance->BorderSize = 0;
            this->btnIngresar->Cursor    = Cursors::Hand;
            this->btnIngresar->Click    += gcnew EventHandler(this, &FormLogin::btnIngresar_Click);

            this->btnCancelar->Text      = L"Cancelar";
            this->btnCancelar->Location  = Point(25, 282);
            this->btnCancelar->Size      = Drawing::Size(340, 30);
            this->btnCancelar->Font      = gcnew Drawing::Font(L"Segoe UI", 9);
            this->btnCancelar->BackColor = Color::White;
            this->btnCancelar->ForeColor = Color::Gray;
            this->btnCancelar->FlatStyle = FlatStyle::Flat;
            this->btnCancelar->FlatAppearance->BorderColor = Color::LightGray;
            this->btnCancelar->Cursor    = Cursors::Hand;
            this->btnCancelar->Click    += gcnew EventHandler(this, &FormLogin::btnCancelar_Click);

            this->panelHeader->Controls->Add(this->lblTitulo);
            this->panelHeader->Controls->Add(this->lblSubtitulo);

            this->panelForm->Controls->Add(this->lblCorreo);
            this->panelForm->Controls->Add(this->txtCorreo);
            this->panelForm->Controls->Add(this->lblPassword);
            this->panelForm->Controls->Add(this->txtPassword);
            this->panelForm->Controls->Add(this->chkMostrarPassword);
            this->panelForm->Controls->Add(this->lblError);
            this->panelForm->Controls->Add(this->btnIngresar);
            this->panelForm->Controls->Add(this->btnCancelar);

            this->Controls->Add(this->panelHeader);
            this->Controls->Add(this->panelForm);

            this->txtPassword->KeyPress += gcnew KeyPressEventHandler(this, &FormLogin::txtPassword_KeyPress);
        }

        void CargarUsuariosPrueba() {
            usuarios = gcnew System::Collections::Generic::List<Usuario^>();
            usuarios->Add(gcnew Organizador(1, L"Admin Organizador", L"ORG001", true,
                L"admin@universidad.edu", L"Ingenieria", L"admin123"));
            usuarios->Add(gcnew Deportista(2, L"Carlos Gomez", L"DEP001", true,
                L"carlos@universidad.edu", L"Ciencias", L"carlos123", 10));
        }

    public:
        FormLogin() {
            InitializeComponent();
            CargarUsuariosPrueba();
        }

    private:
        void chkMostrarPassword_CheckedChanged(Object^ sender, EventArgs^ e) {
            this->txtPassword->PasswordChar = this->chkMostrarPassword->Checked ? '\0' : '*';
        }

        void txtCorreo_GotFocus(Object^ sender, EventArgs^ e) {
            if (txtCorreo->Text == L"usuario@universidad.edu" && txtCorreo->ForeColor == Color::Gray) {
                txtCorreo->Text      = L"";
                txtCorreo->ForeColor = Color::Black;
            }
        }

        void txtCorreo_LostFocus(Object^ sender, EventArgs^ e) {
            if (String::IsNullOrWhiteSpace(txtCorreo->Text)) {
                txtCorreo->Text      = L"usuario@universidad.edu";
                txtCorreo->ForeColor = Color::Gray;
            }
        }

        void txtPassword_KeyPress(Object^ sender, KeyPressEventArgs^ e) {
            if (e->KeyChar == (char)13) {
                btnIngresar_Click(sender, e);
            }
        }

        void btnIngresar_Click(Object^ sender, EventArgs^ e) {
            lblError->Text = L"";
            String^ correo = txtCorreo->Text->Trim();
            String^ pass   = txtPassword->Text;

            // Ignorar si el correo aun muestra el texto de ayuda (placeholder simulado)
            if (correo == L"usuario@universidad.edu" && txtCorreo->ForeColor == Color::Gray)
                correo = L"";

            if (String::IsNullOrEmpty(correo) || String::IsNullOrEmpty(pass)) {
                lblError->Text = L"Por favor complete todos los campos.";
                return;
            }

            Usuario^ usuarioEncontrado = nullptr;
            for each (Usuario^ u in usuarios) {
                if (u->autenticar(correo, pass)) {
                    usuarioEncontrado = u;
                    break;
                }
            }

            if (usuarioEncontrado != nullptr) {
                FormMain^ formMain = gcnew FormMain(usuarioEncontrado);
                formMain->Show();
                this->Hide();
                formMain->FormClosed += gcnew FormClosedEventHandler(this, &FormLogin::OnMainFormClosed);
            } else {
                lblError->Text = L"Correo o contrasena incorrectos.";
                txtPassword->Clear();
                txtPassword->Focus();
            }
        }

        void OnMainFormClosed(Object^ sender, FormClosedEventArgs^ e) {
            this->Close();
        }

        void btnCancelar_Click(Object^ sender, EventArgs^ e) {
            Application::Exit();
        }
    };
}
