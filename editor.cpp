#include "editor.h"

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

void ShapeEditor::OnPaint(HWND hWnd)
{
}

void ShapeEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu = (HMENU)wParam;
	CheckMenuItem(hMenu, menuIndex, MF_BYCOMMAND | MF_CHECKED);
}

void PointEditor::OnPaint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	PointShape shape;
	shape.Set(xStart, yStart, xEnd, yEnd);
	shape.Show(hdc);
	EndPaint(hWnd, &ps);
}

void LineEditor::OnPaint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	LineShape shape;
	shape.Set(xStart, yStart, xEnd, yEnd);
	shape.Show(hdc);
	EndPaint(hWnd, &ps);
}

void RectEditor::OnPaint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	RectShape shape;
	shape.Set(xStart, yStart, xEnd, yEnd);
	shape.Show(hdc);
	EndPaint(hWnd, &ps);
}

void EllipseEditor::OnPaint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	EllipseShape shape;
	shape.Set(xStart, yStart, xEnd, yEnd);
	shape.Show(hdc);
	EndPaint(hWnd, &ps);
}