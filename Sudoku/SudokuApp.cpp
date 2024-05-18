/***************************************************************
 * Name:      SudokuApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2024-05-17
 * Copyright:  ()
 * License:
 **************************************************************/

#include "SudokuApp.h"

//(*AppHeaders
#include "SudokuMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(SudokuApp);

bool SudokuApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	SudokuFrame* Frame = new SudokuFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
