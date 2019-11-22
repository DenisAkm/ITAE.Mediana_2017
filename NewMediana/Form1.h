#pragma once

namespace NewMediana {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::IO;
	using namespace System::Runtime::InteropServices;	

	ref class Form1;
	ref class Form2;
	ref class Form3;
	ref class Form4;
	ref class Form6;
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	protected:



	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ôàéëToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  çàãğóçèòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  íàñòğîéêèToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  âûõîäToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ğåäàêòîğToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  îòêğûòüToolStripMenuItem;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::ToolStripMenuItem^	toolStripMenuItem1;
	private: System::Windows::Forms::Label^  label5;

	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown4;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown5;


	private: System::Windows::Forms::ToolStripMenuItem^  ãğàôèêToolStripMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^  ïîñòğîèòüToolStripMenuItem;
	public: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::ToolStripMenuItem^  î÷èñòèòüÑïèñîêToolStripMenuItem;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ToolStripMenuItem^  âêëş÷èòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  âûêëş÷èòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::ToolStripMenuItem^  ñöåíàğèéÂûâîäàÄàííûõToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ïàğàìåòğûĞàñ÷åòàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ïîìîùüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  îÏğîãğàììåToolStripMenuItem;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint1 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(3,
				10));
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint2 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(4,
				12));
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint3 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(5,
				11));
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint4 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(6,
				16));
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ôàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->î÷èñòèòüÑïèñîêToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->çàãğóçèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->íàñòğîéêèToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ñöåíàğèéÂûâîäàÄàííûõToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ğåäàêòîğToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îòêğûòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ãğàôèêToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîñòğîèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîìîùüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îÏğîãğàììåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->BeginInit();
			this->tableLayoutPanel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->tableLayoutPanel4->SuspendLayout();
			this->SuspendLayout();
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->ôàéëToolStripMenuItem,
					this->ğåäàêòîğToolStripMenuItem, this->ãğàôèêToolStripMenuItem, this->ïîìîùüToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->menuStrip1->Size = System::Drawing::Size(1131, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			this->ôàéëToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->î÷èñòèòüÑïèñîêToolStripMenuItem,
					this->çàãğóçèòüToolStripMenuItem, this->íàñòğîéêèToolStripMenuItem, this->âûõîäToolStripMenuItem
			});
			this->ôàéëToolStripMenuItem->Name = L"ôàéëToolStripMenuItem";
			this->ôàéëToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->ôàéëToolStripMenuItem->Text = L"Ôàéë";
			this->î÷èñòèòüÑïèñîêToolStripMenuItem->Name = L"î÷èñòèòüÑïèñîêToolStripMenuItem";
			this->î÷èñòèòüÑïèñîêToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->î÷èñòèòüÑïèñîêToolStripMenuItem->Text = L"Î÷èñòèòü ñïèñîê";
			this->î÷èñòèòüÑïèñîêToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::î÷èñòèòüÑïèñîêToolStripMenuItem_Click);
			this->çàãğóçèòüToolStripMenuItem->Name = L"çàãğóçèòüToolStripMenuItem";
			this->çàãğóçèòüToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->çàãğóçèòüToolStripMenuItem->Text = L"Âûáğàòü ôàéëû";
			this->çàãğóçèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::çàãğóçèòüToolStripMenuItem_Click);
			this->íàñòğîéêèToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ñöåíàğèéÂûâîäàÄàííûõToolStripMenuItem,
					this->toolStripMenuItem1
			});
			this->íàñòğîéêèToolStripMenuItem->Name = L"íàñòğîéêèToolStripMenuItem";
			this->íàñòğîéêèToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->íàñòğîéêèToolStripMenuItem->Text = L"Íàñòğîéêè";
			this->íàñòğîéêèToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::íàñòğîéêèToolStripMenuItem_Click);
			this->ñöåíàğèéÂûâîäàÄàííûõToolStripMenuItem->Name = L"ñöåíàğèéÂûâîäàÄàííûõToolStripMenuItem";
			this->ñöåíàğèéÂûâîäàÄàííûõToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->ñöåíàğèéÂûâîäàÄàííûõToolStripMenuItem->Text = L"Âûáîğ ñöåíàğèÿ";
			this->ñöåíàğèéÂûâîäàÄàííûõToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::ñöåíàğèéÂûâîäàÄàííûõToolStripMenuItem_Click);
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(166, 22);
			this->toolStripMenuItem1->Text = L"Ïàğàìåòğû";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem1_Click);
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			this->âûõîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::âûõîäToolStripMenuItem_Click);
			this->ğåäàêòîğToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->îòêğûòüToolStripMenuItem });
			this->ğåäàêòîğToolStripMenuItem->Name = L"ğåäàêòîğToolStripMenuItem";
			this->ğåäàêòîğToolStripMenuItem->Size = System::Drawing::Size(69, 20);
			this->ğåäàêòîğToolStripMenuItem->Text = L"Ğåäàêòîğ";
			this->îòêğûòüToolStripMenuItem->Name = L"îòêğûòüToolStripMenuItem";
			this->îòêğûòüToolStripMenuItem->Size = System::Drawing::Size(121, 22);
			this->îòêğûòüToolStripMenuItem->Text = L"Îòêğûòü";
			this->îòêğûòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::îòêğûòüToolStripMenuItem_Click);
			this->ãğàôèêToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ïîñòğîèòüToolStripMenuItem });
			this->ãğàôèêToolStripMenuItem->Name = L"ãğàôèêToolStripMenuItem";
			this->ãğàôèêToolStripMenuItem->Size = System::Drawing::Size(60, 20);
			this->ãğàôèêToolStripMenuItem->Text = L"Ãğàôèê";
			this->ïîñòğîèòüToolStripMenuItem->CheckOnClick = true;
			this->ïîñòğîèòüToolStripMenuItem->Name = L"ïîñòğîèòüToolStripMenuItem";
			this->ïîñòğîèòüToolStripMenuItem->Size = System::Drawing::Size(133, 22);
			this->ïîñòğîèòüToolStripMenuItem->Text = L"Ïîñòğîèòü";
			this->ïîñòğîèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::ïîñòğîèòüToolStripMenuItem_Click);
			this->ïîìîùüToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->îÏğîãğàììåToolStripMenuItem });
			this->ïîìîùüToolStripMenuItem->Name = L"ïîìîùüToolStripMenuItem";
			this->ïîìîùüToolStripMenuItem->Size = System::Drawing::Size(68, 20);
			this->ïîìîùüToolStripMenuItem->Text = L"Ïîìîùü";
			this->îÏğîãğàììåToolStripMenuItem->Name = L"îÏğîãğàììåToolStripMenuItem";
			this->îÏğîãğàììåToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->îÏğîãğàììåToolStripMenuItem->Text = L"Î ïğîãğàììå";
			this->îÏğîãğàììåToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::îÏğîãğàììåToolStripMenuItem_Click);
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				29.93197)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				70.06802)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				808)));
			this->tableLayoutPanel1->Controls->Add(this->trackBar2, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->numericUpDown1, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->numericUpDown2, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->trackBar1, 2, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 601);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(956, 66);
			this->tableLayoutPanel1->TabIndex = 4;
			this->trackBar2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->trackBar2->LargeChange = 3;
			this->trackBar2->Location = System::Drawing::Point(150, 36);
			this->trackBar2->Maximum = 1800;
			this->trackBar2->Minimum = -1800;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(803, 27);
			this->trackBar2->TabIndex = 0;
			this->trackBar2->TabStop = false;
			this->trackBar2->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar2->ValueChanged += gcnew System::EventHandler(this, &Form1::value_change2);
			this->trackBar2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::RemoveValue);
			this->trackBar2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::RefreshValue);
			this->label2->AutoSize = true;
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(3, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 33);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Äî:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 33);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Îò:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->numericUpDown1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->numericUpDown1->DecimalPlaces = 1;
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->numericUpDown1->Location = System::Drawing::Point(56, 3);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, System::Int32::MinValue });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(79, 26);
			this->numericUpDown1->TabIndex = 2;
			this->numericUpDown1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown1_ValueChanged);
			this->numericUpDown1->Enter += gcnew System::EventHandler(this, &Form1::answer);
			this->numericUpDown1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::RemoveValue);
			this->numericUpDown1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::RefreshValue);
			this->numericUpDown2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->numericUpDown2->DecimalPlaces = 1;
			this->numericUpDown2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown2->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->numericUpDown2->Location = System::Drawing::Point(56, 36);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, 0 });
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, System::Int32::MinValue });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(79, 26);
			this->numericUpDown2->TabIndex = 3;
			this->numericUpDown2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown2_ValueChanged);
			this->numericUpDown2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::RemoveValue);
			this->numericUpDown2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::RefreshValue);
			this->trackBar1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->trackBar1->LargeChange = 1;
			this->trackBar1->Location = System::Drawing::Point(150, 3);
			this->trackBar1->Maximum = 1800;
			this->trackBar1->Minimum = -1800;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(803, 27);
			this->trackBar1->TabIndex = 0;
			this->trackBar1->TabStop = false;
			this->trackBar1->Tag = L"0";
			this->trackBar1->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &Form1::value_change);
			this->trackBar1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::RemoveValue);
			this->trackBar1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::RefreshValue);
			this->numericUpDown3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown3->DecimalPlaces = 1;
			this->numericUpDown3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown3->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDown3->Location = System::Drawing::Point(3, 146);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 180, 0, 0, 0 });
			this->numericUpDown3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(104, 24);
			this->numericUpDown3->TabIndex = 3;
			this->numericUpDown3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->numericUpDown3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown3->ValueChanged += gcnew System::EventHandler(this, &Form1::SectorChanged);
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(3, 209);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(104, 16);
			this->label4->TabIndex = 11;
			this->label4->Text = L"X:";
			this->label4->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->numericUpDown4->Dock = System::Windows::Forms::DockStyle::Top;
			this->numericUpDown4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown4->Location = System::Drawing::Point(3, 228);
			this->numericUpDown4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown4->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(104, 24);
			this->numericUpDown4->TabIndex = 4;
			this->numericUpDown4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->numericUpDown4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown4->ValueChanged += gcnew System::EventHandler(this, &Form1::xCol_change);
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(3, 261);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(104, 16);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Y:";
			this->label5->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->numericUpDown5->Dock = System::Windows::Forms::DockStyle::Top;
			this->numericUpDown5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown5->Location = System::Drawing::Point(3, 280);
			this->numericUpDown5->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown5->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown5->Name = L"numericUpDown5";
			this->numericUpDown5->Size = System::Drawing::Size(104, 24);
			this->numericUpDown5->TabIndex = 5;
			this->numericUpDown5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->numericUpDown5->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDown5->ValueChanged += gcnew System::EventHandler(this, &Form1::yCol_changed);
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->HorizontalScrollbar = true;
			this->listBox1->ItemHeight = 15;
			this->listBox1->Location = System::Drawing::Point(12, 37);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(1107, 139);
			this->listBox1->TabIndex = 7;
			this->listBox1->TabStop = false;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::IndexChanged);
			this->listBox1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::double_click);
			this->listBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::deleteItem);
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->chart1, 0, 0);
			this->tableLayoutPanel3->Location = System::Drawing::Point(12, 185);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(981, 413);
			this->tableLayoutPanel3->TabIndex = 8;
			this->chart1->BackColor = System::Drawing::SystemColors::Control;
			chartArea1->AxisY->IsStartedFromZero = false;
			chartArea1->InnerPlotPosition->Auto = false;
			chartArea1->InnerPlotPosition->Height = 88.4641;
			chartArea1->InnerPlotPosition->Width = 93.34964;
			chartArea1->InnerPlotPosition->X = 5.53333;
			chartArea1->InnerPlotPosition->Y = 2.79255;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Enabled = false;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(3, 3);
			this->chart1->Name = L"chart1";
			series1->BorderWidth = 2;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Color = System::Drawing::Color::Transparent;
			series1->LabelBackColor = System::Drawing::Color::Transparent;
			series1->LabelBorderColor = System::Drawing::Color::Transparent;
			series1->Legend = L"Legend1";
			series1->MarkerSize = 2;
			series1->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			series1->Name = L"Series1";
			dataPoint1->Color = System::Drawing::Color::Black;
			series1->Points->Add(dataPoint1);
			series1->Points->Add(dataPoint2);
			series1->Points->Add(dataPoint3);
			series1->Points->Add(dataPoint4);
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(975, 407);
			this->chart1->TabIndex = 0;
			this->chart1->TabStop = false;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &Form1::chart1_Click);
			this->chart1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Coordinata);
			this->tableLayoutPanel4->ColumnCount = 1;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel4->Controls->Add(this->numericUpDown5, 0, 7);
			this->tableLayoutPanel4->Controls->Add(this->numericUpDown4, 0, 5);
			this->tableLayoutPanel4->Controls->Add(this->label4, 0, 4);
			this->tableLayoutPanel4->Controls->Add(this->numericUpDown3, 0, 3);
			this->tableLayoutPanel4->Controls->Add(this->label3, 0, 2);
			this->tableLayoutPanel4->Controls->Add(this->label5, 0, 6);
			this->tableLayoutPanel4->Controls->Add(this->button1, 0, 8);
			this->tableLayoutPanel4->Controls->Add(this->checkBox2, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->checkBox1, 0, 0);
			this->tableLayoutPanel4->Location = System::Drawing::Point(996, 185);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 9;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 49)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 44)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 52)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 29)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 23)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 93)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(110, 482);
			this->tableLayoutPanel4->TabIndex = 9;
			this->label3->AutoSize = true;
			this->label3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(3, 127);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(104, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Ñåêòîğ:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(3, 394);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 63);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Ğàñ÷åò";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			this->checkBox2->AutoSize = true;
			this->checkBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox2->Location = System::Drawing::Point(3, 52);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(104, 38);
			this->checkBox2->TabIndex = 0;
			this->checkBox2->Text = L"Ñğåäíåå çíà÷åíèå";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox2_CheckedChanged);
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox1->Location = System::Drawing::Point(3, 3);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(104, 43);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"Ìåäèàííîå çíà÷åíèå";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(835, 675);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(18, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"H:";
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(859, 675);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(13, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"0";
			this->label7->Click += gcnew System::EventHandler(this, &Form1::label7_Click);
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(914, 675);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(17, 13);
			this->label8->TabIndex = 12;
			this->label8->Text = L"V:";
			this->label8->Click += gcnew System::EventHandler(this, &Form1::label8_Click);
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(937, 675);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(13, 13);
			this->label9->TabIndex = 13;
			this->label9->Text = L"0";
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1131, 697);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->tableLayoutPanel4);
			this->Controls->Add(this->tableLayoutPanel3);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Mediana v6.2";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::MouseCoordinates);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->EndInit();
			this->tableLayoutPanel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void çàãğóçèòüToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void íàñòğîéêèToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void âûõîäToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void îòêğûòüToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void answer(System::Object^  sender, System::EventArgs^  e);
