#pragma once

namespace NewMediana {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	ref class Form5;
	ref class Form4;
	ref class Form6;
	/// <summary>
	/// Summary for Form5
	/// </summary>
	public ref class Form5 : public System::Windows::Forms::Form
	{
	public:
		Form5(Form4^ Form)
		{
			InitializeComponent();
			gform4 = Form;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form5()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	public: System::Windows::Forms::ComboBox^  comboBox1;

	public:
	private: System::Windows::Forms::Label^  label1;

	public: System::Windows::Forms::TextBox^  textBox1;
	public: System::Windows::Forms::TextBox^  textBox2;
			
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Button^  button18;
	private: System::Windows::Forms::Button^  button19;
	private: System::Windows::Forms::Button^  button20;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::Button^  button21;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::Button^  button22;
	private: System::Windows::Forms::Button^  button23;
	private: System::Windows::Forms::Button^  button24;
	private: System::Windows::Forms::Button^  button25;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form5::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->SuspendLayout();
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(73, 32);
			this->button1->TabIndex = 0;
			this->button1->TabStop = false;
			this->button1->Text = L"Сдвиг";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form5::button1_Click);
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->Location = System::Drawing::Point(132, 8);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(90, 29);
			this->button2->TabIndex = 1;
			this->button2->TabStop = false;
			this->button2->Text = L"Сохранить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form5::button2_Click);
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"Колонка A", L"Колонка B", L"Колонка C", L"Колонка D",
					L"Колонка E", L"Колонка F", L"Колонка G", L"Колонка H", L"Колонка I"
			});
			this->comboBox1->Location = System::Drawing::Point(11, 12);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(357, 21);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form5::colChanged);
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(271, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(12, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"–";
			this->textBox1->Location = System::Drawing::Point(186, 51);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(80, 20);
			this->textBox1->TabIndex = 3;
			this->textBox2->Location = System::Drawing::Point(289, 51);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(80, 20);
			this->textBox2->TabIndex = 4;
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(15, 91);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(274, 17);
			this->checkBox3->TabIndex = 14;
			this->checkBox3->TabStop = false;
			this->checkBox3->Text = L"Применять ко всем файлам в списке редактора";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(3, 26);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(350, 24);
			this->textBox3->TabIndex = 15;
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->ColumnCount = 4;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->Controls->Add(this->button14, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->button13, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->button12, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->button11, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->button20, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->button19, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->button10, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->button9, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->button8, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->button7, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->button6, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->button5, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->button4, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->button3, 0, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(179, 154);
			this->tableLayoutPanel1->TabIndex = 16;
			this->button14->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button14->Location = System::Drawing::Point(91, 117);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(38, 34);
			this->button14->TabIndex = 11;
			this->button14->TabStop = false;
			this->button14->Text = L"+/-";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &Form5::button14_Click);
			this->button13->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button13->Location = System::Drawing::Point(47, 117);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(38, 34);
			this->button13->TabIndex = 10;
			this->button13->TabStop = false;
			this->button13->Text = L"0";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &Form5::button13_Click);
			this->button12->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button12->Location = System::Drawing::Point(3, 117);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(38, 34);
			this->button12->TabIndex = 9;
			this->button12->TabStop = false;
			this->button12->Text = L",";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &Form5::button12_Click);
			this->button11->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button11->Location = System::Drawing::Point(91, 79);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(38, 32);
			this->button11->TabIndex = 8;
			this->button11->TabStop = false;
			this->button11->Text = L"3";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form5::button11_Click);
			this->button20->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button20->Location = System::Drawing::Point(135, 41);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(41, 32);
			this->button20->TabIndex = 21;
			this->button20->TabStop = false;
			this->button20->Text = L"C";
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &Form5::button20_Click);
			this->button19->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button19->Location = System::Drawing::Point(135, 3);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(41, 32);
			this->button19->TabIndex = 20;
			this->button19->TabStop = false;
			this->button19->Text = L"←";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &Form5::button19_Click);
			this->button10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button10->Location = System::Drawing::Point(47, 79);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(38, 32);
			this->button10->TabIndex = 7;
			this->button10->TabStop = false;
			this->button10->Text = L"2";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form5::button10_Click);
			this->button9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9->Location = System::Drawing::Point(3, 79);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(38, 32);
			this->button9->TabIndex = 6;
			this->button9->TabStop = false;
			this->button9->Text = L"1";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form5::button9_Click);
			this->button8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8->Location = System::Drawing::Point(91, 41);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(38, 32);
			this->button8->TabIndex = 5;
			this->button8->TabStop = false;
			this->button8->Text = L"6";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form5::button8_Click);
			this->button7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->Location = System::Drawing::Point(47, 41);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(38, 32);
			this->button7->TabIndex = 4;
			this->button7->TabStop = false;
			this->button7->Text = L"5";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form5::button7_Click);
			this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(3, 41);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(38, 32);
			this->button6->TabIndex = 3;
			this->button6->TabStop = false;
			this->button6->Text = L"4";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form5::button6_Click);
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(91, 3);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(38, 32);
			this->button5->TabIndex = 2;
			this->button5->TabStop = false;
			this->button5->Text = L"9";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form5::button5_Click);
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(47, 3);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(38, 32);
			this->button4->TabIndex = 1;
			this->button4->TabStop = false;
			this->button4->Text = L"8";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form5::button4_Click);
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(3, 3);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(38, 32);
			this->button3->TabIndex = 0;
			this->button3->TabStop = false;
			this->button3->Text = L"7";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form5::button3_Click);
			this->button15->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button15->Location = System::Drawing::Point(3, 41);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(73, 32);
			this->button15->TabIndex = 17;
			this->button15->TabStop = false;
			this->button15->Text = L"Умнож-е";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &Form5::button15_Click);
			this->button16->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button16->Location = System::Drawing::Point(3, 79);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(73, 32);
			this->button16->TabIndex = 18;
			this->button16->TabStop = false;
			this->button16->Text = L"Обрезать";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &Form5::button16_Click);
			this->button17->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button17->Location = System::Drawing::Point(3, 117);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(73, 34);
			this->button17->TabIndex = 19;
			this->button17->TabStop = false;
			this->button17->Text = L"В дБ";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &Form5::button17_Click);
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				52.16138)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				47.83862)));
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 1, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(12, 191);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(356, 160);
			this->tableLayoutPanel2->TabIndex = 20;
			this->tableLayoutPanel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->button15, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->button16, 0, 2);
			this->tableLayoutPanel3->Controls->Add(this->button1, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->button23, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->button25, 1, 2);
			this->tableLayoutPanel3->Controls->Add(this->button17, 0, 3);
			this->tableLayoutPanel3->Controls->Add(this->button24, 1, 1);
			this->tableLayoutPanel3->Location = System::Drawing::Point(195, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 4;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(158, 154);
			this->tableLayoutPanel3->TabIndex = 17;
			this->button23->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button23->Location = System::Drawing::Point(82, 3);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(73, 32);
			this->button23->TabIndex = 20;
			this->button23->TabStop = false;
			this->button23->Text = L"Норм-ть";
			this->button23->UseVisualStyleBackColor = true;
			this->button23->Click += gcnew System::EventHandler(this, &Form5::button23_Click);
			this->button25->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button25->Location = System::Drawing::Point(82, 79);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(73, 32);
			this->button25->TabIndex = 22;
			this->button25->TabStop = false;
			this->button25->Text = L"Удалить";
			this->button25->UseVisualStyleBackColor = true;
			this->button25->Click += gcnew System::EventHandler(this, &Form5::button25_Click);
			this->button24->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button24->Location = System::Drawing::Point(82, 41);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(73, 32);
			this->button24->TabIndex = 21;
			this->button24->TabStop = false;
			this->button24->Text = L"Округлить";
			this->button24->UseVisualStyleBackColor = true;
			this->button24->Click += gcnew System::EventHandler(this, &Form5::button24_Click);
			this->button18->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button18->Location = System::Drawing::Point(14, 8);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(90, 29);
			this->button18->TabIndex = 21;
			this->button18->TabStop = false;
			this->button18->Text = L"Отменить";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &Form5::button18_Click);
			this->tableLayoutPanel4->BackColor = System::Drawing::SystemColors::Window;
			this->tableLayoutPanel4->ColumnCount = 1;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel4->Controls->Add(this->textBox3, 0, 1);
			this->tableLayoutPanel4->Location = System::Drawing::Point(12, 128);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 2;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 42)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 58)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(356, 57);
			this->tableLayoutPanel4->TabIndex = 5;
			this->tableLayoutPanel5->ColumnCount = 1;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel5->Controls->Add(this->radioButton1, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->radioButton2, 0, 1);
			this->tableLayoutPanel5->Location = System::Drawing::Point(12, 39);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 2;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(128, 46);
			this->tableLayoutPanel5->TabIndex = 2;
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(3, 3);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(103, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->Text = L"Номер стороки";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Form5::radioButton1_CheckedChanged);
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(3, 26);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(111, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->Text = L"Значение ячейки";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->button21->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button21->Location = System::Drawing::Point(251, 8);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(90, 29);
			this->button21->TabIndex = 24;
			this->button21->TabStop = false;
			this->button21->Text = L"Перезаписать";
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &Form5::button21_Click);
			this->tableLayoutPanel6->ColumnCount = 3;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333)));
			this->tableLayoutPanel6->Controls->Add(this->button21, 2, 0);
			this->tableLayoutPanel6->Controls->Add(this->button18, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->button2, 1, 0);
			this->tableLayoutPanel6->Location = System::Drawing::Point(12, 369);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 1;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(356, 45);
			this->tableLayoutPanel6->TabIndex = 25;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(383, 426);
			this->Controls->Add(this->tableLayoutPanel6);
			this->Controls->Add(this->tableLayoutPanel5);
			this->Controls->Add(this->tableLayoutPanel4);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Form5";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Изменение";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &Form5::Form5_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->tableLayoutPanel6->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Form4^ gform4;
		Form6^ gform6;
		//Form1^ gform1;
		String^ Extention = ".mr";
		String^ DirectoryOfResults;
		int part1;
		int part2;
		Decimal changer;
		Decimal newValue;
		Decimal celldata; 
		//int numberOfRows;
		bool comma = false;
		bool sign = true;
		String^ TextValue = "";
		//bool *Changed;		
		bool error = false;
		double maxValue = 0;
		bool deleteLastColumn;
		String^ TempDirectory;
		String^ temp = "temp";	
		
private: System::Void colChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
public: System::Void Form5::refreshrowvalues();
		 public: double RoundNumber(double var, int n)
		 {
					 static const double powerOfTen[] = { 1.0, 10.0, 100.0, 1000.0, 10000.0, 100000.0, 1000000.0 };
					 return var = floor(var * powerOfTen[n] + 0.5) / powerOfTen[n];
		 }
private: System::Void Form5::CheckEnteredRange();

private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e);	//плюс-минус
private: System::Void Form5_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e);	//запятая
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e);	//ноль
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e);	//один
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e);	//два
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e);	//три
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e);	//четыре
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e);	//пять
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e);	//шесть
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);	//семь
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e);	//весемь
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e);	//девять
private: System::Void button19_Click(System::Object^  sender, System::EventArgs^  e);	//backspace
private: System::Void button20_Click(System::Object^  sender, System::EventArgs^  e);	//clear
//
// функции
//
private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e);	//multiple
private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e);	//trim
private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e);	//dB
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void SavingReductedData(int selectedFile);

private: System::Void button21_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button23_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button24_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button25_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Function_Click(String^ name, int type);
private: System::Void FindMaximum(int t);  
};
}
