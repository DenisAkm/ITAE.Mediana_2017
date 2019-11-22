#include "Header.h"
#include "Form5.h"
#include "Form4.h"
#include "Form1.h"
#include "Form6.h"

namespace NewMediana
{
System::Void Form5::colChanged(System::Object^  sender, System::EventArgs^  e)
{
	//int a = comboBox1->SelectedIndex;
	if (comboBox1->SelectedIndex+1>gform4->gform1->NumOfColum)
	{
		MessageBox::Show("Выбрана пустая колонка", "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
		comboBox1->SelectedIndex = gform4->reductedColumn;
		goto End;
	}
	this->Text = String::Concat("Изменение колонки", comboBox1->Items[comboBox1->SelectedIndex]->ToString()->String::Substring(comboBox1->Items[comboBox1->SelectedIndex]->ToString()->IndexOf(" ")));
	gform4->dataGridView1->ClearSelection();
	int a = comboBox1->SelectedIndex;
	gform4->reductedColumn = comboBox1->SelectedIndex;
	refreshrowvalues();
End: NULL;
}
//
System::Void Form5::button18_Click(System::Object^  sender, System::EventArgs^  e)	//кнопка отмена
{
	//int a = gform4->selectedFile;
	gform4->RefrechInfo(gform4->selectedFile - 1);
	if (checkBox3->Checked)
	{
		String^ mrDataFile;
		String^ ShortOriginDataFileName;
		String^ ShortOriginDataFileNameWithoutExtention;
		for (int i = 0; i < gform4->listBox1->Items->Count; i++)
		{
			ShortOriginDataFileName = gform4->listBox1->Items[i]->ToString();
			ShortOriginDataFileNameWithoutExtention = ShortOriginDataFileName->String::Remove(ShortOriginDataFileName->LastIndexOf("."));
			mrDataFile = Path::Combine(gform4->gform1->HomeDirectory, temp, String::Concat(ShortOriginDataFileNameWithoutExtention, Extention));
			if (File::Exists(mrDataFile))
			{
				File::Delete(mrDataFile);
			}
		}
	}
	this->Hide();
}
System::Void Form5::button2_Click(System::Object^  sender, System::EventArgs^  e) 
{	
	String^ message = "Файлы расположены:";
	String^ ShortOriginDataFileName;
	String^ ShortOriginDataFileNameWithoutExtention;
	String^ mrDataFile;
	String^ datDataFile;
	
	gform4->gform1->listBox1->Items->Clear();

	if (checkBox3->Checked)
	{
		for (int i = 0; i < gform4->listBox1->Items->Count; i++)
		{
			ShortOriginDataFileName = gform4->listBox1->Items[i]->ToString();
			ShortOriginDataFileNameWithoutExtention = ShortOriginDataFileName->String::Remove(ShortOriginDataFileName->LastIndexOf("."));
			mrDataFile = Path::Combine(gform4->gform1->HomeDirectory, temp, String::Concat(ShortOriginDataFileNameWithoutExtention, Extention));
			if (ShortOriginDataFileNameWithoutExtention->Substring(ShortOriginDataFileNameWithoutExtention->LastIndexOf("_")) == "_mr")
			{
				datDataFile = Path::Combine(DirectoryOfResults, String::Concat(ShortOriginDataFileNameWithoutExtention, ".dat"));
			}
			else
			{
				datDataFile = Path::Combine(DirectoryOfResults, String::Concat(ShortOriginDataFileNameWithoutExtention, "_mr.dat"));
			}
			if (!(Directory::Exists(DirectoryOfResults)))
			{
				Directory::CreateDirectory(DirectoryOfResults);
			}
			if (File::Exists(mrDataFile))
			{
				if (File::Exists(datDataFile))
				{
					File::Delete(datDataFile);
				}
				File::Copy(mrDataFile, datDataFile);
				File::Delete(mrDataFile);
			}
			else
			{
				goto End;
			}
			message = String::Concat(message, "\n\n", datDataFile);
			gform4->gform1->listBox1->Items->Add(datDataFile);
		}		
	}
	else
	{
		ShortOriginDataFileName = gform4->listBox1->Items[gform4->selectedFile - 1]->ToString();
		ShortOriginDataFileNameWithoutExtention = ShortOriginDataFileName->String::Remove(ShortOriginDataFileName->LastIndexOf("."));
		mrDataFile = Path::Combine(gform4->gform1->HomeDirectory, temp, String::Concat(ShortOriginDataFileNameWithoutExtention, Extention));
		if (ShortOriginDataFileNameWithoutExtention->Substring(ShortOriginDataFileNameWithoutExtention->LastIndexOf("_")) == "_mr")
		{
			datDataFile = Path::Combine(DirectoryOfResults, String::Concat(ShortOriginDataFileNameWithoutExtention, ".dat"));
		}
		else
		{
			datDataFile = Path::Combine(DirectoryOfResults, String::Concat(ShortOriginDataFileNameWithoutExtention, "_mr.dat"));
		}
		if (!(Directory::Exists(DirectoryOfResults)))
		{
			Directory::CreateDirectory(DirectoryOfResults);
		}
		if (File::Exists(mrDataFile))
		{
			if (File::Exists(datDataFile))
			{
				File::Delete(datDataFile);
			}
			File::Copy(mrDataFile, datDataFile);
			File::Delete(mrDataFile);			
		}
		else
		{
			MessageBox::Show("Ошибка сохранения", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			goto End;
		}
		message = String::Concat(message, "\n\n", datDataFile);

		
		gform4->gform1->listBox1->Items->Add(datDataFile);
	}

	if (Directory::Exists(TempDirectory))
	{
		Directory::Delete(TempDirectory);
	}

	MessageBox::Show(message, "Информация",
		MessageBoxButtons::OK, MessageBoxIcon::Information);


	this->Hide();
	if (gform4->listBox1->Items->Count == 1 || checkBox3->Checked)
	{
		gform4->Close();
	}
	else
	{
		gform4->listBox1->Items->Clear();
		gform4->dataGridView1->Rows->Clear();
		gform4->numberOfDataRows = 0;
		gform4->CreateAditionalEmptyRows();
	}

	MessageBox::Show("Список обновлён", "Информация",
		MessageBoxButtons::OK, MessageBoxIcon::Information); 

	


	if (gform4->gform1->построитьToolStripMenuItem->Checked)
	{
		gform4->gform1->exiting = false;
		gform4->gform1->SelectedFileToRead = gform4->selectedFile;
		gform4->gform1->listBox1->SelectedIndex = gform4->gform1->SelectedFileToRead-1;
		gform4->gform1->BufferData();
		if (gform4->gform1->exiting)
		{
			goto End;
		}
		gform4->gform1->GraphCompiler(gform4->gform1->DataMassive);
		if (gform4->gform1->exiting)
		{
			goto End;
		}
		gform4->gform1->DrawCompiler(gform4->gform1->DataMassive);
	}
End:NULL;
}
System::Void Form5::button21_Click(System::Object^  sender, System::EventArgs^  e)
{	
	String^ ShortOriginDataFileName;
	String^ ShortOriginDataFileNameWithoutExtention;
	String^ mrDataFile;
	String^ datDataFile;
	
	if (checkBox3->Checked)
	{
		for (int i = 0; i < gform4->listBox1->Items->Count; i++)
		{
			ShortOriginDataFileName = gform4->listBox1->Items[i]->ToString();
			ShortOriginDataFileNameWithoutExtention = ShortOriginDataFileName->String::Remove(ShortOriginDataFileName->LastIndexOf("."));
			mrDataFile = Path::Combine(gform4->gform1->HomeDirectory, temp, String::Concat(ShortOriginDataFileNameWithoutExtention, Extention));
			if (ShortOriginDataFileNameWithoutExtention->Substring(ShortOriginDataFileNameWithoutExtention->LastIndexOf("_")) == "_mr")
			{
				datDataFile = Path::Combine(DirectoryOfResults, String::Concat(ShortOriginDataFileNameWithoutExtention, ".dat"));
			}
			else
			{
				datDataFile = Path::Combine(DirectoryOfResults, String::Concat(ShortOriginDataFileNameWithoutExtention, "_mr.dat"));
			}
			if (File::Exists(mrDataFile))
			{
				try
				{
					File::Delete(Path::Combine(gform4->Foldername, ShortOriginDataFileName));
				}
				catch (Exception ^ e)
				{
					MessageBox::Show("Невозможно пересохранить некоторые файлы, поскольку они используются другим приложением \n"+ e->ToString(), "Ошибка",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
					goto End;
				}
				File::Copy(mrDataFile, Path::Combine(gform4->Foldername, ShortOriginDataFileName));
				File::Delete(mrDataFile);

			}
			else
			{
				if (File::Exists(datDataFile))
				{
					File::Delete(Path::Combine(gform4->Foldername, ShortOriginDataFileName));
					File::Copy(datDataFile, Path::Combine(gform4->Foldername, ShortOriginDataFileName));
					File::Delete(datDataFile);
				}
				else
				{
					MessageBox::Show("Не найдены файлы для сохранения", "Ошибка",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
					goto End;
				}
			}
		}
	}
	else
	{		
		ShortOriginDataFileName = gform4->listBox1->Items[gform4->selectedFile - 1]->ToString();
		ShortOriginDataFileNameWithoutExtention = ShortOriginDataFileName->String::Remove(ShortOriginDataFileName->LastIndexOf("."));
		mrDataFile = Path::Combine(gform4->gform1->HomeDirectory, temp, String::Concat(ShortOriginDataFileNameWithoutExtention, Extention));
		if (ShortOriginDataFileNameWithoutExtention->Substring(ShortOriginDataFileNameWithoutExtention->LastIndexOf("_")) == "_mr")
		{
			datDataFile = Path::Combine(DirectoryOfResults, String::Concat(ShortOriginDataFileNameWithoutExtention, ".dat"));
			gform4->listBox1->Items->RemoveAt(gform4->selectedFile - 1);
			gform4->dataGridView1->Rows->Clear();
			gform4->numberOfDataRows = 0;
			gform4->CreateAditionalEmptyRows();
		}
		else
		{
			datDataFile = Path::Combine(DirectoryOfResults, String::Concat(ShortOriginDataFileNameWithoutExtention, "_mr.dat"));
		}

		if (File::Exists(mrDataFile))
		{
			File::Delete(Path::Combine(gform4->Foldername, ShortOriginDataFileName));
			File::Copy(mrDataFile, Path::Combine(gform4->Foldername, ShortOriginDataFileName));
			File::Delete(mrDataFile);
		}
		else
		{
			if (File::Exists(datDataFile))
			{
				if (gform4->Foldername->String::Substring(gform4->Foldername->LastIndexOf("\\") + 1) == "Редактор файлов")
				{
					File::Delete(Path::Combine(gform4->Foldername, String::Concat(ShortOriginDataFileName->Remove(ShortOriginDataFileName->LastIndexOf("_")), ".dat")));
					File::Copy(datDataFile, Path::Combine(gform4->Foldername, String::Concat(ShortOriginDataFileName->Remove(ShortOriginDataFileName->LastIndexOf("_")), ".dat")));					
				}
				else
				{
					File::Delete(Path::Combine(gform4->Foldername, ShortOriginDataFileName));
					File::Copy(datDataFile, Path::Combine(gform4->Foldername, ShortOriginDataFileName));					
				}
				File::Delete(datDataFile);				
			}
			else
			{
				MessageBox::Show("Не найдены файлы для сохранения", "Ошибка",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				goto End;
			}
		}
	}
	if (Directory::Exists(TempDirectory))
	{
		Directory::Delete(TempDirectory);
	}
	MessageBox::Show("Файлы перезаписаны!", "Информация",
		MessageBoxButtons::OK, MessageBoxIcon::Information);
	this->Close();
	if (gform4->listBox1->Items->Count == 1 || checkBox3->Checked)
	{		
		gform4->Close();
	}
	
End: NULL;
}
//
System::Void Form5::checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	refreshrowvalues();
}
System::Void Form5::refreshrowvalues()
{
	try
	{
		if (radioButton1->Checked)
		{
			//label1->Text = "От строки:";
			//label2->Text = "До строки:";
			textBox1->Text = "1";
			textBox2->Text = Convert::ToString(gform4->numberOfDataRows);
		}
		if (radioButton2->Checked)
		{
			//int MaxVal = gform4->dataGridView1->Columns[gform4->reductedColumn]->

			Decimal MaxVal = Convert::ToDecimal(gform4->dataGridView1->Rows[1]->Cells[gform4->reductedColumn+1]->FormattedValue->ToString());
			Decimal MinVal = Convert::ToDecimal(gform4->dataGridView1->Rows[1]->Cells[gform4->reductedColumn+1]->FormattedValue->ToString());
			for (int i = 0; i < gform4->numberOfDataRows; i++)
			{
				if (!(gform4->dataGridView1->Rows[i]->Cells[gform4->reductedColumn+1]->FormattedValue->ToString() == ""))
				{
					//String^ fd = gform4->dataGridView1->Rows[i]->Cells[gform4->reductedColumn - 1]->FormattedValue->ToString();
					//String^ a = gform4->dataGridView1->Rows[i]->Cells[gform4->reductedColumn - 1]->FormattedValue->ToString();
					if (Decimal::Compare(MaxVal, Convert::ToDecimal(gform4->dataGridView1->Rows[i]->Cells[gform4->reductedColumn+1]->FormattedValue->ToString())) < 0)
					{
						MaxVal = Convert::ToDecimal(gform4->dataGridView1->Rows[i]->Cells[gform4->reductedColumn+1]->FormattedValue->ToString());
					}
					if (Decimal::Compare(MinVal, Convert::ToDecimal(gform4->dataGridView1->Rows[i]->Cells[gform4->reductedColumn+1]->FormattedValue->ToString())) > 0)
					{
						MinVal = Convert::ToDecimal(gform4->dataGridView1->Rows[i]->Cells[gform4->reductedColumn+1]->FormattedValue->ToString());
					}
				}
			}
			//label1->Text = "От значения:";
			//label2->Text = "До значения:";
			textBox1->Text = Convert::ToString(MinVal);
			textBox2->Text = Convert::ToString(MaxVal);

		}
	}
	catch (System::FormatException^ )
	{		
		MessageBox::Show("Выход за пределы данных", "Ошибка №2",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
		//comboBox1->SelectedIndex = gform4->reductedColumn;
	}
}

System::Void Form5::Form5_Load(System::Object^  sender, System::EventArgs^  e)
{		
	if (gform4->Foldername->String::Substring(gform4->Foldername->LastIndexOf("\\") + 1) == "Редактор файлов")
	{
		DirectoryOfResults = gform4->Foldername;
		checkBox3->Enabled = false;
	}
	else
	{
		DirectoryOfResults = Path::Combine(gform4->Foldername, "Редактор файлов");
	}
	
	radioButton1->Checked = true;
	TempDirectory = Path::Combine(gform4->gform1->HomeDirectory, temp);
	if (Directory::Exists(TempDirectory))
	{
		array<String^>^ tempfiles = Directory::GetFiles(TempDirectory);
		for (int i = 0; i < tempfiles->Length; i++)
		{
			File::Delete(Path::Combine(gform4->gform1->HomeDirectory, tempfiles[i]));
		}		
		try
		{
			Directory::Delete(TempDirectory);
		}
		catch (Exception^ e)
		{
			MessageBox::Show("Что-то пошло не так \n" + e->ToString(), "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		Directory::CreateDirectory(TempDirectory);
	}	
	else
	{
		Directory::CreateDirectory(TempDirectory);
	}
	deleteLastColumn = false;
}
//
//	numpad
//
System::Void Form5::button12_Click(System::Object^  sender, System::EventArgs^  e)	//запятая
{
	if (!(comma))
	{
		TextValue = String::Concat(TextValue, ",");
		comma = true;
	}	
}
System::Void Form5::button13_Click(System::Object^  sender, System::EventArgs^  e)	//ноль
{
	TextValue = String::Concat(TextValue, "0");
	textBox3->Text = TextValue;
} 
System::Void Form5::button9_Click(System::Object^  sender, System::EventArgs^  e)	//один
{
	TextValue = String::Concat(TextValue, "1");
	textBox3->Text = TextValue;
}
System::Void Form5::button10_Click(System::Object^  sender, System::EventArgs^  e)	//два
{
	TextValue = String::Concat(TextValue, "2");
	textBox3->Text = TextValue;
}
System::Void Form5::button11_Click(System::Object^  sender, System::EventArgs^  e)	//три
{
	TextValue = String::Concat(TextValue, "3");
	textBox3->Text = TextValue;
}
System::Void Form5::button6_Click(System::Object^  sender, System::EventArgs^  e)	//четыре
{
	TextValue = String::Concat(TextValue, "4");
	textBox3->Text = TextValue;
}
System::Void Form5::button7_Click(System::Object^  sender, System::EventArgs^  e)	//пять
{
	TextValue = String::Concat(TextValue, "5");
	textBox3->Text = TextValue;
}
System::Void Form5::button8_Click(System::Object^  sender, System::EventArgs^  e)	//шесть
{
	TextValue = String::Concat(TextValue, "6");
	textBox3->Text = TextValue;
}
System::Void Form5::button3_Click(System::Object^  sender, System::EventArgs^  e)	//семь
{
	TextValue = String::Concat(TextValue, "7");
	textBox3->Text = TextValue;
}
System::Void Form5::button4_Click(System::Object^  sender, System::EventArgs^  e)	//весемь
{
	TextValue = String::Concat(TextValue, "8");
	textBox3->Text = TextValue;
}
System::Void Form5::button5_Click(System::Object^  sender, System::EventArgs^  e)	//девять
{
	TextValue = String::Concat(TextValue, "9");
	textBox3->Text = TextValue;
}
System::Void Form5::button14_Click(System::Object^  sender, System::EventArgs^  e)	//плюс-минус
{
	if (sign)
	{
		TextValue = String::Concat("-",TextValue);
		textBox3->Text = TextValue;
		sign = false;
	}
	else
	{
		TextValue = TextValue->String::Substring(1);
		textBox3->Text = TextValue;
		sign = true;
	}	
}
System::Void Form5::button19_Click(System::Object^  sender, System::EventArgs^  e)	//backspace
{
	if (!(TextValue->Length==0))
	{
		TextValue = TextValue->String::Remove(TextValue->Length - 1);
		textBox3->Text = TextValue;
	}
}
System::Void Form5::button20_Click(System::Object^  sender, System::EventArgs^  e)	//clear
{
	textBox3->Text = "";
	TextValue = "";
	sign = true;
	comma = false;
}
//
//	functions
//
System::Void Form5::button1_Click(System::Object^  sender, System::EventArgs^  e)	//shift
{
	Function_Click("shift", 1);
}
System::Void Form5::button15_Click(System::Object^  sender, System::EventArgs^  e)	//multiple
{
	Function_Click("multiple", 1);
}
System::Void Form5::button16_Click(System::Object^  sender, System::EventArgs^  e) 	//trim
{		
	Decimal a;
	String^ ShortOriginDataFileName;
	String^ ShortOriginDataFileNameWithoutExtention;
	String^ mrDataFile;
	CheckEnteredRange();
	if (error)
	{
		MessageBox::Show("Некорректно введён диапазон значений", "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		goto End;
	}
	try
	{
		for (int i = 0; i < gform4->numberOfDataRows; i++)
		{
			if (radioButton1->Checked)
			{
				a = Convert::ToDecimal(gform4->dataGridView1->Rows[i]->Cells[0]->Value->ToString());
				if (!(a >= Convert::ToInt32(textBox1->Text) && a <= Convert::ToInt32(textBox2->Text)))
				{
					{
						gform4->dataGridView1->Rows->RemoveAt(i);
						gform4->numberOfDataRows--;
						i--;
					}
				}
			}
			if (radioButton2->Checked)
			{
				celldata = Convert::ToDecimal(gform4->dataGridView1->Rows[i]->Cells[comboBox1->SelectedIndex + 1]->Value->ToString());
				if (!(celldata >= Convert::ToDecimal(textBox1->Text->String::Replace(".", ",")) && celldata <= Convert::ToDecimal(textBox2->Text->String::Replace(".", ","))))
				{
					{
						gform4->dataGridView1->Rows->RemoveAt(i);
						gform4->numberOfDataRows--;
						i--;
					}
				}
			}
		}
		for (int j = 0; j <= gform4->numberOfDataRows; j++)
		{
			gform4->dataGridView1->Rows[j]->Cells[0]->Value = Convert::ToString(j + 1);
		}
		gform4->CreateAditionalEmptyRows();
	}
	catch (System::Exception^)
	{
		MessageBox::Show("Unnown error", "Ошибка №3",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
		goto End;
	}
	//
	//
	//


	if (!(Directory::Exists(TempDirectory)))
	{
		Directory::CreateDirectory(TempDirectory);
	}
	//
	//
	//
	if (checkBox3->Checked)
	{
		gform6 = gcnew Form6(gform4->gform1);
		gform6->ProcessBarInitialization(gform4->listBox1->Items->Count);
		for (int k = 0; k < gform4->listBox1->Items->Count; k++)
		{
			gform6->progressBar1->PerformStep();
			gform6->Show();
			//
			//
			//
			gform4->gform1->NumOflines = 0;
			gform4->gform1->NumOfColum = 0;
			gform4->gform1->NumOfDelim = 0;
			gform4->gform1->NumOfColum = 0;
			gform4->gform1->NewLineCount = 0;
			gform4->gform1->NSector = 1;
			gform4->gform1->boolean = false;
			gform4->gform1->exiting = false;
			gform4->gform1->skiplineCounter = 0;
			//gform4->gform1->skipline = false;
			gform4->gform1->noNumbers = false;
			//
			//
			//
			String^ DataFilename;
			String^ TempFile = Path::Combine(TempDirectory, String::Concat(gform4->listBox1->Items[k]->ToString()->String::Remove(gform4->listBox1->Items[k]->ToString()->LastIndexOf(".")), ".mr"));
			if (File::Exists(TempFile))
			{
				DataFilename = TempFile;
			}
			else
			{
				DataFilename = Path::Combine(gform4->Foldername, gform4->listBox1->Items[k]->ToString());
			}
			gform4->gform1->PreReading(DataFilename);
			gform4->gform1->Reading(gform4->gform1->ReadlineMassive);

			//
			//
			//
			ShortOriginDataFileName = gform4->listBox1->Items[k]->ToString();
			ShortOriginDataFileNameWithoutExtention = ShortOriginDataFileName->String::Remove(ShortOriginDataFileName->LastIndexOf("."));
			mrDataFile = Path::Combine(gform4->gform1->HomeDirectory, temp, String::Concat(ShortOriginDataFileNameWithoutExtention, Extention));
			StreamWriter^ sw = gcnew StreamWriter(mrDataFile);
			//
			//
			//			
			for (int l = 0; l < gform4->gform1->NumOflines; l++)
			{
				celldata = Convert::ToDecimal(gform4->gform1->DataMassive[l][comboBox1->SelectedIndex]);
				if (radioButton1->Checked)
				{
					if (l >= Convert::ToInt32(textBox1->Text) - 1 && l <= Convert::ToInt32(textBox2->Text) - 1)
					{
						for (int j = 0; j < gform4->gform1->NumOfColum; j++)
						{
							sw->Write(Convert::ToDecimal(gform4->gform1->DataMassive[l][j]));
							if (j + 1 == gform4->gform1->NumOfColum)
							{
								sw->Write(Environment::NewLine);
							}
							else
							{
								sw->Write(";");
							}
						}

					}
				}
				if (radioButton2->Checked)
				{
					if (celldata >= Convert::ToDecimal(textBox1->Text) && celldata <= Convert::ToDecimal(textBox2->Text))
					{
						for (int j = 0; j < gform4->gform1->NumOfColum; j++)
						{
							sw->Write(Convert::ToDecimal(gform4->gform1->DataMassive[l][j]));
							if (j + 1 == gform4->gform1->NumOfColum)
							{
								sw->Write(Environment::NewLine);
							}
							else
							{
								sw->Write(";");
							}
						}
					}
				}
			}
			sw->Close();
		}
		gform6->progressBar1->PerformStep();
		gform6->Close();
	}
	else
	{
		SavingReductedData(gform4->selectedFile - 1);
	}
	//
	//
	//

	refreshrowvalues();
End: NULL;
	if (error)
	{
		error = false;
	}
}
System::Void Form5::button17_Click(System::Object^  sender, System::EventArgs^  e)	//dB
{
	Function_Click("dB", 2);	
}
System::Void Form5::button23_Click(System::Object^  sender, System::EventArgs^  e) //Нормирование на 1
{
	Function_Click("norm1", 3);	
}
System::Void Form5::button24_Click(System::Object^  sender, System::EventArgs^  e) //Round
{
	Function_Click("round", 1);	
}
System::Void Form5::button25_Click(System::Object^  sender, System::EventArgs^  e) //delete
{
	String^ val;
	deleteLastColumn = true;
	for (int i = 0; i < gform4->numberOfDataRows; i++)
	{		
		for (int j = comboBox1->SelectedIndex + 1; j <= gform4->gform1->NumOfColum; j++)
		{
			if (j == gform4->gform1->NumOfColum)
			{
				gform4->dataGridView1->Rows[i]->Cells[j]->Value = "";
			}
			else
			{
				val = gform4->dataGridView1->Rows[i]->Cells[j + 1]->Value->ToString();
				gform4->dataGridView1->Rows[i]->Cells[j]->Value = val;
			}
		}
	}	
	
	if (checkBox3->Checked)
	{
		gform6 = gcnew Form6(gform4->gform1);
		gform6->ProcessBarInitialization(gform4->listBox1->Items->Count);
		//double variable;
		for (int k = 0; k < gform4->listBox1->Items->Count; k++)
		{
			gform6->progressBar1->PerformStep();
			gform6->Show();
			//
			//	Н.у.
			//
			gform4->gform1->NumOflines = 0;
			gform4->gform1->NumOfColum = 0;
			gform4->gform1->NumOfDelim = 0;
			gform4->gform1->NumOfColum = 0;
			gform4->gform1->NewLineCount = 0;
			gform4->gform1->NSector = 1;
			gform4->gform1->boolean = false;
			gform4->gform1->exiting = false;
			gform4->gform1->skiplineCounter = 0;
			//gform4->gform1->skipline = false;
			gform4->gform1->noNumbers = false;
			//
			//	Чтение файла
			//
			String^ DataFilename;
			String^ TempFile = Path::Combine(TempDirectory, String::Concat(gform4->listBox1->Items[k]->ToString()->String::Remove(gform4->listBox1->Items[k]->ToString()->LastIndexOf(".")), ".mr"));
			if (File::Exists(TempFile))
			{
				DataFilename = TempFile;
			}
			else
			{
				DataFilename = Path::Combine(gform4->Foldername, gform4->listBox1->Items[k]->ToString());
			}
			gform4->gform1->PreReading(DataFilename);
			gform4->gform1->Reading(gform4->gform1->ReadlineMassive);
			int Colums = gform4->gform1->NumOfColum;
			//
			//	Обработка и запись
			//
			for (int l = 0; l < gform4->gform1->NumOflines; l++)
			{	
				for (int s = comboBox1->SelectedIndex + 1; s <= Colums; s++)
				{
					if (!(s == Colums))
					{							
						gform4->gform1->DataMassive[l][s - 1] = gform4->gform1->DataMassive[l][s];
					}					
				}				
			}			
			SavingReductedData(k);
		}
		gform6->progressBar1->PerformStep();
		gform6->Close();		
	}
	else
	{		
		SavingReductedData(gform4->selectedFile - 1);
	}

	if (comboBox1->SelectedIndex + 1 == gform4->gform1->NumOfColum)
	{
		comboBox1->SelectedIndex--;
	}
	deleteLastColumn = false;	
	refreshrowvalues();
}
//
//
//
System::Void Form5::radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
{
	refreshrowvalues();
}
System::Void Form5::radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	refreshrowvalues();	
}

System::Void Form5::SavingReductedData(int selectedFile)
{		
	String^ ShortOriginDataFileName = gform4->listBox1->Items[selectedFile]->ToString();
	String^ ShortOriginDataFileNameWithoutExtention = ShortOriginDataFileName->String::Remove(ShortOriginDataFileName->LastIndexOf("."));	
	String^ mrDataFile = Path::Combine(gform4->gform1->HomeDirectory, temp, String::Concat(ShortOriginDataFileNameWithoutExtention, Extention));
	StreamWriter^ sw = gcnew StreamWriter(mrDataFile);
	int newNumberCol = gform4->gform1->NumOfColum;
	if (deleteLastColumn)
	{
		newNumberCol--;
	}	
	for (int i = 0; i < gform4->numberOfDataRows; i++)
	{
		for (int j = 0; j < newNumberCol; j++)
		{
			if (checkBox3->Checked)
			{
				sw->Write(Convert::ToDecimal(gform4->gform1->DataMassive[i][j]));
				if (j + 1 == newNumberCol)
				{
					sw->Write(Environment::NewLine);
				}
				else
				{
					sw->Write(";");
				}
			}
			else
			{
				sw->Write(gform4->dataGridView1->Rows[i]->Cells[j+1]->Value);
				if (j + 1 == newNumberCol)
				{
					sw->Write(Environment::NewLine);
				}
				else
				{
					sw->Write(";");
				}
			}			
		}		
	}
	sw->Close();
}
System::Void Form5::CheckEnteredRange()
{
	if (radioButton1->Checked)
	{
		try
		{
			Decimal start = Convert::ToInt32(textBox1->Text);
			Decimal finish = Convert::ToInt32(textBox2->Text);
		}
		catch (Exception^)
		{
			error = true;
		}
	}
	if (radioButton2->Checked)
	{
		try
		{
			Decimal start = Convert::ToDecimal(textBox1->Text);
			Decimal finish = Convert::ToDecimal(textBox2->Text);
		}
		catch (Exception^)
		{
			error = true;
		}
	}
	
}
System::Void Form5::Function_Click(String^ name, int type)
{		
	int DecNum = 0;

	//
	//	Проверка корректности ввода диапазона 
	//
	CheckEnteredRange();
	if (error)
	{
		MessageBox::Show("Некорректно введён диапазон значений", "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		goto End;
	}
	//
	//	Проверка корректности ввода величины корректирования
	//
	if (type == 1)
	{
		try
		{
			if (textBox3->Text == "-")
			{
				textBox3->Text = "-1";
			}
			if (textBox3->Text == "")
			{
				String^ mess;
				if (name == "shift")
				{
					mess = "Введите величину сдвига значений колонки";
				}
				if (name == "multiple")
				{
					mess = "Введите множитель изменения колонки";
				}
				if (name == "round")
				{
					mess = "Введите количество знаков после запятой";
				}
				MessageBox::Show(mess, "Внимание",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				goto End;
			}

			if (name == "round")
			{
				DecNum = Convert::ToInt32(textBox3->Text->String::Replace(".", ","));
				changer = 0;
			}
			else
			{
				changer = Convert::ToDecimal(textBox3->Text->String::Replace(".", ","));
				DecNum = 0;
			}

		}
		catch (System::FormatException ^)
		{
			String^ mess;
			if (name == "shift")
			{
				mess = "Введено некорректное значение величины сдвига";
			}
			if (name == "multiple")
			{
				mess = "Введено некорректное значение множителя колонки";
			}
			if (name == "round")
			{
				mess = "Введено некорректное значение количества знаков после запятой";
			}
			MessageBox::Show(mess, "Внимание",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
			goto End;
		}
	}
	//
	//	Проверка наличия отрицательных значений
	//
	if (name == "dB")
	{
		if (checkBox3->Checked)
		{
			//gform6 = gcnew Form6(gform4->gform1);
			//gform6->ProcessBarInitialization(gform4->listBox1->Items->Count * 2);
			for (int k = 0; k < gform4->listBox1->Items->Count; k++)
			{
				//gform6->progressBar1->PerformStep();
				//
				//
				//
				gform4->gform1->NumOflines = 0;
				gform4->gform1->NumOfColum = 0;
				gform4->gform1->NumOfDelim = 0;
				gform4->gform1->NumOfColum = 0;
				gform4->gform1->NewLineCount = 0;
				gform4->gform1->NSector = 1;
				gform4->gform1->boolean = false;
				gform4->gform1->exiting = false;
				gform4->gform1->skiplineCounter = 0;
				//gform4->gform1->skipline = false;
				gform4->gform1->noNumbers = false;
				//
				//
				//				
				String^ DataFilename;
				String^ TempFile = Path::Combine(TempDirectory, String::Concat(gform4->listBox1->Items[k]->ToString()->String::Remove(gform4->listBox1->Items[k]->ToString()->LastIndexOf(".")), ".mr"));
				if (File::Exists(TempFile))
				{
					DataFilename = TempFile;
				}
				else
				{
					DataFilename = Path::Combine(gform4->Foldername, gform4->listBox1->Items[k]->ToString());
				}
				gform4->gform1->PreReading(DataFilename);
				gform4->gform1->Reading(gform4->gform1->ReadlineMassive);

				for (int l = 0; l < gform4->gform1->NumOflines; l++)
				{
					celldata = Convert::ToDecimal(gform4->gform1->DataMassive[l][comboBox1->SelectedIndex]);
					if (celldata <= 0)
					{
						MessageBox::Show("Обнаружено отрицательное или равное нулю значение, перевод в децибелы не может быть выполнен", "Ошибка",
							MessageBoxButtons::OK, MessageBoxIcon::Error);
						goto End;
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < gform4->numberOfDataRows; i++)
			{
				celldata = Convert::ToDecimal(Convert::ToDouble(gform4->dataGridView1->Rows[i]->Cells[comboBox1->SelectedIndex + 1]->Value->ToString()));
				if (celldata <= 0)
				{
					MessageBox::Show("Обнаружено отрицательное или равное нулю значение, перевод в децибелы не может быть выполнен", "Ошибка",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
					goto End;
				}
			}
		}
	}
	//
	//	Вычисление максимального значения
	//
	if (name == "norm1")
	{
		FindMaximum(1);
	}
	//
	//	Обновить таблицу
	//
	celldata = 0;
	newValue = 0;
	try
	{
		for (int i = 0; i < gform4->numberOfDataRows; i++)
		{
			celldata = Convert::ToDecimal(Convert::ToDouble(gform4->dataGridView1->Rows[i]->Cells[comboBox1->SelectedIndex + 1]->Value->ToString()));
			if (radioButton1->Checked)
			{
				if (i >= Convert::ToInt32(textBox1->Text) - 1 && i <= Convert::ToInt32(textBox2->Text) - 1)
				{
					if (name == "shift")
					{
						newValue = Decimal::Add(celldata, changer);						
					}
					if (name == "multiple")
					{
						newValue = Decimal::Multiply(celldata, changer);						
					}					
					if (name == "dB")
					{
						newValue = Convert::ToDecimal(20.0*log10(Convert::ToDouble(celldata)) / log10(exp(1)));					
					}
					if (name == "norm1")
					{
						newValue = Convert::ToDecimal(Convert::ToDouble(celldata) / maxValue);						
					}
					if (name == "round")
					{
						newValue = Decimal::Round(celldata, DecNum);						
					}					
					gform4->dataGridView1->Rows[i]->Cells[comboBox1->SelectedIndex + 1]->Value = newValue;
				}
			}
			if (radioButton2->Checked)
			{
				if (celldata >= Convert::ToDecimal(textBox1->Text->String::Replace(".", ",")) && celldata <= Convert::ToDecimal(textBox2->Text->String::Replace(".", ",")))
				{
					if (name == "shift")
					{
						newValue = Decimal::Add(celldata, changer);						
					}
					if (name == "multiple")
					{
						newValue = Decimal::Multiply(celldata, changer);						
					}					
					if (name == "dB")
					{
						newValue = Convert::ToDecimal(20.0*log10(Convert::ToDouble(celldata)) / log10(exp(1)));						
					}
					if (name == "norm1")
					{
						newValue = Convert::ToDecimal(Convert::ToDouble(celldata) / maxValue);						
					}
					if (name == "round")
					{
						newValue = Decimal::Round(celldata, DecNum);						
					}					
					gform4->dataGridView1->Rows[i]->Cells[comboBox1->SelectedIndex + 1]->Value = newValue;
				}
			}
		}		
		//
		//	Вернуть начальные параметры ввода
		//
		textBox3->Text = "";
		TextValue = "";
		sign = true;
	}
	catch (System::Exception^)
	{
		MessageBox::Show("Unnown error", "Ошибка №1",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
		goto End;
	}
	//
	//	
	//	Блок 2. Мультифайловая обработка
	//
	//
	//
	if (checkBox3->Checked)
	{
		gform6 = gcnew Form6(gform4->gform1);
		gform6->ProcessBarInitialization(gform4->listBox1->Items->Count*2);

		for (int k = 0; k < gform4->listBox1->Items->Count; k++)
		{
			gform6->progressBar1->PerformStep();
			gform6->Show();
			//
			//	Н.у.
			//
			gform4->gform1->NumOflines = 0;
			gform4->gform1->NumOfColum = 0;
			gform4->gform1->NumOfDelim = 0;
			gform4->gform1->NumOfColum = 0;
			gform4->gform1->NewLineCount = 0;
			gform4->gform1->NSector = 1;
			gform4->gform1->boolean = false;
			gform4->gform1->exiting = false;
			gform4->gform1->skiplineCounter = 0;
			//gform4->gform1->skipline = false;
			gform4->gform1->noNumbers = false;
			//
			//	Чтение файла
			//
			String^ DataFilename;
			String^ TempFile = Path::Combine(TempDirectory, String::Concat(gform4->listBox1->Items[k]->ToString()->String::Remove(gform4->listBox1->Items[k]->ToString()->LastIndexOf(".")), ".mr"));
			if (File::Exists(TempFile))
			{
				DataFilename = TempFile;
			}
			else
			{
				DataFilename = Path::Combine(gform4->Foldername, gform4->listBox1->Items[k]->ToString());
			}
			gform4->gform1->PreReading(DataFilename);
			gform4->gform1->Reading(gform4->gform1->ReadlineMassive);
			//
			//	Найти максимум
			//
			if (name == "norm1")
			{
				FindMaximum(2);
			}			
			//
			//	Обработка и запись
			//
			for (int l = 0; l < gform4->gform1->NumOflines; l++)
			{
				celldata = Convert::ToDecimal(gform4->gform1->DataMassive[l][comboBox1->SelectedIndex]);
				if (radioButton1->Checked)
				{
					if (l >= Convert::ToInt32(textBox1->Text) - 1 && l <= Convert::ToInt32(textBox2->Text) - 1)
					{
						if (name == "shift")
						{
							newValue = Decimal::Add(celldata, changer);						
						}
						if (name == "multiple")
						{
							newValue = Decimal::Multiply(celldata, changer);							
						}						
						if (name == "dB")
						{
							newValue = Convert::ToDecimal(20.0*log10(Convert::ToDouble(celldata)) / log10(exp(1)));							
						}
						if (name == "norm1")
						{
							newValue = Convert::ToDecimal(Convert::ToDouble(celldata) / maxValue);							
						}
						if (name == "round")
						{
							newValue = Decimal::Round(celldata, DecNum);
						}						
						gform4->gform1->DataMassive[l][comboBox1->SelectedIndex] = Convert::ToDouble(newValue);
					}
				}
				if (radioButton2->Checked)
				{
					if (celldata >= Convert::ToDecimal(textBox1->Text->String::Replace(".", ",")) && celldata <= Convert::ToDecimal(textBox2->Text->String::Replace(".", ",")))
					{
						if (name == "shift")
						{
							newValue = Decimal::Add(celldata, changer);							
						}
						if (name == "multiple")
						{
							newValue = Decimal::Multiply(celldata, changer);							
						}						
						if (name == "dB")
						{
							newValue = Convert::ToDecimal(20.0*log10(Convert::ToDouble(celldata)) / log10(exp(1)));							
						}
						if (name == "norm1")
						{
							newValue = Convert::ToDecimal(Convert::ToDouble(celldata) / maxValue);							
						}
						if (name == "round")
						{
							newValue = Decimal::Round(celldata, DecNum);
						}						
						gform4->gform1->DataMassive[l][comboBox1->SelectedIndex] = Convert::ToDouble(newValue);
					}
				}
			}			
			SavingReductedData(k);			
		}
		gform6->progressBar1->PerformStep();
		gform6->Close();		
	}
	else
	{
		SavingReductedData(gform4->selectedFile - 1);
	}
	refreshrowvalues();
End: NULL;
	if (error)
	{
		error = false;
	}
}

System::Void Form5::FindMaximum(int t)
{
	maxValue = 0;
	if (t == 1)
	{
		double value = 0;
		for (int i = 0; i < gform4->numberOfDataRows; i++)
		{
			value = Convert::ToDouble(gform4->dataGridView1->Rows[i]->Cells[comboBox1->SelectedIndex + 1]->Value->ToString());
			if (radioButton1->Checked)
			{
				if (i >= Convert::ToInt32(textBox1->Text) - 1 && i <= Convert::ToInt32(textBox2->Text) - 1)
				{
					if (maxValue < abs(value))
					{
						maxValue = abs(value);
					}
				}
			}
			if (radioButton2->Checked)
			{
				if (celldata >= Convert::ToDecimal(textBox1->Text) && celldata <= Convert::ToDecimal(textBox2->Text))
				{
					if (maxValue < abs(value))
					{
						maxValue = abs(value);
					}
				}
			}
		}
	}
	if (t == 2)
	{
		double value = 0;
		for (int i = 0; i < gform4->gform1->NumOflines; i++)
		{
			value = Convert::ToDouble(gform4->gform1->DataMassive[i][comboBox1->SelectedIndex]);
			if (radioButton1->Checked)
			{
				if (i >= Convert::ToInt32(textBox1->Text) - 1 && i <= Convert::ToInt32(textBox2->Text) - 1)
				{
					if (maxValue < abs(value))
					{
						maxValue = abs(value);
					}
				}
			}
			if (radioButton2->Checked)
			{
				if (value >= Convert::ToDouble(textBox1->Text) && value <= Convert::ToDouble(textBox2->Text))
				{
					if (maxValue < abs(value))
					{
						maxValue = abs(value);
					}
				}
			}
		}
	}
}
}