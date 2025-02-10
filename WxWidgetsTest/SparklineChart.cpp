#include "SparklineChart.h"
#include <wx/wx.h>
#include <vector>
#include <algorithm>

SparklineChart::SparklineChart(wxWindow* parent, const std::vector<int>& data)
        : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(300, 100)), m_data(data)
    {
        Bind(wxEVT_PAINT, &SparklinePanel::OnPaint, this);
    }

private:
    std::vector<int> m_data;

    void OnPaint(wxPaintEvent& event)
    {
        wxPaintDC dc(this);

        // Get panel size
        wxSize size = GetSize();
        int width = size.GetWidth();
        int height = size.GetHeight();

        // Draw background
        dc.SetBrush(*wxWHITE_BRUSH);
        dc.SetPen(*wxTRANSPARENT_PEN);
        dc.DrawRectangle(0, 0, width, height);

        if (m_data.empty())
            return;

        // Normalize data to fit within the panel
        auto [minVal, maxVal] = std::minmax_element(m_data.begin(), m_data.end());
        int dataRange = *maxVal - *minVal;
        if (dataRange == 0) dataRange = 1; // Prevent division by zero

        // Scale data to panel dimensions
        std::vector<wxPoint> points;
        int step = width / (m_data.size() - 1);
        for (size_t i = 0; i < m_data.size(); ++i)
        {
            int x = i * step;
            int y = height - (height * (m_data[i] - *minVal) / dataRange);
            points.emplace_back(x, y);
        }

        // Draw sparkline
        dc.SetPen(wxPen(*wxBLUE, 2));
        dc.DrawLines(points.size(), points.data());

        // Draw data points
        dc.SetBrush(*wxBLUE_BRUSH);
        for (const auto& point : points)
        {
            dc.DrawCircle(point, 3);
        }
    }
};

class MyFrame : public wxFrame
{
public:
    MyFrame() : wxFrame(nullptr, wxID_ANY, "Sparkline Chart Example", wxDefaultPosition, wxSize(400, 200))
    {
        // Sample data for the sparkline
        std::vector<int> data = { 5, 10, 15, 20, 10, 5, 25, 30, 15, 10 };

        // Create a panel to display the sparkline
        SparklinePanel* sparklinePanel = new SparklinePanel(this, data);

        // Layout
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(sparklinePanel, 1, wxEXPAND | wxALL, 10);
        SetSizer(sizer);
    }
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        MyFrame* frame = new MyFrame();
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
