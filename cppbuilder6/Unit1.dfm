object Form1: TForm1
  Left = 268
  Top = 101
  BorderStyle = bsDialog
  Caption = 'KDragons'
  ClientHeight = 620
  ClientWidth = 862
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 862
    Height = 480
    Cursor = crCross
    Align = alClient
    OnMouseDown = Image1MouseDown
    OnMouseMove = Image1MouseMove
  end
  object Panel1: TPanel
    Left = 0
    Top = 480
    Width = 862
    Height = 140
    Align = alBottom
    Caption = 'Panel1'
    TabOrder = 0
    object Label2: TLabel
      Left = 192
      Top = 12
      Width = 32
      Height = 13
      Caption = 'Label2'
    end
    object Label1: TLabel
      Left = 11
      Top = 12
      Width = 16
      Height = 13
      Caption = 'K ='
    end
    object ListBox1: TListBox
      Left = 8
      Top = 40
      Width = 841
      Height = 89
      ItemHeight = 13
      TabOrder = 0
    end
    object ComboBox1: TComboBox
      Left = 32
      Top = 8
      Width = 145
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      ItemIndex = 9
      TabOrder = 1
      Text = '10'
      Items.Strings = (
        '1'
        '2'
        '3'
        '4'
        '5'
        '6'
        '7'
        '8'
        '9'
        '10'
        '11'
        '12'
        '13'
        '14'
        '15'
        '16'
        '17'
        '18'
        '19'
        '20')
    end
  end
end
