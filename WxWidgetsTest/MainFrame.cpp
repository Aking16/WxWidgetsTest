#include "MainFrame.h"
#include "ButtonRenderer.h"
#include "SparklineRenderer.h"
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
    grid->CreateGrid(5, 5, wxGrid::wxGridSelectCells);  // 5 rows and 5 columns

    // Set column labels
    /*grid->SetColLabelValue(0, "Name");
    grid->SetColLabelValue(1, "Age");
    grid->SetColLabelValue(2, "Country");
    grid->SetColLabelValue(3, "Chart");
    grid->SetColLabelValue(4, "Actions");*/

	// Set column sizes
	grid->SetColSize(4, 100);

    // Remove the header
    grid->SetColLabelSize(0);

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

    // Create multiple data sets for the SparklineRenderer
    std::vector<std::vector<int>> sparklineData = {
        {5, 10, 15, 20, 15, 10, 5},
        {15, 12, 10, 10, 9, 5, 10},
        {15, 7, 10, 30, 4, 7, 3},
    };

    // Set Chart renderer for the Chart column
    for (int row = 0; row < grid->GetNumberRows(); ++row) {
        if (row < static_cast<int>(sparklineData.size())) {
            grid->SetCellRenderer(row, 3, new SparklineRenderer(sparklineData[row]));
            grid->SetReadOnly(row, 3);
        }
    }

    // Set the Button renderer for the Actions column
    for (int row = 0; row < grid->GetNumberRows(); ++row) {
        grid->SetCellRenderer(row, 4, new ButtonRenderer());
        grid->SetReadOnly(row, 4);
    }
}