
// DFDEditor2Doc.h : CDFDEditor2Doc ��Ľӿ�
//


#pragma once
//#include"DiagramEditor.h"
//class DiagramEditor;
class Diagram;

class CDFDEditor2Doc : public CDocument
{
protected: // �������л�����
	CDFDEditor2Doc();
	DECLARE_DYNCREATE(CDFDEditor2Doc)

// ����
public:
	Diagram *d;
// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CDFDEditor2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
