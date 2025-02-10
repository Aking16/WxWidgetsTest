#include "SparklineRenderer.h"
#include <algorithm> // For std::minmax_element
#include <wx/dc.h>

void SparklineRenderer::Draw(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc, const wxRect& rect,
    int row, int col, bool isSelected)
{
    // Draw cell background
    dc.SetBrush(isSelected ? *wxLIGHT_GREY_BRUSH : *wxWHITE_BRUSH);
    dc.SetPen(*wxTRANSPARENT_PEN);
    dc.DrawRectangle(rect);

    if (m_data.empty())
        return;

    // Normalize data to fit within the cell's dimensions
    auto minmax = std::minmax_element(m_data.begin(), m_data.end());
    int minVal = *minmax.first;
    int maxVal = *minmax.second;
    int dataRange = maxVal - minVal;
    if (dataRange == 0) dataRange = 1; // Avoid division by zero

    // Scale data points
    std::vector<wxPoint> points;
    int step = rect.GetWidth() / (m_data.size() - 1);
    for (size_t i = 0; i < m_data.size(); ++i)
    {
        int x = rect.x + i * step;
        int y = rect.y + rect.GetHeight() -
            (rect.GetHeight() * (m_data[i] - minVal) / dataRange);
        points.emplace_back(x, y);
    }

    // Draw sparkline
    dc.SetPen(wxPen(*wxBLUE, 2));
    dc.DrawLines(points.size(), points.data());

    // Draw data points
    dc.SetBrush(*wxBLUE_BRUSH);
    for (const auto& point : points)
    {
        dc.DrawCircle(point, 2);
    }
}