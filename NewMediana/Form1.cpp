#include "Header.h"
#include "Form1.h"
#include "Form2.h"
#include "Form3.h"
#include "Form4.h"
#include "Form6.h"

namespace NewMediana
{
	System::Void Form1::InitialConditions()
	{
		gform6 = gcnew Form6(this);
		if (listBox1->Items->Count == 0)
		{
			MessageBox::Show("Укажите имя файла!", "Внимание",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			exiting = true;
			goto End;
		}
		if (!(gform2->checkBox3->Checked) && !(gform2->checkBox6->Checked) && !(gform2->checkBox7->Checked) && !(gform2->checkBox8->Checked) && !(gform2->checkBox11->Checked) && !(gform2->checkBox12->Checked))
		{
			MessageBox::Show("Не задан ни один вариант генерации файла с ответом!", "Внимание",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			exiting = true;
			goto End;
		}
		if (start > finish)
		{
			MessageBox::Show("Начальное значение не может быть больше конечного!", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			exiting = true;
			goto End;
		}
		double s = (Convert::ToDouble(numericUpDown2->Value) - Convert::ToDouble(numericUpDown1->Value)) / Convert::ToDouble(numericUpDown3->Value);
		double d;
		d = RoundNumber(s, 0);
		if (!(d - s == 0))
		{
			MessageBox::Show("Неверно указан диапазон рассчета или ширина сектора!", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			exiting = true;
			goto End;
		}
		if (gform2->numericUpDownRound->Value > 6)
		{
			MessageBox::Show("Округление достигло предельного значения!", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			exiting = true;
			goto End;
		}

		orderfile = 0;
		NumOflines = 0;
		NumOfColum = 0;
		NumOfDelim = 0;		
		NewLineCount = 0;
		NSector = 1;
		boolean = false;
		exiting = false;
		//skipline = false;
		skiplineCounter = 0;

		button1->Enabled = false;
			
		gform6->ProcessBarInitialization(listBox1->Items->Count * 7);
	End: NULL;
	}
	System::Void Form1::Settings()
	{
		NumOflines = 0;
		NumOfColum = 0;
		NumOfDelim = 0;		
		NewLineCount = 0;
		NSector = 1;
		boolean = false;
		exiting = false;
		//skipline = false;
		noNumbers = false;
		skiplineCounter = 0;

		start = Convert::ToDouble(numericUpDown1->Value);
		finish = Convert::ToDouble(numericUpDown2->Value);
		sector = Convert::ToDouble(numericUpDown3->Value);

		xCol = Convert::ToInt32(numericUpDown4->Value);
		yCol = Convert::ToInt32(numericUpDown5->Value);
		N = Convert::ToInt32(gform2->numericUpDownRound->Value);
		booleanInLine = gform2->checkBox1->Checked;
		booleanPoint = gform2->checkBox2->Checked;
		booleanMiddle = gform2->checkBox3->Checked;
		booleanDelete = gform2->checkBox4->Checked;
		booleanMedian = gform2->checkBox6->Checked;
		booleanGraphMid = gform2->checkBox7->Checked;
		booleanGraph = gform2->checkBox8->Checked;
		//unifyBln = gform2->checkBox5->Checked;
		numberOfskip = Convert::ToInt32(gform2->numericUpDown1->Value);
		allowskip = gform2->checkBox5->Checked;

		if (gform2->radioButton1->Checked)
		{
			scenarios = 1;
		}
		if (gform2->radioButton2->Checked)
		{
			scenarios = 2;
		}
		if (gform2->radioButton3->Checked)
		{
			scenarios = 3;
		}
		originGraph = gform2->checkBox9->Checked;
		booleanMiddleDat = gform2->checkBox11->Checked;
		booleanMedianDat = gform2->checkBox12->Checked;

	}
	System::Void Form1::PreReading(String^ MyFileName)
	{
		int NofTabs,
			NofSpaces,
			NofSemiCal,
			NofComma,
			NofPoints,
			NofTabsNew,
			NofSpacesNew,
			NofSemiCalNew,
			NofCommaNew,
			NofPointsNew,

			NofEquals = 0,
			NofQuotes = 0,
			NofBracket1 = 0,
			NofBracket2 = 0,
			NofStars = 0,
			Errorline;
			

		//bool noNumbers = false;
		bool firstline = true;
		bool lastline = false;

		//string c;
		//string line;
		String^ sline;
		String^ vline;
		int TotalNumberlines = 0;
		try
		{
			// Create an instance of StreamReader to read from a file.
			StreamReader^ sr = gcnew StreamReader(MyFileName);
			try
			{				
				// Read and display lines from the file until the end of 
				// the file is reached.
				while (sline = sr->ReadLine())
				{
					TotalNumberlines++;
					if (!(sline == ""))
					{
						NumOflines++;
					}
				}
			}
			finally
			{
				if (sr)
					delete (IDisposable^)sr;
			}

			
			sr = gcnew StreamReader(MyFileName);
			//
			//
			if (allowskip)
			{
				String^ probe;
				int ProbeCounter = numberOfskip;
				for (int m = 0; m < ProbeCounter; m++)
				{
					probe = sr->ReadLine();
					if (probe == "")
					{
						ProbeCounter++;
					}
				}
				ReadlineMassive = gcnew array<String^>(NumOflines - numberOfskip);
			}
			else
			{
				ReadlineMassive = gcnew array<String^>(NumOflines);
			}
			try
			{
				int i = 0;
				while (sline = sr->ReadLine())
				{
					if (!(sline == ""))
					{
						ReadlineMassive[i] = sline;
						i++; 						
					}
				}
				//
				//
				//

				for (int j = 0; j < ReadlineMassive->Length; j++)
				{
					sline = ReadlineMassive[j];
					vline = sline;
					NofEquals = 0;
					while (!(vline->IndexOf("=") == -1))
					{
						vline = vline->String::Substring(vline->IndexOf("=") + 1);
						NofEquals++;
					}
					vline = sline;
					NofQuotes = 0;
					while (!(vline->IndexOf("\"") == -1))
					{
						vline = vline->String::Substring(vline->IndexOf("\"") + 1);
						NofQuotes++;
					}
					vline = sline;
					NofBracket1 = 0;
					while (!(vline->IndexOf("(") == -1))
					{
						vline = vline->String::Substring(vline->IndexOf("(") + 1);
						NofBracket1++;
					}
					vline = sline;
					NofBracket2 = 0;
					while (!(vline->IndexOf(")") == -1))
					{
						vline = vline->String::Substring(vline->IndexOf(")") + 1);
						NofBracket2++;
					}
					vline = sline;
					NofStars = 0;
					while (!(vline->IndexOf("*") == -1))
					{
						vline = vline->String::Substring(vline->IndexOf("*") + 1);
						NofStars++;
					}
					CheckNumbers(SysStdString(sline));
					
					if (!(NofEquals == 0) || !(NofQuotes == 0) || !(NofBracket1 == 0) || !(NofBracket2 == 0) || !(NofStars == 0) || noNumbers)
					{
						Errorline = j+1;
						if (skiplineCounter == Errorline - 1)
						{
							skiplineCounter++;
							continue;
						}
						else
						{
							int numberline;
							if (allowskip)
							{
								numberline = Errorline + numberOfskip;
							}
							else
							{
								numberline = Errorline;
							}
							String^ message = "Строчка " + numberline + " в файле " + MyFileName->Remove(MyFileName->LastIndexOf("."))->Substring(
								MyFileName->Remove(MyFileName->LastIndexOf("."))->LastIndexOf("\\") + 1) + " не удовлетворяет формату.  Чтение файла не возможно.";
							MessageBox::Show(message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Stop);
							exiting = true;
							if (построитьToolStripMenuItem->Checked)
							{
								chart1->Series->Clear();
							}
							goto End;
						}						
					}
					noNumbers = false;
				}

			}
			finally
			{
				if (sr)
					delete (IDisposable^)sr;
			}
			if (allowskip)
			{
				NumOflines = NumOflines - skiplineCounter - numberOfskip;
			}
			else
			{
				NumOflines = NumOflines - skiplineCounter;
			}
			
			//
			// Separator Determination
			//
			sline = ReadlineMassive[skiplineCounter];

			vline = sline;
			NofTabs = 0;
			while (!(vline->IndexOf("\t") == -1))
			{
				vline = vline->String::Substring(vline->IndexOf("\t") + 1);
				NofTabs++;
			}
			vline = sline;
			NofSpaces = 0;
			while (!(vline->IndexOf(" ") == -1))
			{
				vline = vline->String::Substring(vline->IndexOf(" ") + 1);
				NofSpaces++;
			}
			vline = sline;
			NofSemiCal = 0;
			while (!(vline->IndexOf(";") == -1))
			{
				vline = vline->String::Substring(vline->IndexOf(";") + 1);
				NofSemiCal++;
			}
			vline = sline;
			NofComma = 0;
			while (!(vline->IndexOf(",") == -1))
			{
				vline = vline->String::Substring(vline->IndexOf(",") + 1);
				NofComma++;
			}
			vline = sline;
			NofPoints = 0;
			while (!(vline->IndexOf(".") == -1))
			{
				vline = vline->String::Substring(vline->IndexOf(".") + 1);
				NofPoints++;
			}

			for (int k = 1 + skiplineCounter; k < NumOflines; k++)
			{
				sline = ReadlineMassive[k];
				vline = sline;
				NofTabsNew = 0;
				while (!(vline->IndexOf("\t") == -1))
				{
					vline = vline->String::Substring(vline->IndexOf("\t") + 1);
					NofTabsNew++;
				}

				vline = sline;
				NofSpacesNew = 0;
				while (!(vline->IndexOf(" ") == -1))
				{
					vline = vline->String::Substring(vline->IndexOf(" ") + 1);
					NofSpacesNew++;
				}

				vline = sline;
				NofSemiCalNew = 0;
				while (!(vline->IndexOf(";") == -1))
				{
					vline = vline->String::Substring(vline->IndexOf(";") + 1);
					NofSemiCalNew++;
				}

				vline = sline;
				NofCommaNew = 0;
				while (!(vline->IndexOf(",") == -1))
				{
					vline = vline->String::Substring(vline->IndexOf(",") + 1);
					NofCommaNew++;
				}

				vline = sline;
				NofPointsNew = 0;
				while (!(vline->IndexOf(".") == -1))
				{
					vline = vline->String::Substring(vline->IndexOf(".") + 1);
					NofPointsNew++;
				}
				if (!(NofTabsNew == NofTabs))
				{
					NofTabs = 0;
				}

				if (!(NofSpacesNew == NofSpaces))
				{
					NofSpaces = 0;
				}

				if (!(NofSemiCalNew == NofSemiCal))
				{
					NofSemiCal = 0;
				}

				if (!(NofCommaNew == NofComma))
				{
					NofComma = 0;
				}
				NofPoints = NofPointsNew + NofPoints;

				if (NofPoints > 0)
				{
					boolean = true;

					if (!(NofTabs == 0))
					{
						Delimeter = "\t";
						NumOfDelim = NofTabs;
					}
					if (!(NofSpaces == 0))
					{
						Delimeter = " ";
						NumOfDelim = NofSpaces;
					}
					if (!(NofSemiCal == 0))
					{
						Delimeter = ";";
						NumOfDelim = NofSemiCal;
					}
					if (!(NofComma == 0))
					{
						Delimeter = ",";
						NumOfDelim = NofComma;
					}
				}
				else
				{
					if (!(NofTabs == 0))
					{
						Delimeter = "\t";
						NumOfDelim = NofTabs;
					}
					if (!(NofSpaces == 0))
					{
						Delimeter = " ";
						NumOfDelim = NofSpaces;
					}
					if (!(NofSemiCal == 0))
					{
						Delimeter = ";";
						NumOfDelim = NofSemiCal;
					}
				}

				if (NofTabs == 0 && NofSpaces == 0 && NofSemiCal == 0 && NofComma == 0)
				{
					MessageBox::Show("Невозможно прочитать файл. Не обнаружен разделитель столбцов.", "Ошибка",
						MessageBoxButtons::OK, MessageBoxIcon::Stop);
					exiting = true;
					goto End;
				}
				if (sline->String::Substring(sline->LastIndexOf(Delimeter) + 1) == "")
				{
					NumOfColum = NumOfDelim;
				}
				else
				{
					NumOfColum = NumOfDelim + 1;
				}
			}
		}
		catch (Exception^)
		{
			// Let the user know what went wrong.
			MessageBox::Show("Неизвестная ошибка. Код 1.1", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Stop);
			exiting = true;
			goto End;
		}
	End: NULL;
	}
	System::Void Form1::Reading(array<String^>^ ReadlineMassive)
	{
		string b;
		string c;
		try
		{
			String^ sline;
			String^ vline;

			allData = new double *[NumOflines];
			for (int m = 0; m <= NumOflines; m++)
			{
				allData[m] = new double[NumOfColum];
			}

			for (int i = 0; i < NumOflines; i++)
			{
				/*if (skipline&&i == 0)
				{
					i = 1;
				}*/
				sline = ReadlineMassive[i + skiplineCounter];

				for (int j = 1; j <= NumOfColum; j++)
				{

					if (j <= NumOfDelim)
					{
						vline = sline->Remove(sline->IndexOf(Delimeter));
						sline = sline->Substring(sline->IndexOf(Delimeter) + 1);
					}
					else
					{
						vline = sline;
					}
					b = SysStdString(vline);
					if (boolean)
					{
						replace(b.begin(), b.end(), '.', ',');
					}

					remove_copy(b.begin(), b.end(), back_inserter(c), '\0');
					CheckNumbers(c);
					if (noNumbers)
					{
						c = "0";
						noNumbers = false;
					}
					ChangeFormat(gcnew String(c.c_str()));
					allData[i][j - 1] = doubdata;
					c = "";
					doubdata = 0;
				}
			}
			//
			// Проверка пустых колонок
			//
			bool *EmptyRows = new bool[NumOfColum];
			for (int h = 0; h < NumOfColum; h++)
			{
				EmptyRows[h] = true;
				for (int y = 0; y < NumOflines; y++)
				{
					if (!(allData[y][h] == 0))
					{
						EmptyRows[h] = false;
					}
				}
			}
			int ColumCounter = 0;
			for (int h = 0; h < NumOfColum; h++)
			{
				if (!(EmptyRows[h]))
				{
					ColumCounter++;
				}
			}
			//
			//	Перезапись без пустых колонок
			//							
			int f = 0;
			DataMassive = new double *[NumOflines];
			for (int m = 0; m <= NumOflines; m++)
			{
				DataMassive[m] = new double[ColumCounter];
			}
			for (int v = 0; v < NumOfColum; v++)
			{
				if (!(EmptyRows[v]))
				{
					for (int i = 0; i < NumOflines; i++)
					{
						DataMassive[i][f] = allData[i][v];
					}
					f++;
				}
			}
			NumOfColum = ColumCounter;
			

		}
		catch (Exception^ )
		{
			// Let the user know what went wrong.
			MessageBox::Show("Неизвестная ошибка. Код 2.1", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Stop);
			exiting = true;			
		}		
	}
	System::Void Form1::PostRearing(double** DataVariableMassive, int xCol, int yCol, double start, double finish, double sector, int NumOflines)
	{
		NewLineCount = 0;
		double diff1, diff2;
		NSector = 1;
		ifColumChosen();
		if (exiting)
		{
			goto End;
		}
		String^ mess = "Установленный диапазон рассчета выходит за границы считанных данных. Поменяйте границы или проверьте формат данных файла.";
		if (DataVariableMassive[0][xCol - 1]<DataVariableMassive[NumOflines - 1][xCol - 1])
		{
			if (DataVariableMassive[0][xCol - 1] > start || DataVariableMassive[NumOflines - 1][xCol - 1] < finish)
			{
				MessageBox::Show(mess, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				exiting = true;
				goto End;
			}
		}
		if (DataVariableMassive[0][xCol - 1]>DataVariableMassive[NumOflines - 1][xCol - 1])
		{
			if (DataVariableMassive[0][xCol - 1] < finish || DataVariableMassive[NumOflines - 1][xCol - 1]>start)
			{
				MessageBox::Show(mess, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				exiting = true;
				goto End;
			}
		}
		if (DataVariableMassive[0][xCol - 1] == DataVariableMassive[NumOflines - 1][xCol - 1])
		{
			MessageBox::Show(mess, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			exiting = true;
			goto End;
		}
		
		
		for (int i = 0; i < NumOflines; i++)
		{
			if (DataVariableMassive[i][xCol - 1] >= start && DataVariableMassive[i][xCol - 1] <= finish)
			{
				//
				// Подсчет строк в диапазоне
				//
				NewLineCount++;
				//
				// Проверка на разрывы
				//
				if (i > 0 && i < NumOflines - 1)
				{					
					diff1 = abs(DataVariableMassive[i - 1][xCol - 1] - DataVariableMassive[i][xCol - 1]);
					diff2 = abs(DataVariableMassive[i][xCol - 1] - DataVariableMassive[i + 1][xCol - 1]);
					if (diff1 / diff2 > 2 || diff2 / diff1 > 2)
					{
						String^ mess = String::Concat("Проверьте колонку X. Обнаружен разрыв в строчке ", i, ".");
						MessageBox::Show(mess, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
						exiting = true;
						goto End;
					}
				}
			}
		}
		int j = 0;
		int x = 0;
		Data = new double *[NewLineCount];
		for (int m = 0; m < NewLineCount; m++)
		{
			Data[m] = new double[3];
		}

		for (int i = 0; i < NumOflines; i++)
		{
			if (DataVariableMassive[i][xCol - 1] >= start && DataVariableMassive[i][xCol - 1] <= finish)
			{
				if (DataVariableMassive[0][xCol - 1] > DataVariableMassive[NumOflines - 1][xCol - 1])
				{
					x = NewLineCount - j - 1;
					Data[x][0] = DataVariableMassive[i][xCol - 1];
					Data[x][1] = DataVariableMassive[i][yCol - 1];
					j++;
				}
				else
				{
					Data[j][0] = DataVariableMassive[i][xCol - 1];
					Data[j][1] = DataVariableMassive[i][yCol - 1];
					j++;
				}
			}
		}
		j = 0;
		for (int i = 0; i < NewLineCount; i++)
		{
			if (Data[i][0] >= start + sector * (NSector - 1) && Data[i][0] <= start + sector * NSector)
			{
				if (Data[i][0] == start + sector * NSector)
				{
					Data[i][2] = 100 + NSector;
					if (!(i == NewLineCount - 1))
					{
						NSector++;
					}
				}
				else
				{
					Data[i][2] = NSector;
				}
			}
			else
			{
				NSector++;
				i--;
			}

			if (Data[i][0] > finish)
			{
				MessageBox::Show("Ошибка кода Data[i][0] >= finish.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				exiting = true;
				goto End;
			}
		}
	End: NULL;		
	}
	System::Void Form1::ArithmeticMean(double **Data, int NewLineCount, int NSector, int N)
	{
		static const double powerOfTen[] = { 1.0, 10.0, 100.0, 1000.0, 10000.0, 100000.0, 1000000.0 };
		static const double negarivPowerOfTen[] = { 0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001, 0.0000001 };
		int k = 1;
		int s = 0;
		double t = 0;
		members = new double[NSector];
		middle = new double[NSector];
		for (int i = 0; i < NewLineCount; i++)
		{
			t = t + Data[i][1];
			s++;
			if (i == 19)
			{
				i = 19;
			}
			if (Data[i][2] == 100 + k)
			{
				middle[k - 1] = floor(t / s * powerOfTen[N] + 0.5) / powerOfTen[N];
				members[k - 1] = s;
				k++;
				t = 0;
				s = 0;
				if (!(i == NewLineCount - 1))
				{
					i--;
				}

			}
			else
			{
				if (i == NewLineCount - 1)
				{
					middle[k - 1] = floor(t / s * powerOfTen[N] + 0.5) / powerOfTen[N];
					members[k - 1] = s;
					k++;
					t = 0;
					s = 0;
				}
				else
				{
					if (!(Data[i + 1][2] == k) && !(Data[i + 1][2] == 100 + k))
					{
						middle[k - 1] = floor(t / s * powerOfTen[N] + 0.5) / powerOfTen[N];
						members[k - 1] = s;
						k++;
						t = 0;
						s = 0;
					}
				}
			}
		}
	}
	System::Void Form1::Medianvalue(int N)
	{
		static const double powerOfTen[] = { 1.0, 10.0, 100.0, 1000.0, 10000.0, 100000.0, 1000000.0, 10000000.0 };
		int k = 1;
		int m = 0;
		int member = Convert::ToInt32(members[0]);
		median = new double[NSector];
		double* Buff = new double[member];


 		for (int j = 0; j < NewLineCount; j++)
		{
			member = Convert::ToInt32(members[k - 1]);
			Buff[m] = Data[j][1];
			m++;

			if (Data[j][2] == 100 + k)
			{
				sort(Buff, Buff + member);
				if (member % 2 == 0)
				{
					median[k - 1] = floor(((Buff[member / 2 - 1] + Buff[member / 2]) / 2)*powerOfTen[N] + 0.5) / powerOfTen[N];
				}
				else
				{
					median[k - 1] = floor(Buff[(member - 1) / 2] * powerOfTen[N] + 0.5) / powerOfTen[N];
				}
				m = 0;
				k++;
				if (!(j == NewLineCount - 1))
				{
					j--;
				}

				if (k - 1 < NSector)
				{
					member = Convert::ToInt32(members[k - 1]);
					double *Buff;
					Buff = new double[member];
				}
			}
			else
			{
				if (j == NewLineCount - 1)
				{
					sort(Buff, Buff + member);
					if (member % 2 == 0)
					{
						median[k - 1] = floor(((Buff[member / 2 - 1] + Buff[member / 2]) / 2)*powerOfTen[N] + 0.5) / powerOfTen[N];
					}
					else
					{
						median[k - 1] = floor(Buff[(member - 1) / 2] * powerOfTen[N] + 0.5) / powerOfTen[N];
					}
					m = 0;
					k++;

					if (k - 1 < NSector)
					{
						member = Convert::ToInt32(members[k - 1]);
						double *Buff;
						Buff = new double[member];
					}
				}
				else
				{
					if (!(Data[j + 1][2] == k) && !(Data[j + 1][2] == 100 + k))
					{
						sort(Buff, Buff + member);
						if (member % 2 == 0)
						{
							double a = Buff[0];
							double b = Buff[member - 1];
							median[k - 1] = floor(((Buff[member / 2 - 1] + Buff[member / 2]) / 2)*powerOfTen[N] + 0.5) / powerOfTen[N];
						}
						else
						{
							median[k - 1] = floor(Buff[(member - 1) / 2] * powerOfTen[N] + 0.5) / powerOfTen[N];
						}
						m = 0;
						k++;
						if (k - 1 < NSector)
						{
							member = Convert::ToInt32(members[k - 1]);
							double *Buff;
							Buff = new double[member];
						}
					}
				}
			}
		}
	}
	System::Void Form1::Writting()
	{
		if (Directory::Exists(folderName) && !booleanDelete && (gform2->radioButton2->Checked))	//orderfile == 0 && 
		{
			MessageBox::Show("Такая папка уже существует. Поставьте флажок <<Разрешить перезапись данных>>.", "Внимание",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
			exiting = true;
			goto End;
		}
		else
		{
			if (scenarios==1)
			{
				ScriptOfWrittingUnify();
			}
			if (scenarios == 2)
			{
				ScriptOfWrittingSeparate();
			}
			if (scenarios == 3)
			{
				ScriptOfWrittingOneDir();
			}
		}
	End: NULL;
	}
	System::Void Form1::ScriptOfWrittingSeparate()
	{
		System::IO::Directory::CreateDirectory(folderName);
		if (booleanGraph)
		{
			String^ pathStringGraphMed = Path::Combine(folderName, GrapherMed);
			StreamWriter^ sw = gcnew StreamWriter(pathStringGraphMed);
			double ArgDbl;
			for (int i = 0; i < NSector; i++)
			{
				ArgDbl = start + i*sector;
				sw->Write(Convert::ToString(ArgDbl)->Replace(",", "."));
				sw->Write(",");
				sw->Write(Convert::ToString(median[i])->Replace(",", "."));
				sw->WriteLine("");

				ArgDbl += sector;
				sw->Write(Convert::ToString(ArgDbl)->Replace(",", "."));
				sw->Write(",");
				sw->Write(Convert::ToString(median[i])->Replace(",", "."));
				sw->WriteLine("");
			}
			sw->Close();
		}

		if (booleanGraphMid)
		{
			String^ pathStringGraphMid = Path::Combine(folderName, GrapherMid);
			StreamWriter^ sw = gcnew StreamWriter(pathStringGraphMid);
			double ArgDbl;
			for (int i = 0; i < NSector; i++)
			{
				ArgDbl = start + i*sector;
				sw->Write(Convert::ToString(ArgDbl)->Replace(",", "."));
				sw->Write(",");
				sw->Write(Convert::ToString(middle[i])->Replace(",", "."));
				sw->WriteLine("");

				ArgDbl += sector;
				sw->Write(Convert::ToString(ArgDbl)->Replace(",", "."));
				sw->Write(",");
				sw->Write(Convert::ToString(middle[i])->Replace(",", "."));
				sw->WriteLine("");
			}
			sw->Close();
		}
		if (booleanMiddle)
		{
			String^ pathStringMid = Path::Combine(folderName, String::Concat(shortFolderName, FoutnameMidTxt));
			StreamWriter^ sw = gcnew StreamWriter(pathStringMid);			
			double arg1;
			double arg2;

			if (booleanInLine)
			{
				for (int i = 0; i < NSector; i++)
				{
					arg1 = start + i*sector;
					arg2 = arg1 + sector;
					if (booleanPoint)
					{
						sw->Write(String::Concat(Convert::ToString(arg1), "...", Convert::ToString(arg2))->Replace(",", "."));
					}
					else
					{
						sw->Write(String::Concat(Convert::ToString(arg1)->Replace(".", ","), "...", Convert::ToString(arg2)->Replace(".", ",")));
					}
					sw->Write("\t");
				}
				sw->WriteLine("");
				for (int i = 0; i < NSector; i++)
				{
					if (booleanPoint)
					{
						sw->Write(Convert::ToString(middle[i])->Replace(",", "."));
					}
					else
					{
						sw->Write(Convert::ToString(middle[i])->Replace(".", ","));
					}
					sw->Write("\t");
				}
			}
			else
			{
				for (int i = 0; i < NSector; i++)
				{
					arg1 = start + i*sector;
					arg2 = arg1 + sector;
					if (booleanPoint)
					{
						sw->Write(String::Concat(Convert::ToString(arg1), "...", Convert::ToString(arg2))->Replace(",", "."));
					}
					else
					{
						sw->Write(String::Concat(Convert::ToString(arg1)->Replace(".", ","), "...", Convert::ToString(arg2)->Replace(".", ",")));
					}
					sw->Write("\t");
					if (booleanPoint)
					{
						sw->Write(Convert::ToString(middle[i])->Replace(",", "."));
					}
					else
					{
						sw->Write(Convert::ToString(middle[i])->Replace(".", ","));
					}
					sw->WriteLine("");
				}
			}
			sw->Close();
		}
		if (booleanMedian)
		{
			String^ pathStringMed = Path::Combine(folderName, String::Concat(shortFolderName, FoutnameMedTxt));
			StreamWriter^ sw = gcnew StreamWriter(pathStringMed);
			double arg1;
			double arg2;
		
			if (booleanInLine)
			{
				for (int i = 0; i < NSector; i++)
				{
					arg1 = start + i*sector;
					arg2 = arg1 + sector;
					if (booleanPoint)
					{
						sw->Write(String::Concat(Convert::ToString(arg1), "...", Convert::ToString(arg2))->Replace(",", "."));
					}
					else
					{
						sw->Write(String::Concat(Convert::ToString(arg1)->Replace(".", ","), "...", Convert::ToString(arg2)->Replace(".", ",")));
					}
					sw->Write("\t");
				}
				sw->WriteLine("");
				for (int i = 0; i < NSector; i++)
				{
					if (booleanPoint)
					{
						sw->Write(Convert::ToString(median[i])->Replace(",", "."));
					}
					else
					{
						sw->Write(Convert::ToString(median[i])->Replace(".", ","));
					}
					sw->Write("\t");
				}
			}
			else
			{
				for (int i = 0; i < NSector; i++)
				{
					arg1 = start + i*sector;
					arg2 = arg1 + sector;
					if (booleanPoint)
					{
						sw->Write(String::Concat(Convert::ToString(arg1), "...", Convert::ToString(arg2))->Replace(",", "."));
					}
					else
					{
						sw->Write(String::Concat(Convert::ToString(arg1)->Replace(".", ","), "...", Convert::ToString(arg2)->Replace(".", ",")));
					}
					sw->Write("\t");
					if (booleanPoint)
					{
						sw->Write(Convert::ToString(median[i])->Replace(",", "."));
					}
					else
					{
						sw->Write(Convert::ToString(median[i])->Replace(".", ","));
					}
					sw->WriteLine("");
				}
			}				
			sw->Close();
		}
		if (originGraph)
		{
			String^ pathStringOrg = Path::Combine(folderName, "Origin.bln");
			StreamWriter^ sw = gcnew StreamWriter(pathStringOrg);

			sw->Write(",");
			sw->Write(shortFolderName);
			sw->WriteLine("");
			for (int i = 0; i < NewLineCount; i++)
			{
				sw->Write(Convert::ToString(Data[i][0])->Replace(",", "."));
				sw->Write(",");
				sw->Write(Convert::ToString(Data[i][1])->Replace(",", "."));
				sw->WriteLine("");
			}
			sw->Close();
		}
		if (booleanMiddleDat)
		{
			String^ pathStringMidDat = Path::Combine(folderName, String::Concat(shortFolderName, FoutnameMidDat));
			StreamWriter^ sw = gcnew StreamWriter(pathStringMidDat);
			double ArgDbl;
			for (int i = 0; i < NSector; i++)
			{
				ArgDbl = start + i*sector;
				sw->Write(Convert::ToString(ArgDbl)->Replace(",", "."));
				sw->Write("\t");
				sw->Write(Convert::ToString(middle[i])->Replace(",", "."));
				sw->WriteLine("");

				ArgDbl += sector;
				sw->Write(Convert::ToString(ArgDbl)->Replace(",", "."));
				sw->Write("\t");
				sw->Write(Convert::ToString(middle[i])->Replace(",", "."));
				sw->WriteLine("");
			}
			sw->Close();
		}
		if (booleanMedianDat)
		{
			String^ pathStringMedDat = Path::Combine(folderName, String::Concat(shortFolderName, FoutnameMedDat));
			StreamWriter^ sw = gcnew StreamWriter(pathStringMedDat);
			double ArgDbl;
			for (int i = 0; i < NSector; i++)
			{
				ArgDbl = start + i*sector;
				sw->Write(Convert::ToString(ArgDbl)->Replace(",", "."));
				sw->Write("\t");
				sw->Write(Convert::ToString(median[i])->Replace(",", "."));
				sw->WriteLine("");

				ArgDbl += sector;
				sw->Write(Convert::ToString(ArgDbl)->Replace(",", "."));
				sw->Write("\t");
				sw->Write(Convert::ToString(median[i])->Replace(",", "."));
				sw->WriteLine("");
			}
			sw->Close();
		}
	}
	System::Void Form1::ScriptOfWrittingUnify()
	{
		int j = 0;

		System::IO::Directory::CreateDirectory(folderName);
		
		if (orderfile == 0)
		{		
			if (booleanGraph || booleanMedianDat || booleanMedian)
			{
				double ArgDbl;
				MedianDataBln = gcnew array<String^, 2>(2 * NSector + 1, NumberOfFiles + 1);
				MedianDataBln[0, 0] = "";
				for (int i = 1; i < 2 * NSector + 1; i++)
				{
					ArgDbl = start + (i - 1) / 2 * sector;
					MedianDataBln[i, orderfile] = Convert::ToString(ArgDbl);
					i++;
					ArgDbl = ArgDbl + sector;
					MedianDataBln[i, orderfile] = Convert::ToString(ArgDbl);
				}
			}
			if (booleanGraphMid || booleanMiddleDat || booleanMiddle)
			{
				double ArgDbl;
				MiddleDataBln = gcnew array<String^, 2>(2 * NSector + 1, NumberOfFiles + 1);
				MiddleDataBln[0, 0] = "";
				for (int i = 1; i < 2 * NSector + 1; i++)
				{
					ArgDbl = start + (i - 1) / 2 * sector;
					MiddleDataBln[i, orderfile] = Convert::ToString(ArgDbl);
					i++;
					ArgDbl = ArgDbl + sector;
					MiddleDataBln[i, orderfile] = Convert::ToString(ArgDbl);
				}
			}
			orderfile++;			
		}
		if (booleanGraph || booleanMedianDat || booleanMedian)
		{
			MedianDataBln[0, orderfile] = FileName;

			for (int i = 1; i < 2 * NSector; i++)
			{

				MedianDataBln[i, orderfile] = Convert::ToString(median[j])->Replace(",", ".");
				i++;
				MedianDataBln[i, orderfile] = Convert::ToString(median[j])->Replace(",", ".");
				j++;
			}
			j = 0;
		}
		if (booleanGraphMid || booleanMiddleDat||booleanMiddle)
		{
			MiddleDataBln[0, orderfile] = FileName;

			for (int i = 1; i < 2 * NSector; i++)
			{

				MiddleDataBln[i, orderfile] = Convert::ToString(middle[j])->Replace(",", ".");
				i++;
				MiddleDataBln[i, orderfile] = Convert::ToString(middle[j])->Replace(",", ".");
				j++;
			}
			j = 0;
		}		
		orderfile++;
	}
	System::Void Form1::ScriptOfWrittingOneDir()
	{
		System::IO::Directory::CreateDirectory(folderName);

		if (booleanMiddle)
		{
			String^ pathStringMid = Path::Combine(folderName, String::Concat(shortFolderName, FoutnameMidTxt));
			StreamWriter^ sw = gcnew StreamWriter(pathStringMid);

			for (int i = 0; i < NSector; i++)
			{
				if (booleanPoint)
				{
					sw->Write(Convert::ToString(middle[i])->Replace(",", "."));
				}
				else
				{
					sw->Write(Convert::ToString(middle[i]));
				}
				if (booleanInLine)
				{
					sw->Write("\t");
				}
				else
				{
					sw->WriteLine("");
				}
			}
			sw->Close();
		}
		if (booleanMedian)
		{
			String^ pathStringMed = Path::Combine(folderName, String::Concat(shortFolderName, FoutnameMedTxt));
			StreamWriter^ sw = gcnew StreamWriter(pathStringMed);

			for (int i = 0; i < NSector; i++)
			{
				if (booleanPoint)
				{
					sw->Write(Convert::ToString(median[i])->Replace(",", "."));
				}
				else
				{
					sw->Write(Convert::ToString(median[i]));
				}
				if (booleanInLine)
				{
					sw->Write("\t");
				}
				else
				{
					sw->WriteLine("");
				}
			}
			sw->Close();
		}
		
		if (booleanMiddleDat)
		{
			String^ pathStringMidDat = Path::Combine(folderName, String::Concat(shortFolderName, FoutnameMidDat));
			StreamWriter^ sw = gcnew StreamWriter(pathStringMidDat);
			double ArgDbl;
			for (int i = 0; i < NSector; i++)
			{
				ArgDbl = start + i*sector;
				sw->Write(Convert::ToString(ArgDbl)->Replace(",", "."));
				sw->Write("\t");
				sw->Write(Convert::ToString(middle[i])->Replace(",", "."));
				sw->WriteLine("");

				ArgDbl += sector;
				sw->Write(Convert::ToString(ArgDbl)->Replace(",", "."));
				sw->Write("\t");
				sw->Write(Convert::ToString(middle[i])->Replace(",", "."));
				sw->WriteLine("");
			}
			sw->Close();
		}
		if (booleanMedianDat)
		{
			String^ pathStringMedDat = Path::Combine(folderName, String::Concat(shortFolderName, FoutnameMedDat));
			StreamWriter^ sw = gcnew StreamWriter(pathStringMedDat);
			double ArgDbl;
			for (int i = 0; i < NSector; i++)
			{
				ArgDbl = start + i*sector;
				sw->Write(Convert::ToString(ArgDbl)->Replace(",", "."));
				sw->Write("\t");
				sw->Write(Convert::ToString(median[i])->Replace(",", "."));
				sw->WriteLine("");

				ArgDbl += sector;
				sw->Write(Convert::ToString(ArgDbl)->Replace(",", "."));
				sw->Write("\t");
				sw->Write(Convert::ToString(median[i])->Replace(",", "."));
				sw->WriteLine("");
			}
			sw->Close();
		}
	}
	System::Void Form1::PostWritting()
	{
		if (booleanGraph)
		{
			StreamWriter^ sw = gcnew StreamWriter(pathWorksheetMed);

			sw->Write("\t");
			for (int k = 1; k <= NumberOfFiles; k++)
			{
				sw->Write(",");
				sw->Write(MedianDataBln[0, k]);				
			}
			sw->WriteLine("");
			for (int i = 1; i < 2 * NSector + 1; i++)
			{
				for (int k = 0; k <= NumberOfFiles; k++)
				{
					if (!(k == 0))
					{
						sw->Write(",");
					}
					sw->Write(MedianDataBln[i, k]);					
				}
				sw->WriteLine("");
			}
			sw->Close();
		}
		if (booleanGraphMid)
		{
			StreamWriter^ sw = gcnew StreamWriter(pathWorksheetMid);

			sw->Write("\t");
			for (int k = 1; k <= NumberOfFiles; k++)
			{
				sw->Write(",");
				sw->Write(MedianDataBln[0, k]);
			}
			sw->WriteLine("");

			for (int i = 1; i < 2 * NSector + 1; i++)
			{
				for (int k = 0; k <= NumberOfFiles; k++)
				{
					if (!(k == 0))
					{
						sw->Write(",");
					}
					sw->Write(MiddleDataBln[i, k]);
				}
				sw->WriteLine("");
			}
			sw->Close();
		}
		if (booleanMedianDat)
		{
			StreamWriter^ sw = gcnew StreamWriter(pathWorksheetMedDat);
			sw->Write("\t");
			for (int k = 1; k <= NumberOfFiles; k++)
			{
				sw->Write(",");
				sw->Write(MedianDataBln[0, k]);
			}
			sw->WriteLine("");
			for (int i = 1; i < 2 * NSector + 1; i++)
			{
				for (int k = 0; k <= NumberOfFiles; k++)
				{
					if (!(k == 0))
					{
						sw->Write(",");
					}
					sw->Write(MedianDataBln[i, k]);
				}
				sw->WriteLine("");
			}
			sw->Close();
		}
		if (booleanMiddleDat)
		{
			StreamWriter^ sw = gcnew StreamWriter(pathWorksheetMidDat);
			sw->Write("\t");
			for (int k = 1; k <= NumberOfFiles; k++)
			{
				sw->Write(",");
				sw->Write(MedianDataBln[0, k]);
			}
			sw->WriteLine("");
			for (int i = 1; i < 2 * NSector + 1; i++)
			{
				for (int k = 0; k <= NumberOfFiles; k++)
				{
					if (!(k == 0))
					{
						sw->Write(",");
					}
					sw->Write(MiddleDataBln[i, k]);
				}
				sw->WriteLine("");
			}
			sw->Close();
		}
		if (booleanMedian)
		{
			StreamWriter^ sw = gcnew StreamWriter(pathWorksheetMedTxt);
			double arg1;
			double arg2;
			if (booleanInLine)
			{
				sw->Write("\t");
				for (int i = 0; i < NSector; i++)
				{					
					arg1 = start + i*sector;
					arg2 = arg1 + sector;
					if (booleanPoint)
					{
						sw->Write(String::Concat(Convert::ToString(arg1), "...", Convert::ToString(arg2))->Replace(",", ".")); 
					}
					else
					{
						sw->Write(String::Concat(Convert::ToString(arg1)->Replace(".", ","), "...", Convert::ToString(arg2)->Replace(".", ",")));
					}
					sw->Write("\t");					
				}
				sw->WriteLine("");
				for (int k = 1; k <= NumberOfFiles; k++)
				{
					sw->Write(MedianDataBln[0, k]);
					sw->Write("\t");
					for (int i = 2; i < 2*NSector+1; i=i+2)
					{
						if (booleanPoint)
						{
							sw->Write(Convert::ToString(MedianDataBln[i, k])->Replace(",", "."));							
						}
						else
						{
							sw->Write(Convert::ToString(MedianDataBln[i, k])->Replace(".", ","));
						}
						sw->Write("\t");						
					}
					sw->WriteLine("");
				}
			}
			else
			{
				sw->Write("\t");
				for (int k = 1; k <= NumberOfFiles; k++)
				{
					if (booleanPoint)
					{
						sw->Write(Convert::ToString(MedianDataBln[0, k])->Replace(",", "."));
					}
					else
					{
						sw->Write(Convert::ToString(MedianDataBln[0, k])->Replace(".", ","));
					}
					sw->Write("\t");
				}
				sw->WriteLine("");
				for (int i = 1; i <= NSector; i++)
				{
					arg1 = start + (i-1)*sector;
					arg2 = arg1 + sector;
					if (booleanPoint)
					{
						sw->Write(String::Concat(Convert::ToString(arg1), "...", Convert::ToString(arg2))->Replace(",", "."));
					}
					else
					{
						sw->Write(String::Concat(Convert::ToString(arg1)->Replace(".", ","), "...", Convert::ToString(arg2)->Replace(".", ",")));
					}
					sw->Write("\t");
					for (int k = 1; k <= NumberOfFiles; k++)
					{
						if (booleanPoint)
						{
							sw->Write(Convert::ToString(MedianDataBln[2*i, k])->Replace(",", "."));
						}
						else
						{							
							sw->Write(Convert::ToString(MedianDataBln[2*i, k])->Replace(".", ","));
						}
						sw->Write("\t");
					}
					sw->WriteLine("");
				}
			}			
			sw->Close();
		}
		if (booleanMiddle)
		{
			StreamWriter^ sw = gcnew StreamWriter(pathWorksheetMidTxt);
			double arg1;
			double arg2;
			if (booleanInLine)
			{
				sw->Write("\t");
				for (int i = 0; i < NSector; i++)
				{
					arg1 = start + i*sector;
					arg2 = arg1 + sector;
					if (booleanPoint)
					{
						sw->Write(String::Concat(Convert::ToString(arg1), "...", Convert::ToString(arg2))->Replace(",", "."));
					}
					else
					{
						sw->Write(String::Concat(Convert::ToString(arg1)->Replace(".", ","), "...", Convert::ToString(arg2)->Replace(".", ",")));
					}
					sw->Write("\t");
				}
				sw->WriteLine("");
				for (int k = 1; k <= NumberOfFiles; k++)
				{
					sw->Write(MiddleDataBln[0, k]);
					sw->Write("\t");
					for (int i = 2; i < 2 * NSector + 1; i = i + 2)
					{
						if (booleanPoint)
						{
							sw->Write(Convert::ToString(MiddleDataBln[i, k])->Replace(",", "."));
						}
						else
						{
							sw->Write(Convert::ToString(MiddleDataBln[i, k])->Replace(".", ","));
						}
						sw->Write("\t");
					}
					sw->WriteLine("");
				}
			}
			else
			{
				sw->Write("\t");
				for (int k = 1; k <= NumberOfFiles; k++)
				{
					if (booleanPoint)
					{
						sw->Write(Convert::ToString(MiddleDataBln[0, k])->Replace(",", "."));
					}
					else
					{
						sw->Write(Convert::ToString(MiddleDataBln[0, k])->Replace(".", ","));
					}
					sw->Write("\t");
				}
				sw->WriteLine("");
				for (int i = 1; i <= NSector; i++)
				{
					arg1 = start + (i - 1)*sector;
					arg2 = arg1 + sector;
					if (booleanPoint)
					{
						sw->Write(String::Concat(Convert::ToString(arg1), "...", Convert::ToString(arg2))->Replace(",", "."));
					}
					else
					{
						sw->Write(String::Concat(Convert::ToString(arg1)->Replace(".", ","), "...", Convert::ToString(arg2)->Replace(".", ",")));
					}
					sw->Write("\t");
					for (int k = 1; k <= NumberOfFiles; k++)
					{
						if (booleanPoint)
						{
							sw->Write(Convert::ToString(MiddleDataBln[2 * i, k])->Replace(",", "."));
						}
						else
						{
							sw->Write(Convert::ToString(MiddleDataBln[2 * i, k])->Replace(".", ","));
						}
						sw->Write("\t");
					}
					sw->WriteLine("");
				}
			}
			sw->Close();
		}
	}
	System::Void Form1::CreateGraph()
	{
		FileInfo^ graphName;
		String^ NewGraphName;
		try
		{
			if (scenarios == 1)
			{
				if (NumberOfFiles == 1 || NumberOfFiles == 2)
				{
					if (booleanGraph && booleanGraphMid)
					{
						graphName = gcnew FileInfo("PlotDouble.grf");
						NewGraphName = String::Concat(shortFolderName, ".grf");
					}
					else
					{
						if (booleanGraph)
						{
							graphName = gcnew FileInfo("PlotDoubleMed.grf");
							NewGraphName = String::Concat(shortFolderName, "Median.grf");
						}
						if (booleanGraphMid)
						{
							graphName = gcnew FileInfo("PlotDoubleMid.grf");
							NewGraphName = String::Concat(shortFolderName, "Middle.grf");
						}
						if (!(booleanGraph) && !(booleanGraphMid))
						{
							goto End;
						}
					}
				}
				if (NumberOfFiles > 2)
				{
					if (booleanGraph && booleanGraphMid)
					{
						graphName = gcnew FileInfo("PlotTriple.grf");
						NewGraphName = String::Concat(shortFolderName, ".grf");
					}
					else
					{
						if (booleanGraph)
						{
							graphName = gcnew FileInfo("PlotTripleMed.grf");
							NewGraphName = String::Concat(shortFolderName, "Median.grf");
						}
						if (booleanGraphMid)
						{
							graphName = gcnew FileInfo("PlotTripleMid.grf");
							NewGraphName = String::Concat(shortFolderName, "Middle.grf");
						}
						if (!(booleanGraph) && !(booleanGraphMid))
						{
							goto End;
						}
					}
				}
			}
			if (scenarios == 2)
			{
				if (booleanGraph && booleanGraphMid)
				{
					graphName = gcnew FileInfo("PlotSingle.grf");
					NewGraphName = String::Concat(shortFolderName, ".grf");
				}
				else
				{
					if (booleanGraph)
					{
						graphName = gcnew FileInfo("PlotSingleMed.grf");
						NewGraphName = String::Concat(shortFolderName, "Median.grf");
					}
					if (booleanGraphMid)
					{
						graphName = gcnew FileInfo("PlotSingleMid.grf");
						NewGraphName = String::Concat(shortFolderName, "Middle.grf");
					}
					if (!(booleanGraph) && !(booleanGraphMid))
					{
						goto End;
					}
				}
			}

			String^ destFileAdress = Path::Combine(folderName, NewGraphName);

			if (scenarios == 3)
			{
			}


			if (File::Exists(destFileAdress))
			{
				String^ message = String::Concat("Файл ", NewGraphName, " уже существует.");
				MessageBox::Show(message, "Внимание!",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
				graphName->CopyTo(destFileAdress);
			}

		}
		catch (Exception^ )
		{
			String^ message = String::Concat("Ошибка копирования файла ", NewGraphName);
			MessageBox::Show(message, "Внимание!",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
			exiting = true;
			goto End;
		}

	End: NULL;
	}
	System::Void Form1::Saving()
	{
		try
		{
			if (File::Exists("Saves.txt"))
			{
				File::Delete("Saves.txt");
			}
			StreamWriter^ sw = gcnew StreamWriter("Saves.txt");
			sw->WriteLine(start);
			sw->WriteLine(finish);
			sw->WriteLine(sector);
			sw->WriteLine(xCol);
			sw->WriteLine(yCol);
			sw->WriteLine(N);
			if (booleanInLine)
			{
				sw->WriteLine(true);
			}
			else
			{
				sw->WriteLine(false);
			}
			if (booleanPoint)
			{
				sw->WriteLine(true);
			}
			else
			{
				sw->WriteLine(false);
			}
			if (booleanMiddle)
			{
				sw->WriteLine(true);
			}
			else
			{
				sw->WriteLine(false);
			}
			if (booleanDelete)
			{
				sw->WriteLine(true);
			}
			else
			{
				sw->WriteLine(false);
			}
			if (booleanMedian)
			{
				sw->WriteLine(true);
			}
			else
			{
				sw->WriteLine(false);
			}
			if (booleanGraphMid)
			{
				sw->WriteLine(true);
			}
			else
			{
				sw->WriteLine(false);
			}
			if (booleanGraph)
			{
				sw->WriteLine(true);
			}
			else
			{
				sw->WriteLine(false);
			}			
			sw->WriteLine(Convert::ToString(scenarios));
			if (originGraph)
			{
				sw->WriteLine(true);
			}
			else
			{
				sw->WriteLine(false);
			}
			if (booleanMiddleDat)
			{
				sw->WriteLine(true);
			}
			else
			{
				sw->WriteLine(false);
			}
			if (booleanMedianDat)
			{
				sw->WriteLine(true);
			}
			else
			{
				sw->WriteLine(false);
			}
			if (построитьToolStripMenuItem->Checked)
			{
				sw->WriteLine(true);
			}
			else
			{
				sw->WriteLine(false);
			}
			sw->WriteLine(numberOfskip);
			if (allowskip)
			{
				sw->WriteLine(true);
			}
			else
			{
				sw->WriteLine(false);
			}
			sw->Close();
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->ToString(), "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Stop);			
		}
	}
	System::Void Form1::MsgBox()
	{
		String^ message = "Данные успешно обработаны!";
		if (scenarios == 1)
		{
			message = String::Concat(message, "\n\nСозданы файлы:");
			if (gform2->checkBox7->Checked)
			{
				message = String::Concat(message, "\n'WorksheetMiddle' - средние значения");
			}
			if (gform2->checkBox8->Checked)
			{
				message = String::Concat(message, "\n'WorksheetMedian' - медианные значения");
			}

			message = String::Concat(message, "\n\nРасположение результатов обработки: \n", folderName);
		}
		if (scenarios == 2)
		{
			message = String::Concat(message, "\n\nСозданы папки:");
			String^ folderNameMess;
			for (int i = 0; i < listBox1->Items->Count; i++)
			{
				folderNameMess = listBox1->Items[i]->ToString()->Remove(listBox1->Items[i]->ToString()->LastIndexOf("."));
				message = String::Concat(message, "\n", folderNameMess);
			}

		}
		if (scenarios == 3)
		{
			message = String::Concat(message, "\n\nФайлы расположены:");			
			message = String::Concat(message, "\n", Path::GetDirectoryName(listBox1->Items[0]->ToString()));
		}

		MessageBox::Show(message, "Результаты",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	System::Void Form1::button1_Click(System::Object^  sender, System::EventArgs^  e)
	{		
		String^ FullFileName;
		InitialConditions();	

		if (exiting)
		{
			goto End;
		}
		
		for (int i = 0; i < listBox1->Items->Count; i++)
		{
			FullFileName = listBox1->Items[i]->ToString();
			FileName = FullFileName->Remove(FullFileName->LastIndexOf("."))->Substring(FullFileName->Remove(FullFileName->LastIndexOf("."))->LastIndexOf("\\") + 1);
			Settings();
			
			if (i == 0 && scenarios == 1)
			{
				int k = 1;
				shortFolderName = String::Concat("Process 1_", Convert::ToString(numericUpDown1->Value)->Replace(",", "."), "..", Convert::ToString(numericUpDown2->Value)->Replace(",", "."), "(+", Convert::ToString(numericUpDown3->Value)->Replace(",", "."), ")");;
				folderName = String::Concat(FullFileName->Remove(FullFileName->LastIndexOf("\\")), "\\", shortFolderName);
				while (Directory::Exists(folderName))
				{
					k++;
					shortFolderName = String::Concat("Process ", k, "_", numericUpDown1->Value, "..", numericUpDown2->Value, "(+", numericUpDown3->Value, ")");
					folderName = String::Concat(FullFileName->Remove(FullFileName->LastIndexOf("\\")), "\\", shortFolderName);
				}
				pathWorksheetMed = Path::Combine(folderName, "WorksheetMedian.bln");
				pathWorksheetMid = Path::Combine(folderName, "WorksheetMiddle.bln");
				pathWorksheetMedDat = Path::Combine(folderName, "WorksheetMedian.dat");
				pathWorksheetMidDat = Path::Combine(folderName, "WorksheetMiddle.dat");
				pathWorksheetMedTxt = Path::Combine(folderName, "WorksheetMedian.txt");
				pathWorksheetMidTxt = Path::Combine(folderName, "WorksheetMiddle.txt");
			}
			if (scenarios == 2)
			{
				folderName = FullFileName->Remove(FullFileName->LastIndexOf("."));
				shortFolderName = FileName;
			}
			if (scenarios == 3)
			{
				folderName = Path::GetDirectoryName(FullFileName);
				shortFolderName = FileName;
			}

			gform6->progressBar1->PerformStep();
			PreReading(FullFileName);
			if (exiting)
			{
				goto End;
			}
			gform6->progressBar1->PerformStep();
			Reading(ReadlineMassive);
			if (exiting)
			{
				goto End;
			}
			gform6->progressBar1->PerformStep();
			PostRearing(DataMassive, xCol, yCol, start, finish, sector, NumOflines);
			if (exiting)
			{
				goto End;
			}
			gform6->progressBar1->PerformStep();
			ArithmeticMean(Data, NewLineCount, NSector, N);
			gform6->progressBar1->PerformStep();
			Medianvalue(N);
			gform6->progressBar1->PerformStep();
			Writting();
			if (exiting)
			{
				goto End;
			}
			gform6->progressBar1->PerformStep();
			if (scenarios == 1)
			{
				if (i == 0)
				{
					CreateGraph();
				}
			}
			if (scenarios == 2)
			{
				CreateGraph();
			}
			if (scenarios == 3)
			{				
			}
		}		
		if (scenarios == 1)
		{
			PostWritting();
		}
		
		Saving();
		MsgBox();		
	End: gform6->Close();
		button1->Enabled = true;
		exiting = false;
	}			
	System::Void Form1::загрузитьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		trackBar1->Minimum = limitleft*trackBarSence;
		trackBar2->Minimum = limitleft*trackBarSence;
		trackBar1->Maximum = limitright*trackBarSence;
		trackBar2->Maximum = limitright*trackBarSence;
		numericUpDown1->Minimum = limitleft;
		numericUpDown1->Maximum = limitright;
		numericUpDown2->Minimum = limitleft;
		numericUpDown2->Maximum = limitright;

		OpenFileScenarios();
	}
	System::Void Form1::настройкиToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//SettingsOpen();
	}
	System::Void Form1::сценарийВыводаДанныхToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		SettingsOpen();
		gform2->tabControl1->SelectedTab = gform2->tabPage1;
	}
	System::Void Form1::toolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		SettingsOpen();
		gform2->tabControl1->SelectedTab = gform2->tabPage2;
	}
	System::Void Form1::выходToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
	}
	System::Void Form1::открытьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		ReductorOpen();
	}
	System::Void Form1::answer(System::Object^  sender, System::EventArgs^  e)
	{
		numericUpDown1->Select(0, 6);
		numericUpDown2->Select(0, 6);
		numericUpDown3->Select(0, 6);
		numericUpDown4->Select(0, 2);
		numericUpDown5->Select(0, 2);		
	}
	System::Void Form1::Form1_Load(System::Object^  sender, System::EventArgs^  e)
	{			
		gform2 = gcnew Form2(this);		
		CheckSaves("Saves.txt");		
		HomeDirectory = Path::GetDirectoryName(Path::GetFullPath("temp.txt"));		
		FormGen(построитьToolStripMenuItem->Checked);
	}
	System::Void Form1::value_change(System::Object^  sender, System::EventArgs^  e)
	{				
		if (!(drawing))
		{
			if (trackBar1->Value >= trackBar2->Value)
			{
				trackBar1->Value = trackBar2->Value;
			}
			/*if (trackBar1->Value <= trackBar1->Minimum)
			{
				trackBar1->Value = trackBar1->Minimum;
				numericUpDown1->Value = numericUpDown1->Minimum;
			}*/
			/*else
			{*/
			numericUpDown1->Value = Decimal::Divide(Convert::ToDecimal(trackBar1->Value), trackBarSence);
			/*}*/
			
		}
	}
	System::Void Form1::value_change2(System::Object^  sender, System::EventArgs^  e)
	{	
		if (!(drawing))
		{
			if (trackBar1->Value >= trackBar2->Value)
			{
				trackBar2->Value = trackBar1->Value;
			}
			/*if (trackBar2->Value <= trackBar2->Minimum)
			{
				trackBar2->Value = trackBar2->Minimum;
				numericUpDown2->Value = numericUpDown2->Minimum;
			}*/
			/*else
			{*/
			numericUpDown2->Value = Decimal::Divide(Convert::ToDecimal(trackBar2->Value), trackBarSence);
			/*}*/
			
		}
	}
	System::Void Form1::numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		if (!(drawing))
		{
			if (numericUpDown1->Value >= -180)
			{
				if (numericUpDown1->Value >= numericUpDown2->Value)
				{
					numericUpDown1->Value = numericUpDown2->Value;
				}
				trackBar1->Value = Convert::ToDouble(numericUpDown1->Value) * trackBarSence;
				if (!(listBox1->Items->Count == 0) && построитьToolStripMenuItem->Checked)
				{
					DrawCompiler(DataMassive);
				}
			}
			else
			{
				numericUpDown1->Value = -180;
			}
		}
	}
	System::Void Form1::numericUpDown2_ValueChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (!(drawing))
		{
			if (numericUpDown2->Value <= 180)
			{
				if (numericUpDown2->Value <= numericUpDown1->Value)
				{
					numericUpDown2->Value = numericUpDown1->Value;
				}
				trackBar2->Value = Convert::ToDouble(numericUpDown2->Value) * trackBarSence;
				if (!(listBox1->Items->Count == 0) && построитьToolStripMenuItem->Checked)
				{
					DrawCompiler(DataMassive);
				}
			}
			else
			{
				numericUpDown2->Value = 180;
			}
		}
	}
	System::Void Form1::SectorChanged(System::Object^  sender, System::EventArgs^  e)
	{			
		if (sector == 1 && numericUpDown3->Value==6)
		{
			numericUpDown3->Value = 5;
		}		
		if (!(listBox1->Items->Count == 0) && построитьToolStripMenuItem->Checked)
		{
			DrawCompiler(DataMassive);
		}
		sector = Convert::ToDouble(numericUpDown3->Value);
	}
	System::Void Form1::xCol_change(System::Object^  sender, System::EventArgs^  e)
	{		
		if (!(listBox1->Items->Count == 0) && построитьToolStripMenuItem->Checked)
		{
			exiting = false;
			xCol = Convert::ToInt32(numericUpDown4->Value);
			yCol = Convert::ToInt32(numericUpDown5->Value);
			if (!(xCol == yCol))
			{
				if (xCol>NumOfColum||yCol>NumOfColum)
				{
					chart1->Series->Clear();
					exiting = true;
					goto End;
				}
				GraphCompiler(DataMassive);
				if (exiting)
				{
					goto End;
				}
				DrawCompiler(DataMassive);
			}
			else
			{
				chart1->Series->Clear();
			}
		End:NULL;
		}
	}
	System::Void Form1::yCol_changed(System::Object^  sender, System::EventArgs^  e) 
	{	

		if (!(listBox1->Items->Count == 0) && построитьToolStripMenuItem->Checked)
		{
			exiting = false;
			xCol = Convert::ToInt32(numericUpDown4->Value);
			yCol = Convert::ToInt32(numericUpDown5->Value);
			if (!(xCol == yCol))
			{
				if (xCol>NumOfColum || yCol>NumOfColum)
				{
					chart1->Series->Clear();
					exiting = true;
					goto End;
				}
				GraphCompiler(DataMassive);
				if (exiting)
				{
					goto End;
				}
				DrawCompiler(DataMassive);
			}
			else
			{
				chart1->Series->Clear();
			}
		End:NULL;
		}
	}
	System::Void Form1::ChangeFormat(String^ data)
	{
		static const double powerOfTen[] = { 1.0, 10.0, 100.0, 1000.0, 10000.0, 100000.0, 1000000.0 };
		static const double negarivePowerOfTen[] = { 1.0, 0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001, 0.0000001 };
		//String^ data = 
		String^ exponenta;
		if (data->Contains("E"))
		{
			if (data->Contains("Exp"))
			{
				exponenta = "Exp";
			}
			else
			{
				exponenta = "E";
			}
		}
		if (data->Contains("e"))
		{
			if (data->Contains("exp"))
			{
				exponenta = "exp";
			}
			else
			{
				exponenta = "e";
			}
		}
		if (data->Contains("E") || data->Contains("e") || data->Contains("exp") || data->Contains("Exp"))
		{
			String^ dataNumb = data->Remove(data->IndexOf(exponenta));
			String^ dataExp = data->Substring(data->IndexOf(exponenta) + 1);
			int n;
			double x = Convert::ToDouble(dataNumb);
			if (dataExp->Contains("-"))
			{
				dataExp = dataExp->Replace("-", "");
				n = Convert::ToInt32(dataExp);
				doubdata = x*negarivePowerOfTen[n];
			}
			if (dataExp->Contains("+"))
			{
				dataExp = dataExp->Replace("+", "");
				n = Convert::ToInt32(dataExp);
				doubdata = x*powerOfTen[n];
			}
		}
		else
		{
			//double a = Convert::ToDouble(data);
			doubdata = Convert::ToDouble(data);
		}
	}
	System::Void Form1::построитьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		FormGen(построитьToolStripMenuItem->Checked);
		if (построитьToolStripMenuItem->Checked&&!(listBox1->Items->Count == 0))
		{
			BufferData();
			if (exiting)
			{
				goto End;
			}
			GraphCompiler(DataMassive);
			if (exiting)
			{
				goto End;
			}
			DrawCompiler(DataMassive);
		End: NULL;
		}
		else
		{
			/*chart1->Series->Clear();*/			
		}
	}
	System::Void Form1::double_click(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
		if (listBox1->Items->Count == 0)
		{
			trackBar1->Minimum = limitleft*trackBarSence;
			trackBar2->Minimum = limitleft*trackBarSence;
			trackBar1->Maximum = limitright*trackBarSence;
			trackBar2->Maximum = limitright*trackBarSence;
			numericUpDown1->Minimum = limitleft;
			numericUpDown1->Maximum = limitright;
			numericUpDown2->Minimum = limitleft;
			numericUpDown2->Maximum = limitright;

			OpenFileScenarios();
		}
		else
		{
			ReductorOpen();
		}		
	}

	System::Void Form1::CheckSaves(String^ loadFile)
	{
		if (File::Exists(loadFile))
		{
			try
			{				
				StreamReader^ sr = gcnew StreamReader(loadFile);

				numericUpDown1->Value = Convert::ToDecimal(sr->ReadLine()->String::Replace(".", ","));
				numericUpDown2->Value = Convert::ToDecimal(sr->ReadLine()->String::Replace(".", ","));
				numericUpDown3->Value = Convert::ToDecimal(sr->ReadLine()->String::Replace(".", ","));
				numericUpDown4->Value = Convert::ToDecimal(sr->ReadLine()->String::Replace(".", ","));
				numericUpDown5->Value = Convert::ToDecimal(sr->ReadLine()->String::Replace(".", ","));
				gform2->numericUpDownRound->Value = Convert::ToDecimal(sr->ReadLine()->String::Replace(".", ","));

				if (sr->ReadLine() == "True")
				{
					gform2->checkBox1->Checked = true;
				}
				else
				{
					gform2->checkBox1->Checked = false;
				}

				if (sr->ReadLine() == "True")
				{
					gform2->checkBox2->Checked = true;
				}
				else
				{
					gform2->checkBox2->Checked = false;
				}

				if (sr->ReadLine() == "True")
				{
					gform2->checkBox3->Checked = true;
				}
				else
				{
					gform2->checkBox3->Checked = false;
				}

				if (sr->ReadLine() == "True")
				{
					gform2->checkBox4->Checked = true;
				}
				else
				{
					gform2->checkBox4->Checked = false;
				}

				if (sr->ReadLine() == "True")
				{
					gform2->checkBox6->Checked = true;
				}
				else
				{
					gform2->checkBox6->Checked = false;
				}

				if (sr->ReadLine() == "True")
				{
					gform2->checkBox7->Checked = true;
				}
				else
				{
					gform2->checkBox7->Checked = false;
				}

				if (sr->ReadLine() == "True")
				{
					gform2->checkBox8->Checked = true;
				}
				else
				{
					gform2->checkBox8->Checked = false;
				}

				String^ line = sr->ReadLine();
				if (line == "1")
				{
					gform2->radioButton1->Checked = true;
				}
				if (line == "2")
				{
					gform2->radioButton2->Checked = true;
				}
				if (line == "3")
				{
					gform2->radioButton3->Checked = true;
				}

				if (sr->ReadLine() == "True")
				{
					gform2->checkBox9->Checked = true;
				}
				else
				{
					gform2->checkBox9->Checked = false;
				}

				if (sr->ReadLine() == "True")
				{
					gform2->checkBox11->Checked = true;
				}
				else
				{
					gform2->checkBox11->Checked = false;
				}

				if (sr->ReadLine() == "True")
				{
					gform2->checkBox12->Checked = true;
				}
				else
				{
					gform2->checkBox12->Checked = false;
				}
				if (sr->ReadLine() == "True")
				{
					построитьToolStripMenuItem->Checked = true;
				}
				else
				{
					построитьToolStripMenuItem->Checked = false;
				}
				gform2->numericUpDown1->Value = Convert::ToDecimal(sr->ReadLine()->String::Replace(".", ","));
				if (sr->ReadLine() == "True")
				{
					gform2->checkBox5->Checked = true;
				}
				else
				{
					gform2->checkBox5->Checked = false;
				}
				sr->Close();
			}
			catch (System::FormatException ^ e)
			{
				MessageBox::Show(e->ToString());
			}
		}
		else
		{
			sector = Convert::ToDouble(numericUpDown3->Value);
		}
		gform2->radioButton3->Checked = true;
		
	}
	System::Void Form1::ifColumChosen()
	{
		if (xCol > NumOfColum || yCol > NumOfColum)
		{
			MessageBox::Show("Выбрана несуществующая колонка. В загружаемом файле колонок всего " + NumOfColum + ".", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Stop);
			exiting = true;
			//goto End;
		}
		if (xCol == yCol || xCol == 0 || yCol == 0)
		{
			MessageBox::Show("Выберите колонку, с которой нужно прочитать значение.", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Stop);
			exiting = true;
			//goto End;
		}
	}
	System::Void Form1::deleteItem(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if (e->Button == System::Windows::Forms::MouseButtons::Right)
		{			
			if (!(listBox1->SelectedIndex == -1))
			{
				chart1->Series->Clear();
				SelectedFileToRead == listBox1->SelectedIndex;
				listBox1->Items->RemoveAt(SelectedFileToRead);
				EmptyChart();
				trackBar1->Minimum = limitleft*trackBarSence;
				trackBar2->Minimum = limitleft*trackBarSence;
				trackBar1->Maximum = limitright*trackBarSence;
				trackBar2->Maximum = limitright*trackBarSence;
				numericUpDown1->Minimum = limitleft;
				numericUpDown1->Maximum = limitright;
				numericUpDown2->Minimum = limitleft;
				numericUpDown2->Maximum = limitright;
			}
		}
	}	
	System::Void Form1::OpenFileScenarios()
	{
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "Data Files(*.txt;*.dat)|*.txt;*.dat|All files (*.*)|*.*";
		openFileDialog1->Multiselect = true;
		try
		{			
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				listBox1->Items->Clear();
				NumberOfFiles = openFileDialog1->FileNames->Length;
				for (int i = 0; i < NumberOfFiles; i++)
				{
					listBox1->Items->Add(openFileDialog1->FileNames[i]->ToString());
				}
				listBox1->SelectedItem = 0;
				listBox1->SetSelected(0, true);
				SelectedFileToRead = 0;
				if (exiting)
				{
					goto End;
				}
				if (построитьToolStripMenuItem->Checked)
				{
					BufferData();
					if (exiting)
					{
						goto End;
					}
					GraphCompiler(DataMassive);
					DrawCompiler(DataMassive);
				}				
			}
			else
			{
			}
		}
		catch (Exception^ e)
		{
			String^ message = "Произошла ошибка функции openFileDialog \n\n" + e->ToString();
			MessageBox::Show(message, "Результаты",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	End:NULL;
	}
	System::Void Form1::очиститьСписокToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		listBox1->Items->Clear();
		EmptyChart();

		trackBar1->Minimum = limitleft*trackBarSence;
		trackBar2->Minimum = limitleft*trackBarSence;
		trackBar1->Maximum = limitright*trackBarSence;
		trackBar2->Maximum = limitright*trackBarSence;
		numericUpDown1->Minimum = limitleft;
		numericUpDown1->Maximum = limitright;
		numericUpDown2->Minimum = limitleft;
		numericUpDown2->Maximum = limitright;
	}
	System::Void Form1::IndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (построитьToolStripMenuItem->Checked)
		{
			exiting = false;						
			if (!(listBox1->SelectedIndex == SelectedFileToRead))
			{				
				BufferData();
				if (exiting)
				{
					goto End;
				}
				GraphCompiler(DataMassive);
				if (exiting)
				{
					goto End;
				}
				DrawCompiler(DataMassive);
			End:NULL;
			}
		}
		SelectedFileToRead = listBox1->SelectedIndex;
	}
	
	System::Void Form1::RefreshValue(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
		if (trackBarBuffer == trackBar1->Value)
		{
			DrawCompiler(DataMassive);
		}
	}
	System::Void Form1::RemoveValue(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		trackBarBuffer = trackBar1->Value;
		MedianLine->Points->Clear();
	}
	
	System::Void Form1::GraphCompiler(double ** DataVariableMassive)
	{
		if (!(listBox1->Items->Count == 0))
		{
			double min;
			double max;
			int interval;
			//
			// chart1
			//
			chart1->Series->Clear();
			chart1->ChartAreas->Clear();
			chart1->Location = System::Drawing::Point(12, 12);
			chart1->Name = L"chart1";
			chart1->Size = System::Drawing::Size(641, 415);
			chart1->TabIndex = 0;
			chart1->Text = L"chart1";
			//
			// series1
			//
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			series1->Name = L"Series1";
			series1->MarkerSize = 2;
			//
			// chart compilation
			//
			chart1->Series->Add(series1);
			chart1->ChartAreas->Add(chartArea1);
			chartArea1->Name = L"ChartArea1";
			chartArea1->AxisY->IsStartedFromZero = false;
			chartArea1->InnerPlotPosition->Auto = false;
			chartArea1->InnerPlotPosition->Height = 88.4641F;
			chartArea1->InnerPlotPosition->Width = 93.34964F;
			chartArea1->InnerPlotPosition->X = 5.53333F;
			chartArea1->InnerPlotPosition->Y = 2.79255F;
			chart1->ChartAreas["ChartArea1"]->AxisY->IsLogarithmic = true;


			for (int i = 0; i < NumOflines; i++)
			{
				double x = DataVariableMassive[i][xCol - 1];
				double y = DataVariableMassive[i][yCol - 1];
				series1->Points->AddXY(x, y);
				if (y <= 0)
				{
					chart1->ChartAreas["ChartArea1"]->AxisY->IsLogarithmic = false;
					chart1->ChartAreas["ChartArea1"]->AxisY->IsStartedFromZero = false;
				}
			}
			double leftEdge;
			double rightEdge;
			if (DataVariableMassive[0][xCol - 1] < DataVariableMassive[NumOflines - 1][xCol - 1])
			{
				leftEdge = DataVariableMassive[0][xCol - 1];
				rightEdge = DataVariableMassive[NumOflines - 1][xCol - 1];
			}
			else
			{
				rightEdge = DataVariableMassive[0][xCol - 1];
				leftEdge = DataVariableMassive[NumOflines - 1][xCol - 1];
			}

			if (rightEdge - leftEdge <= 90)
			{
				interval = 15;
				chart1->ChartAreas["ChartArea1"]->AxisX->Interval = interval;
			}
			else
			{
				interval = 30;
				chart1->ChartAreas["ChartArea1"]->AxisX->Interval = interval;
			}
			int cleft = Convert::ToInt32(AbsRound(Convert::ToDecimal(abs(leftEdge) / interval), true));
			int cright = Convert::ToInt32(AbsRound(Convert::ToDecimal(abs(rightEdge) / interval), true));
			if (leftEdge>0)
			{
				min = cleft * interval - interval;
			}
			else
			{
				min = -cleft * interval;
			}
			if (rightEdge > 0)
			{
				max = cright * interval;
			}
			else
			{
				max = -cright * interval + interval;
			}

			chart1->ChartAreas["ChartArea1"]->AxisX->Maximum = max;
			chart1->ChartAreas["ChartArea1"]->AxisX->Minimum = min;

			chart1->Refresh();
		}

		else
		{
			EmptyChart();
		}
		


	}
	System::Void Form1::DrawCompiler(double ** DataVariableMassive)
	{
		if (!(drawing))
		{
			drawing = true;
			if (!(listBox1->Items->Count == 0) && построитьToolStripMenuItem->Checked)
			{
				start = Convert::ToDouble(numericUpDown1->Value);
				finish = Convert::ToDouble(numericUpDown2->Value);
				sector = Convert::ToDouble(numericUpDown3->Value);

				xCol = Convert::ToInt32(numericUpDown4->Value);
				yCol = Convert::ToInt32(numericUpDown5->Value);
				N = Convert::ToInt32(gform2->numericUpDownRound->Value);

				double minimum, maximum;
				minimum = FindMin(DataVariableMassive, xCol, NumOflines);
				maximum = FindMax(DataVariableMassive, xCol, NumOflines);
				if (abs(minimum) > 360 || abs(maximum) > 360)
				{
					MessageBox::Show("Невозможно построить график с выбранной колонки", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Information);
					exiting = true;

					goto End;
				}

				if (Convert::ToDouble(numericUpDown1->Value)< minimum)
				{
					numericUpDown1->Value = Convert::ToDecimal(minimum);
					trackBar1->Value = minimum * trackBarSence;
					start = minimum;
				}
				if (Convert::ToDouble(numericUpDown2->Value)> maximum)
				{
					numericUpDown2->Value = Convert::ToDecimal(maximum);
					trackBar2->Value = maximum * trackBarSence;
					finish = maximum;
				}
				if (Convert::ToDouble(numericUpDown1->Value)> maximum || Convert::ToDouble(numericUpDown2->Value) < minimum)
				{
					numericUpDown1->Value = Convert::ToDecimal(minimum);
					numericUpDown2->Value = Convert::ToDecimal(maximum);
					trackBar1->Value = minimum * trackBarSence;
					trackBar2->Value = maximum * trackBarSence;
					start = minimum;
					finish = maximum;
				}				

				if (exiting)
				{
					goto End;
				}
				if (DataVariableMassive[0][xCol - 1] < DataVariableMassive[NumOflines - 1][xCol - 1])
				{
					if (!(DataVariableMassive[0][xCol - 1] == minimum) || !(DataVariableMassive[NumOflines - 1][xCol - 1] == maximum))
					{
						MessageBox::Show("Невозможно построить график с выбранной колонки", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Information);
						exiting = true;
						goto End;
					}					
				}
				else
				{
					if (!(DataVariableMassive[NumOflines - 1][xCol - 1] == minimum) || !(DataVariableMassive[0][xCol - 1] == maximum))
					{
						MessageBox::Show("Невозможно построить график с выбранной колонки", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Information);
						exiting = true;
						goto End;
					}				
				}

				/*if (maximum > 0)
				{
					trackBar1->Maximum = Convert::ToDouble(AbsRound(Convert::ToDecimal(maximum * 2), false));
				}
				else
				{
					trackBar1->Maximum = Convert::ToDouble(AbsRound(Convert::ToDecimal(maximum * 2), true));
				}
				if (minimum < 0)
				{
					trackBar1->Minimum = Convert::ToDouble(AbsRound(Convert::ToDecimal(minimum * 2), false));
				}
				else
				{
					trackBar1->Minimum = Convert::ToDouble(AbsRound(Convert::ToDecimal(minimum * 2), true));
				}
				
				if (maximum > 0)
				{
					trackBar2->Maximum = Convert::ToDouble(AbsRound(Convert::ToDecimal(maximum * 2), true));
				}
				else
				{
					trackBar2->Maximum = Convert::ToDouble(AbsRound(Convert::ToDecimal(maximum * 2), false));
				}
				if (minimum < 0)
				{
					trackBar2->Minimum = Convert::ToDouble(AbsRound(Convert::ToDecimal(minimum * 2), true));
				}
				else
				{
					trackBar2->Minimum = Convert::ToDouble(AbsRound(Convert::ToDecimal(minimum * 2), false));
				}	*/
				
				trackBar1->Maximum = Convert::ToDouble(Convert::ToDecimal(maximum * trackBarSence));
				trackBar1->Minimum = Convert::ToDouble(Convert::ToDecimal(minimum * trackBarSence));
				trackBar2->Maximum = Convert::ToDouble(Convert::ToDecimal(maximum * trackBarSence));
				trackBar2->Minimum = Convert::ToDouble(Convert::ToDecimal(minimum * trackBarSence));

				numericUpDown1->Minimum = Convert::ToDecimal(minimum);
				numericUpDown1->Maximum = Convert::ToDecimal(maximum);
				numericUpDown2->Minimum = Convert::ToDecimal(minimum);
				numericUpDown2->Maximum = Convert::ToDecimal(maximum);

				MiddleLine->Points->Clear();
				MedianLine->Points->Clear();
				LeftBorder->Points->Clear();
				RightBorder->Points->Clear();

				DrawBorder();
				if (exiting)
				{
					goto End;
				}
				DrawValues();

				if (!(chart1->Series->Contains(LeftBorder)))
				{
					chart1->Series->Add(LeftBorder);
				}
				if (!(chart1->Series->Contains(RightBorder)))
				{
					chart1->Series->Add(RightBorder);
				}


				if (checkBox1->Checked&&!(chart1->Series->Contains(MedianLine)))
				{
					chart1->Series->Add(MedianLine);
				}
				if (checkBox2->Checked && !(chart1->Series->Contains(MiddleLine)))
				{
					chart1->Series->Add(MiddleLine);
				}			
			}
		End: NULL;			
		}
		drawing = false;
	}
	System::Void Form1::DrawBorder()
	{		
		double maximum = FindMax(DataMassive, yCol, NumOflines);
		double minimum = FindMin(DataMassive, yCol, NumOflines);		
		//
		// leftborder
		//
		LeftBorder->Name = "LeftBorder";
		LeftBorder->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		LeftBorder->Points->AddXY(Convert::ToDouble(numericUpDown1->Value), minimum);
		LeftBorder->Points->AddXY(Convert::ToDouble(numericUpDown1->Value), maximum);
		LeftBorder->Color = System::Drawing::Color::Chartreuse;
		
		//
		// rightborder
		//	
		LeftBorder->Name = "RightBorder";
		RightBorder->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		RightBorder->Points->AddXY(Convert::ToDouble(numericUpDown2->Value), minimum);
		RightBorder->Points->AddXY(Convert::ToDouble(numericUpDown2->Value), maximum);
		RightBorder->Color = System::Drawing::Color::Chartreuse;
		
		
	}
	System::Void Form1::DrawValues()
	{
		if (exiting)
		{
			goto End;
		}
		PostRearing(DataMassive, xCol, yCol, start, finish, sector, NumOflines);
		if (exiting)
		{
			goto End;
		}

		ArithmeticMean(Data, NewLineCount, NSector, 6);
		if (exiting)
		{
			goto End;
		}
		
		Medianvalue(6);
		
		
		if (exiting)
		{
			goto End;
		}

		if (checkBox1->Checked)
		{			
			for (int i = 0; i < NSector; i++)
			{				
				if (median[i]== 0)
				{
					chart1->ChartAreas["ChartArea1"]->AxisY->IsLogarithmic = false;
					chart1->ChartAreas["ChartArea1"]->AxisY->IsStartedFromZero = false;
				}
				
			}
		}
		if (checkBox2->Checked)
		{
			for (int i = 0; i < NSector; i++)
			{
				if (middle[i] == 0)
				{
					chart1->ChartAreas["ChartArea1"]->AxisY->IsLogarithmic = false;
					chart1->ChartAreas["ChartArea1"]->AxisY->IsStartedFromZero = false;
				}

			}
		}
		

		MedianLine->Points->AddXY(start, median[0]);
		MiddleLine->Points->AddXY(start, middle[0]);

		for (int i = 1; i < NSector; i++)
		{
			MedianLine->Points->AddXY(start + sector*i, median[i - 1]);
			MedianLine->Points->AddXY(start + sector*i, median[i]);

			MiddleLine->Points->AddXY(start + sector*i, middle[i - 1]);
			MiddleLine->Points->AddXY(start + sector*i, middle[i]);
		}

		MedianLine->Points->AddXY(finish, median[NSector - 1]);
		MiddleLine->Points->AddXY(finish, middle[NSector - 1]);

		MedianLine->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		MedianLine->Color = System::Drawing::Color::Red;
		MedianLine->BorderWidth = 3;	

		MiddleLine->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		MiddleLine->Color = System::Drawing::Color::DarkOrange;
		MiddleLine->BorderWidth = 3;
	End:NULL;
	}
	System::Void Form1::BufferData() 
	{
		if (!(listBox1->SelectedIndex == -1))
		{			
			SelectedFileToRead = listBox1->SelectedIndex;
			String^ GraphFile = listBox1->Items[SelectedFileToRead]->ToString();
			orderfile = 0;

			Settings();
			PreReading(GraphFile);
			if (exiting)
			{
				goto End;
			}
			Reading(ReadlineMassive);
			if (exiting)
			{
				goto End;
			}
			ifColumChosen();
			if (exiting)
			{
				goto End;
			}
		End:NULL;			
		}
	}

	System::Void Form1::checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (!(listBox1->Items->Count == 0))
		{
			if (checkBox1->Checked)
			{
				chart1->Series->Add(MedianLine);
			}
			else
			{
				chart1->Series->Remove(MedianLine);
			}
		}
	}
	System::Void Form1::checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		if (!(listBox1->Items->Count == 0))
		{
			if (checkBox2->Checked)
			{
				chart1->Series->Add(MiddleLine);
			}
			else
			{
				chart1->Series->Remove(MiddleLine);
			}
		}
	}
	System::Void Form1::FormGen(bool a)
	{		
		if (a)
		{
			// 
			// listBox1
			// 			
			listBox1->Size = System::Drawing::Size(1107, 139);
			// 
			// chart1
			//
			chart1->Enabled = true;
			chart1->Visible = true;			
			tableLayoutPanel3->Location = System::Drawing::Point(12, 185);
			tableLayoutPanel3->Size = System::Drawing::Size(981, 413);
			//
			// tableLayoutPanel1
			//
			tableLayoutPanel1->Controls->Clear();
			tableLayoutPanel1->ColumnStyles->Clear();
			tableLayoutPanel1->RowStyles->Clear();

			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				29.93197F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				70.06802F)));
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
			//
			// tableLayoutPanel4
			//
			tableLayoutPanel4->ColumnStyles->Clear();
			tableLayoutPanel4->Controls->Clear();
			tableLayoutPanel4->RowStyles->Clear();

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
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(3, 209);			
			this->label4->Size = System::Drawing::Size(96, 16);						
			this->label4->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			//
			// numericUpDown4
			// 
			this->numericUpDown4->Dock = System::Windows::Forms::DockStyle::Top;
			this->numericUpDown4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown4->Location = System::Drawing::Point(3, 228);			
			this->numericUpDown4->Size = System::Drawing::Size(96, 24);			
			this->numericUpDown4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;			
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));			
			this->numericUpDown3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown3->Location = System::Drawing::Point(3, 146);						
			this->numericUpDown3->Size = System::Drawing::Size(96, 24);			
			this->numericUpDown3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;			
			// 
			// numericUpDown5
			// 
			this->numericUpDown5->Dock = System::Windows::Forms::DockStyle::Top;
			this->numericUpDown5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown5->Location = System::Drawing::Point(3, 280);			
			this->numericUpDown5->Size = System::Drawing::Size(96, 24);			
			this->numericUpDown5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(3, 261);			
			this->label5->Size = System::Drawing::Size(96, 16);			
			this->label5->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(3, 394);			
			this->button1->Size = System::Drawing::Size(96, 63);						
			this->button1->UseVisualStyleBackColor = true;
			//
			// Form1
			//
			this->ClientSize = System::Drawing::Size(1131, 697);
		}
		else
		{
			// 
			// listBox1
			// 	
			listBox1->Size = System::Drawing::Size(493, 154);
			// 
			// chart1
			//
			chart1->Enabled = false;
			chart1->Visible = false;
			tableLayoutPanel3->Location = System::Drawing::Point(0, 0);
			tableLayoutPanel3->Size = System::Drawing::Size(0, 0);
			//
			// tableLayoutPanel1
			//
			tableLayoutPanel1->Controls->Clear();
			tableLayoutPanel1->ColumnStyles->Clear();
			tableLayoutPanel1->RowStyles->Clear();

			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				38)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				85)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				284)));
			this->tableLayoutPanel1->Controls->Add(this->trackBar2, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->numericUpDown1, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->numericUpDown2, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->trackBar1, 2, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 207);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(493, 100);
			this->tableLayoutPanel1->TabIndex = 4;
			//
			// tableLayoutPanel4
			//
			tableLayoutPanel4->ColumnStyles->Clear();
			tableLayoutPanel4->Controls->Clear();
			tableLayoutPanel4->RowStyles->Clear();

			this->tableLayoutPanel4->ColumnCount = 6;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				68)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				117)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				82)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				34)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				90)));
			this->tableLayoutPanel4->Controls->Add(this->label5, 4, 0);
			this->tableLayoutPanel4->Controls->Add(this->label4, 2, 0);
			this->tableLayoutPanel4->Controls->Add(this->numericUpDown3, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->numericUpDown4, 3, 0);
			this->tableLayoutPanel4->Controls->Add(this->numericUpDown5, 5, 0);
			this->tableLayoutPanel4->Controls->Add(this->label3, 0, 0);
			this->tableLayoutPanel4->Location = System::Drawing::Point(12, 321);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(493, 41);
			this->tableLayoutPanel4->TabIndex = 5;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(372, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(28, 41);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Y:";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(173, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(111, 41);
			this->label4->TabIndex = 7;
			this->label4->Text = L"X:";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(3, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(96, 41);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Сектор:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// numericUpDown1
			// 
			numericUpDown1->Minimum = -180;
			numericUpDown1->Maximum = 180;
			// 
			// numericUpDown2
			// 
			numericUpDown2->Minimum = -180;
			numericUpDown2->Maximum = 180;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Anchor = System::Windows::Forms::AnchorStyles::None;			
			this->numericUpDown3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));			
			this->numericUpDown3->Location = System::Drawing::Point(105, 8);						
			this->numericUpDown3->Size = System::Drawing::Size(62, 24);			
			this->numericUpDown3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->numericUpDown4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown4->Location = System::Drawing::Point(290, 8);			
			this->numericUpDown4->Size = System::Drawing::Size(50, 24);			
			this->numericUpDown4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// numericUpDown5
			// 
			this->numericUpDown5->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->numericUpDown5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown5->Location = System::Drawing::Point(406, 8);			
			this->numericUpDown5->Size = System::Drawing::Size(50, 24);			
			this->numericUpDown5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(12, 398);			
			this->button1->Size = System::Drawing::Size(493, 38);						
			this->button1->UseVisualStyleBackColor = true;			
			//
			// trackbar
			//
			trackBar1->Minimum = limitleft*trackBarSence;
			trackBar2->Minimum = limitleft*trackBarSence;
			trackBar2->Maximum = limitright*trackBarSence;
			trackBar1->Maximum = limitright*trackBarSence;
			// 
			// Form1
			// 
			this->ClientSize = System::Drawing::Size(517, 449);
			this->Controls->Add(this->button1);
		}
	}
	System::Void Form1::MouseCoordinates(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
		label7->Text = "0";
		label9->Text = "0";
	}
	System::Void Form1::Coordinata(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{		
		if (!(listBox1->Items->Count == 0))
		{
			Decimal H;
			Decimal V;
			H = Convert::ToDecimal((e->X - 80)*(chart1->ChartAreas->FindByName("ChartArea1")->AxisX->Maximum - chart1->
				ChartAreas->FindByName("ChartArea1")->AxisX->Minimum) / (935 - 80) + chart1->ChartAreas->FindByName("ChartArea1")->AxisX->Minimum);

			if (chart1->ChartAreas->FindByName("ChartArea1")->AxisY->IsLogarithmic)
			{
				Decimal a = Convert::ToDecimal(log10(chart1->ChartAreas->FindByName("ChartArea1")->AxisY->Maximum));
				Decimal b = Convert::ToDecimal(log10(chart1->ChartAreas->FindByName("ChartArea1")->AxisY->Minimum));
				a = AbsRound(a, true);
				b = AbsRound(b, false);
				V = Convert::ToDecimal(pow(10, (361 - e->Y)*Convert::ToDouble(Decimal::Subtract(a, b)) / (361 - 23) + Convert::ToDouble(b)));
			}
			else
			{
				V = Convert::ToDecimal((361 - e->Y)*(chart1->ChartAreas->FindByName("ChartArea1")->AxisY->Maximum - chart1->
					ChartAreas->FindByName("ChartArea1")->AxisY->Minimum) / (361 - 23) + chart1->ChartAreas->FindByName("ChartArea1")->AxisY->Minimum);
			}

			if (Convert::ToDouble(H) > chart1->ChartAreas->FindByName("ChartArea1")->AxisX->Maximum || Convert::ToDouble(H)<chart1->ChartAreas->FindByName("ChartArea1")->AxisX->Minimum || Convert::ToDouble(V)>chart1->ChartAreas->FindByName("ChartArea1")->AxisY->Maximum || Convert::ToDouble(V) < chart1->ChartAreas->FindByName("ChartArea1")->AxisY->Minimum)
			{
				label7->Text = "0";
				label9->Text = "0";
			}
			else
			{
				label7->Text = Convert::ToString(Decimal::Round(H, 1));
				label9->Text = Convert::ToString(Decimal::Round(V, 3));
			}
		}
	}
	System::Void Form1::ReductorOpen()
	{
		try
		{
			gform4->Show();
			gform4->Activate();
		}
		catch (System::ObjectDisposedException ^)
		{
			gform4 = gcnew Form4(this);
			gform4->Show();
			for (int i = 0; i < listBox1->Items->Count; i++)
			{
				gform4->listBox1->Items->Add(listBox1->Items[i]->ToString()->Substring(listBox1->Items[i]->ToString()->LastIndexOf("\\") + 1));
				gform4->Foldername = listBox1->Items[0]->ToString()->Remove(listBox1->Items[0]->ToString()->LastIndexOf("\\"));
			}
			if (listBox1->Items->Count == 1)
			{
				gform4->selectedFile = 1;
				gform4->listBox1->SetSelected(0, true);
				gform4->RefrechInfo(0);
			}
			if (listBox1->Items->Count > 1)
			{
				gform4->selectedFile = SelectedFileToRead;
				gform4->listBox1->SetSelected(SelectedFileToRead, true);
			}
		}
		catch (System::NullReferenceException ^)
		{
			gform4 = gcnew Form4(this);
			gform4->Show();
			for (int i = 0; i < listBox1->Items->Count; i++)
			{
				gform4->listBox1->Items->Add(listBox1->Items[i]->ToString()->Substring(listBox1->Items[i]->ToString()->LastIndexOf("\\") + 1));
				gform4->Foldername = listBox1->Items[0]->ToString()->Remove(listBox1->Items[0]->ToString()->LastIndexOf("\\"));
			}
			if (listBox1->Items->Count == 1)
			{
				gform4->selectedFile = 1;
				gform4->listBox1->SetSelected(0, true);
				gform4->RefrechInfo(0);
			}
			if (listBox1->Items->Count > 1)
			{
				gform4->selectedFile = SelectedFileToRead;
				gform4->listBox1->SetSelected(SelectedFileToRead, true);				
			}
		}
	}
	System::Void Form1::EmptyChart()
	{
		System::Windows::Forms::DataVisualization::Charting::Series^ seriesExample = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
		System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartAreaExample = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
		System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint1 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(3,
			10));
		System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint2 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(4,
			12));
		System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint3 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(5,
			11));
		System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint4 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(6,
			16));
		seriesExample->Points->Add(dataPoint1);
		seriesExample->Points->Add(dataPoint2);
		seriesExample->Points->Add(dataPoint3);
		seriesExample->Points->Add(dataPoint4);
		seriesExample->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		seriesExample->LabelBackColor = System::Drawing::Color::Transparent;
		seriesExample->LabelBorderColor = System::Drawing::Color::Transparent;
		seriesExample->Color = System::Drawing::Color::Transparent;
		chart1->ChartAreas->Clear();
		chart1->ChartAreas->Add(chartAreaExample);
		chartAreaExample->AxisY->IsStartedFromZero = false;
		chart1->Series->Clear();
		chart1->Series->Add(seriesExample);
	}
	System::Void Form1::SettingsOpen()
	{
		try
		{
			gform2->Show();
			gform2->Activate();
		}
		catch (System::ObjectDisposedException ^)
		{
			bool cb3 = gform2->checkBox3->Checked;
			bool cb6 = gform2->checkBox6->Checked;
			bool cb11 = gform2->checkBox11->Checked;
			bool cb12 = gform2->checkBox12->Checked;
			bool cb7 = gform2->checkBox7->Checked;
			bool cb8 = gform2->checkBox8->Checked;
			int rb;
			if (gform2->radioButton1->Checked)
			{
				rb = 1;
			}
			if (gform2->radioButton2->Checked)
			{
				rb = 2;
			}
			if (gform2->radioButton3->Checked)
			{
				rb = 3;
			}
			bool cb9 = gform2->checkBox9->Checked;
			bool cb1 = gform2->checkBox1->Checked;
			bool cb2 = gform2->checkBox2->Checked;
			bool cb4 = gform2->checkBox4->Checked;
			Decimal rN = gform2->numericUpDownRound->Value;
			gform2 = gcnew Form2(this);
			gform2->checkBox3->Checked = cb3;
			gform2->checkBox6->Checked = cb6;
			gform2->checkBox11->Checked = cb11;
			gform2->checkBox12->Checked = cb12;
			gform2->checkBox7->Checked = cb7;
			gform2->checkBox8->Checked = cb8;
			if (rb == 1)
			{
				gform2->radioButton1->Checked = true;
			}
			if (rb == 2)
			{
				gform2->radioButton2->Checked = true;
			}
			if (rb == 3)
			{
				gform2->radioButton3->Checked = true;
			}
			gform2->checkBox9->Checked = cb9;
			gform2->checkBox1->Checked = cb1;
			gform2->checkBox2->Checked = cb2;
			gform2->checkBox4->Checked = cb4;
			gform2->numericUpDownRound->Value = rN;
			gform2->checkBox5->Checked = allowskip;
			gform2->numericUpDown1->Value = numberOfskip;
			gform2->Show();
		}

		if (!(gform2->checkBox3->Checked))
		{
			gform2->checkBox3->ForeColor = SystemColors::ControlDarkDark;
		}
		if (!(gform2->checkBox6->Checked))
		{
			gform2->checkBox6->ForeColor = SystemColors::ControlDarkDark;
		}
		if (!(gform2->checkBox11->Checked))
		{
			gform2->checkBox11->ForeColor = SystemColors::ControlDarkDark;
		}
		if (!(gform2->checkBox12->Checked))
		{
			gform2->checkBox12->ForeColor = SystemColors::ControlDarkDark;
		}
		if (!(gform2->checkBox7->Checked))
		{
			gform2->checkBox7->ForeColor = SystemColors::ControlDarkDark;
		}
		if (!(gform2->checkBox8->Checked))
		{
			gform2->checkBox8->ForeColor = SystemColors::ControlDarkDark;
		}
		if (!(gform2->checkBox9->Checked))
		{
			gform2->checkBox9->ForeColor = SystemColors::ControlDarkDark;
		}
	}
	
	System::Void Form1::оПрограммеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		String^ mess;
		mess = String::Concat("Версия 6.2 от 25.11.2016 \nРазработал: Акимов Денис Игоревич \ne-mail: denis.akimov0@mail.ru");
		
		MessageBox::Show(mess, "Mediana",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}