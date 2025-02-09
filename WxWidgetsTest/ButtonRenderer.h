#ifndef BUTTON_RENDERER_H
#define BUTTON_RENDERER_H

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include <wx/wx.h>
#else
#include <wx/wxprec.h>
#endif

#include <wx/grid.h>

class ButtonRenderer : public wxGridCellRenderer
{
public:

    ButtonRenderer() {};

    virtual ~ButtonRenderer() {};

    virtual wxGridCellRenderer*
        Clone() const { return new ButtonRenderer(); };

    virtual void
        Draw(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc, const wxRect& rect,
            int row, int col, bool isSelected);

    virtual wxSize
        GetBestSize(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc, int row, int col)
    {
        return wxSize(75, 25);
    };

};

#endif