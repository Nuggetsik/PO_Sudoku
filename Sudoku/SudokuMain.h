/***************************************************************
 * Name:      SudokuMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2024-05-17
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef SUDOKUMAIN_H
#define SUDOKUMAIN_H

#include <vector>
//(*Headers(SudokuFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
//*)

class SudokuFrame: public wxFrame
{
    public:

        SudokuFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~SudokuFrame();

    private:

        wxString num; // ѕеременна€ дл€ хранени€ значени€, которое нужно добавить к wxTextCtrl

        //(*Handlers(SudokuFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButtonClicked(wxCommandEvent& event);
        void OnTextCtrl(wxCommandEvent& event);
        //*)

         //(*Identifiers(SudokuFrame)
         static const long ID_BUTTON1;
         static const long ID_BUTTON2;
         static const long ID_BUTTON3;
         static const long ID_BUTTON4;
         static const long ID_BUTTON5;
         static const long ID_BUTTON6;
         static const long ID_BUTTON7;
         static const long ID_BUTTON8;
         static const long ID_BUTTON9;
         //*)

        static const long ID_BUTTONS[9]; // —татический массив дл€ хранени€ идентификаторов кнопок


        std::vector<wxTextCtrl*> textCtrls;
        std::vector<wxButton*> Buttons;
        DECLARE_EVENT_TABLE()
};

#endif // SUDOKUMAIN_H
