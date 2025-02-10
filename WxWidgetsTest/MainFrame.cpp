#include "MainFrame.h"
#include "ButtonRenderer.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    // Create a wxGrid control
    wxGrid* grid = new wxGrid(this, wxID_ANY, wxPoint(10, 10), wxSize(580, 300));

    // Set the default column and row sizes
    grid->SetDefaultColSize(100);
    grid->SetDefaultRowSize(25);
    grid->SetRowLabelSize(50);
    grid->SetColLabelSize(25);

    // Set the number of rows and columns
    grid->CreateGrid(5, 4, wxGrid::wxGridSelectCells);  // 5 rows and 3 columns

    // Set column labels
    grid->SetColLabelValue(0, "Name");
    grid->SetColLabelValue(1, "Age");
    grid->SetColLabelValue(2, "Country");
    grid->SetColLabelValue(3, "Actions");

    // Fill the grid with some data
    grid->SetCellValue(0, 0, "John");
    grid->SetCellValue(0, 1, "30");
    grid->SetCellValue(0, 2, "USA");

    grid->SetCellValue(1, 0, "Alice");
    grid->SetCellValue(1, 1, "25");
    grid->SetCellValue(1, 2, "Canada");

    grid->SetCellValue(2, 0, "Bob");
    grid->SetCellValue(2, 1, "28");
    grid->SetCellValue(2, 2, "UK");

    // Set the renderer for the last column
    wxGridCellAttr* attr = new wxGridCellAttr();
    attr->SetReadOnly(true);
    attr->SetRenderer(new ButtonRenderer());

    grid->SetColAttr(3, attr);
}

