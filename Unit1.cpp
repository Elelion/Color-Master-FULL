//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;

void ResetLBI()
{
//Присваиваем индекс выделенного элемента (для перелистывания с Form3)
	if(Form1->ListBox1->Visible == true)			{	Form3->buf2->Text = Form1->ListBox1->ItemIndex;				}
	if(Form1->LB2_MainColors->Visible == true)		{	Form3->buf2->Text = Form1->LB2_MainColors->ItemIndex;		}
	if(Form1->LB3_RedColors->Visible == true)		{	Form3->buf2->Text = Form1->LB3_RedColors->ItemIndex;		}
	if(Form1->LB4_GreenColors->Visible == true)		{	Form3->buf2->Text = Form1->LB4_GreenColors->ItemIndex;		}
	if(Form1->LB5_BlueColors->Visible == true)		{	Form3->buf2->Text = Form1->LB5_BlueColors->ItemIndex;		}
	if(Form1->LB6_PinkColors->Visible == true)		{	Form3->buf2->Text = Form1->LB6_PinkColors->ItemIndex;		}
	if(Form1->LB7_OrangeColors->Visible == true)	{	Form3->buf2->Text = Form1->LB7_OrangeColors->ItemIndex;		}
	if(Form1->LB8_YellowColors->Visible == true)	{	Form3->buf2->Text = Form1->LB8_YellowColors->ItemIndex;		}
	if(Form1->LB9_VioletColors->Visible == true)	{	Form3->buf2->Text = Form1->LB9_VioletColors->ItemIndex;		}
	if(Form1->LB10_BrownColors->Visible == true)	{	Form3->buf2->Text = Form1->LB10_BrownColors->ItemIndex;		}
	if(Form1->LB11_WhiteColors->Visible == true)	{	Form3->buf2->Text = Form1->LB11_WhiteColors->ItemIndex;		}
	if(Form1->LB12_GreyColors->Visible == true)		{	Form3->buf2->Text = Form1->LB12_GreyColors->ItemIndex;		}

//Сброс ВСЕХ ListBox's (ListBox1, LB2,...12)
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
	Form1->LB12_GreyColors->ItemIndex = -1;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	ListBox1->Visible = true; //Отображаем главную цветовую панель, остальные скрываем
	LB2_MainColors->Visible = 	false;
	LB3_RedColors->Visible = 	false;
	LB4_GreenColors->Visible = 	false;
	LB5_BlueColors->Visible = 	false;
	LB6_PinkColors->Visible = 	false;
	LB7_OrangeColors->Visible = false;
	LB8_YellowColors->Visible = false;
	LB9_VioletColors->Visible = false;
	LB10_BrownColors->Visible = false;
	LB11_WhiteColors->Visible = false;
	LB12_GreyColors->Visible = 	false;

	Form1->Panel2->Visible = false;
	Form1->Label3->Text = Menu1->Text;

	//Выравниваем заголовок
	Form1->Label1->Position->X = 17;
	Form1->Label3->Position->X = Label1->Width + 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormResize(TObject *Sender)
{
	Panel2->Visible = false;

	Label1->Position->X = 10;
	Label1->Position->Y = 12;

//Позиционируем кнопку меню
	ImgBtn6->Position->X = Panel1->Width - ImgBtn6->Width;
	ImgBtn5->Position->X = Panel1->Width - ImgBtn5->Width;

//Позиционируем кнопку вверх
	ImgBtn4->Position->X = Panel1->Width - ImgBtn4->Width * 2; //46 + 46(кнопка меню)
	ImgBtn3->Position->X = Panel1->Width - ImgBtn3->Width * 2;

//Позиционируем кнопку вниз
	ImgBtn2->Position->X = Panel1->Width - ImgBtn2->Width * 3; //46 + 46(кнопка меню) + 46(кнопка вверх)
	ImgBtn1->Position->X = Panel1->Width - ImgBtn1->Width * 3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	Timer1->Enabled = false;

	ImgBtn1->Visible = true;
	ImgBtn2->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ImgBtn1Click(TObject *Sender)
{
	TimerSelect->Enabled = false; //Что бы не было события OnClick при Select

	Timer1->Enabled = true;
	ImgBtn1->Visible = false;
	ImgBtn2->Visible = true;

	if(ListBox1->Visible == true)
	{
		ListBox1->ItemIndex = ListBox1->Count -1;
		ListBox1->ItemIndex = -1;
	}

	if(LB2_MainColors->Visible == true)
	{
		LB2_MainColors->ItemIndex = LB2_MainColors->Count -1;
		LB2_MainColors->ItemIndex = -1;
	}

	if(LB3_RedColors->Visible == true)
	{
		LB3_RedColors->ItemIndex = LB3_RedColors->Count -1;
		LB3_RedColors->ItemIndex = -1;
	}

	if(LB4_GreenColors->Visible == true)
	{
		LB4_GreenColors->ItemIndex = LB4_GreenColors->Count -1;
		LB4_GreenColors->ItemIndex = -1;
	}

	if(LB5_BlueColors->Visible == true)
	{
		LB5_BlueColors->ItemIndex = LB5_BlueColors->Count -1;
		LB5_BlueColors->ItemIndex = -1;
	}

	if(LB6_PinkColors->Visible == true)
	{
		LB6_PinkColors->ItemIndex = LB6_PinkColors->Count -1;
		LB6_PinkColors->ItemIndex = -1;
	}

	if(LB7_OrangeColors->Visible == true)
	{
		LB7_OrangeColors->ItemIndex = LB7_OrangeColors->Count -1;
		LB7_OrangeColors->ItemIndex = -1;
	}

	if(LB8_YellowColors->Visible == true)
	{
		LB8_YellowColors->ItemIndex = LB8_YellowColors->Count -1;
		LB8_YellowColors->ItemIndex = -1;
	}

	if(LB9_VioletColors->Visible == true)
	{
		LB9_VioletColors->ItemIndex = LB9_VioletColors->Count -1;
		LB9_VioletColors->ItemIndex = -1;
	}

	if(LB10_BrownColors->Visible == true)
	{
		LB10_BrownColors->ItemIndex = LB10_BrownColors->Count -1;
		LB10_BrownColors->ItemIndex = -1;
	}

	if(LB11_WhiteColors->Visible == true)
	{
		LB11_WhiteColors->ItemIndex = LB11_WhiteColors->Count -1;
		LB11_WhiteColors->ItemIndex = -1;
	}

	if(LB12_GreyColors->Visible == true)
	{
		LB12_GreyColors->ItemIndex = LB12_GreyColors->Count -1;
		LB12_GreyColors->ItemIndex = -1;
	}

	Panel2->Visible = false;
	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;

	TimerSelect->Enabled = true; //Включаем обработчик события OnClick при Select
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ImgBtn3Click(TObject *Sender)
{
	TimerSelect->Enabled = false; //Что бы не было события OnClick при Select

	Timer2->Enabled = true;
	ImgBtn3->Visible = false;
	ImgBtn4->Visible = true;

	if(ListBox1->Visible == true)
	{
		ListBox1->ItemIndex = 0;
		ListBox1->ItemIndex = -1;
	}

	if(LB2_MainColors->Visible == true)
	{
		LB2_MainColors->ItemIndex = 0;
		LB2_MainColors->ItemIndex = -1;
	}

	if(LB3_RedColors->Visible == true)
	{
		LB3_RedColors->ItemIndex = 0;
		LB3_RedColors->ItemIndex = -1;
	}

	if(LB4_GreenColors->Visible == true)
	{
		LB4_GreenColors->ItemIndex = 0;
		LB4_GreenColors->ItemIndex = -1;
	}

	if(LB5_BlueColors->Visible == true)
	{
		LB5_BlueColors->ItemIndex = 0;
		LB5_BlueColors->ItemIndex = -1;
	}

	if(LB6_PinkColors->Visible == true)
	{
		LB6_PinkColors->ItemIndex = 0;
		LB6_PinkColors->ItemIndex = -1;
	}

	if(LB7_OrangeColors->Visible == true)
	{
		LB7_OrangeColors->ItemIndex = 0;
		LB7_OrangeColors->ItemIndex = -1;
	}

	if(LB8_YellowColors->Visible == true)
	{
		LB8_YellowColors->ItemIndex = 0;
		LB8_YellowColors->ItemIndex = -1;
	}

	if(LB9_VioletColors->Visible == true)
	{
		LB9_VioletColors->ItemIndex = 0;
		LB9_VioletColors->ItemIndex = -1;
	}

	if(LB10_BrownColors->Visible == true)
	{
		LB10_BrownColors->ItemIndex = 0;
		LB10_BrownColors->ItemIndex = -1;
	}

	if(LB11_WhiteColors->Visible == true)
	{
		LB11_WhiteColors->ItemIndex = 0;
		LB11_WhiteColors->ItemIndex = -1;
	}

	if(LB12_GreyColors->Visible == true)
	{
		LB12_GreyColors->ItemIndex = 0;
		LB12_GreyColors->ItemIndex = -1;
	}

	Panel2->Visible = false;
	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;

	TimerSelect->Enabled = true; //Включаем обработчик события OnClick при Select
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ImgBtn5Click(TObject *Sender)
{
//Отображаем панель
	if(Panel2->Visible == false)
	{
		Panel2->Width = 181;
		Panel2->Position->X = Form1->Width - Panel2->Width - 20; //Делаем отступ от правого края
		Panel2->Position->Y = 46; //Отступ с верху
		Panel2->Height = 458;

		//Эмитируем нажатие меню
		ImgBtn5->Visible = false;
		ImgBtn6->Visible = true;

		//Отображаем выпадающее Меню
		Panel2->Visible = true;
	}

//Убираем панель
	else
	{
		ImgBtn5->Visible = true;
		ImgBtn6->Visible = false;

		Form1->Panel2->Visible = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerSelectTimer(TObject *Sender)
{
	if(ListBoxItem351->IsSelected == true || Salmon3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 112, 84);
		Form3->Label1->Text = Form1->ListBoxItem351->Text;
		Form3->Label3->Text = "205, 112, 84";
		Form3->Label5->Text = "#CD7054";
		Form3->Label7->Text = "Salmon3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem382->IsSelected == true || DeepPink2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 18, 137);
		Form3->Label1->Text = Form1->ListBoxItem382->Text;
		Form3->Label3->Text = "238, 18, 137";
		Form3->Label5->Text = "#EE1289";
		Form3->Label7->Text = "DeepPink2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem100->IsSelected == true || Salmon->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(250, 128, 114);
		Form3->Label1->Text = Form1->ListBoxItem100->Text;
		Form3->Label3->Text = "250, 128, 114";
		Form3->Label5->Text = "#FA8072";
		Form3->Label7->Text = "Salmon";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem406->IsSelected == true || VioletRed2->IsSelected == true)
	{
		Form3->buf2->Text = ListBox1->ItemIndex; //Присваиваем текущее значение выделенного ListBoxItem
		Form3->Rectangle1->Fill->Color = MakeColor(238, 58, 140);
		Form3->Label1->Text = Form1->ListBoxItem406->Text;
		Form3->Label3->Text = "238, 58, 140";
		Form3->Label5->Text = "#EE3A8C";
		Form3->Label7->Text = "VioletRed2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem301->IsSelected == true || Gold2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 201, 0);
		Form3->Label1->Text = Form1->ListBoxItem301->Text;
		Form3->Label3->Text = "238, 201, 0";
		Form3->Label5->Text = "#EEC900";
		Form3->Label7->Text = "Gold2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem274->IsSelected == true || Chartreuse3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(102, 205, 0);
		Form3->Label1->Text = Form1->ListBoxItem274->Text;
		Form3->Label3->Text = "102, 205, 0";
		Form3->Label5->Text = "#66CD00";
		Form3->Label7->Text = "Chartreuse3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem43->IsSelected == true || DeepSkyBlue->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 191, 225);
		Form3->Label1->Text = Form1->ListBoxItem43->Text;
		Form3->Label3->Text = "0, 191, 225";
		Form3->Label5->Text = "#00BFFF";
		Form3->Label7->Text = "DeepSkyBlue";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem237->IsSelected == true || Turquoise2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 229, 238);
		Form3->Label1->Text = Form1->ListBoxItem237->Text;
		Form3->Label3->Text = "0, 229, 238";
		Form3->Label5->Text = "#00E5EE";
		Form3->Label7->Text = "Turquoise2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem251->IsSelected == true || Aquamarine4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(69, 139, 116);
		Form3->Label1->Text = Form1->ListBoxItem251->Text;
		Form3->Label3->Text = "69, 139, 116";
		Form3->Label5->Text = "#458B74";
		Form3->Label7->Text = "Aquamarine4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem275->IsSelected == true || Chartreuse4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(69, 139, 0);
		Form3->Label1->Text = Form1->ListBoxItem275->Text;
		Form3->Label3->Text = "69, 139, 0";
		Form3->Label5->Text = "#458B00";
		Form3->Label7->Text = "Chartreuse4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem330->IsSelected == true || Wheat3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 186, 150);
		Form3->Label1->Text = Form1->ListBoxItem330->Text;
		Form3->Label3->Text = "205, 186, 150";
		Form3->Label5->Text = "#CDBA96";
		Form3->Label7->Text = "Wheat3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem15->IsSelected == true || Cornsilk->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 248, 220);
		Form3->Label1->Text = Form1->ListBoxItem15->Text;
		Form3->Label3->Text = "255, 248, 220";
		Form3->Label5->Text = "#FFF8DC";
		Form3->Label7->Text = "Cornsilk";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem163->IsSelected == true || Ivory4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 139, 131);
		Form3->Label1->Text = Form1->ListBoxItem163->Text;
		Form3->Label3->Text = "139, 139, 131";
		Form3->Label5->Text = "#8B8B83";
		Form3->Label7->Text = "Ivory4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem158->IsSelected == true || Cornsilk3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 200, 177);
		Form3->Label1->Text = Form1->ListBoxItem158->Text;
		Form3->Label3->Text = "205, 200, 177";
		Form3->Label5->Text = "#CDC8B1";
		Form3->Label7->Text = "Cornsilk3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem157->IsSelected == true || Cornsilk2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 232, 205);
		Form3->Label1->Text = Form1->ListBoxItem157->Text;
		Form3->Label3->Text = "238, 232, 205";
		Form3->Label5->Text = "#8B8970";
		Form3->Label7->Text = "Cornsilk2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem127->IsSelected == true || Thistle->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(216, 191, 216);
		Form3->Label1->Text = Form1->ListBoxItem127->Text;
		Form3->Label3->Text = "216, 191, 216";
		Form3->Label5->Text = "#D8BFD8";
		Form3->Label7->Text = "Thistle";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem27->IsSelected == true || Black->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 0, 0);
		Form3->Label1->Text = Form1->ListBoxItem27->Text;
		Form3->Label3->Text = "0, 0, 0";
		Form3->Label5->Text = "#000000";
		Form3->Label7->Text = "Black";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem187->IsSelected == true || RoyalBlue4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(39, 64, 139);
		Form3->Label1->Text = Form1->ListBoxItem187->Text;
		Form3->Label3->Text = "39, 64, 139";
		Form3->Label5->Text = "#27408B";
		Form3->Label7->Text = "RoyalBlue4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem313->IsSelected == true || RosyBrown2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 180, 180);
		Form3->Label1->Text = Form1->ListBoxItem313->Text;
		Form3->Label3->Text = "238, 180, 180";
		Form3->Label5->Text = "#EEB4B4";
		Form3->Label7->Text = "RosyBrown2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem5->IsSelected == true || FloralWhite->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 250, 240);
		Form3->Label1->Text = Form1->ListBoxItem5->Text;
		Form3->Label3->Text = "255, 250, 240";
		Form3->Label5->Text = "#FFFAF0";
		Form3->Label7->Text = "FloralWhite";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem238->IsSelected == true || Turquoise3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 197, 205);
		Form3->Label1->Text = Form1->ListBoxItem238->Text;
		Form3->Label3->Text = "0, 197, 205";
		Form3->Label5->Text = "#00C5CD";
		Form3->Label7->Text = "Turquoise3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem123->IsSelected == true || DarkViolet->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(148, 0, 211);
		Form3->Label1->Text = Form1->ListBoxItem123->Text;
		Form3->Label3->Text = "148, 0, 211";
		Form3->Label5->Text = "#9400D3";
		Form3->Label7->Text = "DarkViolet";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem75->IsSelected == true || DarkKhaki->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(189, 183, 107);
		Form3->Label1->Text = Form1->ListBoxItem75->Text;
		Form3->Label3->Text = "189, 183, 107";
		Form3->Label5->Text = "#BDB76B";
		Form3->Label7->Text = "DarkKhaki";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem415->IsSelected == true || Orchid3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 105, 201);
		Form3->Label1->Text = Form1->ListBoxItem415->Text;
		Form3->Label3->Text = "205, 105, 201";
		Form3->Label5->Text = "#CD69C9";
		Form3->Label7->Text = "Orchid3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem431->IsSelected == true || Purple3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(125, 38, 205);
		Form3->Label1->Text = Form1->ListBoxItem431->Text;
		Form3->Label3->Text = "125, 38, 205";
		Form3->Label5->Text = "#7D26CD";
		Form3->Label7->Text = "Purple3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem118->IsSelected == true || Violet->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 130, 238);
		Form3->Label1->Text = Form1->ListBoxItem118->Text;
		Form3->Label3->Text = "238, 130, 238";
		Form3->Label5->Text = "#EE82EE";
		Form3->Label7->Text = "Violet";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem115->IsSelected == true || MediumVioletRed->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(199, 21, 133);
		Form3->Label1->Text = Form1->ListBoxItem115->Text;
		Form3->Label3->Text = "199, 21, 133";
		Form3->Label5->Text = "#C71585";
		Form3->Label7->Text = "MediumVioletRed";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem181->IsSelected == true || SlateBlue2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(122, 103, 238);
		Form3->Label1->Text = Form1->ListBoxItem181->Text;
		Form3->Label3->Text = "122, 103, 238";
		Form3->Label5->Text = "#7A67EE";
		Form3->Label7->Text = "SlateBlue2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem422->IsSelected == true || MediumOrchid2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(209, 95, 238);
		Form3->Label1->Text = Form1->ListBoxItem422->Text;
		Form3->Label3->Text = "209, 95, 238";
		Form3->Label5->Text = "#D15FEE";
		Form3->Label7->Text = "MediumOrchid2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem344->IsSelected == true || Firebrick4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 26, 26);
		Form3->Label1->Text = Form1->ListBoxItem344->Text;
		Form3->Label3->Text = "139, 26, 26";
		Form3->Label5->Text = "#8B1A1A";
		Form3->Label7->Text = "Firebrick4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem434->IsSelected == true || MediumPurple2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(159, 121, 238);
		Form3->Label1->Text = Form1->ListBoxItem434->Text;
		Form3->Label3->Text = "159, 121, 238";
		Form3->Label5->Text = "#9F79EE";
		Form3->Label7->Text = "MediumPurple2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem383->IsSelected == true || DeepPink3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 16, 118);
		Form3->Label1->Text = Form1->ListBoxItem383->Text;
		Form3->Label3->Text = "205, 16, 118";
		Form3->Label5->Text = "#CD1076";
		Form3->Label7->Text = "DeepPink3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem370->IsSelected == true || Tomato2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 92, 66);
		Form3->Label1->Text = Form1->ListBoxItem370->Text;
		Form3->Label3->Text = "238, 92, 66";
		Form3->Label5->Text = "#EE5C42";
		Form3->Label7->Text = "Tomato2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem390->IsSelected == true || Pink2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 169, 184);
		Form3->Label1->Text = Form1->ListBoxItem390->Text;
		Form3->Label3->Text = "238, 169, 184";
		Form3->Label5->Text = "#EEA9B8";
		Form3->Label7->Text = "Pink2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem379->IsSelected == true || Red3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 0, 0);
		Form3->Label1->Text = Form1->ListBoxItem379->Text;
		Form3->Label3->Text = "205, 000, 000";
		Form3->Label5->Text = "#CD0000";
		Form3->Label7->Text = "Red3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem189->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 0, 238);
		Form3->Label1->Text = Form1->ListBoxItem189->Text;
		Form3->Label3->Text = "0, 0, 238";
		Form3->Label5->Text = "#0000EE";
		Form3->Label7->Text = "Blue2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem70->IsSelected == true || MediumSpringGreen->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 250, 154);
		Form3->Label1->Text = Form1->ListBoxItem70->Text;
		Form3->Label3->Text = "0, 250, 154";
		Form3->Label5->Text = "#00FA9A";
		Form3->Label7->Text = "MediumSpringGreen";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem52->IsSelected == true || MediumTurquoise->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(72, 209, 204);
		Form3->Label1->Text = Form1->ListBoxItem52->Text;
		Form3->Label3->Text = "72, 209, 204";
		Form3->Label5->Text = "#48D1CC";
		Form3->Label7->Text = "MediumTurquoise";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem86->IsSelected == true || SaddleBrown->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 69, 19);
		Form3->Label1->Text = Form1->ListBoxItem86->Text;
		Form3->Label3->Text = "139, 69, 19";
		Form3->Label5->Text = "#8B4513";
		Form3->Label7->Text = "SaddleBrown";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem191->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 0, 139);
		Form3->Label1->Text = Form1->ListBoxItem191->Text;
		Form3->Label3->Text = "0, 0, 139";
		Form3->Label5->Text = "#00008B";
		Form3->Label7->Text = "Blue4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem203->IsSelected == true || DeepSkyBlue4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 104, 139);
		Form3->Label1->Text = Form1->ListBoxItem203->Text;
		Form3->Label3->Text = "0, 104, 139";
		Form3->Label5->Text = "#00688B";
		Form3->Label7->Text = "DeepSkyBlue4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem337->IsSelected == true || Chocolate2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 118, 33);
		Form3->Label1->Text = Form1->ListBoxItem337->Text;
		Form3->Label3->Text = "238, 118, 33";
		Form3->Label5->Text = "#EE7621";
		Form3->Label7->Text = "Chocolate2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem444->IsSelected == true || Grey41->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(105, 105, 105);
		Form3->Label1->Text = Form1->ListBoxItem444->Text;
		Form3->Label3->Text = "105, 105, 105";
		Form3->Label5->Text = "#696969";
		Form3->Label7->Text = "Grey41";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem230->IsSelected == true || PaleTurquoise3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(150, 205, 205);
		Form3->Label1->Text = Form1->ListBoxItem230->Text;
		Form3->Label3->Text = "150, 205, 205";
		Form3->Label5->Text = "#96CDCD";
		Form3->Label7->Text = "PaleTurquoise3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem29->IsSelected == true || DimGrey->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(105, 105, 105);
		Form3->Label1->Text = Form1->ListBoxItem29->Text;
		Form3->Label3->Text = "105, 105, 105";
		Form3->Label5->Text = "#696969";
		Form3->Label7->Text = "DimGray";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem25->IsSelected == true || MistyRose->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 228, 225);
		Form3->Label1->Text = Form1->ListBoxItem25->Text;
		Form3->Label3->Text = "255, 228, 225";
		Form3->Label5->Text = "#FFE4E1";
		Form3->Label7->Text = "MistyRose";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem166->IsSelected == true || Honeydew3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(193, 205, 193);
		Form3->Label1->Text = Form1->ListBoxItem166->Text;
		Form3->Label3->Text = "193, 205, 193";
		Form3->Label5->Text = "#C1CDC1";
		Form3->Label7->Text = "Honeydew3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem169->IsSelected == true || LavenderBlush2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 224, 229);
		Form3->Label1->Text = Form1->ListBoxItem169->Text;
		Form3->Label3->Text = "238, 224, 229";
		Form3->Label5->Text = "#EEE0E5";
		Form3->Label7->Text = "LavenderBlush2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem106->IsSelected == true || Tomato->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 99, 71);
		Form3->Label1->Text = Form1->ListBoxItem106->Text;
		Form3->Label3->Text = "255, 99, 71";
		Form3->Label5->Text = "#FF6347";
		Form3->Label7->Text = "Tomato";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem318->IsSelected == true || IndianRed3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 85, 85);
		Form3->Label1->Text = Form1->ListBoxItem318->Text;
		Form3->Label3->Text = "205, 85, 85";
		Form3->Label5->Text = "#CD5555";
		Form3->Label7->Text = "IndianRed3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem338->IsSelected == true || Chocolate3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 102, 29);
		Form3->Label1->Text = Form1->ListBoxItem338->Text;
		Form3->Label3->Text = "205, 102, 29";
		Form3->Label5->Text = "#CD661D";
		Form3->Label7->Text = "Chocolate3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem109->IsSelected == true || HotPink->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 105, 180);
		Form3->Label1->Text = Form1->ListBoxItem109->Text;
		Form3->Label3->Text = "255, 105, 180";
		Form3->Label5->Text = "#FF69B4";
		Form3->Label7->Text = "HotPink";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem243->IsSelected == true || Cyan4->IsSelected == true || DarkCyan->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 139, 139);
		Form3->Label1->Text = Form1->ListBoxItem243->Text;
		Form3->Label3->Text = "0, 139, 139";
		Form3->Label5->Text = "#008B8B";
		Form3->Label7->Text = "Cyan4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem287->IsSelected == true || Khaki4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 134, 78);
		Form3->Label1->Text = Form1->ListBoxItem287->Text;
		Form3->Label3->Text = "139, 134, 78";
		Form3->Label5->Text = "#8B864E";
		Form3->Label7->Text = "Khaki4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem335->IsSelected == true || Tan4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 90, 43);
		Form3->Label1->Text = Form1->ListBoxItem335->Text;
		Form3->Label3->Text = "139, 90, 43";
		Form3->Label5->Text = "#8B5A2B";
		Form3->Label7->Text = "Tan4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem348->IsSelected == true || Brown4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 35, 35);
		Form3->Label1->Text = Form1->ListBoxItem348->Text;
		Form3->Label3->Text = "139, 35, 35";
		Form3->Label5->Text = "#8B2323";
		Form3->Label7->Text = "Brown4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem376->IsSelected == true || OrangeRed4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 37, 0);
		Form3->Label1->Text = Form1->ListBoxItem376->Text;
		Form3->Label3->Text = "139, 37, 0";
		Form3->Label5->Text = "#8B2500";
		Form3->Label7->Text = "OrangeRed4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem302->IsSelected == true || Gold3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 173, 0);
		Form3->Label1->Text = Form1->ListBoxItem302->Text;
		Form3->Label3->Text = "205, 173, 0";
		Form3->Label5->Text = "#CDAD00";
		Form3->Label7->Text = "Gold3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem428->IsSelected == true || DarkOrchid4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(104, 34, 139);
		Form3->Label1->Text = Form1->ListBoxItem428->Text;
		Form3->Label3->Text = "104, 34, 139";
		Form3->Label5->Text = "#68228B";
		Form3->Label7->Text = "DarkOrchid4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem372->IsSelected == true || Tomato4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 54, 38);
		Form3->Label1->Text = Form1->ListBoxItem372->Text;
		Form3->Label3->Text = "139, 54, 38";
		Form3->Label5->Text = "#8B3626";
		Form3->Label7->Text = "Tomato4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem199->IsSelected == true || SteelBlue4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(54, 100, 139);
		Form3->Label1->Text = Form1->ListBoxItem199->Text;
		Form3->Label3->Text = "54, 100, 139";
		Form3->Label5->Text = "#36648B";
		Form3->Label7->Text = "SteelBlue4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem194->IsSelected == true || DodgerBlue3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(24, 116, 205);
		Form3->Label1->Text = Form1->ListBoxItem194->Text;
		Form3->Label3->Text = "24, 116, 205";
		Form3->Label5->Text = "#1874CD";
		Form3->Label7->Text = "DodgerBlue3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem33->IsSelected == true || NavyColor->IsSelected == true || Navy->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 0, 128);
		Form3->Label1->Text = Form1->ListBoxItem33->Text;
		Form3->Label3->Text = "0, 0, 128";
		Form3->Label5->Text = "#000080";
		Form3->Label7->Text = "NavyBlue";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem215->IsSelected == true || SlateGrey4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(108, 123, 139);
		Form3->Label1->Text = Form1->ListBoxItem215->Text;
		Form3->Label3->Text = "108, 123, 139";
		Form3->Label5->Text = "#6C7B8B";
		Form3->Label7->Text = "SlateGray4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem432->IsSelected == true || Purple4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(85, 26, 139);
		Form3->Label1->Text = Form1->ListBoxItem432->Text;
		Form3->Label3->Text = "85, 26, 139";
		Form3->Label5->Text = "#551A8B";
		Form3->Label7->Text = "Purple4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem210->IsSelected == true || LightSkyBlue3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(141, 182, 205);
		Form3->Label1->Text = Form1->ListBoxItem210->Text;
		Form3->Label3->Text = "141, 182, 205";
		Form3->Label5->Text = "#8DB6CD";
		Form3->Label7->Text = "LightSkyBlue3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem450->IsSelected == true || DarkGray->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(169, 169, 169);
		Form3->Label1->Text = Form1->ListBoxItem450->Text;
		Form3->Label3->Text = "169, 169, 169";
		Form3->Label5->Text = "#A9A9A9";
		Form3->Label7->Text = "DarkGrey";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem247->IsSelected == true || DarkSlateGrey4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(82, 139, 139);
		Form3->Label1->Text = Form1->ListBoxItem247->Text;
		Form3->Label3->Text = "82, 139, 139";
		Form3->Label5->Text = "#528B8B";
		Form3->Label7->Text = "DarkSlateGray4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem299->IsSelected == true || Yellow4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 139, 0);
		Form3->Label1->Text = Form1->ListBoxItem299->Text;
		Form3->Label3->Text = "139, 139, 0";
		Form3->Label5->Text = "#8B8B00";
		Form3->Label7->Text = "Yellow4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem440->IsSelected == true || Thistle4->IsSelected == true)
	{	Form3->Rectangle1->Fill->Color = MakeColor(139, 123, 139);
		Form3->Label1->Text = Form1->ListBoxItem440->Text;
		Form3->Label3->Text = "139, 123, 139";
		Form3->Label5->Text = "#8B7B8B";
		Form3->Label7->Text = "Thistle4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem404->IsSelected == true || Maroon4->IsSelected == true)
	{
		Form3->buf2->Text = ListBox1->ItemIndex; //Присваиваем текущее значение выделенного ListBoxItem
		Form3->Rectangle1->Fill->Color = MakeColor(139, 28, 98);
		Form3->Label1->Text = Form1->ListBoxItem404->Text;
		Form3->Label3->Text = "139, 28, 98";
		Form3->Label5->Text = "#8B1C62";
		Form3->Label7->Text = "Maroon4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem453->IsSelected == true || DarkMagenta->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 0, 139);
		Form3->Label1->Text = Form1->ListBoxItem453->Text;
		Form3->Label3->Text = "139, 0, 139";
		Form3->Label5->Text = "#8B008B";
		Form3->Label7->Text = "DarkMagenta";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem103->IsSelected == true || DarkOrange->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 140, 0);
		Form3->Label1->Text = Form1->ListBoxItem103->Text;
		Form3->Label3->Text = "255, 140, 0";
		Form3->Label5->Text = "#FF8C00";
		Form3->Label7->Text = "DarkOrange";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem60->IsSelected == true || DarkOliveGreen->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(85, 107, 47);
		Form3->Label1->Text = Form1->ListBoxItem60->Text;
		Form3->Label3->Text = "85, 107, 47";
		Form3->Label5->Text = "#556B2F";
		Form3->Label7->Text = "DarkOliveGreen";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem267->IsSelected == true || SpringGreen4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 139, 69);
		Form3->Label1->Text = Form1->ListBoxItem267->Text;
		Form3->Label3->Text = "0, 139, 69";
		Form3->Label5->Text = "#008B45";
		Form3->Label7->Text = "SpringGreen4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem207->IsSelected == true || SkyBlue4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(74, 112, 139);
		Form3->Label1->Text = Form1->ListBoxItem207->Text;
		Form3->Label3->Text = "74, 112, 139";
		Form3->Label5->Text = "#4A708B";
		Form3->Label7->Text = "SkyBlue4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem235->IsSelected == true || CadetBlue4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(83, 134, 139);
		Form3->Label1->Text = Form1->ListBoxItem235->Text;
		Form3->Label3->Text = "83, 134, 139";
		Form3->Label5->Text = "#53868B";
		Form3->Label7->Text = "CadetBlue4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem363->IsSelected == true || DarkOrange3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 102, 0);
		Form3->Label1->Text = Form1->ListBoxItem363->Text;
		Form3->Label3->Text = "205, 102, 0";
		Form3->Label5->Text = "#CD6600";
		Form3->Label7->Text = "DarkOrange3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem195->IsSelected == true || DodgerBlue4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(16, 78, 139);
		Form3->Label1->Text = Form1->ListBoxItem195->Text;
		Form3->Label3->Text = "16, 78, 139";
		Form3->Label5->Text = "#104E8B";
		Form3->Label7->Text = "DodgerBlue4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem364->IsSelected == true || DarkOrange4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 69, 0);
		Form3->Label1->Text = Form1->ListBoxItem364->Text;
		Form3->Label3->Text = "139, 69, 0";
		Form3->Label5->Text = "#8B4500";
		Form3->Label7->Text = "DarkOrange4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem367->IsSelected == true || Coral3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 91, 69);
		Form3->Label1->Text = Form1->ListBoxItem367->Text;
		Form3->Label3->Text = "205, 91, 69";
		Form3->Label5->Text = "#CD5B45";
		Form3->Label7->Text = "Coral3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem352->IsSelected == true || Salmon4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 76, 57);
		Form3->Label1->Text = Form1->ListBoxItem352->Text;
		Form3->Label3->Text = "139, 76, 57";
		Form3->Label5->Text = "#8B4C39";
		Form3->Label7->Text = "Salmon4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem311->IsSelected == true || DarkGoldenrod4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 101, 8);
		Form3->Label1->Text = Form1->ListBoxItem311->Text;
		Form3->Label3->Text = "139, 101, 8";
		Form3->Label5->Text = "#8B6508";
		Form3->Label7->Text = "DarkGoldenrod4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem227->IsSelected == true || LightCyan4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(122, 139, 139);
		Form3->Label1->Text = Form1->ListBoxItem227->Text;
		Form3->Label3->Text = "122, 139, 139";
		Form3->Label5->Text = "#7A8B8B";
		Form3->Label7->Text = "LightCyan4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem59->IsSelected == true || DarkGreen->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 100, 0);
		Form3->Label1->Text = Form1->ListBoxItem59->Text;
		Form3->Label3->Text = "0, 100, 0";
		Form3->Label5->Text = "#006400";
		Form3->Label7->Text = "DarkGreen";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem291->IsSelected == true || LightGoldenrod4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 129, 76);
		Form3->Label1->Text = Form1->ListBoxItem291->Text;
		Form3->Label3->Text = "139, 129, 76";
		Form3->Label5->Text = "#8B814C";
		Form3->Label7->Text = "LightGoldenrod4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem271->IsSelected == true || Green4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 139, 0);
		Form3->Label1->Text = Form1->ListBoxItem271->Text;
		Form3->Label3->Text = "0, 139, 0";
		Form3->Label5->Text = "#008B00";
		Form3->Label7->Text = "Green4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem283->IsSelected == true || DarkOliveGreen4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(110, 139, 61);
		Form3->Label1->Text = Form1->ListBoxItem283->Text;
		Form3->Label3->Text = "110, 139, 61";
		Form3->Label5->Text = "#6E8B3D";
		Form3->Label7->Text = "DarkOliveGreen4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem355->IsSelected == true || LightSalmon3->IsSelected == true || LightSalmonColor3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 129, 98);
		Form3->Label1->Text = Form1->ListBoxItem355->Text;
		Form3->Label3->Text = "205, 129, 98";
		Form3->Label5->Text = "#CD8162";
		Form3->Label7->Text = "LightSalmon3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem263->IsSelected == true || PaleGreen4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(84, 139, 84);
		Form3->Label1->Text = Form1->ListBoxItem263->Text;
		Form3->Label3->Text = "84, 139, 84";
		Form3->Label5->Text = "#548B54";
		Form3->Label7->Text = "PaleGreen4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem303->IsSelected == true || Gold4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 117, 0);
		Form3->Label1->Text = Form1->ListBoxItem303->Text;
		Form3->Label3->Text = "139, 117, 0";
		Form3->Label5->Text = "#8B7500";
		Form3->Label7->Text = "Gold4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem190->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 0, 205);
		Form3->Label1->Text = Form1->ListBoxItem190->Text;
		Form3->Label3->Text = "0, 0, 205";
		Form3->Label5->Text = "#0000CD";
		Form3->Label7->Text = "Blue3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem408->IsSelected == true || VioletRed4->IsSelected == true)
	{
		Form3->buf2->Text = ListBox1->ItemIndex; //Присваиваем текущее значение выделенного ListBoxItem
		Form3->Rectangle1->Fill->Color = MakeColor(139, 34, 82);
		Form3->Label1->Text = Form1->ListBoxItem408->Text;
		Form3->Label3->Text = "139, 34, 82";
		Form3->Label5->Text = "#8B2252";
		Form3->Label7->Text = "VioletRed4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem239->IsSelected == true || Turquoise4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 134, 139);
		Form3->Label1->Text = Form1->ListBoxItem239->Text;
		Form3->Label3->Text = "0, 134, 139";
		Form3->Label5->Text = "#00868B";
		Form3->Label7->Text = "Turquoise4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem28->IsSelected == true || DarkSlateGrey->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(47, 79, 79);
		Form3->Label1->Text = Form1->ListBoxItem28->Text;
		Form3->Label3->Text = "47, 79, 79";
		Form3->Label5->Text = "#2F4F4F";
		Form3->Label7->Text = "DarkSlateGray";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem35->IsSelected == true || DarkSlateBlue->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(72, 61, 139);
		Form3->Label1->Text = Form1->ListBoxItem35->Text;
		Form3->Label3->Text = "72, 61, 139";
		Form3->Label5->Text = "#483D8B";
		Form3->Label7->Text = "DarkSlateBlue";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem342->IsSelected == true || Firebrick3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 38, 38);
		Form3->Label1->Text = Form1->ListBoxItem342->Text;
		Form3->Label3->Text = "205, 38, 38";
		Form3->Label5->Text = "#CD2626";
		Form3->Label7->Text = "Firebrick3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem122->IsSelected == true || DarkOrchid->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(153, 50, 204);
		Form3->Label1->Text = Form1->ListBoxItem122->Text;
		Form3->Label3->Text = "153, 50, 204";
		Form3->Label5->Text = "#9932CC";
		Form3->Label7->Text = "DarkOrchid";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem219->IsSelected == true || LightSteelBlue4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(110, 123, 139);
		Form3->Label1->Text = Form1->ListBoxItem219->Text;
		Form3->Label3->Text = "110, 123, 139";
		Form3->Label5->Text = "#6E7B8B";
		Form3->Label7->Text = "LightSteelBlue4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem218->IsSelected == true || LightSteelBlue3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(162, 181, 205);
		Form3->Label1->Text = Form1->ListBoxItem218->Text;
		Form3->Label3->Text = "162, 181, 205";
		Form3->Label5->Text = "#A2B5CD";
		Form3->Label7->Text = "LightSteelBlue3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem305->IsSelected == true || Goldenrod2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 180, 34);
		Form3->Label1->Text = Form1->ListBoxItem305->Text;
		Form3->Label3->Text = "238, 180, 34";
		Form3->Label5->Text = "#EEB422";
		Form3->Label7->Text = "Goldenrod2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem1->IsSelected == true || Snow->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 250, 250);
		Form3->Label1->Text = Form1->ListBoxItem1->Text;
		Form3->Label3->Text = "255, 250, 250";
		Form3->Label5->Text = "#FFFAFA";
		Form3->Label7->Text = "Snow";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem130->IsSelected == true || Snow3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 201, 201);
		Form3->Label1->Text = Form1->ListBoxItem130->Text;
		Form3->Label3->Text = "205, 201, 201";
		Form3->Label5->Text = "#CDC9C9";
		Form3->Label7->Text = "Snow3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem131->IsSelected == true || Snow4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 137, 137);
		Form3->Label1->Text = Form1->ListBoxItem131->Text;
		Form3->Label3->Text = "139, 137, 137";
		Form3->Label5->Text = "#8B8989";
		Form3->Label7->Text = "Snow4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem19->IsSelected == true || Honeydew->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(240, 255, 240);
		Form3->Label1->Text = Form1->ListBoxItem19->Text;
		Form3->Label3->Text = "240, 255, 240";
		Form3->Label5->Text = "#F0FFF0";
		Form3->Label7->Text = "Honeydew";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem221->IsSelected == true || LightBlue2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(178, 223, 238);
		Form3->Label1->Text = Form1->ListBoxItem221->Text;
		Form3->Label3->Text = "178, 223, 238";
		Form3->Label5->Text = "#B2DFEE";
		Form3->Label7->Text = "LightBlue2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem16->IsSelected == true || Ivory->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 255, 240);
		Form3->Label1->Text = Form1->ListBoxItem16->Text;
		Form3->Label3->Text = "255, 255, 240";
		Form3->Label5->Text = "#FFFFF0";
		Form3->Label7->Text = "Ivory";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem416->IsSelected == true || Orchid4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 71, 137);
		Form3->Label1->Text = Form1->ListBoxItem416->Text;
		Form3->Label3->Text = "139, 71, 137";
		Form3->Label5->Text = "#8B4789";
		Form3->Label7->Text = "Orchid4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem419->IsSelected == true || Plum3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 150, 205);
		Form3->Label1->Text = Form1->ListBoxItem419->Text;
		Form3->Label3->Text = "205, 150, 205";
		Form3->Label5->Text = "#CD96CD";
		Form3->Label7->Text = "Plum3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem46->IsSelected == true || SteelBlue->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(70, 130, 180);
		Form3->Label1->Text = Form1->ListBoxItem46->Text;
		Form3->Label3->Text = "70, 130, 180";
		Form3->Label5->Text = "#4682B4";
		Form3->Label7->Text = "SteelBlue";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem30->IsSelected == true || SlateGrey->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(112, 128, 144);
		Form3->Label1->Text = Form1->ListBoxItem30->Text;
		Form3->Label3->Text = "112, 128, 144";
		Form3->Label5->Text = "#708090";
		Form3->Label7->Text = "SlateGray";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem214->IsSelected == true || SlateGrey3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(159, 182, 205);
		Form3->Label1->Text = Form1->ListBoxItem214->Text;
		Form3->Label3->Text = "159, 182, 205";
		Form3->Label5->Text = "#9FB6CD";
		Form3->Label7->Text = "SlateGray3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem213->IsSelected == true || SlateGrey2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(185, 211, 238);
		Form3->Label1->Text = Form1->ListBoxItem213->Text;
		Form3->Label3->Text = "185, 211, 238";
		Form3->Label5->Text = "#B9D3EE";
		Form3->Label7->Text = "SlateGray2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem206->IsSelected == true || SkyBlue3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(108, 166, 205);
		Form3->Label1->Text = Form1->ListBoxItem206->Text;
		Form3->Label3->Text = "108, 166, 205";
		Form3->Label5->Text = "#6CA6CD";
		Form3->Label7->Text = "SkyBlue3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem198->IsSelected == true || SteelBlue3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(79, 148, 205);
		Form3->Label1->Text = Form1->ListBoxItem198->Text;
		Form3->Label3->Text = "79, 148, 205";
		Form3->Label5->Text = "#4F94CD";
		Form3->Label7->Text = "SteelBlue3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem159->IsSelected == true || Cornsilk4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 136, 120);
		Form3->Label1->Text = Form1->ListBoxItem159->Text;
		Form3->Label3->Text = "139, 136, 120";
		Form3->Label5->Text = "#8B8878";
		Form3->Label7->Text = "Cornsilk4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem138->IsSelected == true || AntiqueWhite3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 192, 176);
		Form3->Label1->Text = Form1->ListBoxItem138->Text;
		Form3->Label3->Text = "205, 192, 176";
		Form3->Label5->Text = "#CDC0B0";
		Form3->Label7->Text = "AntiqueWhite3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem92->IsSelected == true || Gray->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(190 , 190, 190);
		Form3->Label1->Text = Form1->ListBoxItem92->Text;
		Form3->Label3->Text = "190 , 190, 190";
		Form3->Label5->Text = "#BEBEBE";
		Form3->Label7->Text = "Gray";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem314->IsSelected == true || RosyBrown3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 155, 155);
		Form3->Label1->Text = Form1->ListBoxItem314->Text;
		Form3->Label3->Text = "205, 155, 155";
		Form3->Label5->Text = "#CD9B9B";
		Form3->Label7->Text = "RosyBrown3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem295->IsSelected == true || LightYellow4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 139, 122);
		Form3->Label1->Text = Form1->ListBoxItem295->Text;
		Form3->Label3->Text = "139, 139, 122";
		Form3->Label5->Text = "#8B8B7A";
		Form3->Label7->Text = "LightYellow4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem56->IsSelected == true || CadetBlue->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(95, 158, 160);
		Form3->Label1->Text = Form1->ListBoxItem56->Text;
		Form3->Label3->Text = "95, 158, 160";
		Form3->Label5->Text = "#5F9EA0";
		Form3->Label7->Text = "CadetBlue";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem246->IsSelected == true || DarkSlateGrey3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(121, 205, 205);
		Form3->Label1->Text = Form1->ListBoxItem246->Text;
		Form3->Label3->Text = "121, 205, 205";
		Form3->Label5->Text = "#79CDCD";
		Form3->Label7->Text = "DarkSlateGray3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem331->IsSelected == true || Wheat4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 126, 102);
		Form3->Label1->Text = Form1->ListBoxItem331->Text;
		Form3->Label3->Text = "139, 126, 102";
		Form3->Label5->Text = "#8B7E66";
		Form3->Label7->Text = "Wheat4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem209->IsSelected == true || LightSkyBlue2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(164, 211, 238);
		Form3->Label1->Text = Form1->ListBoxItem209->Text;
		Form3->Label3->Text = "164, 211, 238";
		Form3->Label5->Text = "#A4D3EE";
		Form3->Label7->Text = "LightSkyBlue2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem211->IsSelected == true || LightSkyBlue4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(96, 123, 139);
		Form3->Label1->Text = Form1->ListBoxItem211->Text;
		Form3->Label3->Text = "96, 123, 139";
		Form3->Label5->Text = "#607B8B";
		Form3->Label7->Text = "LightSkyBlue4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem223->IsSelected == true || LightBlue4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(104, 131, 139);
		Form3->Label1->Text = Form1->ListBoxItem223->Text;
		Form3->Label3->Text = "104, 131, 139";
		Form3->Label5->Text = "#68838B";
		Form3->Label7->Text = "LightBlue4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem128->IsSelected == true || Silver->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(192, 192, 192);
		Form3->Label1->Text = Form1->ListBoxItem128->Text;
		Form3->Label3->Text = "192, 192, 192";
		Form3->Label5->Text = "#C0C0C0";
		Form3->Label7->Text = "Silver";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem242->IsSelected == true || Cyan3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 205, 205);
		Form3->Label1->Text = Form1->ListBoxItem242->Text;
		Form3->Label3->Text = "0, 205, 205";
		Form3->Label5->Text = "#00CDCD";
		Form3->Label7->Text = "Cyan3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem285->IsSelected == true || Khaki2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 230, 133);
		Form3->Label1->Text = Form1->ListBoxItem285->Text;
		Form3->Label3->Text = "238, 230, 133";
		Form3->Label5->Text = "#EEE685";
		Form3->Label7->Text = "Khaki2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem333->IsSelected == true || Tan2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 154, 73);
		Form3->Label1->Text = Form1->ListBoxItem333->Text;
		Form3->Label3->Text = "238, 154, 73";
		Form3->Label5->Text = "#EE9A49";
		Form3->Label7->Text = "Tan2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem327->IsSelected == true || BurlyWood4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 115, 85);
		Form3->Label1->Text = Form1->ListBoxItem327->Text;
		Form3->Label3->Text = "139, 115, 85";
		Form3->Label5->Text = "#8B7355";
		Form3->Label7->Text = "Burlywood4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem185->IsSelected == true || RoyalBlue2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(67, 110, 238);
		Form3->Label1->Text = Form1->ListBoxItem185->Text;
		Form3->Label3->Text = "67, 110, 238";
		Form3->Label5->Text = "#436EEE";
		Form3->Label7->Text = "RoyalBlue2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem110->IsSelected == true || DeepPink->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 20, 147);
		Form3->Label1->Text = Form1->ListBoxItem110->Text;
		Form3->Label3->Text = "255, 20, 147";
		Form3->Label5->Text = "#FF1493";
		Form3->Label7->Text = "DeepPink";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem273->IsSelected == true || Chartreuse2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(118, 238, 0);
		Form3->Label1->Text = Form1->ListBoxItem273->Text;
		Form3->Label3->Text = "118, 238, 0";
		Form3->Label5->Text = "#76EE00";
		Form3->Label7->Text = "Chartreuse2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem173->IsSelected == true || MistyRose2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 213, 210);
		Form3->Label1->Text = Form1->ListBoxItem173->Text;
		Form3->Label3->Text = "238, 213, 210";
		Form3->Label5->Text = "#EED5D2";
		Form3->Label7->Text = "MistyRose2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem418->IsSelected == true || Plum2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 174, 238);
		Form3->Label1->Text = Form1->ListBoxItem418->Text;
		Form3->Label3->Text = "238, 174, 238";
		Form3->Label5->Text = "#EEAEEE";
		Form3->Label7->Text = "Plum2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem202->IsSelected == true || DeepSkyBlue3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 154, 205);
		Form3->Label1->Text = Form1->ListBoxItem202->Text;
		Form3->Label3->Text = "0, 154, 205";
		Form3->Label5->Text = "#009ACD";
		Form3->Label7->Text = "DeepSkyBlue3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem37->IsSelected == true || MediumSlateBlue->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(123, 104, 238);
		Form3->Label1->Text = Form1->ListBoxItem37->Text;
		Form3->Label3->Text = "123, 104, 238";
		Form3->Label5->Text = "#7B68EE";
		Form3->Label7->Text = "MediumSlateBlue";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem226->IsSelected == true || LightCyan3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(180, 205, 205);
		Form3->Label1->Text = Form1->ListBoxItem226->Text;
		Form3->Label3->Text = "180, 205, 205";
		Form3->Label5->Text = "#B4CDCD";
		Form3->Label7->Text = "LightCyan3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem286->IsSelected == true || Khaki3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 198, 115);
		Form3->Label1->Text = Form1->ListBoxItem286->Text;
		Form3->Label3->Text = "205, 198, 115";
		Form3->Label5->Text = "#CDC673";
		Form3->Label7->Text = "Khaki3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem31->IsSelected == true || LightGrey->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(211, 211, 211);
		Form3->Label1->Text = Form1->ListBoxItem31->Text;
		Form3->Label3->Text = "211, 211, 211";
		Form3->Label5->Text = "#D3D3D3";
		Form3->Label7->Text = "LightGrey";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem245->IsSelected == true || DarkSlateGrey2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(141, 238, 238);
		Form3->Label1->Text = Form1->ListBoxItem245->Text;
		Form3->Label3->Text = "141, 238, 238";
		Form3->Label5->Text = "#8DEEEE";
		Form3->Label7->Text = "DarkSlateGray2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem162->IsSelected == true || Ivory3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 205, 193);
		Form3->Label1->Text = Form1->ListBoxItem162->Text;
		Form3->Label3->Text = "205, 205, 193";
		Form3->Label5->Text = "#CDCDC1";
		Form3->Label7->Text = "Ivory3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem234->IsSelected == true || CadetBlue3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(122, 197, 205);
		Form3->Label1->Text = Form1->ListBoxItem234->Text;
		Form3->Label3->Text = "122, 197, 205";
		Form3->Label5->Text = "#7AC5CD";
		Form3->Label7->Text = "CadetBlue3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem438->IsSelected == true || Thistle2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 210, 238);
		Form3->Label1->Text = Form1->ListBoxItem438->Text;
		Form3->Label3->Text = "238, 210, 238";
		Form3->Label5->Text = "#EED2EE";
		Form3->Label7->Text = "Thistle2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem112->IsSelected == true || LightPink->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 182, 193);
		Form3->Label1->Text = Form1->ListBoxItem112->Text;
		Form3->Label3->Text = "255, 182, 193";
		Form3->Label5->Text = "#FFB6C1";
		Form3->Label7->Text = "LightPink";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem398->IsSelected == true || PaleVioletRed2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 121, 159);
		Form3->Label1->Text = Form1->ListBoxItem398->Text;
		Form3->Label3->Text = "238, 121, 159";
		Form3->Label5->Text = "#EE799F";
		Form3->Label7->Text = "PaleVioletRed2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem394->IsSelected == true || LightPink2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 162, 173);
		Form3->Label1->Text = Form1->ListBoxItem394->Text;
		Form3->Label3->Text = "238, 162, 173";
		Form3->Label5->Text = "#EEA2AD";
		Form3->Label7->Text = "LightPink2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem391->IsSelected == true || Pink3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 145, 158);
		Form3->Label1->Text = Form1->ListBoxItem391->Text;
		Form3->Label3->Text = "205, 145, 158";
		Form3->Label5->Text = "#CD919E";
		Form3->Label7->Text = "Pink3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem410->IsSelected == true || Magenta2->IsSelected == true)
	{
		Form3->buf2->Text = ListBox1->ItemIndex; //Присваиваем текущее значение выделенного ListBoxItem
		Form3->Rectangle1->Fill->Color = MakeColor(238, 0, 238);
		Form3->Label1->Text = Form1->ListBoxItem410->Text;
		Form3->Label3->Text = "238, 0, 238";
		Form3->Label5->Text = "#EE00EE";
		Form3->Label7->Text = "Magenta2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem289->IsSelected == true || LightGoldenrod2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 220, 130);
		Form3->Label1->Text = Form1->ListBoxItem289->Text;
		Form3->Label3->Text = "238, 220, 130";
		Form3->Label5->Text = "#EEDC82";
		Form3->Label7->Text = "LightGoldenrod2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem261->IsSelected == true || PaleGreen2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(144, 238, 144);
		Form3->Label1->Text = Form1->ListBoxItem261->Text;
		Form3->Label3->Text = "144, 238, 144";
		Form3->Label5->Text = "#90EE90";
		Form3->Label7->Text = "PaleGreen2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem362->IsSelected == true || DarkOrange2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 118, 0);
		Form3->Label1->Text = Form1->ListBoxItem362->Text;
		Form3->Label3->Text = "238, 118, 0";
		Form3->Label5->Text = "#EE7600";
		Form3->Label7->Text = "DarkOrange2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem265->IsSelected == true || SpringGreen2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 238, 118);
		Form3->Label1->Text = Form1->ListBoxItem265->Text;
		Form3->Label3->Text = "0, 238, 118";
		Form3->Label5->Text = "#00EE76";
		Form3->Label7->Text = "SpringGreen2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem45->IsSelected == true || LightSkyBlue->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(135, 206, 250);
		Form3->Label1->Text = Form1->ListBoxItem45->Text;
		Form3->Label3->Text = "135, 206, 250";
		Form3->Label5->Text = "#87CEFA";
		Form3->Label7->Text = "LightSkyBlue";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem101->IsSelected == true || LightSalmon->IsSelected == true || LightSalmonColor->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 160, 122);
		Form3->Label1->Text = Form1->ListBoxItem101->Text;
		Form3->Label3->Text = "255, 160, 122";
		Form3->Label5->Text = "#FFA07A";
		Form3->Label7->Text = "LightSalmon";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem10->IsSelected == true || BlanchedAlmond->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 235, 205);
		Form3->Label1->Text = Form1->ListBoxItem10->Text;
		Form3->Label3->Text = "255, 235, 205";
		Form3->Label5->Text = "#FFEBCD";
		Form3->Label7->Text = "BlanchedAlmond";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem88->IsSelected == true || Peru->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 133, 63);
		Form3->Label1->Text = Form1->ListBoxItem88->Text;
		Form3->Label3->Text = "205, 133, 63";
		Form3->Label5->Text = "#CD853F";
		Form3->Label7->Text = "Peru";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem105->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(240, 128, 128);
		Form3->Label1->Text = Form1->ListBoxItem105->Text;
		Form3->Label3->Text = "240, 128, 128";
		Form3->Label5->Text = "#F08080";
		Form3->Label7->Text = "LightCoral";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem356->IsSelected == true || LightSalmon4->IsSelected == true || LightSalmonColor4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 87, 66);
		Form3->Label1->Text = Form1->ListBoxItem356->Text;
		Form3->Label3->Text = "139, 87, 66";
		Form3->Label5->Text = "#8B5742";
		Form3->Label7->Text = "LightSalmon4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem317->IsSelected == true || IndianRed2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 99, 99);
		Form3->Label1->Text = Form1->ListBoxItem317->Text;
		Form3->Label3->Text = "238, 99, 99";
		Form3->Label5->Text = "#EE6363";
		Form3->Label7->Text = "IndianRed2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem81->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 221, 130);
		Form3->Label1->Text = Form1->ListBoxItem81->Text;
		Form3->Label3->Text = "238, 221, 130";
		Form3->Label5->Text = "#EEDD82";
		Form3->Label7->Text = "LightGoldenrod";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem269->IsSelected == true || Green2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 238, 0);
		Form3->Label1->Text = Form1->ListBoxItem269->Text;
		Form3->Label3->Text = "0, 238, 0";
		Form3->Label5->Text = "#00EE00";
		Form3->Label7->Text = "Green2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem257->IsSelected == true || SeaGreen2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(78, 238, 148);
		Form3->Label1->Text = Form1->ListBoxItem257->Text;
		Form3->Label3->Text = "78, 238, 148";
		Form3->Label5->Text = "#4EEE94";
		Form3->Label7->Text = "SeaGreen2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem225->IsSelected == true || LightCyan2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(209, 238, 238);
		Form3->Label1->Text = Form1->ListBoxItem225->Text;
		Form3->Label3->Text = "209, 238, 238";
		Form3->Label5->Text = "#D1EEEE";
		Form3->Label7->Text = "LightCyan2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem281->IsSelected == true || DarkOliveGreen2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(188, 238, 104);
		Form3->Label1->Text = Form1->ListBoxItem281->Text;
		Form3->Label3->Text = "188, 238, 104";
		Form3->Label5->Text = "#BCEE68";
		Form3->Label7->Text = "DarkOliveGreen2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem222->IsSelected == true || LightBlue3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(154, 192, 205);
		Form3->Label1->Text = Form1->ListBoxItem222->Text;
		Form3->Label3->Text = "154, 192, 205";
		Form3->Label5->Text = "#9AC0CD";
		Form3->Label7->Text = "LightBlue3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem134->IsSelected == true || Seashell3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 197, 191);
		Form3->Label1->Text = Form1->ListBoxItem134->Text;
		Form3->Label3->Text = "205, 197, 191";
		Form3->Label5->Text = "#CDC5BF";
		Form3->Label7->Text = "Seashell3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem77->IsSelected == true || LightGoldenrodYellow->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(250, 250, 210);
		Form3->Label1->Text = Form1->ListBoxItem77->Text;
		Form3->Label3->Text = "250, 250, 210";
		Form3->Label5->Text = "#FAFAD2";
		Form3->Label7->Text = "LightGoldenrodYellow";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem277->IsSelected == true || OliveDrab2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(179, 238, 58);
		Form3->Label1->Text = Form1->ListBoxItem277->Text;
		Form3->Label3->Text = "179, 238, 58";
		Form3->Label5->Text = "#B3EE3A";
		Form3->Label7->Text = "OliveDrab2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem48->IsSelected == true || LightBlue->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(173, 216, 230);
		Form3->Label1->Text = Form1->ListBoxItem48->Text;
		Form3->Label3->Text = "173, 216, 230";
		Form3->Label5->Text = "#ADD8E6";
		Form3->Label7->Text = "LightBlue";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem217->IsSelected == true || LightSteelBlue2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(188, 210, 238);
		Form3->Label1->Text = Form1->ListBoxItem217->Text;
		Form3->Label3->Text = "188, 210, 238";
		Form3->Label5->Text = "#BCD2EE";
		Form3->Label7->Text = "LightSteelBlue2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem197->IsSelected == true || SteelBlue2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(92, 172, 238);
		Form3->Label1->Text = Form1->ListBoxItem197->Text;
		Form3->Label3->Text = "92, 172, 238";
		Form3->Label5->Text = "#5CACEE";
		Form3->Label7->Text = "SteelBlue2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem278->IsSelected == true || OliveDrab3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(154, 205, 50);
		Form3->Label1->Text = Form1->ListBoxItem278->Text;
		Form3->Label3->Text = "154, 205, 50";
		Form3->Label5->Text = "#9ACD32";
		Form3->Label7->Text = "OliveDrab3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem407->IsSelected == true || VioletRed3->IsSelected == true)
	{
		Form3->buf2->Text = ListBox1->ItemIndex; //Присваиваем текущее значение выделенного ListBoxItem
		Form3->Rectangle1->Fill->Color = MakeColor(205, 50, 120);
		Form3->Label1->Text = Form1->ListBoxItem407->Text;
		Form3->Label3->Text = "205, 50, 120";
		Form3->Label5->Text = "#CD3278";
		Form3->Label7->Text = "VioletRed3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem233->IsSelected == true || CadetBlue2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(142, 229, 238);
		Form3->Label1->Text = Form1->ListBoxItem233->Text;
		Form3->Label3->Text = "142, 229, 238";
		Form3->Label5->Text = "#8EE5EE";
		Form3->Label7->Text = "CadetBlue2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem249->IsSelected == true || Aquamarine2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(118, 238, 198);
		Form3->Label1->Text = Form1->ListBoxItem249->Text;
		Form3->Label3->Text = "118, 238, 198";
		Form3->Label5->Text = "#76EEC6";
		Form3->Label7->Text = "Aquamarine2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem119->IsSelected == true || Plum->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(221, 160, 221);
		Form3->Label1->Text = Form1->ListBoxItem119->Text;
		Form3->Label3->Text = "221, 160, 221";
		Form3->Label5->Text = "#DDA0DD";
		Form3->Label7->Text = "Plum";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem121->IsSelected == true || MediumOrchid->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(186, 85, 211);
		Form3->Label1->Text = Form1->ListBoxItem121->Text;
		Form3->Label3->Text = "186, 85, 211";
		Form3->Label5->Text = "#BA55D3";
		Form3->Label7->Text = "MediumOrchid";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem64->IsSelected == true || LightSeaGreen->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(32, 178, 170);
		Form3->Label1->Text = Form1->ListBoxItem64->Text;
		Form3->Label3->Text = "32, 178, 170";
		Form3->Label5->Text = "#20B2AA";
		Form3->Label7->Text = "LightSeaGreen";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem455->IsSelected == true || LightGreen->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(144, 238, 144);
		Form3->Label1->Text = Form1->ListBoxItem455->Text;
		Form3->Label3->Text = "144, 238, 144";
		Form3->Label5->Text = "#90EE90";
		Form3->Label7->Text = "LightGreen";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem133->IsSelected == true || Seashell2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 229, 222);
		Form3->Label1->Text = Form1->ListBoxItem133->Text;
		Form3->Label3->Text = "238, 229, 222";
		Form3->Label5->Text = "#EEE5DE";
		Form3->Label7->Text = "Seashell2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem111->IsSelected == true || Pink->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 192, 203);
		Form3->Label1->Text = Form1->ListBoxItem111->Text;
		Form3->Label3->Text = "255, 192, 203";
		Form3->Label5->Text = "#FFC0CB";
		Form3->Label7->Text = "Pink";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem414->IsSelected == true || Orchid2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 122, 233);
		Form3->Label1->Text = Form1->ListBoxItem414->Text;
		Form3->Label3->Text = "238, 122, 233";
		Form3->Label5->Text = "#EE7AE9";
		Form3->Label7->Text = "Orchid2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem387->IsSelected == true || HotPink3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 96, 144);
		Form3->Label1->Text = Form1->ListBoxItem387->Text;
		Form3->Label3->Text = "205, 96, 144";
		Form3->Label5->Text = "#CD6090";
		Form3->Label7->Text = "HotPink3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem392->IsSelected == true || Pink4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 99, 108);
		Form3->Label1->Text = Form1->ListBoxItem392->Text;
		Form3->Label3->Text = "139, 99, 108";
		Form3->Label5->Text = "#8B636C";
		Form3->Label7->Text = "Pink4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem388->IsSelected == true || HotPink4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 58, 98);
		Form3->Label1->Text = Form1->ListBoxItem388->Text;
		Form3->Label3->Text = "139, 58, 98";
		Form3->Label5->Text = "#8B3A62";
		Form3->Label7->Text = "HotPink4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem114->IsSelected == true || MaroonColor->IsSelected == true || Maroon->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(176, 48, 96);
		Form3->Label1->Text = Form1->ListBoxItem114->Text;
		Form3->Label3->Text = "176, 48, 96";
		Form3->Label5->Text = "#B03060";
		Form3->Label7->Text = "Maroon";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem396->IsSelected == true || LightPink4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 95, 101);
		Form3->Label1->Text = Form1->ListBoxItem396->Text;
		Form3->Label3->Text = "139, 95, 101";
		Form3->Label5->Text = "#8B5F65";
		Form3->Label7->Text = "LightPink4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem24->IsSelected == true || LavenderBlush->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 240, 245);
		Form3->Label1->Text = Form1->ListBoxItem24->Text;
		Form3->Label3->Text = "255, 240, 245";
		Form3->Label5->Text = "#FFF0F5";
		Form3->Label7->Text = "LavenderBlush";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem386->IsSelected == true || HotPink2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 106, 167);
		Form3->Label1->Text = Form1->ListBoxItem386->Text;
		Form3->Label3->Text = "238, 106, 167";
		Form3->Label5->Text = "#EE6AA7";
		Form3->Label7->Text = "HotPink2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem84->IsSelected == true || RosyBrown->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(188, 143, 143);
		Form3->Label1->Text = Form1->ListBoxItem84->Text;
		Form3->Label3->Text = "188, 143, 143";
		Form3->Label5->Text = "#BC8F8F";
		Form3->Label7->Text = "RosyBrown";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem395->IsSelected == true || LightPink3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 140, 149);
		Form3->Label1->Text = Form1->ListBoxItem395->Text;
		Form3->Label3->Text = "205, 140, 149";
		Form3->Label5->Text = "#CD8C95";
		Form3->Label7->Text = "LightPink3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem167->IsSelected == true || Honeydew4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(131, 139, 131);
		Form3->Label1->Text = Form1->ListBoxItem167->Text;
		Form3->Label3->Text = "131, 139, 131";
		Form3->Label5->Text = "#838B83";
		Form3->Label7->Text = "Honeydew4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem93->IsSelected == true || Wheat->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(245, 222, 179);
		Form3->Label1->Text = Form1->ListBoxItem93->Text;
		Form3->Label3->Text = "245, 222, 179";
		Form3->Label5->Text = "#F5DEB3";
		Form3->Label7->Text = "Wheat";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem125->IsSelected == true || Purple->IsSelected == true || PurpleColor->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(160, 32, 240);
		Form3->Label1->Text = Form1->ListBoxItem125->Text;
		Form3->Label3->Text = "160, 32, 240";
		Form3->Label5->Text = "#A020F0";
		Form3->Label7->Text = "Purple";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem170->IsSelected == true || LavenderBlush3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 193, 197);
		Form3->Label1->Text = Form1->ListBoxItem170->Text;
		Form3->Label3->Text = "205, 193, 197";
		Form3->Label5->Text = "#CDC1C5";
		Form3->Label7->Text = "LavenderBlush3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem315->IsSelected == true || RosyBrown4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 105, 105);
		Form3->Label1->Text = Form1->ListBoxItem315->Text;
		Form3->Label3->Text = "139, 105, 105";
		Form3->Label5->Text = "#8B6969";
		Form3->Label7->Text = "RosyBrown4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem117->IsSelected == true || Magenta->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 0, 255);
		Form3->Label1->Text = Form1->ListBoxItem117->Text;
		Form3->Label3->Text = "255, 0, 255";
		Form3->Label5->Text = "#FF00FF";
		Form3->Label7->Text = "Magenta";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem126->IsSelected == true || MediumPurple->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(147, 112, 219);
		Form3->Label1->Text = Form1->ListBoxItem126->Text;
		Form3->Label3->Text = "000, 000, 000";
		Form3->Label5->Text = "#9370DB";
		Form3->Label7->Text = "MediumPurple";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem427->IsSelected == true || DarkOrchid3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(154, 50, 205);
		Form3->Label1->Text = Form1->ListBoxItem427->Text;
		Form3->Label3->Text = "154, 50, 205";
		Form3->Label5->Text = "#9A32CD";
		Form3->Label7->Text = "DarkOrchid3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem2->IsSelected == true || GhostWhite->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(248, 248, 255);
		Form3->Label1->Text = Form1->ListBoxItem2->Text;
		Form3->Label3->Text = "248, 248, 255";
		Form3->Label5->Text = "#F8F8FF";
		Form3->Label7->Text = "GhostWhite";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem39->IsSelected == true || MediumBlue->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 0, 205);
		Form3->Label1->Text = Form1->ListBoxItem39->Text;
		Form3->Label3->Text = "0, 0, 205";
		Form3->Label5->Text = "#0000CD";
		Form3->Label7->Text = "MediumBlue";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem9->IsSelected == true || PapayaWhip->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 239, 213);
		Form3->Label1->Text = Form1->ListBoxItem9->Text;
		Form3->Label3->Text = "255, 239, 213";
		Form3->Label5->Text = "#FFEFD5";
		Form3->Label7->Text = "PapayaWhip";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem94->IsSelected == true || SandyBrown->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(244, 164, 96);
		Form3->Label1->Text = Form1->ListBoxItem94->Text;
		Form3->Label3->Text = "244, 164, 96";
		Form3->Label5->Text = "#F4A460";
		Form3->Label7->Text = "SandyBrown";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem290->IsSelected == true || LightGoldenrod3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 190, 112);
		Form3->Label1->Text = Form1->ListBoxItem290->Text;
		Form3->Label3->Text = "205, 190, 112";
		Form3->Label5->Text = "#CDBE70";
		Form3->Label7->Text = "LightGoldenrod3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem334->IsSelected == true || Tan3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 133, 63);
		Form3->Label1->Text = Form1->ListBoxItem334->Text;
		Form3->Label3->Text = "205, 133, 63";
		Form3->Label5->Text = "#CD853F";
		Form3->Label7->Text = "Tan3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem145->IsSelected == true || PeachPuff2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 203, 173);
		Form3->Label1->Text = Form1->ListBoxItem145->Text;
		Form3->Label3->Text = "238, 203, 173";
		Form3->Label5->Text = "#EECBAD";
		Form3->Label7->Text = "PeachPuff2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem12->IsSelected == true || PeachPuff->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 218, 185);
		Form3->Label1->Text = Form1->ListBoxItem12->Text;
		Form3->Label3->Text = "255, 218, 185";
		Form3->Label5->Text = "#FFDAB9";
		Form3->Label7->Text = "PeachPuff";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem146->IsSelected == true || PeachPuff3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 175, 149);
		Form3->Label1->Text = Form1->ListBoxItem146->Text;
		Form3->Label3->Text = "205, 175, 149";
		Form3->Label5->Text = "#CDAF95";
		Form3->Label7->Text = "PeachPuff3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem446->IsSelected == true || Grey61->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(156, 156, 156);
		Form3->Label1->Text = Form1->ListBoxItem446->Text;
		Form3->Label3->Text = "156, 156, 156";
		Form3->Label5->Text = "#9C9C9C";
		Form3->Label7->Text = "Grey61";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem205->IsSelected == true || SkyBlue2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(126, 192, 238);
		Form3->Label1->Text = Form1->ListBoxItem205->Text;
		Form3->Label3->Text = "126, 192, 238";
		Form3->Label5->Text = "#7EC0EE";
		Form3->Label7->Text = "SkyBlue2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem262->IsSelected == true || PaleGreen3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(124, 205, 124);
		Form3->Label1->Text = Form1->ListBoxItem262->Text;
		Form3->Label3->Text = "124, 205, 124";
		Form3->Label5->Text = "#7CCD7C";
		Form3->Label7->Text = "PaleGreen3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem229->IsSelected == true || PaleTurquoise2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(174, 238, 238);
		Form3->Label1->Text = Form1->ListBoxItem229->Text;
		Form3->Label3->Text = "174, 238, 238";
		Form3->Label5->Text = "#AEEEEE";
		Form3->Label7->Text = "PaleTurquoise2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem87->IsSelected == true || Sienna->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(160, 82, 45);
		Form3->Label1->Text = Form1->ListBoxItem87->Text;
		Form3->Label3->Text = "160, 82, 45";
		Form3->Label5->Text = "#A0522D";
		Form3->Label7->Text = "Sienna";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem423->IsSelected == true || MediumOrchid3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(180, 82, 205);
		Form3->Label1->Text = Form1->ListBoxItem423->Text;
		Form3->Label3->Text = "180, 82, 205";
		Form3->Label5->Text = "#B452CD";
		Form3->Label7->Text = "MediumOrchid3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem360->IsSelected == true || Orange4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 90, 0);
		Form3->Label1->Text = Form1->ListBoxItem360->Text;
		Form3->Label3->Text = "139, 90, 0";
		Form3->Label5->Text = "#8B5A00";
		Form3->Label7->Text = "Orange4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem102->IsSelected == true || Orange->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 160, 0);
		Form3->Label1->Text = Form1->ListBoxItem102->Text;
		Form3->Label3->Text = "255, 160, 0";
		Form3->Label5->Text = "#FFA500";
		Form3->Label7->Text = "Orange";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem107->IsSelected == true || OrangeRed->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 69, 0);
		Form3->Label1->Text = Form1->ListBoxItem107->Text;
		Form3->Label3->Text = "255, 69, 0";
		Form3->Label5->Text = "#FF4500";
		Form3->Label7->Text = "OrangeRed";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem282->IsSelected == true || DarkOliveGreen3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(162, 205, 90);
		Form3->Label1->Text = Form1->ListBoxItem282->Text;
		Form3->Label3->Text = "162, 205, 90";
		Form3->Label5->Text = "#A2CD5A";
		Form3->Label7->Text = "DarkOliveGreen3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem266->IsSelected == true || SpringGreen3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 205, 102);
		Form3->Label1->Text = Form1->ListBoxItem266->Text;
		Form3->Label3->Text = "0, 205, 102";
		Form3->Label5->Text = "#00CD66";
		Form3->Label7->Text = "SpringGreen3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem279->IsSelected == true || OliveDrab4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(105, 139, 34);
		Form3->Label1->Text = Form1->ListBoxItem279->Text;
		Form3->Label3->Text = "105, 139, 34";
		Form3->Label5->Text = "#698B22";
		Form3->Label7->Text = "OliveDrab4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem44->IsSelected == true || SkyBlue->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(135, 206, 235);
		Form3->Label1->Text = Form1->ListBoxItem44->Text;
		Form3->Label3->Text = "135, 206, 235";
		Form3->Label5->Text = "#87CEEB";
		Form3->Label7->Text = "SkyBlue";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem424->IsSelected == true || MediumOrchid4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(122, 55, 139);
		Form3->Label1->Text = Form1->ListBoxItem424->Text;
		Form3->Label3->Text = "122, 55, 139";
		Form3->Label5->Text = "#7A378B";
		Form3->Label7->Text = "MediumOrchid4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem412->IsSelected == true || Magenta4->IsSelected == true)
	{
		Form3->buf2->Text = ListBox1->ItemIndex; //Присваиваем текущее значение выделенного ListBoxItem
		Form3->Rectangle1->Fill->Color = MakeColor(139, 0, 139);
		Form3->Label1->Text = Form1->ListBoxItem412->Text;
		Form3->Label3->Text = "139, 0, 139";
		Form3->Label5->Text = "#8B008B";
		Form3->Label7->Text = "Magenta4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem32->IsSelected == true || MidnightBlue->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(25, 25, 112);
		Form3->Label1->Text = Form1->ListBoxItem32->Text;
		Form3->Label3->Text = "25, 25, 112";
		Form3->Label5->Text = "#191970";
		Form3->Label7->Text = "MidnightBlue";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem201->IsSelected == true || DeepSkyBlue2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 178, 238);
		Form3->Label1->Text = Form1->ListBoxItem201->Text;
		Form3->Label3->Text = "0, 178, 238";
		Form3->Label5->Text = "#00B2EE";
		Form3->Label7->Text = "DeepSkyBlue2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem151->IsSelected == true || NavajoWhite4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 121, 94);
		Form3->Label1->Text = Form1->ListBoxItem151->Text;
		Form3->Label3->Text = "139, 121, 94";
		Form3->Label5->Text = "#8B795E";
		Form3->Label7->Text = "NavajoWhite4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem149->IsSelected == true || NavajoWhite2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 207, 161);
		Form3->Label1->Text = Form1->ListBoxItem149->Text;
		Form3->Label3->Text = "238, 207, 161";
		Form3->Label5->Text = "#EECFA1";
		Form3->Label7->Text = "NavajoWhite2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem150->IsSelected == true || NavajoWhite3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 179, 139);
		Form3->Label1->Text = Form1->ListBoxItem150->Text;
		Form3->Label3->Text = "205, 179, 139";
		Form3->Label5->Text = "#CDB38B";
		Form3->Label7->Text = "NavajoWhite3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem13->IsSelected == true || NavajoWhite->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 222, 173);
		Form3->Label1->Text = Form1->ListBoxItem13->Text;
		Form3->Label3->Text = "255, 222, 173";
		Form3->Label5->Text = "#FFDEAD";
		Form3->Label7->Text = "NavajoWhite";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem20->IsSelected == true || MintCream->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(245, 255, 250);
		Form3->Label1->Text = Form1->ListBoxItem20->Text;
		Form3->Label3->Text = "245, 255, 250";
		Form3->Label5->Text = "#F5FFFA";
		Form3->Label7->Text = "MintCream";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem51->IsSelected == true || DarkTurquoise->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 206, 209);
		Form3->Label1->Text = Form1->ListBoxItem51->Text;
		Form3->Label3->Text = "0, 206, 209";
		Form3->Label5->Text = "#00CED1";
		Form3->Label7->Text = "DarkTurquoise";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem6->IsSelected == true || OldLace->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(253, 245, 230);
		Form3->Label1->Text = Form1->ListBoxItem6->Text;
		Form3->Label3->Text = "253, 245, 230";
		Form3->Label5->Text = "#FDF5E6";
		Form3->Label7->Text = "OldLace";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem135->IsSelected == true || Seashell4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 134, 130);
		Form3->Label1->Text = Form1->ListBoxItem135->Text;
		Form3->Label3->Text = "139, 134, 130";
		Form3->Label5->Text = "#8B8682";
		Form3->Label7->Text = "Seashell4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem339->IsSelected == true || Chocolate4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 69, 19);
		Form3->Label1->Text = Form1->ListBoxItem339->Text;
		Form3->Label3->Text = "139, 69, 19";
		Form3->Label5->Text = "#8B4513";
		Form3->Label7->Text = "Chocolate4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem186->IsSelected == true || RoyalBlue3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(58, 95, 205);
		Form3->Label1->Text = Form1->ListBoxItem186->Text;
		Form3->Label3->Text = "58, 95, 205";
		Form3->Label5->Text = "#3A5FCD";
		Form3->Label7->Text = "RoyalBlue3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem165->IsSelected == true || Honeydew2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(224, 238, 224);
		Form3->Label1->Text = Form1->ListBoxItem165->Text;
		Form3->Label3->Text = "224, 238, 224";
		Form3->Label5->Text = "#E0EEE0";
		Form3->Label7->Text = "Honeydew2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem61->IsSelected == true || DarkSeaGreen->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(143, 188, 143);
		Form3->Label1->Text = Form1->ListBoxItem61->Text;
		Form3->Label3->Text = "143, 188, 143";
		Form3->Label5->Text = "#8FBC8F";
		Form3->Label7->Text = "DarkSeaGreen";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem255->IsSelected == true || DarkSeaGreen4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(105, 139, 105);
		Form3->Label1->Text = Form1->ListBoxItem255->Text;
		Form3->Label3->Text = "105, 139, 105";
		Form3->Label5->Text = "#698B69";
		Form3->Label7->Text = "DarkSeaGreen4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem254->IsSelected == true || DarkSeaGreen3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(155, 205, 155);
		Form3->Label1->Text = Form1->ListBoxItem254->Text;
		Form3->Label3->Text = "155, 205, 155";
		Form3->Label5->Text = "#9BCD9B";
		Form3->Label7->Text = "DarkSeaGreen3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem18->IsSelected == true || Seashell->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 245, 238);
		Form3->Label1->Text = Form1->ListBoxItem18->Text;
		Form3->Label3->Text = "255, 245, 238";
		Form3->Label5->Text = "#FFF5EE";
		Form3->Label7->Text = "Seashell";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem62->IsSelected == true || AquaColor->IsSelected == true || Aqua->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(46, 139, 87);
		Form3->Label1->Text = Form1->ListBoxItem62->Text;
		Form3->Label3->Text = "46, 139, 87";
		Form3->Label5->Text = "#2E8B57";
		Form3->Label7->Text = "Aqua";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem443->IsSelected == true || Grey31->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(79, 79, 79);
		Form3->Label1->Text = Form1->ListBoxItem443->Text;
		Form3->Label3->Text = "79, 79, 79";
		Form3->Label5->Text = "#4F4F4F";
		Form3->Label7->Text = "Grey31";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem14->IsSelected == true || Moccasin->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 228, 181);
		Form3->Label1->Text = Form1->ListBoxItem14->Text;
		Form3->Label3->Text = "255, 228, 181";
		Form3->Label5->Text = "#FFE4B5";
		Form3->Label7->Text = "Moccasin";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem323->IsSelected == true || Sienna4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 71, 38);
		Form3->Label1->Text = Form1->ListBoxItem323->Text;
		Form3->Label3->Text = "139, 71, 38";
		Form3->Label5->Text = "#8B4726";
		Form3->Label7->Text = "Sienna4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem378->IsSelected == true || Red2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 0, 0);
		Form3->Label1->Text = Form1->ListBoxItem378->Text;
		Form3->Label3->Text = "238, 000, 000";
		Form3->Label5->Text = "#EE0000";
		Form3->Label7->Text = "Red2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem7->IsSelected == true || Linen->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(250, 240, 230);
		Form3->Label1->Text = Form1->ListBoxItem7->Text;
		Form3->Label3->Text = "250, 240, 230";
		Form3->Label5->Text = "#FAF0E6";
		Form3->Label7->Text = "Linen";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem350->IsSelected == true || Salmon2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 130, 98);
		Form3->Label1->Text = Form1->ListBoxItem350->Text;
		Form3->Label3->Text = "238, 130, 98";
		Form3->Label5->Text = "#EE8262";
		Form3->Label7->Text = "Salmon2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem17->IsSelected == true || LemonChiffon->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 250, 205);
		Form3->Label1->Text = Form1->ListBoxItem17->Text;
		Form3->Label3->Text = "255, 250, 205";
		Form3->Label5->Text = "#FFFACD";
		Form3->Label7->Text = "LemonChiffon";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem154->IsSelected == true || LemonChiffon3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 201, 165);
		Form3->Label1->Text = Form1->ListBoxItem154->Text;
		Form3->Label3->Text = "205, 201, 165";
		Form3->Label5->Text = "#CDC9A5";
		Form3->Label7->Text = "LemonChiffon3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem153->IsSelected == true || LemonChiffon2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 233, 191);
		Form3->Label1->Text = Form1->ListBoxItem153->Text;
		Form3->Label3->Text = "238, 233, 191";
		Form3->Label5->Text = "#EEE9BF";
		Form3->Label7->Text = "LemonChiffon2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem430->IsSelected == true || Purple2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(145, 44, 238);
		Form3->Label1->Text = Form1->ListBoxItem430->Text;
		Form3->Label3->Text = "145, 44, 238";
		Form3->Label5->Text = "#912CEE";
		Form3->Label7->Text = "Purple2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem411->IsSelected == true || Magenta3->IsSelected == true)
	{
		Form3->buf2->Text = ListBox1->ItemIndex; //Присваиваем текущее значение выделенного ListBoxItem
		Form3->Rectangle1->Fill->Color = MakeColor(205, 0, 205);
		Form3->Label1->Text = Form1->ListBoxItem411->Text;
		Form3->Label3->Text = "205, 0, 205";
		Form3->Label5->Text = "#CD00CD";
		Form3->Label7->Text = "Magenta3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem120->IsSelected == true || Orchid->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(218, 112, 214);
		Form3->Label1->Text = Form1->ListBoxItem120->Text;
		Form3->Label3->Text = "218, 112, 214";
		Form3->Label5->Text = "#DA70D6";
		Form3->Label7->Text = "Orchid";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem270->IsSelected == true || Green3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 205, 0);
		Form3->Label1->Text = Form1->ListBoxItem270->Text;
		Form3->Label3->Text = "0, 205, 0";
		Form3->Label5->Text = "#00CD00";
		Form3->Label7->Text = "Green3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem177->IsSelected == true || Azure2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(224, 238, 238);
		Form3->Label1->Text = Form1->ListBoxItem177->Text;
		Form3->Label3->Text = "224, 238, 238";
		Form3->Label5->Text = "#E0EEEE";
		Form3->Label7->Text = "Azure2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem21->IsSelected == true || Azure->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(240, 255, 255);
		Form3->Label1->Text = Form1->ListBoxItem21->Text;
		Form3->Label3->Text = "240, 255, 255";
		Form3->Label5->Text = "#F0FFFF";
		Form3->Label7->Text = "Azure";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem178->IsSelected == true || Azure3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(193, 205, 205);
		Form3->Label1->Text = Form1->ListBoxItem178->Text;
		Form3->Label3->Text = "193, 205, 205";
		Form3->Label5->Text = "#C1CDCD";
		Form3->Label7->Text = "Azure3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem179->IsSelected == true || Azure4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(131, 139, 139);
		Form3->Label1->Text = Form1->ListBoxItem179->Text;
		Form3->Label3->Text = "131, 139, 139";
		Form3->Label5->Text = "#838B8B";
		Form3->Label7->Text = "Azure4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem23->IsSelected == true || Lavender->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(230, 230, 250);
		Form3->Label1->Text = Form1->ListBoxItem23->Text;
		Form3->Label3->Text = "230, 230, 250";
		Form3->Label5->Text = "#E6E6FA";
		Form3->Label7->Text = "Lavender";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem309->IsSelected == true || DarkGoldenrod2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 173, 14);
		Form3->Label1->Text = Form1->ListBoxItem309->Text;
		Form3->Label3->Text = "238, 173, 14";
		Form3->Label5->Text = "#EEAD0E";
		Form3->Label7->Text = "DarkGoldenrod2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem108->IsSelected == true || RedColor->IsSelected == true || Red->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 0, 0);
		Form3->Label1->Text = Form1->ListBoxItem108->Text;
		Form3->Label3->Text = "255, 0, 0";
		Form3->Label5->Text = "#FF0000";
		Form3->Label7->Text = "Red";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem375->IsSelected == true || OrangeRed3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 55, 0);
		Form3->Label1->Text = Form1->ListBoxItem375->Text;
		Form3->Label3->Text = "205, 55, 0";
		Form3->Label5->Text = "#CD3700";
		Form3->Label7->Text = "OrangeRed3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem116->IsSelected == true || VioletRed->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(208, 32, 144);
		Form3->Label1->Text = Form1->ListBoxItem116->Text;
		Form3->Label3->Text = "208, 32, 144";
		Form3->Label5->Text = "#D02090";
		Form3->Label7->Text = "VioletRed";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem98->IsSelected == true || Brown->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(165, 42, 42);
		Form3->Label1->Text = Form1->ListBoxItem98->Text;
		Form3->Label3->Text = "165, 42, 42";
		Form3->Label5->Text = "#A52A2A4";
		Form3->Label7->Text = "Brown";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem40->IsSelected == true || RoyalBlue->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(65, 105, 225);
		Form3->Label1->Text = Form1->ListBoxItem40->Text;
		Form3->Label3->Text = "65, 105, 225";
		Form3->Label5->Text = "#4169E1";
		Form3->Label7->Text = "RoyalBlue";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem403->IsSelected == true || Maroon3->IsSelected == true)
	{
		Form3->buf2->Text = ListBox1->ItemIndex; //Присваиваем текущее значение выделенного ListBoxItem
		Form3->Rectangle1->Fill->Color = MakeColor(205, 41, 144);
		Form3->Label1->Text = Form1->ListBoxItem403->Text;
		Form3->Label3->Text = "205, 41, 144";
		Form3->Label5->Text = "#CD2990";
		Form3->Label7->Text = "Maroon3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem445->IsSelected == true || Grey51->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(130, 130, 130);
		Form3->Label1->Text = Form1->ListBoxItem445->Text;
		Form3->Label3->Text = "130, 130, 130";
		Form3->Label5->Text = "#828282";
		Form3->Label7->Text = "Grey51";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem326->IsSelected == true || BurlyWood3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 170, 125);
		Form3->Label1->Text = Form1->ListBoxItem326->Text;
		Form3->Label3->Text = "205, 170, 125";
		Form3->Label5->Text = "#CDAA7D";
		Form3->Label7->Text = "Burlywood3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem321->IsSelected == true || Sienna2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 121, 66);
		Form3->Label1->Text = Form1->ListBoxItem321->Text;
		Form3->Label3->Text = "238, 121, 66";
		Form3->Label5->Text = "#EE7942";
		Form3->Label7->Text = "Sienna2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem322->IsSelected == true || Sienna3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 104, 57);
		Form3->Label1->Text = Form1->ListBoxItem322->Text;
		Form3->Label3->Text = "205, 104, 57";
		Form3->Label5->Text = "#CD6839";
		Form3->Label7->Text = "Sienna3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem83->IsSelected == true || DarkGoldenrodColor->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(184, 134, 11);
		Form3->Label1->Text = Form1->ListBoxItem83->Text;
		Form3->Label3->Text = "184, 134, 11";
		Form3->Label5->Text = "#B8860B";
		Form3->Label7->Text = "DarkGoldenrod";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem171->IsSelected == true || LavenderBlush4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 131, 134);
		Form3->Label1->Text = Form1->ListBoxItem171->Text;
		Form3->Label3->Text = "139, 131, 134";
		Form3->Label5->Text = "#8B8386";
		Form3->Label7->Text = "LavenderBlush4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem96->IsSelected == true || Chocolate->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(210, 105, 30);
		Form3->Label1->Text = Form1->ListBoxItem96->Text;
		Form3->Label3->Text = "210, 105, 30";
		Form3->Label5->Text = "#D2691E";
		Form3->Label7->Text = "Chocolate";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem319->IsSelected == true || IndianRed4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 58, 58);
		Form3->Label1->Text = Form1->ListBoxItem319->Text;
		Form3->Label3->Text = "139, 58, 58";
		Form3->Label5->Text = "#8B3A3A";
		Form3->Label7->Text = "IndianRed4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem104->IsSelected == true || Coral->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 127, 80);
		Form3->Label1->Text = Form1->ListBoxItem104->Text;
		Form3->Label3->Text = "255, 127, 80";
		Form3->Label5->Text = "#FF7F50";
		Form3->Label7->Text = "Coral";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem366->IsSelected == true || Coral2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 106, 80);
		Form3->Label1->Text = Form1->ListBoxItem366->Text;
		Form3->Label3->Text = "238, 106, 80";
		Form3->Label5->Text = "#EE6A50";
		Form3->Label7->Text = "Coral2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem97->IsSelected == true || Firebrick->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(178, 34, 34);
		Form3->Label1->Text = Form1->ListBoxItem97->Text;
		Form3->Label3->Text = "178, 34, 34";
		Form3->Label5->Text = "#B22222";
		Form3->Label7->Text = "Firebrick";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem374->IsSelected == true || OrangeRed2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 64, 0);
		Form3->Label1->Text = Form1->ListBoxItem374->Text;
		Form3->Label3->Text = "238, 64, 0";
		Form3->Label5->Text = "#EE4000";
		Form3->Label7->Text = "OrangeRed2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem368->IsSelected == true || Coral4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 62, 47);
		Form3->Label1->Text = Form1->ListBoxItem368->Text;
		Form3->Label3->Text = "139, 62, 47";
		Form3->Label5->Text = "#8B3E2F";
		Form3->Label7->Text = "Coral4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem347->IsSelected == true || Brown3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 51, 51);
		Form3->Label1->Text = Form1->ListBoxItem347->Text;
		Form3->Label3->Text = "205, 51, 51";
		Form3->Label5->Text = "#CD3333";
		Form3->Label7->Text = "Brown3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem341->IsSelected == true || Firebrick2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 44, 44);
		Form3->Label1->Text = Form1->ListBoxItem341->Text;
		Form3->Label3->Text = "238, 44, 44";
		Form3->Label5->Text = "#EE2C2C";
		Form3->Label7->Text = "Firebrick2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem346->IsSelected == true || Brown2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 59, 59);
		Form3->Label1->Text = Form1->ListBoxItem346->Text;
		Form3->Label3->Text = "238, 59, 59";
		Form3->Label5->Text = "#EE3B3B";
		Form3->Label7->Text = "Brown2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem155->IsSelected == true || LemonChiffon4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 137, 112);
		Form3->Label1->Text = Form1->ListBoxItem155->Text;
		Form3->Label3->Text = "139, 137, 112";
		Form3->Label5->Text = "#8B8970";
		Form3->Label7->Text = "LemonChiffon4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem85->IsSelected == true || IndianRed->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 92, 92);
		Form3->Label1->Text = Form1->ListBoxItem85->Text;
		Form3->Label3->Text = "205, 92, 92";
		Form3->Label5->Text = "#CD5C5C";
		Form3->Label7->Text = "IndianRed";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem124->IsSelected == true || BlueViolet->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(138, 43, 226);
		Form3->Label1->Text = Form1->ListBoxItem124->Text;
		Form3->Label3->Text = "138, 43, 226";
		Form3->Label5->Text = "#8A2BE2";
		Form3->Label7->Text = "BlueViolet";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem258->IsSelected == true || SeaGreen3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(67, 205, 128);
		Form3->Label1->Text = Form1->ListBoxItem258->Text;
		Form3->Label3->Text = "67, 205, 128";
		Form3->Label5->Text = "#43CD80";
		Form3->Label7->Text = "SeaGreen3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem359->IsSelected == true || Orange3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 133, 0);
		Form3->Label1->Text = Form1->ListBoxItem359->Text;
		Form3->Label3->Text = "205, 133, 0";
		Form3->Label5->Text = "#CD8500";
		Form3->Label7->Text = "Orange3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem80->IsSelected == true || Gold->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 215, 0);
		Form3->Label1->Text = Form1->ListBoxItem80->Text;
		Form3->Label3->Text = "255, 215, 0";
		Form3->Label5->Text = "#FFD700";
		Form3->Label7->Text = "Gold";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem82->IsSelected == true || Goldenrod->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(218, 165, 32);
		Form3->Label1->Text = Form1->ListBoxItem82->Text;
		Form3->Label3->Text = "218, 165, 32";
		Form3->Label5->Text = "#DAA520";
		Form3->Label7->Text = "Goldenrod";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem306->IsSelected == true || Goldenrod3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 155, 29);
		Form3->Label1->Text = Form1->ListBoxItem306->Text;
		Form3->Label3->Text = "205, 155, 29";
		Form3->Label5->Text = "#CD9B1D";
		Form3->Label7->Text = "Goldenrod3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem58->IsSelected == true || MediumAquamarine->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(102, 205, 170);
		Form3->Label1->Text = Form1->ListBoxItem58->Text;
		Form3->Label3->Text = "102, 205, 170";
		Form3->Label5->Text = "#66CDAA";
		Form3->Label7->Text = "MediumAquamarine";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem63->IsSelected == true || MediumSeaGreen->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(60, 179, 113);
		Form3->Label1->Text = Form1->ListBoxItem63->Text;
		Form3->Label3->Text = "60, 179, 113";
		Form3->Label5->Text = "#3CB371";
		Form3->Label7->Text = "MediumSeaGreen";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem73->IsSelected == true || ForestGreen->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(34, 139, 34);
		Form3->Label1->Text = Form1->ListBoxItem73->Text;
		Form3->Label3->Text = "34, 139, 34";
		Form3->Label5->Text = "#228B22";
		Form3->Label7->Text = "ForestGreen";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem68->IsSelected == true || GreenColor->IsSelected == true || Green->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 255, 0);
		Form3->Label1->Text = Form1->ListBoxItem68->Text;
		Form3->Label3->Text = "0, 255, 0";
		Form3->Label5->Text = "#00FF00";
		Form3->Label7->Text = "Green";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem69->IsSelected == true || Chartreuse->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(127, 255, 0);
		Form3->Label1->Text = Form1->ListBoxItem69->Text;
		Form3->Label3->Text = "127, 255, 0";
		Form3->Label5->Text = "#7FFF00";
		Form3->Label7->Text = "Chartreuse";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem250->IsSelected == true || Aquamarine3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(102, 205, 170);
		Form3->Label1->Text = Form1->ListBoxItem250->Text;
		Form3->Label3->Text = "102, 205, 170";
		Form3->Label5->Text = "#66CDAA";
		Form3->Label7->Text = "Aquamarine3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem71->IsSelected == true || GreenYellow->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(173, 255, 47);
		Form3->Label1->Text = Form1->ListBoxItem71->Text;
		Form3->Label3->Text = "173, 255, 47";
		Form3->Label5->Text = "#ADFF2F";
		Form3->Label7->Text = "GreenYellow";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem67->IsSelected == true || LawnGreen->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(124, 252, 0);
		Form3->Label1->Text = Form1->ListBoxItem67->Text;
		Form3->Label3->Text = "124, 252, 0";
		Form3->Label5->Text = "#7CFC00";
		Form3->Label7->Text = "LawnGreen";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem42->IsSelected == true || DodgerBlue->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(30, 144, 225);
		Form3->Label1->Text = Form1->ListBoxItem42->Text;
		Form3->Label3->Text = "30, 144, 225";
		Form3->Label5->Text = "#1E90FF";
		Form3->Label7->Text = "DodgerBlue";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem231->IsSelected == true || PaleTurquoise4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(102, 139, 139);
		Form3->Label1->Text = Form1->ListBoxItem231->Text;
		Form3->Label3->Text = "102, 139, 139";
		Form3->Label5->Text = "#668B8B";
		Form3->Label7->Text = "PaleTurquoise4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem399->IsSelected == true || PaleVioletRed3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 104, 137);
		Form3->Label1->Text = Form1->ListBoxItem399->Text;
		Form3->Label3->Text = "205, 104, 137";
		Form3->Label5->Text = "#CD6889";
		Form3->Label7->Text = "PaleVioletRed3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem294->IsSelected == true || LightYellow3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 205, 180);
		Form3->Label1->Text = Form1->ListBoxItem294->Text;
		Form3->Label3->Text = "205, 205, 180";
		Form3->Label5->Text = "#CDCDB4";
		Form3->Label7->Text = "LightYellow3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem161->IsSelected == true || Ivory2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 238, 224);
		Form3->Label1->Text = Form1->ListBoxItem161->Text;
		Form3->Label3->Text = "238, 238, 224";
		Form3->Label5->Text = "#EEEEE0";
		Form3->Label7->Text = "Ivory2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem293->IsSelected == true || LightYellow2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 238, 209);
		Form3->Label1->Text = Form1->ListBoxItem293->Text;
		Form3->Label3->Text = "238, 238, 209";
		Form3->Label5->Text = "#EEEED1";
		Form3->Label7->Text = "LightYellow2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem79->IsSelected == true || Yellow->IsSelected == true || YellowColor->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 255, 0);
		Form3->Label1->Text = Form1->ListBoxItem79->Text;
		Form3->Label3->Text = "255, 255, 0";
		Form3->Label5->Text = "#FFFF00";
		Form3->Label7->Text = "Yellow";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem89->IsSelected == true || BurlyWood->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(222, 184, 135);
		Form3->Label1->Text = Form1->ListBoxItem89->Text;
		Form3->Label3->Text = "222, 184, 135";
		Form3->Label5->Text = "#DEB887";
		Form3->Label7->Text = "Burlywood";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem354->IsSelected == true || LightSalmon2->IsSelected == true || LightSalmonColor2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 149, 114);
		Form3->Label1->Text = Form1->ListBoxItem354->Text;
		Form3->Label3->Text = "238, 149, 114";
		Form3->Label5->Text = "#EE9572";
		Form3->Label7->Text = "LightSalmon2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem298->IsSelected == true || Yellow3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 205, 0);
		Form3->Label1->Text = Form1->ListBoxItem298->Text;
		Form3->Label3->Text = "205, 205, 0";
		Form3->Label5->Text = "#CDCD00";
		Form3->Label7->Text = "Yellow3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem297->IsSelected == true || Yellow2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 238, 0);
		Form3->Label1->Text = Form1->ListBoxItem297->Text;
		Form3->Label3->Text = "238, 238, 0";
		Form3->Label5->Text = "#EEEE00";
		Form3->Label7->Text = "Yellow2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem72->IsSelected == true || YellowGreen->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(154, 205, 50);
		Form3->Label1->Text = Form1->ListBoxItem72->Text;
		Form3->Label3->Text = "154, 205, 50";
		Form3->Label5->Text = "#";
		Form3->Label7->Text = "YellowGreen";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem358->IsSelected == true || Orange2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 154, 0);
		Form3->Label1->Text = Form1->ListBoxItem358->Text;
		Form3->Label3->Text = "238, 154, 0";
		Form3->Label5->Text = "#EE9A00";
		Form3->Label7->Text = "Orange2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem448->IsSelected == true || Grey81->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(207, 207, 207);
		Form3->Label1->Text = Form1->ListBoxItem448->Text;
		Form3->Label3->Text = "207, 207, 207";
		Form3->Label5->Text = "#CFCFCF";
		Form3->Label7->Text = "Grey81";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem447->IsSelected == true || Grey71->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(181, 181, 181);
		Form3->Label1->Text = Form1->ListBoxItem447->Text;
		Form3->Label3->Text = "181, 181, 181";
		Form3->Label5->Text = "#B5B5B5";
		Form3->Label7->Text = "Grey71";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem449->IsSelected == true || Grey91->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(232, 232, 232);
		Form3->Label1->Text = Form1->ListBoxItem449->Text;
		Form3->Label3->Text = "232, 232, 232";
		Form3->Label5->Text = "#E8E8E8";
		Form3->Label7->Text = "Grey91";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem129->IsSelected == true || Snow2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 233, 233);
		Form3->Label1->Text = Form1->ListBoxItem129->Text;
		Form3->Label3->Text = "238, 233, 233";
		Form3->Label5->Text = "#EEE9E9";
		Form3->Label7->Text = "Snow2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem95->IsSelected == true || Tan->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(210, 180, 140);
		Form3->Label1->Text = Form1->ListBoxItem95->Text;
		Form3->Label3->Text = "210, 180, 140";
		Form3->Label5->Text = "#D2B48C";
		Form3->Label7->Text = "Tan";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem310->IsSelected == true || DarkGoldenrod3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 149, 12);
		Form3->Label1->Text = Form1->ListBoxItem310->Text;
		Form3->Label3->Text = "205, 149, 12";
		Form3->Label5->Text = "#CD950C";
		Form3->Label7->Text = "DarkGoldenrod3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem436->IsSelected == true || MediumPurple4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(93, 71, 139);
		Form3->Label1->Text = Form1->ListBoxItem436->Text;
		Form3->Label3->Text = "93, 71, 139";
		Form3->Label5->Text = "#5D478B";
		Form3->Label7->Text = "MediumPurple4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem371->IsSelected == true || Tomato3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 79, 57);
		Form3->Label1->Text = Form1->ListBoxItem371->Text;
		Form3->Label3->Text = "205, 79, 57";
		Form3->Label5->Text = "#CD4F39";
		Form3->Label7->Text = "Tomato3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem175->IsSelected == true || MistyRose4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 125, 123);
		Form3->Label1->Text = Form1->ListBoxItem175->Text;
		Form3->Label3->Text = "139, 125, 123";
		Form3->Label5->Text = "#8B7D7B";
		Form3->Label7->Text = "MistyRose4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem147->IsSelected == true || PeachPuff4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 119, 101);
		Form3->Label1->Text = Form1->ListBoxItem147->Text;
		Form3->Label3->Text = "139, 119, 101";
		Form3->Label5->Text = "#8B7765";
		Form3->Label7->Text = "PeachPuff4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem38->IsSelected == true || LightSlateBlue->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(132, 112, 255);
		Form3->Label1->Text = Form1->ListBoxItem38->Text;
		Form3->Label3->Text = "132, 112, 255";
		Form3->Label5->Text = "#8470FF";
		Form3->Label7->Text = "LightSlateBlue";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
    }

	if(ListBoxItem36->IsSelected == true || SlateBlue->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(106, 90, 205);
		Form3->Label1->Text = Form1->ListBoxItem36->Text;
		Form3->Label3->Text = "106, 90, 205";
		Form3->Label5->Text = "#6A5ACD";
		Form3->Label7->Text = "SlateBlue";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem57->IsSelected == true || LightSlateGrey->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(119 , 136, 153);
		Form3->Label1->Text = Form1->ListBoxItem57->Text;
		Form3->Label3->Text = "119 , 136, 153";
		Form3->Label5->Text = "#778899";
		Form3->Label7->Text = "LightSlateGray";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem441->IsSelected == true || Grey11->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(28, 28, 28);
		Form3->Label1->Text = Form1->ListBoxItem441->Text;
		Form3->Label3->Text = "28, 28, 28";
		Form3->Label5->Text = "#1C1C1C";
		Form3->Label7->Text = "Grey11";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem442->IsSelected == true || Grey21->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(54, 54, 54);
		Form3->Label1->Text = Form1->ListBoxItem442->Text;
		Form3->Label3->Text = "54, 54, 54";
		Form3->Label5->Text = "#363636";
		Form3->Label7->Text = "Grey21";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem307->IsSelected == true || Goldenrod4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 105, 20);
		Form3->Label1->Text = Form1->ListBoxItem307->Text;
		Form3->Label3->Text = "139, 105, 20";
		Form3->Label5->Text = "#8B6914";
		Form3->Label7->Text = "Goldenrod4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem47->IsSelected == true || LightSteelBlue->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(176, 196, 222);
		Form3->Label1->Text = Form1->ListBoxItem47->Text;
		Form3->Label3->Text = "176, 196, 222";
		Form3->Label5->Text = "#B0C4DE";
		Form3->Label7->Text = "LightSteelBlue";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem41->IsSelected == true || BlueColor->IsSelected == true || Blue->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 0, 225);
		Form3->Label1->Text = Form1->ListBoxItem41->Text;
		Form3->Label3->Text = "0, 0, 225";
		Form3->Label5->Text = "#0000FF";
		Form3->Label7->Text = "Blue";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem49->IsSelected == true || PowderBlue->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(176, 224, 230);
		Form3->Label1->Text = Form1->ListBoxItem49->Text;
		Form3->Label3->Text = "176, 224, 230";
		Form3->Label5->Text = "#B0E0E6";
		Form3->Label7->Text = "PowderBlue";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem426->IsSelected == true || DarkOrchid2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(178, 85, 238);
		Form3->Label1->Text = Form1->ListBoxItem426->Text;
		Form3->Label3->Text = "178, 85, 238";
		Form3->Label5->Text = "#B23AEE";
		Form3->Label7->Text = "DarkOrchid2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem4->IsSelected == true || Gainsboro->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(220, 220, 220);
		Form3->Label1->Text = Form1->ListBoxItem4->Text;
		Form3->Label3->Text = "220, 220, 220";
		Form3->Label5->Text = "#DCDCDC";
		Form3->Label7->Text = "Gainsboro";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem259->IsSelected == true || SeaGreen4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(46, 139, 87);
		Form3->Label1->Text = Form1->ListBoxItem259->Text;
		Form3->Label3->Text = "46, 139, 87";
		Form3->Label5->Text = "#2E8B57";
		Form3->Label7->Text = "SeaGreen4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem66->IsSelected == true || SpringGreen->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 255, 127);
		Form3->Label1->Text = Form1->ListBoxItem66->Text;
		Form3->Label3->Text = "0, 255, 127";
		Form3->Label5->Text = "#00FF7F";
		Form3->Label7->Text = "SpringGreen";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem34->IsSelected == true || CornflowerBlue->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(100, 149, 237);
		Form3->Label1->Text = Form1->ListBoxItem34->Text;
		Form3->Label3->Text = "100, 149, 237";
		Form3->Label5->Text = "#6495ED";
		Form3->Label7->Text = "CornflowerBlue";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem380->IsSelected == true || Red4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 0, 0);
		Form3->Label1->Text = Form1->ListBoxItem380->Text;
		Form3->Label3->Text = "139, 000, 000";
		Form3->Label5->Text = "#8B0000";
		Form3->Label7->Text = "Red4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem74->IsSelected == true || OliveDrab->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(107, 142, 35);
		Form3->Label1->Text = Form1->ListBoxItem74->Text;
		Form3->Label3->Text = "107, 142, 35";
		Form3->Label5->Text = "#6B8E23";
		Form3->Label7->Text = "OliveDrab";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem55->IsSelected == true || LightCyan->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(224, 255, 255);
		Form3->Label1->Text = Form1->ListBoxItem55->Text;
		Form3->Label3->Text = "224, 255, 255";
		Form3->Label5->Text = "#E0FFFF";
		Form3->Label7->Text = "LightCyan";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem325->IsSelected == true || BurlyWood2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 197, 145);
		Form3->Label1->Text = Form1->ListBoxItem325->Text;
		Form3->Label3->Text = "238, 197, 145";
		Form3->Label5->Text = "#EEC591";
		Form3->Label7->Text = "Burlywood2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem420->IsSelected == true || Plum4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 102, 139);
		Form3->Label1->Text = Form1->ListBoxItem420->Text;
		Form3->Label3->Text = "139, 102, 139";
		Form3->Label5->Text = "#8B668B";
		Form3->Label7->Text = "Plum4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem174->IsSelected == true || MistyRose3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 183, 181);
		Form3->Label1->Text = Form1->ListBoxItem174->Text;
		Form3->Label3->Text = "205, 183, 181";
		Form3->Label5->Text = "#CDB7B5";
		Form3->Label7->Text = "MistyRose3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem329->IsSelected == true || Wheat2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 216, 147);
		Form3->Label1->Text = Form1->ListBoxItem329->Text;
		Form3->Label3->Text = "238, 216, 147";
		Form3->Label5->Text = "#EED8AE";
		Form3->Label7->Text = "Wheat2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem400->IsSelected == true || PaleVioletRed4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 71, 93);
		Form3->Label1->Text = Form1->ListBoxItem400->Text;
		Form3->Label3->Text = "139, 71, 93";
		Form3->Label5->Text = "#8B475D";
		Form3->Label7->Text = "PaleVioletRed4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem99->IsSelected == true || DarkSalmon->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(233, 150, 122);
		Form3->Label1->Text = Form1->ListBoxItem99->Text;
		Form3->Label3->Text = "233, 150, 122";
		Form3->Label5->Text = "#E9967A";
		Form3->Label7->Text = "DarkSalmon";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem76->IsSelected == true || PaleGoldenrod->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 232, 170);
		Form3->Label1->Text = Form1->ListBoxItem76->Text;
		Form3->Label3->Text = "238, 232, 170";
		Form3->Label5->Text = "#EEE8AA";
		Form3->Label7->Text = "PaleGoldenrod";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem65->IsSelected == true || PaleGreen->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(152, 251, 152);
		Form3->Label1->Text = Form1->ListBoxItem65->Text;
		Form3->Label3->Text = "152, 251, 152";
		Form3->Label5->Text = "#98FB98";
		Form3->Label7->Text = "PaleGreen";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
    }

	if(ListBoxItem253->IsSelected == true || DarkSeaGreen2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(180, 238, 180);
		Form3->Label1->Text = Form1->ListBoxItem253->Text;
		Form3->Label3->Text = "180, 238, 180";
		Form3->Label5->Text = "#B4EEB4";
		Form3->Label7->Text = "DarkSeaGreen2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem78->IsSelected == true || LightYellow->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 255, 224);
		Form3->Label1->Text = Form1->ListBoxItem78->Text;
		Form3->Label3->Text = "255, 255, 224";
		Form3->Label5->Text = "#FFFFE0";
		Form3->Label7->Text = "LightYellow";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem22->IsSelected == true || AliceBlue->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(240, 248, 255);
		Form3->Label1->Text = Form1->ListBoxItem22->Text;
		Form3->Label3->Text = "240, 248, 255";
		Form3->Label5->Text = "#F0F8FF";
		Form3->Label7->Text = "AliceBlue";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem113->IsSelected == true || PaleVioletRed->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(219, 112, 147);
		Form3->Label1->Text = Form1->ListBoxItem113->Text;
		Form3->Label3->Text = "219, 112, 147";
		Form3->Label5->Text = "#DB7093";
		Form3->Label7->Text = "PaleVioletRed";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem50->IsSelected == true || PaleTurquoise->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(175, 238, 238);
		Form3->Label1->Text = Form1->ListBoxItem50->Text;
		Form3->Label3->Text = "175, 238, 238";
		Form3->Label5->Text = "#AFEEEE";
		Form3->Label7->Text = "PaleTurquoise";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem439->IsSelected == true || Thistle3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 181, 205);
		Form3->Label1->Text = Form1->ListBoxItem439->Text;
		Form3->Label3->Text = "205, 181, 205";
		Form3->Label5->Text = "#CDB5CD";
		Form3->Label7->Text = "Thistle3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem141->IsSelected == true || Bisque2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 213, 183);
		Form3->Label1->Text = Form1->ListBoxItem141->Text;
		Form3->Label3->Text = "238, 213, 183";
		Form3->Label5->Text = "#EED5B7";
		Form3->Label7->Text = "Bisque2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem11->IsSelected == true || Bisque->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 228, 196);
		Form3->Label1->Text = Form1->ListBoxItem11->Text;
		Form3->Label3->Text = "255, 228, 196";
		Form3->Label5->Text = "#FFE4C4";
		Form3->Label7->Text = "Bisque";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem143->IsSelected == true || Bisque4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 125, 107);
		Form3->Label1->Text = Form1->ListBoxItem143->Text;
		Form3->Label3->Text = "139, 125, 107";
		Form3->Label5->Text = "#8B7D6B";
		Form3->Label7->Text = "Bisque4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem142->IsSelected == true || Bisque3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(205, 183, 158);
		Form3->Label1->Text = Form1->ListBoxItem142->Text;
		Form3->Label3->Text = "205, 183, 158";
		Form3->Label5->Text = "#CDB79E";
		Form3->Label7->Text = "Bisque3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem54->IsSelected == true || Cyan->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 255, 255);
		Form3->Label1->Text = Form1->ListBoxItem54->Text;
		Form3->Label3->Text = "0, 255, 255";
		Form3->Label5->Text = "#00FFFF";
		Form3->Label7->Text = "Cyan";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem53->IsSelected == true || Turquoise->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(64, 224, 208);
		Form3->Label1->Text = Form1->ListBoxItem53->Text;
		Form3->Label3->Text = "64, 224, 208";
		Form3->Label5->Text = "#40E0D0";
		Form3->Label7->Text = "Turquoise";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem3->IsSelected == true || WhiteSmoke->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(245, 245, 245);
		Form3->Label1->Text = Form1->ListBoxItem3->Text;
		Form3->Label3->Text = "245, 245, 245";
		Form3->Label5->Text = "#F5F5F5";
		Form3->Label7->Text = "WhiteSmoke";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem26->IsSelected == true || White->IsSelected == true || WhiteColor->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(255, 255, 255);
		Form3->Label1->Text = Form1->ListBoxItem26->Text;
		Form3->Label3->Text = "255, 255, 255";
		Form3->Label5->Text = "#FFFFFF";
		Form3->Label7->Text = "White";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
    }

	if(ListBoxItem90->IsSelected == true || Beige->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(245, 245, 220);
		Form3->Label1->Text = Form1->ListBoxItem90->Text;
		Form3->Label3->Text = "245, 245, 220";
		Form3->Label5->Text = "#F5F5DC";
		Form3->Label7->Text = "Beige";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem384->IsSelected == true || DeepPink4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 10, 80);
		Form3->Label1->Text = Form1->ListBoxItem384->Text;
		Form3->Label3->Text = "139, 10, 80";
		Form3->Label5->Text = "#8B0A50";
		Form3->Label7->Text = "DeepPink4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem183->IsSelected == true || SlateBlue4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(71, 60, 139);
		Form3->Label1->Text = Form1->ListBoxItem183->Text;
		Form3->Label3->Text = "71, 60, 139";
		Form3->Label5->Text = "#473C8B";
		Form3->Label7->Text = "SlateBlue4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem182->IsSelected == true || SlateBlue3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(105, 89, 205);
		Form3->Label1->Text = Form1->ListBoxItem182->Text;
		Form3->Label3->Text = "105, 89, 205";
		Form3->Label5->Text = "#6959CD";
		Form3->Label7->Text = "SlateBlue3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem139->IsSelected == true || AntiqueWhite4->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(139, 131, 120);
		Form3->Label1->Text = Form1->ListBoxItem139->Text;
		Form3->Label3->Text = "139, 131, 120";
		Form3->Label5->Text = "#8B8378";
		Form3->Label7->Text = "AntiqueWhite4";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem8->IsSelected == true || AntiqueWhite->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(250, 235, 215);
		Form3->Label1->Text = Form1->ListBoxItem8->Text;
		Form3->Label3->Text = "250, 235, 215";
		Form3->Label5->Text = "#FAEBD7";
		Form3->Label7->Text = "AntiqueWhite";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem137->IsSelected == true || AntiqueWhite2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 223, 204);
		Form3->Label1->Text = Form1->ListBoxItem137->Text;
		Form3->Label3->Text = "238, 223, 204";
		Form3->Label5->Text = "#EEDFCC";
		Form3->Label7->Text = "AntiqueWhite2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem435->IsSelected == true || MediumPurple3->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(137, 104, 205);
		Form3->Label1->Text = Form1->ListBoxItem435->Text;
		Form3->Label3->Text = "137, 104, 205";
		Form3->Label5->Text = "#8968CD";
		Form3->Label7->Text = "MediumPurple3";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem402->IsSelected == true || Maroon2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(238, 48, 167);
		Form3->Label1->Text = Form1->ListBoxItem402->Text;
		Form3->Label3->Text = "238, 48, 167";
		Form3->Label5->Text = "#EE30A7";
		Form3->Label7->Text = "Maroon2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem241->IsSelected == true || Cyan2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(0, 238, 238);
		Form3->Label1->Text = Form1->ListBoxItem241->Text;
		Form3->Label3->Text = "0, 238, 238";
		Form3->Label5->Text = "#00EEEE";
		Form3->Label7->Text = "Cyan2";

		ResetLBI();
		Panel2->Visible = false;

		Form3->Show();
	}

	if(ListBoxItem91->IsSelected == true || Aquamarine->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(127, 255, 212);
		Form3->Label1->Text = Form1->ListBoxItem91->Text;
		Form3->Label3->Text = "127, 255, 212";
		Form3->Label5->Text = "#7FFFD4";
		Form3->Label7->Text = "Aquamarine";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}

	if(ListBoxItem193->IsSelected == true || DodgerBlue2->IsSelected == true)
	{
		Form3->Rectangle1->Fill->Color = MakeColor(28, 134, 238);
		Form3->Label1->Text = Form1->ListBoxItem193->Text;
		Form3->Label3->Text = "28, 134, 238";
		Form3->Label5->Text = "#1C86EE";
		Form3->Label7->Text = "DodgerBlue2";

		ResetLBI();
		Panel2->Visible = false;
		Form3->Show();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
	RectangleAll->Visible = true;
	RectangleAllPrs->Visible = false;

		//Делаем картинку НЕ нажатой (т.е. возвращаем в исходное состояние)
	Image13->Visible = true;
	Image1->Visible = false;

	//Делаем кнопку Меню НЕ нажатой (т.е. возвращаем в исходное состояние)
	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;

	Panel2->Visible = false;
	Timer3->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer5Timer(TObject *Sender)
{
	RectangleRed->Visible = true;
	RectangleRedPrs->Visible = false;

	//Делаем картинку НЕ нажатой (т.е. возвращаем в исходное состояние)
	Image15->Visible = true;
	Image3->Visible = false;

	//Делаем кнопку Меню НЕ нажатой (т.е. возвращаем в исходное состояние)
	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;

	Panel2->Visible = false;
	Timer5->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer4Timer(TObject *Sender)
{
	RectangleMain->Visible = true;
	RectangleMainPrs->Visible = false;

	//Делаем картинку НЕ нажатой (т.е. возвращаем в исходное состояние)
	Image14->Visible = true;
	Image2->Visible = false;

	//Делаем кнопку Меню НЕ нажатой (т.е. возвращаем в исходное состояние)
	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;

	Panel2->Visible = false;
	Timer4->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer6Timer(TObject *Sender)
{
	RectangleGreen->Visible = true;
	RectangleGreenPrs->Visible = false;

	//Делаем картинку НЕ нажатой (т.е. возвращаем в исходное состояние)
	Image16->Visible = true;
	Image4->Visible = false;

	//Делаем кнопку Меню НЕ нажатой (т.е. возвращаем в исходное состояние)
	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;

	Panel2->Visible = false;
	Timer6->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer7Timer(TObject *Sender)
{
	RectangleBlue->Visible = true;
	RectangleBluePrs->Visible = false;

	//Делаем картинку НЕ нажатой (т.е. возвращаем в исходное состояние)
	Image17->Visible = true;
	Image5->Visible = false;

	//Делаем кнопку Меню НЕ нажатой (т.е. возвращаем в исходное состояние)
	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;

	Panel2->Visible = false;
	Timer7->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer8Timer(TObject *Sender)
{
	RectanglePink->Visible = true;
	RectanglePinkPrs->Visible = false;

	//Делаем картинку НЕ нажатой (т.е. возвращаем в исходное состояние)
	Image18->Visible = true;
	Image6->Visible = false;

	//Делаем кнопку Меню НЕ нажатой (т.е. возвращаем в исходное состояние)
	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;

	Panel2->Visible = false;
	Timer8->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer9Timer(TObject *Sender)
{
	RectangleOrange->Visible = true;
	RectangleOrangePrs->Visible = false;

	//Делаем картинку НЕ нажатой (т.е. возвращаем в исходное состояние)
	Image19->Visible = true;
	Image7->Visible = false;

	//Делаем кнопку Меню НЕ нажатой (т.е. возвращаем в исходное состояние)
	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;

	Panel2->Visible = false;
	Timer9->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer10Timer(TObject *Sender)
{
	RectangleYellow->Visible = true;
	RectangleYellowPrs->Visible = false;

	//Делаем картинку НЕ нажатой (т.е. возвращаем в исходное состояние)
	Image20->Visible = true;
	Image8->Visible = false;

	//Делаем кнопку Меню НЕ нажатой (т.е. возвращаем в исходное состояние)
	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;

	Panel2->Visible = false;
	Timer10->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer11Timer(TObject *Sender)
{
	RectangleViolet->Visible = true;
	RectangleVioletPrs->Visible = false;

	//Делаем картинку НЕ нажатой (т.е. возвращаем в исходное состояние)
	Image21->Visible = true;
	Image9->Visible = false;

	//Делаем кнопку Меню НЕ нажатой (т.е. возвращаем в исходное состояние)
	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;

	Panel2->Visible = false;
	Timer11->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer12Timer(TObject *Sender)
{
	RectangleBrown->Visible = true;
	RectangleBrownPrs->Visible = false;

	//Делаем картинку НЕ нажатой (т.е. возвращаем в исходное состояние)
	Image22->Visible = true;
	Image10->Visible = false;

	//Делаем кнопку Меню НЕ нажатой (т.е. возвращаем в исходное состояние)
	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;

	Panel2->Visible = false;
	Timer12->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer13Timer(TObject *Sender)
{
	RectangleWhite->Visible = true;
	RectangleWhitePrs->Visible = false;

	//Делаем картинку НЕ нажатой (т.е. возвращаем в исходное состояние)
	Image23->Visible = true;
	Image11->Visible = false;

	//Делаем кнопку Меню НЕ нажатой (т.е. возвращаем в исходное состояние)
	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;

	Panel2->Visible = false;
	Timer13->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer14Timer(TObject *Sender)
{
	RectangleGrey->Visible = true;
	RectangleGreyPrs->Visible = false;

	//Делаем картинку НЕ нажатой (т.е. возвращаем в исходное состояние)
	Image24->Visible = true;
	Image12->Visible = false;

	//Делаем кнопку Меню НЕ нажатой (т.е. возвращаем в исходное состояние)
	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;

	Panel2->Visible = false;
	Timer14->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleAllMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	//Делаем визуальное нажатие
	RectangleAll->Visible = false;
	RectangleAllPrs->Visible = true;
	Image13->Visible = false;
	Image1->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleMainMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	//Делаем визуальное нажатие
	RectangleMain->Visible = false;
	RectangleMainPrs->Visible = true;
	Image14->Visible = false;
	Image2->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleRedMouseLeave(TObject *Sender)
{
	ListBox1->Visible = false;
	LB2_MainColors->Visible = false;

	LB3_RedColors->Visible = true;

	LB4_GreenColors->Visible = false;
	LB5_BlueColors->Visible = false;
	LB6_PinkColors->Visible = false;
	LB7_OrangeColors->Visible = false;
	LB8_YellowColors->Visible = false;
	LB9_VioletColors->Visible = false;
	LB10_BrownColors->Visible = false;
	LB11_WhiteColors->Visible = false;
	LB12_GreyColors->Visible = false;

	IndianRed->Text = ListBoxItem85->Text;
	IndianRed2->Text = ListBoxItem317->Text;
	IndianRed3->Text = ListBoxItem318->Text;
	IndianRed4->Text = ListBoxItem319->Text;
	Firebrick->Text = ListBoxItem97->Text;
	Salmon->Text = ListBoxItem100->Text;
	DarkSalmon->Text = ListBoxItem99->Text;
	LightSalmon->Text = ListBoxItem101->Text;
	RedColor->Text = ListBoxItem108->Text;
//	LightCoral->Text = ListBoxItem105->Text;
	Firebrick2->Text = ListBoxItem341->Text;
	Firebrick3->Text = ListBoxItem342->Text;
	Firebrick4->Text = ListBoxItem344->Text;
	Salmon2->Text = ListBoxItem350->Text;
	Salmon3->Text = ListBoxItem351->Text;
	Salmon4->Text = ListBoxItem352->Text;
	LightSalmon2->Text = ListBoxItem354->Text;
	LightSalmon3->Text = ListBoxItem355->Text;
	LightSalmon4->Text = ListBoxItem356->Text;
	Red2->Text = ListBoxItem378->Text;
	Red3->Text = ListBoxItem379->Text;
	Red4->Text = ListBoxItem380->Text;
	Brown->Text = ListBoxItem98->Text;
	Brown2->Text = ListBoxItem346->Text;
	Brown3->Text = ListBoxItem347->Text;
	Brown4->Text = ListBoxItem348->Text;

	Label3->Text = Menu3->Text;

	Timer5->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleRedMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	//Делаем визуальное нажатие
	RectangleRed->Visible = false;
	RectangleRedPrs->Visible = true;
	Image15->Visible = false;
	Image3->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleGreenMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	//Делаем визуальное нажатие
	RectangleGreen->Visible = false;
	RectangleGreenPrs->Visible = true;
	Image16->Visible = false;
	Image4->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleBlueMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	//Делаем визуальное нажатие
	Image17->Visible = false;
	Image5->Visible = true;
	RectangleBlue->Visible = false;
	RectangleBluePrs->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectanglePinkMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	//Делаем визуальное нажатие
	RectanglePink->Visible = false;
	RectanglePinkPrs->Visible = true;
	Image18->Visible = false;
	Image6->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleOrangeMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	//Делаем визуальное нажатие
	RectangleOrange->Visible = false;
	RectangleOrangePrs->Visible = true;
	Image19->Visible = false;
	Image7->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleYellowMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	//Делаем визуальное нажатие
	RectangleYellow->Visible = false;
	RectangleYellowPrs->Visible = true;
	Image20->Visible = false;
	Image8->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleVioletMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	//Делаем визуальное нажатие
	RectangleViolet->Visible = false;
	RectangleVioletPrs->Visible = true;
	Image21->Visible = false;
	Image9->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleBrownMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	//Делаем визуальное нажатие
	RectangleBrown->Visible = false;
	RectangleBrownPrs->Visible = true;
	Image22->Visible = false;
	Image10->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleWhiteMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	//Делаем визуальное нажатие
	RectangleWhite->Visible = false;
	RectangleWhitePrs->Visible = true;
	Image23->Visible = false;
	Image11->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleGreyMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	//Делаем визуальное нажатие
	RectangleGrey->Visible = false;
	RectangleGreyPrs->Visible = true;
	Image24->Visible = false;
	Image12->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleGreenMouseLeave(TObject *Sender)
{
	ListBox1->Visible = false;
	LB2_MainColors->Visible = false;
	LB3_RedColors->Visible = false;

	LB4_GreenColors->Visible = true;

	LB5_BlueColors->Visible = false;
	LB6_PinkColors->Visible = false;
	LB7_OrangeColors->Visible = false;
	LB8_YellowColors->Visible = false;
	LB9_VioletColors->Visible = false;
	LB10_BrownColors->Visible = false;
	LB11_WhiteColors->Visible = false;
	LB12_GreyColors->Visible = false;

	GreenYellow->Text = ListBoxItem71->Text;
	Chartreuse->Text = ListBoxItem69->Text;
	LawnGreen->Text = ListBoxItem67->Text;
	PaleGreen->Text = ListBoxItem65->Text;
	MediumSpringGreen->Text = ListBoxItem70->Text;
	SpringGreen->Text = ListBoxItem66->Text;
	MediumSeaGreen->Text = ListBoxItem63->Text;
	AquaColor->Text = ListBoxItem62->Text;
	ForestGreen->Text = ListBoxItem73->Text;
	GreenColor->Text = ListBoxItem68->Text;
	DarkGreen->Text = ListBoxItem59->Text;
	YellowGreen->Text = ListBoxItem72->Text;
	OliveDrab->Text = ListBoxItem74->Text;
	DarkOliveGreen->Text = ListBoxItem60->Text;
	MediumAquamarine->Text = ListBoxItem58->Text;
	DarkSeaGreen->Text = ListBoxItem61->Text;
	LightSeaGreen->Text = ListBoxItem64->Text;
	DarkSeaGreen2->Text = ListBoxItem253->Text;
	DarkSeaGreen3->Text = ListBoxItem254->Text;
	DarkSeaGreen4->Text = ListBoxItem255->Text;
	SeaGreen2->Text = ListBoxItem257->Text;
	SeaGreen3->Text = ListBoxItem258->Text;
	SeaGreen4->Text = ListBoxItem259->Text;
	PaleGreen2->Text = ListBoxItem261->Text;
	PaleGreen3->Text = ListBoxItem262->Text;
	PaleGreen4->Text = ListBoxItem263->Text;
	SpringGreen2->Text = ListBoxItem265->Text;
	SpringGreen3->Text = ListBoxItem266->Text;
	SpringGreen4->Text = ListBoxItem267->Text;
	Green2->Text = ListBoxItem269->Text;
	Green3->Text = ListBoxItem270->Text;
	Green4->Text = ListBoxItem271->Text;
	Chartreuse2->Text = ListBoxItem273->Text;
	Chartreuse3->Text = ListBoxItem274->Text;
	Chartreuse4->Text = ListBoxItem275->Text;
	OliveDrab2->Text = ListBoxItem277->Text;
	OliveDrab3->Text = ListBoxItem278->Text;
	OliveDrab4->Text = ListBoxItem279->Text;
	DarkOliveGreen2->Text = ListBoxItem281->Text;
	DarkOliveGreen3->Text = ListBoxItem282->Text;
	DarkOliveGreen4->Text = ListBoxItem283->Text;
	Aquamarine->Text = ListBoxItem91->Text;
	Aquamarine2->Text = ListBoxItem249->Text;
	Aquamarine3->Text = ListBoxItem250->Text;
	Aquamarine4->Text = ListBoxItem251->Text;
	DarkCyan->Text = ListBoxItem243->Text;
	LightGreen->Text = ListBoxItem455->Text;
	LightCyan->Text = ListBoxItem55->Text;
	LightCyan2->Text = ListBoxItem225->Text;
	LightCyan3->Text = ListBoxItem226->Text;
	LightCyan4->Text = ListBoxItem227->Text;
	Honeydew4->Text = ListBoxItem167->Text;
	Azure4->Text = ListBoxItem179->Text;

	Label3->Text = Menu4->Text;

	Timer6->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleBlueMouseLeave(TObject *Sender)
{
	ListBox1->Visible = false;
	LB2_MainColors->Visible = false;
	LB3_RedColors->Visible = false;
	LB4_GreenColors->Visible = false;

	LB5_BlueColors->Visible = true;

	LB6_PinkColors->Visible = false;
	LB7_OrangeColors->Visible = false;
	LB8_YellowColors->Visible = false;
	LB9_VioletColors->Visible = false;
	LB10_BrownColors->Visible = false;
	LB11_WhiteColors->Visible = false;
	LB12_GreyColors->Visible = false;

	Cyan->Text = ListBoxItem54->Text;
	Turquoise->Text = ListBoxItem53->Text;
	MediumTurquoise->Text = ListBoxItem52->Text;
	DarkTurquoise->Text = ListBoxItem51->Text;
	CadetBlue->Text = ListBoxItem56->Text;
	SteelBlue->Text = ListBoxItem46->Text;
	PowderBlue->Text = ListBoxItem49->Text;
	LightBlue->Text = ListBoxItem48->Text;
	SkyBlue->Text = ListBoxItem44->Text;
	DeepSkyBlue->Text = ListBoxItem43->Text;
	DodgerBlue->Text = ListBoxItem42->Text;
	CornflowerBlue->Text = ListBoxItem34->Text;
	MediumSlateBlue->Text = ListBoxItem37->Text;
	RoyalBlue->Text = ListBoxItem40->Text;
	BlueColor->Text = ListBoxItem41->Text;
	MediumBlue->Text = ListBoxItem39->Text;
	NavyColor->Text = ListBoxItem33->Text;
	MidnightBlue->Text = ListBoxItem32->Text;
	DarkSlateBlue->Text = ListBoxItem35->Text;
	SlateBlue->Text = ListBoxItem36->Text;
	LightSlateBlue->Text = ListBoxItem38->Text;
	LightSkyBlue->Text = ListBoxItem45->Text;
	LightSteelBlue->Text = ListBoxItem47->Text;
	PaleTurquoise->Text = ListBoxItem50->Text;
	SlateBlue2->Text = ListBoxItem181->Text;
	SlateBlue3->Text = ListBoxItem182->Text;
	SlateBlue4->Text = ListBoxItem183->Text;
	RoyalBlue2->Text = ListBoxItem185->Text;
	RoyalBlue3->Text = ListBoxItem186->Text;
	RoyalBlue4->Text = ListBoxItem187->Text;
	DodgerBlue2->Text = ListBoxItem193->Text;
	DodgerBlue3->Text = ListBoxItem194->Text;
	DodgerBlue4->Text = ListBoxItem195->Text;
	SteelBlue2->Text = ListBoxItem197->Text;
	SteelBlue3->Text = ListBoxItem198->Text;
	SteelBlue4->Text = ListBoxItem199->Text;
	DeepSkyBlue2->Text = ListBoxItem201->Text;
	DeepSkyBlue3->Text = ListBoxItem202->Text;
	DeepSkyBlue4->Text = ListBoxItem203->Text;
	SkyBlue2->Text = ListBoxItem205->Text;
	SkyBlue3->Text = ListBoxItem206->Text;
	SkyBlue4->Text = ListBoxItem207->Text;
	LightSkyBlue2->Text = ListBoxItem209->Text;
	LightSkyBlue3->Text = ListBoxItem210->Text;
	LightSkyBlue4->Text = ListBoxItem211->Text;
	LightSteelBlue2->Text = ListBoxItem217->Text;
	LightSteelBlue3->Text = ListBoxItem218->Text;
	LightSteelBlue4->Text = ListBoxItem219->Text;
	LightBlue2->Text = ListBoxItem221->Text;
	LightBlue3->Text = ListBoxItem222->Text;
	LightBlue4->Text = ListBoxItem223->Text;
	PaleTurquoise2->Text = ListBoxItem229->Text;
	PaleTurquoise3->Text = ListBoxItem230->Text;
	PaleTurquoise4->Text = ListBoxItem231->Text;
	CadetBlue2->Text = ListBoxItem233->Text;
	CadetBlue3->Text = ListBoxItem234->Text;
	CadetBlue4->Text = ListBoxItem235->Text;
	Turquoise2->Text = ListBoxItem237->Text;
	Turquoise3->Text = ListBoxItem238->Text;
	Turquoise4->Text = ListBoxItem239->Text;
	Cyan2->Text = ListBoxItem241->Text;
	Cyan3->Text = ListBoxItem242->Text;
	Cyan4->Text = ListBoxItem243->Text;
	AliceBlue->Text = ListBoxItem22->Text;

	Label3->Text = Menu5->Text;

	Timer7->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectanglePinkMouseLeave(TObject *Sender)
{
	ListBox1->Visible = false;
	LB2_MainColors->Visible = false;
	LB3_RedColors->Visible = false;
	LB4_GreenColors->Visible = false;
	LB5_BlueColors->Visible = false;

	LB6_PinkColors->Visible = true;

	LB7_OrangeColors->Visible = false;
	LB8_YellowColors->Visible = false;
	LB9_VioletColors->Visible = false;
	LB10_BrownColors->Visible = false;
	LB11_WhiteColors->Visible = false;
	LB12_GreyColors->Visible = false;

	Pink->Text = ListBoxItem111->Text;
	Pink2->Text = ListBoxItem390->Text;
	Pink3->Text = ListBoxItem391->Text;
	Pink4->Text = ListBoxItem392->Text;
	LightPink->Text = ListBoxItem112->Text;
	LightPink2->Text = ListBoxItem394->Text;
	LightPink3->Text = ListBoxItem395->Text;
	LightPink4->Text = ListBoxItem396->Text;
	HotPink->Text = ListBoxItem109->Text;
	HotPink2->Text = ListBoxItem386->Text;
	HotPink3->Text = ListBoxItem387->Text;
	HotPink4->Text = ListBoxItem388->Text;
	DeepPink->Text = ListBoxItem110->Text;
	DeepPink2->Text = ListBoxItem382->Text;
	DeepPink3->Text = ListBoxItem383->Text;
	DeepPink4->Text = ListBoxItem384->Text;
	MediumVioletRed->Text = ListBoxItem115->Text;
	PaleVioletRed->Text = ListBoxItem113->Text;
	PaleVioletRed2->Text = ListBoxItem398->Text;
	PaleVioletRed3->Text = ListBoxItem399->Text;
	PaleVioletRed4->Text = ListBoxItem400->Text;
	MaroonColor->Text = ListBoxItem114->Text;
	Maroon2->Text = ListBoxItem402->Text;
	Maroon3->Text = ListBoxItem403->Text;
	Maroon4->Text = ListBoxItem404->Text;

	Label3->Text = Menu6->Text;

	Timer8->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleOrangeMouseLeave(TObject *Sender)
{
	ListBox1->Visible = false;
	LB2_MainColors->Visible = false;
	LB3_RedColors->Visible = false;
	LB4_GreenColors->Visible = false;
	LB5_BlueColors->Visible = false;
	LB6_PinkColors->Visible = false;

	LB7_OrangeColors->Visible = true;

	LB8_YellowColors->Visible = false;
	LB9_VioletColors->Visible = false;
	LB10_BrownColors->Visible = false;
	LB11_WhiteColors->Visible = false;
	LB12_GreyColors->Visible = false;

	LightSalmonColor->Text = ListBoxItem101->Text;
	LightSalmonColor2->Text = ListBoxItem354->Text;
	LightSalmonColor3->Text = ListBoxItem355->Text;
	LightSalmonColor4->Text = ListBoxItem356->Text;
	Tomato->Text = ListBoxItem106->Text;
	Tomato2->Text = ListBoxItem370->Text;
	Tomato3->Text = ListBoxItem371->Text;
	Tomato4->Text = ListBoxItem372->Text;
	OrangeRed->Text = ListBoxItem107->Text;
	OrangeRed2->Text = ListBoxItem362->Text;
	OrangeRed3->Text = ListBoxItem363->Text;
	OrangeRed4->Text = ListBoxItem364->Text;
	Orange->Text = ListBoxItem102->Text;
	Orange2->Text = ListBoxItem358->Text;
	Orange3->Text = ListBoxItem359->Text;
	Orange4->Text = ListBoxItem360->Text;
	DarkOrange->Text = ListBoxItem103->Text;
	DarkOrange2->Text = ListBoxItem374->Text;
	DarkOrange3->Text = ListBoxItem375->Text;
	DarkOrange4->Text = ListBoxItem376->Text;
	Coral->Text = ListBoxItem104->Text;
	Coral2->Text = ListBoxItem366->Text;
	Coral3->Text = ListBoxItem367->Text;
	Coral4->Text = ListBoxItem368->Text;
	Tan2->Text = ListBoxItem333->Text;
	Tan3->Text = ListBoxItem334->Text;
	Tan4->Text = ListBoxItem335->Text;

	Label3->Text = Menu7->Text;

	Timer9->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleYellowMouseLeave(TObject *Sender)
{
	ListBox1->Visible = false;
	LB2_MainColors->Visible = false;
	LB3_RedColors->Visible = false;
	LB4_GreenColors->Visible = false;
	LB5_BlueColors->Visible = false;
	LB6_PinkColors->Visible = false;
	LB7_OrangeColors->Visible = false;

	LB8_YellowColors->Visible = true;

	LB9_VioletColors->Visible = false;
	LB10_BrownColors->Visible = false;
	LB11_WhiteColors->Visible = false;
	LB12_GreyColors->Visible = false;

	Gold->Text = ListBoxItem80->Text;
	Gold2->Text = ListBoxItem301->Text;
	Gold3->Text = ListBoxItem302->Text;
	Gold4->Text = ListBoxItem303->Text;
	YellowColor->Text = ListBoxItem79->Text;
	Yellow2->Text = ListBoxItem297->Text;
	Yellow3->Text = ListBoxItem298->Text;
	Yellow4->Text = ListBoxItem299->Text;
	LightYellow->Text = ListBoxItem78->Text;
	LightYellow2->Text = ListBoxItem293->Text;
	LightYellow3->Text = ListBoxItem294->Text;
	LightYellow4->Text = ListBoxItem295->Text;
	LemonChiffon->Text = ListBoxItem17->Text;
	LemonChiffon2->Text = ListBoxItem153->Text;
	LemonChiffon3->Text = ListBoxItem154->Text;
	LemonChiffon4->Text = ListBoxItem155->Text;
	LightGoldenrodYellow->Text = ListBoxItem77->Text;
	LightGoldenrod2->Text = ListBoxItem289->Text;
	LightGoldenrod3->Text = ListBoxItem290->Text;
	LightGoldenrod4->Text = ListBoxItem291->Text;
	PapayaWhip->Text = ListBoxItem9->Text;
	Moccasin->Text = ListBoxItem14->Text;
	PeachPuff->Text = ListBoxItem12->Text;
	PeachPuff2->Text = ListBoxItem145->Text;
	PeachPuff3->Text = ListBoxItem146->Text;
	PeachPuff4->Text = ListBoxItem147->Text;
	PaleGoldenrod->Text = ListBoxItem76->Text;
	Khaki2->Text = ListBoxItem285->Text;
	Khaki3->Text = ListBoxItem286->Text;
	Khaki4->Text = ListBoxItem287->Text;
	DarkKhaki->Text = ListBoxItem75->Text;
	Goldenrod->Text = ListBoxItem82->Text;
	Goldenrod2->Text = ListBoxItem305->Text;
	Goldenrod3->Text = ListBoxItem306->Text;
	Goldenrod4->Text = ListBoxItem307->Text;
	DarkGoldenrodColor->Text = ListBoxItem83->Text;
	DarkGoldenrod2->Text = ListBoxItem309->Text;
	DarkGoldenrod3->Text = ListBoxItem310->Text;
	DarkGoldenrod4->Text = ListBoxItem311->Text;

	Label3->Text = Menu8->Text;

	Timer10->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleVioletMouseLeave(TObject *Sender)
{
	ListBox1->Visible = false;
	LB2_MainColors->Visible = false;
	LB3_RedColors->Visible = false;
	LB4_GreenColors->Visible = false;
	LB5_BlueColors->Visible = false;
	LB6_PinkColors->Visible = false;
	LB7_OrangeColors->Visible = false;
	LB8_YellowColors->Visible = false;

	LB9_VioletColors->Visible = true;

	LB10_BrownColors->Visible = false;
	LB11_WhiteColors->Visible = false;
	LB12_GreyColors->Visible = false;

	Lavender->Text = ListBoxItem23->Text;
	Thistle->Text = ListBoxItem127->Text;
	Thistle2->Text = ListBoxItem438->Text;
	Thistle3->Text = ListBoxItem439->Text;
	Thistle4->Text = ListBoxItem440->Text;
	Plum->Text = ListBoxItem119->Text;
	Plum2->Text = ListBoxItem418->Text;
	Plum3->Text = ListBoxItem419->Text;
	Plum4->Text = ListBoxItem420->Text;
	Violet->Text = ListBoxItem118->Text;
	VioletRed->Text = ListBoxItem116->Text;
	VioletRed2->Text = ListBoxItem406->Text;
	VioletRed3->Text = ListBoxItem407->Text;
	VioletRed4->Text = ListBoxItem408->Text;
	Orchid->Text = ListBoxItem120->Text;
	Orchid2->Text = ListBoxItem414->Text;
	Orchid3->Text = ListBoxItem415->Text;
	Orchid4->Text = ListBoxItem416->Text;
	Magenta->Text = ListBoxItem117->Text;
	Magenta2->Text = ListBoxItem410->Text;
	Magenta3->Text = ListBoxItem411->Text;
	Magenta4->Text = ListBoxItem412->Text;
	MediumOrchid->Text = ListBoxItem121->Text;
	MediumOrchid2->Text = ListBoxItem422->Text;
	MediumOrchid3->Text = ListBoxItem423->Text;
	MediumOrchid4->Text = ListBoxItem424->Text;
	MediumPurple->Text = ListBoxItem126->Text;
	MediumPurple2->Text = ListBoxItem434->Text;
	MediumPurple3->Text = ListBoxItem435->Text;
	MediumPurple4->Text = ListBoxItem436->Text;
	BlueViolet->Text = ListBoxItem124->Text;
	DarkViolet->Text = ListBoxItem123->Text;
	DarkOrchid->Text = ListBoxItem122->Text;
	DarkOrchid2->Text = ListBoxItem426->Text;
	DarkOrchid3->Text = ListBoxItem427->Text;
	DarkOrchid4->Text = ListBoxItem428->Text;
	PurpleColor->Text = ListBoxItem125->Text;
	Purple2->Text = ListBoxItem430->Text;
	Purple3->Text = ListBoxItem431->Text;
	Purple4->Text = ListBoxItem432->Text;
	DarkMagenta->Text = ListBoxItem453->Text;

	Label3->Text = Menu9->Text;

	Timer11->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleBrownMouseLeave(TObject *Sender)
{
	ListBox1->Visible = false;
	LB2_MainColors->Visible = false;
	LB3_RedColors->Visible = false;
	LB4_GreenColors->Visible = false;
	LB5_BlueColors->Visible = false;
	LB6_PinkColors->Visible = false;
	LB7_OrangeColors->Visible = false;
	LB8_YellowColors->Visible = false;
	LB9_VioletColors->Visible = false;

	LB10_BrownColors->Visible = true;

	LB11_WhiteColors->Visible = false;
	LB12_GreyColors->Visible = false;

	Cornsilk->Text = ListBoxItem15->Text;
	Cornsilk2->Text = ListBoxItem157->Text;
	Cornsilk3->Text = ListBoxItem158->Text;
	Cornsilk4->Text = ListBoxItem159->Text;
	BlanchedAlmond->Text = ListBoxItem10->Text;
	Bisque->Text = ListBoxItem11->Text;
	Bisque2->Text = ListBoxItem141->Text;
	Bisque3->Text = ListBoxItem142->Text;
	Bisque4->Text = ListBoxItem143->Text;
	NavajoWhite->Text = ListBoxItem13->Text;
	NavajoWhite2->Text = ListBoxItem149->Text;
	NavajoWhite3->Text = ListBoxItem150->Text;
	NavajoWhite4->Text = ListBoxItem151->Text;
	Wheat->Text = ListBoxItem93->Text;
	Wheat2->Text = ListBoxItem329->Text;
	Wheat3->Text = ListBoxItem330->Text;
	Wheat4->Text = ListBoxItem331->Text;
	BurlyWood->Text = ListBoxItem89->Text;
	BurlyWood2->Text = ListBoxItem325->Text;
	BurlyWood3->Text = ListBoxItem326->Text;
	BurlyWood4->Text = ListBoxItem327->Text;
	Tan->Text = ListBoxItem95->Text;
	RosyBrown->Text = ListBoxItem84->Text;
	RosyBrown2->Text = ListBoxItem313->Text;
	RosyBrown3->Text = ListBoxItem314->Text;
	RosyBrown4->Text = ListBoxItem315->Text;
	SandyBrown->Text = ListBoxItem94->Text;
	Peru->Text = ListBoxItem88->Text;
	Chocolate->Text = ListBoxItem96->Text;
	Chocolate2->Text = ListBoxItem337->Text;
	Chocolate3->Text = ListBoxItem338->Text;
	Chocolate4->Text = ListBoxItem339->Text;
	SaddleBrown->Text = ListBoxItem86->Text;
	Sienna->Text = ListBoxItem87->Text;
	Sienna2->Text = ListBoxItem321->Text;
	Sienna3->Text = ListBoxItem322->Text;
	Sienna4->Text = ListBoxItem323->Text;
	MistyRose4->Text = ListBoxItem175->Text;

	Label3->Text = Menu10->Text;

	Timer12->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleWhiteMouseLeave(TObject *Sender)
{
	ListBox1->Visible = false;
	LB2_MainColors->Visible = false;
	LB3_RedColors->Visible = false;
	LB4_GreenColors->Visible = false;
	LB5_BlueColors->Visible = false;
	LB6_PinkColors->Visible = false;
	LB7_OrangeColors->Visible = false;
	LB8_YellowColors->Visible = false;
	LB9_VioletColors->Visible = false;
	LB10_BrownColors->Visible = false;

	LB11_WhiteColors->Visible = true;

	LB12_GreyColors->Visible = false;

	WhiteColor->Text = ListBoxItem26->Text;
	Snow->Text = ListBoxItem1->Text;
	Honeydew->Text = ListBoxItem19->Text;
	MintCream->Text = ListBoxItem20->Text;
	Azure->Text = ListBoxItem21->Text;
	GhostWhite->Text = ListBoxItem2->Text;
	WhiteSmoke->Text = ListBoxItem3->Text;
	Seashell->Text = ListBoxItem18->Text;
	OldLace->Text = ListBoxItem6->Text;
	FloralWhite->Text = ListBoxItem5->Text;
	Ivory->Text = ListBoxItem16->Text;
	AntiqueWhite->Text = ListBoxItem8->Text;
	AntiqueWhite2->Text = ListBoxItem137->Text;
	AntiqueWhite3->Text = ListBoxItem138->Text;
	Linen->Text = ListBoxItem7->Text;
	LavenderBlush->Text = ListBoxItem24->Text;
	MistyRose->Text = ListBoxItem25->Text;
	Snow2->Text = ListBoxItem129->Text;
	Snow3->Text = ListBoxItem130->Text;
	Seashell2->Text = ListBoxItem133->Text;
	Seashell3->Text = ListBoxItem134->Text;
	Ivory2->Text = ListBoxItem161->Text;
	Ivory3->Text = ListBoxItem162->Text;
	LavenderBlush2->Text = ListBoxItem169->Text;
	LavenderBlush3->Text = ListBoxItem170->Text;
	Azure2->Text = ListBoxItem177->Text;
	Azure3->Text = ListBoxItem178->Text;
	MistyRose2->Text = ListBoxItem173->Text;
	MistyRose3->Text = ListBoxItem174->Text;
	Honeydew2->Text = ListBoxItem165->Text;
	Honeydew3->Text = ListBoxItem166->Text;
	Beige->Text = ListBoxItem90->Text;

	Label3->Text = Menu11->Text;

	Timer13->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleGreyMouseLeave(TObject *Sender)
{
	ListBox1->Visible = false;
	LB2_MainColors->Visible = false;
	LB3_RedColors->Visible = false;
	LB4_GreenColors->Visible = false;
	LB5_BlueColors->Visible = false;
	LB6_PinkColors->Visible = false;
	LB7_OrangeColors->Visible = false;
	LB8_YellowColors->Visible = false;
	LB9_VioletColors->Visible = false;
	LB10_BrownColors->Visible = false;
	LB11_WhiteColors->Visible = false;

	LB12_GreyColors->Visible = true;

	Gainsboro->Text = ListBoxItem4->Text;
	LightGrey->Text = ListBoxItem31->Text;
	Silver->Text = ListBoxItem128->Text;
	DarkGray->Text = ListBoxItem450->Text;
	Gray->Text = ListBoxItem92->Text;
	DimGrey->Text = ListBoxItem29->Text;
	LightSlateGrey->Text = ListBoxItem57->Text;
	SlateGrey->Text = ListBoxItem30->Text;
	DarkSlateGrey->Text = ListBoxItem28->Text;
	Grey11->Text = ListBoxItem441->Text;
	Grey21->Text = ListBoxItem442->Text;
	Grey31->Text = ListBoxItem443->Text;
	Grey41->Text = ListBoxItem444->Text;
	Grey51->Text = ListBoxItem445->Text;
	Grey61->Text = ListBoxItem446->Text;
	Grey71->Text = ListBoxItem447->Text;
	Grey81->Text = ListBoxItem448->Text;
	Grey91->Text = ListBoxItem449->Text;
	SlateGrey2->Text = ListBoxItem213->Text;
	SlateGrey3->Text = ListBoxItem214->Text;
	SlateGrey4->Text = ListBoxItem215->Text;
	DarkSlateGrey2->Text = ListBoxItem245->Text;
	DarkSlateGrey3->Text = ListBoxItem246->Text;
	DarkSlateGrey4->Text = ListBoxItem247->Text;
	AntiqueWhite4->Text = ListBoxItem139->Text;
	Snow4->Text = ListBoxItem131->Text;
	Seashell4->Text = ListBoxItem135->Text;
	Ivory4->Text = ListBoxItem163->Text;
	LavenderBlush4->Text = ListBoxItem171->Text;

	Label3->Text = Menu12->Text;

	Timer14->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
	Timer2->Enabled = false;

	ImgBtn3->Visible = true;
	ImgBtn4->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleMainMouseLeave(TObject *Sender)
{
	ListBox1->Visible = false;

	LB2_MainColors->Visible = true;

	LB3_RedColors->Visible = false;
	LB4_GreenColors->Visible = false;
	LB5_BlueColors->Visible = false;
	LB6_PinkColors->Visible = false;
	LB7_OrangeColors->Visible = false;
	LB8_YellowColors->Visible = false;
	LB9_VioletColors->Visible = false;
	LB10_BrownColors->Visible = false;
	LB11_WhiteColors->Visible = false;
	LB12_GreyColors->Visible = false;

	Black->Text = ListBoxItem27->Text;
	White->Text = ListBoxItem26->Text;
	Purple->Text = ListBoxItem125->Text;
	Red->Text = ListBoxItem108->Text;
	Maroon->Text = ListBoxItem114->Text;
	Yellow->Text = ListBoxItem79->Text;
	Green->Text = ListBoxItem68->Text;
	Aqua->Text = ListBoxItem62->Text;
	Blue->Text = ListBoxItem41->Text;
	Navy->Text = ListBoxItem33->Text;

	Label3->Text = Menu2->Text;

	Timer4->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RectangleAllMouseLeave(TObject *Sender)
{
	ListBox1->Visible = true;

	LB2_MainColors->Visible = false;
	LB3_RedColors->Visible = false;
	LB4_GreenColors->Visible = false;
	LB5_BlueColors->Visible = false;
	LB6_PinkColors->Visible = false;
	LB7_OrangeColors->Visible = false;
	LB8_YellowColors->Visible = false;
	LB9_VioletColors->Visible = false;
	LB10_BrownColors->Visible = false;
	LB11_WhiteColors->Visible = false;
	LB12_GreyColors->Visible = false;

	Label3->Text = Menu1->Text;

	Timer3->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ImgBtn6Click(TObject *Sender)
{
//Отображаем панель
	if(Panel2->Visible == false)
	{
		Panel2->Width = 181;
		Panel2->Position->X = Form1->Width - Panel2->Width - 20; //Делаем отступ от правого края
		Panel2->Position->Y = 46; //Отступ с верху
		Panel2->Height = 458;

		//Эмитируем нажатие меню
		ImgBtn5->Visible = false;
		ImgBtn6->Visible = true;

		//Отображаем выпадающее Меню
		Panel2->Visible = true;
	}

//Убираем панель
	else
	{
		ImgBtn5->Visible = true;
		ImgBtn6->Visible = false;

		Form1->Panel2->Visible = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB9_VioletColorsMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB9_VioletColorsMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB8_YellowColorsMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB8_YellowColorsMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB7_OrangeColorsMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB7_OrangeColorsMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB6_PinkColorsMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB6_PinkColorsMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB5_BlueColorsMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB5_BlueColorsMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB4_GreenColorsMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB4_GreenColorsMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB3_RedColorsMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB3_RedColorsMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB2_MainColorsMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB2_MainColorsMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB12_GreyColorsMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB12_GreyColorsMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB11_WhiteColorsMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB11_WhiteColorsMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB10_BrownColorsMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB10_BrownColorsMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Panel2->Visible = false; //On scrolling OR touch DOWN - Vissible off PanelMenu
	ListBox1->ItemIndex = -1;

	ImgBtn5->Visible = true;
	ImgBtn6->Visible = false;
}
//---------------------------------------------------------------------------

