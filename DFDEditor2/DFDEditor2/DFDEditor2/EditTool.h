#pragma once
class Element;
class Diagram;

#include"Tool.h"

class EditTool : public Tool
{
public:
	EditTool();
	EditTool(DiagramEditor *d);
	~EditTool();
	void Press(CPoint pos, HWND hWnd);  // ����
	void RightPress(CPoint pos, HWND hWnd);  // �һ�->�޸�����
	void DoubleClick(CPoint pos, HWND hWnd);  // ˫��->������ͼ
	void Move(CPoint pos, CPoint oldpos);  // �ƶ�ͼԪ
	void Release(CPoint pos);  // �������ͷ�
	void RightRelease(CPoint pos);  // ����Ҽ��ͷ�
	void GotoFatherWnd();  // �򿪸����ڣ���ӦESC��
	void Remove();  // ɾ��ͼԪ����ӦDELETE��
	void CreateNewDiagram();  // ������ͼ��
	void OpenDiagramtoProcess(HWND hWnd, Diagram *d);  // ��Process����ͼ
};
