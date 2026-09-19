#pragma once
#include <windows.h>
#include "shape.h" 

class Editor
{
public:
	virtual void OnLBdown(HWND hWnd) = 0;
	virtual void OnLBup(HWND hWnd) = 0;
	virtual void OnMouseMove(HWND hWnd) = 0;
	virtual void OnPaint(HWND hWnd) = 0;
    virtual ~Editor() {}
};

class ShapeEditor : public Editor
{
protected:
    int menuIndex = 0;
    static int xStart, yStart, xEnd, yEnd;
    static bool isDrawing;
public:
    void OnInitMenuPopup(HWND hWnd, WPARAM wParam);
    int GetMenuIndex() { return menuIndex; }

    void OnLBdown(HWND hWnd) override;
    void OnLBup(HWND hWnd) override;
    void OnMouseMove(HWND hWnd) override;
    void OnPaint(HWND hWnd) override;
};

class PointEditor : public ShapeEditor
{
public:
    void OnPaint(HWND hWnd) override;
};

class LineEditor : public ShapeEditor
{
public:
    void OnPaint(HWND hWnd) override;
};

class RectEditor : public ShapeEditor
{
public:
    void OnPaint(HWND hWnd) override;
};

class EllipseEditor : public ShapeEditor
{
public:
    void OnPaint(HWND hWnd) override;
};