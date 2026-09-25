#pragma once

namespace GestionTorneosView {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace GestionTorneosModel;

    public ref class FormEquipos : public Form {
    private:
        Panel^       panelTop;
        Label^       lblTitulo;
        Button^      btnAgregar;
        Button^      btnEditar;
        Button^      btnEliminar;
        Button^      btnCerrar;
        DataGridView^ dgvEquipos;
        GroupBox^    grpDetalle;

        Label^   lblNombre;
        TextBox^ txtNombre;
        Label^   lblFacultad;
        TextBox^ txtFacultad;
        Button^  btnGuardar;
        Button^  btnLimpiar;

        System::Collections::Generic::List<Equipo^>^ equipos;
        Equipo^ equipoSeleccionado;
        bool modoEdicion;

        Button^ CrearBtnTop(String^ txt, Color col, int x) {
            Button^ b = gcnew Button();
            b->Text      = txt;
            b->BackColor = col;
            b->ForeColor = Color::White;
            b->FlatStyle = FlatStyle::Flat;
            b->FlatAppearance->BorderSize = 0;
            b->Font      = gcnew Drawing::Font(L"Segoe UI", 8, FontStyle::Bold);
            b->Size      = Drawing::Size(90, 30);
            b->Location  = Point(x, 12);
            b->Cursor    = Cursors::Hand;
            return b;
        }

        void InitializeComponent() {
            this->panelTop    = gcnew Panel();
            this->lblTitulo   = gcnew Label();
            this->dgvEquipos  = gcnew DataGridView();
            this->grpDetalle  = gcnew GroupBox();
            this->lblNombre   = gcnew Label();
            this->txtNombre   = gcnew TextBox();
            this->lblFacultad = gcnew Label();
            this->txtFacultad = gcnew TextBox();
            this->btnGuardar  = gcnew Button();
            this->btnLimpiar  = gcnew Button();

            this->Text          = L"Gestion de Equipos";
            this->Size          = Drawing::Size(800, 500);
            this->StartPosition = FormStartPosition::CenterParent;
            this->BackColor     = Color::FromArgb(245, 247, 250);
            this->MinimizeBox   = false;

            // Panel Top
            this->panelTop->Dock      = DockStyle::Top;
            this->panelTop->Height    = 55;
            this->panelTop->BackColor = Color::FromArgb(22, 160, 133);

            this->lblTitulo->Text      = L"  Gestion de Equipos";
            this->lblTitulo->Font      = gcnew Drawing::Font(L"Segoe UI", 13, FontStyle::Bold);
            this->lblTitulo->ForeColor = Color::White;
            this->lblTitulo->Dock      = DockStyle::Left;
            this->lblTitulo->Width     = 400;
            this->lblTitulo->TextAlign = ContentAlignment::MiddleLeft;

            this->btnAgregar  = CrearBtnTop(L"+ Agregar",  Color::FromArgb(39, 174, 96),  410);
            this->btnEditar   = CrearBtnTop(L"Editar",     Color::FromArgb(211, 84, 0),   510);
            this->btnEliminar = CrearBtnTop(L"Eliminar",   Color::FromArgb(169, 50, 38),  610);
            this->btnCerrar   = CrearBtnTop(L"Cerrar",     Color::FromArgb(80, 80, 80),   700);

            this->btnAgregar->Click  += gcnew EventHandler(this, &FormEquipos::btnAgregar_Click);
            this->btnEditar->Click   += gcnew EventHandler(this, &FormEquipos::btnEditar_Click);
            this->btnEliminar->Click += gcnew EventHandler(this, &FormEquipos::btnEliminar_Click);
            this->btnCerrar->Click   += gcnew EventHandler(this, &FormEquipos::btnCerrar_Click);

            this->panelTop->Controls->Add(lblTitulo);
            this->panelTop->Controls->Add(btnAgregar);
            this->panelTop->Controls->Add(btnEditar);
            this->panelTop->Controls->Add(btnEliminar);
            this->panelTop->Controls->Add(btnCerrar);

            // DataGridView
            this->dgvEquipos->Location            = Point(10, 65);
            this->dgvEquipos->Size                = Drawing::Size(500, 400);
            this->dgvEquipos->ReadOnly            = true;
            this->dgvEquipos->AllowUserToAddRows  = false;
            this->dgvEquipos->SelectionMode       = DataGridViewSelectionMode::FullRowSelect;
            this->dgvEquipos->MultiSelect         = false;
            this->dgvEquipos->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            this->dgvEquipos->BackgroundColor     = Color::White;
            this->dgvEquipos->BorderStyle         = BorderStyle::None;
            this->dgvEquipos->ColumnHeadersDefaultCellStyle->BackColor = Color::FromArgb(22, 160, 133);
            this->dgvEquipos->ColumnHeadersDefaultCellStyle->ForeColor = Color::White;
            this->dgvEquipos->ColumnHeadersDefaultCellStyle->Font = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            this->dgvEquipos->EnableHeadersVisualStyles = false;
            this->dgvEquipos->RowHeadersVisible = false;
            this->dgvEquipos->AlternatingRowsDefaultCellStyle->BackColor = Color::FromArgb(225, 245, 240);
            this->dgvEquipos->CellClick += gcnew DataGridViewCellEventHandler(this, &FormEquipos::dgvEquipos_CellClick);

            this->dgvEquipos->Columns->Add(L"ID",       L"ID");
            this->dgvEquipos->Columns->Add(L"Nombre",   L"Nombre del Equipo");
            this->dgvEquipos->Columns->Add(L"Facultad", L"Facultad");
            this->dgvEquipos->Columns[0]->FillWeight = 25;

            // GroupBox Detalle
            this->grpDetalle->Text      = L"Detalle del Equipo";
            this->grpDetalle->Location  = Point(520, 65);
            this->grpDetalle->Size      = Drawing::Size(265, 200);
            this->grpDetalle->Font      = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            this->grpDetalle->ForeColor = Color::FromArgb(22, 160, 133);

            lblNombre->Text     = L"Nombre:";
            lblNombre->Font     = gcnew Drawing::Font(L"Segoe UI", 8, FontStyle::Bold);
            lblNombre->Location = Point(10, 25);
            lblNombre->AutoSize = true;
            txtNombre->Location = Point(10, 43);
            txtNombre->Width    = 240;
            txtNombre->Font     = gcnew Drawing::Font(L"Segoe UI", 9);

            lblFacultad->Text     = L"Facultad:";
            lblFacultad->Font     = gcnew Drawing::Font(L"Segoe UI", 8, FontStyle::Bold);
            lblFacultad->Location = Point(10, 75);
            lblFacultad->AutoSize = true;
            txtFacultad->Location = Point(10, 93);
            txtFacultad->Width    = 240;
            txtFacultad->Font     = gcnew Drawing::Font(L"Segoe UI", 9);

            btnGuardar->Text      = L"Guardar";
            btnGuardar->Location  = Point(10, 140);
            btnGuardar->Size      = Drawing::Size(110, 35);
            btnGuardar->BackColor = Color::FromArgb(22, 160, 133);
            btnGuardar->ForeColor = Color::White;
            btnGuardar->FlatStyle = FlatStyle::Flat;
            btnGuardar->FlatAppearance->BorderSize = 0;
            btnGuardar->Font      = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            btnGuardar->Cursor    = Cursors::Hand;
            btnGuardar->Click    += gcnew EventHandler(this, &FormEquipos::btnGuardar_Click);

            btnLimpiar->Text      = L"Limpiar";
            btnLimpiar->Location  = Point(135, 140);
            btnLimpiar->Size      = Drawing::Size(110, 35);
            btnLimpiar->BackColor = Color::Gray;
            btnLimpiar->ForeColor = Color::White;
            btnLimpiar->FlatStyle = FlatStyle::Flat;
            btnLimpiar->FlatAppearance->BorderSize = 0;
            btnLimpiar->Font      = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            btnLimpiar->Cursor    = Cursors::Hand;
            btnLimpiar->Click    += gcnew EventHandler(this, &FormEquipos::btnLimpiar_Click);

            grpDetalle->Controls->Add(lblNombre);
            grpDetalle->Controls->Add(txtNombre);
            grpDetalle->Controls->Add(lblFacultad);
            grpDetalle->Controls->Add(txtFacultad);
            grpDetalle->Controls->Add(btnGuardar);
            grpDetalle->Controls->Add(btnLimpiar);

            this->Controls->Add(panelTop);
            this->Controls->Add(dgvEquipos);
            this->Controls->Add(grpDetalle);
        }

        void CargarGrilla() {
            dgvEquipos->Rows->Clear();
            for each (Equipo^ eq in equipos) {
                dgvEquipos->Rows->Add(eq->getIdEquipo(), eq->getNombreEquipo(), eq->getFacultad());
            }
        }

        void LimpiarFormulario() {
            txtNombre->Clear();
            txtFacultad->Clear();
            equipoSeleccionado = nullptr;
            modoEdicion = false;
        }

    public:
        FormEquipos(System::Collections::Generic::List<Equipo^>^ listaEquipos) {
            equipoSeleccionado = nullptr;
            modoEdicion        = false;
            equipos            = listaEquipos;
            InitializeComponent();
            CargarGrilla();
        }

    private:
        void dgvEquipos_CellClick(Object^ sender, DataGridViewCellEventArgs^ e) {
            if (e->RowIndex < 0 || e->RowIndex >= equipos->Count) return;
            equipoSeleccionado = equipos[e->RowIndex];
            txtNombre->Text    = equipoSeleccionado->getNombreEquipo();
            txtFacultad->Text  = equipoSeleccionado->getFacultad();
        }

        void btnAgregar_Click(Object^ sender, EventArgs^ e) {
            LimpiarFormulario();
            txtNombre->Focus();
        }

        void btnEditar_Click(Object^ sender, EventArgs^ e) {
            if (equipoSeleccionado == nullptr) {
                MessageBox::Show(L"Seleccione un equipo.", L"Aviso",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
                return;
            }
            modoEdicion = true;
            txtNombre->Focus();
        }

        void btnEliminar_Click(Object^ sender, EventArgs^ e) {
            if (equipoSeleccionado == nullptr) {
                MessageBox::Show(L"Seleccione un equipo.", L"Aviso",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
                return;
            }
            System::Windows::Forms::DialogResult res = MessageBox::Show(
                L"Eliminar equipo: " + equipoSeleccionado->getNombreEquipo() + L"?",
                L"Confirmar", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
            if (res == System::Windows::Forms::DialogResult::Yes) {
                equipos->Remove(equipoSeleccionado);
                LimpiarFormulario();
                CargarGrilla();
            }
        }

        void btnGuardar_Click(Object^ sender, EventArgs^ e) {
            if (String::IsNullOrWhiteSpace(txtNombre->Text) || String::IsNullOrWhiteSpace(txtFacultad->Text)) {
                MessageBox::Show(L"Complete todos los campos.", L"Validacion",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            if (modoEdicion && equipoSeleccionado != nullptr) {
                equipoSeleccionado->setNombreEquipo(txtNombre->Text);
                equipoSeleccionado->setFacultad(txtFacultad->Text);
                MessageBox::Show(L"Equipo actualizado.", L"Exito",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
            } else {
                int id = equipos->Count + 1;
                equipos->Add(gcnew Equipo(id, txtNombre->Text, txtFacultad->Text));
                MessageBox::Show(L"Equipo agregado.", L"Exito",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            LimpiarFormulario();
            CargarGrilla();
        }

        void btnLimpiar_Click(Object^ sender, EventArgs^ e) { LimpiarFormulario(); }
        void btnCerrar_Click(Object^ sender, EventArgs^ e)  { this->Close(); }
    };
}

