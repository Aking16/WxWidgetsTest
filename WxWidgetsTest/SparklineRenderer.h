#ifndef SPARKLINE_RENDERER_H
#define SPARKLINE_RENDERER_H

#include <wx/grid.h>
#include <vector>

class SparklineRenderer : public wxGridCellRenderer
{
public:
    SparklineRenderer(const std::vector<int>& data) : m_data(data) {}

	virtual ~SparklineRenderer() {};

	virtual wxGridCellRenderer*
		Clone() const { return new SparklineRenderer(m_data); };

    virtual void
        Draw(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc, const wxRect& rect,
            int row, int col, bool isSelected);

    virtual wxSize
        GetBestSize(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc, int row, int col)
    {
        return wxSize(75, 25);
    };

private:
    std::vector<int> m_data;
};

#endif // SPARKLINE_RENDERER_H