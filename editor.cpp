#include "editor.h"
#include "shape_editor.h"

int ShapeEditor::xStart = 0;
int ShapeEditor::yStart = 0;
int ShapeEditor::xEnd = 0;
int ShapeEditor::yEnd = 0;
bool ShapeEditor::isDrawing = false;

void ShapeEditor::OnLBdown(HWND hWnd)
{
    POINT pt;
    GetCursorPos(&pt);
    ScreenToClient(hWnd, &pt);
    xStart = xEnd = pt.x;
    yStart = yEnd = pt.y;
    isDrawing = true;
}

void ShapeEditor::OnMouseMove(HWND hWnd)
{
    if (isDrawing)
    {
        POINT pt;
        GetCursorPos(&pt);
        ScreenToClient(hWnd, &pt);
        xEnd = pt.x;
        yEnd = pt.y;
        InvalidateRect(hWnd, NULL, TRUE);
    }
}

void ShapeEditor::OnLBup(HWND hWnd)
{
    if (isDrawing)
    {
        isDrawing = false;
        InvalidateRect(hWnd, NULL, TRUE);
    }
}

void ShapeEditor::OnPaint(HDC hdc)
{
}

void PointEditor::OnLBup(HWND hWnd)
{
    if (isDrawing)
    {
        isDrawing = false;
        PointShape* shape = new PointShape();
        shape->Set(xStart, yStart, xEnd, yEnd);
        owner->AddShape(shape); 
        InvalidateRect(hWnd, NULL, TRUE);
    }
}

void PointEditor::OnPaint(HDC hdc)
{
    if (isDrawing)
    {
        PointShape shape;
        shape.Set(xStart, yStart, xEnd, yEnd);
        shape.Show(hdc);
    }
}

void LineEditor::OnLBup(HWND hWnd)
{
    if (isDrawing)
    {
        isDrawing = false;
        LineShape* shape = new LineShape();
        shape->Set(xStart, yStart, xEnd, yEnd);
        owner->AddShape(shape); 
        InvalidateRect(hWnd, NULL, TRUE);
    }
}

void LineEditor::OnPaint(HDC hdc)
{
    if (isDrawing)
    {
        LineShape shape;
        shape.Set(xStart, yStart, xEnd, yEnd);
        shape.Show(hdc);
    }
}

void RectEditor::OnLBup(HWND hWnd)
{
    if (isDrawing)
    {
        isDrawing = false;
        RectShape* shape = new RectShape();
        shape->Set(xStart, yStart, xEnd, yEnd);
        owner->AddShape(shape);
        InvalidateRect(hWnd, NULL, TRUE);
    }
}

void RectEditor::OnPaint(HDC hdc)
{
    if (isDrawing)
    {
        RectShape shape;
        shape.Set(xStart, yStart, xEnd, yEnd);
        shape.Show(hdc);
    }
}

void EllipseEditor::OnLBup(HWND hWnd)
{
    if (isDrawing)
    {
        isDrawing = false;
        EllipseShape* shape = new EllipseShape();
        shape->Set(xStart, yStart, xEnd, yEnd);
        owner->AddShape(shape); 
        InvalidateRect(hWnd, NULL, TRUE);
    }
}

void EllipseEditor::OnPaint(HDC hdc)
{
    if (isDrawing)
    {
        EllipseShape shape;
        shape.Set(xStart, yStart, xEnd, yEnd);
        shape.Show(hdc);
    }
}