#include "Header.h"
#include "Form2.h"
#include "Form1.h"


namespace NewMediana
{
	System::Void Form2::checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (checkBox3->Checked)
		{
			checkBox3->ForeColor = SystemColors::ControlText;
		}
		else
		{
			checkBox3->ForeColor = SystemColors::ControlDarkDark;
		}
	}
	System::Void Form2::checkBox6_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (checkBox6->Checked)
		{
			checkBox6->ForeColor = SystemColors::ControlText;
		}
		else
		{
			checkBox6->ForeColor = SystemColors::ControlDarkDark;
		}
	}
	System::Void Form2::checkBox11_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (checkBox11->Checked)
		{
			checkBox11->ForeColor = SystemColors::ControlText;
		}
		else
		{
			checkBox11->ForeColor = SystemColors::ControlDarkDark;
		}
	}
	System::Void Form2::checkBox12_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (checkBox12->Checked)
		{
			checkBox12->ForeColor = SystemColors::ControlText;
		}
		else
		{
			checkBox12->ForeColor = SystemColors::ControlDarkDark;
		}
	}
	System::Void Form2::checkBox7_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (checkBox7->Checked)
		{
			checkBox7->ForeColor = SystemColors::ControlText;
			if (!(checkBox8->Checked))
			{
				//checkBox5->Enabled = true;
			}
		}
		else
		{
			checkBox7->ForeColor = SystemColors::ControlDarkDark;
			if (!(checkBox8->Checked))
			{
				//checkBox5->Enabled = false;
			}
		}
	}
	System::Void Form2::checkBox8_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (checkBox8->Checked)
		{
			checkBox8->ForeColor = SystemColors::ControlText;			
		}
		else
		{
			checkBox8->ForeColor = SystemColors::ControlDarkDark;			
		}
	}
	System::Void Form2::checkBox9_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (checkBox9->Checked)
		{
			checkBox9->ForeColor = SystemColors::ControlText;
		}
		else
		{
			checkBox9->ForeColor = SystemColors::ControlDarkDark;
		}
	}
	System::Void Form2::checkBox5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) //radioButton1_CheckedChanged
	{		
		if (radioButton1->Checked)
		{
			checkBox3->Enabled = true;
			checkBox6->Enabled = true;

			checkBox11->Enabled = true;
			checkBox12->Enabled = true;

			checkBox7->Enabled = true;
			checkBox8->Enabled = true;
			checkBox9->Enabled = false;

			if (!(checkBox4->Enabled))
			{
				checkBox4->Enabled = true;
				checkBox4->Checked = PreviousCheckBox4State;
			}
		}				
	}
	System::Void Form2::checkBox10_CheckedChanged(System::Object^  sender, System::EventArgs^  e)	//radioButton2_CheckedChanged
	{		
		if (radioButton2->Checked)
		{
			checkBox3->Enabled = true;
			checkBox6->Enabled = true;

			checkBox11->Enabled = true;
			checkBox12->Enabled = true;

			checkBox7->Enabled = true;
			checkBox8->Enabled = true;
			checkBox9->Enabled = true;

			if (!(checkBox4->Enabled))
			{
				checkBox4->Enabled = true;
				checkBox4->Checked = PreviousCheckBox4State;
			}
		}
	}
	System::Void Form2::radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{		
		if (radioButton3->Checked)
		{
			checkBox3->Enabled = true;
			checkBox6->Enabled = true;

			checkBox11->Enabled = true;
			checkBox12->Enabled = true;

			checkBox7->Enabled = false;
			checkBox8->Enabled = false;
			checkBox9->Enabled = false;

			PreviousCheckBox4State = checkBox4->Checked;
			checkBox4->Checked = true;
			checkBox4->Enabled = false;
		}		
	}
	System::Void Form2::numericUpDownRound_ValueChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (numericUpDownRound->Value > 6)
		{
			numericUpDownRound->BackColor = Color::OrangeRed;
		}
		if (numericUpDownRound->Value <= 6)
		{
			numericUpDownRound->BackColor = SystemColors::Window;
		}
	}
	System::Void Form2::checkBox5_CheckedChanged_1(System::Object^  sender, System::EventArgs^  e) 
	{
		if (checkBox5->Checked)
		{
			numericUpDown1->Enabled = true;
			gform1->allowskip = true;
		}
		else
		{
			numericUpDown1->Enabled = false;
			gform1->allowskip = false;
		}
		if (gform1->ïîñòðîèòüToolStripMenuItem->Checked&&!(gform1->listBox1->Items->Count == 0))
		{
			gform1->BufferData();
			if (gform1->exiting)
			{
				goto End;
			}
			gform1->GraphCompiler(gform1->DataMassive);
			gform1->DrawCompiler(gform1->DataMassive);
		} 
	End: NULL;
	}
	System::Void Form2::allowValue_change(System::Object^  sender, System::EventArgs^  e)
	{
		
		gform1->numberOfskip = Convert::ToInt32(numericUpDown1->Value);
		if (gform1->ïîñòðîèòüToolStripMenuItem->Checked&& !(gform1->listBox1->Items->Count == 0))
		{
			gform1->BufferData();
			if (gform1->exiting)
			{
				goto End;
			}
			gform1->GraphCompiler(gform1->DataMassive);
			gform1->DrawCompiler(gform1->DataMassive);
		}
	End: NULL;
	}
}

