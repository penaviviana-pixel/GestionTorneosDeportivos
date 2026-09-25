#pragma once

namespace GestionTorneosView {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace GestionTorneosModel;

    // Clase auxiliar para fila de tabla de posiciones (para poder ordenar)
    ref class FilaTabla {
    public:
        String^ Equipo;
        int PJ, PG, PE, PP, GF, GC, DIF, PTS;
        FilaTabla(String^ eq, int pj, int pg, int pe, int pp, int gf, int gc, int dif, int pts)
            : Equipo(eq), PJ(pj), PG(pg), PE(pe), PP(pp), GF(gf), GC(gc), DIF(dif), PTS(pts) {}
    };

    ref class ComparadorFilas : public System::Collections::Generic::IComparer<FilaTabla^> {
    public:
        virtual int Compare(FilaTabla^ a, FilaTabla^ b) {
            if (b->PTS != a->PTS) return b->PTS.CompareTo(a->PTS);
            if (b->DIF != a->DIF) return b->DIF.CompareTo(a->DIF);
            return b->GF.CompareTo(a->GF);
        }
    };

    public ref class FormTablaPosiciones : public Form {
    private:
        Panel^       panelTop;
        Label^       lblTitulo;
        Button^      btnActualizar;
        Button^      btnCerrar;
        Label^       lblSelTorneo;
        ComboBox^    cmbTorneo;
        DataGridView^ dgvTabla;
        Label^       lblFechaAct;

        System::Collections::Generic::List<Torneo^>^  torneos;
        System::Collections::Generic::List<Equipo^>^  equipos;
        System::Collections::Generic::List<Partido^>^ partidos;
        TablaPosiciones^ tabla;

        void InitializeComponent() {
            this->panelTop      = gcnew Panel();
            this->lblTitulo     = gcnew Label();
            this->btnActualizar = gcnew Button();
            this->btnCerrar     = gcnew Button();
            this->lblSelTorneo  = gcnew Label();
            this->cmbTorneo     = gcnew ComboBox();
            this->dgvTabla      = gcnew DataGridView();
            this->lblFechaAct   = gcnew Label();

            this->Text          = L"Tabla de Posiciones";
            this->Size          = Drawing::Size(750, 550);
            this->StartPosition = FormStartPosition::CenterParent;
            this->BackColor     = Color::FromArgb(245, 247, 250);
            this->MinimizeBox   = false;

            // Panel Top
            panelTop->Dock      = DockStyle::Top;
            panelTop->Height    = 55;
            panelTop->BackColor = Color::FromArgb(22, 160, 133);

            lblTitulo->Text      = L"  Tabla de Posiciones";
            lblTitulo->Font      = gcnew Drawing::Font(L"Segoe UI", 13, FontStyle::Bold);
            lblTitulo->ForeColor = Color::White;
            lblTitulo->Dock      = DockStyle::Left;
            lblTitulo->Width     = 350;
            lblTitulo->TextAlign = ContentAlignment::MiddleLeft;

            btnActualizar->Text      = L"Actualizar";
            btnActualizar->BackColor = Color::FromArgb(39, 174, 96);
            btnActualizar->ForeColor = Color::White;
            btnActualizar->FlatStyle = FlatStyle::Flat;
            btnActualizar->FlatAppearance->BorderSize = 0;
            btnActualizar->Font      = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            btnActualizar->Size      = Drawing::Size(100, 30);
            btnActualizar->Location  = Point(555, 12);
            btnActualizar->Cursor    = Cursors::Hand;
            btnActualizar->Click    += gcnew EventHandler(this, &FormTablaPosiciones::btnActualizar_Click);

            btnCerrar->Text      = L"Cerrar";
            btnCerrar->BackColor = Color::FromArgb(80, 80, 80);
            btnCerrar->ForeColor = Color::White;
            btnCerrar->FlatStyle = FlatStyle::Flat;
            btnCerrar->FlatAppearance->BorderSize = 0;
            btnCerrar->Font      = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            btnCerrar->Size      = Drawing::Size(80, 30);
            btnCerrar->Location  = Point(660, 12);
            btnCerrar->Cursor    = Cursors::Hand;
            btnCerrar->Click    += gcnew EventHandler(this, &FormTablaPosiciones::btnCerrar_Click);

            panelTop->Controls->Add(lblTitulo);
            panelTop->Controls->Add(btnActualizar);
            panelTop->Controls->Add(btnCerrar);

            lblSelTorneo->Text     = L"Seleccionar Torneo:";
            lblSelTorneo->Font     = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            lblSelTorneo->Location = Point(15, 68);
            lblSelTorneo->AutoSize = true;

            cmbTorneo->Location      = Point(170, 65);
            cmbTorneo->Width         = 350;
            cmbTorneo->DropDownStyle = ComboBoxStyle::DropDownList;
            cmbTorneo->Font          = gcnew Drawing::Font(L"Segoe UI", 9);
            cmbTorneo->SelectedIndexChanged += gcnew EventHandler(this, &FormTablaPosiciones::cmbTorneo_SelectedIndexChanged);

            lblFechaAct->Text      = L"";
            lblFechaAct->Location  = Point(15, 95);
            lblFechaAct->AutoSize  = true;
            lblFechaAct->Font      = gcnew Drawing::Font(L"Segoe UI", 8, FontStyle::Italic);
            lblFechaAct->ForeColor = Color::Gray;

            // DataGridView
            dgvTabla->Location            = Point(15, 115);
            dgvTabla->Size                = Drawing::Size(710, 390);
            dgvTabla->ReadOnly            = true;
            dgvTabla->AllowUserToAddRows  = false;
            dgvTabla->SelectionMode       = DataGridViewSelectionMode::FullRowSelect;
            dgvTabla->MultiSelect         = false;
            dgvTabla->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            dgvTabla->BackgroundColor     = Color::White;
            dgvTabla->BorderStyle         = BorderStyle::None;
            dgvTabla->ColumnHeadersDefaultCellStyle->BackColor = Color::FromArgb(22, 160, 133);
            dgvTabla->ColumnHeadersDefaultCellStyle->ForeColor = Color::White;
            dgvTabla->ColumnHeadersDefaultCellStyle->Font = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            dgvTabla->EnableHeadersVisualStyles = false;
            dgvTabla->RowHeadersVisible = false;
            dgvTabla->AlternatingRowsDefaultCellStyle->BackColor = Color::FromArgb(225, 245, 240);

            dgvTabla->Columns->Add(L"Pos",    L"#");
            dgvTabla->Columns->Add(L"Equipo", L"Equipo");
            dgvTabla->Columns->Add(L"PJ",     L"PJ");
            dgvTabla->Columns->Add(L"PG",     L"PG");
            dgvTabla->Columns->Add(L"PE",     L"PE");
            dgvTabla->Columns->Add(L"PP",     L"PP");
            dgvTabla->Columns->Add(L"GF",     L"GF");
            dgvTabla->Columns->Add(L"GC",     L"GC");
            dgvTabla->Columns->Add(L"DIF",    L"DIF");
            dgvTabla->Columns->Add(L"PTS",    L"PTS");

            dgvTabla->Columns[0]->FillWeight = 25;
            dgvTabla->Columns[1]->FillWeight = 120;
            for (int i = 2; i <= 9; i++) dgvTabla->Columns[i]->FillWeight = 35;
            dgvTabla->Columns[9]->DefaultCellStyle->Font      = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            dgvTabla->Columns[9]->DefaultCellStyle->ForeColor = Color::FromArgb(22, 160, 133);

            this->Controls->Add(panelTop);
            this->Controls->Add(lblSelTorneo);
            this->Controls->Add(cmbTorneo);
            this->Controls->Add(lblFechaAct);
            this->Controls->Add(dgvTabla);
        }

        void CargarCombos() {
            cmbTorneo->Items->Clear();
            for each (Torneo^ t in torneos) cmbTorneo->Items->Add(t->getNombreTorneo());
        }

        void GenerarTabla(Torneo^ torneo) {
            dgvTabla->Rows->Clear();
            if (torneo == nullptr) return;

            auto dictEquipos = gcnew System::Collections::Generic::Dictionary<int, array<int>^>();
            for each (Equipo^ eq in equipos) {
                dictEquipos[eq->getIdEquipo()] = gcnew array<int>(6) { 0, 0, 0, 0, 0, 0 };
            }

            for each (Partido^ p in partidos) {
                if (p->getEstadoPartido() != L"Finalizado") continue;
                Equipo^ local     = p->getEquipoLocal();
                Equipo^ visitante = p->getEquipoVisitante();
                if (local == nullptr || visitante == nullptr) continue;

                int gl = p->getMarcadorLocal();
                int gv = p->getMarcadorVisitante();

                if (dictEquipos->ContainsKey(local->getIdEquipo())) {
                    auto d = dictEquipos[local->getIdEquipo()];
                    d[0]++; d[4] += gl; d[5] += gv;
                    if (gl > gv) d[1]++; else if (gl == gv) d[2]++; else d[3]++;
                }
                if (dictEquipos->ContainsKey(visitante->getIdEquipo())) {
                    auto d = dictEquipos[visitante->getIdEquipo()];
                    d[0]++; d[4] += gv; d[5] += gl;
                    if (gv > gl) d[1]++; else if (gv == gl) d[2]++; else d[3]++;
                }
            }

            auto filas = gcnew System::Collections::Generic::List<FilaTabla^>();
            for each (Equipo^ eq in equipos) {
                if (!dictEquipos->ContainsKey(eq->getIdEquipo())) continue;
                auto d   = dictEquipos[eq->getIdEquipo()];
                int pts  = d[1] * 3 + d[2];
                int dif  = d[4] - d[5];
                filas->Add(gcnew FilaTabla(eq->getNombreEquipo(), d[0], d[1], d[2], d[3], d[4], d[5], dif, pts));
            }

            filas->Sort(gcnew ComparadorFilas());

            int pos = 1;
            for each (FilaTabla^ f in filas) {
                dgvTabla->Rows->Add(pos++, f->Equipo, f->PJ, f->PG, f->PE, f->PP, f->GF, f->GC, f->DIF, f->PTS);
            }
            lblFechaAct->Text = L"Ultima actualizacion: " + DateTime::Now.ToString(L"dd/MM/yyyy HH:mm");
        }

    public:
        FormTablaPosiciones(System::Collections::Generic::List<Torneo^>^  listaTorneos,
                            System::Collections::Generic::List<Equipo^>^  listaEquipos,
                            System::Collections::Generic::List<Partido^>^ listaPartidos) {
            torneos  = listaTorneos;
            equipos  = listaEquipos;
            partidos = listaPartidos;
            tabla    = gcnew TablaPosiciones(1, DateTime::Now.ToShortDateString());
            InitializeComponent();
            CargarCombos();
            if (torneos->Count > 0) {
                cmbTorneo->SelectedIndex = 0;
                GenerarTabla(torneos[0]);
            }
        }

    private:
        void cmbTorneo_SelectedIndexChanged(Object^ sender, EventArgs^ e) {
            if (cmbTorneo->SelectedIndex >= 0 && cmbTorneo->SelectedIndex < torneos->Count)
                GenerarTabla(torneos[cmbTorneo->SelectedIndex]);
        }

        void btnActualizar_Click(Object^ sender, EventArgs^ e) {
            if (cmbTorneo->SelectedIndex >= 0 && cmbTorneo->SelectedIndex < torneos->Count)
                GenerarTabla(torneos[cmbTorneo->SelectedIndex]);
        }

        void btnCerrar_Click(Object^ sender, EventArgs^ e) { this->Close(); }
    };
}

