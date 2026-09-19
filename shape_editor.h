#pragma once
#include <windows.h>

class Shape;
class ShapeEditor;

class ShapeObjectsEditor
{
protected:
	Shape* pcshape[120];
	int currentIndex;
	ShapeEditor* pse = nullptr;
	int currentTool = 0;
public:
	ShapeObjectsEditor();
	~ShapeObjectsEditor();

	void StartPointEditor();
	void StartLineEditor();
	void StartRectEditor();
	void StartEllipseEditor();

	void OnLBdown(HWND hWnd);
	void OnLBup(HWND hWnd);
	void OnMouseMove(HWND hWnd);
	void OnPaint(HWND hWnd);

	void OnInitMenuPopup(HWND hWnd, WPARAM wParam);
};