private: System::Void value_change(System::Object^  sender, System::EventArgs^  e);
private: System::Void value_change2(System::Object^  sender, System::EventArgs^  e);
private: System::Void xCol_change(System::Object^  sender, System::EventArgs^  e);
private: System::Void yCol_changed(System::Object^  sender, System::EventArgs^  e);

	private: System::Void InitialConditions();
	private: System::Void Settings();
	public: System::Void PreReading(String^ MyFileName);
	public: System::Void Reading(array<String^>^ ReadlineMassive);
	private: System::Void PostRearing(double** VariableDataMassive, int xCol, int yCol, double start, double finish, double sector, int NumOflines);
	private: System::Void ArithmeticMean(double **Data, int NewLineCount, int NSector, int N);
	private: System::Void Medianvalue(int N);
	private: System::Void Writting();
	private: System::Void ScriptOfWrittingSeparate();
	private: System::Void ScriptOfWrittingUnify();
	private: System::Void PostWritting();
	private: System::Void CreateGraph();
	private: System::Void Saving();
	private: System::Void MsgBox();
	public: System::Void ChangeFormat(String^ var);

			 array<String^, 2>^ MedianDataBln;
			 array<String^, 2>^ MiddleDataBln;
			 array<String^>^ ReadlineMassive;
			 String^ HomeDirectory;
			 String^ FoutnameMidDat = "_middle.dat";
			 String^ FoutnameMedDat = "_median.dat";
			 String^ FoutnameMidTxt = "_middle.txt";
			 String^ FoutnameMedTxt = "_median.txt";
			 String^ GrapherMed = "medianGraph.bln";
			 String^ GrapherMid = "middleGraph.bln";
			 String^ shortFolderName;
			 String^ FileName;			 
			 String^ folderName;
			 String^ pathWorksheetMed;
			 String^ pathWorksheetMid;	
			 String^ pathWorksheetMedDat;
			 String^ pathWorksheetMidDat;
			 String^ pathWorksheetMedTxt;
			 String^ pathWorksheetMidTxt;
			 public: Form2^ gform2;
			 public: Form3^ gform3;
			 public: Form4^ gform4;
			 public: Form6^ gform6;
			 bool noNumbers;
			 bool drawing = false;
			 String^ Delimeter;
			 public: double **allData;
			 public: int NumOflines;
			 public: int orderfile = 0;		//íàìåğ êîëîíêè äëÿ çàïèñè â ôàéë = íîìåğ (êîë-âî) ôàéëà + 1
			 //public: bool skipline;
					 int skiplineCounter = 0;
		 public: bool allowskip;
		 public: int numberOfskip;
			 public: bool boolean;
					 bool booleanGraph;
					 bool booleanGraphMid;
					 bool booleanMedian;
					 bool booleanInLine;
					 bool booleanPoint;
					 bool booleanMiddle;
					 bool booleanDelete;
					 bool booleanMiddleDat;
					 bool booleanMedianDat;
					 bool exiting;
					 bool originGraph;
					 double **Data;
					 double **DataMassive;
					 double *mlines;
					 double *middle;
					 double *median;
					 double *members;
					 double *Upper;
					 double *Lower;
					 double start;		//íà÷àëüíîå çíà÷åíèå óãëà ğàññ÷¸òà
					 double	finish;		//êîíå÷íîå çíà÷åíèå óãëà ğàññ÷¸òà
					 double	sector;		//øàã ğàçáèåíèÿ		
					 int NumberOfFiles;
					 double doubdata;
			 public: int NSector,		//ïîğÿäêîâûé íîìåğ ñåêòîğà
				 NumOfDelim,
				 xCol,		//íîìåğ êîëîíêè äëÿ x â ôàéëå
				 yCol,		//íîìåğ êîëîíêè äëÿ y â ôàéëå
				 N,
				 test,
				 NewLineCount,
				 scenarios;
			 public: int NumOfColum;
					 double trackBarBuffer;
					 int SelectedFileToRead;
					 int limitleft = -180;
					 int limitright = 180;
					 int trackBarSence = 10;

