#pragma once
#include "FormTorneos.h"
#include "FormEquipos.h"
#include "FormPartidos.h"
#include "FormInscripcion.h"
#include "FormTablaPosiciones.h"

namespace GestionTorneosView {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace GestionTorneosModel;

    public ref class FormMain : public Form {
    private:
        Panel^  panelTop;
        Label^  lblBienvenida;
        Label^  lblUsuario;
        Button^ btnCerrarSesion;

        Panel^  panelNav;
        Button^ btnTorneos;
        Button^ btnEquipos;
        Button^ btnPartidos;
        Button^ btnInscripciones;
        Button^ btnTablaPosiciones;
        Label^  lblMenuTitulo;

        Panel^  panelContent;
        Label^  lblWelcome;
        Label^  lblSubWelcome;
        Panel^  panelStats;

        Panel^  cardTorneos;
        Panel^  cardEquipos;
        Panel^  cardPartidos;
        Panel^  cardInscripciones;

        Usuario^ usuarioActual;

        System::Collections::Generic::List<Torneo^>^  torneos;
        System::Collections::Generic::List<Equipo^>^  equipos;
        System::Collections::Generic::List<Partido^>^ partidos;

        Panel^ CrearTarjeta(String^ titulo, String^ valor, Color color, Point ubicacion) {
            Panel^ card = gcnew Panel();
            card->Size      = Drawing::Size(165, 90);
            card->Location  = ubicacion;
            card->BackColor = color;

            Label^ lblValor = gcnew Label();
            lblValor->Text      = valor;
            lblValor->Font      = gcnew Drawing::Font(L"Segoe UI", 22, FontStyle::Bold);
            lblValor->ForeColor = Color::White;
            lblValor->Location  = Point(15, 10);
            lblValor->AutoSize  = true;

            Label^ lblTit = gcnew Label();
            lblTit->Text      = titulo;
            lblTit->Font      = gcnew Drawing::Font(L"Segoe UI", 8);
            lblTit->ForeColor = Color::FromArgb(220, 220, 220);
            lblTit->Location  = Point(15, 55);
            lblTit->AutoSize  = true;

            card->Controls->Add(lblValor);
            card->Controls->Add(lblTit);
            return card;
        }

        Button^ CrearBotonNav(String^ texto, int posY) {
            Button^ btn = gcnew Button();
            btn->Text      = texto;
            btn->Font      = gcnew Drawing::Font(L"Segoe UI", 10);
            btn->ForeColor = Color::White;
            btn->BackColor = Color::FromArgb(26, 82, 118);
            btn->FlatStyle = FlatStyle::Flat;
            btn->FlatAppearance->BorderSize  = 0;
            btn->FlatAppearance->MouseOverBackColor = Color::FromArgb(40, 116, 166);
            btn->Size      = Drawing::Size(200, 45);
            btn->Location  = Point(0, posY);
            btn->TextAlign = ContentAlignment::MiddleLeft;
            btn->Padding   = System::Windows::Forms::Padding(20, 0, 0, 0);
            btn->Cursor    = Cursors::Hand;
            return btn;
        }

        Button^ CrearBtnTop(String^ txt, Color col, int x) {
            Button^ b = gcnew Button();
            b->Text      = txt;
            b->BackColor = col;
            b->ForeColor = Color::White;
            b->FlatStyle = FlatStyle::Flat;
            b->FlatAppearance->BorderSize = 0;
            b->Font      = gcnew Drawing::Font(L"Segoe UI", 8, FontStyle::Bold);
            b->Size      = Drawing::Size(100, 30);
            b->Location  = Point(x, 15);
            b->Cursor    = Cursors::Hand;
            return b;
        }

        void InitializeComponent() {
            this->panelTop          = gcnew Panel();
            this->lblBienvenida     = gcnew Label();
            this->lblUsuario        = gcnew Label();
            this->panelNav          = gcnew Panel();
            this->lblMenuTitulo     = gcnew Label();
            this->panelContent      = gcnew Panel();
            this->lblWelcome        = gcnew Label();
            this->lblSubWelcome     = gcnew Label();
            this->panelStats        = gcnew Panel();

            this->Text            = L"Gestion de Torneos";
            this->Size            = Drawing::Size(1000, 650);
            this->StartPosition   = FormStartPosition::CenterScreen;
            this->MinimumSize     = Drawing::Size(900, 600);
            this->BackColor       = Color::FromArgb(245, 247, 250);

            // Panel Top
            this->panelTop->Dock      = DockStyle::Top;
            this->panelTop->Height    = 60;
            this->panelTop->BackColor = Color::FromArgb(26, 82, 118);

            this->lblBienvenida->Text      = L"Gestion de Torneos Universitarios";
            this->lblBienvenida->Font      = gcnew Drawing::Font(L"Segoe UI", 13, FontStyle::Bold);
            this->lblBienvenida->ForeColor = Color::White;
            this->lblBienvenida->Location  = Point(15, 15);
            this->lblBienvenida->AutoSize  = true;

            this->lblUsuario->Text      = L"";
            this->lblUsuario->Font      = gcnew Drawing::Font(L"Segoe UI", 9);
            this->lblUsuario->ForeColor = Color::FromArgb(174, 214, 241);
            this->lblUsuario->Location  = Point(700, 20);
            this->lblUsuario->AutoSize  = true;

            this->btnCerrarSesion = CrearBtnTop(L"Cerrar sesion", Color::FromArgb(169, 50, 38), 880);
            this->btnCerrarSesion->Click += gcnew EventHandler(this, &FormMain::btnCerrarSesion_Click);

            this->panelTop->Controls->Add(this->lblBienvenida);
            this->panelTop->Controls->Add(this->lblUsuario);
            this->panelTop->Controls->Add(this->btnCerrarSesion);

            // Panel Nav
            this->panelNav->Dock      = DockStyle::Left;
            this->panelNav->Width     = 200;
            this->panelNav->BackColor = Color::FromArgb(26, 82, 118);

            this->lblMenuTitulo->Text      = L"  MENU";
            this->lblMenuTitulo->Font      = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            this->lblMenuTitulo->ForeColor = Color::FromArgb(174, 214, 241);
            this->lblMenuTitulo->Size      = Drawing::Size(200, 30);
            this->lblMenuTitulo->Location  = Point(0, 10);

            this->btnTorneos         = CrearBotonNav(L"  Torneos",          50);
            this->btnEquipos         = CrearBotonNav(L"  Equipos",         100);
            this->btnPartidos        = CrearBotonNav(L"  Partidos",        150);
            this->btnInscripciones   = CrearBotonNav(L"  Inscripciones",   200);
            this->btnTablaPosiciones = CrearBotonNav(L"  Tabla Posiciones",250);

            this->btnTorneos->Click         += gcnew EventHandler(this, &FormMain::btnTorneos_Click);
            this->btnEquipos->Click         += gcnew EventHandler(this, &FormMain::btnEquipos_Click);
            this->btnPartidos->Click        += gcnew EventHandler(this, &FormMain::btnPartidos_Click);
            this->btnInscripciones->Click   += gcnew EventHandler(this, &FormMain::btnInscripciones_Click);
            this->btnTablaPosiciones->Click += gcnew EventHandler(this, &FormMain::btnTablaPosiciones_Click);

            this->panelNav->Controls->Add(this->lblMenuTitulo);
            this->panelNav->Controls->Add(this->btnTorneos);
            this->panelNav->Controls->Add(this->btnEquipos);
            this->panelNav->Controls->Add(this->btnPartidos);
            this->panelNav->Controls->Add(this->btnInscripciones);
            this->panelNav->Controls->Add(this->btnTablaPosiciones);

            // Panel Content
            this->panelContent->Dock      = DockStyle::Fill;
            this->panelContent->BackColor = Color::FromArgb(245, 247, 250);
            this->panelContent->Padding   = System::Windows::Forms::Padding(20);

            this->lblWelcome->Text      = L"Bienvenido al Sistema";
            this->lblWelcome->Font      = gcnew Drawing::Font(L"Segoe UI", 18, FontStyle::Bold);
            this->lblWelcome->ForeColor = Color::FromArgb(26, 82, 118);
            this->lblWelcome->Location  = Point(25, 25);
            this->lblWelcome->AutoSize  = true;

            this->lblSubWelcome->Text      = L"Seleccione una opcion del menu lateral para comenzar.";
            this->lblSubWelcome->Font      = gcnew Drawing::Font(L"Segoe UI", 10);
            this->lblSubWelcome->ForeColor = Color::Gray;
            this->lblSubWelcome->Location  = Point(25, 65);
            this->lblSubWelcome->AutoSize  = true;

            this->panelStats->Location  = Point(25, 110);
            this->panelStats->Size      = Drawing::Size(740, 100);
            this->panelStats->BackColor = Color::Transparent;

            this->cardTorneos       = CrearTarjeta(L"Torneos activos",     L"0", Color::FromArgb(26, 82, 118),   Point(0,   0));
            this->cardEquipos       = CrearTarjeta(L"Equipos registrados", L"0", Color::FromArgb(40, 116, 166),  Point(185, 0));
            this->cardPartidos      = CrearTarjeta(L"Partidos jugados",    L"0", Color::FromArgb(22, 160, 133),  Point(370, 0));
            this->cardInscripciones = CrearTarjeta(L"Inscripciones",       L"0", Color::FromArgb(211, 84, 0),    Point(555, 0));

            this->panelStats->Controls->Add(this->cardTorneos);
            this->panelStats->Controls->Add(this->cardEquipos);
            this->panelStats->Controls->Add(this->cardPartidos);
            this->panelStats->Controls->Add(this->cardInscripciones);

            this->panelContent->Controls->Add(this->lblWelcome);
            this->panelContent->Controls->Add(this->lblSubWelcome);
            this->panelContent->Controls->Add(this->panelStats);

            this->Controls->Add(this->panelContent);
            this->Controls->Add(this->panelNav);
            this->Controls->Add(this->panelTop);
        }

        void InicializarDatos() {
            torneos  = gcnew System::Collections::Generic::List<Torneo^>();
            equipos  = gcnew System::Collections::Generic::List<Equipo^>();
            partidos = gcnew System::Collections::Generic::List<Partido^>();

            torneos->Add(gcnew Torneo(1, L"Torneo de Futbol 2026",
                DateTime::Now, DateTime::Now.AddMonths(2), L"Activo", L"Eliminacion directa"));
            torneos->Add(gcnew Torneo(2, L"Copa Basquetbol",
                DateTime::Now, DateTime::Now.AddMonths(1), L"Activo", L"Liga"));

            equipos->Add(gcnew Equipo(1, L"Los Tigres", L"Ingenieria"));
            equipos->Add(gcnew Equipo(2, L"Aguila FC",  L"Ciencias"));
            equipos->Add(gcnew Equipo(3, L"Halcones",   L"Medicina"));
        }

        void ActualizarValorTarjeta(Panel^ card, int valor) {
            for each (Control^ c in card->Controls) {
                Label^ lbl = dynamic_cast<Label^>(c);
                if (lbl != nullptr && lbl->Font->Size > 15) {
                    lbl->Text = valor.ToString();
                    return;
                }
            }
        }

        void ActualizarTarjetas() {
            ActualizarValorTarjeta(cardTorneos,       torneos->Count);
            ActualizarValorTarjeta(cardEquipos,       equipos->Count);
            ActualizarValorTarjeta(cardPartidos,      partidos->Count);
            ActualizarValorTarjeta(cardInscripciones, 0);
        }

    public:
        FormMain(Usuario^ usuario) {
            InitializeComponent();
            this->usuarioActual = usuario;
            lblUsuario->Text    = L"  " + usuario->getNombre();
            InicializarDatos();
            ActualizarTarjetas();
        }

    private:
        void btnTorneos_Click(Object^ sender, EventArgs^ e) {
            FormTorneos^ f = gcnew FormTorneos(torneos);
            f->ShowDialog(this);
            ActualizarTarjetas();
        }

        void btnEquipos_Click(Object^ sender, EventArgs^ e) {
            FormEquipos^ f = gcnew FormEquipos(equipos);
            f->ShowDialog(this);
            ActualizarTarjetas();
        }

        void btnPartidos_Click(Object^ sender, EventArgs^ e) {
            FormPartidos^ f = gcnew FormPartidos(partidos, equipos, torneos);
            f->ShowDialog(this);
            ActualizarTarjetas();
        }

        void btnInscripciones_Click(Object^ sender, EventArgs^ e) {
            FormInscripcion^ f = gcnew FormInscripcion(torneos, equipos);
            f->ShowDialog(this);
        }

        void btnTablaPosiciones_Click(Object^ sender, EventArgs^ e) {
            FormTablaPosiciones^ f = gcnew FormTablaPosiciones(torneos, equipos, partidos);
            f->ShowDialog(this);
        }

        void btnCerrarSesion_Click(Object^ sender, EventArgs^ e) {
            System::Windows::Forms::DialogResult res = MessageBox::Show(
                L"Esta seguro de que desea cerrar la sesion?",
                L"Confirmar", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
            if (res == System::Windows::Forms::DialogResult::Yes) {
                this->Close();
            }
        }
    };
}
