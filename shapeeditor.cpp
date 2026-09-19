#include "shape_editor.h"
#include "shape.h"
#include "editor.h"

ShapeObjectsEditor::ShapeObjectsEditor()
{
	currentIndex = 0;
	pse = nullptr;
	currentTool = -1;
}

ShapeObjectsEditor::~ShapeObjectsEditor()
{
	delete pse;
	for (int i = 0; i < currentIndex; i++)
	{
		delete pcshape[i];
	}
}

void ShapeObjectsEditor::OnLBdown(HWND hWnd)
{
	if (pse) pse->OnLBdown(hWnd);
}

void ShapeObjectsEditor::OnLBup(HWND hWnd)
{
	if (pse) pse->OnLBup(hWnd);
}

void ShapeObjectsEditor::OnMouseMove(HWND hWnd)
{
	if (pse) pse->OnMouseMove(hWnd);
}

void ShapeObjectsEditor::OnPaint(HWND hWnd)
{
	if (pse) pse->OnPaint(hWnd);
}

void ShapeObjectsEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu = (HMENU)wParam;
	if (hMenu == GetSubMenu(GetMenu(hWnd), 1))
	{
		for (int i = 0; i < 4; i++)
		{
			CheckMenuItem(hMenu, i, MF_BYPOSITION | MF_UNCHECKED);
		}
		CheckMenuItem(hMenu, currentTool, MF_BYPOSITION | MF_CHECKED);
	}
}

void ShapeObjectsEditor::StartPointEditor() { delete pse; currentTool = 0; pse = new PointEditor(); }
void ShapeObjectsEditor::StartLineEditor() { delete pse; currentTool = 1; pse = new LineEditor(); }
void ShapeObjectsEditor::StartRectEditor() { delete pse; currentTool = 2; pse = new RectEditor(); }
void ShapeObjectsEditor::StartEllipseEditor() { delete pse; currentTool = 3; pse = new EllipseEditor(); }