System::Windows::Forms::DataVisualization::Charting::Series^ LeftBorder = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
System::Windows::Forms::DataVisualization::Charting::Series^ RightBorder = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
System::Windows::Forms::DataVisualization::Charting::Series^ MiddleLine = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
System::Windows::Forms::DataVisualization::Charting::Series^ MedianLine = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());

	public: string SysStdString(String^ var)
	{
				string answer;
				return answer = msclr::interop::marshal_as< std::string >(var);
	}
	public:	char* and_SysStringToChar(System::String^ string)
	{
				return (char*)(void*)Marshal::StringToHGlobalAnsi(string);
	}
			
	public:	bool CheckNumbers(string var)
	{
				int	N0,
					N1,
					N2,
					N3,
					N4,
					N5,
					N6,
					N7,
					N8,
					N9;

				N0 = count(var.begin(), var.end(), '0');
				N1 = count(var.begin(), var.end(), '1');
				N2 = count(var.begin(), var.end(), '2');
				N3 = count(var.begin(), var.end(), '3');
				N4 = count(var.begin(), var.end(), '4');
				N5 = count(var.begin(), var.end(), '5');
				N6 = count(var.begin(), var.end(), '6');
				N7 = count(var.begin(), var.end(), '7');
				N8 = count(var.begin(), var.end(), '8');
				N9 = count(var.begin(), var.end(), '9');
				if ((N1 == 0 && N2 == 0 && N3 == 0 && N4 == 0 && N5 == 0 && N6 == 0 && N7 == 0 && N8 == 0 && N9 == 0 && N0 == 0))
				{
					return noNumbers = true;
				}
				else
				{
					return noNumbers = false;
				}
	}
	public: double RoundNumber(double var, int n)
	{
				static const double powerOfTen[] = { 1.0, 10.0, 100.0, 1000.0, 10000.0, 100000.0, 1000000.0 };
				return var = floor(var / powerOfTen[n] + 0.5) / powerOfTen[n];
	}


