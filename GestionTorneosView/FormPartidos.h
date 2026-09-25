#pragma once

namespace GestionTorneosView {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace GestionTorneosModel;

    public ref class FormPartidos : public Form {
    private:
        Panel^       panelTop;
        Label^       lblTitulo;
        Button^      btnAgregar;
        Button^      btnRegistrarResultado;
        Button^      btnCerrar;
        DataGridView^ dgvPartidos;
        GroupBox^    grpDetalle;

        Label^          lblTorneo;
        ComboBox^       cmbTorneo;
        Label^          lblLocal;
        ComboBox^       cmbLocal;
        Label^          lblVisitante;
        ComboBox^       cmbVisitante;
        Label^          lblFecha;
        DateTimePicker^ dtpFecha;
        Label^          lblHora;
        DateTimePicker^ dtpHora;
        Button^         btnGuardar;
        Button^         btnLimpiar;

        GroupBox^      grpResultado;
        Label^         lblMarcLocal;
        NumericUpDown^ nudLocal;
        Label^         lblMarcVisit;
        NumericUpDown^ nudVisitante;
        Button^        btnGuardarResultado;

        System::Collections::Generic::List<Partido^>^ partidos;
        System::Collections::Generic::List<Equipo^>^  equipos;
        System::Collections::Generic::List<Torneo^>^  torneos;
        Partido^ partidoSeleccionado;

        Button^ CrearBtnTop(String^ txt, Color col, int x, int w) {
            Button^ b = gcnew Button();
            b->Text      = txt;
            b->BackColor = col;
            b->ForeColor = Color::White;
            b->FlatStyle = FlatStyle::Flat;
            b->FlatAppearance->BorderSize = 0;
            b->Font      = gcnew Drawing::Font(L"Segoe UI", 8, FontStyle::Bold);
            b->Size      = Drawing::Size(w, 30);
            b->Location  = Point(x, 12);
            b->Cursor    = Cursors::Hand;
            return b;
        }

        void AgregarLabelEnGrp(GroupBox^ grp, String^ txt, int x, int y) {
            Label^ l = gcnew Label();
            l->Text     = txt;
            l->Font     = gcnew Drawing::Font(L"Segoe UI", 8, FontStyle::Bold);
            l->Location = Point(x, y);
            l->AutoSize = true;
            grp->Controls->Add(l);
        }

        void InitializeComponent() {
            this->panelTop             = gcnew Panel();
            this->lblTitulo            = gcnew Label();
            this->dgvPartidos          = gcnew DataGridView();
            this->grpDetalle           = gcnew GroupBox();
            this->lblTorneo            = gcnew Label();
            this->cmbTorneo            = gcnew ComboBox();
            this->lblLocal             = gcnew Label();
            this->cmbLocal             = gcnew ComboBox();
            this->lblVisitante         = gcnew Label();
            this->cmbVisitante         = gcnew ComboBox();
            this->lblFecha             = gcnew Label();
            this->dtpFecha             = gcnew DateTimePicker();
            this->lblHora              = gcnew Label();
            this->dtpHora              = gcnew DateTimePicker();
            this->btnGuardar           = gcnew Button();
            this->btnLimpiar           = gcnew Button();
            this->grpResultado         = gcnew GroupBox();
            this->lblMarcLocal         = gcnew Label();
            this->nudLocal             = gcnew NumericUpDown();
            this->lblMarcVisit         = gcnew Label();
            this->nudVisitante         = gcnew NumericUpDown();
            this->btnGuardarResultado  = gcnew Button();

            this->Text          = L"Gestion de Partidos";
            this->Size          = Drawing::Size(1000, 600);
            this->StartPosition = FormStartPosition::CenterParent;
            this->BackColor     = Color::FromArgb(245, 247, 250);
            this->MinimizeBox   = false;

            // Panel Top
            this->panelTop->Dock      = DockStyle::Top;
            this->panelTop->Height    = 55;
            this->panelTop->BackColor = Color::FromArgb(41, 128, 185);

            lblTitulo->Text      = L"  Gestion de Partidos";
            lblTitulo->Font      = gcnew Drawing::Font(L"Segoe UI", 13, FontStyle::Bold);
            lblTitulo->ForeColor = Color::White;
            lblTitulo->Dock      = DockStyle::Left;
            lblTitulo->Width     = 350;
            lblTitulo->TextAlign = ContentAlignment::MiddleLeft;

            this->btnAgregar            = CrearBtnTop(L"+ Nuevo Partido",    Color::FromArgb(39, 174, 96),  360, 120);
            this->btnRegistrarResultado = CrearBtnTop(L"Registrar Resultado", Color::FromArgb(211, 84, 0),  490, 140);
            this->btnCerrar             = CrearBtnTop(L"Cerrar",             Color::FromArgb(80, 80, 80),   870, 80);

            btnAgregar->Click            += gcnew EventHandler(this, &FormPartidos::btnAgregar_Click);
            btnRegistrarResultado->Click += gcnew EventHandler(this, &FormPartidos::btnRegistrarResultado_Click);
            btnCerrar->Click             += gcnew EventHandler(this, &FormPartidos::btnCerrar_Click);

            panelTop->Controls->Add(lblTitulo);
            panelTop->Controls->Add(btnAgregar);
            panelTop->Controls->Add(btnRegistrarResultado);
            panelTop->Controls->Add(btnCerrar);

            // DataGridView
            dgvPartidos->Location            = Point(10, 65);
            dgvPartidos->Size                = Drawing::Size(600, 500);
            dgvPartidos->ReadOnly            = true;
            dgvPartidos->AllowUserToAddRows  = false;
            dgvPartidos->SelectionMode       = DataGridViewSelectionMode::FullRowSelect;
            dgvPartidos->MultiSelect         = false;
            dgvPartidos->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            dgvPartidos->BackgroundColor     = Color::White;
            dgvPartidos->BorderStyle         = BorderStyle::None;
            dgvPartidos->ColumnHeadersDefaultCellStyle->BackColor = Color::FromArgb(41, 128, 185);
            dgvPartidos->ColumnHeadersDefaultCellStyle->ForeColor = Color::White;
            dgvPartidos->ColumnHeadersDefaultCellStyle->Font = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            dgvPartidos->EnableHeadersVisualStyles = false;
            dgvPartidos->RowHeadersVisible = false;
            dgvPartidos->AlternatingRowsDefaultCellStyle->BackColor = Color::FromArgb(232, 244, 253);
            dgvPartidos->CellClick += gcnew DataGridViewCellEventHandler(this, &FormPartidos::dgvPartidos_CellClick);

            dgvPartidos->Columns->Add(L"ID",        L"ID");
            dgvPartidos->Columns->Add(L"Local",     L"Equipo Local");
            dgvPartidos->Columns->Add(L"Visitante", L"Equipo Visitante");
            dgvPartidos->Columns->Add(L"Fecha",     L"Fecha");
            dgvPartidos->Columns->Add(L"Marcador",  L"Marcador");
            dgvPartidos->Columns->Add(L"Estado",    L"Estado");
            dgvPartidos->Columns[0]->FillWeight = 25;

            // GroupBox Nuevo Partido
            grpDetalle->Text      = L"Nuevo Partido";
            grpDetalle->Location  = Point(620, 65);
            grpDetalle->Size      = Drawing::Size(365, 300);
            grpDetalle->Font      = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            grpDetalle->ForeColor = Color::FromArgb(41, 128, 185);

            AgregarLabelEnGrp(grpDetalle, L"Torneo:",           10, 25);
            cmbTorneo->Location = Point(10, 43); cmbTorneo->Width = 340; cmbTorneo->DropDownStyle = ComboBoxStyle::DropDownList;
            grpDetalle->Controls->Add(cmbTorneo);

            AgregarLabelEnGrp(grpDetalle, L"Equipo Local:",     10, 75);
            cmbLocal->Location = Point(10, 93); cmbLocal->Width = 340; cmbLocal->DropDownStyle = ComboBoxStyle::DropDownList;
            grpDetalle->Controls->Add(cmbLocal);

            AgregarLabelEnGrp(grpDetalle, L"Equipo Visitante:", 10, 125);
            cmbVisitante->Location = Point(10, 143); cmbVisitante->Width = 340; cmbVisitante->DropDownStyle = ComboBoxStyle::DropDownList;
            grpDetalle->Controls->Add(cmbVisitante);

            AgregarLabelEnGrp(grpDetalle, L"Fecha:", 10, 175);
            dtpFecha->Location = Point(10, 193); dtpFecha->Width = 160; dtpFecha->Format = DateTimePickerFormat::Short;
            grpDetalle->Controls->Add(dtpFecha);

            AgregarLabelEnGrp(grpDetalle, L"Hora:", 185, 175);
            dtpHora->Location = Point(185, 193); dtpHora->Width = 165; dtpHora->Format = DateTimePickerFormat::Time; dtpHora->ShowUpDown = true;
            grpDetalle->Controls->Add(dtpHora);

            btnGuardar->Text      = L"Guardar Partido";
            btnGuardar->Location  = Point(10, 240);
            btnGuardar->Size      = Drawing::Size(160, 35);
            btnGuardar->BackColor = Color::FromArgb(41, 128, 185);
            btnGuardar->ForeColor = Color::White;
            btnGuardar->FlatStyle = FlatStyle::Flat;
            btnGuardar->FlatAppearance->BorderSize = 0;
            btnGuardar->Font      = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            btnGuardar->Cursor    = Cursors::Hand;
            btnGuardar->Click    += gcnew EventHandler(this, &FormPartidos::btnGuardar_Click);
            grpDetalle->Controls->Add(btnGuardar);

            btnLimpiar->Text      = L"Limpiar";
            btnLimpiar->Location  = Point(185, 240);
            btnLimpiar->Size      = Drawing::Size(160, 35);
            btnLimpiar->BackColor = Color::Gray;
            btnLimpiar->ForeColor = Color::White;
            btnLimpiar->FlatStyle = FlatStyle::Flat;
            btnLimpiar->FlatAppearance->BorderSize = 0;
            btnLimpiar->Font      = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            btnLimpiar->Cursor    = Cursors::Hand;
            btnLimpiar->Click    += gcnew EventHandler(this, &FormPartidos::btnLimpiar_Click);
            grpDetalle->Controls->Add(btnLimpiar);

            // GroupBox Resultado
            grpResultado->Text      = L"Registrar Resultado";
            grpResultado->Location  = Point(620, 375);
            grpResultado->Size      = Drawing::Size(365, 145);
            grpResultado->Font      = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            grpResultado->ForeColor = Color::FromArgb(211, 84, 0);
            grpResultado->Enabled   = false;

            lblMarcLocal->Text     = L"Goles Local:";
            lblMarcLocal->Location = Point(10, 30);
            lblMarcLocal->AutoSize = true;
            lblMarcLocal->Font     = gcnew Drawing::Font(L"Segoe UI", 8, FontStyle::Bold);
            nudLocal->Location     = Point(10, 50);
            nudLocal->Width        = 80;
            nudLocal->Minimum      = 0;
            nudLocal->Maximum      = 99;

            lblMarcVisit->Text     = L"Goles Visitante:";
            lblMarcVisit->Location = Point(120, 30);
            lblMarcVisit->AutoSize = true;
            lblMarcVisit->Font     = gcnew Drawing::Font(L"Segoe UI", 8, FontStyle::Bold);
            nudVisitante->Location = Point(120, 50);
            nudVisitante->Width    = 80;
            nudVisitante->Minimum  = 0;
            nudVisitante->Maximum  = 99;

            btnGuardarResultado->Text      = L"Guardar Resultado";
            btnGuardarResultado->Location  = Point(10, 90);
            btnGuardarResultado->Size      = Drawing::Size(340, 35);
            btnGuardarResultado->BackColor = Color::FromArgb(211, 84, 0);
            btnGuardarResultado->ForeColor = Color::White;
            btnGuardarResultado->FlatStyle = FlatStyle::Flat;
            btnGuardarResultado->FlatAppearance->BorderSize = 0;
            btnGuardarResultado->Font      = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            btnGuardarResultado->Cursor    = Cursors::Hand;
            btnGuardarResultado->Click    += gcnew EventHandler(this, &FormPartidos::btnGuardarResultado_Click);

            grpResultado->Controls->Add(lblMarcLocal);
            grpResultado->Controls->Add(nudLocal);
            grpResultado->Controls->Add(lblMarcVisit);
            grpResultado->Controls->Add(nudVisitante);
            grpResultado->Controls->Add(btnGuardarResultado);

            this->Controls->Add(panelTop);
            this->Controls->Add(dgvPartidos);
            this->Controls->Add(grpDetalle);
            this->Controls->Add(grpResultado);
        }

        void CargarCombos() {
            cmbTorneo->Items->Clear();
            cmbLocal->Items->Clear();
            cmbVisitante->Items->Clear();
            for each (Torneo^ t in torneos)  cmbTorneo->Items->Add(t->getNombreTorneo());
            for each (Equipo^ eq in equipos) {
                cmbLocal->Items->Add(eq->getNombreEquipo());
                cmbVisitante->Items->Add(eq->getNombreEquipo());
            }
        }

        void CargarGrilla() {
            dgvPartidos->Rows->Clear();
            for each (Partido^ p in partidos) {
                String^ marcador = p->getMarcadorLocal().ToString() + L" - " + p->getMarcadorVisitante().ToString();
                String^ local    = p->getEquipoLocal()     != nullptr ? p->getEquipoLocal()->getNombreEquipo()     : L"?";
                String^ visit    = p->getEquipoVisitante() != nullptr ? p->getEquipoVisitante()->getNombreEquipo() : L"?";
                dgvPartidos->Rows->Add(p->getIdPartido(), local, visit,
                    p->getFecha().ToShortDateString(), marcador, p->getEstadoPartido());
            }
        }

        void LimpiarFormulario() {
            cmbTorneo->SelectedIndex    = -1;
            cmbLocal->SelectedIndex     = -1;
            cmbVisitante->SelectedIndex = -1;
            dtpFecha->Value  = DateTime::Now;
            dtpHora->Value   = DateTime::Now;
            grpResultado->Enabled = false;
            partidoSeleccionado   = nullptr;
        }

    public:
        FormPartidos(System::Collections::Generic::List<Partido^>^ listaPartidos,
                     System::Collections::Generic::List<Equipo^>^  listaEquipos,
                     System::Collections::Generic::List<Torneo^>^  listaTorneos) {
            partidos = listaPartidos;
            equipos  = listaEquipos;
            torneos  = listaTorneos;
            partidoSeleccionado = nullptr;
            InitializeComponent();
            CargarCombos();
            CargarGrilla();
        }

    private:
        void dgvPartidos_CellClick(Object^ sender, DataGridViewCellEventArgs^ e) {
            if (e->RowIndex < 0 || e->RowIndex >= partidos->Count) return;
            partidoSeleccionado   = partidos[e->RowIndex];
            grpResultado->Enabled = (partidoSeleccionado->getEstadoPartido() != L"Finalizado");
        }

        void btnAgregar_Click(Object^ sender, EventArgs^ e) {
            LimpiarFormulario();
            cmbTorneo->Focus();
        }

        void btnRegistrarResultado_Click(Object^ sender, EventArgs^ e) {
            if (partidoSeleccionado == nullptr) {
                MessageBox::Show(L"Seleccione un partido de la lista.", L"Aviso",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
                return;
            }
            grpResultado->Enabled = true;
        }

        void btnGuardar_Click(Object^ sender, EventArgs^ e) {
            if (cmbLocal->SelectedIndex < 0 || cmbVisitante->SelectedIndex < 0) {
                MessageBox::Show(L"Seleccione los equipos.", L"Validacion",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            if (cmbLocal->SelectedIndex == cmbVisitante->SelectedIndex) {
                MessageBox::Show(L"El equipo local y visitante no pueden ser el mismo.", L"Validacion",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            Equipo^ local     = equipos[cmbLocal->SelectedIndex];
            Equipo^ visitante = equipos[cmbVisitante->SelectedIndex];
            int id = partidos->Count + 1;
            Partido^ nuevo = gcnew Partido(id, dtpFecha->Value, dtpHora->Value, local, visitante);
            nuevo->setEstadoPartido(L"Programado");
            partidos->Add(nuevo);
            MessageBox::Show(L"Partido registrado.", L"Exito",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
            LimpiarFormulario();
            CargarGrilla();
        }

        void btnGuardarResultado_Click(Object^ sender, EventArgs^ e) {
            if (partidoSeleccionado == nullptr) return;
            partidoSeleccionado->registrarResultado((int)nudLocal->Value, (int)nudVisitante->Value);
            partidoSeleccionado->finalizarPartido();
            MessageBox::Show(L"Resultado registrado correctamente.", L"Exito",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
            grpResultado->Enabled = false;
            CargarGrilla();
        }

        void btnLimpiar_Click(Object^ sender, EventArgs^ e) { LimpiarFormulario(); }
        void btnCerrar_Click(Object^ sender, EventArgs^ e)  { this->Close(); }
    };
}

