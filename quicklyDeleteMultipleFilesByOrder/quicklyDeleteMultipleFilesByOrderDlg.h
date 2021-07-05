
// quicklyDeleteMultipleFilesByOrderDlg.h : ͷ�ļ�
//

#pragma once
#include <fstream>


// CquicklyDeleteMultipleFilesByOrderDlg �Ի���
class CquicklyDeleteMultipleFilesByOrderDlg : public CDialogEx
{
// ����
public:
	CquicklyDeleteMultipleFilesByOrderDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_QUICKLYDELETEMULTIPLEFILESBYORDER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAddFiles();

	static void CreateFile(int n);
	static void WriteFile(std::ofstream &file );
	static UINT MyThreadProc(LPVOID Param);
	afx_msg void OnBnClickedButtonDelete();
	// ��Ҫɾ����Ŀ¼
	CString dirPath;
	afx_msg void OnBnClickedButtonSelectDir();
	afx_msg void OnBnClickedButtonDelete2();
	afx_msg void OnBnClickedButtonDelete3();
};