private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void numericUpDown2_ValueChanged(System::Object^  sender, System::EventArgs^  e);
public: System::Void ïîñòğîèòüToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void double_click(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
public: System::Void GraphCompiler(double ** DataMassive);
private: System::Void CheckSaves(String^ loadFile);	// âãğóçêà ïàğàìåòğîâ
private: System::Void deleteItem(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void ifColumChosen();
private: System::Void OpenFileScenarios();
private: System::Void î÷èñòèòüÑïèñîêToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void ScriptOfWrittingOneDir();
private: System::Void IndexChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void chart1_Click(System::Object^  sender, System::EventArgs^  e) 
{
}
		 double FindMax(double** DataVariableMassive, int Col, int NumberOfLines)
		 {
			 double maximum = DataVariableMassive[0][Col - 1];
			 for (int i = 1; i < NumberOfLines; i++)
			 {
				 if (DataVariableMassive[i][Col - 1] > maximum)
				 {
					 maximum = DataVariableMassive[i][Col - 1];
				 }
			 }
			 return maximum;

		 }
		 double FindMin(double** DataVariableMassive, int Col, int NumberOfLines)
		 {
			 double minimum = DataVariableMassive[0][Col - 1];
			 for (int i = 1; i < NumberOfLines; i++)
			 {
				 if (DataVariableMassive[i][Col - 1] < minimum)
				 {
					 minimum = DataVariableMassive[i][Col - 1];
				 }
			 }
			 return minimum;
		 }
		 Decimal AbsRound(Decimal b, bool up)
		 {
			 if (up)
			 {
				 if (Decimal::Compare(b, Decimal::Floor(b)))
				 {			
					 b = Decimal::Add(Decimal::Floor(b), 1);
				 }
				 else
				 {
					 b = Decimal::Floor(b);
				 }
			 }
			 else
			 {
				 if (Decimal::Compare(b, Decimal::Floor(b)))
				 {
					 b = Decimal::Floor(b);
				 }
				 else
				 {					 
					 b = Decimal::Subtract(Decimal::Floor(b), 1);
				 }
			 }
			 return b;
		 }
private: System::Void DrawBorder();
private: System::Void DrawValues();
		 public: System::Void BufferData();
private: System::Void RefreshValue(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);

private: System::Void RemoveValue(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void SectorChanged(System::Object^  sender, System::EventArgs^  e);
public: System::Void DrawCompiler(double ** DataVariableMassive);

private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void FormGen(bool a);
private: System::Void label7_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MouseCoordinates(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void Coordinata(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void ReductorOpen();
		 public: System::Void EmptyChart();
private: System::Void ñöåíàğèéÂûâîäàÄàííûõToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void SettingsOpen();
private: System::Void toolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e); 
private: System::Void îÏğîãğàììåToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
};
}
