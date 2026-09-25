#pragma once

namespace GestionTorneosView {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace GestionTorneosModel;

    public ref class FormInscripcion : public Form {
    private:
        Panel^       panelTop;
        Label^       lblTitulo;
        Button^      btnCerrar;
        Button^      btnAprobar;
        Button^      btnRechazar;
        DataGridView^ dgvInscripciones;
        GroupBox^    grpNueva;

        Label^          lblTorneo;
        ComboBox^       cmbTorneo;
        Label^          lblEquipo;
        ComboBox^       cmbEquipo;
        Label^          lblFecha;
        DateTimePicker^ dtpFecha;
        Label^          lblPago;
        TextBox^        txtCodigoPago;
        Label^          lblMonto;
        NumericUpDown^  nudMonto;
        Label^          lblObs;
        TextBox^        txtObservaciones;
        Button^         btnInscribir;

        System::Collections::Generic::List<Torneo^>^      torneos;
        System::Collections::Generic::List<Equipo^>^      equipos;
        System::Collections::Generic::List<Inscripcion^>^ inscripciones;

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

        void AgregarLbl(GroupBox^ grp, String^ txt, int x, int y) {
            Label^ l = gcnew Label();
            l->Text     = txt;
            l->Font     = gcnew Drawing::Font(L"Segoe UI", 8, FontStyle::Bold);
            l->Location = Point(x, y);
            l->AutoSize = true;
            grp->Controls->Add(l);
        }

        void InitializeComponent() {
            this->panelTop         = gcnew Panel();
            this->lblTitulo        = gcnew Label();
            this->dgvInscripciones = gcnew DataGridView();
            this->grpNueva         = gcnew GroupBox();
            this->lblTorneo        = gcnew Label();
            this->cmbTorneo        = gcnew ComboBox();
            this->lblEquipo        = gcnew Label();
            this->cmbEquipo        = gcnew ComboBox();
            this->lblFecha         = gcnew Label();
            this->dtpFecha         = gcnew DateTimePicker();
            this->lblPago          = gcnew Label();
            this->txtCodigoPago    = gcnew TextBox();
            this->lblMonto         = gcnew Label();
            this->nudMonto         = gcnew NumericUpDown();
            this->lblObs           = gcnew Label();
            this->txtObservaciones = gcnew TextBox();
            this->btnInscribir     = gcnew Button();

            this->Text          = L"Inscripciones";
            this->Size          = Drawing::Size(950, 580);
            this->StartPosition = FormStartPosition::CenterParent;
            this->BackColor     = Color::FromArgb(245, 247, 250);
            this->MinimizeBox   = false;

            // Panel Top
            panelTop->Dock      = DockStyle::Top;
            panelTop->Height    = 55;
            panelTop->BackColor = Color::FromArgb(142, 68, 173);

            lblTitulo->Text      = L"  Inscripciones de Equipos";
            lblTitulo->Font      = gcnew Drawing::Font(L"Segoe UI", 13, FontStyle::Bold);
            lblTitulo->ForeColor = Color::White;
            lblTitulo->Dock      = DockStyle::Left;
            lblTitulo->Width     = 400;
            lblTitulo->TextAlign = ContentAlignment::MiddleLeft;

            this->btnAprobar  = CrearBtnTop(L"Aprobar",  Color::FromArgb(39, 174, 96),  410, 90);
            this->btnRechazar = CrearBtnTop(L"Rechazar", Color::FromArgb(169, 50, 38),  510, 90);
            this->btnCerrar   = CrearBtnTop(L"Cerrar",   Color::FromArgb(80, 80, 80),   840, 80);

            btnAprobar->Click  += gcnew EventHandler(this, &FormInscripcion::btnAprobar_Click);
            btnRechazar->Click += gcnew EventHandler(this, &FormInscripcion::btnRechazar_Click);
            btnCerrar->Click   += gcnew EventHandler(this, &FormInscripcion::btnCerrar_Click);

            panelTop->Controls->Add(lblTitulo);
            panelTop->Controls->Add(btnAprobar);
            panelTop->Controls->Add(btnRechazar);
            panelTop->Controls->Add(btnCerrar);

            // DataGridView
            dgvInscripciones->Location            = Point(10, 65);
            dgvInscripciones->Size                = Drawing::Size(580, 490);
            dgvInscripciones->ReadOnly            = true;
            dgvInscripciones->AllowUserToAddRows  = false;
            dgvInscripciones->SelectionMode       = DataGridViewSelectionMode::FullRowSelect;
            dgvInscripciones->MultiSelect         = false;
            dgvInscripciones->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            dgvInscripciones->BackgroundColor     = Color::White;
            dgvInscripciones->BorderStyle         = BorderStyle::None;
            dgvInscripciones->ColumnHeadersDefaultCellStyle->BackColor = Color::FromArgb(142, 68, 173);
            dgvInscripciones->ColumnHeadersDefaultCellStyle->ForeColor = Color::White;
            dgvInscripciones->ColumnHeadersDefaultCellStyle->Font = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            dgvInscripciones->EnableHeadersVisualStyles = false;
            dgvInscripciones->RowHeadersVisible = false;
            dgvInscripciones->AlternatingRowsDefaultCellStyle->BackColor = Color::FromArgb(245, 235, 250);

            dgvInscripciones->Columns->Add(L"ID",        L"ID");
            dgvInscripciones->Columns->Add(L"Fecha",     L"Fecha Registro");
            dgvInscripciones->Columns->Add(L"Estado",    L"Estado");
            dgvInscripciones->Columns->Add(L"CodigoPago", L"Cod. Pago");
            dgvInscripciones->Columns->Add(L"Obs",       L"Observaciones");
            dgvInscripciones->Columns[0]->FillWeight = 25;

            // GroupBox Nueva Inscripcion
            grpNueva->Text      = L"Nueva Inscripcion";
            grpNueva->Location  = Point(600, 65);
            grpNueva->Size      = Drawing::Size(340, 410);
            grpNueva->Font      = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            grpNueva->ForeColor = Color::FromArgb(142, 68, 173);

            AgregarLbl(grpNueva, L"Torneo:", 10, 25);
            cmbTorneo->Location = Point(10, 43); cmbTorneo->Width = 315; cmbTorneo->DropDownStyle = ComboBoxStyle::DropDownList;
            grpNueva->Controls->Add(cmbTorneo);

            AgregarLbl(grpNueva, L"Equipo:", 10, 75);
            cmbEquipo->Location = Point(10, 93); cmbEquipo->Width = 315; cmbEquipo->DropDownStyle = ComboBoxStyle::DropDownList;
            grpNueva->Controls->Add(cmbEquipo);

            AgregarLbl(grpNueva, L"Fecha Inscripcion:", 10, 125);
            dtpFecha->Location = Point(10, 143); dtpFecha->Width = 315; dtpFecha->Format = DateTimePickerFormat::Short;
            grpNueva->Controls->Add(dtpFecha);

            AgregarLbl(grpNueva, L"Codigo de Pago:", 10, 175);
            txtCodigoPago->Location = Point(10, 193); txtCodigoPago->Width = 155; txtCodigoPago->Font = gcnew Drawing::Font(L"Segoe UI", 9);
            grpNueva->Controls->Add(txtCodigoPago);

            AgregarLbl(grpNueva, L"Monto:", 175, 175);
            nudMonto->Location     = Point(175, 193); nudMonto->Width = 150; nudMonto->Minimum = 0; nudMonto->Maximum = 9999; nudMonto->DecimalPlaces = 2;
            grpNueva->Controls->Add(nudMonto);

            AgregarLbl(grpNueva, L"Observaciones:", 10, 225);
            txtObservaciones->Location  = Point(10, 243); txtObservaciones->Width = 315; txtObservaciones->Height = 50;
            txtObservaciones->Multiline = true; txtObservaciones->Font = gcnew Drawing::Font(L"Segoe UI", 9);
            grpNueva->Controls->Add(txtObservaciones);

            btnInscribir->Text      = L"Registrar Inscripcion";
            btnInscribir->Location  = Point(10, 310);
            btnInscribir->Size      = Drawing::Size(315, 40);
            btnInscribir->BackColor = Color::FromArgb(142, 68, 173);
            btnInscribir->ForeColor = Color::White;
            btnInscribir->FlatStyle = FlatStyle::Flat;
            btnInscribir->FlatAppearance->BorderSize = 0;
            btnInscribir->Font      = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            btnInscribir->Cursor    = Cursors::Hand;
            btnInscribir->Click    += gcnew EventHandler(this, &FormInscripcion::btnInscribir_Click);
            grpNueva->Controls->Add(btnInscribir);

            this->Controls->Add(panelTop);
            this->Controls->Add(dgvInscripciones);
            this->Controls->Add(grpNueva);
        }

        void CargarCombos() {
            cmbTorneo->Items->Clear();
            cmbEquipo->Items->Clear();
            for each (Torneo^ t in torneos)  cmbTorneo->Items->Add(t->getNombreTorneo());
            for each (Equipo^ eq in equipos) cmbEquipo->Items->Add(eq->getNombreEquipo());
        }

        void CargarGrilla() {
            dgvInscripciones->Rows->Clear();
            for each (Inscripcion^ insc in inscripciones) {
                auto estados = insc->getEstadoInscripcion();
                String^ estado = (estados != nullptr && estados->Count > 0) ? estados[estados->Count - 1] : L"Pendiente";
                String^ codPago = (insc->getObjPago() != nullptr) ? insc->getObjPago()->getCodigoOperacion() : L"";
                dgvInscripciones->Rows->Add(
                    insc->getIdInscripcion(),
                    insc->getFechaRegistro().ToShortDateString(),
                    estado,
                    codPago,
                    insc->getObservaciones()
                );
            }
        }

    public:
        FormInscripcion(System::Collections::Generic::List<Torneo^>^ listaTorneos,
                        System::Collections::Generic::List<Equipo^>^ listaEquipos) {
            torneos        = listaTorneos;
            equipos        = listaEquipos;
            inscripciones  = gcnew System::Collections::Generic::List<Inscripcion^>();
            InitializeComponent();
            CargarCombos();
            CargarGrilla();
        }

    private:
        void btnInscribir_Click(Object^ sender, EventArgs^ e) {
            if (cmbTorneo->SelectedIndex < 0 || cmbEquipo->SelectedIndex < 0) {
                MessageBox::Show(L"Seleccione el torneo y el equipo.", L"Validacion",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            if (String::IsNullOrWhiteSpace(txtCodigoPago->Text)) {
                MessageBox::Show(L"Ingrese el codigo de pago.", L"Validacion",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            Pago^ pago = gcnew Pago(inscripciones->Count + 1, (double)nudMonto->Value, txtCodigoPago->Text);
            auto estados = gcnew System::Collections::Generic::List<String^>();
            estados->Add(L"Pendiente");
            Inscripcion^ insc = gcnew Inscripcion(
                inscripciones->Count + 1, dtpFecha->Value, estados,
                txtObservaciones->Text, pago);
            inscripciones->Add(insc);
            MessageBox::Show(L"Inscripcion registrada. Estado: Pendiente de aprobacion.", L"Exito",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
            CargarGrilla();
        }

        void btnAprobar_Click(Object^ sender, EventArgs^ e) {
            if (dgvInscripciones->SelectedRows->Count == 0) {
                MessageBox::Show(L"Seleccione una inscripcion.", L"Aviso",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
                return;
            }
            int idx = dgvInscripciones->SelectedRows[0]->Index;
            if (idx < 0 || idx >= inscripciones->Count) return;
            inscripciones[idx]->aprobar();
            MessageBox::Show(L"Inscripcion aprobada.", L"Exito",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
            CargarGrilla();
        }

        void btnRechazar_Click(Object^ sender, EventArgs^ e) {
            if (dgvInscripciones->SelectedRows->Count == 0) {
                MessageBox::Show(L"Seleccione una inscripcion.", L"Aviso",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
                return;
            }
            int idx = dgvInscripciones->SelectedRows[0]->Index;
            if (idx < 0 || idx >= inscripciones->Count) return;
            inscripciones[idx]->rechazar(L"Rechazada por organizador");
            MessageBox::Show(L"Inscripcion rechazada.", L"Info",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
            CargarGrilla();
        }

        void btnCerrar_Click(Object^ sender, EventArgs^ e) { this->Close(); }
    };
}

