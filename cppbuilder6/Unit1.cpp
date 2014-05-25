//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
float x1n,x2n,y1n,y2n;
int ind=0;
int sch=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void risov(float x1,float y1,float x2,float y2,float k,TImage *Image1)
{
   if(k>0)
   {
      float xn = (x1+x2)/2 + (y2-y1)/2;
      float yn = (y1+y2)/2 - (x2-x1)/2;

      risov(x1,y1,xn,yn,k-1,Image1);
      risov(x2,y2,xn,yn,k-1,Image1);
   }
   else
   {
      Image1->Canvas->Pen->Color = int(x1*x2*y1*y2)%250;
      Image1->Canvas->MoveTo(x1,y1);
      Image1->Canvas->LineTo(x2,y2);
      sch++;
      if(sch==10000)
      {
         Form1->Update();
         Sleep(100);
         sch=0;
      };
   };
   return;
};

//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{

   Image1->Canvas->Pen->Color = clRed;
   Image1->Canvas->Rectangle(0,0,Image1->Width,Image1->Height);

   
   ListBox1->Clear();
   ListBox1->Items->Add("Укажите координаты для X1 и Y1");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   if(ind==0)
   {
      //Image1->Canvas->Pen->Width = 3;
      Image1->Canvas->Rectangle(0,0,Image1->Width,Image1->Height);
      x1n = X;
      y1n = Y;
      //Image1->Canvas->Ellipse(X-5,Y-5,X+5,Y+5);
      ListBox1->Items->Add("Выбраны координаты: X1="+IntToStr(X)+", Y1="+IntToStr(Y));
      ListBox1->Items->Add("Укажите координаты для X2 и Y2");
      ind++;
      return;
   };
   if(ind>0)
   {
      x2n = X;
      y2n = Y;
      //Image1->Canvas->Ellipse(X-5,Y-5,X+5,Y+5);
      ListBox1->Items->Add("Выбраны координаты: X2="+IntToStr(X)+", Y2="+IntToStr(Y));
      ListBox1->Items->Add("Идет построение");
      int k=ComboBox1->ItemIndex+1;
      risov(x1n,y1n,x2n,y2n,k,Image1);
      ind = 0;
      ListBox1->Clear();
      ListBox1->Items->Add("Укажите координаты для X1 и Y1");
      return;
   };
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
   Label2->Caption = "X = "+IntToStr(X)+", Y = "+IntToStr(Y);
}
//---------------------------------------------------------------------------




