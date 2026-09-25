#pragma once

namespace GestionTorneosView {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace GestionTorneosModel;

    public ref class FormTorneos : public Form {
    private:
        Panel^       panelTop;
        Label^       lblTitulo;
        Button^      btnAgregar;
        Button^      btnEditar;
        Button^      btnEliminar;
        Button^      btnCerrar;
        DataGridView^ dgvTorneos;
        GroupBox^    grpDetalle;

        Label^          lblNombre;
        TextBox^        txtNombre;
        Label^          lblFechaInicio;
        DateTimePicker^ dtpFechaInicio;
        Label^          lblFechaFin;
        DateTimePicker^ dtpFechaFin;
        Label^          lblEstado;
        ComboBox^       cmbEstado;
        Label^          lblFormato;
        ComboBox^       cmbFormato;
        Button^         btnGuardar;
        Button^         btnLimpiar;

        System::Collections::Generic::List<Torneo^>^ torneos;
        Torneo^ torneoSeleccionado;
        bool modoEdicion;

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

        void AgregarCampo(Label^ lbl, String^ lblTxt, Control^ ctrl, int y) {
            lbl->Text     = lblTxt;
            lbl->Font     = gcnew Drawing::Font(L"Segoe UI", 8, FontStyle::Bold);
            lbl->Location = Point(10, y);
            lbl->AutoSize = true;
            ctrl->Location = Point(10, y + 18);
            ctrl->Width    = 280;
            grpDetalle->Controls->Add(lbl);
            grpDetalle->Controls->Add(ctrl);
        }

        void InitializeComponent() {
            this->panelTop      = gcnew Panel();
            this->lblTitulo     = gcnew Label();
            this->dgvTorneos    = gcnew DataGridView();
            this->grpDetalle    = gcnew GroupBox();
            this->lblNombre     = gcnew Label();
            this->txtNombre     = gcnew TextBox();
            this->lblFechaInicio = gcnew Label();
            this->dtpFechaInicio = gcnew DateTimePicker();
            this->lblFechaFin   = gcnew Label();
            this->dtpFechaFin   = gcnew DateTimePicker();
            this->lblEstado     = gcnew Label();
            this->cmbEstado     = gcnew ComboBox();
            this->lblFormato    = gcnew Label();
            this->cmbFormato    = gcnew ComboBox();
            this->btnGuardar    = gcnew Button();
            this->btnLimpiar    = gcnew Button();

            this->Text            = L"Gestion de Torneos";
            this->Size            = Drawing::Size(900, 580);
            this->StartPosition   = FormStartPosition::CenterParent;
            this->BackColor       = Color::FromArgb(245, 247, 250);
            this->MinimizeBox     = false;

            // Panel Top
            this->panelTop->Dock      = DockStyle::Top;
            this->panelTop->Height    = 55;
            this->panelTop->BackColor = Color::FromArgb(26, 82, 118);

            this->lblTitulo->Text      = L"  Gestion de Torneos";
            this->lblTitulo->Font      = gcnew Drawing::Font(L"Segoe UI", 13, FontStyle::Bold);
            this->lblTitulo->ForeColor = Color::White;
            this->lblTitulo->Dock      = DockStyle::Left;
            this->lblTitulo->Width     = 400;
            this->lblTitulo->TextAlign = ContentAlignment::MiddleLeft;

            this->btnAgregar  = CrearBtnTop(L"+ Agregar",  Color::FromArgb(39, 174, 96),  410, 90);
            this->btnEditar   = CrearBtnTop(L"Editar",     Color::FromArgb(211, 84, 0),   510, 90);
            this->btnEliminar = CrearBtnTop(L"Eliminar",   Color::FromArgb(169, 50, 38),  610, 90);
            this->btnCerrar   = CrearBtnTop(L"Cerrar",     Color::FromArgb(100, 100, 100),780, 90);

            this->btnAgregar->Click  += gcnew EventHandler(this, &FormTorneos::btnAgregar_Click);
            this->btnEditar->Click   += gcnew EventHandler(this, &FormTorneos::btnEditar_Click);
            this->btnEliminar->Click += gcnew EventHandler(this, &FormTorneos::btnEliminar_Click);
            this->btnCerrar->Click   += gcnew EventHandler(this, &FormTorneos::btnCerrar_Click);

            this->panelTop->Controls->Add(this->lblTitulo);
            this->panelTop->Controls->Add(this->btnAgregar);
            this->panelTop->Controls->Add(this->btnEditar);
            this->panelTop->Controls->Add(this->btnEliminar);
            this->panelTop->Controls->Add(this->btnCerrar);

            // DataGridView
            this->dgvTorneos->Location               = Point(10, 65);
            this->dgvTorneos->Size                   = Drawing::Size(560, 480);
            this->dgvTorneos->ReadOnly               = true;
            this->dgvTorneos->AllowUserToAddRows     = false;
            this->dgvTorneos->SelectionMode          = DataGridViewSelectionMode::FullRowSelect;
            this->dgvTorneos->MultiSelect            = false;
            this->dgvTorneos->AutoSizeColumnsMode    = DataGridViewAutoSizeColumnsMode::Fill;
            this->dgvTorneos->BackgroundColor        = Color::White;
            this->dgvTorneos->BorderStyle            = BorderStyle::None;
            this->dgvTorneos->ColumnHeadersDefaultCellStyle->BackColor = Color::FromArgb(26, 82, 118);
            this->dgvTorneos->ColumnHeadersDefaultCellStyle->ForeColor = Color::White;
            this->dgvTorneos->ColumnHeadersDefaultCellStyle->Font = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            this->dgvTorneos->EnableHeadersVisualStyles = false;
            this->dgvTorneos->RowHeadersVisible = false;
            this->dgvTorneos->AlternatingRowsDefaultCellStyle->BackColor = Color::FromArgb(235, 245, 255);
            this->dgvTorneos->CellClick += gcnew DataGridViewCellEventHandler(this, &FormTorneos::dgvTorneos_CellClick);

            this->dgvTorneos->Columns->Add(L"ID",          L"ID");
            this->dgvTorneos->Columns->Add(L"Nombre",      L"Nombre del Torneo");
            this->dgvTorneos->Columns->Add(L"FechaInicio", L"Fecha Inicio");
            this->dgvTorneos->Columns->Add(L"FechaFin",    L"Fecha Fin");
            this->dgvTorneos->Columns->Add(L"Estado",      L"Estado");
            this->dgvTorneos->Columns->Add(L"Formato",     L"Formato");
            this->dgvTorneos->Columns[0]->FillWeight = 30;

            // GroupBox Detalle
            this->grpDetalle->Text      = L"Detalle / Formulario";
            this->grpDetalle->Location  = Point(580, 65);
            this->grpDetalle->Size      = Drawing::Size(305, 480);
            this->grpDetalle->Font      = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            this->grpDetalle->ForeColor = Color::FromArgb(26, 82, 118);

            AgregarCampo(lblNombre,      L"Nombre:",       txtNombre,       25);
            AgregarCampo(lblFechaInicio, L"Fecha Inicio:", dtpFechaInicio, 80);
            AgregarCampo(lblFechaFin,    L"Fecha Fin:",    dtpFechaFin,   135);
            AgregarCampo(lblEstado,      L"Estado:",       cmbEstado,     190);
            AgregarCampo(lblFormato,     L"Formato:",      cmbFormato,    240);

            this->txtNombre->Font = gcnew Drawing::Font(L"Segoe UI", 9);

            this->cmbEstado->Items->Add(L"Activo");
            this->cmbEstado->Items->Add(L"Pendiente");
            this->cmbEstado->Items->Add(L"Finalizado");
            this->cmbEstado->Items->Add(L"Cancelado");
            this->cmbEstado->DropDownStyle = ComboBoxStyle::DropDownList;

            this->cmbFormato->Items->Add(L"Eliminacion directa");
            this->cmbFormato->Items->Add(L"Liga");
            this->cmbFormato->Items->Add(L"Grupos + Eliminatoria");
            this->cmbFormato->DropDownStyle = ComboBoxStyle::DropDownList;

            this->btnGuardar->Text      = L"Guardar";
            this->btnGuardar->Location  = Point(10, 300);
            this->btnGuardar->Size      = Drawing::Size(130, 35);
            this->btnGuardar->BackColor = Color::FromArgb(26, 82, 118);
            this->btnGuardar->ForeColor = Color::White;
            this->btnGuardar->FlatStyle = FlatStyle::Flat;
            this->btnGuardar->FlatAppearance->BorderSize = 0;
            this->btnGuardar->Font      = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            this->btnGuardar->Cursor    = Cursors::Hand;
            this->btnGuardar->Click    += gcnew EventHandler(this, &FormTorneos::btnGuardar_Click);

            this->btnLimpiar->Text      = L"Limpiar";
            this->btnLimpiar->Location  = Point(155, 300);
            this->btnLimpiar->Size      = Drawing::Size(130, 35);
            this->btnLimpiar->BackColor = Color::Gray;
            this->btnLimpiar->ForeColor = Color::White;
            this->btnLimpiar->FlatStyle = FlatStyle::Flat;
            this->btnLimpiar->FlatAppearance->BorderSize = 0;
            this->btnLimpiar->Font      = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            this->btnLimpiar->Cursor    = Cursors::Hand;
            this->btnLimpiar->Click    += gcnew EventHandler(this, &FormTorneos::btnLimpiar_Click);

            this->grpDetalle->Controls->Add(this->btnGuardar);
            this->grpDetalle->Controls->Add(this->btnLimpiar);

            this->Controls->Add(this->panelTop);
            this->Controls->Add(this->dgvTorneos);
            this->Controls->Add(this->grpDetalle);
        }

        void CargarGrilla() {
            dgvTorneos->Rows->Clear();
            for each (Torneo^ t in torneos) {
                dgvTorneos->Rows->Add(
                    t->getIdTorneo(),
                    t->getNombreTorneo(),
                    t->getFechaInicio().ToShortDateString(),
                    t->getFechaFin().ToShortDateString(),
                    t->getEstado(),
                    t->getFormato()
                );
            }
        }

        void LimpiarFormulario() {
            txtNombre->Clear();
            dtpFechaInicio->Value    = DateTime::Now;
            dtpFechaFin->Value       = DateTime::Now.AddMonths(1);
            cmbEstado->SelectedIndex = -1;
            cmbFormato->SelectedIndex = -1;
            torneoSeleccionado = nullptr;
            modoEdicion = false;
        }

    public:
        FormTorneos(System::Collections::Generic::List<Torneo^>^ listaTorneos) {
            torneoSeleccionado = nullptr;
            modoEdicion        = false;
            torneos            = listaTorneos;
            InitializeComponent();
            CargarGrilla();
        }

    private:
        void dgvTorneos_CellClick(Object^ sender, DataGridViewCellEventArgs^ e) {
            if (e->RowIndex < 0 || e->RowIndex >= torneos->Count) return;
            torneoSeleccionado    = torneos[e->RowIndex];
            txtNombre->Text       = torneoSeleccionado->getNombreTorneo();
            dtpFechaInicio->Value = torneoSeleccionado->getFechaInicio();
            dtpFechaFin->Value    = torneoSeleccionado->getFechaFin();
            cmbEstado->Text       = torneoSeleccionado->getEstado();
            cmbFormato->Text      = torneoSeleccionado->getFormato();
        }

        void btnAgregar_Click(Object^ sender, EventArgs^ e) {
            LimpiarFormulario();
            modoEdicion = false;
            txtNombre->Focus();
        }

        void btnEditar_Click(Object^ sender, EventArgs^ e) {
            if (torneoSeleccionado == nullptr) {
                MessageBox::Show(L"Seleccione un torneo para editar.", L"Aviso",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
                return;
            }
            modoEdicion = true;
            txtNombre->Focus();
        }

        void btnEliminar_Click(Object^ sender, EventArgs^ e) {
            if (torneoSeleccionado == nullptr) {
                MessageBox::Show(L"Seleccione un torneo para eliminar.", L"Aviso",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
                return;
            }
            System::Windows::Forms::DialogResult res = MessageBox::Show(
                L"Desea eliminar el torneo: " + torneoSeleccionado->getNombreTorneo() + L"?",
                L"Confirmar eliminacion", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
            if (res == System::Windows::Forms::DialogResult::Yes) {
                torneos->Remove(torneoSeleccionado);
                LimpiarFormulario();
                CargarGrilla();
            }
        }

        void btnGuardar_Click(Object^ sender, EventArgs^ e) {
            if (String::IsNullOrWhiteSpace(txtNombre->Text)) {
                MessageBox::Show(L"El nombre del torneo es obligatorio.", L"Validacion",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            if (cmbEstado->SelectedIndex < 0 || cmbFormato->SelectedIndex < 0) {
                MessageBox::Show(L"Seleccione el estado y el formato.", L"Validacion",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            if (modoEdicion && torneoSeleccionado != nullptr) {
                torneoSeleccionado->setNombreTorneo(txtNombre->Text);
                torneoSeleccionado->setFechaInicio(dtpFechaInicio->Value);
                torneoSeleccionado->setFechaFin(dtpFechaFin->Value);
                torneoSeleccionado->setEstado(cmbEstado->Text);
                torneoSeleccionado->setFormato(cmbFormato->Text);
                MessageBox::Show(L"Torneo actualizado correctamente.", L"Exito",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
            } else {
                int nuevoId = torneos->Count + 1;
                Torneo^ nuevo = gcnew Torneo(nuevoId, txtNombre->Text,
                    dtpFechaInicio->Value, dtpFechaFin->Value,
                    cmbEstado->Text, cmbFormato->Text);
                torneos->Add(nuevo);
                MessageBox::Show(L"Torneo agregado correctamente.", L"Exito",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            LimpiarFormulario();
            CargarGrilla();
        }

        void btnLimpiar_Click(Object^ sender, EventArgs^ e) { LimpiarFormulario(); }
        void btnCerrar_Click(Object^ sender, EventArgs^ e)  { this->Close(); }
    };
}

