//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Ani.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	TRectangle *Rectangle7;
	TLabel *Label2;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label3;
	TRectangle *Rectangle1;
	TPanel *Panel1;
	TRectangle *Rectangle4;
	TRectangle *Rectangle5;
	TLabel *Label1;
	TImage *ImgBtn2;
	TImage *ImgBtn1;
	TImage *ImgBtn3;
	TPanel *Panel4;
	TRectangle *Rectangle6;
	TLabel *Label7;
	TLabel *Label6;
	TPanel *Panel6;
	TPanel *Panel12;
	TRectangle *Rectangle2;
	TButton *Button4;
	TFloatAnimation *FloatAnimation4;
	TLabel *FullName1Color;
	TLabel *FullName1;
	TPanel *Panel8;
	TRectangle *Rectangle3;
	TButton *Button5;
	TFloatAnimation *FloatAnimation5;
	TLabel *FullName2Color;
	TLabel *FullName2;
	TFloatAnimation *FloatAnimation1;
	TLabel *buf1;
	TRoundRect *RoundRect2;
	TRoundRect *RoundRect4;
	TRoundRect *RoundRect3;
	TImage *BtnRightPrs;
	TImage *BtnRight;
	TRoundRect *RoundRect1;
	TImage *BtnLeftPrs;
	TImage *BtnLeft;
	TTimer *Timer1;
	TTimer *Timer2;
	TLabel *buf2;
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall ImgBtn1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall ImgBtn3Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall BtnLeftClick(TObject *Sender);
	void __fastcall BtnRightClick(TObject *Sender);
	void __fastcall ImgBtn2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
