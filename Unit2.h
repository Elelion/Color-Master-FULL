//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TRectangle *Rectangle5;
	TLabel *Label1;
	TPanel *Panel6;
	TRectangle *Rectangle4;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TRectangle *Rectangle1;
	TRectangle *Rectangle2;
	TPanel *Panel4;
	TRectangle *Rectangle6;
	TLabel *Label2;
	TPanel *Panel9;
	TRectangle *Rectangle7;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
