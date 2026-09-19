#include "shape_editor.h"
#include "editor.h"

ShapeObjectsEditor::ShapeObjectsEditor()
{
    currentIndex = 0;
    pse = nullptr;
    currentTool = -1;
    for (int i = 0; i < 120; i++)
    {
        pcshape[i] = nullptr;
    }
}

ShapeObjectsEditor::~ShapeObjectsEditor()
{
    delete pse;
    for (int i = 0; i < currentIndex; i++)
    {
        delete pcshape[i];
    }
}

void ShapeObjectsEditor::AddShape(Shape* shape)
{
    if (currentIndex < 120 && shape != nullptr)
    {
        pcshape[currentIndex] = shape;
        currentIndex++;
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
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);


    for (int i = 0; i < currentIndex; i++)
    {
        if (pcshape[i])
        {
            pcshape[i]->Show(hdc);
        }
    }


    if (pse)
    {
        pse->OnPaint(hdc);
    }

    EndPaint(hWnd, &ps);
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
        if (currentTool != -1)
        {
            CheckMenuItem(hMenu, currentTool, MF_BYPOSITION | MF_CHECKED);
        }
    }
}

void ShapeObjectsEditor::StartPointEditor()
{
    delete pse;
    currentTool = 0;
    pse = new PointEditor(this);
}

void ShapeObjectsEditor::StartLineEditor()
{
    delete pse;
    currentTool = 1;
    pse = new LineEditor(this);
}

void ShapeObjectsEditor::StartRectEditor()
{
    delete pse;
    currentTool = 2;
    pse = new RectEditor(this);
}

void ShapeObjectsEditor::StartEllipseEditor()
{
    delete pse;
    currentTool = 3;
    pse = new EllipseEditor(this);
}