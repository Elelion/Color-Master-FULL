//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormResize(TObject *Sender)
{
	//��������� ����������������� ����������� ����
	Panel6->Position->X = Form3->Width - Panel6->Width - 20;

	//������������� ���������� ������ ����������� ����
	ImgBtn1->Position->X = Panel1->Width - 46;
	ImgBtn1->Position->Y = 0;

	ImgBtn2->Position->X = ImgBtn1->Position->X;
	ImgBtn2->Position->Y = ImgBtn1->Position->Y;

	ImgBtn3->Position->X = Panel1->Width - 96;
	ImgBtn3->Position->Y = 0;

//---

	//������������� ������ �������� ����� / ������ (������ / �����)
	BtnLeft->Position->X = 0;
	BtnLeftPrs->Position->X = 0;
	BtnRight->Position->X = Rectangle1->Width - BtnRight->Width + 2;
	BtnRightPrs->Position->X = Rectangle1->Width - BtnRight->Width + 2;

	BtnLeft->Position->Y = Rectangle1->Height / 2 + 26;
	BtnLeftPrs->Position->Y = Rectangle1->Height / 2 + 26; //, ��� +24 - ��� ����� "������"
	BtnRight->Position->Y = Rectangle1->Height / 2 + 26;
	BtnRightPrs->Position->Y = Rectangle1->Height / 2 + 26;

	//�������� RoundRect, ��� �� �� ����� ��� ����� ��� �� ��������
	RoundRect1->Position->X = -38;
	RoundRect2->Position->X = -38;
	RoundRect1->Position->Y = Rectangle1->Height / 2;
	RoundRect2->Position->Y = Rectangle1->Height / 2;

	RoundRect3->Position->X = Rectangle1->Width - 38;
	RoundRect4->Position->X = Rectangle1->Width - 38; //, ��� -28 - ��� ����� "������"
	RoundRect3->Position->Y = Rectangle1->Height / 2;
	RoundRect4->Position->Y = Rectangle1->Height / 2;

//---

	//������������� ������ Label'�
	Label1->Width = Panel1->Width - ImgBtn1->Width - ImgBtn3->Width - Rectangle4->Width;

	Label2->Position->X = 0;
	Label3->Position->X = Label2->Width;

	Label4->Position->X = Panel2->Width - Label5->Width - Label4->Width;
	Label5->Position->X = Panel2->Width - Label5->Width;

	Label6->Position->X = 0;
	Label7->Position->X = Label6->Width;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
//		Panel6->Visible = false;

		//���� ����������� ����� label'��, ������� ���������� ����� ���������
//		FullName1->Text = buf1->Text;
//		FullName2->Text = buf1->Text;

		//������ ������� ����, ������ ����� ��� ���� �� �����
//		Rectangle2->Fill->Color = MakeColor(9, 145, 167);
//		Rectangle3->Fill->Color = MakeColor(9, 145, 167);

//		ImgBtn3->Visible = false;

//		ImgBtn1->Visible = true;
//		ImgBtn2->Visible = false;
							 /*
		Form1->ListBox1->ItemIndex = -1;
		Form1->LB2_MainColors->ItemIndex = -1;
		Form1->LB3_RedColors->ItemIndex = -1;
		Form1->LB4_GreenColors->ItemIndex = -1;
		Form1->LB5_BlueColors->ItemIndex = -1;
		Form1->LB6_PinkColors->ItemIndex = -1;
		Form1->LB7_OrangeColors->ItemIndex = -1;
		Form1->LB8_YellowColors->ItemIndex = -1;
		Form1->LB9_VioletColors->ItemIndex = -1;
		Form1->LB10_BrownColors->ItemIndex = -1;
		Form1->LB11_WhiteColors->ItemIndex = -1;
		Form1->LB12_GreyColors->ItemIndex = -1; */
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button5Click(TObject *Sender)
{
//������� ����
	if(Button5->StyleLookup == "additembutton")
	{   	            //buf1->Text == "��������� �� ������"
		if(FullName2->Text == buf1->Text && FullName1->Text != buf1->Text) //���� ����������� ����� �� ����
		{
			ImgBtn3->Visible = true; //����������, ���� ������ ��� �����, �� ���������� ������
		}

		else //���� ���, �� ������
		{
			ImgBtn3->Visible = false;
		}

		Button5->StyleLookup = "deleteitembutton";
		FullName2->Text = Label1->Text;
		Rectangle3->Fill->Color = Rectangle1->Fill->Color;

		//��������� ����� �� Form4 ��� ��������� ���������
		Form2->Label2->Text = Label1->Text; //��������
		Form2->Label6->Text = Label7->Text; //Name
		Form2->Label7->Text = Label3->Text;	//RGB
		Form2->Label8->Text = Label5->Text; //HTNL

		//���� �������� ���� ��� ������� ����� �� ������
		if(Label7->Text == "AntiqueWhite" || Label7->Text == "AntiqueWhite2" || Label7->Text == "AntiqueWhite3" ||
		   Label7->Text == "Azure" || Label7->Text == "Azure2" || Label7->Text == "Azure3" || Label7->Text == "claWhite" ||
		   Label7->Text == "Beige" || Label7->Text == "FloralWhite" || Label7->Text == "GhostWhite" || Label7->Text == "Honeydew" ||
		   Label7->Text == "Honeydew2" || Label7->Text == "Honeydew3" || Label7->Text == "Ivory" || Label7->Text == "Ivory2" ||
		   Label7->Text == "Ivory3" || Label7->Text == "LavenderBlush" || Label7->Text == "LavenderBlush2" || Label7->Text == "LavenderBlush3" ||
		   Label7->Text == "Linen" || Label7->Text == "MintCream" || Label7->Text == "MistyRose" || Label7->Text == "MistyRose2" ||
		   Label7->Text == "MistyRose3" || Label7->Text == "OldLace" || Label7->Text == "Seashell" || Label7->Text == "Seashell2" ||
		   Label7->Text == "Seashell3" || Label7->Text == "Snow" || Label7->Text == "Snow2" || Label7->Text == "Snow3" ||
		   Label7->Text == "White" || Label7->Text == "WhiteSmoke" || //���� ���� �� ���� ��������
		   Label7->Text == "AliceBlue" || Label7->Text == "PaleTurquoise" || Label7->Text == "CadetBlue2" || Label7->Text == "LightBlue2" ||
		   Label7->Text == "LightYellow" || Label7->Text == "LightYellow2" || Label7->Text == "PapayaWhip" || Label7->Text == "Lavender" ||
		   Label7->Text == "Gainsboro" || Label7->Text == "Grey91" || Label7->Text == "Grey81" || Label7->Text == "LightCyan" ||
		   Label7->Text == "LightCyan2" || Label7->Text == "" || Label7->Text == "" || Label7->Text == "" || Label7->Text == "BlanchedAlmond" ||
		   Label7->Text == "Cornsilk2" || Label7->Text == "Cornsilk")
		{
			FullName2->Visible = false;
			FullName2Color->Visible = true;
			FullName2Color->Text = Label1->Text;
		}
		//� ��� ���������� ����� �� ����� ����
		else
		{
			FullName2->Visible = true;
			FullName2Color->Visible = false;
		}
	}

//�������� ����
	else
	{                    //buf2->Text == "�� �����"
		if(FullName2->Text == buf1->Text && FullName1->Text != buf1->Text) //���� ����������� ����� �� ����
		{
			ImgBtn3->Visible = true; //����������, ���� ������ ��� �����, �� ���������� ������
		}

		else //���� ���, �� ������
		{
			ImgBtn3->Visible = false;
		}

		FullName2->Visible = true;
		Button5->StyleLookup = "additembutton";
		Rectangle3->Fill->Color = MakeColor(9, 145, 167);

		FullName2->Text = buf1->Text;

		//���������� ����������� ����
		FullName2->Visible = true;
		FullName2Color->Visible = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ImgBtn1Click(TObject *Sender)
{
//��������� ������
	if(Panel6->Visible == false)
	{
		//���� ����������� ����� label'��, ������� ���������� ����� ���������
		FullName1->Text = buf1->Text;
		FullName1->Position->X = 8;
		FullName1Color->Position->X = 8;
		FullName1->Position->Y = 0;
		FullName1Color->Position->Y = 0;

		FullName2->Text = buf1->Text;
		FullName2->Position->X = 8;
		FullName2Color->Position->X = 8;
		FullName2->Position->Y = 0;
		FullName2Color->Position->Y = 0;

		//������ ��������� � ����
		Button4->StyleLookup = "additembutton";
		Button5->StyleLookup = "additembutton";

		//����������� ������ ���� � ����������
		Panel6->Width = 185;
		Panel6->Position->X = Form3->Width - Panel6->Width - 20; //������ ������ �� ������� ����

		Rectangle2->Width = 187;
		Rectangle2->Position->X = 0;
		Rectangle2->Fill->Color = MakeColor(9, 145, 167);

		Rectangle3->Width = 187;
		Rectangle3->Position->X = 0;
		Rectangle3->Fill->Color = MakeColor(9, 145, 167);

		//������ �������� ����������
		Panel6->Visible = true;
		FullName1->Visible = true;
		FullName2->Visible = true;

		ImgBtn1->Visible = false;
		ImgBtn2->Visible = true;

		//���������� ����������� ����
		FullName1->Visible = true;
		FullName1Color->Visible = false;

		FullName2->Visible = true;
		FullName2Color->Visible = false;
	}

//������� ������
	else
	{
		Panel6->Visible = false;

		//���� ����������� ����� label'��, ������� ���������� ����� ���������
		FullName1->Text = buf1->Text;
		FullName2->Text = buf1->Text;

		//������ ������� ����, ������ ����� ��� ���� �� �����
		Rectangle2->Fill->Color = MakeColor(9, 145, 167);
		Rectangle3->Fill->Color = MakeColor(9, 145, 167);

		ImgBtn3->Visible = false;

		ImgBtn1->Visible = true;
		ImgBtn2->Visible = false;

		//���������� ����������� ����
		FullName1->Visible = true;
		FullName1Color->Visible = false;

		FullName2->Visible = true;
		FullName2Color->Visible = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender)
{
//����������� ������ (��������)
	ImgBtn1->Position->X = Panel1->Width - 46;
	ImgBtn1->Position->Y = 0;

	ImgBtn2->Position->X = ImgBtn1->Position->X;
	ImgBtn2->Position->Y = ImgBtn1->Position->Y;

	ImgBtn3->Position->X = Panel1->Width - 96;
	ImgBtn3->Position->Y = 0;

//����������� ���������
	Label2->Position->X = 0;
	Label3->Position->X = Label2->Width;

	Label5->Position->X = Panel2->Width - Label5->Width;
	Label4->Position->X = Panel2->Width - Label5->Width - Label4->Width;

	Label6->Position->X = 0;
	Label7->Position->X = Label6->Width;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button4Click(TObject *Sender)
{
//������� ����
	if(Button4->StyleLookup == "additembutton")
	{                   //buf2->Text == "�� �����"
		if(FullName1->Text == buf1->Text && FullName2->Text != buf1->Text) //���� ����������� ����� �� ����
		{
			ImgBtn3->Visible = true; //����������, ���� ������ ��� �����, �� ���������� ������
		}

		else
		{
			ImgBtn3->Visible = false; //���� ���, �� ������
		}

		Button4->StyleLookup = "deleteitembutton";

		FullName1->Text = Label1->Text;

		Rectangle2->Fill->Color = Rectangle1->Fill->Color;

		//��������� ����� �� Form4 ��� ��������� ���������
		Form2->Label1->Text = Label1->Text; //��������
		Form2->Label3->Text = Label7->Text; //Name
		Form2->Label4->Text = Label3->Text;	//RGB
		Form2->Label5->Text = Label5->Text; //HTNL

		//���� �������� ���� ��� ������� ����� �� ������
		if(Label7->Text == "AntiqueWhite" || Label7->Text == "AntiqueWhite2" || Label7->Text == "AntiqueWhite3" ||
		   Label7->Text == "Azure" || Label7->Text == "Azure2" || Label7->Text == "Azure3" || Label7->Text == "claWhite" ||
		   Label7->Text == "Beige" || Label7->Text == "FloralWhite" || Label7->Text == "GhostWhite" || Label7->Text == "Honeydew" ||
		   Label7->Text == "Honeydew2" || Label7->Text == "Honeydew3" || Label7->Text == "Ivory" || Label7->Text == "Ivory2" ||
		   Label7->Text == "Ivory3" || Label7->Text == "LavenderBlush" || Label7->Text == "LavenderBlush2" || Label7->Text == "LavenderBlush3" ||
		   Label7->Text == "Linen" || Label7->Text == "MintCream" || Label7->Text == "MistyRose" || Label7->Text == "MistyRose2" ||
		   Label7->Text == "MistyRose3" || Label7->Text == "OldLace" || Label7->Text == "Seashell" || Label7->Text == "Seashell2" ||
		   Label7->Text == "Seashell3" || Label7->Text == "Snow" || Label7->Text == "Snow2" || Label7->Text == "Snow3" ||
		   Label7->Text == "White" || Label7->Text == "WhiteSmoke" || //���� ���� �� ���� ��������
		   Label7->Text == "AliceBlue" || Label7->Text == "PaleTurquoise" || Label7->Text == "CadetBlue2" || Label7->Text == "LightBlue2" ||
		   Label7->Text == "LightYellow" || Label7->Text == "LightYellow2" || Label7->Text == "PapayaWhip" || Label7->Text == "Lavender" ||
		   Label7->Text == "Gainsboro" || Label7->Text == "Grey91" || Label7->Text == "Grey81" || Label7->Text == "LightCyan" ||
		   Label7->Text == "LightCyan2" || Label7->Text == "" || Label7->Text == "" || Label7->Text == "" || Label7->Text == "BlanchedAlmond" ||
		   Label7->Text == "Cornsilk2" || Label7->Text == "Cornsilk")
		{
			FullName1->Visible = false;
			FullName1Color->Visible = true;
			FullName1Color->Text = Label1->Text;
		}
		//� ��� ���������� ����� �� ����� ����
		else
		{
			FullName1->Visible = true;
			FullName1Color->Visible = false;
		}
	}

//�������� ����
	else
	{                   //buf2->Text == "�� �����"
		if(FullName1->Text == buf1->Text && FullName2->Text != buf1->Text) //���� ����������� ����� �� ����
		{
			ImgBtn3->Visible = true; //����������, ���� ������ ��� �����, �� ���������� ������
		}

		else
		{
			ImgBtn3->Visible = false; //���� ���, �� ������
		}

		FullName1->Visible = true;
		Button4->StyleLookup = "additembutton";

		Rectangle2->Fill->Color = MakeColor(9, 145, 167);

		FullName1->Text = buf1->Text;

		//���������� ����������� ����
		FullName1->Visible = true;
		FullName1Color->Visible = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ImgBtn3Click(TObject *Sender)
{
	Form2->Rectangle1->Fill->Color = Rectangle2->Fill->Color;
	Form2->Rectangle2->Fill->Color = Rectangle3->Fill->Color;

	Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Timer1Timer(TObject *Sender)
{
//������ ������ BtnLeft ����� �� �������
	RoundRect1->Visible = true;
	RoundRect2->Visible = false;
	BtnLeft->Visible = true;
	BtnLeftPrs->Visible = false;

	Timer1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Timer2Timer(TObject *Sender)
{
//������ ������ BtnRight ����� �� �������
	RoundRect3->Visible = true;
	RoundRect4->Visible = false;
	BtnRight->Visible = true;
	BtnRightPrs->Visible = false;

	Timer2->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::BtnLeftClick(TObject *Sender)
{
//buf2->Text = buf2->Text.ToInt() - 1; -->> ��������� ������� �������� ������� buf2 �� 1 (�.�. -1)
//� ����������� ListBox, LB2...12, ��� ����������� �������� �� ��������, ��� ����
	if(Form1->ListBox1->Visible == true && buf2->Text.ToInt() > 0) //0 ����� ������ (�������) item
	{
		buf2->Text = buf2->Text.ToInt() - 1;
		Form1->ListBox1->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB2_MainColors->Visible == true && buf2->Text.ToInt() > 0)
	{
		buf2->Text = buf2->Text.ToInt() - 1;
		Form1->LB2_MainColors->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB3_RedColors->Visible == true && buf2->Text.ToInt() > 0)
	{
		buf2->Text = buf2->Text.ToInt() - 1;
		Form1->LB3_RedColors->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB4_GreenColors->Visible == true && buf2->Text.ToInt() > 0)
	{
		buf2->Text = buf2->Text.ToInt() - 1;
		Form1->LB4_GreenColors->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB5_BlueColors->Visible == true && buf2->Text.ToInt() > 0)
	{
		buf2->Text = buf2->Text.ToInt() - 1;
		Form1->LB5_BlueColors->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB6_PinkColors->Visible == true && buf2->Text.ToInt() > 0)
	{
		buf2->Text = buf2->Text.ToInt() - 1;
		Form1->LB6_PinkColors->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB7_OrangeColors->Visible == true && buf2->Text.ToInt() > 0)
	{
		buf2->Text = buf2->Text.ToInt() - 1;
		Form1->LB7_OrangeColors->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB8_YellowColors->Visible == true && buf2->Text.ToInt() > 0)
	{
		buf2->Text = buf2->Text.ToInt() - 1;
		Form1->LB8_YellowColors->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB9_VioletColors->Visible == true && buf2->Text.ToInt() > 0)
	{
		buf2->Text = buf2->Text.ToInt() - 1;
		Form1->LB9_VioletColors->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB10_BrownColors->Visible == true && buf2->Text.ToInt() > 0)
	{
		buf2->Text = buf2->Text.ToInt() - 1;
		Form1->LB10_BrownColors->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB11_WhiteColors->Visible == true && buf2->Text.ToInt() > 0)
	{
		buf2->Text = buf2->Text.ToInt() - 1;
		Form1->LB11_WhiteColors->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB12_GreyColors->Visible == true && buf2->Text.ToInt() > 0)
	{
		buf2->Text = buf2->Text.ToInt() - 1;
		Form1->LB12_GreyColors->ItemIndex = buf2->Text.ToInt();
	}
//������ ������ BtnLeft �������
	RoundRect1->Visible = false;
	RoundRect2->Visible = true;
	BtnLeft->Visible = false;
	BtnLeftPrs->Visible = true;

	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::BtnRightClick(TObject *Sender)
{
//buf2->Text = buf2->Text.ToInt() + 1; -->> ����������� ������� �������� ������� buf2 �� 1 (�.�. +1)
//� ����������� ListBox, LB2...12, ��� ����������� �������� �� ��������, ��� ����
	if(Form1->ListBox1->Visible == true && buf2->Text.ToInt() < Form1->ListBox1->Count -1) //-1 ��� �� �� ���� ��������� �� �� ���. item
	{
		buf2->Text = buf2->Text.ToInt() + 1;
		Form1->ListBox1->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB2_MainColors->Visible == true && buf2->Text.ToInt() < Form1->LB2_MainColors->Count -1)
	{
		buf2->Text = buf2->Text.ToInt() + 1;
		Form1->LB2_MainColors->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB3_RedColors->Visible == true && buf2->Text.ToInt() < Form1->LB3_RedColors->Count -1)
	{
		buf2->Text = buf2->Text.ToInt() + 1;
		Form1->LB3_RedColors->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB4_GreenColors->Visible == true && buf2->Text.ToInt() < Form1->LB4_GreenColors->Count -1)
	{
		buf2->Text = buf2->Text.ToInt() + 1;
		Form1->LB4_GreenColors->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB5_BlueColors->Visible == true && buf2->Text.ToInt() < Form1->LB5_BlueColors->Count -1)
	{
		buf2->Text = buf2->Text.ToInt() + 1;
		Form1->LB5_BlueColors->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB6_PinkColors->Visible == true && buf2->Text.ToInt() < Form1->LB6_PinkColors->Count -1)
	{
		buf2->Text = buf2->Text.ToInt() + 1;
		Form1->LB6_PinkColors->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB7_OrangeColors->Visible == true && buf2->Text.ToInt() < Form1->LB7_OrangeColors->Count -1)
	{
		buf2->Text = buf2->Text.ToInt() + 1;
		Form1->LB7_OrangeColors->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB8_YellowColors->Visible == true && buf2->Text.ToInt() < Form1->LB8_YellowColors->Count -1)
	{
		buf2->Text = buf2->Text.ToInt() + 1;
		Form1->LB8_YellowColors->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB9_VioletColors->Visible == true && buf2->Text.ToInt() < Form1->LB9_VioletColors->Count -1)
	{
		buf2->Text = buf2->Text.ToInt() + 1;
		Form1->LB9_VioletColors->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB10_BrownColors->Visible == true && buf2->Text.ToInt() < Form1->LB10_BrownColors->Count -1)
	{
		buf2->Text = buf2->Text.ToInt() + 1;
		Form1->LB10_BrownColors->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB11_WhiteColors->Visible == true && buf2->Text.ToInt() < Form1->LB11_WhiteColors->Count -1)
	{
		buf2->Text = buf2->Text.ToInt() + 1;
		Form1->LB11_WhiteColors->ItemIndex = buf2->Text.ToInt();
	}

	if(Form1->LB12_GreyColors->Visible == true && buf2->Text.ToInt() < Form1->LB12_GreyColors->Count -1)
	{
		buf2->Text = buf2->Text.ToInt() + 1;
		Form1->LB12_GreyColors->ItemIndex = buf2->Text.ToInt();
	}

//������ ������ BtnRight �������
	RoundRect3->Visible = false;
	RoundRect4->Visible = true;
	BtnRight->Visible = false;
	BtnRightPrs->Visible = true;

	Timer2->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ImgBtn2Click(TObject *Sender)
{
//��������� ������
	if(Panel6->Visible == false)
	{
		//���� ����������� ����� label'��, ������� ���������� ����� ���������
		FullName1->Text = buf1->Text;
		FullName1->Position->X = 8;
		FullName1->Position->Y = 0;

		FullName2->Text = buf1->Text;
		FullName2->Position->X = 8;
		FullName2->Position->Y = 0;

		//������ ��������� � ����
		Button4->StyleLookup = "additembutton";
		Button5->StyleLookup = "additembutton";

		//����������� ������ ���� � ����������
		Panel6->Width = 185;
		Panel6->Position->X = Form3->Width - Panel6->Width - 20; //������ ������ �� ������� ����

		Rectangle2->Width = 187;
		Rectangle2->Position->X = 0;
		Rectangle2->Fill->Color = MakeColor(9, 145, 167);

		Rectangle3->Width = 187;
		Rectangle3->Position->X = 0;
		Rectangle3->Fill->Color = MakeColor(9, 145, 167);

		//������ �������� ����������
		Panel6->Visible = true;
		FullName1->Visible = true;
		FullName2->Visible = true;

		ImgBtn1->Visible = false;
		ImgBtn2->Visible = true;
	}

//������� ������
	else
	{
		Panel6->Visible = false;

		//���� ����������� ����� label'��, ������� ���������� ����� ���������
		FullName1->Text = buf1->Text;
		FullName2->Text = buf1->Text;

		//������ ������� ����, ������ ����� ��� ���� �� �����
		Rectangle2->Fill->Color = MakeColor(9, 145, 167);
		Rectangle3->Fill->Color = MakeColor(9, 145, 167);

		ImgBtn3->Visible = false;

		ImgBtn1->Visible = true;
		ImgBtn2->Visible = false;
	}
}
//---------------------------------------------------------------------------
