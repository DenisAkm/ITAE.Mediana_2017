#include "Header.h"
#include "Form4.h"
#include "Form1.h"
#include "Form5.h"

namespace NewMediana
{
System::Void Form4::î÷èñòèòüÂñåToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	listBox1->Items->Clear();		
	dataGridView1->Rows->Clear();
	numberOfDataRows = 0;
	CreateAditionalEmptyRows();
}
System::Void Form4::âûõîäToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	Hide();
}
System::Void Form4::âûáðàòüÔàéëToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	openScenarios();
}

System::Void Form4::Form4_Load(System::Object^  sender, System::EventArgs^  e)
{
	RowsMaxNumber = 23;
	CreateAditionalEmptyRows();	
	maximum = false;
}
System::Void Form4::RefrechInfo(int i)
{
	dataGridView1->Rows->Clear();
	numberOfEmptyRows = 0;
	FileInfo = Path::Combine(Foldername, listBox1->Items[i]->ToString());
	//
	gform1->NumOflines = 0;
	gform1->NumOfColum = 0;
	gform1->NumOfDelim = 0;
	gform1->NumOfColum = 0;
	gform1->NewLineCount = 0;
	gform1->NSector = 1;
	gform1->boolean = false;
	gform1->exiting = false;
	gform1->skiplineCounter = 0;
	//gform1->skipline = false;
	gform1->noNumbers = false;
	gform1->skiplineCounter = 0;
	//
	gform1->PreReading(FileInfo);
	if (gform1->exiting)
	{
		goto End;
	}
	gform1->Reading(gform1->ReadlineMassive);
	//
	numberOfDataRows = gform1->NumOflines;
	for (int k = 0; k < numberOfDataRows; k++)
	{
		dataGridView1->Rows->Add();
		dataGridView1->Rows[k]->Cells[0]->Value = Convert::ToString(k + 1);

		for (int j = 0; j < gform1->NumOfColum; j++)
		{
			dataGridView1->Rows[k]->Cells[j + 1]->Value = Convert::ToDecimal(gform1->DataMassive[k][j]);
		}
	}
	CreateAditionalEmptyRows();
End: NULL;
}
System::Void Form4::listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{		
	if (!(listBox1->SelectedIndex == -1))
	{
		if (!(listBox1->SelectedIndex + 1 ==  selectedFile))
		{
			RefrechInfo(listBox1->SelectedIndex);
			selectedFile = listBox1->SelectedIndex + 1;
		}				
	}	
}

System::Void Form4::answer_Enter(System::Object^  sender, System::EventArgs^  e)
{	
}
System::Void Form4::deleteVariant(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if (e->Button == System::Windows::Forms::MouseButtons::Right)
	{
		int s = 0;
		if (!(listBox1->SelectedIndex == -1))
		{
			s = listBox1->SelectedIndex;
			listBox1->Items->RemoveAt(s);
			
			selectedFile = 0;
			numberOfDataRows = 0;
			CreateAditionalEmptyRows();
		}
	}
	dataGridView1->CurrentCell = dataGridView1->Rows[0]->Cells[1];
}
System::Void Form4::ColHeader_DClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e)
{
	int nonZeroCol = 0;
	for (int i = 1; i < dataGridView1->ColumnCount; i++)
	{
		String^ ds = dataGridView1->Rows[0]->Cells[i]->FormattedValue->ToString();
		if (!(ds == ""))
		{
			nonZeroCol++;
		}
	}
	if (e->ColumnIndex > nonZeroCol)
	{
		MessageBox::Show("Âûáðàíà ïóñòàÿ êîëîíêà", "Îøèáêà",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
		goto End;
	}
	reductedColumn = e->ColumnIndex;
	//
	// Open form5
	//
	try
	{
		if (e->ColumnIndex == gform5->comboBox1->SelectedIndex)
		{
			gform5->Show();
			gform5->Activate();
		}
		else
		{
			gform5 = gcnew Form5(this);
			gform5->Show();
		}
		
	}
	catch (System::ObjectDisposedException ^ )
	{
		gform5 = gcnew Form5(this);
		gform5->Show();
	}
	catch (System::NullReferenceException ^ )
	{
		gform5 = gcnew Form5(this);
		gform5->Show();
	}
	//
	//	Open form5
	//
	gform5->Text = String::Concat("Èçìåíåíèå Column", reductedColumn);
	gform5->comboBox1->Text = gform5->comboBox1->Items[e->ColumnIndex-1]->ToString();	
	gform5->refreshrowvalues();
	
End: NULL;
}
System::Void Form4::CreateAditionalEmptyRows()
{	
	if (numberOfDataRows == 0)
	{
		dataGridView1->Rows->Clear();
		for (int i = 0; i < RowsMaxNumber; i++)
		{
			dataGridView1->Rows->Add();
			dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(i + 1);
		}		
		numberOfEmptyRows = RowsMaxNumber;
	}
	else
	{
		while (numberOfEmptyRows>0)
		{
			dataGridView1->Rows->RemoveAt(numberOfDataRows + numberOfEmptyRows - 1);
			numberOfEmptyRows--;
		}
		if (numberOfDataRows < RowsMaxNumber)
		{
			numberOfEmptyRows = RowsMaxNumber - numberOfDataRows;
			for (int i = 0; i < numberOfEmptyRows; i++)
			{
				dataGridView1->Rows->Add();
				dataGridView1->Rows[numberOfDataRows + i]->Cells[0]->Value = Convert::ToString(numberOfDataRows + i + 1);
			}			
		}	
		else
		{	
			numberOfEmptyRows = 1;
			dataGridView1->Rows->Add();
			dataGridView1->Rows[numberOfDataRows]->Cells[0]->Value = Convert::ToString(numberOfDataRows+1);			
		}
	}
	dataGridView1->CurrentCell = dataGridView1->Rows[0]->Cells[1];
}
System::Void Form4::openDialog(System::Object^  sender, System::EventArgs^  e)
{
	if (listBox1->Items->Count == 0)
	{
		openScenarios();
	}	
}
System::Void Form4::openScenarios()
{
	Refresh = true;
	OpenFileDialog^ OpenFileDialog1 = gcnew OpenFileDialog;
	openFileDialog1->Filter = "Data Files(*.txt;*.dat)|*.txt;*.dat|All files (*.*)|*.*";
	openFileDialog1->Multiselect = true;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		listBox1->Items->Clear();
		//filelist = gcnew array<String^>(openFileDialog1->FileNames->Length);
		Foldername = openFileDialog1->FileNames[0]->ToString()->Remove(openFileDialog1->FileNames[0]->ToString()->LastIndexOf("\\"));
		for (int i = 0; i < openFileDialog1->FileNames->Length; i++)
		{
			listBox1->Items->Add(openFileDialog1->FileNames[i]->ToString()->Substring(openFileDialog1->FileNames[i]->ToString()->LastIndexOf("\\") + 1));
		}
	}

	if (listBox1->Items->Count == 1)
	{
		RefrechInfo(0);
		selectedFile = 1;
	}
	else
	{
		selectedFile = 0;
		numberOfDataRows = 0;
		CreateAditionalEmptyRows();
	}
}
System::Void Form4::resizing(System::Object^  sender, System::EventArgs^  e)
{
	if (maximum)
	{		
		maximum = false;
		RowsMaxNumber = 23;
		CreateAditionalEmptyRows();
	}
	else
	{			
		maximum = true;
		RowsMaxNumber = 43;
		CreateAditionalEmptyRows();
	}
	
}
}